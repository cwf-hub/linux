CROSS = arm-xm-linux-

CC = $(CROSS)gcc
CC64 = gcc
TARGET = app

DEPS = $(shell find -name "*.h")
SRC = $(shell find -name "*.c")
OBJ = $(SRC:%.c=%.o)

CFLAGS = -I./include

REL_LIB = ./lib
XM_LIB = $(REL_LIB)/xm

LDFLAGS += -lpthread

all:$(TARGET)

MPI_LIBS := $(XM_LIB)/*.a 

%.o:%.c $(DEPS)
	$(CC64) $(CFLAGS) -c $< -o $@
#说明：
#$@表示目标项，即$(TARGET),$^表示依赖项的所有文件，即$(OBJ)	
$(TARGET):$(OBJ)
	$(CC64) $(LDFLAGS) -o $@ $^ -Xlinker "-(" $(MPI_LIBS) -Xlinker "-)"
	
clean:
	rm -rf $(TARGET)
	rm -rf $(OBJ)
