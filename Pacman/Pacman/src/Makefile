CC = g++   #编译方式
VERSION = -g -std=c++11 -Wall  #采用c++11显示所有警告
INCLUDE = -I../include -lglut -lGL    #头文件，库文件
TARGET = ../bin/Pacman  #目标文件
SRCS = $(wildcard *.cpp)  #源代码文件
OBJS = $(patsubst %cpp,%o,$(SRCS))   #输出文.o文件

all:$(TARGET)
	
$(TARGET):$(OBJS)
	$(CC) $(OBJS) $(VERSION) $(INCLUDE) -o $(TARGET)

%.o:%.cpp
	$(CC) $(VERSION) $(INCLUDE) -c $<

.PHONY:clean
clean:
	rm -rf $(OBJS) $(TARGET)
