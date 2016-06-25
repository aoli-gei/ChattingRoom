CC := gcc
CFLAGS := -Wall -O3
Libs = -lpthread -lncurses
Target := client
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += pthread tcp_client main window others
AllObjs := $(addsuffix /src/*.o,$(Modules))

