#include "main.h"


int main(int argc, char *argv[])
{
	char *ofile;
	char *infile;
	size_t o_name_len;
	//record *get_record(char *name, char*val, char type, int slot, char *scope)
	switch(argc){
		case 1:
			printf("%s: no input files\n", argv[0]);

			symbol_table *stab = create_stab(100);
			record *rec = get_record("ONE", "1", 't', 0, "Global");

			stab_insert( get_record("ONE", "1", 't', 0, "Global"), stab);
			stab_insert( get_record("TWO", "2", 't', 1, "Global"), stab);
			stab_insert( get_record("THREE", "3", 't', 1, "Global"), stab);

			print_stab(stab);
			//run_preprocessor("input", "output");
			break;
		case 2:
			if(strcmp(argv[1], "--help") == 0){
				usage();
			}
			else if(strcmp(argv[1], "--version") == 0){
				version();
			}
			else {
				//run_preprocessor(argv[1], "a.out"); /* No output name specified, we default to unix a.out */
				
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
