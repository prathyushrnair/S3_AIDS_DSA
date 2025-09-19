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

