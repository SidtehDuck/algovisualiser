#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED
// Insertion Sort
void insertionsort(int a[], int MAX){
    int temp,i,j,swapflag;
    int sorting=1;
    for(i=1; i<MAX; i++){
        temp=a[i];
        j=i-1;
        while (j>=0 && a[j]>temp){
                swapflag=1;
                a[j+1]=a[j];
                j--;
        }
    swapflag=1;
    a[j+1]=temp;
    }
    sorting=0;
    A:  printf("");
}

#endif // INSERTIONSORT_H_INCLUDED
