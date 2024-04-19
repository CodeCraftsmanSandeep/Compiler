// This header contains functions to print one possible MIPS code, from the generated AST
// AST ---> MIPS code
#include <stdio.h>
#include <stdlib.h>

void print_labels(struct statement_node* trav){
    int print_count = 0;
    while(trav != NULL){
        if(trav->type == PRINT_STATEMENT){

            print_count++;
        }
        trav = trav->next;
        
    }
    return;
}


void print_main(struct statement_node* trav){
	while(trav != NULL ){
		switch(trav->type){
			case(BREAK_STATEMENT):
				// printf("%s", tabs);
				// printf("Break statement\n");
				break;

			case(CONTINUE_STATEMENT):
				// printf("%s", tabs);
				// printf("Continue statement\n");
				break;

			case(EXPRESSION):
				// printf("%s", tabs);
				// inorder(trav->expr_node);
				// printf("\n");
				break;
			
			case(PRINT_STATEMENT):
				// printf("%s", tabs);
				// printf("PRINT : ");
				// inorder(trav->expr_node);
				// printf("\n");
				break;
			
			case(READ_STATEMENT):
				// printf("%s", tabs);
				// printf("READ : ");
				// inorder(trav->expr_node);
				// printf("\n");
				break;
			
			case(IF_STATEMENT):
				// struct if_statement_node* if_node = trav->if_node;
				// printf("%s", tabs);
				// printf("IF\n");
				// printf("%s", tabs);
				// printf("Condition: "); 
				// inorder(if_node->condition); 
				// printf("\n");

				// print_root(if_node->true_block, strdup(tabs));
				// while(if_node->false_node != NULL){
				// 	if_node = if_node->false_node;
				// 	if(if_node->condition == NULL){
				// 		printf("%s", tabs);
				// 		printf("ELSE\n");
				// 	}else{
				// 		printf("%s", tabs);
				// 		printf("ELSE IF\n");
						
				// 		printf("%s", tabs);
				// 		printf("Condition: "); inorder(if_node->condition); printf("\n");
				// 	}					
				// 	print_root(if_node->true_block, strdup(tabs));
				// }

				break;

			case(FOR_STATEMENT):
				// printf("%s", tabs);
				// printf("For\n");

				// printf("%s", tabs);
				// printf("Expr1: "); inorder(trav->for_node->expr1); printf("\n");
				// printf("%s", tabs);
				// printf("Expr2: "); inorder(trav->for_node->expr2); printf("\n");
				// printf("%s", tabs);
				// printf("Expr3: "); inorder(trav->for_node->expr3); printf("\n");
				// print_root(trav->for_node->inside_block, strdup(tabs));
                break;
		}
		trav = trav->next;
	}
}

void code_generator(struct block* root, char* file_name){
    printf("-----MIPS code-----\n");
    printf("\t.file	1 \"%s\" \n", file_name); 
    printf("\t.section .mdebug.abi32\n");
	printf("\t.previous\n");
	printf("\t.nan	legacy\n");
	printf("\t.module	fp=xx\n");
	printf("\t.module	nooddspreg\n");
	printf("\t.abicalls \n");
    printf("\t.text\n");

    if(root == NULL){
        // no declarations, no body
        printf("NEED TO DO: MAIN CODE \n");
        printf("\n");
        printf("\t.set	macro\n");
        printf("\t.set	reorder\n");
        printf("\t.end	main\n");
        printf("\t.size	main, .-main\n");
        printf("\t.ident	\"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0\"\n");
        printf("\t.section	.note.GNU-stack,\"\",@progbits\n");
        return;
    }

	struct statement_node* trav = root->block_start;
    int decl_count = 0; // counts the number of declarations (global)

	while(trav != NULL && trav->type == DECLARATION){
        printf("\t.global ");
        printf("%s\n", trav->decl_node->name);
        if(decl_count == 0) printf("\t.section	.bss,\"aw\",@nobits\n");
        printf("\t.align	2\n");
        printf("\t.type	%s, @object\n", trav->decl_node->name);
        int size = sizeof(int);

        if(trav->decl_node->type == ARRAY) size = sizeof(int)*get_expression_value(trav->decl_node->size);

        printf("\t.size	%s, %d\n", trav->decl_node->name, size);
        printf("%s:\n",  trav->decl_node->name);
        printf("\t.size %d\n", size);
		trav = trav->next; 
        decl_count++;
	}

    // lets print a label for print statement
    printf("\t.rdata\n");
    printf("\t.align 2\n");
    printf("$LC0:\n");
    printf("\t.ascii \"%%d\\012\\000\" \n");

    // content for startig main
    printf("\t.text\n");
    printf("\t.align 2\n");
    printf("\t.global main\n");
    printf("\t.set nomips16\n");
    printf("\t.set nomicromips\n");
    printf("\t.ent main\n");
    printf("\t.type main, @function\n");
    printf("main:\n");

    print_main(trav);

    printf("\n");
    printf("\t.set	macro\n");
    printf("\t.set	reorder\n");
    printf("\t.end	main\n");
    printf("\t.size	main, .-main\n");
    printf("\t.ident	\"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0\"\n");
    printf("\t.section	.note.GNU-stack,\"\",@progbits\n");
    return;
}
