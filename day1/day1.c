#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define DEBUG
#define BUFFER_SIZE 1024
#define INIT_SIZE 100

int main(void){
    FILE* input;
    char buffer[BUFFER_SIZE];
    int* sums;
    sums = calloc(INIT_SIZE,sizeof(int));

    #ifdef DEBUG
    printf("OPENING FILE...\n");
    #endif
    input = fopen("day1.txt","r");


    int i = 0;
    int current_size = INIT_SIZE;
    int sum = 0;
    #ifdef DEBUG
            printf("READING FILE...\n");
            #endif
    while(!feof(input)){
        if(i > current_size){
            #ifdef DEBUG
            printf("REALLOCATING...\n");
            #endif
            sums = realloc(sums, current_size*sizeof(int)*2);
            current_size *= 2;
        }
        fgets(buffer,BUFFER_SIZE,input);
        if(buffer[0] != '\n'){
            int temp = atoi(buffer);
            sum+= temp;
            #ifdef DEBUG
            printf("sum = %d + %d\n",sum,temp);
            #endif
        }else{
            #ifdef DEBUG
            printf("\ni=%d sum=%d\n",i,sum);
            #endif
            sums[i] = sum;
            sum = 0;
            i++;
        }
    }
    int j,temp;
    int max1=0,max1_idx=0,max2=0,max2_idx=0,max3=0,max3_idx=0;
    for(j=0;j<i;j++){
        if(sums[j] > max1){
            max1=sums[j];
            max1_idx=j;
        }
        if(max1 > max2){
            temp = max2;
            max2 = max1;
            max1 = temp;
            temp = max2_idx;
            max2_idx = max1_idx;
            max1_idx = temp;
        }
        if(max2 > max3){
            temp = max3;
            max3 = max2;
            max2 = temp;
            temp = max3_idx;
            max3_idx = max2_idx;
            max2_idx = temp;
        }
    }
    printf("The elf with the most calories is elf %d carrying %d calories\nNext is elf %d carrying %d calories\nFinally elf %d carrying %d calories\nTotal:%d\n",max3_idx,max3,max2_idx,max2,max1_idx,max1,max1+max2+max3);
    fclose(input);
    return 0;
}

