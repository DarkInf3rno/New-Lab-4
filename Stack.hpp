#ifndef STACK_H
#define STACK_H

namespace StackTop {
	using namespace std;

	template <typename T>
	struct StackFrame {
		T data;
		StackFrame<T>* link;
	};

	template <typename T>
	using StackFramePtr = StackFrame<T>*;

	template <typename T>
	class Stack {
	public:

		Stack(); // Initializes the object to empty Stack
		Stack(const Stack& stack); // Copy Constructor 
		~Stack(); // Destroys stack and returns it all the memory to free memory
    
		StackFramePtr<T> peek(); // Peeks at top of the stack and returns top

    int getSize();  //Helper function that returns the size of the stack. 
		void push(T d); // d is added to the stack
		T pop(); //  Precondition: the stack is not empty
		// returns top symbol on the stack and then removes top symbol from the stack
		bool empty() const; // Returns true if stack is empty
    void clear(); 
    StackFramePtr<T> clone(StackFramePtr<T> source); 
		Stack<T>& operator=(const Stack<T>& s);
		void reverse();

    StackFrame<T> getTop(); 
    void insertToBottom(T info); // helper function
	private:
		StackFramePtr<T> top;
	};
}
#endif 
