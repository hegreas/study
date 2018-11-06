#include <stdio.h>
#include <libelf.h>
#include <gelf.h>
#include <sys/stat.h>
#include <fcntl.h>

void test(int i)
{
	printf(" call test with i: %d\n", i);
}

int main(int argc, char** argv)
{
	Elf        *elf = NULL;
	Elf_Scn    *scn = NULL;
	GElf_Shdr  shdr;
	Elf_Data   *data = NULL;
	int fd, ii, count;

	void (*test_func)(int);

	elf_version(EV_CURRENT);
	fd = open(argv[0], O_RDONLY);
	elf = elf_begin(fd, ELF_C_READ, NULL);
	while((scn = elf_nextscn(elf, scn)) != NULL) {
		gelf_getshdr(scn, &shdr);
		if(shdr.sh_type == SHT_SYMTAB) {
			break;
		}
	}
	data = elf_getdata(scn, NULL);
	count = shdr.sh_size / shdr.sh_entsize;

	for(ii = 0; ii < count; ++ii) {
		GElf_Sym sym;
		gelf_getsym(data, ii, &sym);
		if(strcmp("test", elf_strptr(elf, shdr.sh_link, sym.st_name)))
			continue;
		test_func = (void(*)(int))(sym.st_value);
		test_func(255);
		break;
	}
	elf_end(elf);
	close(fd);

	return 0;
}
