CC=arm-anykav200-linux-uclibcgnueabi-gcc
CFLAGS=-std=c99

SRCS:=$(wildcard *.c)
OBJS:=$(patsubst %.o,%.c,$(SRCS))

md5 : $(OBJS)
	echo "OBJS="$(OBJS)
	echo "SRCS="$(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	echo "CFLAGS="$(CFLAGS)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o md5
