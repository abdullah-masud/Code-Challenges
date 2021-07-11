#include <stdio.h>
int insertionSort(int *array, int n);
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

    insertionSort(array,n);
}

int insertionSort(int *array, int n)
{
    int item;
    for(int i=1; i<=n; i++)
    {
        int insert_at = i;
        item = array[i];
        int j = i-1;
        while(j>=0 && item <array[j])
        {
            array[j+1] = array[j];
            j--;
        }
        insert_at = j+1;
        array[insert_at] = item;
    }

    printf("\nSorted Array: \n");
    for(int k=0; k<n; k++)
    {
        printf("%d\n",array[k]);

    }

}
