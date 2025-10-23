#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void pickRandomOption(char* dest) {
    int randNum = rand() % 3;
    switch (randNum)
    {
    case 0:
        strcpy(dest, "Rock");
        break;
    case 1:
        strcpy(dest, "Paper");
        break;
    case 2: 
        strcpy(dest, "Scissor");
        break;
    }
}

void determineWin(const char* personChoice, const char* computerChoice, char* result) {
    if (strcmp(personChoice, computerChoice) == 0) {
        strcpy(result, "Tie");
        return;
    }

    if (strcmp(personChoice, "Rock") == 0) {
        strcpy(result, strcmp(computerChoice, "Scissor") == 0 ? "Won" : "Lost");
    } else if (strcmp(personChoice, "Paper") == 0) {
        strcpy(result, strcmp(computerChoice, "Rock") == 0 ? "Won" : "Lost");
    } else {
        strcpy(result, strcmp(computerChoice, "Paper") == 0 ? "Won" : "Lost");
    }
}

int main(void) {
    srand(time(NULL));

    printf("Welcome to Rock Paper Scissor.\n");

    int yourWins = 0;
    int computerWins = 0;

    while (1)
    {
        char choice[1024] = "";
        char computerChoice[8] = "";

        printf("Choose an option: ");
        scanf("%s", choice);
        pickRandomOption(computerChoice);


        printf("You picked %s\n", choice);
        printf("Computer picked %s\n", computerChoice);

        char result[5] = "";
        determineWin(choice, computerChoice, result);

        if (strcmp(result, "Won") == 0) {
            yourWins++;
            printf("You won! %d-%d\n", yourWins, computerWins);
        } else if (strcmp(result, "Lost") == 0) {
            computerWins++;
            printf("You lost! %d-%d\n", yourWins, computerWins);
        } else {
            printf("There was a tie.\n");
        }
    }
    
}