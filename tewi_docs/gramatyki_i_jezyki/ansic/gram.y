/************************************************************************
 *									*
 * Gramatyka Jezyka C zgodna ze standardem ANSI				*
 * 									*
 * Zrodlo : Briam W. Kernighan, Dennis M. Ritchie [1994] "Jezyk ANSI C" *
 *          Wydawnictwo Naukowo Techniczne				*
 *	    								*
 * Autor  : Tomasz Klimek						*
 * Data   : 05-04-2006							*
 *									*
 ************************************************************************/

%{
  #include <stdio.h>
  #include <string.h>
  #include "stack.h"
  #include "list.h"
  #include "tree.h"
  #include "def.h"
  #include "bst.h"
 
  enum instructions { seq , nseq };
 
  extern char* yytext;
  extern int column;
  enum instructions insType = seq;
  enum side sideParent = prawy;

  char cFuncdef[100];
  char cFunc[100];
  char cTmp[100];

  unsigned long complex;
  double efficiency;

  list lHead,lTail;
  stos sMystos;
  node nTreenode;  
  bstnode tn = NULL;

  FILE* yyin;
%}

 %token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
 %token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
 %token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
 %token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
 %token XOR_ASSIGN OR_ASSIGN TYPE_NAME

 %token TYPEDEF EXTERN STATIC AUTO REGISTER
 %token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
 %token STRUCT UNION ENUM ELIPSIS RANGE

 %token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

 %start file
%%

primary_expr
	: identifier 
	| CONSTANT
	| STRING_LITERAL
	| '(' expr ')'
	;

postfix_expr
	: primary_expr
	| postfix_expr '[' expr ']'
	| postfix_expr '(' {
	                    if (strcmp(cTmp, cFuncdef))
	                     { 
			      add2tree(&nTreenode, lTail, sideParent, _CALL);
	          	      sideParent = lewy;
			     }
			    else 
			     {
			      add2tree(&nTreenode, lTail, sideParent, _REC);
	          	      sideParent = lewy;
			     }
			    insType = nseq;
			   } 
		       ')'
	| postfix_expr '(' { 
	                    if (strcmp(cTmp, cFuncdef))
	                     { 
			      add2tree(&nTreenode, lTail, sideParent, _CALL);
	          	      sideParent = lewy;
			     }
			    else 
			     {
			      add2tree(&nTreenode, lTail, sideParent, _REC);
	          	      sideParent = lewy;
			     }
	                    insType = nseq;
			   } 
	  argument_expr_list ')'
	| postfix_expr '.' identifier
	| postfix_expr PTR_OP identifier
	| postfix_expr INC_OP
	| postfix_expr DEC_OP
	;

argument_expr_list
	: assignment_expr
	| argument_expr_list ',' assignment_expr
	;

unary_expr
	: postfix_expr
	| INC_OP unary_expr
	| DEC_OP unary_expr
	| unary_operator cast_expr
	| SIZEOF unary_expr
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expr
	: unary_expr
	| '(' type_name ')' cast_expr
	;

multiplicative_expr
	: cast_expr
	| multiplicative_expr '*' cast_expr
	| multiplicative_expr '/' cast_expr
	| multiplicative_expr '%' cast_expr
	;

additive_expr
	: multiplicative_expr
	| additive_expr '+' multiplicative_expr
	| additive_expr '-' multiplicative_expr
	;

shift_expr
	: additive_expr
	| shift_expr LEFT_OP additive_expr
	| shift_expr RIGHT_OP additive_expr
	;

relational_expr
	: shift_expr
	| relational_expr '<' shift_expr
	| relational_expr '>' shift_expr
	| relational_expr LE_OP shift_expr
	| relational_expr GE_OP shift_expr
	;

equality_expr
	: relational_expr
	| equality_expr EQ_OP relational_expr
	| equality_expr NE_OP relational_expr
	;

and_expr
	: equality_expr
	| and_expr '&' equality_expr
	;

exclusive_or_expr
	: and_expr
	| exclusive_or_expr '^' and_expr
	;

inclusive_or_expr
	: exclusive_or_expr
	| inclusive_or_expr '|' exclusive_or_expr
	;

logical_and_expr
	: inclusive_or_expr
	| logical_and_expr AND_OP inclusive_or_expr
	;

logical_or_expr
	: logical_and_expr
	| logical_or_expr OR_OP logical_and_expr
	;

conditional_expr
	: logical_or_expr
	| logical_or_expr '?' logical_or_expr ':' conditional_expr
	;

assignment_expr
	: conditional_expr
	| unary_expr assignment_operator assignment_expr
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expr
	: assignment_expr
	| expr ',' assignment_expr
	;

constant_expr
	: conditional_expr
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: CHAR
	| SHORT
	| INT
	| LONG
	| SIGNED
	| UNSIGNED
	| FLOAT
	| DOUBLE
	| CONST
	| VOLATILE
	| VOID
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union identifier '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union identifier
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: type_specifier_list struct_declarator_list ';'
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expr
	| declarator ':' constant_expr
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM identifier '{' enumerator_list '}'
	| ENUM identifier
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: identifier
	| identifier '=' constant_expr
	;

declarator
	: declarator2 
	| pointer declarator2
	;

declarator2
	: identifier
	| '(' declarator ')'
	| declarator2 '[' ']'
	| declarator2 '[' constant_expr ']'
	| declarator2 '(' { strcpy(cFunc, cTmp); } ')'
	| declarator2 '(' { strcpy(cFunc, cTmp); } parameter_type_list ')' 
	| declarator2 '(' { strcpy(cFunc, cTmp); } parameter_identifier_list ')'
	;

pointer
	: '*'
	| '*' type_specifier_list
	| '*' pointer
	| '*' type_specifier_list pointer
	;

type_specifier_list
	: type_specifier
	| type_specifier_list type_specifier
	;

parameter_identifier_list
	: identifier_list
	| identifier_list ',' ELIPSIS
	;

identifier_list
	: identifier
	| identifier_list ',' identifier
	;

parameter_type_list
	: parameter_list
	| parameter_list ',' ELIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: type_specifier_list declarator
	| type_name
	;

type_name
	: type_specifier_list
	| type_specifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| abstract_declarator2
	| pointer abstract_declarator2
	;

abstract_declarator2
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expr ']'
	| abstract_declarator2 '[' ']'
	| abstract_declarator2 '[' constant_expr ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| abstract_declarator2 '(' ')'
	| abstract_declarator2 '(' parameter_type_list ')'
	;

initializer
	: assignment_expr
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement {
				if ( insType == seq ) 
				 {
				  add2tree(&nTreenode, lTail, sideParent, _SEQ);
  	          		  sideParent = lewy;
				 }
				else insType = seq;
			       }
	| selection_statement  
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: identifier ':' statement
	| CASE constant_expr ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expr ';'  
	;

selection_statement
	: if_stm statement { 
	                    Pop(&sMystos, &nTreenode);   
			    sideParent = lewy;
			   }
	| if_stm statement ELSE statement {
	                                   Pop(&sMystos, &nTreenode);   
 			                   sideParent = lewy;
	                                  }
	| SWITCH {
                  add2tree(&nTreenode, lTail, sideParent, _SWITCH);
  	          Push(&sMystos, nTreenode);
		  sideParent = prawy;
	         }
	  '(' expr ')' statement {
	                          Pop(&sMystos, &nTreenode);   
			          sideParent = lewy;
                                 }
	;

if_stm
   : IF '(' expr ')' { 
                      add2tree(&nTreenode, lTail, sideParent, _IF);
		      Push(&sMystos, nTreenode);
		      sideParent = prawy;
		     }
   ;


for_stm
   : FOR {
          add2tree(&nTreenode, lTail, sideParent, _FOR);
          Push(&sMystos, nTreenode);
          sideParent = prawy;
         }
   ;

iteration_statement
	: WHILE {
	         add2tree(&nTreenode, lTail, sideParent, _WHILE);
                 Push(&sMystos, nTreenode);
                 sideParent = prawy;
	        }
	  '(' expr ')' statement {
	                          Pop(&sMystos, &nTreenode); 
				  sideParent = lewy;                         
				 }
	| DO {
	      add2tree(&nTreenode, lTail, sideParent, _DO);
              Push(&sMystos, nTreenode);
              sideParent = prawy;
	     }
	  statement 
	  WHILE '(' expr ')' ';' { Pop(&sMystos, &nTreenode); sideParent = lewy; }
	| for_stm '(' ';' ';' ')' statement { Pop(&sMystos, &nTreenode); sideParent = lewy; }
	| for_stm '(' ';' ';' expr ')' statement { Pop(&sMystos, &nTreenode); sideParent = lewy; }
	| for_stm '(' ';' expr ';' ')' statement { Pop(&sMystos, &nTreenode); sideParent = lewy; }
	| for_stm '(' ';' expr ';' expr ')' statement { Pop(&sMystos, &nTreenode); sideParent = lewy; }
	| for_stm '(' expr ';' ';' ')' statement { Pop(&sMystos, &nTreenode); sideParent = lewy; }
	| for_stm '(' expr ';' ';' expr ')' statement { Pop(&sMystos, &nTreenode); sideParent = lewy; }
	| for_stm '(' expr ';' expr ';' ')' statement { Pop(&sMystos, &nTreenode); sideParent = lewy; }
	| for_stm '(' expr ';' expr ';' expr ')' statement { Pop(&sMystos, &nTreenode); sideParent = lewy; }
	;

jump_statement
	: GOTO identifier ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expr ';'
	;

file
	: external_definition
	| file external_definition
	;

external_definition
	: function_definition
	| declaration 
	;

function_definition
	: declarator { 
	              strcpy(cFuncdef, cFunc);
		      if ( Find(lHead, &lTail, cFuncdef) )
		       {
		        sMystos = NULL;
			nTreenode = NULL;
		       }
		      else yyerror("Blad w pliku konfiguracyjnym!\n");
		     }
	  function_body
	| declaration_specifiers 
	  declarator { 
	              strcpy(cFuncdef, cFunc); 
		      if ( Find(lHead, &lTail, cFuncdef) )
		       {
		        sMystos = NULL;
			nTreenode = NULL;
    	               }
		      else yyerror("Blad w pliku konfiguracyjnym!\n");
		     }
	  function_body
	;

function_body
	: compound_statement
	| declaration_list compound_statement
	;

identifier
	: IDENTIFIER { strcpy(cTmp,yytext); }
	;
%%


yyerror(s)
char *s;
{
 fflush(stdout);
 printf("%s\n", s);
 Clear_list(&lHead);
 Clear_stack(sMystos);
 exit(1);
}

int main(int argc,char* argv[])
{

 lHead = lTail = NULL;

 if ( argc == 4 )
  if ( read_def(argv[3], &lHead, &lTail, &tn))
   {
    yyin = fopen(argv[1],"r");
  
    if ( yyin == NULL )
     {
      puts("Blad przy otwieraniu pliku zrodlowego!");
      exit(1);
     }
  
    yyparse();

    Complexity(&lHead, argv[2], &complex, &efficiency);

    printf(" Calkowita zlozonosc komponentu : %d  [ CWU ]\n", complex);
    printf(" Calkowita efektywnosc komponentu : %f  [ CWU/LOC ]\n\n", efficiency);
    
    return 0;
    del4bsttree(tn);
   }
 puts("Nieprawidlowa ilosc parametrow wejsciowych!");
 del4bsttree(tn);
 return 1;
}
