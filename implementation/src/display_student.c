#include <stdio.h>
#include <stdlib.h>

#include "display_student.h"

int display_student(void)
{
    student_t student;
    FILE *fptr;
    int count = 0;
    if((fptr = fopen("students.bin","rb"))==NULL)
    {
        return -2;
    }
    printf("\n### STUDENT DETAILS ###\n");
    while (fread(&student,sizeof(student), 1, fptr) == 1)
    {
        printf("Name = %s\nstudent ID = %s\nAge = %d\nMarks = %dn\n",student.name,student.stuID,student.age,student.marks);
        count++;
    }
    printf("### STUDENT DETAILS ###\n\n");
    fclose(fptr);
    return count;
}