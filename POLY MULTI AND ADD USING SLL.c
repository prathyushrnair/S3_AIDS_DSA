#include<stdio.h>
#include<stdlib.h>
typedef struct term {
	int coefficient;
	int exponent;
	struct term *link;
} TERM;

typedef struct {
	TERM *head;
} polynomial;

polynomial *create() {
	polynomial *p=(polynomial*) malloc (sizeof(polynomial));
	p->head=NULL;
	return(p);
}

void insert(polynomial *p,int coefficient, int exponent) {
	TERM *new_node = (TERM*) malloc(sizeof(TERM));
	new_node->coefficient=coefficient;
	new_node->exponent=exponent;
	new_node->link=NULL;
	if (p->head==NULL) {
		p->head=new_node;
	}
	else {
		TERM *curr=p->head;
		while (curr->link!=NULL) {
			curr=curr->link;
		}
		curr->link=new_node;
	}
}

void display(polynomial *p) {
	TERM *current=p->head;
	if (current ==NULL) {
		printf("Empty Polynomial\n");
		return;
	}
	printf("Here are the details...\n");
	while(current!=NULL) {
		printf("%d %d",current->coefficient,current->exponent);
		if(current->link!=NULL) {
			printf(" + ");
		}
		current=current->link;
	}
	printf("\n");
}

polynomial *add(polynomial *p1,polynomial *p2) {
	polynomial *result=create();
	TERM *a=p1->head;
	TERM *b=p2->head;
	while (a!=NULL && b!=NULL) {
		if(a->exponent == b->exponent) {
			int sum = a->coefficient + b->coefficient;
			if (sum!=0) {
				insert(result,sum,a->exponent);
				a=a->link;
				b=b->link;
			}
		}
		else if (a->exponent > b->exponent) {
			insert(result,a->coefficient,a->exponent);
			a=a->link;
		}
		else {
			insert(result,b->coefficient,b->exponent);
			b=b->link;
		}

	}

	while (a!=NULL) {
		insert(result,a->coefficient,a->exponent);
		a=a->link;
	}
	while (b!=NULL) {
		insert(result,b->coefficient,b->exponent);
		b=b->link;
	}
	return result;

}

int main() {
	int choices,i=0;
	polynomial *p1=create();
	polynomial *p2=create();
	while (1) {
		printf("These are the choices\n");
		printf("1.create\n2.Insert\n3.Display\n4.Add 2 poly\n5.Break\n");
		printf("Enter the choice from above\n");
		scanf("%d",&choices);
		if (choices==1) {
			printf("polynomials are created \n");
		}
		else if (choices==2) {
			int n,coefficient,exponent;
			printf("Enter the numbe of terms");
			scanf("%d",&n);
			for(i=0; i<n; i++) {
				printf("Enter coeff and expo for");
				scanf("%d",&coefficient);
				scanf("%d",&exponent);
				insert(p1,coefficient,exponent);
			}
			int j=0,coefficient1,exponent1,m=0;
			printf("Enter the number of terms for poly2\n");
			scanf("%d",&m);
			for(j; j<m; j++) {
				printf("Enter the coefficient and exponent for poly2\n");
				scanf("%d %d",&coefficient1,&exponent1);
				insert(p2,coefficient1,exponent1);
			}

		}
		else if(choices==3) {
			//Display fn
			display(p1);
			display(p2);
		}
		else if (choices==4) {
			//addition fn
			polynomial *sum =add(p1,p2);
			printf("results..\n");
			display(sum);
		}

	}
}

