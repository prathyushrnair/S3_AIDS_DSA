#include<stdio.h>
#include<stdlib.h>
#include "sorting.h"


int partition(int array[],int low,int high)
{
    int i=0,j=0;
    i=low-1;
    int pivot=array[high];
    for(j=low;j<high;j++)
    {
        if(array[j] <= pivot)
        {
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i+1],&array[high]);
    return i+1;
}

void quicksort(int array[],int low,int high)
{
    if (low < high)
    {
        int pivot=partition(array,low,high);
        quicksort(array,low,pivot-1);
        quicksort(array,pivot+1,high);
    }
}



/*
REFERENCES

https://www.w3schools.com/dsa/dsa_algo_quicksort.php
https://www.youtube.com/watch?v=Vtckgz38QHs

*/
