#include "list.h"

struct testStruct {
    int len;
	int msgType;
	char name[10];
	struct list_head ttList;
};

static struct list_head globalList;

int main(int argc, char** argv)
{
    struct list_head myList;
    INIT_LIST_HEAD(&globalList);

	struct testStruct study[6];

	for(int i=0; i<6; i++) {
		list_add_tail(&(study[i].ttList), &globalList);
	}

	strncpy(study[0].name, "abc", 4);
	strncpy(study[1].name, "kkk", 4);
	strncpy(study[2].name, "mmm", 4);
	strncpy(study[3].name, "sss", 4);
	strncpy(study[4].name, "ppp", 4);
	strncpy(study[5].name, "zzz", 4);

	struct testStruct* pMyStruct = list_first_entry(&globalList, struct testStruct, ttList);


	list_for_each_entry(pMyStruct, &globalList, ttList) {
    	printf("test program..., pMyStruct->name = %s\n", pMyStruct->name);
	}
}
