CC = gcc 
EXEC = arraysort
OBJS = test.o mysort.o


all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -O3 $^ -o $@

clean:
	rm -f $(EXEC) *.elf *.gdb *.o
.PHONY: all clean
