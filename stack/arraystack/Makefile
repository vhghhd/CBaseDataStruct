CC = gcc 
EXEC = arraystack
OBJS = test.o arraystack.o


all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -O3 $^ -o $@

clean:
	rm -f $(EXEC) *.elf *.gdb *.o
.PHONY: all clean
