
CFLAGS=-fplan9-extensions
LIBS=-lSDLmain -lSDL

all: libhyperbole.a

libcJSON.a: cJSON.o cJSON_Utils.o
	ar rcs $@ $^

libhyperbole.a: entity.o rect.o clock.o libcJSON.a
	ar rcs $@ $^
