#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double area(triangle tr){
    double p = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(p*(p-tr.a)*(p-tr.b)*(p-tr.c));
}
void sort_by_area(triangle* tr, int n) {
    for (int i = 0; i < n; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (area(tr[idx]) > area(tr[j])) {
                idx = j;
            }
        }
        if (idx != i) {
            triangle temp = tr[idx];
            tr[idx] = tr[i];
            tr[i] = temp;
        }
    }
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;
#define INT_MAX 1e7 ;

int perimeter(triangle tr){
    return (tr.a + tr.b + tr.c)/2; 
}
int area(int p, triangle tr){
    int val = p*(p-tr.a)*(p-tr.b)*(p-tr.c);
    return val>>1;
}
void sort_by_area(triangle* tr, int n) {
    
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        int p = perimeter(tr[i]);
        arr[i] = area(p,tr[i]);                
    }
    triangle* res = (triangle*)malloc(n*sizeof(triangle));
    int idx=0;
    for(int i=0; i<n; i++){
    int ind=0;
        for(int j=0; j<n; j++){
            if(arr[ind] > arr[j]){
                ind = j;
            }
        }
        res[idx].a = tr[ind].a;
        res[idx].b = tr[ind].b;
        res[idx].c = tr[ind].c;
        arr[ind] = INT_MAX;
        idx++;
    }
    tr = res;
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}
*/

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
