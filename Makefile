SRC = inih/ini.c
OBJ = $(SRC:.c=.o)
OUT = libinih.a
INCLUDES = -I..
CCFLAGS =-Wall -g -O2
EXEC=tarea1
CC=gcc
SRCCODE=src

default: $(OUT)

compile: external $(SRCCODE)/main.c
	$(CC) $(CFLAGS) -Iincludes -L./ $(SRCCODE)/main.c objects/*.o -linih -ldl -o bin/$(EXEC) -g

external:
	for a in `ls $(SRCCODE)/*.c|grep -v main| sed 's/src\///g'`; do $(CC) $(CFLAGS) -g -Iincludes -c $(SRCCODE)/$$a  -o objects/$${a%*.c}.o; done

run:
	bin/$(EXEC) attacks ELEPEMONES

.c.o:
	$(CC) $(INCLUDES) $(CCFLAGS) $(EXTRACCFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ) $(EXTRAARFLAGS)
	mkdir objects
	mkdir bin

clean:
	rm -f $(OBJ) $(OUT)
