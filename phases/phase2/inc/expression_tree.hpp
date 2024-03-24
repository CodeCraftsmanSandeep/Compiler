


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

	switch(type){
		case(ARRAY_LOC):
			va_list args;
			va_start(args, type);
			curr->arr_ptr = (struct array_access*)malloc(sizeof(struct array_access));
			curr->arr_ptr->sym_ptr = va_arg(args, struct symbol_table*);
			curr->arr_ptr->index = va_arg(args, struct expression_node*);
			va_end(args);
			break;
		case(VAR):
			break;

		case(NUM):
			break;
		
		case(UNARY_MINUS):
			break;

		default:

	}

	return curr;
}

void inorder(struct expression_node* root){
	if(root == NULL) return;
	inorder(root->left);
	inorder(root->right);
	return;
}

