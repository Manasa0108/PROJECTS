#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
class spl
{
 char name[30];
 int vote;
 public:
 spl()
 {
  vote=0;
 }
 void plusvote()
 {
	vote++;
 }
 void setname(char ch[])
 {
  strcpy(name,ch);
 }
};
void main()
{
 spl cand1[17],cand2[21];
 char name1[18][45]={{"Aishwarya Kannan"},{"Akalya S "},{"Bharat Parthasarathy"},{"Tejas Chhura"},{"Anusha Ananth Kumar"},{"Kaavya Iyer"},{"Sharmila Suresh"},{"Avani Maroo"},{"Pranesh HP "},{"Saathivika SS"},{"Abirami Arumugam"},{"S Nitesh Kanna"},{"Hiranaya S"},{"Mahima L M"},{"Lavanaya Nambiar "},{"D Bhagyeesh"},{"R Hemamalini"}};
 char name2[22][45]={{"Aparajitha Bhaskar"},{"Prisha V"},{"Husna Qadeer"},{"Samritha R"},{"Shirya Rajesh"},{"Aashruthaa"},{"Heera Krishna D"},{"Shreya Iyengar R"},{"Vaishnavi Ganpule"},{"Pratiksha G"},{"Dennis R"},{"Pranaav Dhakshesh G"},{"Maahir A ali"},{"Mummadi Annuridh Reddy"},{"Sricharan Kosygan A"},{"Vaibhav V Bommalapalayam"},{"Vidyuth K C"},{"Avyukth Harsh Agarawal"},{"Shwetha P"},{"N L Shrinihhi"},{"R Sudhira"}};

 cand1[0].setname(name1[0]);
 cand1[1].setname(name1[1]);
 cand1[2].setname(name1[2]);
 cand1[3].setname(name1[3]);
 cand1[4].setname(name1[4]);
 cand1[5].setname(name1[5]);
 cand1[6].setname(name1[6]);
 cand1[7].setname(name1[7]);
 cand1[8].setname(name1[8]);
 cand1[9].setname(name1[9]);
 cand1[10].setname(name1[10]);
 cand1[11].setname(name1[11]);
 cand1[12].setname(name1[12]);
 cand1[13].setname(name1[13]);
 cand1[14].setname(name1[14]);
 cand1[15].setname(name1[15]);
 cand1[16].setname(name1[16]);



 cand2[0].setname(name2[0]);
 cand2[1].setname(name2[1]);
 cand2[2].setname(name2[2]);
 cand2[3].setname(name2[3]);
 cand2[4].setname(name2[4]);
 cand2[5].setname(name2[5]);
 cand2[6].setname(name2[6]);
 cand2[7].setname(name2[7]);
 cand2[8].setname(name2[8]);
 cand2[9].setname(name2[9]);
 cand2[10].setname(name2[10]);
 cand2[11].setname(name2[11]);
 cand2[12].setname(name2[12]);
 cand2[13].setname(name2[13]);
 cand2[14].setname(name2[14]);
 cand2[15].setname(name2[15]);
 cand2[16].setname(name2[16]);
 cand2[17].setname(name2[17]);
 cand2[18].setname(name2[18]);
 cand2[19].setname(name2[19]);
 cand2[20].setname(name2[20]);


 char ch1[10],ch2[10];
  int i=0;
 strcpy(ch1,"q");
 while((strcmp(ch1,"q"))==0)
 {

  retry1:
 ax:
	 int i=0,l,flag=0,x=0;
	char a[10] ;
	cout<<"Enter SPL choice \n";
	gets(a);
	l=strlen(a);
	for(i=0;i<l;i++)
	 if(!(isdigit(a[i])))

	 flag=1;

	if(flag==1)
  {cout<<"\nInvalid input!  \n\n";
	 goto ax;
	 }
	 for(i=0;i<l;i++)
	 { x=(x+a[i])-48;
		x=x*10;
	 }

		  x=x/10;



  switch (x)
  {
	case 1: cand1[0].plusvote();
			  break;
	case 2: cand1[1].plusvote();
			  break;
	case 3: cand1[2].plusvote();
			  break;
	case 4: cand1[3].plusvote();
			  break;
	case 5: cand1[4].plusvote();
			  break;
	case 6: cand1[5].plusvote();
			  break;
	case 7: cand1[6].plusvote();
			  break;
	case 8: cand1[7].plusvote();
			  break;
	case 9: cand1[8].plusvote();
			  break;
	case 10: cand1[9].plusvote();
			  break;
	case 11: cand1[10].plusvote();
			  break;
	case 12: cand1[11].plusvote();
			  break;
	case 13: cand1[12].plusvote();
			  break;
	case 14: cand1[13].plusvote();
			  break;
	case 15: cand1[14].plusvote();
			  break;
	case 16: cand1[15].plusvote();
			  break;
	case 17: cand1[16].plusvote();
			  break;

	default: cout<<"\nInvalid input!  \n\n";
				goto retry1;
  }


  retry2:

 ay:
		int l1,flag1=0,x1=0;
		i=0;
	char b[10] ;
	cout<<"\nEnter ASPL choice \n";
	gets(b);
	l1=strlen(b);
	for(i=0;i<l1;i++)
	 if(!(isdigit(b[i])))

	 flag1=1;

	if(flag1==1)
  {cout<<"\nInvalid input! \n\n";
	 goto ay;
	 }
	 for(i=0;i<l1;i++)
	 { x1=(x1+b[i])-48;
		x1=x1*10;
	 }

		  x1=x1/10;

  switch (x1)
  {
	case 1: cand2[0].plusvote();
			  break;
	case 2: cand2[1].plusvote();
			  break;
	case 3: cand2[2].plusvote();
			  break;
	case 4: cand2[3].plusvote();
			  break;
	case 5: cand2[4].plusvote();
			  break;
	case 6: cand2[5].plusvote();
			  break;
	case 7: cand2[6].plusvote();
			  break;
	case 8: cand2[7].plusvote();
				  break;
	case 9: cand2[8].plusvote();
			  break;
	case 10: cand2[9].plusvote();
			  break;
	case 11: cand2[10].plusvote();
			  break;
	case 12: cand2[11].plusvote();
			  break;
	case 13: cand2[12].plusvote();
			  break;
	case 14: cand2[13].plusvote();
			  break;
	case 15: cand2[14].plusvote();
			  break;
	case 16: cand2[15].plusvote();
			  break;
	case 17: cand2[16].plusvote();
			  break;
	case 18: cand2[17].plusvote();
			  break;
	case 19: cand2[18].plusvote();
			  break;
	case 20: cand2[19].plusvote();
			  break;
	case 21: cand2[20].plusvote();
			  break;
	default: cout<<"\nInvalid input!\n\n";
				goto retry2;
  }
  clrscr();
  cout<<"\n\n\n\t\tYOUR VOTE HAS BEEN CAST SUCCESSFULLY! \n  ";
  aaa:

  cout<<"\n\t\t\tDo you want to continue? \n\t\t ";
  gets(ch1);
 if((strcmp(ch1,"q"))==0)
 { cout<<" contniue \n \n ";
 }
 else
 {
 if((strcmp(ch1,"no"))==0)
  {cout<<"stopping";
  }
  else
	{cout<<"Invalid Option! RETRY! \n \n";
	 goto aaa;
	 }
	}

	clrscr();
 }
	end:
 cout<<"\n\n\n\n\t\tDO YOU WANT TO END THE VOTING PROCESS? yes or no\n\t\t ";
 gets(ch2);
 if((strcmp(ch2,"yes"))==0)
 {
	clrscr();
	cout<<"\n\n\n\n\t\tELECTION PROCESS SUCCESSFULLY TERMINATED!  ";
 }
 else
 {  if((strcmp(ch2,"no"))==0)
  { clrscr();
	goto retry1;
    }
	else
  { cout<<"\nInvalid option";
  clrscr();
  goto end;
  }
 }
 ofstream f1,f2;
 f1.open("spl.dat",ios::binary);
 f2.open("aspl.dat",ios::binary);
 if(!f1||!f2)
 {
	cout<<"Cannot open file! \n \n";
	getch();
	exit(1);
 }
 for(i=0;i<17;i++)
 {
	f1.write((char*)&cand1[i],sizeof(cand1[i]));

 }
 for(int j=0;j<21;j++)
 {
	f2.write((char*)&cand2[j],sizeof(cand2[j]));

 }
 f1.close();
 f2.close();
 exit (0);
}

