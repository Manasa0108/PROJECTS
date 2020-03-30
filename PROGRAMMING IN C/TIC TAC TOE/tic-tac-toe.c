#include<stdio.h>
#include<stdlib.h>
void main()
{int flag=0,i,j,k,u=0,c=0,i1,i2,i3,i4,i5,i6,i7,i8,i9,e=0;
char a1='1',a2='2',a3='3',a4='4',a5='5',a6='6',a7='7',a8='8',a9='9';
while((flag==0)&&(e<4))
{e++;
if(a1<58)
{i1=a1-48;
}else
{i1=a1;
}if(a2<58)
{i2=a2-48;
}else
{i2=a2;
}if(a3<58)
{i3=a3-48;
}else
{i
3=a3;
}if(a4<58)
{i4=a4-48;
}else
{i4=a4;
}
if(a5<58)
{i
5=a5-48;
}else
{i5=a5;
}if(a6<58)
{i6=a6-48;
}else
{i6=a6;
}if(a7<58)
{i7=a7-48;
}else
{i7=a7;
}if(a8<58)
{i8=a8-48;
}else
{i8=a8;
}if(a9<58)
{i9=a9-48;
}else
{i9=a9;
}
printf("enter one of the available numbers");
printf("\n %c | %c | %c \n",a1,a2,a3);
printf("_____________\n");
printf(" %c | %c | %c \n",a4,a5,a6);
printf("_____________\n");
printf(" %c | %c | %c \n",a7,a8,a9);
scanf("%d",&k);
if(k==i1)
{
a1='O';
}else if(k==i2)
{
a2='O';
}else if(k==i3)
{
a3='O';
}else if(k==i4)
{
a4='O';
}else if(k==i5)
{
a5='O';
}else if(k==i6)
{
a6='O';
}else if(k==i7)
{
a7='O';
}else if(k==i8)
{
a8='O';
}else if(k==i9)
{ a9='O';
}
if(a1<58)
{i1=a1-48;
}else
{i1=a1;
}if(a2<58)
{i2=a2-48;
}
else
{i2=a2;
}if(a3<58)
{i3=a3-48;
}else
{i3=a3;
}if(a4<58)
{i4=a4-48;
}else
{i4=a4;
}if(a5<58)
{i5=a5-48;
}else
{i5=a5;
}if(a6<58)
{i6=a6-48;
}else
{i6=a6;
}if(a7<58)
{i7=a7-48;
}else
{i7=a7;
}i
f(a8<58)
{i8=a8-48;
}else
{i8=a8;
}if(a9<58)
{i9=a9-48;
}else
{i9=a9;
}
int q=0,y;
while(q==0)
{
y=(rand()%9+1);
if(y==i1)
{ a1=='X';
q=1;
}else if(y==i2)
{
a2='X';
q=1;
}else if(y==i3)
{
a3='X';
q=1;
}else if(y==i4)
{
a4='X';
q=1;
}else if(y==i5)
{
a5='X';
q=1;
}else if(y==i6)
{
a6='X';
q=1;
}else if(y==i7)
{
a7='X';
q=1;
}else if(y==i8)
{
a8='X';
q=1;
}else if(y==i9)
{
a9='X';
q=1;
}e
lse
{
continue;
}}
if(((a1=='O')&&(a2=='O')&&(a3=='O')))
{
u=1;
flag=1;
}else if(((a4=='O')&&(a5=='O')&&(a6=='O')))
{
u=1;
flag=1;
}else if(((a7=='O')&&(a8=='O')&&(a9=='O')))
{
u=1;
flag=1;
}else if(((a1=='O')&&(a4=='O')&&(a7=='O')))
{
u=1;
flag=1;
}else if(((a2=='O')&&(a5=='O')&&(a8=='O')))
{
u=1;
flag=1;
}else if(((a3=='O')&&(a6=='O')&&(a9=='O')))
{
u=1;
flag=1;
}else if(((a1=='O')&&(a5=='O')&&(a9=='O')))
{
u=1;
flag=1;
}else if(((a3=='O')&&(a5=='O')&&(a7=='O')))
{
u=1;
flag=1;
}else if(((a1=='X')&&(a2=='X')&&(a3=='X')))
{
c=1;
flag=1;
}else if(((a4=='X')&&(a5=='X')&&(a6=='X')))
{
c=1;
flag=1;
}else if(((a7=='X')&&(a8=='X')&&(a9=='X')))
{
c=1;
flag=1;
}else if(((a1=='X')&&(a4=='X')&&(a7=='X')))
{
c=1;
flag=1;
}else if(((a2=='X')&&(a5=='X')&&(a8=='X')))
{
c=1;
flag=1;
}else if(((a3=='X')&&(a6=='X')&&(a9=='X')))
{
c=1;
flag=1;
}else if(((a1=='X')&&(a5=='X')&&(a9=='X')))
{
c=1;
flag=1;
}else if(((a3=='X')&&(a5=='X')&&(a7=='X')))


{
c=1;
flag=1;
}else
{continue;
}}
printf("\n %c | %c | %c \n",a1,a2,a3);
printf("_____________\n");
printf(" %c | %c | %c \n",a4,a5,a6);
printf("_____________\n");
printf(" %c | %c | %c \n",a7,a8,a9);
if(c==1)
{
printf("computer is the winner");
}else if(u==1)
{
printf("user is the winner");
}
}

