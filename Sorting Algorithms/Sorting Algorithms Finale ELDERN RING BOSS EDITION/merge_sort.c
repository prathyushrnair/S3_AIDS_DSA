#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#include "sorting.h"

void mergesort(int array[],int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int mid= (low+high)/2;
    mergesort(array,low,mid);
    mergesort(array ,mid+1,high);
    //slicing left and right parts for split
    int left_size=mid-low+1;
    int right_size=high - mid;

    int left[left_size];
    int right[right_size];

    for(int i=0;i<left_size;i++)
    {
        left[i]=array[low+i];
    }
    for(int i=0;i<right_size;i++)
    {
        right[i]=array[mid+i+1];
    }

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
}