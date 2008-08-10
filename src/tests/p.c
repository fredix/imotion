#include <stdio.h>

int main(void)
{

int a = 15;
int z = 20;

int *b = &a;
int *q = &z;

int **c;
c = &b;

//*b = 16;

**c=77;

printf("b = %d\n", b);
printf("c = %d\n", *c);
return 0;

}
