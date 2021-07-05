#include <stdio.h>

int main() {
  //Variables
  int num = 0, students = 0, classes = 0, x, y, z;
  float grades[10], average = 0;
  char name[50];

  //opening txt file
  FILE *fp;
  fp = fopen("averageGrades.txt", "a");
  if (fp == NULL) { //check if file opened
  printf ("Erro ao abrir arquivo!\n");
    return 1; //finish the if there is an error
  }

  printf("\n#####GRADES#####\n");
  //how many classes
  printf("\nHow many classes? \n");
  scanf("%i", &classes);
  for(x = 0; x< classes; x++){
    printf("\n\t\t\t*** CLASS %x ***\n", x + 1);
    fprintf (fp, "\n\t\t\t\tCLASS %d", x+1); //writing in the file
    //how many students
    printf("\nHow many students? \n");
    scanf("%i", &students);
    fprintf (fp, "\n%d Students", students);
    //loop
    for(int y = 0; y < students; y++){
      //name
      printf("\nName os student %i: ", y+1);
      scanf("%s", name);
      fprintf (fp, "\n\nStudent: %s", name);
      //how many grades does this student have
      printf("How many grades? ");
      scanf("%i", &num);
      //Using a loop to take student grades and add up
      for(z = 0; z < num; z++){
        printf("Grade %i: ", z + 1);
        scanf("%f", &grades[z]);
        fprintf (fp, "\nGrade %i: %1.f", z + 1, grades[z]);
        average = average + grades[z];
      }
    //media
    average  = average / num;
    //result
    printf("\n%s - Media: %.1f\n", name, average);
    fprintf (fp, "\nMedia: %.1f", average);
    z = 0;
    average = 0;
    }
  }
  return 0;
}
