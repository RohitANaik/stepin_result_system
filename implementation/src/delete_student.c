#include "delete_student.h"
#include "utility.h"

int delete_student(const char *name)
{
    student_t student;
    FILE *f, *ft;
    int flag, result;

    f = fopen("students.bin","rb");
    if(f == NULL)
    {
        return -2;
    }
    else{
        ft = fopen("temp.bin","wb+");
        if(ft == NULL)
        {
            result == -3;
        }
        else{
            while(fread(&student, sizeof(student_t), 1, f)==1)
            {
                if(strcmp(student.name,name)!=0)
                    fwrite(&student, sizeof(student_t), 1, ft);
                 if(strcmp(student.name,name)==0)
                    flag = 1;
            }
            fclose(f);
            f = NULL;
            fclose(ft);

            if (flag != 1)
            {
                remove("temp.bin");
                result = -1;
            }
            else{
                remove("students.bin");
                rename("temp.bin","students.bin");
                result = 0;
            }

        }
    }
    if (NULL != f)
    fclose(f);

    return result;
}