#ifndef QUEUE_H
#define QUEUE_H

#include <ostream>

using namespace std;

template<class Type>
class Queue;

template<class Type>
ostream &operator << (ostream &, const Queue<Type> &);

template<class Type>
struct Node {
    Type data;
    Node* next;
};


template<class Type>
class Queue {
public:
    Queue();
    ~Queue();

    //Returns true if the stack is empty
    bool isEmpty();

    //Adds an item to the end of the queue
    void add(Type data);

    // Removes the item at the front of the queue
    void remove();

    // Returns the value in the front of the queue (without removing)
    Type peek();

    // Overloads the extraction operator to display the queue
    friend ostream &operator << <> (ostream &, const Queue<Type> &);

private:
    Node<Type> *front;
    Node<Type> *end;
};

// Constructor
template<class Type>
Queue<Type>::Queue() {
    front = nullptr;
    end = nullptr;
}

// Destructor
template<class Type>
Queue<Type>::~Queue() {
    while(!isEmpty()) {
        remove();
    }
}

template<class Type>
bool Queue<Type>::isEmpty() {
    return (front == nullptr);
}

template<class Type>
void Queue<Type>::add(Type data) {
    if(isEmpty()) {
        Node<Type>* temp = new Node<Type> (data);
        front = temp;
        end = temp;
    } else {
        Node<Type>* temp = new Node<Type>(data);
        end -> next = temp;
        end = temp;
    }
}

template<class Type>
void Queue<Type>::remove() {
    if(!isEmpty()) {
        Node<Type>* temp = front;
        front = front->next;
        delete temp;
    }
}

template<class Type>
Type Queue<Type>::peek() {
    return front -> data;
}

template<class Type>
ostream &operator << (ostream &out, const Queue<Type> &q) {
    Node<Type> *current = q.front;

    while(current != nullptr) {
        out << current->data << " ";
        current = current -> next;
    }
    return out;
}

#endif //QUEUE_H