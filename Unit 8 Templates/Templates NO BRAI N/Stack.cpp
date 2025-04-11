// #include "Stack.h"
// #include <iostream>
//
// template<class Type>
// // Constructor
// Stack<Type>::Stack() {
//     top = nullptr;
// }
// template<class Type>
// // Destructor
// Stack<Type>::~Stack() {
//     while(!isEmpty()) {
//         pop();
//     }
// }
// template<class Type>
// void Stack<Type>::push(Type data) {
//     Node<Type> *toAdd = new Node<Type>;
//     toAdd->data = data;
//
//     if(top == nullptr) {
//         // Empty stack!
//         top = toAdd;
//         toAdd -> next = nullptr;
//     } else {
//         // Anything that is not the first node
//         toAdd -> next = top;
//         top = toAdd;
//     }
// }
//
// template<class Type>
// Type Stack<Type>::peek() {
//     return top -> data;
// }
// template<class Type>
// void Stack<Type>::pop() {
//     if(!isEmpty()) {
//         Node<Type> *temp = top;
//         top = top->next;
//     }
// }
//
// template<class Type>
// bool Stack<Type>::isEmpty() {
//     return (top == nullptr);
// }
//
// template<class Type>
// ostream &operator << (ostream & out, const Stack<Type> &s) {
//     Node<Type> *curr = s.top;
//
//     while(curr != nullptr) {
//         out << curr->data << " ";
//         curr = curr -> next;
//     }
//
//     return out;
// }