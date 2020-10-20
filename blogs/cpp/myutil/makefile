#export CC=/opt/local/bin/gcc
#export CXX=/opt/local/bin/g++
CC = gcc
CXX =g++
LD = gcc
INC=-I/usr/local/include -I/opt/local/include
LIBDIR=-L/usr/local/lib -L/opt/local/lib

#INC=-L/root/wks/blogs/googletest/googletest/include
#LIBDIR=-L/root/wks/blogs/googletest/build/lib

#CXXLIB=libgtest.a
TARGET = test

CFLAGS=-Wall -c -Werror -g -std=gnu11 -Wextra  -fsanitize=address -fsanitize-recover=address
CXXFLAGS=-Wall -c -Werror -std=c++11 -g -Wextra  -fsanitize=address -fsanitize-recover=address
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))


CPPSRCS = $(wildcard *.cc)
CPPOBJS = $(patsubst %cc, %o, $(CPPSRCS))

.PHONY:all clean

all: $(TARGET)

## gtest pthread must put behind target
$(TARGET): $(OBJS) $(CPPOBJS)
	$(CXX) -o $@ $^ -fsanitize=address -g1 $(LIBDIR) -lgtest -lpthread

%.o:%.c
	$(CC) $(CFLAGS) $^

%.o:%.cc
	$(CXX) $(INC) $(CPPFLAGS) -c -g $^

run:
	./$(TARGET)

clean:
	rm -f $(OBJS) $(CPPOBJS) $(TARGET)
