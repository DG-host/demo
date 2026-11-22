#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

typedef struct item
{
    long arrive;
    int processtime;
} Item;   // 用户传入的存储类型

#define MAXQUEUE 10

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct _QUEUE_H_{
    Node * front;   /*指向队列首相的指针*/
    Node * rear;    /*指向队列尾项的指针*/
    int items;      /*队列的项数*/
} Queue;

void InitializeQueue(Queue * pq);

bool QueueIsFull(const Queue * pq);

bool QueueIsEmpty(const Queue * pq);

int QueueItemCount(const Queue * pq);


/*操作：    在队列末尾添加项*/
bool EnQueue(Item item, Queue * pq);

/*操作：    从队列开头删除项*/
bool DeQueue(Item *pitem, Queue * pq);

void EmptyTheQueue(Queue * pq);

#endif