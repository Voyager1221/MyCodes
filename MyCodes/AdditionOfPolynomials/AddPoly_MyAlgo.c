#include<stdio.h>
#include<stdlib.h>

struct PolyNode{
    int coeff;
    int expo;
    struct PolyNode* next;
};

typedef struct PolyNode PolyNode;

PolyNode *first=NULL,*second=NULL, *add=NULL;
PolyNode *prev=NULL;
int flag =0;

PolyNode* createNode(int coeff, int expo){
    PolyNode *newNode;
    newNode = (PolyNode*) malloc(sizeof(PolyNode));
    newNode->next = NULL;
    newNode->coeff = coeff;
    newNode->expo = expo;
    return newNode;
}

void createPoly(int coeff, int expo){
    PolyNode *newNode=NULL;
    //PolyNode *prev;
    newNode = createNode(coeff, expo);
    if(flag==0){
        if(first==NULL){
            first = newNode;    
        }
    }
    else{
        if(second==NULL){
            second = newNode;
        }
    }
    prev->next = newNode;
    prev = newNode;
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
    while(temp->next){
        printf("%dx^%d + ",temp->coeff,temp->expo);
        
    if(temp->next==NULL){    
        printf("%dx^%d", temp->coeff, temp->expo);
    }
    temp = temp->next;
    }
}

/* int menu(){

    int ch;
    printf("\n1.\tTo add node");
    printf("\n1.\tTo add node");
    printf("\n1.\tTo add node");
}
 */
int main(){
    int deg1, deg2, coeff1, coeff2;
    printf("\nEnter the degree of 1st Polynomial\n");
    scanf("%d",&deg1);
    printf("\nEnter the degree of 2nd Polynomial\n");
    scanf("%d",&deg2);

    /* while (deg1>=0){
        printf("\nEnter the coefficient of degree %d :",deg1 );
        scanf("%d", &coeff1);
        createPoly(coeff1,deg1--);
    } */
    for(int i=deg1;i>=0;i--){
        printf("\nEnter the coefficient of degree %d :",i );
        scanf("%d", &coeff1);
        createPoly(coeff1,i);
    }
    flag=1;
    printf("\nFor 2nd Polynomial\n");
    for(int i=deg2;i>=0;i--){
        printf("\nEnter the coefficient of degree %d :",i );
        scanf("%d", &coeff2);
        createPoly(coeff2,i);
    }

    /* while(deg2>=0){
        printf("\nEnter the coefficient of degree %d :",deg2 );
        scanf("%d", &coeff2);
        createPoly(coeff2,deg2--);
    } */
    
    printf("\n1st Polynomial is : \n");
    display(first);

    printf("\n2nd Polynomial is : \n");
    display(second);
    
    addition();
    
    printf("\nThe addition of Polynomials is : \n");
    display(add);
}