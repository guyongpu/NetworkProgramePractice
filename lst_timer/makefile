all : main
main : main.o
	g++ -o main main.o 
main.o : main.cpp sort_timer_lst.cpp sort_timer_lst.h util_timer.cpp util_timer.h
	g++ -c main.cpp sort_timer_lst.cpp sort_timer_lst.h util_timer.cpp util_timer.h
clean :
	rm test *.o
