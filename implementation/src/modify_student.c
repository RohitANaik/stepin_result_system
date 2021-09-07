#include "modify_student.h"
#include "utility.h"

int modify_student(char *name, student_t *update_student)
{
    int result = 0;
    FILE *fptr;
    int flag = 0;
    student_t old_student;

    fptr = fopen("students.bin","rb+");

    if(fptr == NULL)
    {
        return -2;
    }
    else{
        while(fread(&old_student, sizeof(student_t), 1, fptr)==1)
        {
            if (strcmp(name, old_student.name)==0)
            {
                fseek(fptr, -sizeof(student_t), SEEK_CUR);
                fwrite(update_student, sizeof(student_t), 1, fptr);
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            result = 0;
        }
        else{
            result = -1;
        }
        fclose(fptr);
    }
    return result;
}