src=$(wildcard *.c)
exe=$(patsubst %.c,%.out,$(src))
ALL:$(exe)

$(exe):%.out:%.c
	gcc $< -o $@

clean:
	-rm -rf $(exe)
