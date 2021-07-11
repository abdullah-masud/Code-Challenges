#include <stdio.h>
int bubbleSort(int *array, int n);

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

    bubbleSort(array,n);
}

int bubbleSort(int *array, int n)
{
    int temp;

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(array[j]>array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("\nSorted Array: \n");
    for(int k=0; k<n; k++)
    {
        printf("%d\n",array[k]);

    }
}
