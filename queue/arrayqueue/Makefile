CC = gcc 
EXEC = arraylist
OBJS = test.o arraylist.o


all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -O3 $^ -o $@

clean:
	rm -f $(EXEC) *.elf *.gdb *.o
.PHONY: all clean
