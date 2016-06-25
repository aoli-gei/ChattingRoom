CC := gcc
CFLAGS := -Wall -O3
Libs = -lpthread
Target := sever
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += pthread tcp_sever main
AllObjs := $(addsuffix /src/*.o,$(Modules))

