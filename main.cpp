#include <iostream>
#include "QueueClass.h"
#include "ListClass.h"
#define ARR_SIZE 32



void testQueue(){
    QueueClass *newQueue = new QueueClass();

    for (int i = 0; i < 3; i++)
        newQueue->Enqueue(i);

    int a = newQueue->Dequeue();

    newQueue->Enqueue(3);

    while (!newQueue->isEmpty()){
        std::cout << newQueue->Dequeue() << std::endl;
    }

    newQueue->Clear();
}

void testList(){
    ListClass *newList = new ListClass();

    for (int i = 0; i < 4; i++)
        newList->Add(i*2);
    newList->PrintList();

    newList->Add(5);
    newList->PrintList();


    std::cout << newList->GetIndex(2) <<std::endl;
    newList->Delete(3);
    newList->PrintList();
}

int main() {
    //testQueue();
    testList();
    return 0;
}
