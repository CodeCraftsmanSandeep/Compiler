#include <bits/stdc++.h>
#include <cstdarg>
#include <cstdlib>
using namespace std;

struct node{
	int num;
	int a;
};

int func(int num, ...){
	va_list args;
	va_start(args, num);
	if(num  == 1){
		int arg3 = va_arg(args, int);
		printf("%d\n", arg3);
	}else{
		 struct node* arg3 = va_arg(args, struct node*);
		 
		printf("%d\n", arg3->num);
	}
	va_end(args);
	return 1;
}



int main(){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->num = 109;
	temp->a = 10000;
	
	func(1, 2);
	func(2, temp);
	
}	
