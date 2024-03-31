/*
#include <stdio.h>
#include <stdlib.h>

struct node{
	union {
		int data1;
		double data2;
	};
};

void function(int arg1, ){

}

int main(){
	int x = - - - - - 2;
	int y = + + + + 2;
	int z = - - + - 3;
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data1 = 2;
	printf("data =  %d\n", n->data1);
	
	n->data1 = 200;
	printf("data =  %d\n", n->data1);
		
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	return 0;
}
*/

#include <stdio.h>
#include <stdarg.h>

void my_function(int arg1, int arg2, ...) {
  va_list args;
   va_start(args, arg2);

    printf("arg1: %d\n", arg1);
    printf("arg2: %d\n", arg2);

 int arg3 = va_arg(args, int);
 printf("arg3: %d\n", arg3);

   va_end(args);
}

int main() {
//    my_function(1, 2, 3, 4, 5);
	int i = -1;
	printf("%d\n", i = 100);
	if(i = 1){
		printf("sandeep\n");
	}
	int a, b, c;
	// a + b = c;
	int arr[100];
	arr[1010];
	break;
    return 0;
}
