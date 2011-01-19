/** \file preprocessor.c
	\brief 
  */

#include "preprocessor.h"


void run_preprocessor(const char *prog, const char *ifilename, const char *ofilename)
{
	
	/* Order of file processing ("data" is the name of the intermediary file"): 
     **********************************************************************
     * ifilename(open the stream) -->  include_headers("data") --> data --> 
     * remove_comments("data") --> data --> handle_defines("data") -->
     * data
     */

	/* We need certain flags to be set here.  If they are not set, then we simply use
     * the system defaults.  These flags deal with the standard directories, among others things.
	 */

	int dir_flag = FALSE;
	int lib_flag = FALSE;

	
	/* set_flags(dir_flag, lib_flag); */

	if( !dir_flag ){
		sys_inc_dir = (char*)xmalloc(sizeof(char)*strlen(DEFAULT_INC_DIR) + 1);
		strcpy(sys_inc_dir, DEFAULT_INC_DIR);
	}
	if( !lib_flag ){
		sys_lib_dir = (char*)xmalloc(sizeof(char)*strlen(DEFAULT_LIB_DIR) + 1);
		strcpy(sys_lib_dir, DEFAULT_LIB_DIR);
	}


	/********************************************************************
     *  First we import all included header files into the current working c temp 
     *  file and output an intermediary object file.  
     ********************************************************************/

	include_headers(prog, ifilename, INTERIM_FILENAME);

	/* This same interim file is then used for all subsequent operations, including
       feeding it to the compiler (scanner, parser, etc etc).
	*/

	/* After header files are included, we remove all C-Style comments from the tmp file*/
	//remove_comments(prog, INTERIM_FILENAME);


	/* At this point, we have to handle #defines.  There are two types of cases here.
       One is a symbolic constant, the other is a macro.  I will handle the constant case
       first, and leave stubs for macro, as I'm not sure if I'll implement it fully yet
    */

	//handle_defines((char*)prog, "tmp.txt");
		
	

	
	/* Memory Clean Up */

	if( !dir_flag ){
		free(sys_inc_dir);
	}
	if( !lib_flag ){
		free(sys_lib_dir);
	}
}

char *handle_defines(char* prog, char *filename)
{
	char c;
	int j;
	char *def_keyword;
	char *def_name;
	char *def_value;

	char *def_name_tmp;
	int paren_flag = FALSE;
		
	/* create preprocessor symbol table here */
	symbol_table *defines_stab = create_stab(MAX_SLOTS);

	FILE *i = fopen(filename, "r");

	/* This bit handles the defines */
	while( (c = getc(i)) != EOF ){
		
		if( c == '#' && (tolower(fcpeek(i)) == 'd') ) {
			def_keyword = getword(i);
			def_name = getword(i);
			
			/* does the first macro-word have '(' ? */
			/* If so then: */
			/*
			if(strchr(def_name, '(')){
				def_name_tmp = getword(i);
				while(!strchr(def_name_tmp, ')')){
					strcat(def_name, def_name_tmp);
					free(def_name_tmp);	
					def_name_tmp = getword(i);
				}
				strcat(def_name, def_name_tmp);
				free(def_name_tmp);
			}*/
		
			def_value = getword(i);
		
			stab_insert( get_record(def_name, def_value, 't', 0, "Global"), defines_stab );

			

			free(def_keyword);
			free(def_name);
			free(def_value);
		}

		
		
	}	

	print_stab(defines_stab);
	/* This bit handles the defines */



	return NULL;
}

void include_headers(const char *prog, const char *ifilename, const char *ofilename)
{
	char c;                    /**> Top level character stream container.  Holds the characters of ifilename. */
	char c_inc;                /**> Nested character stream container.  Holds the characters of the included files to write. */
	char *inc_fname;           /**> This is the stripped include file name. */
	char *inc_keyword;         /**> This is for debugging, holds the include keyword file read so far. */
	char *full_filename;       /**> This represents the directory (is_it_system?) and filename concatenated. */
	char *fname;           
	char *file_path;           /**> Holds the full pathname.*/
	
	int is_it_system = FALSE;  /**> (is it system files?)  Just a flag to specify system vs. user files. */

	FILE *includes;            /**> Input file stream for all include files to be inserted. */



	FILE *i = fopen(ifilename, "r");
	FILE *o = fopen(ofilename, "w");

	if(!i)
		file_error((char*)prog, "open", (char*)ifilename, "for inserting include headers", "No such file or directory");
	if(!o)
		file_error((char*)prog, "write", (char*)ofilename, "for inserting include headers(preproc intermediate file)\n", "Unknown reason.");
		
	
	/* Here we write out the included file to the intermediary preprocessor file */
	while( (c = getc(i)) != EOF ){
		
		if(c == '#' && (fcpeek(i) == 'i')){
			
			inc_keyword = getword(i);
			full_filename = getword(i);

			/* Here, we determine if the include file is a system file, or user defined */
			if(full_filename && full_filename[0] == '<')
				is_it_system = TRUE;
			else if (full_filename && full_filename[0] == '"')
				is_it_system = FALSE;
			
			inc_fname = (char*)get_inc_fname(full_filename);
/*
			printf("%s :\n", inc_keyword);
			printf("'%s' :\n", inc_fname);
			printf("Is it system file? %s\n\n", ((is_it_system)? "Yes": "No"));
*/
			if(is_it_system){
				file_path = (char*)xmalloc(sizeof(char)* (strlen(sys_inc_dir) + strlen(inc_fname) + 1));
				strcpy(file_path, sys_inc_dir);
				strcat(file_path, inc_fname);
				strcat(file_path, "\0");
			}
			else if(!is_it_system){
				file_path = (char*)xmalloc(sizeof(char)* (strlen(sys_inc_dir) + 3));
				strcpy(file_path, "./");
				strcat(file_path, inc_fname);
				strcat(file_path, "\0");
			}
			/*
			printf("Full Path: %s\n", file_path);
			*/

			includes = fopen(file_path, "r");
			if (!includes){
				file_error((char*)prog, "open", (char*)file_path, "While doing header inclusions", "No such file or directory");
			}

			while ( (c_inc = getc(includes)) != EOF ) {
				putc(c_inc, o);
			}
			
			fclose(includes);
			
			
			free(inc_keyword);
			free(inc_fname);	
			//free(fname);
			

			c = getc(i); /* We need to pop this off c (since it's the '#' character) from the 
                          * if conditional above.  Then it is safe to write out. */
		}
		putc(c, o); 
	}
	
	
	fclose(i);
	fclose(o);
}

void remove_comments(const char *prog, const char *filename)
{

	FILE *i = fopen(filename, "r");
	FILE *o = fopen("data.tmp", "w");
	
	if(!i)
		file_error((char*)prog, "open", (char*)filename, "for removing comments", "No such file or directory.");
	if(!o)
		file_error((char*)prog, "write", (char*)filename, "preproc intermediate file", "Unknown reason(possibly permissions");
	
	/* This code handles the multiline comments removal */
	char c, c_tmp;
	while ( (c = getc(i)) != EOF ){
		if(c == '/' && (fcpeek(i) == '*')){
			c = getc(i);  /* Holds '*' */
			c = getc(i);  /* Knock that starter '*' off the file discriptor. */
			while( c != EOF ){
				if(c == '*' && fcpeek(i) == '/')
					break;
				c = getc(i);
			}
			
			c = getc(i); /* Pop off the last '*' */
			c = getc(i); /* Pop off the last '/' */
		}
		putc(c, o);
	}

	fclose(i);
	fclose(o);

	remove(filename);
	rename("data.tmp", filename);
}

char *get_inc_fname(char *n)
{
	int i;
	size_t size = strlen(n);
	char *new_word = (char*)xmalloc(sizeof(char)*(size-2)); /* + 1 for the '\0' terminator */
	
	
	for(i = 0; i < (size-2); i++){
		new_word[i] = n[i+1];
		
	}

	new_word[size-2] = '\0';
	free(n);
	return new_word;
}



