#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
typedef unsigned char* Elf32_Addr;
typedef unsigned short Elf32_Half;
typedef unsigned int   Elf32_Off;
typedef signed int     Elf32_SWord;
typedef unsigned int   Elf32_Word;

#define EI_NIDENT 16
typedef struct{
	unsigned char e_ident[EI_NIDENT];
	Elf32_Half 	  e_type;
	Elf32_Half 	  e_machine;
	Elf32_Word	  e_version;
	Elf32_Addr 	  e_entry;
	Elf32_Off	  e_phoff;
	Elf32_Off	  e_shoff;
	Elf32_Word	  e_flags;
	Elf32_Half	  e_ehsize;
	Elf32_Half	  e_phentsize;
	Elf32_Half	  e_phnum;
	Elf32_Half	  e_shentsize;
	Elf32_Half	  e_shnum;
	Elf32_Half	  e_shstrndx;
}Elf32_Ehdr; 




#endif
