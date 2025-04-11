#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template<class Type>
class Stack;

template<class Type>
ostream & operator << (ostream &, const Stack<Type> &);

template<class Type>
struct Node {
    Type data;
    Node *next;
};

template<class Type>

class Stack {
public:
    Stack();
    ~Stack();

    // Push: Adds to the top of the stack
    void push(Type data);

    // Pop: Removes top value
    void pop();

    // Lookup top value
    Type peek();

    //isEmpty? Returns if stack is empty
    bool isEmpty();

    friend ostream & operator << <> (ostream &, const Stack<Type> &);
private:
    Node<Type> *top;

};
#endif //STACK_H


// Constructor
template<class Type>
Stack<Type>::Stack() {
    top = nullptr;
}

template<class Type>
// Destructor
Stack<Type>::~Stack() {
    while(!isEmpty()) {
        pop();
    }
}

template<class Type>
void Stack<Type>::push(Type data) {
    Node <Type> *toAdd = new Node<Type>;
    toAdd->data = data;
    toAdd->next = nullptr;

    if(top ==nullptr) {
        // Empty Stacc
        top = toAdd;
        toAdd ->next = nullptr;
    }else {
        // != First note
        toAdd->next = top;
        top = toAdd;
    }
}

template<class Type>
Type Stack<Type>::peek() {
    return top->data;
}
template<class Type>
void Stack<Type>::pop() {
    if(!isEmpty()) {
        Node<Type> *temp = top;
        top = top ->next;
        delete temp;
    }
}

template<class Type>
bool Stack<Type>::isEmpty(){
    return (top == nullptr);
}

template<class Type>
ostream & operator << (ostream & out, const Stack<Type> &s) {
    Node <Type>*curr = s.top;
    while(curr !=nullptr) {
        out << curr->data << " ";
        curr = curr->next;
    }
    return out;
}
