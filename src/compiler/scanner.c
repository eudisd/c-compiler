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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
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
                    parse_tokens(o,word);
                }
				break;

			/* Now, we deal with other tokens (operators, constants, id's, etc) */

			case '{':
                if( !strcmp(word, "{") ) {
                    sprintf(tk_buffer0, "%d", TK_LEFTBRACKET);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case '}':
                if( !strcmp(word, "}") ) {
                    sprintf(tk_buffer0, "%d", TK_RIGHTBRACKET);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case '(':
				/* ( */
				/* (casting) */
                if( !strcmp(word, "(") ) {
                    sprintf(tk_buffer0, "%d", TK_LEFTPAREN);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case ')':
                if( !strcmp(word, ")") ) {
                    sprintf(tk_buffer0, "%d", TK_RIGHTPAREN);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case ']':
                if( !strcmp(word, "]") ) {
                    sprintf(tk_buffer0, "%d", TK_RIGHT_SQR_BRACKET);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case '[':
                if( !strcmp(word, "[") ) {
                    sprintf(tk_buffer0, "%d", TK_LEFT_SQR_BRACKET);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case '.':
                if( !strcmp(word, ".") ) {
                    sprintf(tk_buffer0, "%d", TK_DOT);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;
            
            case ',':
                if( !strcmp(word, ",") ) {
                    sprintf(tk_buffer0, "%d", TK_COMMA);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case '!':
                if( !strcmp(word, "!") ) {
                    sprintf(tk_buffer0, "%d", TK_UNARY_EXCLAMATION);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case '~':
                /* ~ */
				/* ~= */
                if( !strcmp(word, "~") ) {
                    sprintf(tk_buffer0, "%d", TK_UNARY_TILDA);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				
				break;
			
			case '+':
				/* + */
				/* ++ */
				/* += */
                if( !strcmp(word, "+") ) {
                    sprintf(tk_buffer0, "%d", TK_PLUS);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case '-':
				/* - */
				/* -- */
				/* -= */
                if( !strcmp(word, "-") ) {
                    sprintf(tk_buffer0, "%d", TK_MINUS);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case '*':
				/* * */
                 /* Is it a mult?  Is it a dereference?  is it a pointer?  Is it a santactic sugar?
                    these are all questions which must be answered here */
				/* *= */
                if( !strcmp(word, "*") ) {
                    sprintf(tk_buffer0, "%d", TK_MULT_STAR);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case '&':
                if( !strcmp(word, "&") ) {
                    sprintf(tk_buffer0, "%d", TK_BIT_AMPERSAND);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				/* & */
				/* && */
				/* &= */
				break;

			case '/':
				/* / */
				/* /= */
                if( !strcmp(word, "/") ) {
                    sprintf(tk_buffer0, "%d", TK_DIV);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;
			
			case '%':
                if( !strcmp(word, "%") ) {
                    sprintf(tk_buffer0, "%d", TK_MOD);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				/* % */
				/* %= */
				break;

			case '<':
                if( !strcmp(word, "<") ) {
                    sprintf(tk_buffer0, "%d", TK_LESS_LOGIC);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				/* < */
				/* << */
				/* <= */
				/* <<= */
				break;

			case '>':
                if( !strcmp(word, ">") ) {
                    sprintf(tk_buffer0, "%d", TK_GREATER_LOGIC);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				/* > */
				/* >> */
				/* >= */
				/* >>= */			
				break;

			case '=':
                if( !strcmp(word, "=") ) {
                    sprintf(tk_buffer0, "%d", TK_EQU);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				/* = */
				/* == */
				break;

			case '|':
                /* | */
				/* || */
				/* |= */
                if( !strcmp(word, "|") ) {
                    sprintf(tk_buffer0, "%d", TK_BIT_OR);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				
				break;

			case '^':
                /* ^ */
				/* ^= */
                if( !strcmp(word, "^") ) {
                    sprintf(tk_buffer0, "%d", TK_BIT_XOR);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				
				break;

			case '?':
                if( !strcmp(word, "?") ) {
                    sprintf(tk_buffer0, "%d", TK_QUESTION);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;

			case ':':
                if( !strcmp(word, ":") ) {
                    sprintf(tk_buffer0, "%d", TK_COLON);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
				break;
            
            case ';':
                if( !strcmp(word, ";") ) {
                    sprintf(tk_buffer0, "%d", TK_SEMICOLON);
                    put_ulexeme(o, tk_buffer0);
                }
                else {
                    parse_tokens(o,word);
                }
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
                parse_tokens(o, word);
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

int parse_tokens(FILE *o, char *word)
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

int get_sval(char *s)
{
    if( !strcmp(s, "{") )
        return TK_LEFTBRACKET;
    else if( !strcmp(s, "}") )
        return TK_RIGHTBRACKET;
    else if( !strcmp(s, "(") )
        return TK_LEFTPAREN;
    else if( !strcmp(s, ")") )
        return TK_RIGHTPAREN;
    else if( !strcmp(s, "[") )
        return TK_LEFT_SQR_BRACKET;
    else if( !strcmp(s, "]") )
        return TK_RIGHT_SQR_BRACKET;
    else if( !strcmp(s, ".") )
        return TK_DOT;
    else if( !strcmp(s, "!") )
        return TK_UNARY_EXCLAMATION;
    else if( !strcmp(s, "~") )
        return TK_UNARY_TILDA;
    else if( !strcmp(s, "++") )
        return TK_UNARY_PLUSPLUS;
    else if( !strcmp(s, "--") )
        return TK_UNARY_MINUSMINUS;
    else if( !strcmp(s, "+") )
        return TK_PLUS;
    else if( !strcmp(s, "-") )
        return TK_MINUS;
    else if( !strcmp(s, "*") )
        return TK_UNARY_STAR;
    else if( !strcmp(s, "&") )
        return TK_UNARY_AMPERSAND;
    else if( !strcmp(s, "/") )
        return TK_DIV;
    else if( !strcmp(s, "%") )
        return TK_MOD;
    else if( !strcmp(s, "<<") )
        return TK_LEFT_SHIFT;
    else if( !strcmp(s, ">>") )
        return TK_RIGHT_SHIFT;
    else if( !strcmp(s, "<") )
        return TK_LESS_LOGIC;
    else if( !strcmp(s, ">") )
        return TK_GREATER_LOGIC;
    else if( !strcmp(s, ">=") )
        return TK_GREATER_EQU_LOGIC;
    else if( !strcmp(s, "<=") )
        return TK_LESS_EQU_LOGIC;
    else if( !strcmp(s, "==") )
        return TK_EQU_EQU_LOGIC;
    else if( !strcmp(s, "!=") )
        return TK_NOT_EQU_LOGIC;
    else if( !strcmp(s, "^") )
        return TK_BIT_XOR;
    else if( !strcmp(s, "|") )
        return TK_BIT_OR;
    else if( !strcmp(s, "&&") )
        return TK_LOGIC_AND;
    else if( !strcmp(s, "||") )
        return TK_LOGIC_OR;
    else if( !strcmp(s, "?") )
        return TK_QUESTION;
    else if( !strcmp(s, ":") )
        return TK_COLON;
    else if( !strcmp(s, ";") )
        return TK_SEMICOLON;
    else if( !strcmp(s, "=") )
        return TK_EQU;
    else if( !strcmp(s, "+=") )
        return TK_PLUS_EQU;
    else if( !strcmp(s, "-=") )
        return TK_MINUS_EQU;
    else if( !strcmp(s, "*=") )
        return TK_STAR_EQU;
    else if( !strcmp(s, "/=") )
        return TK_DIV_EQU;
    else if( !strcmp(s, "%=") )
        return TK_MOD_EQU;
    else if( !strcmp(s, "&=") )
        return TK_AND_EQU;
    else if( !strcmp(s, "^=") )
        return TK_XOR_EQU;
    else if( !strcmp(s, "|=") )
        return TK_OR_EQU;
    else if( !strcmp(s, "<=") )
        return TK_LSHIFT_EQU;
    else if( !strcmp(s, ">=") )
        return TK_RSHIFT_EQU;
    else if( !strcmp(s, ",") )
        return TK_COMMA;
    else if( !strcmp(s, "") )
        return TK_LEFTPAREN;
    else if( !strcmp(s, ")") )
        return TK_RIGHTPAREN;
    else if( !strcmp(s, "auto") )
        return TK_AUTO;
    else if( !strcmp(s, "break") )
        return TK_BREAK;
    else if( !strcmp(s, "case") )
        return TK_CASE;
    else if( !strcmp(s, "char") )
        return TK_CHAR;
    else if( !strcmp(s, "const") )
        return TK_CONST;
    else if( !strcmp(s, "continue") )
        return TK_CONTINUE;
    else if( !strcmp(s, "default") )
        return TK_DEFAULT;
    else if( !strcmp(s, "do") )
        return TK_DO;
    else if( !strcmp(s, "double") )
        return TK_DOUBLE;
    else if( !strcmp(s, "else") )
        return TK_ELSE;
    else if( !strcmp(s, "enum") )
        return TK_ENUM;
    else if( !strcmp(s, "extern") )
        return TK_EXTERN;
    else if( !strcmp(s, "float") )
        return TK_FLOAT;
    else if( !strcmp(s, "for") )
        return TK_FOR;
    else if( !strcmp(s, "goto") )
        return TK_GOTO;
    else if( !strcmp(s, "if") )
        return TK_IF;
    else if( !strcmp(s, "int") )
        return TK_INT;
    else if( !strcmp(s, "long") )
        return TK_LONG;
    else if( !strcmp(s, "register") )
        return TK_REGISTER;
    else if( !strcmp(s, "return") )
        return TK_RETURN;
    else if( !strcmp(s, "short") )
        return TK_SHORT;
    else if( !strcmp(s, "signed") )
        return TK_SIGNED;
    else if( !strcmp(s, "sizeof") )
        return TK_SIZEOF;
    else if( !strcmp(s, "static") )
        return TK_STATIC;
    else if( !strcmp(s, "struct") )
        return TK_STRUCT;
    else if( !strcmp(s, "switch") )
        return TK_SWITCH;
    else if( !strcmp(s, "typedef") )
        return TK_TYPEDEF;
    else if( !strcmp(s, "union" ) )
        return TK_UNION;
    else if( !strcmp(s, "unsigned") )
        return TK_UNSIGNED;
    else if( !strcmp(s, "void") )
        return TK_VOID;
    else if( !strcmp(s, "volatile") )
        return TK_VOLATILE;
    else if( !strcmp(s, "while") )
        return TK_WHILE;
    

#define TK_SEMICOLON           85
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


