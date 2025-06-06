#include <stdio.h>

void update(int *a,int *b) {
    // *a = *a + *b;
    // *b = *a - *b;
    // *a = *a - *b;
    *a = *a + *b;
    *b = *a - (2 *(*b)) > 0 ? *a - (2 *(*b)) : -(*a - (2 *(*b))) ;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
