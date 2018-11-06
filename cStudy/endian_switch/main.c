struct student {
	char name[5];
	short age;
	int score;
	char flag;
};

int main(int argc, char **argv)
{
    printf("sizeof student : %d\n", sizeof(struct student));

	struct student my_stu;

	memcpy(my_stu.name, "chehongfeng", sizeof(my_stu.name));
	my_stu.age = 0x1122;
	my_stu.score = 0xaabbccdd;
	my_stu.flag = 0xf;

	for(int i=0; i<sizeof(struct student); i++) {
		printf("0x%02x, ", ((char*)(&my_stu))[i]);
		if((i+1)%10 == 0) {
			printf("\n");
		}
	}

	printf("\n");
	my_stu.age = htons(my_stu.age);
	my_stu.score = htonl(my_stu.score);

	for(int i=0; i<sizeof(struct student); i++) {
		printf("0x%02x, ", ((char*)(&my_stu))[i]);
		if((i+1)%10 == 0) {
			printf("\n");
		}
	}
}
