#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
#define SIZE 9
bool is_ascii(char c);
void print_stacks(struct stack* array[SIZE]);

int main(void){
    FILE* stack_input;
    FILE* mov_input;
    struct stack* stacks[SIZE]; 
    
    for(int i = 0; i<SIZE; i++){
        stacks[i] = init_stack(i);
    }

    //stack_input = fopen("day5_2.txt","r");
    //stack_input = fopen("r_example_stack.txt","r");
    stack_input = fopen("reverse_stack.txt","r");
    char in;
    int i = 0,j = 0,char_count=2;
    while(!feof(stack_input)){
        in = fgetc(stack_input);
        if(is_ascii(in)){
            push(stacks[j],in);
            print_stacks(stacks);
        }
        if(char_count%4 == 0){
            j++;
        }
        char_count++;
        if(in == '\n'){
            j=0;
            i++;
        }
        if(in == '1' || in == 1){
            break;
        }
    }
    print_stacks(stacks);
    fclose(stack_input);


    mov_input = fopen("day5.txt","r");
    //mov_input = fopen("example.txt","r");
    int quantity,src,dest;
    while(!feof(mov_input)){
        fscanf(mov_input,"move %d from %d to %d\n",&quantity,&src,&dest);
        for(int i = 0;i<quantity;i++){
            char box = pop(stacks[src-1]);
            if(box != 0){
                push(stacks[dest-1],box);
                printf("pushing %c from %d to %d\n",box,src-1,dest-1);
                print_stacks(stacks);
            }
        }
    }
    print_stacks(stacks);
    fclose(mov_input);
    
    return 0;
}

bool is_ascii(char c){
    if((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z')){
        return true;
    }
    return false;
}

void print_stacks(struct stack* array[SIZE]){
    for(int i = 0; i<SIZE; i++){
        struct node* iterator = array[i]->head;
        printf("%d:\t",i);
        while(iterator  != NULL){
            printf("[%c] ",iterator->box);
            iterator = iterator->below;
        }
        printf("\n");
    }
    printf("\n\n");
}