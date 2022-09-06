PROG = len
OBJS = len.o len_c.o len_s.o

%.o: %.c
	gcc -g -c -o $@ $<

%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
