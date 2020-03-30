#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct
{
	int norder;
	char pname[100][100];
	int cost[100];
	int totalcost;
}orders;

typedef struct
{
	int dd;
	int mm;
	int yy;
}Date;

typedef struct
{
	char name[100];
	char uname[100];
	char pass[100];
	char emid[100];
	char addr[100];
	char phone[15];
	orders account;
	Date date;
}user;

int filesize(FILE *fp)
{
	int n;
	long int size;
	fpos_t pos;
	fseek(fp,0,2);
	size=ftell(fp);
	n=size/sizeof(user);
	fseek(fp,0,0);
	return n;
}

void dobcheck(int dob[])
{
 int flag=0;
 int d, m, y;
do
{
	printf("Enter DOB:\n");
	printf("Day(dd) : ");
	scanf("%d",&d);
	printf("Month(mm) : ");
	scanf("%d",&m);
	printf("Year(yyy) : ");
	scanf("%d",&y);
 if((y>1870)&&(y<2020))
 {
  if(y%400==0)
  {
     if(m==2)
     {
      if((d<=29)&&(d>0))
      {
       flag=1;
      }
      else
      {
      flag=0;
      }
     }
     else if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
     {
     if((d<=31)&&(d>0))
     {
      flag=1;
     }
     else
     {
      flag=0;
     }
     }
     else if((m==4)||(m==6)||(m==9)||(m==11))
     {
      if((d<=30)&&(d>0))
      {
       flag=1;
      }
      else
      {
       flag=0;
      }
     }
  }
  else if(y%100==0)
  {
   if(m==2)
    {
      if((d<=28)&&(d>0))
      {
       flag=1;
      }
      else
      {
      flag=0;
      }
    }
    else if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
    {
     if((d<=31)&&(d>0))
     {
      flag=1;
     }
     else
     {
      flag=0;
     }
    }
    else if((m==4)||(m==6)||(m==9)||(m==11))
    {
     if((d<=30)&&(d>0))
     {
      flag=1;
     }
     else
     {
      flag=0;
     }
    }

  }
  else if(y%4==0)
  {
   if(m==2)
     {
      if((d<=29)&&(d>0))
      {
       flag=1;
      }
      else
      {
      flag=0;
      }
     }
     else if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
     {
     if((d<=31)&&(d>0))
     {
      flag=1;
     }
     else
     {
      flag=0;
     }
     }
     else if((m==4)||(m==6)||(m==9)||(m==11))
     {
      if((d<=30)&&(d>0))
      {
       flag=1;
      }
      else
      {
       flag=0;
      }
     }
  }
  else
  {
   if(m==2)
    {
      if((d<=28)&&(d>0))
      {
       flag=1;
      }
      else
      {
      flag=0;
      }
    }
    else if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
    {
     if((d<=31)&&(d>0))
     {
      flag=1;
     }
     else
     {
      flag=0;
     }
    }
    else if((m==4)||(m==6)||(m==9)||(m==11))
    {
     if((d<=30)&&(d>0))
     {
      flag=1;
     }
     else
     {
      flag=0;
     }
    }
  }
 }

if(flag==0)
{
printf("DOB Entered is INVALID Please try again \n\n");
}
}
while(flag==0);
dob[0]=d;
dob[1]=m;
dob[2]=y;
}

void shop(user rec)
{
	int n;
	user temp;
	FILE *fp;
	fpos_t pos;
	fp=fopen("Accounts.bin","rb+");
	int choice=0;
	int ch;
	while(choice!=5)
	{
		system("cls");
		printf("\t\tMOBILE BRANDS\n\n");
		printf("Enter\n1 - Apple\n2 - Oneplus\n3 - Xioami\n4 - Samsung\n5 - Return\n");
  		scanf("%d",&choice);
		switch(choice)
  		{
  			case 1:
  				printf("Enter\n1 -Iphone 6  - Rs.35,500\n2 - Iphone 7- Rs.50,000\n3 - Iphone X - Rs.90,000\n4- Return\n");
  				scanf("%d",&ch);
  				if(ch!=4)
  					printf("Order Succesfully Placed !\n");
  				switch(ch)
  				{
  					case 1:
						  strcpy(rec.account.pname[rec.account.norder],"Iphone 6");
						  rec.account.cost[rec.account.norder]=35500;
						  rec.account.totalcost+=35500;
						  rec.account.norder++;
						  break;
  					case 2:
						  strcpy(rec.account.pname[rec.account.norder],"Iphone 7");
						  rec.account.cost[rec.account.norder]=50000;
						  rec.account.totalcost+=50000;
						  rec.account.norder++;
						  break;
					case 3:
						  strcpy(rec.account.pname[rec.account.norder],"Iphone X");
						  rec.account.cost[rec.account.norder]=90000;
						  rec.account.totalcost+=90000;
						  rec.account.norder++;
						  break;
					default:
						break;
				}
				break;
			case 2:
  				printf("Enter\n1 -Oneplus 6  - Rs.30,000\n2 - Oneplus 6t - Rs.35,000\n3 - Oneplus 7 - Rs.50,000\n4- Return\n");
  				scanf("%d",&ch);
  				if(ch!=4)
  					printf("Order Succesfully Placed !\n");
  				switch(ch)
  				{
  					case 1:
						  strcpy(rec.account.pname[rec.account.norder],"Oneplus 6");
						  rec.account.cost[rec.account.norder]=30000;
						  rec.account.totalcost+=30000;
						  rec.account.norder++;
						  break;
  					case 2:
						  strcpy(rec.account.pname[rec.account.norder],"Oneplus 6t");
						  rec.account.cost[rec.account.norder]=35000;
						  rec.account.totalcost+=35000;
						  rec.account.norder++;
						  break;
					case 3:
						  strcpy(rec.account.pname[rec.account.norder],"Oneplus 7");
						  rec.account.cost[rec.account.norder]=50000;
						  rec.account.totalcost+=50000;
						  rec.account.norder++;
						  break;
					default:
						break;
				}
				break;
			case 3:
  				printf("Enter\n1 -Mi Note 3  - Rs.11,000\n2 - Mi Note 5- Rs.10,000\n3 - Mi Note Gpro - Rs.12800\n4- Return\n");
  				scanf("%d",&ch);
  				if(ch!=4)
  					printf("Order Succesfully Placed !\n");
  				switch(ch)
  				{
  					case 1:
						  strcpy(rec.account.pname[rec.account.norder],"Mi Note 3");
						  rec.account.cost[rec.account.norder]=11000;
						  rec.account.totalcost+=11000;
						  rec.account.norder++;
						  break;
  					case 2:
						  strcpy(rec.account.pname[rec.account.norder],"Mi Note 5");
						  rec.account.cost[rec.account.norder]=10000;
						  rec.account.totalcost+=10000;
						  rec.account.norder++;
						  break;
					case 3:
						  strcpy(rec.account.pname[rec.account.norder],"Mi Note Gpro");
						  rec.account.cost[rec.account.norder]=12800;
						  rec.account.totalcost+=12800;
						  rec.account.norder++;
						  break;
					default:
						break;
				}
				break;
			case 4:
  				printf("Enter\n1 -Samsung S10  - Rs.76,000\n2 - Samsung A5- Rs.20,000\n3 - Samsung S9+ - Rs.60,000\n4- Return\n");
  				scanf("%d",&ch);
  				if(ch!=4)
  					printf("Order Succesfully Placed !\n");
  				switch(ch)
  				{
  					case 1:
						  strcpy(rec.account.pname[rec.account.norder],"Samsung S10");
						  rec.account.cost[rec.account.norder]=76000;
						  rec.account.totalcost+=76000;
						  rec.account.norder++;
						  break;
  					case 2:
						  strcpy(rec.account.pname[rec.account.norder],"Samsung A5");
						  rec.account.cost[rec.account.norder]=20000;
						  rec.account.totalcost+=20000;
						  rec.account.norder++;
						  break;
					case 3:
						  strcpy(rec.account.pname[rec.account.norder],"Samsung S9+");
						  rec.account.cost[rec.account.norder]=90000;
						  rec.account.totalcost+=90000;
						  rec.account.norder++;
						  break;
					default:
						break;
				}
				break;
			case 5:
				break;
			default:
				printf("Invalid Choice !!!");
		}
		system("pause");			
	}
	/*
	printf("order = %d\n",rec.account.norder);
	printf("cost  = %d\n",rec.account.cost[rec.account.norder-1]);
	printf("tcost = %d\n",rec.account.totalcost);
	system("pause");
	*/
	fseek(fp,0,0);
	n=filesize(fp);
	for(int i=0;i<n;i++)
	{
		fgetpos(fp, &pos);
		fread(&temp, sizeof(user), 1, fp);
		if(!strcmp(rec.name,temp.name))
		{
			fsetpos(fp, &pos);
			fwrite(&rec, sizeof(user), 1, fp);
		}
	}
	fclose(fp);
}

void adminpage()
{
	int n,c=1;
	int sum=0;
	user temp;
	FILE *fp;
	user rec;
	system("cls");
	fp=fopen("Accounts.bin","rb");
	while(c!=5)
	{
		printf("\t\tNOZAMA !!!\n");
		printf("\t Admin Account \n");
		printf("\n1.Total Revenue\n2.All Accounts\n3.All Transactions\n4.Back to Home Page\n");
		printf("Enter Choice : ");
		scanf("%d",&c);
		if(c==1)
		{
			sum=0;
			n=filesize(fp);
			fseek(fp,0,0);
			for(int i=0;i<n;i++)
			{
				fread(&temp, sizeof(user), 1, fp);
				sum+=temp.account.totalcost;
			}
			printf("Total Revenue = %d\n",sum);
			system("pause");
		}
		else if(c==2)
		{
			n=filesize(fp);
			for(int i=0;i<n;i++)
			{
				fread(&rec, sizeof(user), 1, fp);
				printf("\nName : %s\n",rec.name);
				printf("Username : %s\n",rec.uname);
				printf("Password : %s\n",rec.pass);
				printf("Address : %s\n",rec.addr);
				printf("Phone Number : %s\n",rec.phone);
				printf("Email ID : %s\n",rec.emid);
				printf("DOB : %d.%d.%d\n",rec.date.dd,rec.date.mm,rec.date.yy);
			}
			system("pause");
		}
		else if(c==3)
		{
			n=filesize(fp);
			for(int i=0;i<n;i++)
			{
				fread(&temp, sizeof(user), 1, fp);
				printf("Name : %s\n",temp.name);
				for(int j=0;j<temp.account.norder;j++)
				{
					printf("Product Name : %s",temp.account.pname[j]);
					printf("\nCost : %d\n\n",temp.account.cost[j]);
					//printf("\nCost +1 : %d\n\n",temp.account.cost[j+1]);
				}
			}	
			system("pause");
		}
		else if(c==4)
			return;
		else
		{
			printf("INVALID CHOICE !!!\n");
			system("pause");
		}
		system("cls");
	}
	return;
	//fclose(fp);
}

void Passw(char password[])
{
	char ch;
	int i;
	for(i=0;i<10;i++)
	{
		ch = getch();
		if(ch==13)
			break;
		password[i] = ch;
		ch = '*' ;
		printf("%c",ch);
	}
	password[i] = '\0';
	printf("\n");
}

void mainpage(user rec)
{
	FILE *fp;
	user temp;
	int c,n,ch;			//rec is the Structure Variable With the details of account
	here:
	system("cls");		//Sent as a Parameter , Write to File after changes
	printf("\t\tNOZAMA !!!\n");
	printf("\tWelcome %s \n\n",rec.name);
	printf("1.Shop\n2.Your Orders\n3.Exit\n");
	printf("Enter Choice : ");
	scanf("%d",&c);
	if(c==1)
	{
		shop(rec);
	}
	else if(c==2)
	{
		fp=fopen("Accounts.bin","rb");
		n=filesize(fp);
		for(int i=0;i<n;i++)
		{
			fread(&temp, sizeof(user), 1, fp);
			if(!strcmp(rec.name,temp.name))
			{
				for(int j=0;j<temp.account.norder;j++)
				{
					printf("Product Name : %s",temp.account.pname[j]);
					printf("\nCost : %d\n\n",temp.account.cost[j]);
				}
			}	
		}
		system("pause");
	}
	else if(c==3)
		return;
	goto here;
}

void login()
{
	FILE *fp;
	user rec;
	int c,n;
	char username[100],pass[100];
	printf("\t\tNOZAMA\n");
	printf("\n1.Login as User\n2.Login as Admin\n3.Back to Home Page\n");
	printf("Enter Choice : ");
	scanf("%d",&c);
	label:
	if(c==1)
	{
		fp=fopen("Accounts.bin","rb");
		fseek(fp,0,0);
		system("cls");
		printf("\t\tLOGIN\n\n");
		again:
		printf("Username : ");
		scanf("%s",username);
		printf("Password : ");
		Passw(pass);
		n=filesize(fp);
		for(int i=0;i<n;i++)
		{
			fread(&rec, sizeof(user), 1, fp);
			if(!strcmp(username,rec.uname)&&!strcmp(pass,rec.pass))
			{
				mainpage(rec);
				return;
			}
		}
		printf("INCORRECT DETAILS !!!\nPlease Enter Again\n");
		goto again;
	}
	else if(c==2)
	{
		system("cls");
		printf("\t\tLOGIN\n\n");
		printf("Username : Admin\n");
		printf("Password : ");
		Passw(pass);
		if(!strcmp(pass,"1234"))
			adminpage();
		else
		{
			printf("Wrong Password !!!\n");
		}
	}
	else if(c==3)
	{
		//fclose(fp);
		return;
	}
	else
	{
		printf("Invalid Choice\n");
		printf("Enter Choice Again : ");
		scanf("%d",&c);
		goto label;
	}
	//fclose(fp);
	return;
}

void signup()
{
	user rec;
	int dob[3];
	FILE *fp;
	fp=fopen("Accounts.bin","ab+");
	system("cls");
	printf("\t\tSignup Page\n\n");
	printf("Enter Name : ");
	scanf(" %[^\n]",rec.name);
	printf("Enter Username : ");
	scanf(" %[^\n]",rec.uname);
	printf("Enter Password : ");
	scanf(" %[^\n]",rec.pass);
	printf("Enter Address : ");
	scanf(" %[^\n]",rec.addr);
	printf("Enter Phone Number : ");
	scanf(" %[^\n]",rec.phone);
	printf("Enter Email ID : ");
	scanf(" %[^\n]",rec.emid);
	dobcheck(dob);
	rec.date.dd=dob[0];
	rec.date.mm=dob[1];
	rec.date.yy=dob[2];
	rec.account.norder=0;
	rec.account.totalcost=0;
	fwrite(&rec, sizeof(user), 1, fp);
	fclose(fp);
	printf("\nSignup Successful\n");
}


int main()
{
	int ch;
	while(1)
	{
	
		printf("\t\tWelcome To NOZAMA !!!\n\n");
		printf("1.Login\n2.Signup\n3.Exit\n");
		printf("Enter Choice : ");
		scanf("%d",&ch);	
		switch(ch)
		{
			case 1:
				system("cls");
				login();
				break;
			case 2:
				system("cls");
				signup();
				break;
			case 3:
				exit(0);
			default:
				printf("Invalid Choice !!!\n");
		}
		printf("\n");
		system("pause");
		system("cls");
	}
}
