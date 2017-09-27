CC=gcc -Wall
BIN=bin
INC=include
LIB=lib
OBJ=obj
SRC=src


all: clean runall


############################################################################################
# Question 1

${OBJ}/program_trace.o: ${SRC}/program_trace.c
	${CC} -c -o ${OBJ}/program_trace.o ${SRC}/program_trace.c -I ${INC}

${BIN}/program_trace: ${OBJ}/program_trace.o
	${CC} -o ${BIN}/program_trace ${OBJ}/program_trace.o

runtrace: ${BIN}/program_trace
	echo "=====Testing Program Trace====="
	${BIN}/program_trace

############################################################################################
# Question 2

${OBJ}/decoder.o: ${SRC}/decoder.c
	${CC} -c -o ${OBJ}/decoder.o ${SRC}/decoder.c -I ${INC}

${BIN}/decoder: ${OBJ}/decoder.o
	${CC} -o ${BIN}/decoder ${OBJ}/decoder.o

rundecoder: ${BIN}/decoder
	echo "=====Testing Decoder====="
	${BIN}/decoder

############################################################################################
# Question 3

${OBJ}/converters.o: ${INC}/converters.h ${SRC}/converters.c
	${CC} -c -o ${OBJ}/converters.o ${SRC}/converters.c -I ${INC}

${OBJ}/multi_converter.o: ${INC}/converters.h ${SRC}/multi_converter.c
	${CC} -c -o ${OBJ}/multi_converter.o ${SRC}/multi_converter.c -I ${INC}

${LIB}/converters.a: ${OBJ}/converters.o
	ar rcs ${LIB}/converters.a ${OBJ}/converters.o

${BIN}/multi_converter: ${OBJ}/multi_converter.o ${LIB}/converters.a
	${CC} -o ${BIN}/multi_converter ${OBJ}/multi_converter.o ${LIB}/converters.a

runconverter: ${BIN}/multi_converter
	echo "=====Testing Multi-converter====="
	${BIN}/multi_converter CNY 100.000

############################################################################################


runall: runtrace rundecoder runconverter

clean:
	rm -f ${OBJ}/* ${BIN}/* ${LIB}/*