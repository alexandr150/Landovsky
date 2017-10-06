//
// Created by Alexandr on 06.10.2017.
//
#include <iostream>
#include "ListClass.h"
#define MAX_SIZE 64



ListClass::ListClass() {
    holesQueue = new QueueClass();
    listArray = (listNode**) new listNode [MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++)
        listArray[i] = nullptr;
    head = tail = -1;
}

ListClass::~ListClass() {
    delete holesQueue;
    delete [] listArray;
}

void ListClass::Add(int data) {
    int indexNewNode;
    listNode *newNode = new listNode();
    newNode->data = data;

    //Если список пуст
    if (head == -1) {
        newNode->nextNode = newNode->prevNode = -1;
        listArray[0] = newNode;
        head = tail = 0;
        return;
    }

    //Ищем, куда воткнуть новый элемент в массиве
    if (holesQueue->isEmpty()) {
        //Означает, что вставляем в первую непустую ячейку массива
        for (int i = 0; i < MAX_SIZE; i++)
            if (listArray[i] == nullptr) {
                listArray[indexNewNode = i] = newNode;
                break;
            }

    } else {
        //Означает, что дырка есть, и добавляем новый элемент
        //по индексу этой дырки
        listArray[indexNewNode = holesQueue->Dequeue()] = newNode;
    }

    //Ищем, перед кем должен стоять новый элемент
    listNode *iterator = listArray[head];

    while (data > iterator->data) {
        if ( iterator->nextNode == -1 )
        {
            iterator = nullptr;
            break;
        }
        iterator = listArray[iterator->nextNode];
    }

    //Связываем новый элемент с другими элементами

    if (iterator == listArray[head]) {
        //Означает, что новый элемент вставляется в начало списка
        newNode->nextNode = head;
        newNode->prevNode = -1;
        iterator->prevNode = indexNewNode;
        head = indexNewNode;
    }
    else if (iterator == nullptr) {
        //Означает, что новый элемент вставляется в конец списка
        newNode->nextNode = -1;
        newNode->prevNode = tail;
        listArray[tail]->nextNode = indexNewNode;
        tail = indexNewNode;
    }
    else {   //Означает, что новый элемент вставляется в середину списка
        newNode->prevNode = iterator->prevNode;
        newNode->nextNode = listArray[newNode->prevNode]->nextNode;
        listArray[iterator->prevNode]->nextNode = iterator->prevNode = indexNewNode;
    }
}

void ListClass::Delete(int indexDel){

    listNode *iterator = listArray[head];
    int indexDelArray = head;
    // Идем до удаляемого элемента
    for ( int i = 0; i < indexDel; i++ ){
        if ( iterator->nextNode == -1 ) return;
        indexDelArray = iterator->nextNode;
        iterator = listArray[iterator->nextNode];
    }

    //Если удаляемый элемент является головой
    if ( iterator == listArray[head] ) {
        if ( listArray[iterator->nextNode] != nullptr ) {
            holesQueue->Enqueue(indexDelArray);
            listArray[iterator->nextNode]->prevNode = -1;
            head = iterator->nextNode;
        }
        else // если он является и головой и хвостом ( 1 - элемент )
        {
            head = tail = -1;
        }
    }
    //Если удаляемый элемент является хвостом
    else if ( iterator == listArray[tail] ){
        listArray[iterator->prevNode]->nextNode = -1;
        tail = iterator->prevNode;
    }
    //Иначе удаляем из серединыстоит в середине
    else {
        listArray[iterator->prevNode]->nextNode = iterator->nextNode;
        listArray[iterator->nextNode]->prevNode = iterator->prevNode;
        holesQueue->Enqueue(indexDelArray);
    }
    delete iterator;
    listArray[indexDelArray] = nullptr;
}

int ListClass::GetIndex( int data ){
    if (head == -1)
        return -1;
    int indexInList = 0;
    listNode *iterator = listArray[head];
    // Идем до искомого элемента
    while( iterator->data != data ){
        iterator = listArray[iterator->nextNode];
        indexInList++;
        if ( iterator == nullptr ) return -1;
    }
    return indexInList;
}

void ListClass::Clear(){
    if (head == -1)
        return;

    listNode *iterator = listArray[head];
    while ( iterator->nextNode != -1 ) {
        iterator = listArray[iterator->nextNode];
        delete listArray[iterator->prevNode];
        iterator->prevNode == -1;
    }
    delete iterator;
    head = tail = -1;

}

void ListClass::PrintList() {
    if ( head == -1 )
        return;

    listNode *iterator =  listArray[head];
    while ( iterator->nextNode != -1 ) {
        std::cout << iterator->data << " --> ";
        iterator = listArray[iterator->nextNode];
    }
    std::cout << iterator->data << " --> ";
    std::cout << std::endl;
}