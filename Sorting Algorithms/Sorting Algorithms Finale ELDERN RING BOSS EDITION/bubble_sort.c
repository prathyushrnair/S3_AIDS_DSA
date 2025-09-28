#include<stdio.h>
#include<stdlib.h>
#include "sorting.h"

void bubble_sort(int array[],int length)
{
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            if (array[i] < array[j])
            {
                swap(&array[i],&array[j]);
            }
        }
    }
    printf("\nBubble Sort function exits..\n");
}


