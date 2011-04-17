/** \file main.c
\brief 
*/

#include "main.h"

size_t total_newlines = 1;

extern file_struct file;

symbol_table *string_table;
symbol_table *id_table;

int main(int argc, char *argv[])
{
	char *ofile;                 /**> Filename of the output file                                   */
	char *infile;                /**> Filename of the input file                                    */
	size_t o_name_len;           /**> Filesize of the name specifed by the -o flag                  */

	/* Initialize some file information */
	strcpy(file.calling_prog, argv[0]);
	strcpy(file.default_o, DEFAULT_OUTPUT);
	file.cur_line = 0;
	file.cur_column = 0;

	switch(argc){
	case 1:
		printf("%s: no input files.\n Try --help for more options.\n", file.calling_prog);
		break;

	case 2:
		if(strcmp(argv[1], "--help") == 0){
			usage();
		}
		else if(strcmp(argv[1], "--version") == 0){
			version();
		}
		else {
			/* Initialize File Contents */
			strcpy(file.filename, argv[1]);

			/* No output name specified, we default to unix elf name a.out */
			// run_preprocessor(&file);

			run_scanner(&file);
            run_parser();  /* Generates Stack Code */
		}
		break;
	case 3:
		if(strcmp(argv[1], "-c")){
			/* Stop the linking process, output object files.
			(Highly unlikely that I'll implement this, but I'll keep it
			here for posterity anyway).
			*/
		}
		break;
	default:
		/* These next few lines handle the -o flag */	

		o_name_len = strlen((char*)scan_for_o(argc, argv));

		if(o_name_len > 0){ 
			ofile = (char*)xmalloc(sizeof(char)*o_name_len);
			strcpy(ofile, (char*)scan_for_o(argc, argv));

			/* Do stuff here */
			//run_preprocessor(argv[0], argv[1], ofile);

            strcpy(file.filename, argv[1]);
            strcpy(file.default_o, ofile);

			run_scanner(&file); /* Outputs an interim file */
            run_parser();  /* Generates Stack Code */

            //print_stab(string_table);
	        //print_stab(id_table);

			free(ofile);
		}

		break;
	}


	return EXIT_SUCCESS;
}

