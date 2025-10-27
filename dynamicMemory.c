#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "readFunctions.h"

typedef struct City{
    char name[64];
    int population;
} City;

typedef struct ListElem {
    struct ListElem* next;

    City city;
} ListElem;

void printCity(const City* city);
void createNewCity(City* newCity);
void appendList(const City* city, ListElem** listHead);
void printList(const ListElem* listHead);
void freeList();

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

    ListElem* listHead = NULL;

    while (1) {
        printf("1. Add City\n2. Print List\n3. Free List\n>");
        int option;
        readNumber(&option);
        switch (option)
        {
        case 1:
            City* newCity = malloc(sizeof(City));
            createNewCity(newCity);
            appendList(newCity, &listHead);
            break;
        case 2:
            printList(listHead);
            break;
        case 3:
            freeList(&listHead);
            break;
        
        default:
            printf("Invalid Option.");
            break;
        }
    }

}

void printCity(const City* city) {
    printf("Name: %s\nPopulation: %d\n", city->name, city->population);
}

void createNewCity(City* newCity) {
    printf("Whats the city called?\n");
    scanf("%s", newCity->name);

    printf("Whats the city's population?\n");
    readNumber(&newCity->population);
}

void appendList(const City* city, ListElem** listHead) {
    ListElem* newElem = malloc(sizeof(ListElem));
    newElem->city = *city;
    newElem->next = NULL;

    if (*listHead == NULL) {
        *listHead = newElem;
    } else {
        ListElem* current = *listHead;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newElem;
    }
}

void printList(const ListElem* listHead) {

    if (listHead == NULL) {
        printf("There are currently no cities.\n");
        return;
    }

    const ListElem* currentListElem = listHead;

    while (1) {    
        printf("---------------\n");
        printCity(&currentListElem->city);
        printf("---------------\n");

        if (currentListElem->next != NULL) {
            currentListElem = currentListElem->next;
        } else {
            break;
        }
    }
}

void freeList(ListElem** listHead) {
    ListElem* currentListElem = *listHead;
    //ListElem* nextListElem;

    while (currentListElem != NULL) {
        ListElem* nextListElem = currentListElem->next;
        free(currentListElem);
        currentListElem = nextListElem;
    }

    *listHead = NULL;
}