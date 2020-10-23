#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED
// Insertion Sort
int counti=0;

int notsortedi(int a[], int MAX){
    int q;
    for(q=0;q<MAX-1;q++)
    {
        if(a[q]>a[q+1])
            return 1;
    }
    return 0;
}

void insertionsort(int a[], int MAX){
    int temp,i,j,swapflag;
    int sorting=1;
    while(notsortedi(a, 50)){
    for(i=1; i<MAX; i++){
        temp=a[i];
        j=i-1;
        while (j>=0 && a[j]>temp){
                swapflag=1;
                a[j+1]=a[j];
                counti+=1;
                j--;
        }
    swapflag=1;
    a[j+1]=temp;
    counti+=1;
    }
    }

    sorting=0;
    printf("\n Total number of Swappings are: %d",counti);
    A:  printf("");
}

#endif // INSERTIONSORT_H_INCLUDED
