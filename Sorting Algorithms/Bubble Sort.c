#include<stdio.h>
#include<stdlib.h>

void swap_function(int *first_number,int *second_number)
{
    int temp=*first_number;
    *first_number=*second_number;
    *second_number=temp;
}
void bubble_sort(int array[],int length)
{
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            if (array[i] < array[j])
            {
                swap_function(&array[i],&array[j]);
            }
        }
    }
    printf("\nBubble Sort function exits..\n");
}
void print_function(int array[],int max_length)
{
    printf("Elements in the array is \n");
    for(int i=0;i<max_length;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n ------------------------ \n");
}
int main()
{
    int array[]={64, 34, 25, 5, 22, 11, 90, 12};
    int n= sizeof(array)/sizeof(array[0]);
    bubble_sort(array,n);
    print_function(array,n);
    return 0;
}
