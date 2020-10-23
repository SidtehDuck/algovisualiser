#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED
void selectionsort(int a[], int MAX)
{   int pos, sorting,temp,j,i;
    for(i=0; i<MAX-1; i++){
        int min=i;
        for(j=i+1; j<MAX; j++){
            if(a[j]<a[min]){
                min=j;
                pos=j;
            }
        }
        if (min!=i){
            temp=a[pos];
            a[pos]=a[i];
            a[i]=temp;
            goto A;
        }
    }
    sorting=0;
	A:  printf("");
}

#endif // SELECTIONSORT_H_INCLUDED
