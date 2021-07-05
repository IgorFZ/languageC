#include <stdio.h>

int main()
{
    //Variables
    int num = 0, students = 0, classes = 0, x, y, z;
    float grades[10], average = 0;
    char name[50], dot = 59;

    //opening txt file
    FILE *fp;
    fp = fopen("averageGrades.txt", "w");

    if (fp == NULL)   //check if file opened
    {
        printf ("Erro ao abrir arquivo!\n");
        return 1; //finish the if there is an error
    }

    //opening csv file
    FILE *csv;
    csv = fopen("averageGrades.csv", "w");

    if (csv == NULL)   //check if file opened
    {
        printf ("Erro ao abrir arquivo!\n");
        return 1; //finish the if there is an error
    }

    printf("\n#####GRADES#####\n");
    //how many classes
    printf("\nHow many classes? \n");
    scanf("%i", &classes);
    for(x = 0; x< classes; x++)
    {
        printf("\n\t\t\t*** CLASS %x ***\n", x + 1);
        fprintf (fp, "\n\t\t\t\tCLASS %d", x+1); //writing in the txt file
        fprintf (csv, "%d%c", x+1, dot); //writing in the csv file
        //how many students
        printf("\nHow many students? \n");
        scanf("%i", &students);
        fprintf (fp, "\n%d Students", students);
        fprintf (csv, "%d%c", students, dot);
        //loop
        for(int y = 0; y < students; y++)
        {
            //name
            printf("\nName os student %i: ", y+1);
            scanf("%s", name);
            fprintf (fp, "\n\nStudent: %s", name);
            fprintf (csv, "%s%c", &name, dot);
            //how many grades does this student have
            printf("How many grades? ");
            scanf("%i", &num);
            fprintf (csv, "%d%c", num, dot);
            //Using a loop to take student grades and add up
            for(z = 0; z < num; z++)
            {
                printf("Grade %i: ", z + 1);
                scanf("%f", &grades[z]);
                fprintf(fp, "\nGrade %i: %1.f", z + 1, grades[z]);
                fprintf(csv, "%.1f%c", grades[z], dot);
                average = average + grades[z];
            }
            //media
            average  = average / num;
            //result
            printf("\n%s - Average: %.1f\n", name, average);
            fprintf(fp, "\nAverage: %.1f", average);
            fprintf(csv, "%.1f", average);
            z = 0;
            average = 0;
        }
        fprintf(csv, "\n");
    }
    return 0;
}
