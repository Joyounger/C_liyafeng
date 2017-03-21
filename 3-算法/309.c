#include <stdio.h>
#define MAX_SIZE 10000
#define KEY_SIZE 20

typedef struct hashtable
{
    char k[KEY_SIZE];
    char used;
    int count;
} hashtable;
hashtable table[MAX_SIZE];

unsigned int ELFhash(char* key, unsigned int size)
{
    unsigned int g = 0, h = 0;

    while (*key)
    {
        h = (h << 4) + *key++;
        g = h & 0xF0000000L;
        if (g)
        {
            h ^= g >> 24;
            h &= ~g;
        }
    }
    return h % size;
}

int main()
{
    char key[KEY_SIZE] = {0}, word[KEY_SIZE] = {0};
    unsigned int cnt = 0, n = 0, num = 0;
    unsigned int max = 0, hash = 0;

    scanf("%d", &n);
    num = n;
    while (n--)
    {
        scanf("%s", key);
        hash = ELFhash(key, MAX_SIZE);
collided:
        if (table[hash].used && strcmp(table[hash].k, key))
        {
            if (++cnt == num)
            {
                break;
            }
            hash = (++hash) % MAX_SIZE;
            goto collided;
        } else {
            ++(table[hash].count);
            strncpy(table[hash].k, key, KEY_SIZE - 1);
            table[hash].used = 1;
        }

        if (table[hash].count > max)
        {
            max = table[hash].count;
            strncpy(word, table[hash].k, KEY_SIZE - 1);
        }
        
    }

    printf("the most frequent word is %s!\n", word);

    return 0;
}