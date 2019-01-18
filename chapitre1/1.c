#include<stdio.h>
#include<stdlib.h>
#define max(x,y) x>y?x:y

int main() {
	char tc[]={'a','b','c','d','e'};
	char *p;
	char c1,c2,c3,c4,c5;
	
	p=&tc[2];
	c1=*(p-2);
	c2=*(p-1);
	c3=*p;
	c4=*++p;
	c5=*(p+1);
	
	printf("%c %c %c %c %c\n",c1,c2,c3,c4,c5);
	printf("max = %d\n",max(1,3));
	return 1;
}
