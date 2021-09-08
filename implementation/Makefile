PROJ_NAME = studentdetails
TEST_PROJ_NAME = Test_$(PROJ_NAME)

BUILD_DIR = implementation

# All source code files
SRC =src/add_student.c\
src/delete_student.c\
src/modify_student.c src/search_student.c src/display_student.c\
src/utility.c

# All test source files
TEST_SRC = test/studentdetails_test.c\
unity/unity.c

# All include folders with header files
INC = -Iinc\
-Iunity

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
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

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all run test coverage cppcheck valgrind clean
all:$(BUILD_DIR)
	gcc main.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC)) $(IN)
run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
test: $(SRC) $(TEST_SRC)
	gcc $^ $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) $(IN)
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) 
	
coverage:${PROJECT_NAME}
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) $(IN)
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(SRC)
	
cppcheck: $(SRC)
	cppcheck --enable=all main.c $(SRC)
valgrind:
	valgrind $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	rmdir $(BUILD_DIR)
