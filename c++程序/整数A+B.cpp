#include <stdio.h>
int main(void)
{
	int a,b,c,d;
	char next[20];
	next[0]='\0'; 
	c=scanf("%d",&a);
	if(c!=1)
	scanf("%*s");
	d=scanf("%d",&b);
	scanf("%s",next);
	if(c==1&&a>0)
	printf("%d",a);
	else
	{	putchar('?');
	
	}
	putchar('+');	
	if(d==1&&b>0&&next[0]=='\0')
	printf("%d",b);
	else putchar('?');
	putchar('=');
	if(c==1&&d==1&&next[0]=='\0')printf("%d",a+b);
	else putchar('?');
	return 0;	
}
