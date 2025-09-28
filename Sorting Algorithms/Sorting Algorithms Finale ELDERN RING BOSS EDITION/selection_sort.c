#include<stdio.h>
#include<stdlib.h>
#include "sorting.h"
void selection_sort(int array[],int lenght)
{
    for(int i=0;i<lenght-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<lenght;j++)
        {
            if(array[j] < array[min_index])
            {
                min_index=j;

            }

        }
        swap(&array[i],&array[min_index]);

    }
    printf("Sorting is completed...\n");
}


