#include <stdio.h>
int maxSumSubArray(int *array, int low, int high);
int maxCrossingSubArray(int *array, int low, int mid, int high);
int maximum(int a, int b, int c);

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

    int maxSum = maxSumSubArray(array,0,n-1);

    printf("Maximum Sum Sub Array: %d", maxSum);
}

// function to calculate the maximum sub array sum
int maxSumSubArray(int *array, int low, int high)
{
    // If only one element (Best Case)
    if(high==low)
    {
        return array[high];
    }

    int mid = (low+high)/2;

    // Maximum sum in the left sub array
    int maxSumLeft_subArray =  maxSumSubArray(array,low,mid);
    // Maximum sum in the left sub array
    int maxSumRight_subArray =  maxSumSubArray(array,mid+1,high);
    // maximum sum in the array containing the middle element
    int maxSumCrossing_subArray = maxCrossingSubArray(array,low,mid,high);

    // returning the maximum among the above three numbers
    return maximum(maxSumLeft_subArray, maxSumRight_subArray, maxSumCrossing_subArray);

}

// function to find maximum sum of sub array crossing the middle element.
int maxCrossingSubArray(int *array, int low, int mid, int high)
{
    // Elements on left of mid
    int left_sum = -1000000;
    int i, sum = 0;

    /* iterating from middle element to the lowest element to find the
     maximum sum of the left sub array containing the middle element also. */
    for(i=mid; i>=low; i--)
    {
        sum = sum + array[i];
        if(sum>left_sum)
        {
            left_sum = sum;
        }
    }

    // Elements on right of mid
    int right_sum = -1000000;
    sum = 0;
    for(i=mid+1; i<=high; i++)
    {
        sum = sum + array[i];
        if(sum>right_sum)
        {
            right_sum=sum;
        }
    }

    // returning the maximum sum of the sub array containing the middle element.
    return (left_sum+right_sum);
}

// function to return maximum number among three numbers
int maximum(int a, int b, int c)
{
    if(a>=b && a>=c)
    {
        return a;
    }
    else if(b>=a && b>=c)
    {
        return b;
    }
    else
    {
        return c;
    }
}
