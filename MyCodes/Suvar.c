#include<stdio.h>
#include<stdlib.h>

struct PolyNode{
    int coeff;
    int expo;
    struct PolyNode* next;
};

typedef struct PolyNode PolyNode;

PolyNode *first=NULL,*second=NULL, *add=NULL;
int flag =0;
PolyNode *prev = NULL;

PolyNode* createNode(int coeff, int expo)
{
    PolyNode *newNode;
    newNode = (PolyNode*) malloc(sizeof(PolyNode));
    newNode->next = NULL;
    newNode->coeff = coeff;
    newNode->expo = expo;
    return newNode;
}

void createPoly(int coeff, int expo){
    PolyNode *Node = NULL;

    Node = createNode(coeff, expo);
    if(flag==0)
    {
        if(first==NULL)
        {
            first = Node;
            prev = Node;
        }
    }
    else
    {
        if(second==NULL){
            second = Node;
            prev = Node;
        }
    }
    prev->next = Node;
    prev = Node;
}

int sizeOfLL(PolyNode *temp){
    int cnt  = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void addition(){
    PolyNode *p1,*p2;
    p1 = first;
    p2 = second;

    if(sizeOfLL(first)>=sizeOfLL(second)){
        add=p1;
        while(sizeOfLL(p1)!=sizeOfLL(second)){
            p1 = p1->next;
        }
        while(p1){
            p1->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    else if(sizeOfLL(first)<sizeOfLL(second)){
        add=p2;
        while(sizeOfLL(p1)!=sizeOfLL(p2)){
            p2 = p2->next;
        }
        while(p2){
            p2->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
}

void display(PolyNode *temp){
    while(temp){
        printf("%dx^%d + ",temp->coeff,temp->expo);
        temp = temp->next;
    }
}


int main(){
    int deg1, deg2, coeff1, coeff2;
    printf("\nEnter the degree of 1st Polynomial\n");
    scanf("%d",&deg1);
    printf("\nEnter the degree of 2nd Polynomial\n");
    scanf("%d",&deg2);

    printf("\nEnter 1st Polynomial\n");
    for(int i=deg1;i>=0;i--){
        printf("\nEnter the coefficient of degree %d :",i);
        scanf("%d", &coeff1);
        createPoly(coeff1,i);
    }

    printf("\nEnter 2nd Polynomial\n");
    flag=1;
    //prev = NULL;
    for(int i=deg2;i>=0;i--){
        printf("\nEnter the coefficient of degree %d :",i);
        scanf("%d", &coeff2);
        createPoly(coeff2,i);
    }

    printf("\n1st Polynomial is : \n");
    display(first);

    printf("\n2nd Polynomial is : \n");
    display(second);

    addition();

    printf("\nThe addition of Polynomials is : \n");
    //printf("\nValue of addition : %d", add);
    display(add);
}
