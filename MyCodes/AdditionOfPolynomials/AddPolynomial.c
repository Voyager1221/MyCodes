#include<stdio.h>
#include<stdlib.h>
struct Poly{
    int coeff;
    int expo;
    struct Poly* next;
};
typedef struct Poly Poly;

Poly*head=NULL, *last=NULL;
Poly *first=NULL, *second=NULL;
Poly **add=NULL;
int flag=0;

void createNode(int coeff, int expo){
    Poly *newNode;
    newNode = (Poly*) malloc(sizeof(Poly));
    newNode->coeff =coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    if(flag==0){
        
        if(first==NULL){
            first = newNode;
            last = newNode;
            printf("\nFlag=0");
        }
    }
    else{
        printf("\nFlag=1");
        if(second==NULL){
            second = newNode;
            last = newNode;
        }
    }    
    last->next = newNode;
    last = newNode;
    
}

int sizeOfLL(Poly *temp){
    int cnt=0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void additionOfPolynomials(){
    Poly *p1, *p2;
    //int indicator=0;
    p1=first;
    p2=second;
    
    if(sizeOfLL(first)>=sizeOfLL(second)){
        printf("\naddress of p1 : %d",&p1);
        add=&p1;
        while(sizeOfLL(p1)!=sizeOfLL(p2)){        
            p1 = p1->next;
        }
        while(p1){
            p1->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    else if(sizeOfLL(first)<sizeOfLL(second)){
        printf("\naddress of p2 : %d",&p2);
        add=&p2;
        while(sizeOfLL(p2)!=sizeOfLL(p1)){
            p2 = p2->next;
        }
        while(p2){
            p2->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    //return add;
}

void display(Poly**Node){

    while((*Node)->next != NULL)
    {
        printf("%dx^%d + " , (*Node)->coeff , (*Node)->expo);
        (*Node) = (*Node)->next;

        if((*Node)->next == NULL)
            printf("%dx^%d " , (*Node)->coeff , (*Node)->expo);
    }
}

/* int menu(){

    int ch;
    printf("\n1.\tTo  node");
    printf("\n2.\tTo add node");
    printf("\n1.\tTo add node");
    printf("\n1.\tTo add node");
    printf("\n1.\tTo add node");
} */

int main(){

    int d1 , d2 , coefficient1 , coefficient2;
    printf("\nEnter degree of 1st Polynomial\n");
    scanf("%d" , &d1);
    printf("\nEnter degree of 2nd Polynomial\n");
    scanf("%d" , &d2);

    //struct Poly *first = NULL , *second = NULL , *addition = NULL;

    printf("\nFor 1st Polynomial : \n");
    for(int i = d1 ; i >= 0 ; i--)
    {
        printf("\nEnter the coefficient of degree %d : \n" , i);
        scanf("%d" , &coefficient1);
        createNode(coefficient1, i);
    }
    flag=1;
    printf("\nFor 2nd Polynomial : \n");
    for(int i = d2 ; i >= 0 ; i--)
    {
        printf("\nEnter the coefficient of degree %d : \n" , i);
        scanf("%d" , &coefficient2);
        createNode(coefficient2, i);
    }

    printf("\n1st Polynomial is : \n");
    display(&first);

    printf("\n2nd Polynomial is : \n");
    display(&second);
    
    additionOfPolynomials();
    
    printf("\nThe addition of Polynomials is : \n");
    printf("\nValue of **add : %d",add);
    display(add);
}