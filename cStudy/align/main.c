
struct student {
	char name;
	int age;
	char des[10];
//}__attribute__((aligned(1)));
}__attribute__((packed));

int main(int argc, char **argv)
{
    printf("length of student : %d\n", sizeof(struct student));
}
