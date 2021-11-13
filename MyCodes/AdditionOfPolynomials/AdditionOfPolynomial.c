#include<stdio.h>
#include<stdlib.h>

struct Poly
{
    int coeff;
    int expo;
    struct Poly *next;
};

//struct Poly Poly1 , Poly2 , Poly3;
struct Poly *front = NULL , *temp = NULL;

void createNode(int c , int e , struct Poly **newnode)
{
    newnode = (struct Poly **)malloc(sizeof(struct Poly));

    if(*newnode == NULL)
    {
        printf("\nMalloc failed to allocate memory\n");
    }
    else
    {
        (*newnode)->coeff = c;
        (*newnode)->expo = e;

        if(front == NULL)
        {
            (*newnode)->next = NULL;
            front = (*newnode);
            temp = (*newnode);
            
        }
        else
        {
            (*newnode)->next = NULL;
            temp->next = (*newnode);
            temp = (*newnode);
        }
    }
    printf("\nFront Coeff %d " , front->coeff);
    printf("\nAddress of front %d " , &front);
    printf("\nNewnode coeff %d" , (*newnode)->coeff);
    printf("\nnewnode add %d" , &newnode);
    printf("\ntemp coeff %d" , temp->coeff);
    printf("\ntemp add %d" , &temp);
}

struct Poly *addPolynomials(struct Poly *Poly1 , struct Poly *Poly2)
{
    struct Poly *first = Poly1 , *second = Poly2;
    struct Poly *Poly3 = NULL;
    display(first);
    display(second);

    if(first->expo > second->expo)
    {
        createNode(first->coeff , first->expo , &Poly3);
    }
    else
    {
        createNode(second->coeff , second->expo , &Poly3);
    }

    while(first != NULL && second != NULL)
    {
        if(first->expo == second->expo)
        {
            createNode(first->coeff + second->coeff , first->expo , &Poly3);
        }
        first = first->next;
        second = second->next;
    }
    return Poly3;
}

void display(struct Poly *Node)
{
    struct Poly *temp = Node;
    printf("%d" , Node->coeff);
    Node = Node->next;
    printf("%d" , Node->coeff);

    while(temp->next != NULL)
    {
        printf("%dx^%d + " , temp->coeff , temp->expo);
        temp = temp->next;

        if(temp->next == NULL)
            printf("%dx^%d " , temp->coeff , temp->expo);
    }
}
void main()
{
    int d1 , d2 , coefficient1 , coefficient2;
    printf("\nEnter degree of 1st Polynomial\n");
    scanf("%d" , &d1);
    printf("\nEnter degree of 2nd Polynomial\n");
    scanf("%d" , &d2);

    struct Poly *first = NULL , *second = NULL , *addition = NULL;

    printf("\nFor 1st Polynomial : \n");
    for(int i = d1 ; i >= 0 ; i--)
    {
        printf("\nEnter the coefficient of degree %d : \n" , i);
        scanf("%d" , &coefficient1);
        createNode(coefficient1 , i , &first);
    }
    //printf("\n1st Polynomial is : \n");
    printf("%d" , first->coeff);
    first = first->next;
    printf("%d" , first->coeff);

    /*display(first);

    front = NULL , temp = NULL;
    printf("\nFor 2nd Polynomial : \n");
    for(int i = d2 ; i >= 0 ; i--)
    {
        printf("\nEnter the coefficient of degree %d : \n" , i);
        scanf("%d" , &coefficient2);
        createNode(coefficient2 , i , &second);
    }

    printf("\n2nd Polynomial is : \n");
    display(&second);

    addition = (struct Poly *)malloc(sizeof(struct Poly));
    front = NULL , temp = NULL;
    printf("\n\nAddition of Polynomial 1 and Polynomial 2 is : \n");
    addition = addPolynomials(first , second);
    display(addition);*/
}