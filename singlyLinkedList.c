#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
};


int main(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = 10;
    newnode->next = NULL;
    printf("The value of newnode is: %d\n", newnode->info);

}