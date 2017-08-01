#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <fstream>

template<class T>
class MyList
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

    public:
        MyList():Head(nullptr) {};
        ~MyList(){
            Node* buf;
            while (Head)
            {
                buf=Head->next;
                delete Head;
                Head=buf;
            }
        }

        void push(T x){
            Node *temp = new Node;
            temp->setX(x);
            (!isEmpty()) ? temp->next=Head : temp->next=nullptr;
            Head=temp;
        }

        void pop() {
            if (!isEmpty()) {
                Node *buf;
                buf=Head->next;
                delete Head;
                Head=buf;
            }
            else std::cout << "List is empty\n";
        }

        bool isEmpty() {
            return (Head==(nullptr));
        }

        T* getFront() {
            if (isEmpty()) { std::cout << "List is empty, returning nullptr\n"; return nullptr; }
            return Head->getX();
        }

        int getAmount() {
            Node *temp=Head;
            int num=0;
            while (temp!=nullptr)
            {
                num++;
                temp=temp->next;
            }
            return num;
        }

        void unload() {
            if (isEmpty()) std::cout << "List is empty\n";
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

        void show() {
            if (isEmpty()) std::cout << "List is empty\n";
            else {
                Node* myIterator=Head;
                while (myIterator!=nullptr){
                    std::cout << *myIterator->getX();
                    myIterator=myIterator->next;
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
                        if (mas[i]<mas[j]) {
                            buf=mas[i];
                            mas[i]=mas[j];
                            mas[j]=buf;
                        }

            for (int i=0;i<amount;i++) push(mas[i]);
        };

        void linearSearch(T x){
            int num=-1;
            int amount=getAmount();
            Node* myIterator=Head;
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

#endif // MYLIST_H
