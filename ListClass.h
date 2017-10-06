//
// Created by Alexandr on 06.10.2017.
//

#include "QueueClass.h"

#ifndef ALG_LAB1_V3_LISTCLASS_H
#define ALG_LAB1_V3_LISTCLASS_H

class ListClass {

private:

    struct listNode{
        int data, nextNode, prevNode;
    };
    listNode **listArray;
    int head, tail;
    QueueClass *holesQueue;

public:
    ListClass();
    ~ListClass();
    void Add(int data);
    void Delete(int index);
    void Clear();
    int GetIndex(int data);
    void PrintList();





};

#endif //ALG_LAB1_V3_LISTCLASS_H