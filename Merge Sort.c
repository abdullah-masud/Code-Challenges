#include <stdio.h>
main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    mergeSort(arr,0,n-1);

    printArray(arr, n);
}

// Divide the array into two sub arrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two sub arrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Merge two subarrays L and M into arr
void merge(int arr[], int l, int m, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], M[n2];


  for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[m + 1 + j];
    }
    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[l..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

    // Print the array
void printArray(int arr[], int size) {

    printf("Sorted Elements: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        printf("\n");
    }
}
