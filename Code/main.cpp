#include <iostream>
#include "mystack.h"
#include "myqueue.h"
#include "mydoublelist.h"
#include "mylist.h"
#include "object.h"

int main()
{
    MyStack<Object> Stack;
    MyQueue<Object> Queue;
    MyList<Object> List;
    MyDoubleList<Object> DoubleList;

    Object a(1,"Water",10);
    Object b(2,"House",20);
    Object c(3,"Elephant",30);
    Object d(4,"Sword",40);
    Object e(5,"Glass",50);

    std::cout << "Test Stack?" << std::endl;
    std::string answer;
    std::cin >> answer;
    if (!(answer=="no")) {

        Stack.push(d);
        Stack.push(b);
        Stack.push(c);
        Stack.push(a);
        Stack.push(e);

        Stack.unload();
    }

    std::cout << "Test Queue?" << std::endl;
    std::cin >> answer;
    if (!(answer=="no")) {

        Queue.push(d);
        Queue.push(b);
        Queue.push(c);
        Queue.push(a);
        Queue.push(e);

        Queue.linearSearch(a);

        Queue.bubbleSort();

        Queue.unload();
    }

    std::cout << "Test List?" << std::endl;
    std::cin >> answer;
    if (!(answer=="no")) {

        List.push(d);
        List.push(b);
        List.push(c);
        List.push(a);
        List.push(e);

        List.linearSearch(a);

        List.bubbleSort();

        List.show();
    }

    std::cout << "Test Doublelist?" << std::endl;
    std::cin >> answer;
    if (!(answer=="no")) {

        DoubleList.pushFront(d);
        DoubleList.pushFront(b);
        DoubleList.pushFront(c);
        DoubleList.pushFront(a);
        DoubleList.pushFront(e);

        DoubleList.linearSearch(a);

        DoubleList.bubbleSort();

        DoubleList.showFront();
        DoubleList.showBack();
        DoubleList.unloadBack();
        DoubleList.unloadBack();
    }

    std::cout << "Press any key and ENTER to quit\n";
    int Pause;
    std::cin >> Pause;
    return 0;
}
