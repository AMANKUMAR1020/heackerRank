#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int max_of_four(int a, int b, int c, int d){
//    return ((a > b ? a : b) > c ? (a > b ? a : b) : c) > d ? ((a > b ? a : b) > c ? (a > b ? a : b) : c) : d;
    
    if(a > b){
        if(a>c){
            if(a>d){
                return a;
            }else{
                return d;
            }
        }else{
            if(c>d){
                return c;
            }else{
                return d;
            }
        }
    }else{
        if(b>c){
            if(b>d){
                return b;
            }else{
                return d;
            }
        }else{
            if(c>d){
                return c;
            }else{
                return d;
            }
        }
    }
    
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
