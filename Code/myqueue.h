#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <fstream>

template<class T>
class MyQueue   //LIFO data structure, i made it supporting forwarding through elements
{
    struct Node
        {
            T* x;
            Node *next;

            Node() {  x = new T; }

            ~Node() { delete x; }

            T* getX() {  return x; }
            void setX(T buf) { *x=buf; }
        };

    Node *Head;
    Node *Tail;

    public:
        MyQueue(): Head(nullptr),Tail(nullptr) {};
        ~MyQueue(){
            Node* buf;
            while (Head)
            {
                buf=Head->next;
                delete Head;
                Head=buf;
            }
        }

        void push(T x) {
            Node *temp = new Node;
            temp->setX(x);
            if (!isEmpty()) temp->next=Tail; else { temp->next=nullptr; Head=temp; }
            Tail=temp;
        }

        void pop() {
            if (!isEmpty())
                if (Head==Tail) { delete Head; Head=nullptr; }
                    else {  Node *buf=Tail;
                            for (;buf->next!=Head;) buf=buf->next;
                            delete Head;
                            buf->next=nullptr;
                            Head=buf;
                    }
            else std::cout << "Queue is empty\n";
        }

        bool isEmpty() {
            return (Head==nullptr);
        }

        T* getFront() {
            if (isEmpty()) { std::cout << "Queue is empty, returning nullptr\n"; return nullptr; }
            return Head->getX();
        }

        int getAmount() {
            Node *temp=Tail;
            int num=0;
            while (temp!=nullptr)
            {
                num++;
                temp=temp->next;
            }
            return num;
        }

        void unload() {
            if (isEmpty()) std::cout << "Queue is empty\n";
            else {
                T* bufObj;
                while (!isEmpty()){
                    bufObj=Head->getX();
                    std::cout << *bufObj;
                    pop();
                }
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

        void bubbleSort() {
            int amount=getAmount();
            T mas[amount];
            T buf;

            for (int i=0;i<amount;i++)
            {
                mas[i]=*getFront();
                pop();
            };

            for (int i=0;i<amount;i++)
                for (int j=0;j<amount;j++)
                        if (mas[i]>mas[j]) {
                            buf=mas[i];
                            mas[i]=mas[j];
                            mas[j]=buf;
                        }

            for (int i=0;i<amount;i++) push(mas[i]);
        };

        void linearSearch(T x){
            int num=-1;
            int amount=getAmount();
            Node* myIterator=Tail;
            T mas[amount];

            for (int i=0;i<amount;i++)
            {
                mas[i]=*myIterator->getX();
                myIterator=myIterator->next;
            };

            for (int i=0;i<amount;i++) if (mas[i]==x) { num=i+1;  break;};

            (num==-1) ? std::cout << "\nElement " << x << " not found\n" : std::cout << "\nElement " << x << " is found on " << num << " position" << std::endl;
        };
};

#endif // MYQUEUE_H

