PROJ_NAME = studentdetails

BUILD =build

SRC = src/add_student.c\
src/delete_student.c\
src/display_student.c\
src/modify_student.c\
src/search_student.c\
src/utility.c\

TEST_SRC = ${SRC}\
test/studentdetails_test.c\
unity/unity.c\

TEST_OUTPUT = $(BUILD)/Test_$(PROJ_NAME).TEST_OUTPUT

INC = -Iinc\
-Iunity\

INCLUDE_LIBS = 

PROJECT_OUTPUT = $(BUILD)/$(PROJ_NAME).TEST_OUTPUT

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
   IN=
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
	  IN=-lm
   endif
endif

DOCUMENTATION_OUTPUT = documentation/html

$(PROJ_NAME):all

.PHONY: run clean test doc all

run: $(PROJ_NAME)
      ./$(PROJECT_OUTPUT).TEST_OUTPUT

all: $(SRC) $(BUILD)
      gcc studentdetails.c $(SRC) $(INC) -o $(PROJECT_OUTPUT).TEST_OUTPUT


doc:
      make -C ./documentation

test:$(BUILD)
      gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
      ./$(TEST_OUTPUT)
   
valgrind:
	valgrind $(call FixPath,$(BUILD)/$(PROJ_NAME).$(EXEC))

clean:
      rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT) students.bin

$(BUILD):
      mkdir build
