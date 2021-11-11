#include <iostream>
#include "Stack.hpp"
#include <cstddef>
#include <cstdlib>
#include <vector>

using namespace StackTop;
using namespace std;


template<typename T>
Stack<T>::Stack() {
	top = NULL;
}

//What does this even do?
// Constructor Function

template<typename T>
int Stack<T>::getSize() {

  StackFramePtr<T> tempTop = this->peek();
  int counter = 0; 

  while(1)  {
    if (tempTop == nullptr) {

    return counter; 

    }

    else {

      //if (tempTop->link != nullptr) {
        counter++; 
        tempTop = tempTop->link; 

    }
  }
}

template<typename T>
void Stack<T>::clear () {

  int size = this->getSize(); 
  if (!(this->empty())) {

    for (int i = 0; i < size; i++) {

      this->pop(); 

  }

  } else {return;}
}

template<typename T>
Stack<T>::~Stack() {
	
	while (!empty()) {
		 pop(); // pop calls delete
	}
}

// uses cstddef
template<typename T>
bool Stack<T>::empty() const {
	return (top == nullptr);
}

template<typename T>
StackFramePtr<T> Stack<T>::peek() {
	return top;
}
//Copy constructor
template<typename T>
Stack<T>::Stack(const Stack& stack){

   top = clone(stack.top);
  
}

//Helper function for copy
template<typename T>
StackFramePtr<T> Stack<T>::clone(StackFramePtr<T> source) {
  if (source == NULL){
    return NULL;
  }

   try {

    StackFramePtr<T> newNode = new StackFrame<T>; 
    newNode -> data = source -> data;
   // cout << "Clone ran" << endl; 
    newNode -> link = source -> link;
    return newNode; 
   }
   catch (bad_alloc e) {
     cout <<"Error, bad allocation" << endl;
     exit(1);
   }
}

  /*
  StackFramePtr<T> newNode = new StackFramePtr<T>;
  newNode -> data = source -> data; 
  this -> link = newNode; 
  Stack();
*/
/*
//Create a new adress for the deep copy, in top. 
//Setting new adress for top
  StackFramePtr<T> topHelper; 
  this -> top = topHelper; 
  delete topHelper; 

//Changing the data and setting a new adress for the link pointer thing

  this -> data = source->data; 
  StackFramePtr<T> linker;
  this -> link = linker; 

//go into link and repeat again until the size of new stack equals the size of the source stack. in that case set link = null. 
*/
/*
NodePtr newNode = new Node;
  newNode->key = root->key;
  newNode -> left = clone(root ->left);
*/
/*
1) Access top
2) Change the data in top
3) Set a new link address. 

these are notes for my own use

NodePtr BinarySearchTree::clone(NodePtr root) const{

  if (root){
  NodePtr newNode = new Node;
  newNode->key = root->key;
  newNode -> left = clone(root ->left);
  newNode -> right = clone(root ->right);
  return newNode;
}
return NULL;
}

*/

  



  


  




template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
  if (this == &s){
  return *this;
  }
  delete top;
  top = clone(s.top);
   return *this;
}

/*
template<typename T>
Stack<T>& operator=(const Stack<T>& s) {

  int newstackSize = s.getSize(); 
  int oldstackSize = this->getSize(); 
  
  //Empty old stack 
    while (!(this->empty())) {

          this->pop();

    }

    
  //Store newstack variables within a vector
    vector<T> tempVector; 
    for (int i = 0; i >= newstackSize; i--) {
        
        tempVector.push_back(s.push());
        s.pop();

        cout << tempVector[i-1]; 

      }

  //Push into stack
    for (int i = tempVector.size()-1; i >= 0; i--) {
        
        this->push(tempVector[i]); 
        

      }

    tempVector.clear(); 

}
  */

/*
For deep copy
  =Stack::Stack(const Stack &r) {
    stck_size = r.stck_size;
    stck = new int[stck_size];
    top = r.top;
    memcpy(stck, r.stck, top*sizeof (int));
}

1) Find the size of the new stack
2) Empty old stack. 
3) Get all the elements of the new stack and store somewhere. Last in first out tings.
4) Push back into stack

*/

template<typename T>
T Stack<T>::pop() {
	if (empty()) {
		cout << "Error: popping an empty stack " << endl;
		exit(1);

	}
	else {
		try {
			T result = top->data;
			StackFramePtr<T> temp;
			temp = top;
			top = top->link;
			delete temp;
			return result;
		}
		catch (std::bad_alloc e) {
			cout << "Error, bad allocation" << endl;
			exit(1);
		}
	}
}


template<typename T>
void Stack<T>::push(T data) {
  try {
		StackFramePtr<T> newStack = new StackFrame<T>;
		
    newStack->data = data; // new
		newStack->link = top;
		top = newStack;
  
  }
	catch (std::bad_alloc e) {
		cout << "Error, bad allocation" << endl;
		exit(1);
	}
}

template<typename T>
void Stack<T>::insertToBottom(T info){
  StackFramePtr<T> temp = peek();
  if (empty()){
    push(info); // Stack is empty, push it in
  }
  else {
    T temp2 = pop(); // pops the elements
    insertToBottom(info); // Inserts the give element to bottom
    push(temp2); // then pushes all popped elements
  }
}

template<typename T>
void Stack<T>::reverse(){

if (empty() != true){
  T info = pop(); // pops the elements
  reverse(); // recurses back
  insertToBottom(info); // Inserts to bottom
   }
}




/*
// You cant use while loops for this
template<typename T>
void Stack<T>::reverse(){
 
  vector<T> tempVector; 

StackFramePtr<T> temp = this->peek();
	if (this->empty()) {
    cout << "Ur stack be empty";
		exit(1);
	}
	else {
		while (1) {

      StackFramePtr<T> temp2 = this->peek();
      if (temp2 == nullptr) {return;}

      else {
          StackFramePtr<T> temp2 = this->peek(); //Returns the top StackFramePtr<T>

        //Get the data
          T tempData = temp2->data; 
        //Push the data into stack2
          tempVector.push_back(tempData);
        //Get rid of the top and proceed further until the break condition is triggered. 
          this->pop(); 

      }
      int length = tempVector.size(); 

      for (int i = length-1; i>=0; i--) {

        this->push(tempVector[i]);

      }
		} 
  //Take top and keep pushing into a new stack. Then use equals operator to set equals to the first stack. 
  }
}
*/









