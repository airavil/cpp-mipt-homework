#include <stdio.h>
int count_even(int array[], int size) 
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (array[i] % 2 == 0)
            count++;
    return count;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    printf("%i\n", count_even(arr, size));
}