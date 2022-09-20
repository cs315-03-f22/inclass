PROG = get_bitseq
OBJS = get_bitseq.o get_bitseq_c.o get_bitseq_s.o

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $(PROG) $(OBJS)

clean:
	rm -rf $(PROG) $(OBJS)
