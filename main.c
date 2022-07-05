#include <stdio.h>
#include <string.h>

const int x = 32;

struct Person // Struct for a person
{
    char name[255];
    char title[255];
    char favFood[255];
    char favColour[255];
    int hasBeard;

    int percent;
    float weight;
};

char *toLowerCase(char *a)
{
    for (int i = 0; a[i] != '\0'; i++)
        a[i] = a[i] | x;

    return a;
}

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

    char yn = 'N';
    printf("\nDoes the person have a beard?: (Y / N) ");
    fflush(stdin);
    scanf("%c", &yn);

    if (strcmp(toLowerCase(&yn), "y"))
    {
        person.hasBeard = 1;
    }
    else
    {
        person.hasBeard = 0;
    }

    if (strcmp(toLowerCase(person.title), "sheikh") == 0 || strcmp(toLowerCase(person.title), "imam") == 0 || strcmp(toLowerCase(person.title), "ustaadh") == 0)
    {
        person.percent += 100;
    }
    if (strcmp(toLowerCase(person.favFood), "sweets") == 0)
    {
        person.percent += 25;
    }
    if (strcmp(toLowerCase(person.favColour), "red") == 0)
    {
        person.percent += 25;
    }
    if (person.weight >= 60)
    {
        person.percent += 25;
    }
    if (person.hasBeard == 1)
    {
        person.percent += 25;
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
