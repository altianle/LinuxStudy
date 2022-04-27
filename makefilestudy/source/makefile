src=$(wildcard ../source/*.c)
obj=$(patsubst ../source/%.c, ../lib/%.o, $(src))
exe=$(patsubst %.c, %.out, $(src))
ALL:a.out $(exe)
myargs= -g -I../inc -I../source

$(obj):../lib/%.o:../source/%.c
	gcc -c $< -o $@ $(myargs)

$(exe):../source/%.out:../lib/%.o
	gcc $< -o $@ $(myargs)

a.out:$(obj)
	gcc $^ -o $@ $(myargs)

clean:
	-rm -rf a.out $(obj) $(exe).out
	
