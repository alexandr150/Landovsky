//
// Created by Alexandr on 06.10.2017.
//

#include <cstdio>
#include "QueueClass.h"

QueueClass::QueueClass(){
    currentNode = NULL;
}

QueueClass::~QueueClass(){
}

void QueueClass::Enqueue(int toAdd){

    node *newNode = new node;
    newNode->q_value = toAdd;
    newNode->q_prev = NULL;

    if (isEmpty()) {
        newNode->q_next = NULL;


    } else {
        GetToLast();
        newNode->q_next = currentNode;
        currentNode->q_prev = newNode;
    }

    currentNode = newNode;
}

int QueueClass::Dequeue(){

    GetToFirst();
    int toReturn = currentNode->q_value;

    if (currentNode->q_prev == currentNode->q_next){
        currentNode = NULL;
    } else {
        currentNode = currentNode->q_prev;
        delete currentNode->q_next;
        currentNode->q_next = NULL; //Вот это хз надо ли
    }
    return toReturn;
}

bool QueueClass::isEmpty(){
    return (currentNode == NULL);
}

int QueueClass::Front(){
    GetToFirst();
    return currentNode->q_value;
}

void QueueClass::Clear(){
    if (this->isEmpty())
        return;

    GetToLast();
    while (currentNode->q_next != NULL){
        currentNode = currentNode->q_next;
        delete(currentNode->q_prev);
    }
    delete(currentNode);
    currentNode = NULL;
}

void QueueClass::GetToLast(){
    if (this->isEmpty())
        return;

    while (currentNode->q_prev != NULL)
        currentNode = currentNode->q_prev;
}

//Переносит указатель *currentNode на крайний справа элемент
void QueueClass::GetToFirst(){
    if (this->isEmpty())
        return;

    while (currentNode->q_next != NULL)
        currentNode = currentNode->q_next;
}

