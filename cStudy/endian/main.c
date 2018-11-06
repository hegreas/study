union u_test {
	short tt;
	char aa;
};

int main(int argc, char **argv)
{
	union u_test myTest;

	myTest.tt = 0x1122;

	printf("myTest.aa = 0x%02x\n", myTest.aa);

}
