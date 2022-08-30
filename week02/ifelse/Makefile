PROG = ifelse
OBJS = ifelse.o ifelse_c.o ifelse_s.o

# pattern rule for C files
%.o: %.c
	gcc -g -c -o $@ $<

# pattern rule for Asm files
%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
