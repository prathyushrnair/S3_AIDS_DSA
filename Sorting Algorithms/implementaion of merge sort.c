#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int arr[10] = {64, 34, 25, 12, 22, 11, 90};
void mergesort(int array[],int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int mid= (low+high)/2;
    //slicing left and right parts for split
    int left_size=mid-low+1;
    int right_size=high - mid;

    int left[left_size];
    int right[right_size];

    for(int i=0;i<left_size;i++)
    {
        left[i]=array[low+i];
    }
    printf("Left 'SUB array' is \n");
    for(int i=0;i<left_size;i++)
    {
        printf("%d  ",left[i]);
    }printf("\n");
    //similarily for the right side

    for(int i=0;i<right_size;i++)
    {
        right[i]=array[mid+i+1];
    }
    printf("Right 'SUB array' is \n");
    for(int i=0;i<right_size;i++)
    {
        printf("\t %d \t",right[i]);
    }
    mergesort(array,low,mid);
    mergesort(array ,mid+1,high);
    int i=0,j=0,k=low;
    while (i<left_size && j<right_size)
    {
        if (left[i] <= right[j])
        {
            array[k++]=left[i++];
        }
        else
        {
            array[k++]=right[j++];
        }
    }
    while (i<left_size)
    {
        array[k++]=left[i++];
    }
    while(j<right_size)
    {
        array[k++]=right[j++];
    }
    //printing the merged result
    printf("Merged result: ");
    for(int i = low; i <= high; i++) {
        printf("\t%d\t", array[i]);
    }
    printf("\n\n");
}


void main()
{
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i = 0; i < arr_len; i++) {
        printf("\t%d\t", arr[i]);
    }
    printf("\n\n");

    // Call mergesort on the global array
    mergesort(arr, 0, arr_len - 1);

    printf("Final sorted array: ");
    for(int i = 0; i < arr_len; i++) {
        printf("\t%d\t", arr[i]);
    }
    printf("\n");
}
