#include <stdio.h>
#include "stack.h"
int main()
{
    Item temp=0;
    int ch;
    Stack st;
    InitializeStack(&st);
    puts("Type a to add value,");
    puts("type d to delete a value, and type q to quit");
    while ((ch = getchar()) != 'q')
    {
        if (ch != 'a' && ch != 'd')
            continue;
        if (ch == 'a')
        {
            printf("Integer to add: ");
            scanf("%d", &temp);
            if (!StackIsFull(&st))
            {
                printf("Putting %d into stack\n", temp);
                Add(&st, temp);
            }
            else{
                puts("Stack is full!");
            }
        }
        else{
            if (!StackIsEmpty(&st))
            {
                Delete(&st, &temp);
                printf("Removing %d from stack\n", temp);
            }
            else
            {
                puts("Nothing to delete!");
            }
        }
        printf("%d items in stack\n", CountStack(&st));
        puts("Type a to add, d to delete, q to quit:");
    }
    EmptyStack(&st);
    puts("Bye!");
    return 0;
}