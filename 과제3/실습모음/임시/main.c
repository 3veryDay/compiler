#include <stdio.h>
extern int yyparse();
void main() {
  printf("start of parser\n");
  yyparse();
  printf("end of parser\n");
  printf("2171047 JoYoona\n2176143 ParkSohyun\n2176365 JoEunhye\n2176368 JiHyunseo\n");
}
