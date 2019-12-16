all : main
main : util_timer.cpp sort_timer_lst.cpp  main.cpp
	g++ -o main util_timer.cpp sort_timer_lst.cpp main.cpp
main2 : util_timer.cpp sort_timer_lst.cpp  main.cpp
	g++ -o main2 util_timer.cpp sort_timer_lst.cpp main2.cpp
clean :
	rm *.gch *.o main main2
run :
	./main 127.0.0.1 8888
run2 :
	./main2 127.0.0.1 8888
connect :
	telnet 127.0.0.1 8888
