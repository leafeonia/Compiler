%option yylineno

%{
#include "tree.h"
#define YYSTYPE Node*
#include <string.h>
#include <stdio.h>
#include "syntax.tab.h"
int yycolumn = 1;
extern int errorFlag;
extern int endLine;
#define YY_USER_ACTION\
	yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = yycolumn; \
	yylloc.last_column = yycolumn + yyleng - 1; \
	yycolumn += yyleng;
	
#define INIT_TYPE(TYPE,val) yylval = initNode(TYPE, val, yylineno)
#define INIT(val) INIT_TYPE(TERMINAL,val)
%}

%x Comment1
%x Comment2

nonZeroDigit [1-9]
digit [0-9]
octDigit [0-7]
hexDigit [0-9a-fA-F]
_word [_a-zA-Z]
_wordDigit [_0-9a-zA-Z]
_wordDigitError [_0-9a-zA-Z\.\+-]

%%

";"     						{ INIT("SEMI"); return SEMI;}
","								{ INIT("COMMA"); return COMMA;}
"="								{ INIT("ASSIGNOP"); return ASSIGNOP;}
">"|"<"|">="|"<="|"=="|"!="		{ INIT("RELOP"); return RELOP;}
"+"								{ INIT("PLUS"); return PLUS;}
"-"								{ INIT("MINUS"); return MINUS;}
"*"								{ INIT("STAR"); return STAR;}
"/"								{ INIT("DIV"); return DIV;}
"&&"							{ INIT("AND"); return AND;}
"||"							{ INIT("OR"); return OR;}
"."								{ INIT("DOT"); return DOT;}
"!"								{ INIT("NOT"); return NOT;}
"int"|"float"					{ INIT_TYPE(ENUM_TYPE, yytext); return TYPE;}
"("								{ INIT("LP"); return LP;}
")"								{ INIT("RP"); return RP;}
"["								{ INIT("LB"); return LB;}
"]"								{ INIT("RB"); return RB;}
"{"								{ INIT("LC"); return LC;}
"}"								{ INIT("RC"); return RC;}
"struct"						{ INIT("STRUCT"); return STRUCT;}
"return"						{ INIT("RETURN"); return RETURN;}
"if"							{ INIT("IF"); return IF;}
"else"							{ INIT("ELSE"); return ELSE;}
"while"							{ INIT("WHILE"); return WHILE;}
[ \t]+							{}
\n|\r							{ yycolumn = 1; }

"//"							{ BEGIN(Comment1);}
<Comment1>"\n"					{ BEGIN(INITIAL);}
<Comment1>.						{}

"/*"							{ BEGIN(Comment2);}
<Comment2>"*/"					{ BEGIN(INITIAL);}
<Comment2>.						{}
<Comment2>\n					{}
<Comment2><<EOF>>				{ fprintf(stderr, "Error type A at Line %d: Unterminated nested comment.\n",yylineno); setError(1); BEGIN(INITIAL);}

<<EOF>>							{ endLine = yylineno; yyterminate();}

0								{ INIT_TYPE(ENUM_INT, yytext); return INT;}
{nonZeroDigit}{digit}* 			{ INIT_TYPE(ENUM_INT, yytext); return INT;}
0{octDigit}+	{ INIT_TYPE(OCT, yytext); return INT;}
0[Xx]{hexDigit}+	{ INIT_TYPE(HEX, yytext); return INT;}
0[Xx]{_wordDigit}*				{ fprintf(stderr, "Error type A at Line %d: Illegal hexadecimal number '%s'.\n",yylineno, yytext); setError(1);}
0{_wordDigit}+					{ fprintf(stderr, "Error type A at Line %d: Illegal octal number '%s'.\n",yylineno, yytext); setError(1);}
{_word}{_wordDigit}*			{ INIT_TYPE(ENUM_ID, yytext); return ID;}

(({digit}*\.{digit}+)|({digit}+\.{digit}*))[Ee][\+-]?{digit}+	{ INIT_TYPE(ENUM_FLOAT, yytext); return FLOAT;}
(({digit}*\.{digit}+)|({digit}+\.{digit}*))[Ee]{_wordDigitError}*	{ fprintf(stderr, "Error type A at Line %d: Illegal floating point number '%s'.\n",yylineno, yytext); setError(1);}

{digit}+\.{digit}+				{ INIT_TYPE(ENUM_FLOAT, yytext); return FLOAT;}


.  		 						{ fprintf( stderr, "Error type A at Line %d: Mysterious characters '%s'.\n", yylineno, yytext); setError(1); }
%%
