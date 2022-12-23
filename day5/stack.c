#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack* init_stack(int id){
    struct stack* new_stack;
    new_stack = (struct stack*)malloc(sizeof(struct stack));
    new_stack->base = NULL;
    new_stack->head = new_stack->base;
    new_stack->ID = id;
    return new_stack;
}


char pop(struct stack* s){
    char to_return;
    struct node* temp;
    if(s->head == s->base){
        to_return = 0;
        printf("Stack is empty\n");
    }else{
        to_return = s->head->box;
        temp = s->head;
        s->head=s->head->below;
        free(temp);
    }
    return to_return;
}

int push(struct stack* s,char c){
    struct node* new_node;
    new_node = (struct node*) malloc(sizeof(struct node));
    new_node->box = c;
    new_node->below = s->head;
    s->head = new_node;
    return 1;
}