#include "search_student.h"
#include "utility.h"

int search_student(const char *name)
{
    student_t student;
    FILE *f;

    f = fopen("students.bin","rb");
    if(f == NULL)
    {
        return -2;
    }

    while (fread(&student, sizeof(student_t), 1, f)==1)
    {
        if(strcmp(student.name, name) == 0)
        {
            printf("\nSTUDENT DETAILS for %s:\n", name);
            printf("Name = %s\nstudent ID = %s\nAge = %d\nMarks = %dn\n",student.name,student.stuID,student.age,student.marks);
            fclose(f);
            return 0;
       
        }
    }
    fclose(f);
    return -1;
}