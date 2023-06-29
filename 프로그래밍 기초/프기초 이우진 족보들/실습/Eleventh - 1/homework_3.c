#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    typedef struct Club_
    {
        char clubName[100];
        char country[100];
    } Club;

    typedef struct Player_
    {
        char name[100];
        int age;
        Club club;
    } Player;

    int value;
    scanf("%d", &value);
    Player playerArray[value];

    for (int i = 0; i < value; i++)
    {
        scanf("%s %d %s %s", playerArray[i].name, &playerArray[i].age, playerArray[i].club.clubName, playerArray[i].club.country);
    }

    while (1)
    {
        char clubName[100] = {0};
        scanf("%s", clubName);
        if (strcmp(clubName, "exit") == 0)
        {
            break;
        }
        else
        {
            for (int i = 0; i < value; i++)
            {
                if (strcmp(playerArray[i].club.clubName, clubName) == 0)
                {
                    printf("%s %d\n", playerArray[i].name, playerArray[i].age);
                }
            }
        }
    }

    return 0;
}