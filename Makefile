CC = gcc
TARGET = main
SRCS = main.c LunarSolarConverter.c xiao_liu_ren.c
OBJS = $(SRCS:.c=.o)

#$(TARGET):$(SRCS)
#	$(CC) $(TARGET) $(SRCS)

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o:%.c
	$(CC) -MMD -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -f $(TARGET) $(OBJS) $(OBJS:.o=.d)

.PHONY:clean
