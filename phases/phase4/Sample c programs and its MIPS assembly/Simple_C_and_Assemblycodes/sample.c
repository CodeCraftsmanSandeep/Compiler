#include<stdio.h>
int a,b,arr[10],c,d;
int main(){
	scanf("%d%d%d%d", &a,&b,&c,&d);
	if(a >b)c=a;
	else c=b;
	printf("%d \n", c);
	arr[0]=20;
	printf(" %d \n", arr[0]);
	arr[2]=20;
	arr[3]=30;
	return arr[3];

	
}
