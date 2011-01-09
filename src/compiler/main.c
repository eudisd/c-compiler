#include "main.h"

int main(int argc, char *argv[])
{
	char *ofile;
	char *infile;
	size_t o_name_len;
	
	switch(argc){
		case 1:
			printf("%s: no input files\n", argv[0]);
			run_preprocessor(argv[0], "tmp.txt", "preproc.data");

			break;
		case 2:
			if(strcmp(argv[1], "--help") == 0){
				usage();
			}
			else if(strcmp(argv[1], "--version") == 0){
				version();
			}
			else {
				ofile = (char*)xmalloc(sizeof(char)*6);
				strcpy(ofile, "a.out");  /* No output name specified, we default to unix a.out */
				printf("%s", ofile);

				/* Do Stuff Here */


				free(ofile);
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


				free(ofile);
			}
			
			break;
		
	}
	
	
	return EXIT_SUCCESS;
}
