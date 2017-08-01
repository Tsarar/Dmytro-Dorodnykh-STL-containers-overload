#ifndef MYDOUBLELIST_H
#define MYDOUBLELIST_H

#include <iostream>
#include <fstream>

template<class T>
class MyDoubleList      //double list implemented as a set of memory blocks in the heap
                        //it supports operations in both directions
{
    struct Node
        {
            T* x;
            Node *next, *prev;

            Node() {  x = new T; }

            ~Node() { delete x; }

            T* getX() {  return x; }
            void setX(T buf) { *x=buf; }
        };

    Node *Head;
    Node *Tail;

    public:
        MyDoubleList(): Head(nullptr),Tail(nullptr) {};
        ~MyDoubleList(){
            Node* buf;
            while (Head)
            {
                buf=Head->prev;
                delete Head;
                Head=buf;
            }
        }

        void pushFront(T x) {
            Node *temp = new Node;
            temp->setX(x);
            temp->next=nullptr;
            if (!isEmpty()) { temp->prev=Head; Head->next=temp; } else { temp->prev=nullptr; Tail=temp; }
            Head=temp;
        }

        void pushBack(T x) {
            Node *temp = new Node;
            temp->setX(x);
            temp->prev=nullptr;
            if (!isEmpty()) { temp->next=Tail; Tail->prev=temp; } else { temp->next=nullptr; Head=temp; }
            Tail=temp;
        }

        void popFront() {
            if (!isEmpty())
                if (Head==Tail) { delete Head; Head=nullptr; Tail=nullptr; }
                else {
                        Node *buf=Head->prev;
                        delete Head;
                        Head=buf;
                        Head->next=nullptr;
                    }
            else std::cout << "Double list is empty\n";
        }

        void popBack() {
            if (!isEmpty())
                if (Head==Tail) { delete Head; Head=nullptr; Tail=nullptr; }
                else {
                        Node *buf=Tail->next;
                        delete Tail;
                        Tail=buf;
                        Tail->prev=nullptr;
                    }
            else std::cout << "Double list is empty\n";
        }

        bool isEmpty() {
            return (Head==nullptr);
        }

        T* getFront() {
            if (isEmpty()) { std::cout << "Double list is empty, returning nullptr\n"; return nullptr; }
            return Head->getX();
        }

        T* getBack() {
            if (isEmpty()) { std::cout << "Double list is empty, returning nullptr\n"; return nullptr; }
            return Tail->getX();
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

        void showFront() {
            if (isEmpty()) std::cout << "Double list is empty\n";
            else {
                Node *myIterator=Head;
                while (myIterator!=nullptr){
                    std::cout << *myIterator->getX();
                    myIterator=myIterator->prev;
                }
                std::cout << std::endl;
            }
        };

        void showBack() {
            if (isEmpty()) std::cout << "Double list is empty\n";
            else {
                Node *myIterator=Tail;
                while (myIterator!=nullptr){
                    std::cout << *myIterator->getX();
                    myIterator=myIterator->next;
                }
                std::cout << std::endl;
            }
        };

        void unloadFront() {
            if (isEmpty()) std::cout << "Double list is empty\n";
            else {
                T* bufObj;
                while (!isEmpty()){
                    bufObj=Head->getX();
                    std::cout << *bufObj;
                    popFront();
                }
            }
        };

        void unloadBack() {
            if (isEmpty()) std::cout << "Double list is empty\n";
            else {
                T* bufObj;
                while (!isEmpty()){
                    bufObj=Tail->getX();
                    std::cout << *bufObj;
                    popBack();
                }
            }
        };

        void fillFromFile() {
            std::ifstream input("input.txt");
            if (!input) std::cout << "File is not found"; else {
            T obj;
            while (input){
                    input >> obj;
                    pushFront(obj);
                }
                popFront();
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
                popFront();
            };

            for (int i=0;i<amount;i++)
                for (int j=0;j<amount;j++)
                        if (mas[i]>mas[j]) {
                            buf=mas[i];
                            mas[i]=mas[j];
                            mas[j]=buf;
                        }

            for (int i=0;i<amount;i++) pushFront(mas[i]);
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

#endif // MYDOUBLELIST_H


