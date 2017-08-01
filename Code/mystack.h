#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <fstream>

template<class T>
class MyStack
{
    struct Node {   //stack does not support forwarding through elements, it supports either pop or push
                    //its also FIFO
            Node *next;
            T* x;

            Node() {  x = new T; }

            ~Node() { delete x; }

            T* getX() {  return x; }
            void setX(T buf) { *x=buf; }
        };

    Node *Head;
    int amount;

    public:
        MyStack():Head(nullptr) { amount=0; };
        ~MyStack(){ while (amount) pop(); }

        void push(T x){
            Node *temp = new Node;
            temp->setX(x);
            (!isEmpty()) ? temp->next=Head : temp->next=nullptr;
            Head=temp;
            amount++;
        }

        void pop() {
            if (!isEmpty()) {
                Node *buf;
                buf=Head->next;
                delete Head;
                Head=buf;
                amount--;
            }
            else std::cout << "Stack is empty\n";
        }

        bool isEmpty() {
            return (Head==(nullptr));
        }

        T* getFront() {
            if (isEmpty()) { std::cout << "Stack is empty, returning nullptr\n"; return nullptr; }
            return Head->getX();
        }

        int getAmount() {
            return amount;
        }

        void unload() {
            if (isEmpty()) std::cout << "Stack is empty\n";
            else {
                T* bufObj;
                while (!isEmpty()){
                    bufObj=Head->getX();
                    std::cout << *bufObj;
                    pop();
                }
                std::cout << std::endl;
            }
        };

        void fillFromFile() {
            std::ifstream input("input.txt");
            if (!input) std::cout << "File is not found"; else {
            T obj;
            while (input){
                    input >> obj;
                    push(obj);
                }
                pop();
            };
            input.close();
        };
};

#endif // MYSTACK_H
