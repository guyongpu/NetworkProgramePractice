all : main
main : util_timer.cpp sort_timer_lst.cpp  main.cpp
	g++ -o main util_timer.cpp sort_timer_lst.cpp main.cpp
clean :
	rm *.gch *.o main
run :
	./main 127.0.0.1 8888
connect :
	telnet 127.0.0.1 8888
