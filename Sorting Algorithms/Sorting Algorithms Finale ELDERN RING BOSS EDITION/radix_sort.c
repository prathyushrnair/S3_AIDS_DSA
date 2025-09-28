#include<stdio.h>
#include<stdlib.h>
#include "sorting.h"
int getmax(int arr[],int n)
{
    int big=arr[0];
    for (int i=0;i<n;i++)
    {
        if (arr[i] > big)
        {
            big=arr[i];
        }
    }
    return big;
}
void countsort(int arr[],int n,int exp)
{
    int output[n];
    int i,count[10]={0};
    for(i=0;i<n;i++)
    {
        count[(arr[i]/exp)%10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
void radixsort(int arr[],int n)
{
    int exp;
    int max=getmax(arr,n);
    for(exp=1;(max/exp)>0;exp*=10)
    {
        countsort(arr,n,exp);
    }

}
// LOGIC THERNNUU (❁´◡`❁)
void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test above functions

// References https://www.w3schools.com/dsa/dsa_algo_radixsort.php
