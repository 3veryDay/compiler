#include <stdio.h>
extern int yyparse();

int main()
{


    int parse_result = yyparse();

    printf("2171047 JoYoona\n2176143 ParkSohyun\n2176365 JoEunhye\n2176368 JiHyunseo\n");

    return parse_result;

}
