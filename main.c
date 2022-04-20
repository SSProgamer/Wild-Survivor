#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int gameover=0, day=1, win=0, screen_main=1, screen_ed=0;
int hp=20, energy=10;
int campfire=0, food=0, water=0;

void eat_drink(){
    system("cls");
    printf("HP : ");
    for(int i=1;i<=20;i++){
        if(i<=hp){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf(" Energy : ");
    for(int i=1;i<=10;i++){
        if(i<=energy){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf("\nFood : %d\n", food);
    printf("Water : %d\n", water);
    printf("\n\n\n\n\n\n1 : Eat food\n");
    printf("2 : Drink water\n");
    printf("3 : Close bag\n");
}

void screen(){
    system("cls");
    printf("Day %d\t", day);
    printf("HP : ");
    for(int i=1;i<=20;i++){
        if(i<=hp){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf("\n\tEnergy : ");
    for(int i=1;i<=10;i++){
        if(i<=energy){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf(" Campfire : ");
    for(int i=1;i<=10;i++){
        if(i<=campfire){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf("\n\n\n\n\n\n1 : Go find someting\n");
    printf("2 : Check bag\n");
    printf("3 : Sleep\n");
    printf("Press x to harakiri.\n");
}

void check_log(){
    hp=hp-(10-campfire);
    campfire=0;
}

void logic(){
    if(hp<=0){
        gameover=1;
    }
    if(hp>20){
        hp=20;
    }
    if(energy>10){
        energy=10;
    }
    else if(energy<0){
        energy=0;
    }
    if(day>=29){
        gameover=1;
        win=1;
    }
}

void input(){
    if(screen_main){
        switch(getch()){
        case '1':
            energy--;
            campfire++;
            screen();
            break;
        case '2':
            screen_main=0;
            screen_ed=1;
            eat_drink();
            break;
        case '3':
            day++;
            energy=10;
            check_log();
            screen();
            break;
        case 'x':
            gameover=1;
            break;
        }
    }
    else if(screen_ed){
        switch(getch()){
        case '1':
            hp++;
            eat_drink();
            break;
        case '2':
            energy++;
            eat_drink();
            break;
        case '3':
            screen_main=1;
            screen_ed=0;
            screen();
            break;
        }
    }
}

int main(){
    while (1)
    {
        printf("##     ## ## ##      ######      ####### ##    ## ######  ##    ## ## ##    ##  ######  ######\n");
        printf("##     ## ## ##      ##   ##     ##      ##    ## ##   ## ##    ## ## ##    ## ##    ## ##   ##\n");
        printf("##  #  ## ## ##      ##   ##     ####### ##    ## ######  ##    ## ## ##    ## ##    ## ######\n");
        printf("## ### ## ## ##      ##   ##          ## ##    ## ##   ##  ##  ##  ##  ##  ##  ##    ## ##   ##\n");
        printf(" ### ###  ## ####### ######      #######  ######  ##   ##   ####   ##   ####    ######  ##   ##\n");
        printf("\n\t\t\t\t\tPress x to play.\n");
        if(getch()=='x'){
            break;
        }
        else{
            system("cls");
        }
    }
    screen();
    while (!gameover)
    {
        input();
        logic();
    }
    system("cls");
    while (1)
    {
        if(win){
            printf("=============================================================================\n");
            printf("        ####### ##    ## ######  ##    ## ## ##    ## ####### ######\n");
            printf("        ##      ##    ## ##   ## ##    ## ## ##    ## ##      ##   ##\n");
            printf("        ####### ##    ## ######  ##    ## ## ##    ## #####   ##   ##\n");
            printf("             ## ##    ## ##   ##  ##  ##  ##  ##  ##  ##      ##   ##\n");
            printf("        #######  ######  ##   ##   ####   ##   ####   ####### ######\n");
            printf("=============================================================================\n");
        }
        else{
            printf("=============================================================================\n");
            printf("          ##    ##  ######  ##    ##     ######  ## ####### ######\n");
            printf("           ##  ##  ##    ## ##    ##     ##   ## ## ##      ##   ##\n");
            printf("            ####   ##    ## ##    ##     ##   ## ## #####   ##   ##\n");
            printf("             ##    ##    ## ##    ##     ##   ## ## ##      ##   ##\n");
            printf("             ##     ######   ######      ######  ## ####### ######\n");
            printf("=============================================================================\n");
        }
        printf("Press x to quit.\n");
        if(getch()=='x'){
            break;
        }
        else{
            system("cls");
        }
    }
    return 0;
}
