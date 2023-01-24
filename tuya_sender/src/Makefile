BIN:=tuya_sender
SRC:=$(wildcard *.c)
LDFLAGS:= -llink_core -lmiddleware_implementation -lplatform_port -lutils_modules
OBJS:=$(SRC:.c=.o)

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
		$(CC) -o $@ $^ $(LDFLAGS)

clean: 
		$(RM) $(BIN)
