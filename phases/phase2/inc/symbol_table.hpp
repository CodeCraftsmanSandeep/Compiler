/*
#ifndef  STDIO_INCLUDE

#define STDIO_INCLUDE
#include <stdio.h>
#include <string.h>

#endif

*/

extern int lineno;
extern char error_string[];
extern void yyerror(char*);
#define max_entries 100
int curr_entries = 0;

enum class declaration_type{
	VARIABLE,
	ARRAY
};
struct symbol_table{
    char* name;
	enum declaration_type type;
	int size;
    bool isInitialized;
    struct symbol_table* next;
};
struct symbol_table* head = NULL;

struct symbol_table* allot_entry(enum declaration_type type, char* name, int size){
	struct symbol_table* curr = (struct symbol_table*)malloc(sizeof(struct symbol_table));
	curr->name = strdup(name);

	/* a variable has size 1 */
	curr->size = size;

	curr->isInitialized = false;
	curr->next = NULL;
	return curr;
}

struct symbol_table* insert_entry(enum declaration_type type, char* name, int size){
	if(head == NULL){
		curr_entries++;
		head = allot_entry(type, name, size);
		return head;
	}
	struct symbol_table* prev = NULL;
	struct symbol_table* trav = head; // traversal pointer

    while(trav != NULL){
		if(strcmp(trav->name, name) == 0){
			sprintf(error_string, "Compilation error: '%s' is already declared", name);
			yyerror(error_string);
		}
		prev = trav;
		trav = trav->next;
    }
    if(curr_entries == max_entries){
		yyerror("Maximum limit crossed in symbol_table");
    }
    curr_entries++;
    prev->next = allot_entry(type, name, size);
    return prev->next;	
}	

// struct symbol_table* lookup(char* name){
// 	if(head == NULL){
// 		sprintf(error_string, "Compilation error: Varaible '%s' is not declared", name);
// 		yyerror(error_string);
// 	}
// 	struct symbol_table* prev = NULL;	
// 	struct symbol_table* trav = head; // traversal pointer

//     while(trav != NULL){
// 		if(strcmp(trav->name, name) == 0){
// 			return trav;
// 		}
// 		prev = trav;
// 		trav = trav->next;
//     }

// 	sprintf(error_string, "Compilation error: Varaible '%s' is not declared", name);
//     yyerror(error_string);
// }


// void printSymbolTable(){
// 	if(head == NULL){
// 		printf("\nEmpty symbol table\n");
// 		return ;
// 	}
// 	printf("\n--Symbol table entries--\n");	
// 	struct symbol_table* trav = head;
// 	while(trav != NULL){
// 		if(!trav->isInitialized)	printf("varaible '%s': Unintialized\n", trav->name);
// 		else if(trav->type == declaration_type::VARIABLE) printf("Variable '%s'\n", trav->name);
// 		else{
// 			printf("Array '%s'of size %d\n", trav->name, trav->size);
// 		}
// 		trav = trav->next;
// 	}
// 	printf("--End of symbol table entries--\n");
// 	return;
// }

// Before test 2 you have to complete assignment 3
// how to support context sensitive lanagauge ????????
// test2 will be extension of project till assginement 3
// after completetion extended to add datatypes in symbol table. (i.e using c++ templates )