
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


enum  expression_node_type{
	VAR,
	ARRAY_LOC,
	NUM,
	UNARY_MINUS,
	PLUS,  /* add operator */
	MINUS,
	MUL,
	DIV,
	MOD,
	GT,
	LT,
	GTEQ,
	LTEQ,
	EQEQ, 		/* '==' is equal to  */
	NTEQ,  		/* !=  is not equal to */
	ASSIGN,	 	/* '=' assignment */
	POST_INCREMENT,		
	POST_DECREMENT,		
	PRE_INCREMENT,		
	PRE_DECREMENT		
};
enum  declaration_type{
	VARIABLE,
	ARRAY
};
struct symbol_table{
    char* name;
	enum declaration_type type;
	struct expression_node* size;
    bool isInitialized;
    struct symbol_table* next;
};



struct array_access{
	struct symbol_table* sym_ptr; 
	struct expression_node* index;
};

struct expression_node{
	enum expression_node_type type;
	union{
		int number_value;
		struct array_access* arr_ptr;
		struct symbol_table* var_ptr;
	};

	struct expression_node* left;
	struct expression_node* right;
};

struct expression_node* allot_expression_node(enum expression_node_type type, ...){
	struct expression_node* curr = (struct expression_node*)malloc(sizeof(struct expression_node));
	curr->type = type;
	curr->left = NULL;
	curr->right = NULL;
	va_list args;
	va_start(args, type);
	switch(type){
		case(ARRAY_LOC):
			curr->arr_ptr = (struct array_access*)malloc(sizeof(struct array_access));
			curr->arr_ptr->sym_ptr = va_arg(args, struct symbol_table*);
			curr->arr_ptr->index = va_arg(args, struct expression_node*);
			break;

		case(VAR):
			curr->var_ptr = va_arg(args, struct symbol_table*);
			break;

		case(NUM):
			curr->number_value = va_arg(args, int);
			break;

		case(UNARY_MINUS):
		case(POST_INCREMENT):
		case(POST_DECREMENT):
		case(PRE_INCREMENT):
		case(PRE_DECREMENT):
			/* storing expression as right child */
			curr->right = va_arg(args, struct expression_node*);
			break;

		default:
			// binary operators
			curr->left = va_arg(args, struct expression_node*);
			curr->right = va_arg(args, struct expression_node*);
	}
	va_end(args);

	return curr;
}

void inorder(struct expression_node* root){
	if(root == NULL) return;

	switch(root->type){
		case(VAR):
			printf(" %s ", root->var_ptr->name);
			break;
		case(ARRAY_LOC):
			printf(" (%s[", root->arr_ptr->sym_ptr->name);
			inorder(root->arr_ptr->index);
			printf("]) " );
			break;
		case(NUM):
			printf(" %d ", root->number_value);
			break;
		case(UNARY_MINUS):
			/* storing expression as right child */
			printf("(Unary_minus ");
			inorder(root->right);
			printf(") ");
			break;
		case (POST_INCREMENT):
			printf("(");
			inorder(root->right);
			printf("Post_increment) ");
			break;

		case (POST_DECREMENT):
			printf("(");
			inorder(root->right);
			printf("Post_decrement) ");
			break;
		
		case (PRE_INCREMENT):
			printf("(Pre_increment");
			inorder(root->right);
			printf(") ");
			break;

		case (PRE_DECREMENT):
			printf("(Pre_decrement");
			inorder(root->right);
			printf(") ");
			break;

		default:
			printf("(");
			inorder(root->left);
			printf(")");
			switch(root->type){
				case(PLUS):
					printf(" Add ");
					break;
				case(MINUS):
					printf(" Sub ");
					break;
				case(MUL):
					printf(" Mul ");
					break;
				case(DIV):
					printf(" Div ");
					break;
				case(GT):
					printf(" Greater_than ");
					break;
				case(GTEQ):
					printf(" Greater_then_or_equal_to ");
					break;
				case(LT):
					printf(" Less_than ");
					break;
				case(LTEQ):
					printf(" Less_than_or_equal_to ");
					break;
				case(EQEQ):
					printf(" Is_equal ");
					break;
				case(NTEQ):
					printf(" Is_not_equal ");
					break;
				case(ASSIGN):
					printf(" Assign ");
					break;
			}
			printf("(");
			inorder(root->right);
			printf(")");
	}
	return;
}