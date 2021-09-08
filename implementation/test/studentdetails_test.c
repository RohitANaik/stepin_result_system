#include "unity.h"
#include "studentdetails.h"

void setUp()
{

}

void tearDown()
{

}

void test_add_student(void)
{
  student_t new_student = {"abc","01feqwert",22,99};
  TEST_ASSERT_EQUAL(1, add_student(&new_student));
}


void test_delete_student(void)
{
  student_t new_student = {"abcd","01feqwerqt",223,939};
  TEST_ASSERT_EQUAL(1, add_student(&new_student));
  TEST_ASSERT_EQUAL(2, delete_student(new_student.name));
}

void test_modify_student(void)
{
  student_t new_student = {"Rohit","01feqwert",22,99};
  student_t new_student1 = {"RohitA","051feqwert",24,96};
  TEST_ASSERT_EQUAL(1, add_student(&new_student));
  TEST_ASSERT_EQUAL(3, modify_student(new_student.name,&new_student1));
  TEST_ASSERT_EQUAL(2, delete_student(new_student.name));
}
void test_search_student(void)
{
  student_t new_student = {"Rohit","01feqwert",22,99};
  TEST_ASSERT_EQUAL(1, add_student(&new_student));
  TEST_ASSERT_EQUAL(4, search_student(new_student.name));
  TEST_ASSERT_EQUAL(2, delete_student(new_student.name));
}

void test_display_student(void)
{
  TEST_ASSERT_EQUAL(5, display_student()>0);
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_add_student);
  RUN_TEST(test_delete_student);
  RUN_TEST(test_modify_student);
  RUN_TEST(test_search_student);
  RUN_TEST(test_display_student);

  return UNITY_END();
}
