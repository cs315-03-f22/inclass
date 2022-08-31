PROGS = foo bar
FOO_OBJS = foo.o 
BAR_OBJS = bar.o

%.o: %.c
	gcc -g -c -o $@ $<

%.o: %.s
	as -g -o $@ $<

all: $(PROGS)

foo: $(FOO_OBJS)
	gcc -g -o $@ $^

bar: $(BAR_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(FOO_OBJS) $(BAR_OBJS)
