
/* Parser grammar for quick source code scan of Java(TM) language programs.
   Copyright (C) 1998, 1999, 2000, 2002, 2003, 2004, 2005
   Free Software Foundation, Inc.
   Contributed by Alexandre Petit-Bianco (apbianco@cygnus.com)

   This file is part of GCC.

    GCC is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2, or (at your option)
    any later version.

    GCC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GCC; see the file COPYING.  If not, write to
    the Free Software Foundation, 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.

    Java and all Java-based marks are trademarks or registered trademarks
    of Sun Microsystems, Inc. in the United States and other countries.
    The Free Software Foundation is independent of Sun Microsystems, Inc.  */

    /* This file parses Java source code. Action can be further completed
    to achieve a desired behavior. This file isn't part of the Java
    language gcc front end.

    The grammar conforms to the Java grammar described in "The Java(TM)
    Language Specification. J. Gosling, B. Joy, G. Steele. Addison Wesley
    1996, ISBN 0-201-63451-1"

    Some rules have been modified to support JDK1.1 inner classes
    definitions and other extensions.  */


%{
  #include <stdio.h>
  #include <string.h>
  
  #include "stack.h"
  #include "list.h"
  #include "tree.h"
  #include "def.h"
 
  enum instructions { seq, nseq };
  enum instructions insType = seq;
  enum side sideParent = prawy;

  extern char* yytext;
  extern unsigned long ulLinenum;
 
  char cTmp[100];
  char cFunc[100];

  unsigned long complex;
  double efficiency;
  list lHead, lTail;
  stos sMystos;
  node nTreenode;

  
  void yyerror (const char*);
  void function_ivoke(void);
  void add_node(enum side, unsigned long);


  FILE* yyin;
%}

%token   LS_TK           SRS_TK          ZRS_TK
%token   BOOL_AND_TK BOOL_OR_TK 
%token   EQ_TK NEQ_TK GTE_TK LTE_TK

%token   PLUS_ASSIGN_TK  MINUS_ASSIGN_TK MULT_ASSIGN_TK DIV_ASSIGN_TK
%token   REM_ASSIGN_TK   
%token   LS_ASSIGN_TK    SRS_ASSIGN_TK   ZRS_ASSIGN_TK
%token   AND_ASSIGN_TK   XOR_ASSIGN_TK   OR_ASSIGN_TK

%token   PUBLIC_TK       PRIVATE_TK         PROTECTED_TK
%token   STATIC_TK       FINAL_TK           SYNCHRONIZED_TK
%token   VOLATILE_TK     TRANSIENT_TK       NATIVE_TK
%token   PAD_TK          ABSTRACT_TK        MODIFIER_TK
%token   STRICT_TK

%token  DECR_TK INCR_TK

%token   DEFAULT_TK      IF_TK              THROW_TK
%token   BOOLEAN_TK      DO_TK              IMPLEMENTS_TK
%token   THROWS_TK       BREAK_TK           IMPORT_TK       
%token   ELSE_TK         INSTANCEOF_TK      RETURN_TK
%token   VOID_TK         CATCH_TK           INTERFACE_TK
%token   CASE_TK         EXTENDS_TK         FINALLY_TK
%token   SUPER_TK        WHILE_TK           CLASS_TK
%token   SWITCH_TK       CONST_TK           TRY_TK
%token   FOR_TK          NEW_TK             CONTINUE_TK
%token   GOTO_TK         PACKAGE_TK         THIS_TK
%token   ASSERT_TK

%token   BYTE_TK         SHORT_TK           INT_TK            LONG_TK
%token   CHAR_TK         INTEGRAL_TK

%token   FLOAT_TK        DOUBLE_TK          FP_TK

%token   ID_TK

%token   OSB_TK  CSB_TK  C_TK

%token   STRING_LIT_TK   CHAR_LIT_TK        INT_LIT_TK        FP_LIT_TK
%token   TRUE_TK         FALSE_TK           BOOL_LIT_TK       NULL_TK


%%

start : compilation_unit
      ;

compilation_unit :
                 | package_declaration
                 | import_declarations
                 | type_declarations
                 | package_declaration import_declarations
                 | package_declaration type_declarations
                 | import_declarations type_declarations
                 | package_declaration import_declarations type_declarations
                 ;

package_declaration : PACKAGE_TK name ';'
                    ;

name : simple_name
     | qualified_name		
     ;

simple_name : identifier
            ;

qualified_name : name '.' identifier
               ;

import_declarations : import_declaration
                    | import_declarations import_declaration
                    ;

import_declaration : single_type_import_declaration
                   | type_import_on_demand_declaration
;

single_type_import_declaration : IMPORT_TK name ';'
                               ;

type_import_on_demand_declaration : IMPORT_TK name '.' '*' ';'
;

type_declarations : type_declaration
                  | type_declarations type_declaration
                  ;

type_declaration : class_declaration
		 | interface_declaration
                 | empty_statement
                 ;

class_declaration : modifiers CLASS_TK identifier super interfaces class_body
                  | CLASS_TK identifier super interfaces class_body
                  ;

modifiers : modifier 
          | modifiers modifier

modifier : PUBLIC_TK
         | PROTECTED_TK
	 | PRIVATE_TK
	 | STATIC_TK
	 | ABSTRACT_TK
	 | FINAL_TK
	 | NATIVE_TK
	 | SYNCHRONIZED_TK
	 | TRANSIENT_TK
	 | VOLATILE_TK
	 | STRICT_TK
	 ;

identifier : ID_TK { strcpy(cTmp, yytext); }
           ;

super :
      |	EXTENDS_TK class_type
      ;

class_type : class_or_interface_type
           ;

class_or_interface_type : name
                        ;

interfaces :
           | IMPLEMENTS_TK interface_type_list
           ;

interface_type_list : interface_type
                    | interface_type_list C_TK interface_type
                    ;

interface_type : class_or_interface_type
               ;

interface_declaration : INTERFACE_TK identifier interface_body
                      |	modifiers INTERFACE_TK identifier interface_body
                      |	INTERFACE_TK identifier extends_interfaces interface_body
                      |	modifiers INTERFACE_TK identifier extends_interfaces interface_body
                      ;

interface_body : '{' '}'
               | '{' interface_member_declarations '}'
;


interface_member_declarations : interface_member_declaration
			      |	interface_member_declarations interface_member_declaration
                              ;

interface_member_declaration : constant_declaration
                             | abstract_method_declaration
                             | class_declaration
                             | interface_declaration
                             | empty_statement
                             ;

constant_declaration : field_declaration
                     ;

field_declaration : type variable_declarators ';'
                  | modifiers type variable_declarators ';'
                  ;

type : primitive_type
     | reference_type
     ;

primitive_type : BYTE_TK
               | SHORT_TK
	       | CHAR_TK
	       | INT_TK
	       | LONG_TK
	       | FLOAT_TK
	       | DOUBLE_TK
	       | BOOLEAN_TK
               ;

reference_type : class_or_interface_type
               | array_type
               ;

array_type : primitive_type dims
           | name dims
           ;

dims : OSB_TK CSB_TK
     | dims OSB_TK CSB_TK
     ;

variable_declarators : variable_declarator
                     | variable_declarators C_TK variable_declarator
                     ;

variable_declarator : variable_declarator_id
                    | variable_declarator_id '=' variable_initializer
                    ;

variable_declarator_id : identifier
                       | variable_declarator_id OSB_TK CSB_TK
                       ;

variable_initializer : expression
                     | array_initializer
                     ;


expression : assignment_expression
           ;

assignment_expression : conditional_expression
                      |	assignment
                      ;


conditional_expression : conditional_or_expression
                       | conditional_or_expression '?' expression ':' conditional_expression
                       ;

conditional_or_expression : conditional_and_expression
                          | conditional_or_expression BOOL_OR_TK conditional_and_expression
                          ;

conditional_and_expression : inclusive_or_expression
                           | conditional_and_expression BOOL_AND_TK inclusive_or_expression
                           ;



multiplicative_expression : unary_expression
                          | multiplicative_expression '*' unary_expression
                          | multiplicative_expression '/' unary_expression
                          | multiplicative_expression '%' unary_expression
                          ;

additive_expression : multiplicative_expression
                    | additive_expression '+' multiplicative_expression
                    | additive_expression '-' multiplicative_expression
                    ;

shift_expression : additive_expression
                 | shift_expression LS_TK additive_expression
                 | shift_expression SRS_TK additive_expression
                 | shift_expression ZRS_TK additive_expression
                 ;

relational_expression : shift_expression
                      |	relational_expression '<' shift_expression
                      |	relational_expression '>' shift_expression
                      |	relational_expression LTE_TK shift_expression
                      |	relational_expression GTE_TK shift_expression
                      |	relational_expression INSTANCEOF_TK reference_type
                      ;

equality_expression : relational_expression
                    | equality_expression EQ_TK relational_expression
                    | equality_expression NEQ_TK relational_expression
                    ;

and_expression : equality_expression
               | and_expression '&' equality_expression
               ;

exclusive_or_expression : and_expression
                        | exclusive_or_expression '^' and_expression
                        ;

inclusive_or_expression : exclusive_or_expression
                        | inclusive_or_expression '|' exclusive_or_expression
                        ;


unary_expression : pre_increment_expression
                 | pre_decrement_expression
                 | '+' unary_expression
                 | '-' unary_expression
                 | unary_expression_not_plus_minus
;

pre_increment_expression : INCR_TK unary_expression
                         ;

pre_decrement_expression : DECR_TK unary_expression
                         ;

unary_expression_not_plus_minus : postfix_expression
                                | '!' unary_expression
                                | '~' unary_expression
                                | cast_expression
                                ;

postfix_expression : primary
                   | name
                   | post_increment_expression
                   | post_decrement_expression
;

primary : primary_no_new_array
        | array_creation_expression
;

primary_no_new_array : literal
                     | THIS_TK
                     | '(' expression ')'
                     | class_instance_creation_expression
                     | field_access
                     | method_invocation
                     | array_access
                     | type_literals
                     | name '.' THIS_TK
                     ;

literal : boolean_literal
        | FP_LIT_TK
        | INT_LIT_TK
        | CHAR_LIT_TK
        | STRING_LIT_TK
        | NULL_TK
        ;

boolean_literal : TRUE_TK
                | FALSE_TK
                ;



class_instance_creation_expression : NEW_TK class_type '(' argument_list ')'
                                   | NEW_TK class_type '(' ')'
                                   | anonymous_class_creation
                                   | something_dot_new identifier '(' ')'
                                   | something_dot_new identifier '(' ')' class_body
                                   | something_dot_new identifier '(' argument_list ')'
                                   | something_dot_new identifier '(' argument_list ')' class_body
                                   ;

argument_list : expression
              | argument_list C_TK expression
              ;

anonymous_class_creation : NEW_TK class_type '(' ')' class_body         
                         | NEW_TK class_type '(' argument_list ')' class_body
                         ;


something_dot_new : name '.' NEW_TK
                  | primary '.' NEW_TK
                  ;


field_access : primary '.' identifier
             | SUPER_TK '.' identifier
             ;


method_invocation : name '(' { function_ivoke(); } ')'
                  | name '(' { function_ivoke(); } argument_list ')'
                  | primary '.' identifier '(' { function_ivoke(); } ')'
                  | primary '.' identifier '(' { function_ivoke(); } argument_list ')'
                  | SUPER_TK '.' identifier '('{ function_ivoke(); } ')'
                  | SUPER_TK '.' identifier '('{ function_ivoke(); } argument_list ')'
                  ;

array_access : name OSB_TK expression CSB_TK
             | primary_no_new_array OSB_TK expression CSB_TK
             ;


type_literals : name '.' CLASS_TK
              |	array_type '.' CLASS_TK
              |	primitive_type '.' CLASS_TK
              |	VOID_TK '.' CLASS_TK
              ;

array_creation_expression : NEW_TK primitive_type dim_exprs
                          | NEW_TK class_or_interface_type dim_exprs
                          | NEW_TK primitive_type dim_exprs dims
                          | NEW_TK class_or_interface_type dim_exprs dims
                          | NEW_TK class_or_interface_type dims array_initializer
                          | NEW_TK primitive_type dims array_initializer
                          ;

dim_exprs : dim_expr
          | dim_exprs dim_expr
          ;

dim_expr : OSB_TK expression CSB_TK
         ;

array_initializer : '{' '}'
                  | '{' variable_initializers '}'
                  | '{' C_TK '}'
                  | '{' variable_initializers C_TK '}'
                  ;

variable_initializers : variable_initializer
                      | variable_initializers C_TK variable_initializer
                      ;


post_increment_expression : postfix_expression INCR_TK
                          ;

post_decrement_expression : postfix_expression DECR_TK
                          ;

assignment : left_hand_side assignment_operator assignment_expression
           ;

left_hand_side : name
               | field_access
               | array_access
               ;


assign_any : PLUS_ASSIGN_TK
           | MINUS_ASSIGN_TK
	   | MULT_ASSIGN_TK
	   | DIV_ASSIGN_TK
	   | REM_ASSIGN_TK
	   | LS_ASSIGN_TK
	   | SRS_ASSIGN_TK
	   | ZRS_ASSIGN_TK
	   | AND_ASSIGN_TK
	   | XOR_ASSIGN_TK
	   | OR_ASSIGN_TK
	   ;

assignment_operator : assign_any
                    | '='
                    ;

abstract_method_declaration : method_header ';'
;

method_header :	type method_declarator throws
              |	VOID_TK method_declarator throws
              |	modifiers type method_declarator throws
              |	modifiers VOID_TK method_declarator throws
              ;


method_declarator : identifier '(' { strcpy(cFunc, cTmp); }  ')' 
                  | identifier '(' { strcpy(cFunc,cTmp); }  formal_parameter_list ')' 
                  | method_declarator OSB_TK CSB_TK
                  ;


formal_parameter_list : formal_parameter
                      |	formal_parameter_list C_TK formal_parameter
                      ;


formal_parameter : type variable_declarator_id
                 | modifiers type variable_declarator_id
                 ;

throws :
       | THROWS_TK class_type_list
       ;


class_type_list : class_type
                | class_type_list C_TK class_type
                ;

extends_interfaces : EXTENDS_TK interface_type
                   | extends_interfaces C_TK interface_type
                   ;


empty_statement : ';'
                ;

class_body : '{' '}'
           | '{' class_body_declarations '}'
           ;

class_body_declarations : class_body_declaration
                        | class_body_declarations class_body_declaration
                        ;


class_body_declaration : class_member_declaration
                       | static_initializer
                       | constructor_declaration
                       | block		
                       ;

class_member_declaration : field_declaration
                         | method_declaration
                         | class_declaration
                         | interface_declaration
                         | empty_statement
                         ;

method_declaration : method_header {
                                    if (Find(lHead, &lTail, cFunc))
				     {
				      sMystos = NULL;
				      nTreenode = NULL;
				     }
				    else
				     {
				      puts("Blad w pliku konfiguracyjnym!");
				      exit(1);
				     }  
                                   }
                     method_body
                   ;

method_body : block
            | ';'
            ;

block : '{' '}'
      |	'{' block_statements '}'
;

block_statements : block_statement
                 | block_statements block_statement
                 ;

block_statement : local_variable_declaration_statement
                | statement
                | class_declaration
                ;

local_variable_declaration_statement : local_variable_declaration ';'
                                     ;

local_variable_declaration : type variable_declarators
                           | modifiers type variable_declarators
                           ;

statement : statement_without_trailing_substatement
          | labeled_statement
          | if_then_statement
          | if_then_else_statement
          | while_statement
          | for_statement
          ;

statement_without_trailing_substatement : block
                                        | empty_statement
                                        | expression_statement {
					                        if ( insType == seq )
                                                                 {
								  add2tree(&nTreenode, lTail, sideParent, SEQ);
								  sideParent = lewy;
								 }
								else insType = seq;
					                       }
                                        | switch_statement
                                        | do_statement
                                        | break_statement
                                        | continue_statement
                                        | return_statement
                                        | synchronized_statement
                                        | throw_statement
                                        | try_statement
                                        | assert_statement
                                        ;

expression_statement : statement_expression ';'
                     ;

statement_expression : assignment
                     | pre_increment_expression
                     | pre_decrement_expression
                     | post_increment_expression
                     | post_decrement_expression
                     | method_invocation
                     | class_instance_creation_expression
                     ;

switch_statement : SWITCH_TK { add_node(prawy, SWITCH); }
                   '(' expression ')' 
		   switch_block {
		                 Pop(&sMystos, &nTreenode);
				 sideParent = lewy;
		                }
                 ;

switch_block : '{' '}'
             | '{' switch_labels '}'
             | '{' switch_block_statement_groups '}'
             | '{' switch_block_statement_groups switch_labels '}'
             ;

switch_block_statement_groups : switch_block_statement_group
                              |	switch_block_statement_groups switch_block_statement_group
                              ;

switch_block_statement_group : switch_labels block_statements
                             ;

switch_labels : switch_label
              |	switch_labels switch_label
              ;

switch_label : CASE_TK constant_expression ':'
             | DEFAULT_TK ':'
             ;

constant_expression : expression
                    ;

do_statement : do_statement_begin statement WHILE_TK '(' expression ')' 
               ';' {
	            Pop(&sMystos, &nTreenode);
		    sideParent = lewy;
	           }
             ;

do_statement_begin : DO_TK { add_node(prawy, DO); }
                   ;

break_statement : BREAK_TK ';'
                | BREAK_TK identifier ';'
                ;

continue_statement : CONTINUE_TK ';'
	           | CONTINUE_TK identifier ';'
                   ;

return_statement : RETURN_TK ';'
                 | RETURN_TK expression ';'
                 ;

synchronized_statement : synchronized '(' expression ')' block
                       ;

synchronized : MODIFIER_TK
             ;

throw_statement : THROW_TK expression ';'
                ;

try_statement : TRY_TK block catches
              |	TRY_TK block finally
              |	TRY_TK block catches finally
              ;

catches : catch_clause
        | catches catch_clause
        ;

catch_clause : CATCH_TK '(' formal_parameter ')' block
             ;

finally : FINALLY_TK block
        ;

assert_statement : ASSERT_TK expression ':' expression ';'
                 | ASSERT_TK expression ';'
                 ;

label_decl : identifier ':'
           ;

labeled_statement : label_decl statement
                  ;

if_stm : IF_TK '(' expression ')' { add_node(prawy, IF); }
       ;

if_then_statement : if_stm statement {
                                      Pop(&sMystos, &nTreenode);
				      sideParent = lewy;
                                     }
                  ;

if_then_else_statement : if_stm statement_nsi ELSE_TK statement {
                                                                 Pop(&sMystos, &nTreenode);
				                                 sideParent = lewy;
                                                                }
                       ;

statement_nsi : statement_without_trailing_substatement
              |	labeled_statement_nsi
              |	if_then_else_statement_nsi
              |	while_statement_nsi
              |	for_statement_nsi
              ;

labeled_statement_nsi : label_decl statement_nsi
                      ;

if_then_else_statement_nsi : if_stm statement_nsi ELSE_TK statement_nsi {
                                                                         Pop(&sMystos, &nTreenode);
				                                         sideParent = lewy;
                                                                        }
                           ;

while_statement_nsi : while_expression statement_nsi {
                                                      Pop(&sMystos, &nTreenode);
 	                                              sideParent = lewy;
                                                     }
                    ;

while_expression : WHILE_TK { add_node(prawy, WHILE); }
                   '(' expression ')'
                 ;

for_statement_nsi : for_begin ';' expression ';' for_update ')' statement_nsi {
                                                                               Pop(&sMystos, &nTreenode);
				                                               sideParent = lewy;
                                                                              }
                  | for_begin ';' ';' for_update ')' statement_nsi {
                                                                    Pop(&sMystos, &nTreenode);
    		                                                    sideParent = lewy;
		                                                   }
                  ;

for_begin : for_header for_init
          ;

for_header : FOR_TK { add_node(prawy, FOR); }
             '('
           ;

for_init :
         | statement_expression_list
         | local_variable_declaration
         ;

for_update :
           | statement_expression_list
           ;

statement_expression_list : statement_expression
                          | statement_expression_list C_TK statement_expression
                          ;

while_statement : while_expression statement {
                                              Pop(&sMystos, &nTreenode);
					      sideParent = lewy;
                                             }
                ;


for_statement : for_begin ';' expression ';' for_update ')'  statement {
                                                                        Pop(&sMystos, &nTreenode);
				                                        sideParent = lewy;
                                                                       }
              |	for_begin ';' ';' for_update ')' statement {
	                                                    Pop(&sMystos, &nTreenode);
	 	                                            sideParent = lewy;
	                                                   }
              ;

static_initializer : STATIC_TK block
                   ;


constructor_declaration : constructor_declaration2
                        | constructor_declaration2 ';'
                        ;

constructor_declaration2 : constructor_declarator throws constructor_body
                         | modifiers constructor_declarator throws constructor_body
			 ;


constructor_declarator : simple_name '(' ')'
                       | simple_name '(' formal_parameter_list ')'
                       ;


constructor_body : '{' '}'
                 | '{' explicit_constructor_invocation '}'
                 | '{' block_statements '}'
                 | '{' explicit_constructor_invocation block_statements '}'
                 ;


explicit_constructor_invocation : this_or_super '(' ')' ';'
                                | this_or_super '(' argument_list ')' ';'
                                | name '.' SUPER_TK '(' argument_list ')' ';'
                                | name '.' SUPER_TK '(' ')' ';'
                                ;


this_or_super : THIS_TK
              |	SUPER_TK
              ;


cast_expression : '(' primitive_type dims ')' unary_expression
                | '(' primitive_type ')' unary_expression
                | '(' expression ')' unary_expression_not_plus_minus
                | '(' name dims ')' unary_expression_not_plus_minus
                ;


%%


void function_ivoke(void)
{

 if (strcmp(cFunc, cTmp))
  add2tree(&nTreenode, lTail, sideParent, CALL);
 else
  add2tree(&nTreenode, lTail, sideParent, REC);
  sideParent = lewy;
 insType = nseq;

}


void add_node(enum side _sideParent, unsigned long _ulWaga)
{

 add2tree(&nTreenode, lTail, sideParent, _ulWaga);
 Push(&sMystos, nTreenode);
 sideParent = _sideParent;

}

void yyerror (const char *msg)
{

 printf("Parse error\n");
 exit (1);

}


int main(int argc, char* argv[])
{
 
 lHead = lTail = NULL;

 if ( argc == 4 )
  if ( read_def(argv[3], &lHead, &lTail))
   {
    yyin = fopen(argv[1], "r");

    if ( yyin == NULL )
     {
      puts("Blad przy otwieraniu pliku zrodlowego!");
      exit(1);
     }
 
    yyparse();
 
    Complexity(&lHead, argv[2], &complex, &efficiency);
    
    printf(" Calkowita zlozonosc komponentu : %d  [ CWU ]\n", complex);
    printf(" Calkowita efektywnosc komponentu : %f [ CWU/LOC ]\n\n", efficiency);
     
    return 0;
   }
 puts("Nieprawidlowa ilosc parametrow wejsciowych!");
 return 1; 
}
