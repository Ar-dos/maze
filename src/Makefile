.PHONY: build test
CC= g++ -std=c++17 -Wall -Werror -Wextra 
LFLAGS = -lgtest --coverage
OS = $(shell uname -s)
OPEN = open
ifeq ($(OS), Linux)
	LFLAGS += -lgtest -lpthread -lrt -lsubunit
	OPEN = xdg-open
endif

all: install

rebuild: clean uninstall all

install: build
	mkdir $(HOME)/Desktop/Maze 
	mkdir $(HOME)/Desktop/Maze/objects
	cp -rf ./build/Viewer.app $(HOME)/Desktop/Maze
	cp objects/* $(HOME)/Desktop/Maze/objects

build: 
	mkdir -p build
	cp -r view/* build/
ifeq ($(OS), Linux)
		cd build; qmake6
else
		cd build; qmake
endif
		make all -C ./build

uninstall:
	rm -rf $(HOME)/Desktop/Maze
	rm -rf /Users/Shared/settings.conf

clean:
	$(RM)  *.o *.a *.out *.gcno *.gcda *.info test
	$(RM) -rf build report
	$(RM) apllication/.clang-format apllication/maze_src/.clang-format apllication/cave/.clang

dvi:
	# brew install doxygen
	doxygen conf.conf
	open doc/html/index.html

dist:
	tar --totals -czf Maze.tar ./*

gcov_report: test
	lcov -c -d . -t test -o test.info
	genhtml -o report test.info
	open report/index.html

test:

	$(CC) test.cc model/maze/maze.cc model/maze/maze_cell.cc model/cave/cave.cc model/parser.cc -o test $(LFLAGS)
	./test --enable-coverage

linter:
	clang-format -n test.cc
	cp .clang-format controller/.clang-format
	clang-format -n controller/*.cc controller/*.h
	rm -rf controller/.clang-format
	cp .clang-format view/.clang-format
	clang-format -n view/*.cc view/*.h
	rm -rf view/.clang-format
	cp .clang-format model/.clang-format
	clang-format -n model/*.cc model/*.h
	rm -rf model/.clang-format
	cp .clang-format model/maze/.clang-format
	clang-format -n model/maze/*.cc model/maze/*.h
	rm -rf model/maze/.clang-format
	cp .clang-format model/cave/.clang-format
	clang-format -n model/cave/*.cc model/cave/*.h
	rm -rf model/cave/.clang-format

leaks: test
	CK_FORK=no leaks --atExit -- ./test

valgrind: test
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./test
