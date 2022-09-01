PROG = loop
OBJS = loop.o loop_c.o loop_s.o

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $@ $^

clean:
	rm $(PROG) $(OBJS)
