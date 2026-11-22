/*list.h -- 简单链表类型的头文件*/
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>    /*C99特性*/

/*特定的程序声明*/

#define TSIZE   45  /*存储电影名的数组大小*/
struct film
{
    char title[TSIZE];
    int rating;
};

/*一些类型定义*/

typedef struct film Item;      

typedef struct node
{
    Item item;
    struct node * next;
}Node;

typedef Node * List;    // 定义指向Node类型指针的别名为List

 void InitializeList(List * plist);

 bool ListIsEmpty(const List *plist);

 bool ListIsFull(const List *plist);

 unsigned int ListItemCount(const List *plist);

 bool AddItem(Item item, List *plist);

 void Traverse(const List *plist, void(*pfun)(Item item));

 void EmptyTheList(List * plist);

 #endif
