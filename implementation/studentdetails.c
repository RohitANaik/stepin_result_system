#include "studentdetails.h"

typedef enum options{
    NONE,
    ADD_STUDENT,
    MODIFY_STUDENT,
    DELETE_STUDENT,
    DISPLAY_STUDENT,
    SEARCH_STUDENT,
    EXIT
}option_t;

int main()
{
    int choice = NONE;

    printf("\n\t****Welcome to student result application****\n");
    for(;;){

        printf("\nSelect your choice: \n");
        printf("1.add student \n2.modify student\n3.delete student \n4.display all student \n5.Search for a student\n6.Exit\n");

        printf("enter your choice:");
        __fpurge(stdin);
        scanf("%d", &choice);

        switch (choice){
            case ADD_STUDENT: {
                student_t *new_student = (student_t *)calloc(1, sizeof(student_t));

                get_student_details(new_student);
                switch(add_student(new_student)){
                    case 0:
                    printf("\n\t*** Adding student successful***");
                    break;
                    default:
                    printf("\n\t***Error in adding student***");
                }
                free(new_student);
                break;
            }
            case DELETE_STUDENT: {
                int student_count = display_student();
                if (0 < student_count) {
                     char name[max_name_length] = "";

                    printf("enter student's name from the above list:");
                    get_data(name);

                    switch (delete_student(name))
                    {
                    case -1:
                        printf("\n\t***No matching student found***\n");
                        break;
                    
                    case -2:
                        printf("\n\t***No student found***\n");
                        break;
                    
                    case 0:
                        printf("\n\t***student record deleted successfully***");
                        break;
                    
                    default:
                        printf("\n\t***Error in delete student***");
                    }
                }else if (student_count == 0) {
                    printf("\n\t***No student found***\n");
                }
                break;
            }
            case MODIFY_STUDENT: {
                int student_count = display_student();
                if (0 < student_count) {
                     char name[max_name_length] = "";
                     student_t *new_student = (student_t *)calloc(1, sizeof(student_t));

                    printf("enter student's name from the above list:");
                    get_data(name);
                    get_student_details(new_student);

                    switch (modify_student(name,new_student))
                    {
                    case -1:
                        printf("\n\t***No matching student found***\n");
                        break;
                    
                    case -2:
                        printf("\n\t***No student found***\n");
                        break;
                    
                    case 0:
                        printf("\n\t***student record modifed successfully***");
                        break;
                    
                    default:
                        printf("\n\t***Error in modify student***");
                    }
                    free(new_student);
                }else if (student_count == 0) {
                    printf("\n\t***No student found***\n");
                }
                break;
            }
            case DISPLAY_STUDENT:
            switch (display_student()){
                case -2:
                printf("\n\t***No Student found***\n\n");
                break;
                case 0:
                printf("\n\t***No student found***\n\n");
                break;
                default:
                printf("\n\t***display students record successful***\n");
            }
            break;

            case SEARCH_STUDENT: {
                int student_count = display_student();
                if (0 < student_count) {
                     char name[max_name_length] = "";
                    
                    printf("enter student's name to search:");
                    __fpurge(stdin);
                    get_data(name);

                    switch (search_student(name))
                    {
                    case -1:
                        printf("\n\t***No matching student found***\n");
                        break;
                    
                    case -2:
                        printf("\n\t***No student found***\n");
                        break;
                    
                    case 0:
                        printf("\n\t***search successfully***");
                        break;
                    
                    default:
                        printf("\n\t***Error in search student***");
                    }
                }else if (student_count == 0) {
                    printf("\n\t***No student found***\n");
                }
                break;
            }
            case EXIT:
                printf("\n\t****EXITING APPLICATION****\n");
                exit(0);
                break;

            default:
                printf("\n\t***selected option not available***");
        }
    }
}
