#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/

    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }

        a[first] = a[last];/*将比第一个小的移到低端*/

        while(first < last && a[first] <= key)
        {
            ++first;
        }

        a[last] = a[first];    
        /*将比第一个大的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

double findMedianSortedArrays(int *A, int m, int*B, int n) {
    int *a = (int *) malloc(sizeof(int) * (m + n));

    memcpy(a,A,sizeof(int)*m);  
    memcpy(a+m,B,sizeof(int)*n);

    Qsort(a, 0, m + n - 1);

    double median=(double) ((n+m)%2? a[(n+m)>>1]:(a[(n+m-1)>>1]+a[(n+m)>>1])/2.0);  

    free(a); 
    return median;
}

int main() {
    int A[4] = {1, 2, 3, 8};
    int B[4] = {7, 4, 5, 6};
    double median = findMedianSortedArrays(A, 4, B, 4);
    printf("result is %f\n", median);
    return 0;
}



