#include <stdio.h>
#include <stdlib.h>
#define DATA_MAX_LEN 1024
#define SEED_MAX_LEN 64
#define SBOX_LEN 256

#define swap_byte(x, y) char t; t = *(x); *(x) = *(y); *(y) = t;

void prepare_key(unsigned char *key_seed_ptr, int key_seed_len,
                                unsigned char *kstate)
{
    unsigned char index1 = 0, index2 = 0;
    short counter;

    for (counter = 0; counter < SBOX_LEN; counter++)
    {
        kstate[counter] = counter;
    }
    for (counter = 0; counter < SBOX_LEN; counter++)
    {
        index2 = (key_seed_ptr[index1] + kstate[counter] + index2) % SBOX_LEN;
        swap_byte(&kstate[counter], &kstate[index2]);
        index1 = (index1 + 1) % key_seed_len;
    }
}

void rc4(unsigned char *data_ptr, int data_len, unsigned char *kstate)
{
    unsigned char x = 0, y = 0, xorIndex = 0;
    short counter;
    
    for (counter = 0; counter < data_len; counter++)
    {
        x = (x + 1) % SBOX_LEN;
        y = (kstate[x] + y) % SBOX_LEN;
        swap_byte(&kstate[x], &kstate[y]);
        xorIndex = (kstate[x] + kstate[y]) % SBOX_LEN;
        data_ptr[counter] ^= kstate[xorIndex];
    }
}

int main()
{
    unsigned char seed[SEED_MAX_LEN] = "password";
    unsigned char data[SEED_MAX_LEN] = "This is a plaintext!";
    unsigned char *p = data; //keyState[SBOX_LEN];
    unsigned char keyState[SBOX_LEN];
    int n, i = 0;

    printf("Key seed: %s\n", seed);
    printf("Plainext: %s\n", data);
    n = strlen(data);
    prepare_key(seed, strlen(seed), keyState);
    rc4(p, n, keyState);
    printf("Ciphertext:");
    while(i < n)
            printf(" %02X", p[i++]);

    return 0;
}

