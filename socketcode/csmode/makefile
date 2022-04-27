src = $(wildcard *.c)
obj = $(patsubst %.c, %.out, $(src))

ALL:$(obj)

$(obj):%.out:%.c
	gcc $< -o $@ -g

clean:
	-rm -rf $(obj)
