#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}


int  median3(int *array, int left, int right) {
    int median = (left + right)/2;
    if (array[left] > array[median])
        swap(&array[left], &array[median]);
    if (array[left] > array[right])
        swap(&array[left], &array[right]);
    if (array[median] > array[right])
        swap(&array[median], &array[right]);

    swap(&array[median], &array[right - 1]);
    return array[right - 1];
}


void quickSelect(int *array, int left, int right) {
    int pivot;
    pivot = median3(array, left, right);
    int i = left, j = right - 1;

    for ( ; ; ) {
        while(i < j && array[++i] < pivot);
        while(i < j && array[--j] > pivot);
        if ( i < j )
            swap(&array[i], &array[j]);
        else
            break;
    }
    swap(&array[i], &pivot);
    quickSelect(array, left, i - 1);
    quickSelect(array, i + 1, right);

}

int main() {
    int array[14] = {9, 2 ,4, 8, 5, 21, 20, 14, 6, 3, 1, 13, 17, 31};
    quickSelect(array, 0, 13);
    printf("k-th big num is :%d\n", array[9]);
    return 0;
}
