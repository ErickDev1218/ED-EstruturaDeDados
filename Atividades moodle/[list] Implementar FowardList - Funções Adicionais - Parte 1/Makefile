run: ForwardList.o main.cpp
	g++ *.o main.cpp -o run

ForwardList.o: ForwardList.cpp ForwardList.h Node.h
	g++ -c ForwardList.cpp

clean:
	del *.exe
	del *.o