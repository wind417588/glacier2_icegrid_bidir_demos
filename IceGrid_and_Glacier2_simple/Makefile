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
LIBS = -lIce -lGlacier2 -lpthread

#Gernation the target file
all: server client
.PHONY : clean

server_objects = Server.o HelloI.o Hello.o
client_objects = Client.o HelloI.o Hello.o

server:$(server_objects)
	$(CXX) -o $@ $(server_objects) $(LIBS)
	
client:$(client_objects)
	$(CXX) -o $@ $(client_objects) $(LIBS)

%.o : %.c
	$(CXX) $(CFLAGS) $(OPTS) -c $<

clean:
	-rm -f $(server_objects) $(client_objects) server client


