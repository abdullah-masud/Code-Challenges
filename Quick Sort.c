#include <stdio.h>
main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int array[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&array[i]);
    }

    quickSort(array,0,n-1);

    printf("\nThe Sorted Array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void quickSort(int array[], int low, int high)
{
    if(low<high)
    {
        int pivot = partition(array, low, high);

        quickSort(array, low, pivot-1);
        quickSort(array, pivot+1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for(int j=low; j<high; j++)
    {
        // if pivot is greater or equal to current element
        if(array[j]<=pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i+1], &array[high]);
    return (i+1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
