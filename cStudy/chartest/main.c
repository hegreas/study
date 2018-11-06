
int main(int argc, char **argv)
{
//    char hello[] = "hello world";

//	printf("test : %s\n", hello);
    char hello[20];

	memset(hello, 0, sizeof(hello));
    memcpy(hello, "hello world", sizeof("hello world"));
}
