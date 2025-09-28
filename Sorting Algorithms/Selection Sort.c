#include<stdio.h>
#include<stdlib.h>
void swap(int *first_number,int *second_number)
{
    int temp=*first_number;
    *first_number=*second_number;
    *second_number=temp;
}

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
    selection_sort(array,n);
    print_function(array,n);
    return 0;
}
