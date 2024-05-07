CXX = g++
version = -std=c++17
TESTS = ./TESTING/
SRC_MODEL_PATH = ./Model/
SRC_MODEL = $(wildcard $(SRC_MODEL_PATH)*.cpp)
SRC_CONTROLLER_PATH = ./Controller/
SRC_CONTROLLER = $(wildcard $(SRC_CONTROLLER_PATH)*.cpp)
SRC_TEST = $(wildcard $(TESTS)*.cpp)
TARGET = tests
REPORT = gcov_report
CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -g
SANITIZE = -fsanitize=address -g
UNAME := $(shell uname)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov 

ifeq ($(UNAME), Linux)
 TEST_FLAGS +=  -lgtest -pthread -lm
else
 TEST_FLAGS += -lgtest -lm
endif

all: uninstall clean $(TARGET) install dvi dist

$(TARGET) : $(SRC) $(SRC_TEST)
	$(CXX) $(version) $(CXXFLAGS) $(SRC_TEST) $(SRC_MODEL) $(SRC_CONTROLLER) $(TEST_FLAGS) -o $(TARGET)
	./$(TARGET)


install: clean
	rm -rf View/Build_3D_VIEWER
	mkdir View/Build_3D_VIEWER
	cd View/Build_3D_VIEWER && cmake ../
	cd View/Build_3D_VIEWER && make
	open View/Build_3D_VIEWER/3d_viewer.app/

uninstall:
	rm -rf View/Build_3D_VIEWER
	rm -rf View/CMakeFiles View/CmakeCache.txt View/Testing View/cmake_install.cmake View/3d_viewer_autogen open View/Build_3D_VIEWER/3d_viewer.app/

dist: install
	tar --totals -cvf 3d_viewer.tar View TESTING Model Controller


dvi:
	Doxygen Doxyfile
	open ./Documentation/html/index.html


$(REPORT) : $(SRC) $(SRC_TEST) build_file
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(SRC_TEST) $(SRC_MODEL) $(SRC_CONTROLLER) $(TEST_FLAGS) -o Build/$(REPORT)
	Build/./$(REPORT)
	lcov -o $(REPORT).info -c -d .
	lcov -r $(REPORT).info "/usr*" -o $(REPORT).info
	genhtml $(REPORT).info -o html_report
	open html_report/index.html

build_file:
	mkdir Build

style: 
	clang-format -i  ./TESTING/*h ./TESTING/*cpp  ./Model/*h ./Model/*cpp ./Controller/*h ./Controller/*cpp ./View/*h ./View/*cpp
clean : uninstall
	rm -rf Build_3D_VIEWER  $(TARGET) *.a  ./html_report/ gcov_report *.gcno *.gcda *.info *.out *.tar 
	rm -rf  *.html *.css test.info test.dSYM report
	rm -rf Documentation
	rm -rf $(SRC_MODEL_PATH)/*.out $(SRC_MODEL_PATH)/*.dSYM $(TESTS)/*.dSYM 
	rm -rf *.dSYM 
