/*
#ifndef  STDIO_INCLUDE

#define STDIO_INCLUDE
#include <stdio.h>
#include <string.h>

#endif

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

extern int lineno;
extern char error_string[];
extern void yyerror(char*);
#define max_entries 100
int curr_entries = 0;

struct symbol_table{
    char* name;
    int value;
    bool isInitialized;
    struct symbol_table* next;
};
struct symbol_table* head = NULL;

struct symbol_table* allot_entry(char* name){
	struct symbol_table* curr = (struct symbol_table*)malloc(sizeof(struct symbol_table));
	curr->name = strdup(name);
	curr->value = 0;
	curr->isInitialized = false;
	curr->next = NULL;
	return curr;
}

struct symbol_table* declare_variable(char* name){
	if(head == NULL){
		curr_entries++;
		head = allot_entry(name);
		return head;
	}
	struct symbol_table* prev = NULL;
	struct symbol_table* trav = head; // traversal pointer
    	
    while(trav != NULL){
		if(strcmp(trav->name, name) == 0){
			sprintf(error_string, "Compilation error: Varaible '%s' is already declared", name);
			yyerror(error_string);
		}
		prev = trav;
		trav = trav->next;
    }
    if(curr_entries == max_entries){
    	yyerror("Maximum limit crossed in symbol_table");
    }
    curr_entries++;
    prev->next = allot_entry(name);
    return prev->next;	
	
}	


struct symbol_table* lookup(char* name){
	if(head == NULL){
		sprintf(error_string, "Compilation error: Varaible '%s' is not declared", name);
		yyerror(error_string);
	}
	struct symbol_table* prev = NULL;	
	struct symbol_table* trav = head; // traversal pointer
    	
    while(trav != NULL){
		if(strcmp(trav->name, name) == 0){
			return trav;
		}
		prev = trav;
		trav = trav->next;
    }

     sprintf(error_string, "Compilation error: Varaible '%s' is not declared", name);
     yyerror(error_string);
}


void printSymbolTable(){
	if(head == NULL){
		printf("\nEmpty symbol table\n");
		return ;
	}
	printf("\n--Symbol table entries--\n");	
	struct symbol_table* trav = head;
	while(trav != NULL){
		if(!trav->isInitialized)	printf("varaible '%s': Unintialized\n", trav->name);
		else printf("variable '%s': %d\n", trav->name, trav->value);
		trav = trav->next;
	}
	printf("--End of symbol table entries--\n");
	return;
}

