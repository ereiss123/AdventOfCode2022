#ifndef STACK_H
#define STACK_H
struct node{
    char box;
    struct node* below;
};

struct stack{
    int ID;
    struct node* head;
    struct node* base;
};

struct stack* init_stack(int id);
char pop(struct stack* s);
int push(struct stack* s,char c);

#endif