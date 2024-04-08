%{
/* lex source for Mini C */
%}

%%

"const"	  return(TCONST);

"else"		return(TELSE);

"if"		return (TIF);

"int"		return(TINT);

"return"	return(TRETURN);

"void"		return(TVOID);

"while"		return(TWHILE);
____________________________________________________________________________________

"11"
return(tequal);

"!="
return(tnotequ);

"^=！"
return(tlesse);

">="
return(tgreate);

"&&"
return(tand);

"||"
return(tor);

"++"
return(tinc);

"--"
return(tdec);

"+="
return(taddAssign);

"-="
return(tsubAssign);

"*="
return(tmulAssign);

"/="
return(tdivAssign);

"%="
return(tmodAssign);
-------------------------------------------------------------------------------
[A-Za-z_][A-Za-z0-9]*
return(tident);

[1-9][0-9]*|0[0-7]+|x|X)[0-9A-Fa-f]*)?
return(tnumber);

"*"（［^*］*+【^*/】）***"*/"
;

"//".*
;

[ \t\n]
;

・
return(yytext[0]);

%%

int yywrap()
{
  return 1;
}
