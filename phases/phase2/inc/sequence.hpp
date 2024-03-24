

// extern void inorder(struct syntax_tree_node* root);

/*  A statemtent can be:
	DECLARATION, ASSIGN, EXPRESSION, IF_STATEMENT, FOR_STATEMENT
*/

enum statement_type{
	DECLARATION,
	EXPRESSION,
	IF_STATEMENT,
	FOR_STATEMENT,
	BREAK_STATEMENT,
	CONTINUE_STATEMENT,
	PRINT_STATMENT
};
struct statement_node{
	enum statement_type type;
	union{
		struct symbol_table* decl_node;			/* if declaration statememt, points to symbol_table entry */
		struct expression_node* expr_node;		/* expression (including assignment)*/
		struct if_statement* if_node;			/* if_sttement pointer  */
		struct for_statement* for_node; 		/* for_statement pointer */
	};
	struct statement_node* next;
	struct statement_node* prev;
};
struct block{
	struct statement_node* block_start;
	struct statement_node* block_end;
};

struct block* allot_block(){
	struct block* curr = (struct block*)malloc(sizeof(struct block));
	curr->block_start = NULL;
	curr->block_end = NULL;
	return curr;
};

enum class if_type{
	IF,
	ELSE_IF,
	ELSE,
	NO_SIBLING
};
struct if_statement{
	struct expression_node* condition;
	struct block* inside_block;
	enum if_type type;
	enum if_type sibling;

	union{
		struct if_statement* else_if_node;
		struct if_statement* else_node; 		// for else condition is NULL
	};
};

struct for_statement{
	// expression ; expression ; expression
	// note: an expression can be assignment (as in C/C++)
	struct syntax_tree_node* expr1;
	struct syntax_tree_node* expr2;
	struct syntax_tree_node* expr3;


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
			insert_entry(decl_type, name, 1);
		}else if(decl_type == ARRAY){
			int size = va_arg(args, int);
			insert_entry(decl_type, name, size);
		}
		va_end(args);
	}else if(type == EXPRESSION){
		va_list args;
		va_start(args, type);
		curr->expr_node = va_arg(args, struct expression_node* );
		va_end(args);
	}else if(type == IF_STATEMENT){
		struct if_statement* if_node = (struct if_statement*)malloc(sizeof(struct if_statement));
		if_node->condition = NULL;
		if_node->inside_block = NULL;
		if_node->type = IF_TYPE;
		if_node->sibling = NO_SIBLING;
		curr->if_node = if_node;
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
	}

	curr->next = NULL;
	curr->prev = NULL;
	return curr;
}

// add break statement