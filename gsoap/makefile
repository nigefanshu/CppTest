
ROOTSRC=$(wildcard *.cpp)
TARGETSRC1=myserver.cpp
TARGETSRC2=myclient.cpp
src=$(filter-out $(TARGETSRC1) $(TARGETSRC2),$(ROOTSRC))

#过滤掉main  cpp文件

OBJ=$(patsubst %.cpp,%.o,$(src))
LIB=-lgsoap++
FLAG=-g -o0 -Wall -std=c++11

#用all包装一下就可以一次编译出多个可执行文件
all:test test2

test:$(OBJ)
	g++ $(FLAG) -o myserver $(TARGETSRC1) $(filter-out soapaddProxy.o,$(OBJ))  $(LIB)
#	@echo $(OBJ)

test2:$(OBJ)
	g++ $(FLAG) -o myclient  $(TARGETSRC2) $(filter-out soapaddService.o,$(OBJ))  $(LIB)

clean:
	rm *.o myserver myclient
	@echo 'clean completed'
