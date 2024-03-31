#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


extern void inorder(struct expression_node* root);

/*  A statemtent can be:
	DECLARATION, ASSIGN, EXPRESSION, IF_STATEMENT, FOR_STATEMENT
*/

struct if_statement_node{
	struct expression_node* condition;
	struct block* true_block;
	struct if_statement_node* false_node;
};
enum if_type{
	IF_TYPE,
	ELSE_IF_TYPE,
	ELSE_TYPE
};
struct if_statement_node* allot_if_statement_node(enum if_type type, struct block* true_block, ...){
	struct if_statement_node* curr = (struct if_statement_node*)malloc(sizeof(struct if_statement_node));
	curr->true_block = true_block;
	if(type != ELSE_TYPE){
		va_list args;
		va_start(args, true_block);
		curr->condition = va_arg(args, struct expression_node* );
		va_end(args);
	}else curr->condition = NULL;
	curr->false_node = NULL;
	return curr;
}

struct block{
	struct statement_node* block_start;
	struct statement_node* block_end;
	bool is_break;
	bool is_continue;
};
struct block* allot_block(){
	struct block* curr = (struct block*)malloc(sizeof(struct block));
	curr->block_start = NULL;
	curr->block_end = NULL;
	curr->is_break = false;
	curr->is_continue = false;
	return curr;
};

enum statement_type{
	DECLARATION,
	EXPRESSION,
	IF_STATEMENT,
	FOR_STATEMENT,
	BREAK_STATEMENT,
	CONTINUE_STATEMENT,
	PRINT_STATEMENT
};
struct statement_node{
	enum statement_type type;
	union{
		struct symbol_table* decl_node;			/* if declaration statememt, points to symbol_table entry */
		struct expression_node* expr_node;		/* expression (including assignment)*/
		struct if_statement_node* if_node;			/* if_sttement pointer  */
		struct for_statement* for_node; 		/* for_statement pointer */
	};
	struct statement_node* next;
	struct statement_node* prev;
};

struct for_statement{
	// expression ; expression ; expression
	// note: an expression can be assignment (as in C/C++)
	struct expression_node* expr1;
	struct expression_node* expr2;
	struct expression_node* expr3;

	struct block* inside_block;
};

struct statement_node* allot_statement(enum statement_type type, ...){
	struct statement_node* curr = (struct statement_node*) malloc(sizeof(struct statement_node));
	curr->type = type;
	if(type == DECLARATION){
		va_list args;
		va_start(args, type);
		enum declaration_type decl_type = va_arg(args, enum declaration_type);
		char* name = va_arg(args, char*);
		if(decl_type == VARIABLE){
			curr->decl_node = insert_entry(decl_type, name, 1); /* symbol table */
		}else if(decl_type == ARRAY){
			int size = va_arg(args, int);
			curr->decl_node = insert_entry(decl_type, name, size);
		}
		va_end(args);
	}else if(type == EXPRESSION){
		va_list args;
		va_start(args, type);
		curr->expr_node = va_arg(args, struct expression_node* );
		va_end(args);
	}else if(type == IF_STATEMENT){
		va_list args;
		va_start(args, type);
		struct block* true_block = va_arg(args, struct block*);
		struct expression_node* condition = va_arg(args, struct expression_node*);
		curr->if_node  = allot_if_statement_node(IF_TYPE, true_block, condition);
		va_end(args);
	}else if(type == FOR_STATEMENT){
		struct for_statement* for_node = (struct for_statement*)malloc(sizeof(struct for_statement));
		va_list args;
		va_start(args, type);
		for_node->expr1 = va_arg(args, struct expression_node* );
		for_node->expr2 = va_arg(args, struct expression_node* );
		for_node->expr3 = va_arg(args, struct expression_node* );
		for_node->inside_block = va_arg(args, struct block* );
		va_end(args);

		curr->for_node = for_node;
	}else if(type == PRINT_STATEMENT){
		va_list args;
		va_start(args, type);
		curr->expr_node = va_arg(args, struct expression_node* );
		va_end(args);
	}

	curr->next = NULL;
	curr->prev = NULL;
	return curr;
}

void print_root(struct block* root, char* tabs){
	if(root == NULL){
		printf("%s", tabs);
		printf("Body\n");
		printf("%s", tabs);
		printf("\tEmpty\n");
		return;
	}
	struct statement_node* trav = root->block_start;
	if(trav->type == DECLARATION){
		printf("Declaration\n");
	}

	while(trav != NULL && trav->type == DECLARATION){
		if(trav->decl_node->type == ARRAY){
			printf("\tArray		: %s (size = %d)\n", trav->decl_node->name, trav->decl_node->size);
		}else if(trav->decl_node->type == VARIABLE){
			printf("\tVariable	: %s\n", trav->decl_node->name);
		}
		trav = trav->next;
	}
	if(trav == NULL) return;
	printf("%s", tabs);
	printf("Body\n");

	tabs = realloc(tabs, (strlen(tabs) + 2)*sizeof(char));
	strcat(tabs, "\t");
	// return;
	while(trav != NULL ){
		switch(trav->type){
			case(BREAK_STATEMENT):
				printf("%s", tabs);
				printf("Break statement\n");
				break;

			case(CONTINUE_STATEMENT):
				printf("%s", tabs);
				printf("Continue statement\n");
				break;

			case(EXPRESSION):
				printf("%s", tabs);
				inorder(trav->expr_node);
				printf("\n");
				break;
			
			case(PRINT_STATEMENT):
				printf("%s", tabs);
				printf("PRINT : ");
				inorder(trav->expr_node);
				printf("\n");
				break;
			
			case(IF_STATEMENT):
				struct if_statement_node* if_node = trav->if_node;
				printf("%s", tabs);
				printf("IF\n");
				printf("%s", tabs);
				printf("Condition: "); 
				inorder(if_node->condition); 
				printf("\n");

				print_root(if_node->true_block, strdup(tabs));
				while(if_node->false_node != NULL){
					if_node = if_node->false_node;
					if(if_node->condition == NULL){
						printf("%s", tabs);
						printf("ELSE\n");
					}else{
						printf("%s", tabs);
						printf("ELSE IF\n");
						
						printf("%s", tabs);
						printf("Condition: "); inorder(if_node->condition); printf("\n");
					}					
					print_root(if_node->true_block, strdup(tabs));
				}
				break;

			case(FOR_STATEMENT):
				printf("%s", tabs);
				printf("For\n");

				printf("%s", tabs);
				printf("Expr1: "); inorder(trav->for_node->expr1); printf("\n");
				printf("%s", tabs);
				printf("Expr2: "); inorder(trav->for_node->expr2); printf("\n");
				printf("%s", tabs);
				printf("Expr3: "); inorder(trav->for_node->expr3); printf("\n");
				print_root(trav->for_node->inside_block, strdup(tabs));
				break;
		}
		trav = trav->next;
	}
}
// add break statement
// how to allow emptt body in if statements
// allowing empty in for