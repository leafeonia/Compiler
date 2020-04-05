%locations
%{
	#include "lex.yy.c"
	#include "tree.h"
	#define ERROR(line, info) //printf("Probable reason of error: %s.\n", info);setError(2);
%}

%define parse.error verbose

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
}	|	Specifier FunDec SEMI{
	$$ = initNode(NONTERMINAL, "ExtDef", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	error SEMI{}
	|	Specifier error ExtDef{}
	;
	
ExtDecList : VarDec{
	$$ = initNode(NONTERMINAL, "ExtDecList", @$.first_line);
	insert($$, $1);
}	|	VarDec COMMA ExtDecList{
	$$ = initNode(NONTERMINAL, "ExtDecList", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
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
}	//|	VarDec LB error RB	{}	
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
}	|	error RP{
	ERROR(@1.first_line, "invalid function definition");
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
}	
	;
	
ParamDec : Specifier VarDec{
	$$ = initNode(NONTERMINAL, "ParamDec", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	
	;
	
CompSt : LC DefList StmtList RC{
	$$ = initNode(NONTERMINAL, "CompSt", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
	insert($$, $4);
}	|	error RC{}
	;
	
StmtList : Stmt StmtList{
	$$ = initNode(NONTERMINAL, "StmtList", @$.first_line);
	insert($$, $1);
	insert($$, $2);
}	|	{
	$$ = NULL;
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
}	|	error SEMI{}
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
}	//| error SEMI{} //| error WHILE LP Exp RP{} 
	|	Specifier DecList error{} | Specifier error SEMI{}
	;
	
DecList : Dec{
	$$ = initNode(NONTERMINAL, "DecList", @$.first_line);
	insert($$, $1);
}	|	Dec COMMA DecList{
	$$ = initNode(NONTERMINAL, "DecList", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
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
}	|	MINUS Exp %prec UMINUS{
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
}	|	ID LP RP{
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
}	|	Exp DOT ID{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	ID{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
}	| 	INT{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
}	|	FLOAT{
	$$ = initNode(NONTERMINAL, "Exp", @$.first_line);
	insert($$, $1);
}	|Exp LB error RB{}|LP error RP{}|ID LP error RP{}
	;
	
Args : Exp COMMA Args{
	$$ = initNode(NONTERMINAL, "Args", @$.first_line);
	insert($$, $1);
	insert($$, $2);
	insert($$, $3);
}	|	Exp{
	$$ = initNode(NONTERMINAL, "Args", @$.first_line);
	insert($$, $1);
}	
	;

%%

yyerror(char* msg) {
	if(getErrorFlag() != 1) printf("Error type B at Line %d: %s.\n", yylineno, msg);
	setError(2);
}


