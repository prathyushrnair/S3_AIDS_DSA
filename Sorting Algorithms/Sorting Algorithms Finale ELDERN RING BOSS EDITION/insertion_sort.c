#include<stdio.h>
#include<stdlib.h>
#include "sorting.h"
void insertion_sort(int array[],int len)
{
        int i=1,j=0;
        for(i=1;i<len;i++)
        {
            int temp=i;
            int temp_value=array[i];
            j=i-1;
            while(j>=0 && array[j]>temp_value)
            {
                array[j+1]=array[j];
                temp=j;
                j--;
            }
        array[temp]=temp_value;
        }
        printf("\nSorting is over..\n");
}

/*
REFERENCES

https://www.w3schools.com/dsa/dsa_algo_insertionsort.php

*/
