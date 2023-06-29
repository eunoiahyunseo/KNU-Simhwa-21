// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     char *name = malloc(sizeof(char) * 100);
//     scanf("%s", name);
//     FILE *fp = fopen(name, "r");

//     while (feof(fp) == 0)
//     {
//         char str[100];
//         fgets(str, 100, fp);
//         printf("%s", str);
//     }
//     fclose(fp);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    typedef struct Student_
    {
        int number;
        char gender;
        double height;
        double weight;
    } Student;

    int value;
    scanf("%d", &value);

    Student studentArray[value];
    for (int i = 0; i < value; i++)
    {
        scanf("%d %c %lf %lf", &studentArray[i].number, &studentArray[i].gender, &studentArray[i].height, &studentArray[i].weight);
    }
    double menWeight = 0;
    double menHeight = 0;
    int menCount = 0;
    double womanWeight = 0;
    double womanHeight = 0;
    int womanCount = 0;

    for (int i = 0; i < value; i++)
    {
        if (studentArray[i].gender == 'M')
        {
            menWeight += studentArray[i].weight;
            menHeight += studentArray[i].height;
            menCount++;
        }
        else
        {
            womanWeight += studentArray[i].weight;
            womanHeight += studentArray[i].height;
            womanCount++;
        }
    }

    printf("M : %d %.1lf %.1lf\n", menCount, menHeight / menCount, menWeight / menCount);
    printf("W : %d %.1lf %.1lf\n", womanCount, womanHeight / womanCount, womanWeight / womanCount);
    return 0;
}