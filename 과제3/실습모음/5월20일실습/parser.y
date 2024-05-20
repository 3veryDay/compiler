/* yace source for Mini C */ void semantic(int);
%}
%token tident number teonst telse tif tint treturn tvoid twhile %token taddAssign tsubAssign mulAssign tdivAssign tmodAssign
%token tor tand tequal notequ tgreate tlesse tine tdec

%%


1 semantic(D). 1:
mini c
: translation unit
{ semantic(2); 3
translation unit : external del
I translation unit external del
semantic（3js s：


( semantic(4); 1
external
del
: function def / declaration
/ semantic (5); 3:


( semantic(6); 3:
function def
: function header compound st
function header: del spec function name formal param
1 semantic(7), J.


{ semantic(8); 1;
del spec
: del specifiers
1 semantic(9); }
del specifiers
: del_ specifier
( semantic(10);):

/ del_ specifiers del specifier
{ semantic(11):)
del
_specifier
: type qualifier
{ semantic (12)::

| type specifier
{ semantic (13);1;
type_qualifier
: tconst
( semantic (14);)
type specifier
: tint


I tvoid
/ semantic(15);):
function name : tident

{ semantic(16):1;

formal_param: *(' opt formal param *)*
{ semantic(17):):
{ semantic (18):)

opt formal param : formal param_list
{ semantic( 19);1:


{ semantic(20);1
formal _param
list
: param del
/ semantic(20)::

formal param_ list * param del
semantic(22): I:
param del
del spee declarator
semantic(23):1:
compound st
'I' opt del list opt stat list *y"

opt del list
declaration list
semantic(24):1


《semantic（23）；：
declaration list
declaration
i semantic (26); ›

I declaration list declaration
semantic (27)::
declaration
: del spee init del list * :
semantic (28);1:
init del_ list
init declarator
semantic(29): 1

init del _list ** init declarator
{ semantic(30)::

: declarator
1 semantic(30):1


| declarator
tnumber
{ semantic (32):):
declarator
- tident
1 semantic (33);
I tident '[' opt number "1*
/ semantic (34):):
opt number
a tnumber
/ semantic(35);)

/ semantic(36):1:
opt stat list
/ statement list
I semantic(37):)

4 scmantic(38): ):
statement list: statement

1 semantic (39):)
statement list statement
{ semantic(40): 1:
statement
* compound st
1 semantic(4 1):

/ expression_st
/ semantic (42);}

1 if st
( semantic(43):/

I while st
semantic (44); }

return st
{ semantic(45);/




expression st opt expression * :
{ semantie(46):) ;
opt
expression : expression

/ semantic(47);)


I semantic(48):} :
if st : tif *(' expression *)* statement

1 semantic(49): )

I tif 'C expression ")" statement

telse statement
1 semantic(50): 1:
while st
return st
: twhile ' expression 1 stateme
{ semantic (5 1);):
treturn opt
_expression ";
( semantic(52),1:
expression
: assignment exp
1 semantic (53):1:
assignment exp: logical or_exp

( semantic (54); )

I unary_exp *=* assignment exp
1 semantic (55),1

unary exp taddAssign assignment exp
i semantic(56);}

unary exp tsubAssign assignment exp
/ semantic(57): I

unary exp tmulAssign assignment exp
{ semantic(58):}

I unary_exp tdivAssign assignment exp
1 semantic(59); 1

lunary exp todAssign assignment exp
¡ semantic(60):)

logical _or_exp: logical and exp

{ semantic(61);)
I logical or exp tor logical and exp
/ semantic (62); 1;
Jogical and exp: equality exp

{ semantic(63);}
| logical and exp tand equality exp
{ semantic(64): 1:
equality_exp : relational exp

{ semantic(65):}

| equality_exp tequal relational exp
/ semantic(66);)

| equality exp trotequ relational exp
{ semantic(67);}:
relational
_exp : additive exp;
{ semantic (68),}

| relational exp '>* additive exp
{ semantic(69); }

relational
_exp "<* additive_exp
{ semantic(70);;

| relational exp greate additive exp
{ semantic(71);)

I relational exp tlesse additive exp
{ semantic(72): P;

additive_ exp : multiplicative exp
{ semantic( 73);}

| additive exp *+* multiplicative exp
{ semantic( 74):)

| additive exp '* multiplicative exp
( semantic(75)::
multiplicative exp : unary_exp

l semantic(76);}

| multiplicative exp *** unary exp
{ semantic (77):)

I multiplicative_exp */* unary_exp
( semantic(78):)

| multiplicative_ exp *%* unary exp
( semantic(79):) ;
ипагу_ схр
: postfix exp
{ semantic(80);)

|*-* unary exp
{ semantic(81);}

| 'T unary_ exp
{ semantic(82):}

tune unary exp
( semantic(83);

tee unary exp
/ semantic(84):1:
postfix exp
- primary exp
/ semantic(85);}

I postfix exp "I' expression 1'
{ semantic(86); 1

I postfix exp (* opt actual param **
1 semantic (87): i

I postfix exp tine
{ semantic(88): )
opt actual param : actual param
I postfix exp tdec
& semantic (89):):

{ semantic(90): 1


I semantic(91);):
actual param actual param list

1 semantic (92): 1:

