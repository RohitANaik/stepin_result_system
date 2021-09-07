#include "utility.h"
#include "student.h"

void get_data(char *name)
{
    int i = 0,j;
    char c, ch;
    __fpurge(stdin);
    do{
        c = getchar();
        if(c!='\n'){
            *(name + i) = c;
            putchar(c);
            i++;
        }
        if(c == 8){
            if (i > 0){
                i--;
            }
            for(j = 0; j< i; j++){
                ch = *(name + j);
                putchar(ch);
            }
        }
    }
    while(c!='\n');
    *(name + i) = '\0';
}

void get_student_details(student_t *student){
    printf("\nEnter name:");
    __fpurge(stdin);
    get_data(student->name);

    printf("\nEnter studentID:");
    __fpurge(stdin);
    get_data(student->stuID);

    printf("\nEnter age:");
    __fpurge(stdin);
    get_data(student->age);

    printf("\nEnter name:");
    __fpurge(stdin);
    get_data(student->marks);
}