src=$(wildcard *.c)
out=$(patsubst %.c, %.out, $(src))

ALL:$(out)
$(out):%.out:%.c
	gcc $< -o $@

clean:
	-rm -rf $(out)
