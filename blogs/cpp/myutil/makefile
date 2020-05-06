#export CC=/opt/local/bin/gcc
#export CXX=/opt/local/bin/g++
CC = gcc
CXX =g++
LD = g++
INC=-I/usr/local/include -I/opt/local/include
LIBDIR=-L/usr/local/lib -L/opt/local/lib
#CXXLIB=libgtest.a
TARGET = test

CFLAGS=-Wall -c -Werror -g -std=gnu11 -Wextra  -fsanitize=address -fsanitize-recover=address
CXXFLAGS=-Wall -c -Werror -g -Wextra  -fsanitize=address -fsanitize-recover=address
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))


CPPSRCS = $(wildcard *.cc)
CPPOBJS = $(patsubst %cc, %o, $(CPPSRCS))

.PHONY:all clean

all: $(TARGET)

$(TARGET): $(OBJS) $(CPPOBJS)
	$(CXX) $(LIBDIR) -lgtest -lpthread -o $@ $^ -fsanitize=address -g1

%.o:%.c
	$(CC) $(CFLAGS) $^

%.o:%.cc
	$(CXX) $(INC) $(CPPFLAGS) -c -g $^

clean:
	rm -f $(OBJS) $(CPPOBJS) $(TARGET)
