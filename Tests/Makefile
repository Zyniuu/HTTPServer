CC := gcc
CFLAGS := -Wall -O2
OUTPATH = ../build/tests
OBJPATH = ../obj

all: DataStructures TestsSub
	@echo "Linking and compiling everything"
	$(CC) $(wildcard $(OBJPATH)/*.o) -o $(OUTPATH)/tests $(CFLAGS)

DataStructures: Node LinkedList

TestsSub: UnitTests TestNode TestLinkedList DataStructuresTests Tests

Tests:
	@echo "Compiling the Tests.c file"
	$(CC) -c $@.c -o $(OBJPATH)/$@.o $(CFLAGS)

UnitTests:
	@echo "Compiling the UnitTests.c file"
	$(CC) -c ../Tests/Common/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

TestNode:
	@echo "Compiling the TestNode.c file"
	$(CC) -c ../Tests/DataStructures/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

TestLinkedList:
	@echo "Compiling the TestLinkedList.c file"
	$(CC) -c ../Tests/DataStructures/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

DataStructuresTests:
	@echo "Compiling the DataStructuresTests.c file"
	$(CC) -c ../Tests/DataStructures/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

Node:
	@echo "Compiling the Node.c file"
	$(CC) -c ../HTTPServer/src/DataStructures/Common/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

LinkedList:
	@echo "Compiling the LinkedList.c file"
	$(CC) -c ../HTTPServer/src/DataStructures/Linear/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)


clean:
	@echo "Cleaning object files"
	rm -rf $(OBJPATH)/*.o