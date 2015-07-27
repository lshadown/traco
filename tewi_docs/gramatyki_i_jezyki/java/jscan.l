%{
  #include <string.h>
  #include "jgram.tab.h"

  unsigned long ulLinenum=0;

  void lexical_error(const char *);
  static int token_for(const char *);
  static int is_allowed_char(const char );

%}

%option noyywrap
%option yylineno
%option stack

single_line_comment    "//".*

white_space            [ \t\r]

preprocessor           ^[ \t]*#.*

dec_digit              [0-9]
hex_digit              [0-9A-Fa-f]
int_suffix             [UuLl]|[Uu][Ll]|[Ll][Uu]
dec_literal            {dec_digit}+{int_suffix}?
hex_literal            0[xX]{hex_digit}+{int_suffix}?
integer_literal        {dec_literal}|{hex_literal}

real_suffix            [FfDdMm]
sign                   [+\-]
exponent_part          [eE]{sign}?{dec_digit}+
whole_real1            {dec_digit}+{exponent_part}{real_suffix}?
whole_real2            {dec_digit}+{real_suffix}
part_real              {dec_digit}*\.{dec_digit}+{exponent_part}?{real_suffix}?
real_literal           {whole_real1}|{whole_real2}|{part_real}

single_char            [^\\\']
simple_esc_seq         \\[\'\"\\0abfnrtv]
uni_esc_seq1           \\u{hex_digit}{4}
uni_esc_seq2           \\U{hex_digit}{8}
uni_esc_seq            {uni_esc_seq1}|{uni_esc_seq2}
hex_esc_seq            \\x{hex_digit}{1,4}
character              {single_char}|{simple_esc_seq}|{hex_esc_seq}|{uni_esc_seq}
character_literal      \'{character}\'


single_string_char     [^\\\"]
reg_string_char        {single_string_char}|{simple_esc_seq}|{hex_esc_seq}|{uni_esc_seq}
regular_string         \"{reg_string_char}*\"
single_verbatim_char   [^\"]
quote_esc_seq          \"\"
verb_string_char       {single_verbatim_char}|{quote_esc_seq}
verbatim_string        @\"{verb_string_char}*\"
string_literal         {regular_string}|{verbatim_string}


letter_char            [A-Za-z]
ident_char             {dec_digit}|{letter_char}|"_"|"@"
identifier             ({letter_char}|"_"){ident_char}*
at_identifier          \@{identifier}


%x IN_COMMENT


%%

{preprocessor}        { ; /* ignore */ }
{white_space}         { ; /* ignore */ }

                      /***** Comments *****/
"/*"                  { yy_push_state(IN_COMMENT); }
<IN_COMMENT>.         { ; /* ignore */ }
<IN_COMMENT>\n        { ; /* ignore */ }
<IN_COMMENT>"*/"      { yy_pop_state(); }

{single_line_comment} { ; /* ignore */ }

                      /***** Literals *****/
{integer_literal}     { return INT_LIT_TK; }
{real_literal}        { return FP_LIT_TK; }
{character_literal}   { return CHAR_LIT_TK; }
{string_literal}      { return STRING_LIT_TK; }

                      /*** Punctuation and Single-Character Operators ***/
","   { return C_TK; }
"["   { return OSB_TK; }
"]"   { return CSB_TK; }

                      /*** Multi-Character Operators ***/
"+="  { return PLUS_ASSIGN_TK; }
"-="  { return MINUS_ASSIGN_TK; }
"*="  { return MULT_ASSIGN_TK; }
"/="  { return DIV_ASSIGN_TK; }
"%="  { return REM_ASSIGN_TK; }
"^="  { return XOR_ASSIGN_TK; }
"&="  { return AND_ASSIGN_TK; }
"|="  { return OR_ASSIGN_TK; }
"<<"  { return LS_TK; }
">>"  { return SRS_TK; }
">>>" { return ZRS_TK; }
">>="  { return SRS_ASSIGN_TK; }
"<<="  { return LS_ASSIGN_TK; }
">>>=" { return ZRS_ASSIGN_TK; }
"=="  { return EQ_TK; }
"!="  { return NEQ_TK; }
"<="  { return LTE_TK; }
">="  { return GTE_TK; }
"&&"  { return BOOL_AND_TK; }
"||"  { return BOOL_OR_TK; }
"++"  { return INCR_TK; }
"--"  { return DECR_TK; }

      
                      /*** Those context-sensitive "keywords" ***/

{identifier}          { return token_for(yytext); }
{at_identifier}       { return ID_TK; }

\n 	{ ulLinenum++; }


.     { 
        if (is_allowed_char(yytext[0])) return yytext[0];
        else lexical_error("invalid token"); 
      }
%%


static struct name_value {
  char *name;
  int value;
} name_value;
static struct name_value keywords [] = { 
 /* This list must remain sorted!!! */
    {"abstract", ABSTRACT_TK},
    {"assert", ASSERT_TK},
    {"bool", BOOLEAN_TK},
    {"break", BREAK_TK},
    {"byte", BYTE_TK},
    {"case", CASE_TK},
    {"catch", CATCH_TK},
    {"char", CHAR_TK},
    {"class", CLASS_TK},
    {"const", CONST_TK},
    {"continue", CONTINUE_TK},
    {"default", DEFAULT_TK},
    {"do", DO_TK},
    {"double", DOUBLE_TK},
    {"else", ELSE_TK},
    {"extends", EXTENDS_TK},
    {"false", FALSE_TK},
    {"final", FINAL_TK},
    {"finally", FINALLY_TK},
    {"float", FLOAT_TK},
    {"for", FOR_TK},
    {"goto", GOTO_TK},
    {"if", IF_TK},
    {"implements", IMPLEMENTS_TK},
    {"import", IMPORT_TK},
    {"instanceof", INSTANCEOF_TK},
    {"int", INT_TK},
    {"interface", INTERFACE_TK},
    {"long", LONG_TK},
    {"native", NATIVE_TK},
    {"new", NEW_TK},
    {"null", NULL_TK},
    {"package", PACKAGE_TK},
    {"private", PRIVATE_TK},
    {"protected", PROTECTED_TK},
    {"public", PUBLIC_TK},
    {"return", RETURN_TK},
    {"short", SHORT_TK},
    {"static", STATIC_TK},
    {"super", SUPER_TK},
    {"switch", SWITCH_TK},
    {"synchronized", SYNCHRONIZED_TK},
    {"this", THIS_TK},
    {"throw", THROW_TK},
    {"throws", THROWS_TK},
    {"transient", TRANSIENT_TK},
    {"true", TRUE_TK},
    {"try", TRY_TK},
    {"void", VOID_TK},
    {"volatile", VOLATILE_TK},
    {"while", WHILE_TK},
  };    

static int bin_search(const char *lexeme, int start, int finish)
{
  if (start >= finish)  /* Not found */
      return ID_TK;
  else {
    int mid = (start+finish)/2;
    int cmp = strcmp(lexeme,keywords[mid].name);
    if (cmp == 0) 
      return keywords[mid].value;
    else if (cmp < 0)
      return bin_search(lexeme,start,mid);
    else
      return bin_search(lexeme,mid+1,finish);
  }
}

static int token_for(const char *lexeme)
{

  static int num_keywords = sizeof(keywords) / sizeof(name_value);
  int token = bin_search(lexeme,0,num_keywords);
  if (token == -1)
    token = ID_TK;
  return token;
}

static int is_allowed_char(const char c)
{
  static char allowed [] = {
    '.', ';', ':',
    '(', ')', '{', '}', '<', '>',
    '+', '-', '*', '/', '%', '&', '|', '!', '~', '^',
    '=', '?',
  };
  static int num_allowed = sizeof(allowed) / sizeof(char);
  int i;
  for (i=0; i<num_allowed; i++) {
    if (allowed[i]==c) 
      return 1;
  }
  return 0;
}

void lexical_error(const char *msg)
{
  fprintf(stderr,"%d:lexical error (%s) [%s]\n",yylineno,msg,yytext);
}
