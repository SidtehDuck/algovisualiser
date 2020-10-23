#ifndef RECURSIVEBUBBLESORT_H_INCLUDED
#define RECURSIVEBUBBLESORT_H_INCLUDED
int countrb=0;
int notsorted(int a[], int MAX){
    int q;
    for(q=0;q<MAX-1;q++)
    {
        if(a[q]>a[q+1])
            return 1;
    }
    return 0;
}
void recursivebubblesort(int a[], int MAX){
    int i=0;
    int j=0;
    int swapflag=0;
    int sorting=1;
    int temp;
    while(notsorted(a, MAX)){
        for (j = 0; j < MAX-1; j++){
            if (a[j] > a[j+1]){
                printf("\nswap %d and %d\n",a[j],a[j+1]);
                countrb+=1;
                swapflag=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                goto A;
                }
        }
        recursivebubblesort(a, MAX-1);
    }
    if (!notsorted(a, 50)){
        printf("\n Total number of Swapings are: %d",countrb);
    }
    sorting=0;
    A:  printf("");
}



#endif // RECURSIVEBUBBLESORT_H_INCLUDED