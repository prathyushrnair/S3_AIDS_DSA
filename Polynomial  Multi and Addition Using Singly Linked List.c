#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int expo;
    struct node *link;
    };
void addterm(struct node **head,int coeff,int expo)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->expo=expo;
    newnode->link=NULL;
    if (*head==NULL)
    {
        *head=newnode;
    }
    struct node *temp=*head;
    while(temp!=NULL)
    {
        temp=temp->link;
    }
    temp->link=newnode;
}

void combineliketerms(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        struct node *prev=temp;
        struct node *next=temp->link;
        while(next->link!=NULL)
        {
            if (next->expo==prev->expo)
            {
                temp->coeff+=prev->coeff;
                prev->link=next->link;
                free(next);
                next=prev->link;
            }
            else
            {
                prev=next;
                next=next->link;
            }
        }
    temp=temp->link;
    }
}

struct node *multiplypoly(struct node *head1,struct node *head2)
{
    struct node *result=NULL;
    struct node *temp1=head1;
    while(temp1!=NULL)
    {
        struct node *temp2=head2;
        while(temp2!=NULL)
        {
            int product_coeff=temp1->coeff*temp2->coeff;
            int product_expo=temp1->expo+temp2->expo;
            addterm(&result,product_coeff,product_expo);
            temp2=temp2->link;
        }
        temp1=temp1->link;
    }
    combineliketerms(result);
    return result;
}
void printPoly(struct node *head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->link;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}
int main() {
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *poly_result = NULL;

    // Example Polynomial 1: 5x^2 + 3x^1 + 2x^0
    addterm(&poly1, 5, 2);
    addterm(&poly1, 3, 1);
    addterm(&poly1, 2, 0);

    printf("Polynomial 1: ");
    printPoly(poly1);

    // Example Polynomial 2: 2x^1 + 4x^0
    addterm(&poly2, 2, 1);
    addterm(&poly2, 4, 0);

    printf("Polynomial 2: ");
    printPoly(poly2);

    // Multiply the polynomials
    poly_result = multiplypoly(poly1, poly2);

    printf("Result of multiplication: ");
    printPoly(poly_result);

    return 0;
}


