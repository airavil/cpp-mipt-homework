#include <stdio.h>
void reverse(int* array, int size) 
{
    int a[size];
    for (int i = 0; i < size; i++)
        a[i] = array[i];
    for (int i = 0; i < size; i++)
        array[i] = a[size-1-i];
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    reverse(arr, size);
    for (int i = 0; i < size; i++)
        printf("%i ", arr[i]);
    printf("\n");
}