CC = gcc
CXX = g++
LD = gcc

TARGET = binread

CFLAGS=-Wall -c -Werror -g -std=gnu11 -Wextra  -fsanitize=address -fsanitize-recover=address
CXXFLAGS=-Wall -c -Werror -g -std=c++11 -Wextra  -fsanitize=address -fsanitize-recover=address
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))


CPPSRCS = $(wildcard *.cc)
CPPOBJS = $(patsubst %cc, %o, $(CPPSRCS))

.PHONY:all clean

all: $(TARGET)

$(TARGET): $(OBJS) $(CPPOBJS)
	$(CXX) -o $@ $^ -fsanitize=address -g1 -L$(LIBDIR) -lgtest -lpthread

%.o:%.c
	$(CC) $(CFLAGS) $^

%.o:%.cc
	$(CXX) -I$(INC) $(CPPFLAGS) -c -g $^

clean:
	rm -f $(OBJS) $(CPPOBJS) $(TARGET)
