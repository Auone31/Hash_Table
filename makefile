OBJS = main.o hashtable.o Linked_List.o
CXX = g++-6
DEBUG = -g
CXXFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main : $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o main

main.o : main.cpp hashtable.h hashtable.cpp Linked_List.h Linked_List.cpp
	$(CXX) $(CXXFLAGS) main.cpp

hashtable.o : hashtable.h hashtable.cpp Linked_List.h Linked_List.cpp
	$(CXX) $(CXXFLAGS) hashtable.cpp

Linked_List.o : Linked_List.h Linked_List.cpp
	$(CXX) $(CXXFLAGS) Linked_List.cpp	

clean:
	\rm *.o *main