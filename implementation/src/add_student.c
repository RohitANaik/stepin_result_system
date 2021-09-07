#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>

#include "add_student.h"
#include "utility.h"

int add_student(student_t *student)
{
    FILE *fptr;
    if ((fptr = fopen("students.bin","ab+"))==NULL)
    {
        return -1;
    }
    fwrite(student, sizeof(student_t), 1, fptr);

    __fpurge(stdin);
    fclose(fptr);

    return 0;
}