#include <stdio.h>
#include <string.h>

#include "readFunctions.h"

typedef struct person
{
    int id;
    char firstName[64];
    char lastName [64];
    int age;
    float height;
} person;

person people[1024];
const person emptyPerson;
int peopleCount = 0;

void addPerson();
void removePerson();
void listPeople();
int comparePeople(const person* a, const person* b, int sortOption);

int main(void) {
    while (1) {
        printf("1. Add Person\n2. Remove Person\n3. List People\n4. Exit\n> ");
        int option;
        readNumber(&option);
        switch (option)
        {
        case 1:
            addPerson();
            break;
        case 2:
            removePerson();
            break;
        case 3:
            listPeople();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Option.\n");
            break;
        }
    }
}

void addPerson() {
    if (peopleCount >= 1024) {
        printf("Error: your list is full!\n");
        return;
    }

    struct person newPerson;

    printf("What's this persons first name?\n>");
    char firstName[64];
    scanf("%s", firstName);

    printf("What's this persons last name?\n>");
    char lastName[64];
    scanf("%s", lastName);

    printf("What's this persons age?\n>");
    int age;
    readNumber(&age);

    printf("What's this persons height?\n>");
    float height;
    readFloat(&height);

    newPerson.id = peopleCount;
    strcpy(newPerson.firstName, firstName);
    strcpy(newPerson.lastName, lastName);
    newPerson.age = age;
    newPerson.height = height;

    people[peopleCount] = newPerson;
    peopleCount++;
    
}

void removePerson() {
    int id;
    printf("What this users ID?\n");
    scanf("%d", &id);
    people[id] = emptyPerson;
    for (size_t i = id; i < peopleCount; i++)
    {
        people[i] = people[i+1];
        people[i].id -= 1; 
    }
    peopleCount--;
}

void listPeople() {
    person sorted[1024];
    printf("How would you like the people to be sorted?\n1. By ID (ascending)\n2. By Age (ascending)\n3. By Height (ascending)\n4. By First Name\n>");
    int sortOption;
    readNumber(&sortOption);

    if (sortOption < 1 || sortOption > 4) {
        printf("Invalid Option. Defaulting to ID");
        sortOption = 1;   
    }

    for (size_t i = 0; i < peopleCount; i++)
    {
        sorted[i] = people[i];   
    }

    for (size_t i = 0; i < peopleCount; i++)
    {
        for (size_t j = 0; j < peopleCount; j++)
        {
            if (comparePeople(&sorted[i], &sorted[j], sortOption) > 0) {
                person temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
        
    }
    
    

    printf("======== %d PEOPLE ========\n", peopleCount);
    for (size_t i = 0; i < peopleCount; i++)
    {
        person person = sorted[i];
        printf("ID: %d\n", person.id);
        printf("Name: %s %s\n", person.firstName, person.lastName);
        printf("Age: %d\n", person.age);
        printf("Height: %.2fm\n", person.height);
        printf("-----------------\n");
    }
    
}

int comparePeople(const person* firstPerson, const person* secondPerson, int sortOption) {
    switch (sortOption)
    {
    case 1:
        return firstPerson->id < secondPerson->id ? 1 : 0;
    case 2:
        return firstPerson->age < secondPerson->age ? 1 : 0;
    case 3:
        return firstPerson->height < secondPerson->height ? 1 : 0;
    case 4:
        return strcmp(firstPerson->firstName, secondPerson->firstName) < 0 ? 1 : 0;
    }
}
