#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define HEIGHT 20
#define WIDTH 40

int snakeTailX[100], snakeTailY[100];

int gameover, key, score;

int x, y, fruitx, fruity;

void setup() {
    
    gameover = 0;

    x = WIDTH / 2;
    y = HEIGHT / 2;
    
    fruitx = rand() % WIDTH;
    fruity = rand() % HEIGHT;
    while (fruitx == 0)
        fruitx = rand() % WIDTH;

    while (fruity == 0)
        fruity = rand() % HEIGHT;

    score = 0;
}

void input() {
    if (kbhit()) {
        switch (tolower(getch())) {
        case 'a':
            if(key!=2)
            key = 1;
            break;
        case 'd':
            if(key!=1)
            key = 2;
            break;
        case 'w':
            if(key!=4)
            key = 3;
            break;
        case 's':
            if(key!=3)
            key = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void printGame() {

}

int main(void) {
    setup();

    while (!gameover) {
        input();
        printf("%d", key);
        Sleep(33);
    }
}