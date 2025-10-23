#include <stdio.h>
#include <string.h>

typedef struct person
{
    int id;
    char firstName[64];
    char lastName [64];
    int age;
    float height;
} person;

person people[1024];
int peopleCount = 0;

void addPerson();
void removePerson();
void listPeople();
void readNumber(int* dest);
void readFloat(float* dest);

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

    people[peopleCount++] = newPerson;
    
}

void removePerson() {
    int id;
    printf("What this users ID?\n");
    scanf("%d", &id);
    person person;
    people[id] = person;
    for (size_t i = id; i < peopleCount; i++)
    {
        people[i] = people[i+1];
        people[i].id -= 1; 
    }
    peopleCount--;
}

void listPeople() {
    printf("======== %d PEOPLE ========\n", peopleCount);

    for (size_t i = 0; i < peopleCount; i++)
    {
        person person = people[i];
        printf("ID: %d\n", person.id);
        printf("Name: %s %s\n", person.firstName, person.lastName);
        printf("Age: %d\n", person.age);
        printf("Height: %.2fm\n", person.height);
        printf("-----------------\n");
    }
    
}

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