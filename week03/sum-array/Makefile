PROG = sumarray
OBJS = sumarray.o sumarray_c.o sumarray_s.o

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
