#include <stdio.h>
#include "readFunctions.h"

void readNumber(int* dest) {
    int ret = scanf("%d", dest);
    if (ret == 0) {
        char garbage[1024];
        scanf("%s", garbage);
        printf("garbage input discarded: %s\n", garbage);
    }
}

void readFloat(float* dest) {
    int ret = scanf("%f", dest);
    if (ret == 0) {
        char garbage[1024];
        scanf("%s", garbage);
        printf("garbage input discarded: %s\n", garbage);
    }
}