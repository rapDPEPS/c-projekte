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
int comparePeople(const person* a, const person* b, int sortOption);
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
    if (peopleCount == 0) {
        printf("No people in the list yet.\n");
        return;
    }

    printf("How would you like the list to be sorted?\n");
    printf("1. ID (ascending)\n");
    printf("2. First name (A-Z)\n");
    printf("3. Last name (A-Z)\n");
    printf("4. Age (youngest first)\n");
    printf("5. Height (shortest first)\n> ");

    int sortOption;
    readNumber(&sortOption);

    if (sortOption < 1 || sortOption > 5) {
        printf("Invalid option. Defaulting to ID order.\n");
        sortOption = 1;
    }

    person sorted[1024];
    for (size_t i = 0; i < (size_t)peopleCount; i++) {
        sorted[i] = people[i];
    }

    for (size_t i = 0; i < (size_t)peopleCount; i++) {
        for (size_t j = i + 1; j < (size_t)peopleCount; j++) {
            if (comparePeople(&sorted[i], &sorted[j], sortOption) > 0) {
                person temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    printf("======== %d PEOPLE ========\n", peopleCount);

    for (size_t i = 0; i < (size_t)peopleCount; i++)
    {
        person person = sorted[i];
        printf("ID: %d\n", person.id);
        printf("Name: %s %s\n", person.firstName, person.lastName);
        printf("Age: %d\n", person.age);
        printf("Height: %.2fm\n", person.height);
        printf("-----------------\n");
    }

}

int comparePeople(const person* a, const person* b, int sortOption) {
    switch (sortOption)
    {
    case 2: {
        int cmp = strcmp(a->firstName, b->firstName);
        return cmp != 0 ? cmp : (a->id - b->id);
    }
    case 3: {
        int cmp = strcmp(a->lastName, b->lastName);
        return cmp != 0 ? cmp : (a->id - b->id);
    }
    case 4:
        if (a->age == b->age) {
            return a->id - b->id;
        }
        return a->age - b->age;
    case 5:
        if (a->height == b->height) {
            return a->id - b->id;
        }
        return (a->height > b->height) - (a->height < b->height);
    case 1:
    default:
        return a->id - b->id;
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