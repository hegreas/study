
int main(int argc, char **argv)
{
    const char *test = "hello world";
    char const *test2;
    char * const test3 = test;

    test2 = malloc(10);

    printf("%s\n", test);
}
