#include<stdio.h>
#include<stdlib.h>
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
int main()
{
    int array[]={64, 34, 25, 12, 22, 11, 90, 5};
    int length=sizeof(array) / sizeof(array[0]);
    insertion_sort(array,length);
    printf("\n..sorted..\n");
    printf("length of the array is %d\n",length);
    for(int i=0;i<length;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}
