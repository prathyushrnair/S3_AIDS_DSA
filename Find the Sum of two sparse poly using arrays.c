#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct term {
	int coeff;
	int expo;
} trm;

int main() {
	trm arr1[MAX],arr2[MAX],arr3[MAX*2]; //allocation to resultant poly must be >>
	//initialise the iterators
	for(int x=0; x<MAX*2; x++) {
		arr3[x].coeff=0;
		arr3[x].expo=0;
	}//clearing all garbage values
	int i=0,j=0,k=0,n1,n2;
	printf("No of non zero elements Poly 1\n");
	scanf("%d",&n1);
	for(i; i<n1; i++) {
		printf("Enter co p1 %d \n",i+1);
		scanf("%d",&arr1[i].coeff);
		printf("Entr expo p1 %d \n",i+1);
		scanf("%d",&arr1[i].expo);
	}
	printf("No of non zero elements poly2\n");
	scanf("%d",&n2);
	for(j; j<n2; j++) {
		printf("Enter coeff poly 2 %d\n",j+1);
		scanf("%d",&arr2[j].coeff);
		printf("Enter expo poly 2\n");
		scanf("%d",&arr2[j].expo);
	}
	i=0;
	j=0;
	while(i<n1 && j<n2) {
		if(arr1[i].expo<arr2[j].expo) {
			arr3[k].expo=arr1[i].expo;
			arr3[k].coeff=arr1[i].coeff;
			i++;
			k++;
		}

		else if(arr1[i].expo>arr2[j].expo) {
			arr3[k].expo=arr2[j].expo;
			arr3[k].coeff=arr2[j].coeff;
			k++;
			j++;
		}
		else {
			int sum=0;
			sum=arr1[i].coeff+arr2[j].coeff;
			if (sum!=0) {
				arr3[k].coeff=sum;
				arr3[k].expo=arr1[i].expo;
				k++;
			}
			i++;
			j++;
		}
	}
	//now take care of the left over terms
	while(i<n1) {
		arr3[k].coeff=arr1[i].coeff;
		arr3[k].expo=arr1[i].expo;
		i++;
		k++;
	}
	while(j<n2) {
		arr3[k].coeff=arr2[j].coeff;
		arr3[k].expo=arr2[j].expo;
		k++;
		j++;
	}
	//print the results
	printf("Result =\n");
	int m=0;
	for(m; m<k; m++) {
		printf("%d",arr3[m].coeff);
		if (arr3[m].expo!=0) {
			printf("X^%d",arr3[m].expo);
		}
		//condition to check for " + "
		if (m!=k-1) {      //checks until k-1 [last term]
			printf(" + ");
		}
	}
	return 0;
}