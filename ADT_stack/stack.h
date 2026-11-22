
#define MAXIMUM 10
#include <stdbool.h>

typedef int Item;
typedef struct node
{
    /* data */
    Item temp;
    struct node * lower;
    struct node * upper;

} Node;


typedef struct stack
{
    Node * top; // 栈顶
    Node * bottom;  // 栈底
    int items;
} Stack;

/*函数：初始化一个栈*/
void InitializeStack(Stack * st);

/*函数：加入一个元素*/
/*效果：添加成功返回true， 否则返回false*/
bool Add(Stack * st, Item item);

/*函数：删除一个元素*/
/*效果：删除一个元素并取出*/
bool Delete(Stack * st, Item * item);

/*函数：统计栈中元素个数*/
int CountStack(const Stack * st);

/*Function: To judge the stack whether is fiiled or not*/
bool StackIsFull(const Stack * st);

/*Function: To judge the stack whether is empty or not*/
bool StackIsEmpty(const Stack * st);

/*Function: To clear the stack*/
void EmptyStack(Stack * st);




