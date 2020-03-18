%locations
%{
	#include "lex.yy.c"
	#include "tree.h"
	#define ERROR(line, info) printf("Error type B at Line %d: %s.\n",line, info);setError();
%}

%token INT FLOAT ID SEMI COMMA TYPE STRUCT RETURN IF ELSE WHILE

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left MINUS PLUS
%left DIV STAR
%right NOT UMINUS
%left DOT LB RB LP RP LC RC

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

Program : ExtDefList{
	$$ = initNode(NONTERMINAL, "Program", @$.first_line);
	insert(NULL, $$);
	insert($$, $1);
}	
	;
	
ExtDefList : ExtDef ExtDefList{
	$$ = initNode(NONTERMINAL, "ExtDefList", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	{
	$$ = NULL;
}	
	;
	
ExtDef : Specifier ExtDecList SEMI{
	$$ = initNode(NONTERMINAL, "ExtDef", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Specifier SEMI{
	$$ = initNode(NONTERMINAL, "ExtDef", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	Specifier FunDec CompSt{
	$$ = initNode(NONTERMINAL, "ExtDef", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	error ExtDecList SEMI{
	ERROR(@1.first_line, "invalid specifier of global variable");
}	|	Specifier error SEMI{
	ERROR(@2.first_line, "invalid global variable");
}	|	error SEMI{
	ERROR(@1.first_line, "invalid struct");
}	|	error FunDec CompSt{
	ERROR(@1.first_line, "invalid specifier of function");
}	|	Specifier error CompSt{
	ERROR(@2.first_line, "invalid function declaration");
}	|	Specifier FunDec error SEMI{
	ERROR(@3.first_line, "error detected in function body");
}
	;
	
ExtDecList : VarDec{
	$$ = initNode(NONTERMINAL, "ExtDecList", @$.first_line);
	insert($$, $1);
}	|	VarDec COMMA ExtDecList{
	$$ = initNode(NONTERMINAL, "ExtDecList", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	error COMMA ExtDecList{
	ERROR(@1.first_line, "invalid declaration of variable");
}	|	VarDec error ExtDecList{
	ERROR(@2.first_line, "missing ',' in variable lists");
}
	;
	
Specifier : TYPE{
	$$ = initNode(NONTERMINAL, "Specifier", @$.first_line);
	insert($$, $1);
}	|	StructSpecifier{
	$$ = initNode(NONTERMINAL, "Specifier", @$.first_line);
	insert($$, $1);
}	
	;
	
StructSpecifier : STRUCT OptTag LC DefList RC{
	$$ = initNode(NONTERMINAL, "StructSpecifier", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
	insert($$, $5);
}	|	STRUCT Tag{
	$$ = initNode(NONTERMINAL, "StructSpecifier", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	STRUCT error DefList RC{
	ERROR(@2.first_line, "invalid struct definition");
}	|	STRUCT OptTag LC DefList error{
	ERROR(@5.first_line, "missing '}' in struct definition");
}	|	STRUCT error SEMI{
	ERROR(@2.first_line, "invalid struct definition");
}
	;
	
OptTag : ID{
	$$ = initNode(NONTERMINAL, "OptTag", @$.first_line);
	insert($$, $1);
}	|	{
	$$ = NULL;
}
	;
	
Tag : ID{
	$$ = initNode(NONTERMINAL, "Tag", @$.first_line);
	insert($$, $1);
}
	;
	
VarDec : ID{
	$$ = initNode(NONTERMINAL, "VarDec", @$.first_line);
	insert($$, $1);
}	|	VarDec LB INT RB{
	$$ = initNode(NONTERMINAL, "VarDec", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
}	|	error LB INT RB{
	ERROR(@1.first_line, "invalid variable declaration");
}	|	VarDec error INT RB{
	ERROR(@2.first_line, "missing '[' in variable declaration");
}	|	VarDec LB error RB{
	ERROR(@3.first_line, "Not a integer in '[]'");
}	|	VarDec LB INT error{
	ERROR(@4.first_line, "missing ']' in variable declaration");
}	
	;
	
FunDec : ID LP VarList RP{
	$$ = initNode(NONTERMINAL, "FunDec", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
}	|	ID LP RP{
	$$ = initNode(NONTERMINAL, "FunDec", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	ID LP error RP{
	ERROR(@3.first_line, "invalid variable list of function");
}	
	;
	
VarList : ParamDec COMMA VarList{
	$$ = initNode(NONTERMINAL, "VarList", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	ParamDec{
	$$ = initNode(NONTERMINAL, "VarList", @$.first_line);
	insert($$, $1);
}	|	error COMMA VarList{
	ERROR(@1.first_line, "invalid parameter declaration");
}	
	;
	
ParamDec : Specifier VarDec{
	$$ = initNode(NONTERMINAL, "ParamDec", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	error VarDec{
	ERROR(@1.first_line, "invalid specifier");
}
	;
	
CompSt : LC DefList StmtList RC{
	$$ = initNode(NONTERMINAL, "CompSt", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
}	|	LC error RC{
	ERROR(@2.first_line, "missing '}'");
}
	;
	
StmtList : Stmt StmtList{
	$$ = initNode(NONTERMINAL, "StmtList", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	{
	$$ = NULL;
}	|	Stmt error StmtList{
	ERROR(@1.first_line, "invalid statement");
}
	;

Stmt : Exp SEMI{
	$$ = initNode(NONTERMINAL, "Stmt", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	CompSt{
	$$ = initNode(NONTERMINAL, "Stmt", @$.first_line);
	insert($$, $1);
}	|	RETURN Exp SEMI{
	$$ = initNode(NONTERMINAL, "Stmt", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	IF LP Exp RP Stmt %prec LOWER_THAN_ELSE{
	$$ = initNode(NONTERMINAL, "Stmt", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
	insert($$, $5);
}	|	IF LP Exp RP Stmt ELSE Stmt{
	$$ = initNode(NONTERMINAL, "Stmt", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
	insert($$, $5);
	insert($$, $6);
	insert($$, $7);
}	|	WHILE LP Exp RP Stmt{
	$$ = initNode(NONTERMINAL, "Stmt", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
	insert($$, $5);
}	|	RETURN error SEMI{
	ERROR(@2.first_line, "invalid return value");
}	|	IF error Exp RP Stmt %prec LOWER_THAN_ELSE{
	ERROR(@2.first_line, "missing '('");
}	|	IF LP error RP Stmt %prec LOWER_THAN_ELSE{
	ERROR(@3.first_line, "invalid 'if' condition");
}	|	IF LP Exp error Stmt %prec LOWER_THAN_ELSE{
	ERROR(@4.first_line, "missing ')'");
}	|	IF error Exp RP Stmt ELSE Stmt{
	ERROR(@2.first_line, "missing '('");
}	|	IF LP error RP Stmt ELSE Stmt{
	ERROR(@3.first_line, "invalid 'if' condition");
}	|	IF LP Exp error Stmt ELSE Stmt{
	ERROR(@4.first_line, "missing ')'");
}	|	WHILE error Exp RP Stmt{
	ERROR(@2.first_line, "missing '('");
}	|	WHILE LP error RP Stmt{
	ERROR(@3.first_line, "invalid 'while' condition");
}	|	WHILE LP Exp error Stmt{
	ERROR(@4.first_line, "missing ')'");
}
	;
	
DefList : Def DefList{
	$$ = initNode(NONTERMINAL, "DefList", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	{
	$$ = NULL;
}
	;
	
Def : Specifier DecList SEMI{
	$$ = initNode(NONTERMINAL, "Def", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Specifier error SEMI{
	ERROR(@2.first_line, "invalid declaration list");
}
	;
	
DecList : Dec{
	$$ = initNode(NONTERMINAL, "DecList", @$.first_line);
	insert($$, $1);
}	|	Dec COMMA DecList{
	$$ = initNode(NONTERMINAL, "DecList", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	error COMMA DecList{
	ERROR(@1.first_line, "invalid declaration");
}	
	;
	
Dec	: VarDec{
	$$ = initNode(NONTERMINAL, "Dec", @$.first_line);
	insert($$, $1);
}	|	VarDec ASSIGNOP Exp{
	$$ = initNode(NONTERMINAL, "Dec", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	error ASSIGNOP Exp{
	ERROR(@1.first_line, "invalid variable declaration");
}	|	VarDec error Exp{
	ERROR(@2.first_line, "missing '='");
}
	;
	
Exp : Exp ASSIGNOP Exp{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp AND Exp{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp OR Exp{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp RELOP Exp{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp PLUS Exp{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp MINUS Exp{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp STAR Exp{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp DIV Exp{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	LP Exp RP{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	LP error RP{
	ERROR(@2.first_line, "invalid expression between '(' and ')'");
}	|	LP Exp error{
	ERROR(@3.first_line, "missing ')'");
}
	|	MINUS Exp %prec UMINUS{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	NOT Exp{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	ID LP Args RP{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
}	|	ID LP error RP{
	ERROR(@3.first_line, "invalid argument");
}	|	ID LP Args error{
	ERROR(@4.first_line, "missing ')'");
}
	|	ID LP RP{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp LB Exp RB{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
}	|	Exp LB error RB{
	ERROR(@3.first_line, "invalid array index");
}	|	Exp LB Exp error{
	ERROR(@4.first_line, "missing ']'");
}
	|	Exp DOT ID{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp DOT error{
	ERROR(@3.first_line, "invalid struct property name");
}	
	|	ID{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
}	| 	INT{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
}	|	FLOAT{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
}	
	;
	
Args : Exp COMMA Args{
	$$ = initNode(NONTERMINAL, "Args", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp{
	$$ = initNode(NONTERMINAL, "Args", @$.first_line);
	insert($$, $1);
}	|	error COMMA Args{
	ERROR(@1.first_line, "invalid argument expression");
}	|	Exp COMMA error{
	ERROR(@3.first_line, "invalid argument");
}
	;

%%

yyerror(char* msg) {
	printf("syntax error at Line %d.\n", yylineno);
	setError();
}


