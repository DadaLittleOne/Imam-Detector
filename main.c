#include <stdio.h>
#include <string.h>

struct Person // Struct for a person
{
    char name[255];
    char title[255];
    char favFood[255];
    char favColour[255];

    int percent;
    float weight;
};

int main() // Main Function
{
    printf("************************\nWelcome to Imam Detector\n************************\n");

    struct Person person;

    printf("\nPlease enter name of person: ");
    scanf("%s", &person.name);

    printf("\nPlease enter the title of person: ");
    scanf("%s", &person.title);

    printf("\nPlease enter the favourite food of person: ");
    scanf("%s", &person.favFood);

    printf("\nPlease enter the favourite colour of the person: ");
    scanf("%s", &person.favColour);

    printf("\nPlease enter weight of person: ");
    scanf("%f", &person.weight);

    if (strcmp(person.title, "sheikh") == 0 || strcmp(person.title, "imam") == 0 || strcmp(person.title, "ustaadh") == 0)
    {
        person.percent += 100;
    }
    if (strcmp(person.favFood, "sweets") == 0)
    {
        person.percent += 33;
    }
    if (strcmp(person.favColour, "red") == 0)
    {
        person.percent += 33;
    }
    if (person.weight >= 60)
    {
        person.percent += 34;
    }

    int drip = 0;
    if (person.percent > 100)
    {
        drip = person.percent - 100;
        person.percent -= 100;
    }
    printf("\n%s's probability of being an Imam is %i.", person.name, person.percent);
    if (drip > 0)
    {
        printf("\n%s also has a drip value of %i.", person.name, drip);
    }
    printf("\n\nPress any key to continue...");
    fflush(stdin);
    getchar();

    return 0;
}
