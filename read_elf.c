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
	printf("Magic:");
    for (i = 0; i < 4; ++i){
		print_text_char(elf32_ehdr.e_ident[i]);
	}
	printf("\n");


	close(fd);	
	return 0;
}
