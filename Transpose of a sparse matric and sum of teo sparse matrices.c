/*
matrices -> tuple format ->transpose ->add the 2 tuple format matrices
3 functions -> Convert Transpose ADD
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define MAX_COL 100
typedef struct {
	int row;
	int column;
	int value;
} values;

typedef struct {
	int no_row;
	int no_column;
	int non_zero_terms;
	values arr[MAX];
} sparse;

sparse convert_to_sparse(int arr1[][MAX_COL],int rows,int cols,sparse *arrr1 ) {
	//take rows column no of terms
	arrr1->no_row=rows;
	arrr1->no_column=cols;
	arrr1->non_zero_terms=0;
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			if (arr1[i][j]!=0) {
				arrr1->arr[arrr1->non_zero_terms].row=i;
				arrr1->arr[arrr1->non_zero_terms].column=j;
				arrr1->arr[arrr1->non_zero_terms].value=arr1[i][j];
				arrr1->non_zero_terms++;
			}
		}
	}
	return *arrr1;
}
//the above functions converts a normal array arr1 to a sparse matrix arrr1
void transpose(sparse *OG,sparse *result) {
	result->no_row=OG->no_column;
	result->no_column=OG->no_row;
	result->non_zero_terms=OG->non_zero_terms;
	for(int i=0; i<OG->non_zero_terms; i++) {
		result->arr[i].row=OG->arr[i].column;
		result->arr[i].column=OG->arr[i].row;
		result->arr[i].value=OG->arr[i].value;
	}
}
void add(sparse *arr1, sparse *arr2,sparse *result) {
	if (arr1->no_row!=arr2->no_row || arr1->no_column!=arr2->no_column) {
		printf("Matrices dimensions are out of bonds\n");
		return;
	}
	result->no_row=arr1->no_row;
	result->no_column=arr1->no_column;
	result->non_zero_terms=0;
	int i=0,j=0;
	while(i<arr1->non_zero_terms && j<arr2->non_zero_terms) {
		if(arr1->arr[i].row<arr2->arr[i].row ||(arr1->arr[i].row==arr2->arr[i].row && arr1->arr[i].column<arr2->arr[j].column)) {
			result->arr[result->non_zero_terms++]=arr1->arr[i++];
		}
		else if(arr1->arr[i].row=arr2->arr[j].row && arr1->arr[i].column==arr2->arr[j].column) {
			result->arr[result->non_zero_terms].row=arr1->arr[i].row;
			result->arr[result->non_zero_terms].column=arr1->arr[i].column;
			result->arr[result->non_zero_terms].value=arr1->arr[i].value+arr2->arr[j].value;
			result->non_zero_terms++;
			i++;
			j++;
		}
		else {
			result->arr[result->non_zero_terms]=arr2->arr[j++];
		}

	}
	while(i<arr1->non_zero_terms) {
		result->arr[result->non_zero_terms++]=arr1->arr[i++];
	}
	while(j<arr2->non_zero_terms) {
		result->arr[result->non_zero_terms++]=arr2->arr[j++];
	}
}

void display(sparse *sp) {
	printf("Details are in this way\n");
	printf("ROW\tCOLUMN\tVALUE\n");
	for(int i=0; i<sp->non_zero_terms; i++) {
		printf("%d\t%d\t%d\n",sp->arr[i].row,sp->arr[i].column,sp->arr[i].value);
	}
}

int main() {
	int arr1[][MAX_COL]= {{1,0,0},{0,2,0},{0,0,3}};
	int arr2[][MAX_COL]= {{0,1,0},{2,0,0},{0,0,4}};
	sparse sa,sb,tranposedd,summ;
	convert_to_sparse(arr1,3,3,&sa);
	convert_to_sparse(arr2,3,3,&sb);
	printf("Matrix 1\n");
	display(&sa);
	printf("Matrix 2\n");
	display(&sb);
	transpose(&sa,&tranposedd);
	printf("transpose of the matrix \n");
	display(&tranposedd);
	add(&sa,&sb,&summ);
	printf("SUmmation of 2 matrices\n");
	display(&summ);

	return 0;
}





