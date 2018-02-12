CC = gcc 
EXEC = listqueue
OBJS = test.o LQueue.o


all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -O3 $^ -o $@

clean:
	rm -f $(EXEC) *.elf *.gdb *.o
.PHONY: all clean
