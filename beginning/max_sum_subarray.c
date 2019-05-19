#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){
    return a > b ? a : b;
}
int sum(int a[], int n){
    int i = 0;
    int best = 0;
    for(i = 0; i < n; i++){
        best = max(a[i], best + a[i]);
    }
    return best;
}

void main(){
    int n;
    int i;
    int *a;
    scanf("%d", &n);
    a = (int*) malloc(sizeof(int)*n);
    for(i = 0; i< n; i++){
        scanf("%d", &a[i]);
    }
    printf("\n%d\n", sum(a,n));
}

/*
 INPUT
8
-1 2 4 -3 5 2 -5 2

Output
7
*/
