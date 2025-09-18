#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct {
	int coeff;
	int expo;
} arr;
typedef struct {
	int n;
	arr arr[MAX];
} poly;
void display(poly *p) {
	int i;
	for(i=0; i<p->n; i++) {
		printf("%d x^%d",p->arr[i].coeff,p->arr[i].expo);
		if(i<p->n-1) {
			printf(" + ");
		}
	}
	printf("\n");

}

poly add(poly *p1,poly *p2) {
	poly result;
	result.n=0;
	int i=0,j=0,k=0;
	while(i<p1->n && j<p2->n) {
		if(p1->arr[i].expo < p2->arr[i].expo) {
			result.arr[k++]=p2->arr[j++];
		}
		else if(p1->arr[i].expo > p2->arr[i].expo) {
			result.arr[k++]=p1->arr[i++];
		}
		else {
			result.arr[k].coeff=p1->arr[i].coeff+p2->arr[j].coeff;
			result.arr[k].expo=p1->arr[i].expo;
			k++;
			j++;
			i++;
		}
	}
	while(i<(p1->n)) {
		result.arr[k++]=p1->arr[i++];
	}
	while(j<(p2->n)) {
		result.arr[k++]=p2->arr[j++];
	}
	return result;
}

void insert(poly *p1,int coeff,int expo) {
	int len=0;
	len=p1->n;
	for(int i=0; i<p1->n; i++) {
		if(p1->arr[i].expo==expo) {
			p1->arr[i].coeff+=coeff;
			return;
		}
	}
	p1->arr[len].coeff=coeff;
	p1->arr[len].expo=expo;
	p1->n++;
}

poly prdt(poly *p1,poly *p2) {
	int coeff=0,result=0,expo=0;
	poly result1;
	result1.n=0;
	for(int i=0; i<p1->n; i++) {
		for(int j=0; j<p2->n; j++) {
			coeff=p1->arr[i].coeff*p2->arr[j].coeff;
			expo=p1->arr[i].expo*p2->arr[i].expo;
			insert(&result1,coeff,expo);
		}
	}
	return result1;
}
//<--Functions code/logic over now onto the main function -->
int main() {
	//initialising 2 poly'
	poly p1= {
		.arr={ {9,8},{7,6},{5,4},{6,9}},
		.n=4
	};
	poly p2= {
		.arr={ {1,2},{3,4},{5,6},{7,8}},
		.n=4

	};
	//display function
	printf("Polynomial 1 =\n");
	display(&p1);
	printf("Polynomial 2=\n");
	display(&p2);
	//add function
	poly sum;
	sum=add(&p1,&p2);
	display(&sum);
	//prdt function
	poly product;
	product=prdt(&p1,&p2);
	display(&product);
	return(1);

}








