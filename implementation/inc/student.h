/**
 * @file student.h
 * @author Rohit A Naik (you@domain.com)
 * @brief collecting student details
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __STUDENT_H_
#define __STUDENT_H_

enum max_length{
    max_name_length = 30,
    max_stuID_length = 10,
    //max_age_length = 10,
    //max_marks_length = 10
};

typedef struct student_t{
    char name[max_name_length];
    char stuID[max_stuID_length];
    int age;
    int marks;

}student_t;

#endif