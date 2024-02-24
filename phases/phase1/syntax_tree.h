#include <stdio.h>


struct syntax_tree_node{
	char* type;
	struct syntax_tree_node* left;
	struct syntax_tree_node* right;
};

struct syntax_tree_node* root = NULL; /* we cannot have same names ?? */

void inorder(struct syntax_tree_node* root){
	if(root == NULL) return;
	
	inorder(root->left);
	printf("%s\n", root->type);
	inorder(root->right);
	return;
}

struct syntax_tree_node* allot_syntax_tree_node(char* name){
	struct syntax_tree_node* curr = (struct syntax_tree_node*)malloc(sizeof(struct syntax_tree_node));
	curr->type = strdup(name);
	curr->left = NULL;
	curr->right = NULL;
	return curr;
}
