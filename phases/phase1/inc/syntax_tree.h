#include <stdio.h>


struct syntax_tree_node{
	int value;
	char* field;
	struct syntax_tree_node* left;
	struct syntax_tree_node* right;
};

struct syntax_tree_node* root = NULL; /* we cannot have same names ?? */

void inorder(struct syntax_tree_node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%s ", root->field);
	inorder(root->right);
	return;
}

struct syntax_tree_node* allot_syntax_tree_node(char* name, int value){
	struct syntax_tree_node* curr = (struct syntax_tree_node*)malloc(sizeof(struct syntax_tree_node));
	curr->field = strdup(name);
	curr->value = value;
	curr->left = NULL;
	curr->right = NULL;
	return curr;
}


struct node{
	char* type;
	struct node* sub_nodes;
	struct syntax_tree_node* root;
	struct node* next;
	struct node* prev;
};

struct node* seq_node_head = NULL;
struct node* seq_node_tail = NULL;

struct node* allot_sequence_node(char* type){
	struct node* curr = (struct node*)malloc(sizeof(struct node));
	curr->type = strdup(type);
	curr->sub_nodes = NULL;
	curr->root = NULL;
	curr->next = NULL;
	curr->prev = NULL;
	return curr;
}

void printSequence(){
	printf("\n--Start of sequence--\n");
	struct node* trav = seq_node_head;
	while(trav != NULL){
		printf("%s\n", trav->type);
		if(trav->sub_nodes != NULL){
			struct node* ptr = trav->sub_nodes;
			while(ptr->prev != NULL) ptr = ptr->prev;
			while(ptr != NULL){			
				printf("\t");	
				inorder(ptr->root);
				printf("\n");
				ptr = ptr->next;
			}
		}
		if(trav->root != NULL){
			printf("\t");
			inorder(trav->root);
			printf("\n");
		}
		trav = trav->next;
	}
	printf("--End of sequence--\n");
	return;
}

void put_in_sequence(char* statement){
	if(seq_node_head == NULL){
		seq_node_head = allot_sequence_node(statement);
		seq_node_tail = seq_node_head;
	}else{
		seq_node_tail->next = allot_sequence_node(statement);
		seq_node_tail = seq_node_tail->next;
	}
	return ;
}


