#include <iostream>
#include "Stack.hpp"
#include <string>
#include "Stack.cpp"
using namespace StackTop;
using namespace std;

template<typename T>
void printStack(Stack<T>& s) {

	T result;
  StackFramePtr<T> temp = s.peek();
	if (s.empty()) {
    cout <<"Stack is empty." << endl;
		exit(1);
	}
	else {
		cout << "Stack elements are ";
		 while (temp!= NULL) {
			result = temp-> data;
			cout << result << " ";
			temp = temp->link;
		} 
		cout << endl;

	}
}

int main() { 
  // part A
	Stack<int> sint1;
  
	sint1.push(1);
	sint1.push(2);
	sint1.push(3);
	sint1.push(4);
	sint1.push(5);
	sint1.push(6);
  sint1.push(7);

  cout<<"Sint1 stack: "<< endl;
  printStack(sint1);


  //sint1.clone(sint1.peek()); 

 
 Stack<int> sint2;
 sint2 = sint1;
  cout <<"Sint2 stack: " <<endl; 
  printStack(sint2);
  
  //sint1.clear();
  sint1.reverse();
  cout <<"Sint1 stack: " <<endl;
  printStack(sint1); 
  

   // part B
  Stack<double> sdouble1;
  sdouble1.push(1.5);
  sdouble1.push(2.5);
  sdouble1.push(3.5);
  sdouble1.push(4.5);
  sdouble1.push(5.5);
  sdouble1.push(6.5);

  cout <<"Sdouble1 stack: " << endl;
  printStack(sdouble1);
  
  
  Stack<double> sdouble2(sdouble1);
  sdouble2.reverse();
  cout <<"Sdouble2 stack: " <<endl;
  printStack(sdouble2);
  cout <<"Top of Sdouble2 is: " << sdouble2.peek() ->data << endl;

  // Part C
  cout << "Enter a string to be reversed: " ;
  Stack<char> palindrome;

  string input;
   
 // cin >> input;
  
  
  
	return 0;

}