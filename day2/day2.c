#include <stdio.h>
#include <stdlib.h>
//#define X Rock
//#define Y Paper
//#define Z Scissors
/*
Part 2 
X: lose
Y: draw
Z: win
*/
#define W 6
#define D 3
#define L 0
#define Rock 1
#define Paper 2
#define Scissors 3

int calcScore(char move1, char move2);

int main(void){
    FILE* input;
    int score = 0;
    //open file
    input = fopen("day2.txt","r");

    //read file
    while(!feof(input)){
        char opp_move, my_move;
        fscanf(input,"%c %c\n",&opp_move,&my_move);
        printf("%c %c\n",opp_move,my_move);
        switch(opp_move){
            case 'A': 
                switch(my_move){
                    case 'X': score +=Scissors+L; break; //Rock on scissors
                    case 'Y': score +=Rock+D; break; //Rock on rock
                    case 'Z': score +=Paper+W; break; //Rock on paper
                }
                break;
            case 'B':
                switch(my_move){
                    case 'X': score +=Rock+L; break; //Paper on rock
                    case 'Y': score +=Paper+D; break; //Paper on paper
                    case 'Z': score += Scissors+W; break; //Paper on scissors
                } 
                break;
            case 'C': 
                switch(my_move){
                    case 'X': score +=Paper+L; break; //Scissors on paper
                    case 'Y': score +=D+Scissors; break; //Scissors on scissors
                    case 'Z': score +=W+Rock; break; //Scissors on rock
                }
                break;
        }
    }
    printf("Final Score: %d\n",score);

}