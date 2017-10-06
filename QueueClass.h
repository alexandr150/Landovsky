//
// Created by Alexandr on 06.10.2017.
//
#ifndef ALG_LAB1_V3_QUEUECLASS_H
#define ALG_LAB1_V3_QUEUECLASS_H

class QueueClass {
private:
    struct node{
        int q_value;
        node *q_next, *q_prev;
    };

    node* currentNode;

protected:
    void GetToLast();
    void GetToFirst();

public:
    QueueClass();
    ~QueueClass();

    void Enqueue(int);
    int Dequeue();
    bool isEmpty();
    int Front();
    void Clear();

};

#endif //ALG_LAB1_V3_QUEUECLASS_H
