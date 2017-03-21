int main()
{
    char *p = "abcde\0f";
    char a[] = "abcde\0f";

    printf("%2d", strlen(p));
    printf("%2d", sizeof(p));
    printf("%2d", strlen(a));
    printf("%2d", sizeof(a));

    return 0;
}

