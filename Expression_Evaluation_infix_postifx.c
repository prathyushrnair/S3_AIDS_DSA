#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<ctype.h>
#define MAX 50
char opstack[MAX];
int optop=-1;

void pushop(char c) {
    if(optop ==MAX-1){
        printf("Stack is full\n Overflowing....\n");
        exit(1);
    }
	opstack[++optop]=c;
}


char popOp() {
    
	return opstack[optop--];
}

char peekop() {
	return opstack[optop];
}

int isemptyop() {
	return optop==-1;
}


float numstack[MAX];
int numtop=-1;
void pushnum(float n) {
	numstack[++numtop]=n;
}
float popnum() {
	return numstack[numtop--];
}

int precedence(char c) {
	if (c=='^') {
		return 3;
	}
	if(c=='*'||c=='/') {
		return 2;
	}
	if(c=='+' ||c=='-') {
		return 1;
	}
	return 0;
}

bool checkRightAssociativity(char c) {
	return c == '^';
}

void convert(char infix[],char postfix[]) {
	int i=0,k=0;
	char c;
	while(c=infix[i++]!='\0') {
		if (isalnum(c)) {
			postfix[k++]=c;
			postfix[k++]=' ';

		}
		else if(c=='(') {
			pushop(c);
		}
		else if(c==')') {
			while(!isemptyop()&&peekop()!='(') {
				postfix[k++]=popOp();
			}
			popOp();
		}
		else {
			while(!isemptyop() &&precedence(peekop()) >=precedence(c)) {
				postfix[k++]=popOp();
				postfix[k++]=' ';
			}
			pushop(c);
		}
		i++;
	}
	while(!isemptyop()) {
		postfix[k++]=popOp(opstack);
		postfix[k++]=' ';
	}
	postfix[k]='\0';
}

int evaluate(char postfix[],float Value[26]) {
	int i=0;
	char c;
	while ((c = postfix[i++]) != '\0') {
		if (isalnum(c)) {
			pushnum(Value[c-'a']);
		}
		else {
			float a=popnum();
			float b=popnum();
			if (c == '+') {
				pushnum(a+b);
			}
			else if(c == '-') {
				pushnum(a-b);
			}
			else if(c == '*') {
				pushnum(a*b);
			}
			else if(c == '/') {
				pushnum(a/b);
			}
			else if(c == '^') {
				pushnum(pow(a,b));
			}
		}
	}
	return popnum();
}

int main() {
	char infix[MAX],postfix[MAX];
	float Value[26]= {0};
	printf("Enter infix expression\n");
	scanf("%s",infix);
	for(int i=0; infix[i]!='\0'; i++) {
		if(isalpha(infix[i])&&Value[infix[i]-'a']==0) {
			printf("Enter value of the variable %c\n ",infix[i]);
			scanf("%f",&Value[infix[i]-'a']);
		}
	}

	convert(infix,postfix);
	printf("%s",postfix);
	float result= evaluate(postfix,Value);
	printf("Result=\n %f",result);

	return 0;
}


















