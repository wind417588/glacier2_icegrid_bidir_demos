#gcc compiler
CC = gcc
CFLAGS = -Wall -Wno-strict-aliasing -Wno-unused-variable
CFLAGS += -std=gnu99

#g++ compiler
CXX = g++
CXXFLAGS = -I. -Wall -fmessage-length=0 -fPIC

#Debug or Release, Debug:-g Release:-O3
ifdef GDB
	OPTS = -g -rdynamic
else
	OPTS = -O2 -rdynamic
endif

#Link the .so or .a library
LIBS = -lIce -lpthread

#Gernation the target file
all: server client
.PHONY : clean

server_objects = Server.o Hello.o HelloI.o
client_objects = Client.o Hello.o HelloI.o

#server: Server.o Hello.o HelloI.o
server:$(server_objects)
	$(CXX) -o $@ $(server_objects) $(LIBS)
	
#client: Client.o Hello,o HelloI.o
client:$(client_objects)
	$(CXX) -o $@ $(client_objects) $(LIBS)

%.o : %.c
	$(CXX) $(CFLAGS) $(OPTS) -c $<

clean:
	-rm -f $(server_objects) $(client_objects) server client


