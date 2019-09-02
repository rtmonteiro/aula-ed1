#include <stdio.h>
#include <stdlib.h>

void main (void) {
    int a, b, c, d;
    int *pa, *pb, *pc, *pd;

    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;

    printf("Digite 4 valores seguidos: \n");

    scanf("%d %d %d %d", pa, pb, pc, pd);

    printf("%d \n", a);
    printf("%d \n", b);
    printf("%d \n", c);
    printf("%d \n", d);

    return 0;
}



