/** \file scanner.c
	\brief Contains all lexical analyzer operations.
  */

#include "scanner.h"

void run_scanner(file_struct *file)
{
	char c;
	char *word;
	
	FILE *i = fopen(INTERIM_FILENAME, "r");
	FILE *o = fopen("data.tmp", "w");

	/* getword() returns a string, so a NULL signifies that
     * nothing useful was retrieved from the input stream 
	 */
	while( (word = getword(i)) != NULL ){
		switch(word[0]){
		
			/* First, the possible keyword tokens */
			case 'a':
                /* auto */
                if ( !strcmp(word, "auto") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_AUTO);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				break;
			case 'b':
                /* break */
                if ( !strcmp(word, "break") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_BREAK);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				break;
			case 'c':
				/* case */
				/* char */
				/* const */
				/* continue */
                if( !strcmp(word, "case") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_CASE);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "char") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_CHAR);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }   
                else if ( !strcmp(word, "const") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_CONST);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else if ( !strcmp(word, "continue") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_CONTINUE);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				break;
			
			case 'd':
				/* default */
				/* do */
				/* double */
                if( !strcmp(word, "default") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_DEFAULT);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "do") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_DO);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }   
                else if ( !strcmp(word, "double") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_DOUBLE);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				break;

			case 'e':
				/* else */
				/* enum */
				/* extern */
                if( !strcmp(word, "else") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_ELSE);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "enum") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_ENUM);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }   
                else if ( !strcmp(word, "extern") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_EXTERN);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				break;
			case 'f':
				/* float */
				/* for */
                if( !strcmp(word, "float") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_FLOAT);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "for") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_FOR);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				break;

			case 'g':
				/* goto */
                 if( !strcmp(word, "goto") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_GOTO);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else {
                    parse_tokens(word);
                }
				break;
	
			case 'i':
				/* int */
                /* if */
                
                if( !strcmp(word, "int") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_INT);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "if") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_IF);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				
				
				
				break;

			case 'l':
				/* long */
                  
                if( !strcmp(word, "long") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_LONG);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else {
                    parse_tokens(word);
                }
				
				break;
			
			case 'r':
				/* register */
				/* return */
                  
                if( !strcmp(word, "register") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_REGISTER);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "return") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_RETURN);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				
				break;
		
			case 's':
				/* short */
				/* signed */
				/* sizeof */
				/* static */
				/* struct */
				/* switch */
                  
                if( !strcmp(word, "short") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_SHORT);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "signed") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_SIGNED);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else if ( !strcmp(word, "sizeof") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_SIZEOF);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                } 

                else if ( !strcmp(word, "static") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_STATIC);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else if ( !strcmp(word, "struct") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_STRUCT);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                } 
                 else if ( !strcmp(word, "switch") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_SWITCH);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                } 
               
                else {
                    parse_tokens(word);
                }
				
				break;

			case 't':
				/* typedef */
                if( !strcmp(word, "typedef") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_TYPEDEF);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else {
                    parse_tokens(word);
                }
				break;

			case 'u':
				/* union */
				/* unsigned */
                if( !strcmp(word, "union") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_UNION);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "unsigned") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_UNSIGNED);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				break;

			case 'v':
				/* void */
				/* volatile */
                if( !strcmp(word, "void") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_VOID);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "volatile") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_VOLATILE);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    parse_tokens(word);
                }
				break;

			case 'w':
				/* while */
                if( !strcmp(word, "while") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_WHILE);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else {
                    parse_tokens(word);
                }
				break;

			/* Now, we deal with other tokens (operators, constants, id's, etc) */

			case '{':
                if( !strcmp(word, "{") ) {
                    sprintf(tk_buffer0, "%d", TK_LEFTBRACKET);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(word);
                }
				break;

			case '}':
                if( !strcmp(word, "}") ) {
                    sprintf(tk_buffer0, "%d", TK_RIGHTBRACKET);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(word);
                }
				break;

			case '(':
				/* ( */
				/* (casting) */
				break;

			case ')':
				break;

			case ']':
				break;

			case '[':
				break;

			case '.':
				break;

			case '!':
				break;

			case '~':
				/* ~ */
				/* ~= */
				break;
			
			case '+':
				/* + */
				/* ++ */
				/* += */
				break;

			case '-':
				/* - */
				/* -- */
				/* -= */
				break;

			case '*':
				/* * */
				/* *= */
				break;

			case '&':
				/* & */
				/* && */
				/* &= */
				break;

			case '/':
				/* / */
				/* /= */
				break;
			
			case '%':
				/* % */
				/* %= */
				break;

			case '<':
				/* < */
				/* << */
				/* <= */
				/* <<= */
				break;

			case '>':
				/* > */
				/* >> */
				/* >= */
				/* >>= */			
				break;

			case '=':
				/* = */
				/* == */
				break;

			case '|':
				/* | */
				/* || */
				/* |= */
				break;

			case '^':
				/* ^ */
				/* ^= */
				break;

			case '?':
				break;

			case ':':
				break;
            
            case ';':
                break;

			/* Constants */

			case '\'':
				break;
		
			/* String Literals */
			case '"':
				break;

			default:
			/* Try To See if it's a identifier, if not: 
			 ERROR! Given token is not part of the lang def. */

				break;
				
		}
		free(word);
	}
    
	fclose(i);
	fclose(o);
	
	
}

void put_lexeme(FILE *o, char *tk_name, char *tk_value)
{
	size_t tk_name_size = strlen(tk_name);
	size_t tk_value_size = strlen(tk_value);
	
	putc('<', o);
	fwrite(tk_name, sizeof(char), tk_name_size, o);
	putc(',', o);
	fwrite(tk_value, sizeof(char), tk_value_size, o);
	putc('>', o);
}

void put_ulexeme(FILE *o, char *tk_name)
{
	size_t tk_name_size = strlen(tk_name);
	
	putc('<', o);
	fwrite(tk_name, sizeof(char), tk_name_size, o);
	putc('>', o);
}


/* NOTE TO SELF: Still need to handle the multiple character
 * token extractions!! That is, say, '<<' as opposed to '<'
 */

char *extract_token(char *word)
{
	switch(word[0]){
		case '{':
			return copy_alloced("{");
		case '}':
			return copy_alloced("}");
		case '(':
			return copy_alloced("(");
		case ')':
			return copy_alloced(")");
		case ']':
			return copy_alloced("]");
		case '[':
			return copy_alloced("[");
		case '.':
			return copy_alloced(".");
		case '!':
			return copy_alloced("!");
		case '~':
			return copy_alloced("~");
				/* ~ */
				/* ~= */
		case '+':
			return copy_alloced("+");
			/* + */
			/* ++ */
			/* += */
		case '-':
			return copy_alloced("-");
			/* - */
			/* -- */
			/* -= */
		case '*':
			return copy_alloced("*");
			/* * */
			/* *= */
		case '&':
			return copy_alloced("&");
			/* & */
			/* && */
			/* &= */
		case '/':
			return copy_alloced("/");
			/* / */
			/* /= */	
		case '%':
			return copy_alloced("%");
			/* % */
			/* %= */
		case '<':
			return copy_alloced("<");
			/* < */
			/* << */
			/* <= */
			/* <<= */
		case '>':
			return copy_alloced(">");
			/* > */
			/* >> */
			/* >= */
			/* >>= */			
		case '=':
			return copy_alloced("=");
			/* = */
			/* == */
		case '|':
			return copy_alloced("|");
			/* | */
			/* || */
			/* |= */
		case '^':
			return copy_alloced("^");
			/* ^ */
			/* ^= */
		case '?':
			return copy_alloced("?");
		case ':':
			return copy_alloced(":");
		case ';':
			return copy_alloced(";");
		/* Constants */

		case '\'':
			return copy_alloced("'");
		/* String Literals */
		/* Questioning if this even belongs here?*/
		case '"':
			return copy_alloced("\"");
			break;
		
		default:
			return return_keyword(word);
			break;
		
		
	}
    return NULL;
}

char *return_keyword(char *word)
{
	if (word == NULL){
		return NULL;
	}
	
	size_t size = strlen(word);
	int i;
	for(i = 0; i < size; i++){
		if( !isdigit(word[i]) && !isalpha(word[i]) && word[i] != '_'){
			break;	
		}
	}
	/* 'i' is the size of the valid keyword or id */
	char *keyword = (char *)xmalloc(sizeof(char)* i  + 1);
	
	strcpy(keyword, word);
	keyword[i] = '\0';
	
	return keyword;
	
}

int is_valid_id(char *word)
{
	size_t size = strlen(word);
	
	int j;
	for(j = 0; j < size; j++){
		if( !isalpha(word[j]) && !isdigit(word[j]) && word[j] != '_' ){
			
			return 0;
		}
		
	}

	return size;
}

int parse_tokens(char *word)
{
	size_t n, m;
	char *token = extract_token(word);
	char *tmp;
	size_t tk_size = strlen(token);
	size_t word_size = strlen(word);
	size_t diff = word_size - tk_size;
	size_t upto = tk_size;

	//printf("%s\n", token);
	//printf("tk_size: %d\n", tk_size);
	//printf("word_size: %d\n", word_size);
	//printf("diff: %d\n\n", diff);
	printf("\n");
	while(tk_size > 0){
		tmp = (char*)xmalloc(sizeof(char)*diff + 1);

		
		for(n = 0, m = upto; n < diff; n++, m++){
			tmp[n] = word[m];
		}	
		tmp[diff] = '\n';
		
		printf("Token: %s\n", token);
		printf("Tmp: %s\n\n", tmp);

		free(token);
		token = extract_token(tmp);
		tk_size = strlen(token);

		upto += tk_size;
		diff = word_size - upto;
		free(tmp);
		
	}

	return 0;

}

/* This is part of the parser! */
/*
char *get_lexeme(FILE *i)
{
	return NULL;
}

char *get_valid_id(char *lexeme)
{
	return NULL;
}

char *get_token_name(char *lexeme)
{
	return NULL;
}
*/


