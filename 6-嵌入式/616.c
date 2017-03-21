#include <stdio.h>

typedef struct Node
{
    char* data;
    struct Node *next;
} LINK;

int linkIsCircle(LINK *phead)
{
    LINK *p1, *p2;

    if (phead == NULL || phead -> next == NULL)
    {
        return 0;
    }
    if (phead == phead -> next)
    {
        return 1;
    }

    p1 = phead;
    p2 = phead->next;
    while (p1 != p2 && p2 != NULL && p2 -> next != NULL)
    {
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
    }
    if (p1 == p2)
    {
        return 1;
    } else {
        return 0;
    }

}

int main()
{
    LINK p, p1, p2, p3;

    p.next = &p1;
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p;
    
    if (linkIsCircle(&p))
    {
        printf("it is a circle!\n");
    } else {
        printf("it is not a circle!\n");
    }

    return 0;
}