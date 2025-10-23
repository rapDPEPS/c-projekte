#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct City{
    int population;
    char name[64];
} City;

typedef struct ListElem {
    struct ListElem* next;

    City city;
} ListElem;

void printCity(const City* city);

int main(void) {
    // printf("%zu\n", sizeof(City));
    // City* city = malloc(sizeof(City)*3);
    // printf("%zu\n", sizeof(city));
    // printf("%zu\n", sizeof(*city));
    // city->population = 1000000000;
    // strcpy(city->name, "Koenigswinter");

    // city[1].population = 2000000000;
    // strcpy(city[1].name, "Hennef");

    // (city+2)->population = 1337;
    // strcpy((city+2)->name, "Bonn");

    // printCity(city);
    // printCity(&city[1]);
    // printCity(city+2);
    // free(city);
    
    return 0;
}

void printCity(const City* city) {
    printf("Population: %d\nName: %s\n", city->population, city->name);
}