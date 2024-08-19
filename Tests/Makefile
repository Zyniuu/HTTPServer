CC := gcc
CFLAGS := -Wall -O2
OUTPATH = ../build/tests
OBJPATH = ../obj

all: Helpers DataStructures HTTP TestsSub
	@echo "Linking and compiling everything"
	$(CC) $(wildcard $(OBJPATH)/*.o) -o $(OUTPATH)/tests $(CFLAGS)

DataStructures: Node LinkedList Queue BST Entry Dictionary

HTTP: Request Config

TestsSub: UnitTests TestNode TestLinkedList TestQueue TestBST TestDictionary DataStructuresTests TestMultiTok TestRemoveSpaces TestRequest TestConfig HelpersTests HTTPTests Tests

.PHONY: Helpers
Helpers:
	@echo "Compiling the Helpers.c file"
	$(CC) -c ../HTTPServer/src/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

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

TestQueue:
	@echo "Compiling the TestQueue.c file"
	$(CC) -c ../Tests/DataStructures/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

TestBST:
	@echo "Compiling the TestBST.c file"
	$(CC) -c ../Tests/DataStructures/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

TestMultiTok:
	@echo "Compiling the TestMultiTok.c file"
	$(CC) -c ../Tests/Helpers/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

TestRemoveSpaces:
	@echo "Compiling the TestRemoveSpaces.c file"
	$(CC) -c ../Tests/Helpers/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

TestRequest:
	@echo "Compiling the TestRequest.c file"
	$(CC) -c ../Tests/HTTP/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

TestConfig:
	@echo "Compiling the TestConfig.c file"
	$(CC) -c ../Tests/HTTP/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

TestDictionary:
	@echo "Compiling the TestDictionary.c file"
	$(CC) -c ../Tests/DataStructures/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

DataStructuresTests:
	@echo "Compiling the DataStructuresTests.c file"
	$(CC) -c ../Tests/DataStructures/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

HelpersTests:
	@echo "Compiling the HelpersTests.c file"
	$(CC) -c ../Tests/Helpers/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

HTTPTests:
	@echo "Compiling the HTTPTests.c file"
	$(CC) -c ../Tests/HTTP/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

Node:
	@echo "Compiling the Node.c file"
	$(CC) -c ../HTTPServer/src/DataStructures/Common/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

LinkedList:
	@echo "Compiling the LinkedList.c file"
	$(CC) -c ../HTTPServer/src/DataStructures/Linear/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

Queue:
	@echo "Compiling the Queue.c file"
	$(CC) -c ../HTTPServer/src/DataStructures/Linear/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

BST:
	@echo "Compiling the BST.c file"
	$(CC) -c ../HTTPServer/src/DataStructures/NonLinear/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

Entry:
	@echo "Compiling Entry.c file"
	$(CC) -c ../HTTPServer/src/DataStructures/NonLinear/Dictionary/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

Dictionary:
	@echo "Compiling the Dictionary.c file"
	$(CC) -c ../HTTPServer/src/DataStructures/NonLinear/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

Request:
	@echo "Compiling the Request.c file"
	$(CC) -c ../HTTPServer/src/HTTP/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

Config:
	@echo "Compiling the Config.c file"
	$(CC) -c ../HTTPServer/src/HTTP/$@/$@.c -o $(OBJPATH)/$@.o $(CFLAGS)

clean:
	@echo "Cleaning object files"
	rm -rf $(OBJPATH)/*.o