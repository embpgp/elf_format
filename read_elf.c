#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "data_struct.h"

void print_text_char(char ch)
{
	if (ch >= ' ' && ch <= '~'){
		printf("%c", ch);
	}else{
		printf(".");
	}
}


int parser_elf_header(Elf32_Ehdr *elf32_ehdr)
{
	int i = 0;
	if (elf32_ehdr == NULL){
		return -1;
	}
	if (!elf32_ehdr->e_ident[4]){
		printf("illegal elf file\n");
		return -1;
	}
	if (!elf32_ehdr->e_ident[5]){
		printf("illegal elf file\n");
	}	
	printf("Magic:");
    for (i = 0; i < 4; ++i){
        print_text_char(elf32_ehdr->e_ident[i]);
    }
 	printf("\n");
	printf("Obj :%d\n", elf32_ehdr->e_ident[4] == 1? 32:64);
	printf("Data:%s\n", elf32_ehdr->e_ident[5] == 1? "LSB":"MSB");
	printf("type:%d\nmachine:%d\nversion:%d\nentry:%p\nphoff:%u\nshoff:%u\nflags:%d\nehsize:%d\nphentsize:%d\nphnum:%d\nshentsize:%d\nshnum:%d\nshstrndx:%d\n",
			elf32_ehdr->e_type,
			elf32_ehdr->e_machine,
			elf32_ehdr->e_version,
			elf32_ehdr->e_entry,
			elf32_ehdr->e_phoff,
			elf32_ehdr->e_shoff,
			elf32_ehdr->e_flags,
			elf32_ehdr->e_ehsize,
			elf32_ehdr->e_phentsize,
			elf32_ehdr->e_phnum,
			elf32_ehdr->e_shentsize,
			elf32_ehdr->e_shnum,
			elf32_ehdr->e_shstrndx);
	return 0;
	
}

int main(int argc, char **argv)
{
	Elf32_Ehdr elf32_ehdr = {0};
	int ret = -1;
	int fd = -1;
	int i = 0;
	if (argv[1] == NULL){
		printf("Please input like %s filename\n", argv[0]);
		exit(-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1){
		perror("error for open file");
		exit(-1);
	}
	if ((ret = read(fd, &elf32_ehdr, sizeof(elf32_ehdr))) == -1){
		perror("error for read file");
		close(fd);
		exit(-1);
	}
	
	if (0 != parser_elf_header(&elf32_ehdr)){
		printf("bad elf file\n");
	}
	close(fd);	
	return 0;
}
