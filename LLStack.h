// Dennis Hahn CS1510 1B Homework #5
// LLStack.h 

#ifndef LLSTACK_H
#define LLSTACK_H

#include "abstractstack.h"

using namespace std; 

template <class T>
class LLStack: public AbstractStack<T>
{
	public:
		T m_data;                
		LLStack<T>* m_next;     
		LLStack() : m_next(NULL) {}

		// Constructor
		LLStack(const T& x, LLStack<T>* p) 
				 : m_data(x), m_next(p) {}
		
		// Destructor 
		 ~LLStack() {}

		// Function Prototypes
		virtual bool isEmpty() const;
		virtual const T& top() const throw ( Oops );
		virtual void push(const T& x);
		virtual void pop();
		virtual void clear();
		void output(); //Outputs stack
};

#include "stackfunctions.hpp"
#endif
