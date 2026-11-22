#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct node{
    char *str;  // 存储扑克牌的字符
    struct node* next;
}Node;

typedef Node * List;    // 链表

void Initialize(List * head) {
    *head = NULL;
}

void CreateNode(Node *node, char *str)
{
    node->str = str;
    node->next = NULL;
}

void AddToList(List *head, char *str) // 添加到链表
{
    Node *pnew;
    Node *scan = *head;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr, "内存分配失败！\n");
        exit(1);
    }

    CreateNode(pnew, str);

    if (scan == NULL)
    {
        *head = pnew;
    }
    else
    {
        while(scan->next != NULL)
        {
            scan = scan->next;
        }
        scan->next = pnew;
    }
}

List CopyList(const List *head)
{
    List newHead = NULL;
    Node *scan = *head;
    while (scan != NULL)
    {
        AddToList(&newHead, scan->str);
        scan = scan->next;
    }
    return newHead;
}

void DoubleList(List *head) // 翻倍
{
    Node * scan = *head;
    Node * p = CopyList(head);
    while (scan->next != NULL)
    {
        scan = scan->next;
    }
    scan->next = p;
}

void TraverseList(List *head) // 遍历链表
{
    Node *scan = *head;
    while (scan != NULL)
    {
        printf("%s ", scan->str);
        scan = scan->next;
    }
    printf("\n");
}

void Insert(List *head, int n ,int pos)
{
    Node *scan = *head;
    Node *prev = NULL;
    int i;
    for (i=0; i<n && scan != NULL; i++) //找到需要移动的节点
    {
        prev = scan;
        scan = scan->next;
    }
    Node *newHead = scan;
    Node *newPrev = NULL;
    while (i<pos && scan != NULL)
    {
        newPrev = scan;
        scan = scan->next;  // 移动到指定位置
        i++;
    }
    prev->next = scan;
    newPrev->next = *head;
    *head = newHead;
}

void MoveToLast(List *head, int n) // 移动链表到最后
{
    if (n <= 0)
    {
        return;
    }
    Node *scan = *head;
    Node *prev = NULL;
    for (int i = 0; i < n && scan != NULL; i++)
    {
        prev = scan;
        scan = scan->next;
    }
    prev->next = NULL; // 断开链表
    Node *last = scan;
    while (last->next != NULL)  // 找到尾节点
    {
        last = last->next;
    }
    last->next = *head; // 接上尾节点
    *head = scan; 
}

char *DeleteNode(List *head, int n) // 删除前n个节点
{
    Node *scan = *head;
    Node *prev = NULL;
    char *str;
    for (int i = 0; i < n && scan != NULL; i++)
    {
        prev = scan;
        scan = scan->next;
        str = prev->str;
        free(prev);
    }
    *head = scan; // 更新头指针
    return str;
}

int main() {
    SetConsoleOutputCP(65001);  // 让控制台按 UTF-8 显示，避免中文乱码
    char * names[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    printf("随机生成4张扑克牌：\n");
    List cards;
    Initialize(&cards);
    srand(time(NULL));
    for (int i=0; i<4; i++)
    {
        int num = rand() % 13 + 1;  // 随机数[1, 13]
        // printf("\t%c\n", str);
        AddToList(&cards, names[num]);
    }
    TraverseList(&cards);

    printf("翻倍后的扑克牌：\n");
    DoubleList(&cards);
    TraverseList(&cards);

    printf("请输入你的名字字数：\n");
    int nameLength;
    scanf("%d", &nameLength);
    MoveToLast(&cards, nameLength);

    printf("当前扑克牌的顺序为：\n");
    TraverseList(&cards);
    printf("请输入你想要将前三张牌插入的位置(1-4):\n");
    int pos;
    scanf("%d", &pos);
    Insert(&cards, 3, pos+3);
    TraverseList(&cards);
    char *ans = DeleteNode(&cards, 1);


    printf("如果你是北方人，请输入1；如果你是南方人，请输入2；如果你不确定，请输入3：\n");
    int region;
    scanf("%d", &region);
    printf("当前扑克牌的顺序为：\n");
    TraverseList(&cards);
    printf("请输入你想要将前%d张牌插入的位置(1-%d):\n", region, 6-region);
    scanf("%d", &pos);
    Insert(&cards, region, pos+region);
    TraverseList(&cards);

    printf("如果你是男生，请输入1；如果你是女生，请输入2：\n");
    int gender;
    scanf("%d", &gender);
    DeleteNode(&cards, gender);
    TraverseList(&cards);

    char *str[7] = {"见", "证", "奇", "迹", "的", "时", "刻"};
    for (int i=0; i<7; i++)
    {
        printf("%s\n", str[i]);
        MoveToLast(&cards, 1);
        TraverseList(&cards);
        Sleep(1000);  // 暂停1秒
    }

    while (cards->next != NULL)
    {
        MoveToLast(&cards, 1);
        DeleteNode(&cards, 1);
        // printf("%c\n", str);
    }
    printf("最后一张牌是：%s\n", cards->str);
    printf("你藏起来的牌是: %s\n", ans);
    printf("奇迹发生了！\n");
    free(cards);
    system("pause");
    return 0;
}