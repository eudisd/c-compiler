/** \file scanner.c
	\brief Contains all lexical analyzer operations.
  */

#include "scanner.h"

symbol_table *string_table;

void run_scanner(file_struct *file)
{
	char *word;
    int _u = 0;
    
    string_table = create_stab(MAX_SLOTS);
    /* Dispatcher. Suggested by professor Vulis to eliminate comparison overhead 
       incurred by switch statement!  Very nice.
    */
    void (*dispatcher[255])(FILE *o, char *word);

    /* Set everything on the dispatcher to the default job */

    for(_u = 0; _u < 256; _u++)
        dispatcher[_u] = &default_;

    dispatcher['a'] = &a;
    dispatcher['b'] = &b;
    dispatcher['c'] = &c;
    dispatcher['d'] = &d;
    dispatcher['e'] = &e;				
    dispatcher['f'] = &f;
    dispatcher['g'] = &g;
    dispatcher['i'] = &i;
    dispatcher['l'] = &l;
    dispatcher['r'] = &r;
    dispatcher['s'] = &s;
    dispatcher['t'] = &t;
    dispatcher['u'] = &u;
    dispatcher['v'] = &v;
    dispatcher['w'] = &w;
    dispatcher['{'] = &leftbracket;
    dispatcher['}'] = &rightbracket;
    dispatcher['('] = &leftparen;
    dispatcher[')'] = &rightparen;
    dispatcher['['] = &left_sqr_bracket;
    dispatcher[']'] = &right_sqr_bracket;
    dispatcher['.'] = &dot;
    dispatcher[','] = &comma;
    dispatcher['!'] = &exclamation;
    dispatcher['~'] = &tilda;
    dispatcher['+'] = &plus;
    dispatcher['-'] = &minus;
    dispatcher['*'] = &unary_star;
    dispatcher['&'] = &ampersand;		
    dispatcher['/'] = &div_;
    dispatcher['%'] = &mod;
    dispatcher['<'] = &less;		
    dispatcher['>'] = &greater;
    dispatcher['='] = &equal;
    dispatcher['|'] = &or;
    dispatcher['^'] = &xor;
    dispatcher['?'] = &question;
    dispatcher[':'] = &colon;
    dispatcher[';'] = &semicolon;
    //dispatcher['$'] = &constant;
    //dispatcher['$'] = &stringlit;
    
	FILE *i = fopen(INTERIM_FILENAME, "r");
	FILE *o = fopen("data.tmp", "w");
   
	/* getword() returns a string, so a NULL signifies that
     * nothing useful was retrieved from the input stream 
	 */
    
	while( (word = getword(i)) != NULL ){
		dispatcher[word[0]](o, word);
		free(word);
	}
    
    print_stab(string_table);

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
			if (word[1] == '=')
                return copy_alloced("~=");
            else
                return copy_alloced("~");
		case '+':
			if (word[1] == '+')
                return copy_alloced("++");
            else if (word[1] == '=')
                return copy_alloced("+=");
            else
                return copy_alloced("+");
		case '-':
			if (word[1] == '-')
                return copy_alloced("--");
			else if (word[1] == '=')
                return copy_alloced("-=");
			else
                return copy_alloced("-");
		case '*':
			if(word[1] == '=')  
                return copy_alloced("*=");
			else 
                return copy_alloced("*");
                
		case '&':
			if(word[1] == '&')
                return copy_alloced("&&");
            else if (word[1] == '=')
                return copy_alloced("&=");
            else 
                return copy_alloced("&");

		case '/':
            if(word[0] == '=')
                return copy_alloced("/=");
            else
			    return copy_alloced("/");
			
		case '%':
			if( word[1] == '=' )
                return copy_alloced("%=");
            else 
                return copy_alloced("%");
			
		case '<':
			if( word[1] == '<' ){
                if (word[2] == '=')
                    return copy_alloced("<<=");
                else
                    return copy_alloced("<<");
            }
            else if (word[1] == '=')
                return copy_alloced("<=");
            else 
                return copy_alloced("<");
     
		case '>':
			if( word[1] == '>' ){
                if (word[2] == '=')
                    return copy_alloced(">>=");
                else
                    return copy_alloced(">>");
            }
            else if (word[1] == '=')
                return copy_alloced(">=");
            else 
                return copy_alloced(">");	
        	
		case '=':
			if( word[1] == '=' )
                return copy_alloced("==");
            else
                return copy_alloced("=");
		case '|':
			if (word[1] == '|')
                return copy_alloced("||");
            else if (word[1] == '=')
                return copy_alloced("|=");
            else 
                return copy_alloced("|");
		case '^':
			if (word[1] == '=')
                return copy_alloced("^=");
            else 
                return copy_alloced("^");
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
			return return_string(word);
			break;
		
		default:
			return return_keyword(word);
			break;
		
		
	}
    return NULL;
}

char *return_string(char *word)
{
    int i, j;
    size_t size = strlen(word);
    char *tmp;
    for(i = 1; i < size; i++){
        if( word[i] == '"' ){
            i++;
            break;
        }
    }

    tmp = (char*)xmalloc(sizeof(char)*i + 1);

    for(j = 0; j < i; j++){
        tmp[j] = word[j];
    }

    tmp[i] = '\0';
    
    
    return tmp;
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
    int index;  /**> Used for the hash return value */
	size_t n, m;
	char *token = extract_token(word);
	char *tmp;
	size_t tk_size = strlen(token);
	size_t word_size = strlen(word);
	size_t diff = word_size - tk_size;
	size_t upto = tk_size;

    token_package tk;

	while(tk_size > 0){
		tmp = (char*)xmalloc(sizeof(char)*diff + 1);

		for(n = 0, m = upto; n < diff; n++, m++){
			tmp[n] = word[m];
		}	
		tmp[diff] = '\n';
		
		tk = get_sval(token);
        //printf("Token: %s\n", token);

        if (tk.type == -1){
            sprintf(tk_buffer0, "%d", tk.val);
            put_ulexeme(o, tk_buffer0);
        }
        else if (tk.type == TK_KEYWORD) {
            sprintf(tk_buffer0, "%d", TK_KEYWORD);
            sprintf(tk_buffer1, "%d", tk.val);
                    
            put_lexeme(o, tk_buffer0, tk_buffer1);
        }
        else if (tk.type == TK_FLOATLIT){

        }
        else if (tk.type == TK_STRINGLIT) {
            
            record *rec = (record*)get_record(token, "no-value", 'S', 0, "\0");
            stab_insert("c-string-literal", rec, string_table);
            index = hash(rec->name, string_table->size);
            /* If there are any collisions, the we just ignore those.  I 
             * output the slot number of the hash, and the TK_STRINLIT token
             */
            sprintf(tk_buffer0, "%d", TK_STRINGLIT);
            sprintf(tk_buffer1, "%d", index);
                    
            put_lexeme(o, tk_buffer0, tk_buffer1);
        }
        
        else if (tk.type == TK_INTLIT) {

        }
                    
		free(token);
		token = extract_token(tmp);
		tk_size = strlen(token);

		upto += tk_size;
		diff = word_size - upto;
		free(tmp);
	}
	return 0;

}

token_package get_sval(char *s)
{
    token_package tk;
    
    if( !strcmp(s, "{") ){
        tk.type = -1;
        tk.val = TK_LEFTBRACKET;
    }
    else if( !strcmp(s, "}") ){
        tk.type = -1;
        tk.val = TK_RIGHTBRACKET;
    }
    else if( !strcmp(s, "(") ){
        tk.type = -1;
        tk.val = TK_LEFTPAREN;
    }
    else if( !strcmp(s, ")") ){
        tk.type = -1;
        tk.val = TK_RIGHTPAREN;
    }
    else if( !strcmp(s, "[") ){
        tk.type = -1;
        tk.val = TK_LEFT_SQR_BRACKET;
    }
    else if( !strcmp(s, "]") ){
        tk.type = -1;
        tk.val = TK_RIGHT_SQR_BRACKET;
    }
    else if( !strcmp(s, ".") ){
        tk.type = -1;
        tk.val = TK_DOT;
    }
    else if( !strcmp(s, "!") ){
        tk.type = -1;
        tk.val = TK_UNARY_EXCLAMATION;
    }
    else if( !strcmp(s, "~") ){
        tk.type = -1;
        tk.val = TK_UNARY_TILDA;
    }
    else if( !strcmp(s, "++") ){
        tk.type = -1;
        tk.val = TK_UNARY_PLUSPLUS;
    }
    else if( !strcmp(s, "--") ){
        tk.type = -1;
        tk.val = TK_UNARY_MINUSMINUS;
    }
    else if( !strcmp(s, "+") ){
        tk.type = -1;
        tk.val = TK_PLUS; 
    }
    else if( !strcmp(s, "-") ){
        tk.type = -1;
        tk.val = TK_MINUS;
    }
    else if( !strcmp(s, "*") ){
        tk.type = -1;
        tk.val = TK_UNARY_STAR;
    }
    else if( !strcmp(s, "&") ){
        tk.type = -1;
        tk.val = TK_UNARY_AMPERSAND;
    }
    else if( !strcmp(s, "/") ){
        tk.type = -1;
        tk.val = TK_DIV;
    }
    else if( !strcmp(s, "%") ){
        tk.type = -1;
        tk.val = TK_MOD;
    }
    else if( !strcmp(s, "<<") ){
        tk.type = -1;
        tk.val = TK_LEFT_SHIFT;
    }
    else if( !strcmp(s, ">>") ){
        tk.type = -1;
        tk.val = TK_RIGHT_SHIFT;
    }
    else if( !strcmp(s, "<") ){
        tk.type = -1;
        tk.val = TK_LESS_LOGIC;
    }
    else if( !strcmp(s, ">") ){
        tk.type = -1;
        tk.val = TK_GREATER_LOGIC;
    }
    else if( !strcmp(s, ">=") ){
        tk.type = -1;
        tk.val = TK_GREATER_EQU_LOGIC;
    }
    else if( !strcmp(s, "<=") ){
        tk.type = -1;
        tk.val = TK_LESS_EQU_LOGIC;
    }
    else if( !strcmp(s, "==") ){
        tk.type = -1;
        tk.val = TK_EQU_EQU_LOGIC;
    }
    else if( !strcmp(s, "!=") ){
        tk.type = -1;
        tk.val = TK_NOT_EQU_LOGIC;
    }
    else if( !strcmp(s, "^") ){
        tk.type = -1;
        tk.val = TK_BIT_XOR;
    }
    else if( !strcmp(s, "|") ){
        tk.type = -1;
        tk.val = TK_BIT_OR;
    }
    else if( !strcmp(s, "&&") ){
        tk.type = -1;
        tk.val = TK_LOGIC_AND;
    }
    else if( !strcmp(s, "||") ){
        tk.type = -1;
        tk.val = TK_LOGIC_OR;
    }
    else if( !strcmp(s, "?") ){
        tk.type = -1;
        tk.val = TK_QUESTION;
    }
    else if( !strcmp(s, ":") ){
        tk.type = -1;
        tk.val = TK_COLON;
    }
    else if( !strcmp(s, ";") ){
        tk.type = -1;
        tk.val = TK_SEMICOLON;
    }
    else if( !strcmp(s, "=") ){
        tk.type = -1;
        tk.val = TK_EQU;
    }
    else if( !strcmp(s, "+=") ){
        tk.type = -1;
        tk.val = TK_PLUS_EQU;
    }
    else if( !strcmp(s, "-=") ){
        tk.type = -1;
        tk.val = TK_MINUS_EQU;
    }
    else if( !strcmp(s, "*=") ){
        tk.type = -1;
        tk.val = TK_STAR_EQU;
    }
    else if( !strcmp(s, "/=") ){
        tk.type = -1;
        tk.val = TK_DIV_EQU;
    }
    else if( !strcmp(s, "%=") ){
        tk.type = -1;
        tk.val = TK_MOD_EQU;
    }
    else if( !strcmp(s, "&=") ){
        tk.type = -1;
        tk.val = TK_AND_EQU;
    }
    else if( !strcmp(s, "^=") ){
        tk.type = -1;
        tk.val = TK_XOR_EQU;
    }
    else if( !strcmp(s, "|=") ){
        tk.type = -1;
        tk.val = TK_OR_EQU;
    }
    else if( !strcmp(s, "<=") ){
        tk.type = -1;
        tk.val = TK_LSHIFT_EQU;
    }
    else if( !strcmp(s, ">=") ){
        tk.type = -1;
        tk.val = TK_RSHIFT_EQU;
    }
/*** NEW AND NOT COMPLETE  ****/
    else if( !strcmp(s, "<<=") ){
        tk.type = -1;
        tk.val = TK_LSHIFT_EQU;
    }
    else if( !strcmp(s, ">>=") ){
        tk.type = -1;
        tk.val = TK_RSHIFT_EQU;
    }
    
/*** NEW AND NOT COMPLETE END ***/
    else if( !strcmp(s, ",") ){
        tk.type = -1;
        tk.val = TK_COMMA;
    }
    else if( !strcmp(s, "") ){
        tk.type = -1;
        tk.val = TK_LEFTPAREN;
    }
    else if( !strcmp(s, ")") ){
        tk.type = -1;
        tk.val = TK_RIGHTPAREN;
    }
    else if( !strcmp(s, "auto") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_AUTO;
    }
    else if( !strcmp(s, "break") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_BREAK;
    }
    else if( !strcmp(s, "case") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_CASE;
    }
    else if( !strcmp(s, "char") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_CHAR;
    }
    else if( !strcmp(s, "const") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_CONST;
    }
    else if( !strcmp(s, "continue") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_CONTINUE;
    }
    else if( !strcmp(s, "default") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_DEFAULT;
    }
    else if( !strcmp(s, "do") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_DO;
    }
    else if( !strcmp(s, "double") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_DOUBLE;
    }
    else if( !strcmp(s, "else") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_ELSE;
    }
    else if( !strcmp(s, "enum") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_ENUM;
    }
    else if( !strcmp(s, "extern") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_EXTERN;
    }
    else if( !strcmp(s, "float") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_FLOAT;
    }
    else if( !strcmp(s, "for") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_FOR;
    }
    else if( !strcmp(s, "goto") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_GOTO;
    }
    else if( !strcmp(s, "if") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_IF;
    }
    else if( !strcmp(s, "int") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_INT;
    }
    else if( !strcmp(s, "long") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_LONG;
    }
    else if( !strcmp(s, "register") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_REGISTER;
    }
    else if( !strcmp(s, "return") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_RETURN;
    }
    else if( !strcmp(s, "short") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_SHORT;
    }
    else if( !strcmp(s, "signed") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_SIGNED;
    }
    else if( !strcmp(s, "sizeof") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_SIZEOF;
    }
    else if( !strcmp(s, "static") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_STATIC;
    }
    else if( !strcmp(s, "struct") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_STRUCT;
    }
    else if( !strcmp(s, "switch") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_SWITCH;
    }
    else if( !strcmp(s, "typedef") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_TYPEDEF;
    }
    else if( !strcmp(s, "union" ) ){
        tk.type = TK_KEYWORD;
        tk.val = TK_UNION;
    }
    else if( !strcmp(s, "unsigned") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_UNSIGNED;
    }
    else if( !strcmp(s, "void") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_VOID;
    }
    else if( !strcmp(s, "volatile") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_VOLATILE;
    }
    else if( !strcmp(s, "while") ){
        tk.type = TK_KEYWORD;
        tk.val = TK_WHILE;
    }

    else {
        if( s[0] == '\"'){
            tk.type = TK_STRINGLIT;
            tk.val = 0;
        }
        else {
            // Return integer tk,
            // or Float tk
        
        }
        

    }
    
    return tk;
}

/************************* DISPATCH *****************************/

void a(FILE *o, char *word)
{
    /* auto */
    if ( !strcmp(word, "auto") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_AUTO);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}

void b(FILE *o, char *word)
{
    /* break */
    if ( !strcmp(word, "break") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_BREAK);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}
void c(FILE *o, char *word)
{
    /* case */
    /* char */
    /* const */
    /* continue */
    if( !strcmp(word, "case") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_CASE);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "char") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_CHAR);
        put_lexeme(o, tk_buffer0, tk_buffer1);
                    
    }   
    else if ( !strcmp(word, "const") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_CONST);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "continue") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_CONTINUE);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}
void d(FILE *o, char *word)
{
    /* default */
    /* do */
    /* double */
    if( !strcmp(word, "default") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_DEFAULT);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "do") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_DO);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }   
    else if ( !strcmp(word, "double") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_DOUBLE);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}
void e(FILE *o, char *word)
{
    /* else */
    /* enum */
    /* extern */
    if( !strcmp(word, "else") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_ELSE);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "enum") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_ENUM);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }   
    else if ( !strcmp(word, "extern") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_EXTERN);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}
				
void f(FILE *o, char *word)
{
    /* float */
	/* for */
    if( !strcmp(word, "float") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_FLOAT);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "for") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_FOR);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}

void g(FILE *o, char *word)
{
    /* goto */
    if( !strcmp(word, "goto") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_GOTO);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}
void i(FILE *o, char *word)
{
    /* int */
    /* if */
    
    if( !strcmp(word, "int") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_INT);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "if") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_IF);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {  
        
        parse_tokens(o,word);
    }
}
void l(FILE *o, char *word)
{
    /* long */
    if( !strcmp(word, "long") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_LONG);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}
void r(FILE *o, char *word)
{
    /* register */
    /* return */
    if( !strcmp(word, "register") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_REGISTER);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "return") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_RETURN);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}
void s(FILE *o, char *word)
{
    /* short */
    /* signed */
    /* sizeof */
    /* static */
    /* struct */
    /* switch */
    if( !strcmp(word, "short") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_SHORT);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "signed") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_SIGNED);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "sizeof") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_SIZEOF);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    } 
    else if ( !strcmp(word, "static") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_STATIC);
        put_lexeme(o, tk_buffer0, tk_buffer1);
        }
    else if ( !strcmp(word, "struct") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_STRUCT);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    } 
    else if ( !strcmp(word, "switch") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_SWITCH);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    } 
    else {
        parse_tokens(o,word);
    }
}

void t(FILE *o, char *word)
{
    /* typedef */
    if( !strcmp(word, "typedef") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_TYPEDEF);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}
void u(FILE *o, char *word)
{
    /* union */
    /* unsigned */
    if( !strcmp(word, "union") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_UNION);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "unsigned") ){
        
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_UNSIGNED);
        put_lexeme(o, tk_buffer0, tk_buffer1);
        }
    else {
        parse_tokens(o,word);
    }
}
void v(FILE *o, char *word)
{
    /* void */
    /* volatile */
    if( !strcmp(word, "void") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_VOID);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else if ( !strcmp(word, "volatile") ){
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_VOLATILE);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
}
void w(FILE *o, char *word)
{
    /* while */
    if( !strcmp(word, "while") ) {
        sprintf(tk_buffer0, "%d", TK_KEYWORD);
        sprintf(tk_buffer1, "%d", TK_WHILE);
        put_lexeme(o, tk_buffer0, tk_buffer1);
    }
    else {
        parse_tokens(o,word);
    }
				
}
void leftbracket(FILE *o, char *word)
{
    if( !strcmp(word, "{") ) {
        sprintf(tk_buffer0, "%d", TK_LEFTBRACKET);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void rightbracket(FILE *o, char *word)
{
    if( !strcmp(word, "}") ) {
        sprintf(tk_buffer0, "%d", TK_RIGHTBRACKET);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
		
void leftparen(FILE *o, char *word)
{
    /* ( */
    /* (casting) */
    if( !strcmp(word, "(") ) {
        sprintf(tk_buffer0, "%d", TK_LEFTPAREN);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void rightparen(FILE *o, char *word)
{
    if( !strcmp(word, ")") ) {
        sprintf(tk_buffer0, "%d", TK_RIGHTPAREN);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void left_sqr_bracket(FILE *o, char *word)
{
    if( !strcmp(word, "]") ) {
        sprintf(tk_buffer0, "%d", TK_RIGHT_SQR_BRACKET);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void right_sqr_bracket(FILE *o, char *word)
{
    if( !strcmp(word, "[") ) {
        sprintf(tk_buffer0, "%d", TK_LEFT_SQR_BRACKET);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void dot(FILE *o, char *word)
{
    if( !strcmp(word, ".") ) {
        sprintf(tk_buffer0, "%d", TK_DOT);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void comma(FILE *o, char *word)
{
    if( !strcmp(word, ",") ) {
        sprintf(tk_buffer0, "%d", TK_COMMA);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void exclamation(FILE *o, char *word)
{
    if( !strcmp(word, "!") ) {
        sprintf(tk_buffer0, "%d", TK_UNARY_EXCLAMATION);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void tilda(FILE *o, char *word)
{
    /* ~ */
    /* ~= */
    if( !strcmp(word, "~") ) {
        sprintf(tk_buffer0, "%d", TK_UNARY_TILDA);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void plus(FILE *o, char *word)
{
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
}
void minus(FILE *o, char *word)
{
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
}
void unary_star(FILE *o, char *word)
{
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
}
void ampersand(FILE *o, char *word)
{
    /* & */
    /* && */
    /* &= */
    if( !strcmp(word, "&") ) {
        sprintf(tk_buffer0, "%d", TK_BIT_AMPERSAND);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}			
void div_(FILE *o, char *word)
{
    /* / */
    /* /= */
    if( !strcmp(word, "/") ) {
        sprintf(tk_buffer0, "%d", TK_DIV);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void mod(FILE *o, char *word)
{
    /* % */
	/* %= */
    if( !strcmp(word, "%") ) {
        sprintf(tk_buffer0, "%d", TK_MOD);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void less(FILE *o, char *word)
{
    /* < */
    /* << */
    /* <= */
    /* <<= */
    if( !strcmp(word, "<") ) {
        sprintf(tk_buffer0, "%d", TK_LESS_LOGIC);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}			
void greater(FILE *o, char *word)
{
    /* > */
    /* >> */
    /* >= */
    /* >>= */	
    if( !strcmp(word, ">") ) {
        sprintf(tk_buffer0, "%d", TK_GREATER_LOGIC);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void equal(FILE *o, char *word)
{
    /* = */
    /* == */
    if( !strcmp(word, "=") ) {
        sprintf(tk_buffer0, "%d", TK_EQU);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void or(FILE *o, char *word)
{
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
}
void xor(FILE *o, char *word)
{
    /* ^ */
    /* ^= */
    if( !strcmp(word, "^") ) {
        sprintf(tk_buffer0, "%d", TK_BIT_XOR);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void question(FILE *o, char *word)
{
    if( !strcmp(word, "?") ) {
        sprintf(tk_buffer0, "%d", TK_QUESTION);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void colon(FILE *o, char *word)
{
    if( !strcmp(word, ":") ) {
        sprintf(tk_buffer0, "%d", TK_COLON);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}
void semicolon(FILE *o, char *word)
{
    if( !strcmp(word, ";") ) {
        sprintf(tk_buffer0, "%d", TK_SEMICOLON);
        put_ulexeme(o, tk_buffer0);
    }
    else {
        parse_tokens(o,word);
    }
}

			/* Constants */
void constant(FILE *o, char *word)
{
}
		
			/* String Literals */
void stringlit(FILE *o, char *word)
{
}

void default_(FILE *o, char *word)
{
    
    /* Try To See if it's a identifier, if not: 
    ERROR! Given token is not part of the lang def. */
    parse_tokens(o, word);
}
			
				
				
		


