#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void main()
{
int n,a=0,b=1,i,c;
printf("How long do you want to print fibonacci series");
scanf("%d",&n);
printf("Your Fibonacci Series is:");
for(i=0;i<=n-1;i++)
{
if(n==1)
{
printf("%d",a);
break;
}
if(n==2)
{
printf("%d %d",a,b);
break;
}
if(n>=3)
{
c=a;
printf("%d ",c);
c=a+b;
a=b;
b=c;
}
}
}

