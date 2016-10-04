CC = g++
CFLAGS = -std=c++11


Calculator: Calculator.o main.o Interpreter.o Evaluator.o ExpStack.o ExpQueue.o LinkedList.o ListNode.o
	g++ Calculator.o main.o Interpreter.o Evaluator.o ExpStack.o ExpQueue.o LinkedList.o ListNode.o -o CalculatorProgram
Interpreter.o: Interpreter.cpp Interpreter.h ExpStack.h ExpQueue.h LinkedList.h
	g++ -c $(CFLAGS) Interpreter.cpp
Evaluator.o: Evaluator.cpp Evaluator.h ExpStack.h 
	g++ -c $(CFLAGS) Evaluator.cpp
ExpStack.o: ExpStack.cpp ExpStack.h
	g++ -c $(CFLAGS) ExpStack.cpp
ExpQueue.o: ExpQueue.cpp ExpQueue.h
	g++ -c $(CFLAGS) ExpQueue.cpp
LinkedList.o: LinkedList.cpp LinkedList.h ListNode.h
	g++ -c $(CFLAGS) LinkedList.cpp
ListNode.o: ListNode.cpp ListNode.h
	g++ -c $(CFLAGS) ListNode.cpp
Calculator.o: Calculator.cpp Calculator.h Interpreter.h LinkedList.h Evaluator.h 
	g++ -c $(CFLAGS) Calculator.cpp
main.o: main.cpp Calculator.h
	g++ -c $(CFLAGS) main.cpp
clean:
	rm -f *.o
	rm CalculatorProgram