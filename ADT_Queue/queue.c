#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

static void CopyToNode(Item item, Node * pd);
static void CopyToItem(Node * pn, Item * pi);

void InitializeQueue(Queue * pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue * pq)
{
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue * pq)
{
    return pq->items == 0;
}

int QueueItemCount(const Queue * pq)
{
    return pq->items;
}

bool EnQueue(Item item, Queue * pq)
{
    Node * pnew;
    
    if (QueueIsFull(pq))
        return false;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (QueueIsEmpty(pq))
    {
        pq->front = pnew;   // 插入到队列的首项
    }
    else
        pq->rear->next = pnew;  // 插入到队列的尾项
    pq->rear = pnew;
    pq->items++;

    return true;
}

bool DeQueue(Item *pitem, Queue * pq)
{
    Node * pt;

    if (QueueIsEmpty(pq))
        return false;

    CopyToItem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;
    return true;
}

void EmptyTheQueue(Queue * pq)
{
    Item dummy;
    while (!QueueIsEmpty(pq))
    {
        DeQueue(&dummy, pq);
    }
}

/*局部函数*/
static void CopyToItem(Node * pn, Item * pi)
{
   *pi = pn->item;
}

static void CopyToNode(Item item, Node * pd)
{
    pd->item = item;
}