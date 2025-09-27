#include<stdio.h>
#include<stdlib.h>
void swap(int *First_number,int *Second_number)
{
    int temp=*First_number;
    *First_number=*Second_number;
    *Second_number=temp;
}

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

int main()
{
    int array[]={64, 34, 25, 12, 22, 11, 90, 5};
    int max_length=sizeof(array)/sizeof(array[0]);
    quicksort(array,0,max_length-1);
    //printing statements
    printf("Sorted list = \n");
    for(int i=0;i < max_length;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}

/*
REFERENCES

https://www.w3schools.com/dsa/dsa_algo_quicksort.php
https://www.youtube.com/watch?v=Vtckgz38QHs

*/
