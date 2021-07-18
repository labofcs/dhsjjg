CC = gcc
CFLAGS = -Wall -std=gnu99
INC = -Iinc

.PHONY : build rebuild clean

build : bin/t_sq_list bin/t_link_list

bin/t_sq_list : obj/sq_list.o obj/t_sq_list.o
	@ mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

bin/t_link_list : obj/link_list.o obj/t_link_list.o
	@ mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

.depend : src/sq_list.c src/t_sq_list.c src/link_list.c
	$(CC) -MM $(INC) $^ > $@
	sed -i '/.o:/ s,^,obj/,' $@
sinclude .depend

obj/%.o : src/%.c $(MAKEFILE_LIST)
	@ mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

rebuild : clean build

clean : 
	-rm .depend
	-rm -rf obj
	-rm -rf bin