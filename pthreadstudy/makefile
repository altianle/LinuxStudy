src=$(wildcard *.c)
pro=$(patsubst %.c,%.out,$(src))

ALL:$(pro)

$(pro):%.out:%.c
	gcc $< -o $@ -lpthread -g

clean:
	-rm -rf $(pro)
