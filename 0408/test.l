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

"=="	return(TEQUAL);

"!="	return(TNOTEQU);

"<="	return(TLESS);

">="	return(TGREATE);

"&&"	return(TAND);

"||"	return(TOR);

"++"	return(TINC);

"--"	return(TDEC);

"+="	return(TADDASSIGN);

"-="	return(TSUBASSIGN);

"*="	return(TMULASSIGN);

"/="	return(TDIVASSIGN);

"%="	return(TMODASSIGN);
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
