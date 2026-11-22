#include <stdio.h>
#include <string.h>
#include <stdlib.h> /*提供exit（）原型*/
#include "list.h"   /*定义List,Item*/
void showmovies(Item item);
char * s_gets(char * st, int n);
int main()
{
    List movies;
    Item temp;
    InitializeList(&movies);    //?
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available!Bye!\n");
        exit(1);
    }

    puts("Enter first movie title:");
    while(s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while(getchar() != '\n')
            continue;
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n"); // stderr是标准错误流，无缓冲区直接输出
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("This list is full!!!\n");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }

    if (ListIsEmpty(&movies))
    {
        printf("No data entered");
    }
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));

    EmptyTheList(&movies);
    printf("Bye!\n");
    return 0;
}

void showmovies(Item item)
{
    printf("Movie: %s Rating: %d\n", item.title, item.rating);
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // 查找换行符
        if (find)   // 如果地址不是NULL
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;            // 处理输入行的剩余内容
    }
    return ret_val;
}