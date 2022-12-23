#include <stdio.h>
#include<stdbool.h>
#define BUFFER_SIZE 14

/*
The only thing that changes between part 1 and part 2 is the buffer size
*/

bool test(char buffer[BUFFER_SIZE]);

int main(void){
    FILE* input;
    input = fopen("day6.txt","r");
    //input = fopen("ex2.txt","r");
    char buffer[BUFFER_SIZE];
    int char_count = 0, i = 0;
    char curr;

    while(!feof(input)){
        curr = fgetc(input);
        buffer[i] = curr;
        if(char_count > BUFFER_SIZE && test(buffer)){
             break;
        }
        char_count++;
        i=char_count%BUFFER_SIZE;  
    }

    printf("The position is %d with %s\n",char_count+1,buffer);
    fclose(input);
    return 0;
}

bool test(char buffer[BUFFER_SIZE]){
    bool different = true;
    for(int i = 0; i<BUFFER_SIZE;i++){
        for(int j = i; j<BUFFER_SIZE;j++){
            if(i!=j && buffer[i] == buffer[j]){
                different = false;
                break;
            }
        }
        if(!different){
            break;
        }
    }
    return different;
}