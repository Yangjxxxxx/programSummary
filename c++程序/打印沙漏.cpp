#include<stdio.h>
#include<stdlib.h>
int m;
void shalou(int a,char ch);
void put_char(char ch,int a);
int main(void)
{
	system("color1A");
	extern int m;
	int a,i,j;
	char ch;
	scanf("%d %c",&a,&ch);
	for(i=1;(i+1)*(i+1)/2-1<=a;i=i+2)
	j=i;
	m=i;
	shalou(j,ch);
	printf("%d",a-((i-1)*(i-1)/2-1)); 
	return 0;
}
void shalou(int a,char ch)
{
	extern int m;
	int i,n;
	if(a>1)
	{
		for(n=0;n<((m-a)/2-1);n++)
		putchar(' ');
		put_char(ch,a);
		putchar('\n');
		shalou(a-2,ch);
		for(n=0;n<((m-a)/2-1);n++)
		putchar(' ');
		put_char(ch,a);
		putchar('\n');
	}
	else 
	{
		for(n=0;n<((m-3)/2);n++)
		putchar(' ');
		putchar(ch);
		putchar('\n');
	}	
}
void put_char(char ch,int a)
{
	int i;
	for(i=0;i<a;i++)
	putchar(ch);
}

