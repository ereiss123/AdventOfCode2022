#include <stdio.h>

int main(void){
    FILE* input;
    input = fopen("day4.txt","r");
    //input = fopen("example.txt","r");
    int elf1_num1,elf1_num2,elf2_num1,elf2_num2,count=0;

    while(!feof(input)){
        fscanf(input,"%d-%d,%d-%d\n",&elf1_num1,&elf1_num2,&elf2_num1,&elf2_num2);
        if((elf1_num1 >= elf2_num1 && elf1_num1 <= elf2_num2) || (elf1_num2 >= elf2_num1 && elf1_num2 <= elf2_num2)){
            count++;
        }
        else if((elf2_num1 >= elf1_num1 && elf2_num1 <= elf1_num2) || (elf2_num2 >= elf1_num1 && elf2_num2 <= elf1_num2)){
            count++;
        }
    }
    printf("Count: %d\n",count);
    fclose(input);
    return 0;
}

/*
Part 1
int main(void){
    FILE* input;
    //input = fopen("day4.txt","r");
    input = fopen("example.txt","r");
    int elf1_num1,elf1_num2,elf2_num1,elf2_num2,count=0;

    while(!feof(input)){
        fscanf(input,"%d-%d,%d-%d\n",&elf1_num1,&elf1_num2,&elf2_num1,&elf2_num2);
        if(elf1_num1 >= elf2_num1 && elf1_num1 <= elf2_num2 && elf1_num2 >= elf2_num1 && elf1_num2 <= elf2_num2 ){
            count++;
        }
        else if(elf2_num1 >= elf1_num1 && elf2_num1 <= elf1_num2 && elf2_num2 >= elf1_num1 && elf2_num2 <= elf1_num2 ){
            count++;
        }
    }
    printf("Count: %d\n",count);
    fclose(input);
    return 0;
}

*/