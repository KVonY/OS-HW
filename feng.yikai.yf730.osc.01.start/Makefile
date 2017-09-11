CC=gcc -Wall -ansi
BIN=bin
INC=include
LIB=lib
OBJ=obj
SRC=src


all: runall


############################################################################################
# Question 2

${OBJ}/stack_array.o: ${INC}/stack.h ${SRC}/stack_array.c
	${CC} -c -o ${OBJ}/stack_array.o ${SRC}/stack_array.c -D STACK_SIZE=12 -I ${INC}

${OBJ}/stack_test.o: ${INC}/stack.h ${SRC}/stack_test.c
	${CC} -c -o ${OBJ}/stack_test.o ${SRC}/stack_test.c -I ${INC}

${LIB}/libstack1.a: ${OBJ}/stack_array.o
	ar rcs ${LIB}/libstack1.a ${OBJ}/stack_array.o

${BIN}/stack_test1: ${OBJ}/stack_test.o ${LIB}/libstack1.a
	${CC} -o ${BIN}/stack_test1 ${OBJ}/stack_test.o ${LIB}/libstack1.a

runarray: ${BIN}/stack_test1
	echo "=====Testing Stack Array====="
	${BIN}/stack_test1

############################################################################################
# Question 5

${OBJ}/list_impl.o: ${INC}/list.h ${SRC}/list_impl.c
	${CC} -c -o ${OBJ}/list_impl.o ${SRC}/list_impl.c -I ${INC}

${OBJ}/stack_list.o: ${INC}/stack.h ${SRC}/stack_list.c
	${CC} -c -o ${OBJ}/stack_list.o ${SRC}/stack_list.c -I ${INC}

${LIB}/libstack2.a: ${OBJ}/list_impl.o ${OBJ}/stack_list.o
	ar rcs ${LIB}/libstack2.a ${OBJ}/list_impl.o ${OBJ}/stack_list.o

${BIN}/stack_test2: ${OBJ}/stack_test.o ${LIB}/libstack2.a
	${CC} -o ${BIN}/stack_test2 ${OBJ}/stack_test.o ${LIB}/libstack2.a

runlist: ${BIN}/stack_test2
	echo "=====Testing Stack List====="
	${BIN}/stack_test2

############################################################################################
# Question 6

${OBJ}/fifo_list.o: ${INC}/fifo.h ${SRC}/fifo_list.c
	${CC} -c -o ${OBJ}/fifo_list.o ${SRC}/fifo_list.c -I ${INC}

${OBJ}/fifo_test.o: ${INC}/fifo.h ${SRC}/fifo_test.c
	${CC} -c -o ${OBJ}/fifo_test.o ${SRC}/fifo_test.c -I ${INC}

${LIB}/libfifo.a: ${OBJ}/list_impl.o ${OBJ}/fifo_list.o
	ar rcs ${LIB}/libfifo.a ${OBJ}/list_impl.o ${OBJ}/fifo_list.o

${BIN}/fifo_test: ${OBJ}/fifo_test.o ${LIB}/libfifo.a
	${CC} -o ${BIN}/fifo_test ${OBJ}/fifo_test.o ${LIB}/libfifo.a

runfifo: ${BIN}/fifo_test
	echo "=====Testing Fifo====="
	${BIN}/fifo_test

############################################################################################


runall: runarray runlist runfifo

clean:
	rm -f ${OBJ}/* ${BIN}/* ${LIB}/*