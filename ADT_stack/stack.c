#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

static Node * CopyToNode(Item item);

void InitializeStack(Stack * st)
{
    st->bottom = st->top = NULL;
    st->items = 0;
}

bool StackIsFull(const Stack * st)
{
    return st->items == MAXIMUM;
}

bool StackIsEmpty(const Stack * st)
{
    return st->items == 0;
}

bool Add(Stack * st, Item item)
{
    if (StackIsFull(st))
    {
        return false;
    }

    Node * pnew;
    pnew = CopyToNode(item);    // 创造了一个pnew节点
    pnew->upper = NULL;
    if (StackIsEmpty(st))
    {
        st->bottom = pnew;
        st->top = pnew;
        pnew->lower = NULL;
    }
    else{
        pnew->lower = st->top;
        st->top = pnew;
    }
    st->items++;
    return true;
}

bool Delete(Stack * st, Item * item)
{
    Node * dn;    // 待删除结点

    if (StackIsEmpty(st))
    {
        printf("The stack is empty!\n");
        return false;
    }
    dn = st->top;
    *item = dn->temp;   // 取出操作
    st->top = dn->lower;
    free(dn);
    st->items--;
    return true;
}

int CountStack(const Stack * st)
{
    return st->items;
}

void EmptyStack(Stack * st)
{
    while (!StackIsEmpty(st))
    {
        Item nd;
        Delete(st, &nd);
    }
}

static Node * CopyToNode(Item item)
{
    Node * pnew;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr, "No memory to allocate!\n");
        exit(1);
    }
    pnew->temp = item;
    pnew->lower = pnew->upper = NULL;
    return pnew;
}