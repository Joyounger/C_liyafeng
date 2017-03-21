#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu 
{
    char name[12];
    int ID;
    char major[8];
};

struct stu *allocNstu()
{
    struct stu *p;

    p = (struct stu *)malloc(sizeof(struct stu));
    if (NULL == p)
    {
        return NULL;
    } else {
        strcpy(p->name, "Mike");
        p->ID = 101;
        strcpy(p->major, "CS");
        return p;
    }
}

int main()
{
    struct stu *p;
    if ((p = allocNstu()) != NULL)
    {
        printf("$s\n", p -> name);
        printf("$d\n", p -> ID);
        printf("$s\n", p -> major);
    }

    free(p);
    
    return 0;
}
