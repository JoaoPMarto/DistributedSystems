OBJECTOS = data.o entry.o tree.o serialization.o

BIN_DIR = bin

SRC_DIR = src

INC_DIR = include

OBJ_DIR = obj

TEST_DIR = testes

CFLAGS = -Wall -I $(INC_DIR) 

CC = gcc


data.o: $(SRC_DIR)/data.c $(INC_DIR)/data.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/data.c -o $(OBJ_DIR)/data.o

entry.o: $(SRC_DIR)/entry.c $(INC_DIR)/entry.h $(INC_DIR)/data.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/entry.c -o $(OBJ_DIR)/entry.o

tree.o: $(SRC_DIR)/tree.c $(INC_DIR)/tree.h $(INC_DIR)/data.h $(INC_DIR)/tree-private.h $(INC_DIR)/entry.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tree.c -o $(OBJ_DIR)/tree.o

serialization.o:$(SRC_DIR)/serialization.c $(INC_DIR)/serialization.h $(INC_DIR)/data.h $(INC_DIR)/entry.h $(INC_DIR)/tree.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/serialization.c -o $(OBJ_DIR)/serialization.o

test_data.o: $(SRC_DIR)/test_data.c $(INC_DIR)/data.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/test_data.c -o $(OBJ_DIR)/test_data.o

test_entry.o: $(SRC_DIR)/test_entry.c $(INC_DIR)/entry.h $(INC_DIR)/data.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/test_entry.c -o $(OBJ_DIR)/test_entry.o

test_tree.o: $(SRC_DIR)/test_tree.c $(INC_DIR)/tree.h $(INC_DIR)/data.h $(INC_DIR)/entry.h $(INC_DIR)/tree-private.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/test_tree.c -o $(OBJ_DIR)/test_tree.o

test_serialization.o: $(SRC_DIR)/test_serialization.c $(INC_DIR)/data.h $(INC_DIR)/entry.h $(INC_DIR)/serialization.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/test_serialization.c -o $(OBJ_DIR)/test_serialization.o

test_data: $(OBJ_DIR)/test_data.o $(OBJ_DIR)/data.o $(OBJ_DIR)/entry.o $(OBJ_DIR)/tree.o $(OBJ_DIR)/serialization.o
	$(CC) $(OBJ_DIR)/test_data.o $(OBJ_DIR)/data.o -lrt -lpthread -o $(BIN_DIR)/test_data

test_entry: $(OBJ_DIR)/test_entry.o $(OBJ_DIR)/data.o $(OBJ_DIR)/entry.o $(OBJ_DIR)/tree.o $(OBJ_DIR)/serialization.o
	$(CC) $(OBJ_DIR)/test_entry.o $(OBJ_DIR)/data.o $(OBJ_DIR)/entry.o -lrt -lpthread -o $(BIN_DIR)/test_entry

test_tree: $(OBJ_DIR)/test_tree.o $(OBJ_DIR)/data.o $(OBJ_DIR)/entry.o $(OBJ_DIR)/tree.o $(OBJ_DIR)/serialization.o
	$(CC) $(OBJ_DIR)/test_tree.o $(OBJ_DIR)/data.o $(OBJ_DIR)/entry.o $(OBJ_DIR)/tree.o -lrt -lpthread -o $(BIN_DIR)/test_tree

test_serialization: $(OBJ_DIR)/test_serialization.o $(OBJ_DIR)/data.o $(OBJ_DIR)/entry.o $(OBJ_DIR)/tree.o $(OBJ_DIR)/serialization.o
	$(CC) $(OBJ_DIR)/test_serialization.o $(OBJ_DIR)/data.o $(OBJ_DIR)/entry.o $(OBJ_DIR)/tree.o $(OBJ_DIR)/serialization.o -lrt -lpthread -o $(BIN_DIR)/test_serialization

clean:
	    
	rm -f $(BIN_DIR)/test_data
	rm -f $(BIN_DIR)/test_entry
	rm -f $(BIN_DIR)/test_tree
	rm -f $(BIN_DIR)/test_serialization
	rm -f *.o
