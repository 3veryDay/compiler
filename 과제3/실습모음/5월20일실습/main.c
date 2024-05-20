#include <stido.h>
void main() {
  printf("start of parser\n");
  yyparse();
  printf("end of parser\n");
}
