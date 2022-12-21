#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 124

//Function Pre-defines
int get_priority(char c);
int get_size(char* array,int size);

int main(void){
    FILE* input;
    input = fopen("day3.txt","r");
    //input = fopen("example.txt","r");
    char buffer1[BUFFER_SIZE],buffer2[BUFFER_SIZE],buffer3[BUFFER_SIZE];
    for(int i=0; i<BUFFER_SIZE;i++){
        buffer1[i] = 0;
        buffer2[i] = 0;
        buffer3[i] = 0;
    }

    int size1=0,sum=0;
    while(!feof(input)){
        fscanf(input,"%s\n%s\n%s\n",buffer1,buffer2,buffer3);
        //size = get_size(buffer,BUFFER_SIZE);
        size1 = get_size(buffer1,BUFFER_SIZE);
        for(int i=0; i<size1;i++){
            char* b1 = strchr(buffer3,buffer1[i]);
            char* b2 = strchr(buffer2,buffer1[i]);
            if(b1 != NULL && b2!=NULL)
                printf("buffer1[i] = %c\tb1=%c\tb2=%c\n",buffer1[i],*b1,*b2);
            if((b1 != NULL ) && (b2 != NULL) ){
                if((buffer1[i] == *b1) && (buffer1[i] == *b2) ){
                    sum+=get_priority(buffer1[i]);
                    break;
                }
            }
        }
    }
    printf("Priority sum: %d\n",sum);
    return 0;
}


int get_size(char* array,int size){
    int valid_size =0;
    for(int i =0; i<size;i++){
        if((array[i] >= 'A' && array[i] <='Z') || (array[i] >= 'a' && array[i] <='z')){
            valid_size++;
        }else{
            break;
        }
    }
    return valid_size;
}

int get_priority(char c){
    int result = 0;
    if(c >= 'a' && c <= 'z'){
        result = c-('a'-1);
    }else if(c >= 'A' && c <= 'Z'){
        result = c-38;
    }else{
        printf("Error: Invalid Character\n");
    }
    return result;
}


/*
Part 1
    int found = 0;
        fscanf(input,"%s\n",buffer);
        size = get_size(buffer,BUFFER_SIZE);
        printf("buffer: %s\t size:%d\n",buffer,size);
        sack2=size;
        sack1=size/2;
        printf("sack1=%d\tsack2=%d\n",sack1,sack2);
        for(int i = 0; i<sack1;i++){
            for(int j = sack1;j<sack2;j++){
                if(buffer[i] == buffer[j]){
                    printf("Comparing %c and %c\tpriority:%d\n",buffer[i],buffer[j],get_priority(buffer[i]));
                    sum+=get_priority(buffer[i]);
                    found = 1;
                    break;
                }
            }
            if(found)
                break;
        }
*/