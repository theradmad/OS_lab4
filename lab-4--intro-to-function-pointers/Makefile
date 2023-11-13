STUDENT_ID=XXXXXXX
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

TASK1_SRC := $(wildcard task1/*.c)
TASK2_SRC := task2/task2.c
EXE := task1/func-ptr task2/task2

all: $(EXE)

task1/func-ptr: $(TASK1_SRC)
	$(CC) $(CFLAGS) -g $^ -o $@

task2/task2: $(TASK2_SRC)
	$(CC) $(CFLAGS) -g $^ -o $@

test: task1/func-ptr
	./$< task1/test-data/test1.csv > task1/test-data/test1.log
	diff task1/test-data/test1.log task1/test-data/test1-exp.log

clean:
	rm -f $(EXE)

zip:
	make clean
	mkdir $(STUDENT_ID)-fp-lab
	cp -r Makefile task1 task2 $(STUDENT_ID)-fp-lab
	zip -r $(STUDENT_ID)-fp-lab.zip $(STUDENT_ID)-fp-lab
	rm -rf $(STUDENT_ID)-fp-lab
