extern int lineno;
extern char error_string[];
extern void yyerror(char*);
#define max_entries 100
int curr_entries = 0;
extern void inorder(struct expression_node *);
struct symbol_table* head = NULL;

struct symbol_table* allot_entry(enum declaration_type type, char* name, struct indexes* sizes){
	struct symbol_table* curr = (struct symbol_table*)malloc(sizeof(struct symbol_table));
	curr->name = strdup(name);
	curr->type = type;
	int count = 0;
	struct indexes* trav = sizes;
	while(trav != NULL){
		count++;
		trav = trav->next;
	}
	curr->dimension = count;
	curr->sizes = sizes;
	curr->next = NULL;
	return curr;
}

struct symbol_table* insert_entry(enum declaration_type type, char* name, struct indexes* sizes){
	if(head == NULL){
		curr_entries++;
		head = allot_entry(type, name, sizes);
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
    prev->next = allot_entry(type, name, sizes);
    return prev->next;	
}

struct symbol_table* lookup(char* name, enum declaration_type type, ...){
	if(head == NULL){
		sprintf(error_string, "Compilation error: Varaible '%s' is not declared", name);
		yyerror(error_string);
	}
	struct symbol_table* prev = NULL;	
	struct symbol_table* trav = head;

	int d = 0;
	va_list args;
	va_start(args, type);
	if(type == ARRAY){
		struct indexes* indices = va_arg(args, struct indexes* );
		while(indices != NULL){
			d++;
			indices = indices->next;
		}
	}
	va_end(args);

    while(trav != NULL){
		if(strcmp(trav->name, name) == 0){
			if(trav->type != type){
				if(type == VARIABLE){
					sprintf(error_string, "Compilation error: '%s' is array not variable", name);
				}else{
					sprintf(error_string, "Compilation error: '%s' is variable not array", name);
				}
				yyerror(error_string);
			}else if(trav->dimension != d){
				sprintf(error_string, "Compilation error: dimension of '%s' is %d, not %d ", name, trav->dimension, d);
				yyerror(error_string);
			}
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
	printf("\n------Symbol table entries------\n");	
	struct symbol_table* trav = head;
	while(trav != NULL){
		
		if(trav->type == VARIABLE && trav->type_of_var == INT_datatype) printf("\tINT Variable '%s' ", trav->name);
		else if(trav->type == VARIABLE && trav->type_of_var == FLOAT_datatype) printf("\tFLOAT Variable '%s' ", trav->name);
		else if (trav->type_of_var == INT_datatype){
			printf("\tArray INT: %s (dimension = %d)\n", trav->name, trav->dimension);
			printf("\tSize: ");
			struct indexes* ptr = trav->sizes;
			while(ptr != NULL){
				inorder(ptr->index);
				ptr = ptr->next;
			}
		}else{
			printf("\tArray FLOAT: %s (dimension = %d)\n", trav->name, trav->dimension);
			printf("\tSize: ");
			struct indexes* ptr = trav->sizes;
			while(ptr != NULL){
				inorder(ptr->index);
				ptr = ptr->next;
			}
		}
		printf("\n");
		
		trav = trav->next;
	}
	printf("------End of symbol table entries------\n");
	return;
}