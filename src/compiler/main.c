/** \file main.c
	\brief 
  */

#include "main.h"

size_t total_newlines = 1;

int main(int argc, char *argv[])
{
	char *ofile;                 /**> Filename of the output file                                   */
	char *infile;                /**> Filename of the input file                                    */
	size_t o_name_len;           /**> Filesize of the name specifed by the -o flag                  */
	file_struct file;            /**> A convinient file structure to be passed around in operations */

	/* Initialize some file information */
	strcpy(file.calling_prog, argv[0]);
	strcpy(file.default_o, DEFAULT_OUTPUT);
	file.cur_line = 0;
	file.cur_column = 0;
	
	switch(argc){
		case 1:
			printf("%s: no input files\n", file.calling_prog);
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
				run_preprocessor(&file); 

				//printf("Total Newlines: %d\n\n", total_newlines); 
				//run_scanner(file.calling_prog, "tmp.txt");
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
				run_preprocessor(argv[0], argv[1], ofile);
				
				//run_scanner(INTERIM_FILENAME);
				
				free(ofile);
			}
			
			break;
	}
	
	
	return EXIT_SUCCESS;
}
