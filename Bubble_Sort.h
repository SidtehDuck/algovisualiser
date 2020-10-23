#ifndef BUBBLE_SORT_H_INCLUDED
#define BUBBLE_SORT_H_INCLUDED
int countb=0;
int notsortedb(int a[], int MAX){
    int q;
    for(q=0;q<MAX-1;q++)
    {
        if(a[q]>a[q+1])
            return 1;
    }
    return 0;
}

int bubblesort(int a[], int MAX){
    int i;
    int j;
    int swapflag;
    int sorting;
    int temp;
    while(notsortedb(a, 50)){
    for (i = 0; i < MAX-1; i++){
       for (j = 0; j < MAX-i-1; j++){
            if(j==MAX-1) j=0;
            printf("\nswap %d and %d\n",a[j],a[j+1]);
            if (a[j] > a[j+1]){
                countb+=1;
                swapflag=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

                goto A;
            }
        }
    }
    }
    if (!notsortedb(a, 50)){
        printf("\n Total number of Swapings are: %d",countb);
    }
    sorting=0;
    A: printf("");
}

#endif // BUBBLE_SORT_H_INCLUDED