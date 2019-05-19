#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int lb1, int ub1, int ub2){
    int i,j,k;
    int *temp;
    int lb2 = ub1 + 1;
    temp = (int*) malloc(sizeof(int)*(ub2 - lb1 + 1));
    i = lb1;
    j = lb2;
    k = 0;
    while ( i<=ub1 && j <= ub2){
        if (a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i<=ub1){
        temp[k++] = a[i++];
    }
    while(j<=ub2){
        temp[k++] = a[j++];
    }
    for(i = lb1, j = 0; i <= ub2; i++, j++){
        a[i] = temp[j];
    }
}
void mergeSort(int a[], int lb, int ub){
    int mid;
    if (lb>=ub){
        return;
    }
    mid = (lb + ub) / 2;
    mergeSort(a, lb, mid);
    mergeSort(a, mid+1, ub);
    merge(a,lb, mid, ub);
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
    mergeSort(a,0, n-1);
    printf("\nsorted array");
    for(i = 0; i<n;i++){
        printf("%d ",a[i]);
    }
}

/*
 INPUT
8
-1 2 4 -3 5 2 -5 2

Output
sorted array-5 -3 -1 2 2 2 4 5
*/