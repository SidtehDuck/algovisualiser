#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED
int counts=0;
int notsorteds(int a[], int MAX){
    int q;
    for(q=0;q<MAX-1;q++)
    {
        if(a[q]>a[q+1])
            return 1;
    }
    return 0;
}
void selectionsort(int a[], int MAX)
{   int pos, sorting,temp,j,i;
    while(notsorteds(a, 50)){
    for(i=0; i<MAX-1; i++){
        int min=i;
        for(j=i+1; j<MAX; j++){
            if(a[j]<a[min]){
                min=j;
                pos=j;
            }
        }
        if (min!=i){
            printf("\nswap %d and %d\n",a[pos],a[i]);
            counts+=1;
            temp=a[pos];
            a[pos]=a[i];
            a[i]=temp;
            goto A;
        }
    }
    }
    if (!notsorteds(a, 50)){
        printf("\n Total number of Swapings are: %d",counts);
    }
    sorting=0;
    A:  printf("");
}

#endif // SELECTIONSORT_H_INCLUDED