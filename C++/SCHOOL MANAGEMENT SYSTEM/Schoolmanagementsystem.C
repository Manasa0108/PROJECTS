#include <iostream.h>
#include <fstream.h>
#include <string.h>           //header files
#include <conio.h>
#include <stdio.h>
#include <iomanip.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////////////////

void admin();        // Global function for the admin user and for displaying the options for the admin to choose from
void contniue();     // Global function for going back to main
void mainpage();     // Global function for accessing mainpage
void displaylast();  // Global function to display the details after the program ends
void homepage();     // Global function to display the front page
void timedelay();    // Global function to display timedelay
void space(int x);   // Global function for spacing

////////////////////////////////////////////////////////////////////////////////////////////

class staffdetails    // class for staff details
{
 private:
  char name[20],gender[10],address[100],qualification[10],jobtitle[10],department[10];
  int dayb, monthb, yearb,dayj,monthj,yearj;                                               //private members:can only be accessed by the member function
  char nalalandaid[20],basicpay[50],contactno[20];


 public:

 //member function

  void registers();                 //a function for registering a staff
  void login();                     //a function for logging in as a staff
  void staff();                     //a function for displaying the options for the staff
  void addstaff();                  //a function to add staff
  void searchstaff();               //a function to search a staff
  void searchstudent();             //a function to display the various options for the user to search from
  void modifystaff();               //a function to modify staff details
  void displaystaffdetails();       //a function to display staff details
  void displayperdetails();         //a function to display the staffs personal details
  void addjobtitle();               //a function to add a job title
  void adddepname();                //a function to add a department title
  void nalalandaidcheck();          //a function for nalalanda id check and to input the information
  void searchnalalandaid();         //a function for serching based on nalalanda id
  void searchnamephoneno();         //a function for serching based on phone no
  void entercontactno();            //a function to check the validity of the entered contact number
  void enterbasicpay();             //a function to enter the basic pay of the staff member
  void checkdob();                  //a function to check the validity of date of birth
  void checkdoj();                  //a function to check the validity of date of join
  void dbodoj();                    //a function to Display Details Based On Date Of Join (dbodoj)

}st;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class studetails
{
private  :
 char name[20],gender[10],address[100],section;
 int dayb, monthb, yearb,daya,montha,yeara,sclass;
 char rollno[20],pcontactno[20],regno[30];            //private members
 char subjectname[10],result[2];
 int marks,avg,maximummark,totalsum,p;

public:

 //class members

 void addstudent();                       //a function to add a student
 void searchstudent();                    //a function to displaying the options for searching for the details
 void modifystudent();                    //a function to modify the student details
 void displaystudentdetails();            //a function to display the student details
 void registrationnocheck();              //a function to input and to check the registration number
 void searchregno();                      //a function to search for a registration number
 void searchnamepphoneno();               //a function to search on name and parents phone number
 void enterpcontactno();                  //a function to enter the parents contact number
 void enterrollno();                      //a function to enter the roll number of the student
 void checkdob();                         //a function to check the validity of the date of birth
 void checkdoa();                         //a function to check the validity of the date of admission
 void subject();                          //a function to input the subject name and marks
 void average();                          //a function to calculate the average,passmark and the highest mark
 void modifysubject();                    //a function to modify the subject
 void addsubject();                       //a function to add a subject
 void dbodoa();                           //a function to Details Based On Date Of Admission (dbodoa)
 void dboc();                             //a function to Details Based On class (dbodoc)
 void dbom();                             //a function to Details Based On marks (dbodom)
}sd,re;


////////////////////////////////////////////////////////////////////////////////////////////////////////

 void main()
 {
  mainpage();
 }


		void space(int x) //TO LEAVE SPACE (USED IN HOMEPAGE.)
		{
		int i;

		  for(i=0;i<x;i++)
		  cout<<" ";

		}
  void timedelay()
		{   double i;

		for(i=0;i<=1000000;i++);
		}
	 void homepage() //THE OPENING PAGE.
		{ int i,j,l;

		  for(i=60,j=0;i>=32;i--,j++)
		  {  clrscr();

		 for(l=0;l<1;l++)
		 {cout<<"\n\n";
		 cout<<"////////////////////////////////////////////////////////////////////////////////\n";
		 cout<<"&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*\n";
		 }space(i);

		 cout<<"WELCOME\n\n";
		 cout<<"&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*\n";

		 space(j);

		 cout<<"TO\n\n";   //21-180
		 cout<<"&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*\n";


		 space(i);

		 cout<<"EFG\n\n";
		 cout<<"&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*\n";

		 space(j);

		 cout<<"   SCHOOL MANAGEMENT SYSTEM\n\n";

		 for(l=0;l<1;l++)
		{ cout<<"&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*\n";
		  cout<<"////////////////////////////////////////////////////////////////////////////////\n";
		  }
		 timedelay();
		  }
		  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

 void mainpage()

 {
 homepage();
	aa:
  clrscr();
  int a=0;
	cout<<"\n\n";
  for(int i=0;i<80;i++)
  cout<<"*";
	 cout<<"\n\n";
	 cout<<"\t\t\t    EEEEE    FFFFFFF     GGGGGG  \n";
	 cout<<"\t\t\t    E        F           G       \n";
	 cout<<"\t\t\t    EEEEE    FFFFFFF     GGGGGG  \n";
	 cout<<"\t\t\t    E        F           G    G  \n";
	 cout<<"\t\t\t    EEEEE    F           GGGGGG  \n\n\n";


	 cout<<"\t\t SSSSSS  CCCCCC  H     H  OOOOOOOO  OOOOOOOO  L         \n";
	 cout<<"\t\t S       C       H     H  O      O  O      O  L         \n";
	 cout<<"\t\t SSSSSS  C       HHHHHHH  O      O  O      O  L         \n";
	 cout<<"\t\t      S  C       H     H  O      O  O      O  L         \n";
	 cout<<"\t\t SSSSSS  CCCCCC  H     H  OOOOOOOO  OOOOOOOO  LLLLLLLL  \n\n\n";

  for( i=0;i<80;i++)
  cout<<"*";

	cout<<"\n\n enter a character to contniue\n\n";
	getche();

	clrscr();
	cout<<"\n\n";
  for( i=0;i<80;i++)
  cout<<"*";


  cout<<"\n\t\t choose one of the following options given below \n\n";
  for( i=0;i<80;i++)
  cout<<"*";
  cout<<"\n\t\t 1.register(for staff only) \n";
  cout<<"\n\t\t 2.login\n";
  cout<<"\n\t\t 3.exit and display \n";
  cout<<"\n\t\t enter 1 or 2 \n\t\t";
  cin>>a;
  if(a==1)
 { st.registers();
 goto aa;
 }
  else
  if(a==2)
 { st.login();
	goto aa;
	}


  }
/////////////////////////////////////////////////////////////////////////////////////////

 void staffdetails :: registers()
 {
  int i;
  clrscr();
  ofstream f1;
  f1.open("staff",ios::binary|ios::app);
  while(!f1)
{
	cerr<<"File not found. \n\t\t";
}
	s:
	cout<<"\n\n";
  for( i=0;i<80;i++)
  cout<<"*";
	cout<<"\n\t  enter the following details for registering for a staff member \t\t\n";

  for( i=0;i<80;i++)
  cout<<"*";
  {
	cout<<"\n\t\t enter name (username) : ";
	gets(name);

	ks:
	cout<<"\n\t\t enter gender  male ,female or neutral : ";
	gets(gender);
	if(strcmp(gender,"male")||strcmp(gender,"female")||strcmp(gender,"neutral")==0)
	cout<<"\n\t\t gender confirmed \n";
	else
	goto ks;

	st.nalalandaidcheck();
	st.entercontactno();
	st.enterbasicpay();
	st.checkdob();
	st.checkdoj();

	cout<<"\n\t\tenter address: ";
	gets(address);
	cout<<"\n\t\tenter qualification : ";
	gets(qualification);
	cout<<"\n\t\tenter department : ";
	gets(department);
	cout<<"\n\t\tenter job title : ";
	gets(jobtitle);

	f1.write((char*)&st,sizeof(st));
	f1.close();

	cout<<"\n ^^^^^^^^^^^^^^^^^^you have been registered successfully ^^^^^^^^^^^^^^^^^^^^^ \n\n ";
  for( i=0;i<79;i++)
  cout<<"*";
  cout<<"\n";
	contniue();
 }
 }


void staffdetails :: login()
{
  aa1:
  clrscr();
  staffdetails st;
  cout<<"\n\n\n";
  for(int i=0;i<80;i++)
  cout<<"*";
  int a1;
  cout<<"\n\t\t choose one of the following option for loging in \n\n" ;
  for(i=0;i<80;i++)
  cout<<"*";
  cout<<"\n\t\t 1.administrater \n"  ;
  cout<<"\n\t\t 2.staff \n";
  cin>>a1;

  if(a1==1)
  {
  admin();
  goto aa1;
  }

  else if(a1==2)
  {
  st.staff();
	goto aa1;
  }
  }



void admin()
{
jl:

clrscr();
  int i;
char passkey[]="       " ;
cout<<"\n\n";
for( i=0;i<80;i++)
  cout<<"*";

cout<<" \n\n \t \t \t \t admin login \n\n\n";
for(i=0;i<80;i++)
  cout<<"*";
cout<<" \n\t\t enter password :"; //password is kshitij(only one admin (who is pre stored))
for(i=0;i<7;i++)
 { passkey[i]=getch();
			 cout<<"*";
		  }
if(strcmp(passkey,"kshitij")==0)
cout<<" \n\t\t login successfull \n";
else
{
cout<<"n\t\t incorrect password try again \n";
goto jl;
}


 w:
int a2=0;
clrscr();

cout<<"\n\n";
for(i=0;i<80;i++)
  cout<<"*";
cout<<"\n\n\t\t\t\t administrater menu \n";
cout<<"\n\t\t\t choose from the following options \n\n";
for(i=0;i<80;i++)
  cout<<"*";
cout<<"\n\n";
cout<<"\t\t 1.add a staff \n";
cout<<"\t\t 2.add a student \n";
cout<<"\t\t 3.search for a staff member \n";
cout<<"\t\t 4.search for a student \n";
cout<<"\t\t 5.modify staff details \n";
cout<<"\t\t 6.modify student details \n";
cout<<"\t\t 7.display staff details \n";
cout<<"\t\t 8.display student details \n";
cout<<"\t\t 9.add subject for the student \n";
cout<<"\t\t 10.add a department for the staff \n";
cout<<"\t\t 11.add a job title for the staff \n";
cout<<"\t\t 12.display student marks and maxmark \n";
cout<<"\t\t 13.modify subject \n";
cout<<"\t\t 14.go back to main menu \n";
cout<<"\t\t enter one of the above option\n\n\t\t";
cin>>a2;

 if(a2==1)
{
 st.addstaff();
 goto w;
}

else if(a2==2)
 {
sd.addstudent() ;
 goto w;
 }
else if(a2==3)
{
 st.searchstaff();
 goto w;
}

else if(a2==4)
 {
 sd.searchstudent();
 goto w;
 }
else if(a2==5)
{
 st.modifystaff();
 goto w;
}

else if(a2==6)
 {
 sd.modifystudent();
 goto w;
 }
else if(a2==7)
{
 st.searchstaff();
 goto w;
}

else if(a2==8)
 {
 sd.searchstudent();
 goto w;
 }
else if(a2==9)
{
 re.addsubject();
 goto w;
}
else if(a2==10)
{  st.adddepname();

  goto w;
}
else if(a2==11)
{
st.addjobtitle();
 goto w;
}
else if(a2==12)
{
 re.average();
 goto w;
}
else if(a2==13)
{
 re.modifysubject();
 goto w;
}
else
{
 cout<<"\n\t\tgoing back to main menu \n\n\t\t";

}
}

////////////////////////////////////////////////////////////////////////////////////////

void staffdetails :: staff()
{
 clrscr();
  int i;
 char naa[20];
 char passkey[]="       " ;
	 labelaa:
	 for(i=0;i<80;i++)
  cout<<"*";
	 cout<<"\n\t\t staff login \n";
	 for(i=0;i<80;i++)
  cout<<"*";

 cout<<"\n\t\t enter name (username) \n";
	 gets(naa);
cout<<"\n\t\t enter password \n";
for(i=0;i<7;i++)
		  { passkey[i]=getch();
			 cout<<"*";
		  }

ifstream f2;
f2.open("staff",ios::binary);
while(!f2)
{
cerr<<"File not found. \n\t\t";
}


while(f2.read((char*)&st,sizeof(st)))
{
if((strcmp(st.name,naa))==0)
{
cout<<"\n\n correct username\n";
}

else
{cout<<"\n\t\t incorrect username try again \n";
goto labelaa;
 }

 if((strcmp(passkey,"kshitij"))==0)
 cout<<"correct password \n";
 else
{cout<<"\n\t\t incorrect password try again \n";
 goto labelaa;
 }

 }
  f2.close();

t1:
t:
int a3=0 ;
for( i=0;i<80;i++)
  cout<<"*";
cout<<"\t\t\t\t\t staff menu \n";
cout<<"\t\t\tchoose from the following options \n";
for(i=0;i<80;i++)
  cout<<"*";
 cout<<"\n\n";
cout<<"\t\t 1.add a student \n";
cout<<"\t\t 2.search for a student \n";
cout<<"\t\t 3.modify student details \n";
cout<<"\t\t 4.display student details \n";
cout<<"\t\t 5.display personal details \n";
cout<<"\t\t 6.add a subject for the student \n";
cout<<"\t\t 7.display all the student marks, passmarks and maxmark   \n";
cout<<"\t\t 8.modify subject \n";
cout<<"\t\t 9.go back to main menu \n";
cout<<"\t\t enter one of the above option \n\n\t\t ";
cin>>a3;

if(a3==1)
 {
sd.addstudent() ;
goto t1;
 }

else if(a3==2)
 {
 sd.searchstudent();
 goto t;
 }

else if(a3==3)
 {
 sd.modifystudent();
 goto t;
 }


else if(a3==4)
 {
 sd.searchstudent();
 goto t;
 }
 else if(a3==5)
{
 st.displayperdetails();
 goto t;
}

else if(a3==6)
{
 re.addsubject();
 goto t;
}
else if(a3==7)
{
 re.average();
 goto t;
}

else if(a3==8)
{
 re.modifysubject();
 goto t;
}
else
{
 cout<<"\n\t\t going back to main menu\n\t\t ";
 goto t;
}

}

///////////////////////////////////////////////////////////////////////////////////////

void staffdetails :: addstaff()
 {
 clrscr();
 ofstream f3;
  f3.open("staff",ios::binary|ios::app);
  while(!f3)
{
cerr<<"File not found. \n\t\t";
}
	cout<<"\n\t\tenter the following details for registering for a staff member \n";
	s:
	cout<<"\n\t\tenter name (username) :";
	gets(name);

  ss:
	cout<<"\n\t\tenter gender  male ,female or neutral :";
	gets(gender);
	if(strcmp(gender,"male")||strcmp(gender,"female")||strcmp(gender,"neutral")==0)
	cout<<"\n\t\t gender confirmed :";
	else
	goto ss;

 st.nalalandaidcheck();
 st.entercontactno();
 st.enterbasicpay();
 st.checkdob();
 st.checkdoj();

 cout<<"\n\t\t enter address:";
 gets(address);
 cout<<"\n\t\t enter qualification :";
 gets(qualification);
 cout<<"\n\t\t enter department :";
 gets(department);
 cout<<"\n\t\t enter job title : ";
 gets(jobtitle);

	f3.write((char*)&st,sizeof(st));
	f3.close();
	cout<<"\n\t\t you have been registered successfully \n\n"   ;
	 for(int i=0;i<80;i++)
  cout<<"*";
  cout<<"\n";
	contniue();
 }


void studetails :: addstudent()
 {
 clrscr();
 ofstream f4;
  f4.open("student",ios::binary|ios::app);
  while(!f4)
{
cerr<<"File not found. \n\t\t";
}
	cout<<"\n\t\t enter the following details for registering  a student : ";
	cout<<"\n\t\t enter name (username) : ";
	gets(name);

	a11 :
	cout<<"\n\t\t enter gender  male ,female or neutral : ";
	gets(gender);
	if(strcmp(gender,"male")||strcmp(gender,"female")||strcmp(gender,"neutral")==0)
	cout<<"\n\t\t gender confirmed\n\t\t ";
	else
	goto a11;

	sd.registrationnocheck();
	sd.enterpcontactno();
	sd.enterrollno();
	sd.checkdob();
	sd.checkdoa();
	sd.subject();
	cout<<"\n\t\t enter address : ";
	gets(address);
	cout<<"\n\t\t enter section : ";
	cin>>section;
	cout<<"\n\t\t enter class : ";
	cin>> sclass;

	f4.write((char*)&sd,sizeof(sd));
	f4.close();
	cout<<"\n\t\t your student has been registered successfully : \n\n";

  for(int i=0;i<80;i++)
  cout<<"*";
  cout<<"\n";
  contniue();

 }

///////////////////////////////////////////////////////////////////////////////////////

void studetails :: subject()
{
	clrscr();

		  cout<<"\n \t \t enter the name of the subjects \n \t \t ";
		  cout<<"\n\t\t subject 1 : ";
		  gets(subjectname);
		  cout<<"\n\t\t enter the mark in the subject \n";
		  cout<<"\n\t\t out of 100: ";
		  cout<<"marks :" ;
		  cin>>marks;

		 if(re.marks==100)
		  strcpy(re.result,"A1");
		  else
			 if(re.marks>=80)
		  strcpy(re.result,"A2");
		  else
		 if(re.marks>=60)
		  strcpy(re.result,"A3");
		  else
		  if(re.marks>=40)
		 strcpy(re.result,"A4");
		  else
		  if(re.marks>=20)
		 strcpy(re.result,"A5");

	}


void studetails :: average()
 {
  int x=1,max=0;
  clrscr();
  ifstream fx8;
  fx8.open("student",ios::binary);
  while(!fx8)
{
cerr<<"File not found. \n\t\t";
}
	while(fx8.read((char*)&re,sizeof(re)))
	{  x++ ;
	totalsum+=sd.marks;
	}
	avg=(totalsum)/x;
	fx8.close();
	ifstream fx7;
	fx7.open("student",ios::binary);
	while(!fx7)
{
cerr<<"File not found. \n\t\t";
}
	while(fx7.read((char*)&re,sizeof(re)))
	{
	if(max>sd.marks)
		 max=sd.marks;
	}
	maximummark=max;
	fx7.close();
	ifstream f8;
	f8.open("student",ios::binary);
	while(f8.read((char*)&re,sizeof(re)))
  {
	cout<<"\n\t\t subject name : ";
	puts(subjectname);
	cout<<"\n\t\t reg no: ";
	puts(regno);
	cout<<"\n\t\t marks: ";
	cout<<marks;
	cout<<"\n\t\t result: ";
	cout<<result;
	cout<<"\n\t\t average OR passmark: " ;
	cout<<avg;
	cout<<"\n\t\t maxmark: " ;
	cout<<maximummark;
	f8.close();
	contniue();
  }
  }


void staffdetails ::  searchstaff()
{
  clrscr();
  for(int i=0;i<80;i++)
  cout<<"*";

  cout<<"\n  \t \t \t  search based on \n\n";
  for(i=0;i<80;i++)
cout<<"*";
  cout<<"\n\n";
	  cout<<"\n\t\t 1.nalalanda ID ";
	  cout<<"\n\t\t 2.name and phone number";
			int a;
	  cout<<"\n\t\t choose one of the  options given above  ";
	  cout<<"\n\t\t enter 1 or 2 ";
	  cin>>a;
 getch();
 clrscr();
 if(a==1)
 st.searchnalalandaid();
 else
 st.searchnamephoneno();
}


void studetails :: searchstudent()
{
	  clrscr();

	  for(int i=0;i<80;i++)
  cout<<"*";
	 cout<<"\n \t \t \t    search based on \n";
  for(i=0;i<80;i++)
  cout<<"*";
	  cout<<"\n\t\t 1.registration number and roll number ";
	  cout<<"\n\t\t 2.name and phone number ";
		int a;
	  cout<<"\n\t\t choose one of the options givenabove \n";
	  cout<<"\n\t\t enter 1 or 2 \n";
	  cin>>a;
 getch();
 clrscr();

 if(a==1)
 sd.searchregno();
 else
 sd.searchnamepphoneno();
	 contniue();

}



void staffdetails :: modifystaff()
{
 clrscr();
		 int flag=0;
		 char nam[20] , nalalanda[20];
		cout<<"\n\t\t enter current nalalanda ID:  ";
		gets(nalalanda);
		cout<<"\n\t\t enter current name : " ;
		gets(nam);
		cout<<"\n\t\t  searching based on nalalanda id and name "   ;
		ifstream f9;
		ofstream f10;
		f9.open("staff",ios::binary) ;
		while(!f9)
{
cerr<<"File not found. \n\t\t";
}
		f10.open("temp",ios::binary|ios::app) ;
		while(!f10)
{
cerr<<"File not found. \n\t\t";
}
		while(f9.read((char*)&st,sizeof(st)))
		{
		if(strcmp(st.nalalandaid,nalalanda)==0)
		 if(strcmp(st.name,nam)==0)
		{ cout<<"\n\t\t\staff found:";
		flag=1;
		}
		else
		{f10.write((char*)&st,sizeof(st));
		}

		}

	  if(flag)
	  {
		clrscr();
	 for(int i=0;i<80;i++)
 cout<<"*";
		cout<<"\n";
		cout<<"\n\t\t\previous details deleted and now enter new details|:"  ;
    for(i=0;i<80;i++)
  cout<<"*";
  cout<<"\n";

	cout<<"\n\t\t enter name: ";
	gets(name);
		  a111 :
	cout<<"\n\t\t enter gender  male ,female or neutral: ";
	gets(gender);
	if(strcmp(gender,"male")||strcmp(gender,"female")||strcmp(gender,"neutral")==0)
	cout<<"\n\t\t gender confirmed: ";
	else
	goto a111;

	st.nalalandaidcheck();
	st.entercontactno();
	st.enterbasicpay();
	st.checkdob();
	st.checkdoj();

	cout<<"\n\t\t enter address: ";
	gets(address);
	cout<<"\n\t\tenter qualification : ";
	gets(qualification);
	cout<<"\n\t\t enter department : ";
	gets(department);
	cout<<"\n\t\t enter job title : ";
	gets(jobtitle);
	}
	f9.close();
	f10.close();
	ofstream fx1;
	remove("staff") ;
	rename("temp","staff");
	fx1.open("staff",ios::binary|ios::app) ;
	fx1.write((char*)&st,sizeof(st));
	cout<<"\n\t\t the details have been modified successfully \n\t\t "   ;
	contniue();

	}



 void studetails :: modifystudent()
	{
	clrscr();
		 int flag=0;
		 char na[20],reno[20];
		cout<<"\n\t\t enter current registration number: ";
		gets(reno);
		cout<<"\n\t\t enter current name: " ;
		gets(na);
		cout<<"\n\t\t searching based on registration number and name:  ";
		ifstream f11;
		ofstream f12;
		f11.open("student",ios::binary) ;
		f12.open("temp",ios::binary|ios::app) ;
		while(f11.read((char*)&sd,sizeof(sd)))
		{     cout<<"hi";
		if((strcmp(sd.regno,reno))==0)
		 {
		cout<<"\n\t\t\staff found\n\t\t";
		flag=1;
		}
		else
		{f12.write((char*)&sd,sizeof(sd));
		}

		}
	  if(flag)
	  {   cout<<"\n\t\t\previous details deleted and now enter new details|:"  ;
			cout<<"\n\t\t enter name: ";
			gets(name);
			sd.registrationnocheck();
			sd.enterpcontactno();
			sd.enterrollno();
			sd.checkdob();
			sd.checkdoa();
			sd.subject();
	a1111:
			cout<<"\n\t\t enter gender  male ,female or neutral : ";
			gets(gender);
	if(strcmp(gender,"male")||strcmp(gender,"female")||strcmp(gender,"neutral")==0)
			cout<<"\n\t\t gender confirmed: ";
	else
	goto a1111;


			cout<<"\n\t\t enter address: ";
			gets(address);
			cout<<"\n\t\t enter section : ";
			cin>>section;
			cout<<"\n\t\t enter class : ";
			cin>> sclass;
	 }
	 f11.close();
	f12.close();
	ofstream fx2;
	remove("student") ;
	rename("temp","student");
	fx2.open("student",ios::binary|ios::app) ;
	fx2.write((char*)&sd,sizeof(sd));
	cout<<"\n\t\t the details have been modified successfully : "   ;
	contniue();

	}

  void studetails :: modifysubject()
  {
		 clrscr();
			int m;
				 char subname[10];
		 char na[20],reno[20];
		cout<<"\n\t\t enter current registration number: ";
		gets(reno);
		cout<<"\n\t\t enter current name: " ;
		gets(na);
		cout<<"\n\t\t searching based on registration number and name:  ";
		ifstream fx4;
		fx4.open("student",ios::binary) ;
		while(!fx4)
{
cerr<<"File not found. \n\t\t";
}
		while(fx4.read((char*)&sd,sizeof(sd)))
		{
		if((strcmp(sd.regno,reno))==0)
		 {

		  cout<<"\n \t \t enter the name of the subjects \n \t \t ";
		  cout<<"\n\t\t subject 1 : ";
		  gets(subname);
		  cout<<"\n\t\t enter the mark in the subject \n";
		  cout<<"\n\t\t out of 100: ";
		  cout<<"marks :" ;
		  cin>>m;
		  strcpy(re.subjectname,subname);
		  re.marks=m;

		 if(re.marks==100)
		  strcpy(re.result,"A1");
		  else
			 if(re.marks>=80)
		  strcpy(re.result,"A2");
		  else
		 if(re.marks>=60)
		  strcpy(re.result,"A3");
		  else
		  if(re.marks>=40)
		  strcpy(re.result,"A4");
		  else
		  if(re.marks>=20)
		  strcpy(re.result,"A5");
		fx4.close();
	  ofstream fx5;
		fx5.open("student",ios::binary) ;
		while(!fx5)
{
cerr<<"File not found. \n\t\t";
}
		fx5.write((char*)&sd,sizeof(sd));
	}
  }
}
void staffdetails :: displaystaffdetails()
{
		clrscr();
		ifstream f13;
		f13.open("staff",ios::binary) ;
		while(!f13)
{
cerr<<"File not found. \n\t\t";
}
		while(f13.read((char*)&st,sizeof(st)))
		{
	cout<<"\n\t\t  name : ";
	puts(name);
	cout<<"\n\t\t  gender : ";
	puts(gender);
	cout<<"\n\t\t nalalanda ID : " ;
	puts(nalalandaid);
	cout<<"\n\t\t  address: ";
	puts(address);
	cout<<"\n\t\t  contact no : ";
	puts(contactno);

//for date of birth
	cout<< "\n\t\t date of birth : ";
	cout<<" \n\t\t day  : ";
	cout<<dayb;
	cout<<"\n\t\t  month  : ";
	cout<<monthb;
	cout<<"\n\t\t year  : ";
	cout<< yearb;

//for date of join
	cout<<"\n\t\t date of join : ";
	cout<<"\n\t\t  day  : ";
	cout<<dayj;
	cout<<" \n\t\t month  : ";
	cout<<monthj;
	cout<<"\n\t\t  year : ";
	cout<< yearj;

	cout<<"\n\t\t  qualification : ";
	puts(qualification);
	cout<<"\n\t\t enter department : ";
	puts(department);
	cout<<"\n\t\t  job title : ";
	puts(jobtitle);
	cout<<"\n\t\t  basic pay : ";
	puts(basicpay);
	  }
		f13.close();
		contniue();
		}


void staffdetails :: displayperdetails()
{
 clrscr();
		st.searchnalalandaid();
		ifstream f14;
		f14.open("staff",ios::binary) ;
		while(!f14)
{
cerr<<"File not found. \n\t\t";
}
		while(f14.read((char*)&st,sizeof(st)))
		{
	cout<<"\n\t\t  name : ";
	puts(name);
	cout<<"\n\t\t  gender : ";
	puts(gender);
	cout<<"\n\t\t nalalanda ID : "  ;
	puts(nalalandaid);
	cout<<"\n\t\t  address : ";
	puts(address);
	cout<<"\n\t\t  contact no : ";
	puts(contactno);

//for date of birth
	cout<<"\n\t\t date of birth : ";
	cout<<"\n\t\t  day : ";
	cout<<dayb;
	cout<<"\n\t\t  month : ";
	cout<<monthb;
	cout<<"\n\t\t  year  : ";
	cout<< yearb;

//for date of join
	cout<<"\n\t\t date of join : ";
	cout<<"\n\t\t  day : ";
	cout<<dayj;
	cout<<"\n\t\t  month  : ";
	cout<<monthj;
	cout<<"\n\t\t  year : ";
	cout<< yearj;

	cout<<"\n\t\t  qualification : ";
	puts(qualification);
	cout<<"\n\t\t enter department : ";
	puts(department);
	cout<<"\n\t\t  job title : ";
	puts(jobtitle);
	cout<<"\n\t\t  basic pay : ";
	puts(basicpay);


	  }
		f14.close();
	contniue();

 }


void staffdetails :: adddepname()
{
	 clrscr();
	 char nalalanda[20];
		 char dep[10];
	cout<<"\n\t\t enter current nalalanda ID: ";
	gets(nalalanda);

	cout<<"\n\t\t enter department : ";
	gets(dep);
	cout<<"\n\t\t searching based on nalalandaid and name:  " ;
	getch();
		ifstream f15;

		f15.open("staff",ios::binary) ;
		while(!f15)
{
cerr<<"File not found. \n\t\t";
}
		while(f15.read((char*)&st,sizeof(st)))
		{if((strcmp(st.nalalandaid,nalalanda))==0)

		 {
				cout<<"hi \n";
		strcat(department,",");
		strcat(department,dep);
		cout<<" new department\n";
		cout<<department;
		f15.close();
	  ofstream fx15;

	fx15.open("staff",ios::binary) ;
	fx15.write((char*)&st,sizeof(st));
	 fx15.close();
}
}

contniue();

}


void staffdetails :: addjobtitle()
	{
	 clrscr();
	char nalalanda[20];
		 char nam[20],jbt[20];
		cout<<"\n\t\t enter current nalalanda ID: ";
		gets(nalalanda);
		cout<<"\n\t\t enter current name: " ;
		gets(nam);
		cout<<"\n\t\t searching based on nalalandaid and name : "  ;
		ifstream f16;
		f16.open("staff",ios::binary) ;
		while(f16.read((char*)&st,sizeof(st)))
		{
		{if(strcmp(st.nalalandaid,nalalanda)==0)

		 {
		cout<<"\n\t\t enter job title : ";
		gets(jbt);
		strcat(jobtitle,",");
		strcat(jobtitle,jbt);
		cout<<"new job title";
		cout<<jobtitle;
		f16.close();
		ofstream fx16;
		fx16.open("staff",ios::binary) ;
		fx16.write((char*)&st,sizeof(st));

	}
	}
	}
	  contniue();
	 }

	 void studetails :: addsubject()
	{
	 clrscr();
	char reg[20];
		 char nam[20],sub[20];
		cout<<"\n\t\t enter current registration no : ";
		gets(reg);
		cout<<"\n\t\t enter current name: " ;
		gets(nam);
		cout<<"\n\t\t searching based on registration and name : "  ;
		ifstream fx23;
		fx23.open("student",ios::binary) ;
		while(fx23.read((char*)&sd,sizeof(sd)))
		{
		{if(strcmp(sd.regno,reg)==0)
		 {
		cout<<"\n\t\t enter subject : ";
		gets(sub);
		strcat(subjectname,",");
		strcat(subjectname,sub);
		cout<<" new subject name";
		cout<<subjectname;
		fx23.close();
		ofstream fx9;
		fx9.open("student",ios::binary|| ios::app) ;
		while(!fx9)
{
cerr<<"File not found. \n\t\t";
}
		fx9.write((char*)&sd,sizeof(sd));
	}
	}
	}
	  contniue();
	 }




void staffdetails :: nalalandaidcheck()
  {


	 ax:
	 int i=0,l,flag=0;
	cout<<"\n\t\t enter nalalanda id ";
	gets(nalalandaid);
	l=strlen(nalalandaid);
	for(i=0;i<l;i++)
	 if(!(isdigit(nalalandaid[i])))
	 flag=1;

	if(flag==1)
  {cout<<"\n\t\t invalid option : ";
	 goto ax;
	 }
		 else
		 if(l<=10)
		  cout<<"\n\t\t valid option\n\t\t ";
		}

void studetails :: registrationnocheck()
  {
	clrscr();


	 ax:
	 int i=0,l,flag=0;
	 cout<<"\n\t\t enter registration number : ";
	 gets(regno);
	 l=strlen(regno);
	 for(i=0;i<l;i++)
	 if(!(isdigit(regno[i])))
	 flag=1;

	if(flag==1)
  {cout<<"\n\t\t invalid option \n\t\t ";
	 goto ax;
	 }

}


void staffdetails :: searchnalalandaid()
 {
 clrscr();
  int n;
  char nalalanda[10];
  for( int i=0;i<80;i++)
  cout<<"*";

		cout<<"\n\n\t\t enter nalalanda ID : ";
		gets(nalalanda);
		cout<<"\n\t\t searching based on nalalandaid \n\t\t  " ;
		ifstream f19;
		f19.open("staff",ios::binary) ;
		while(!f19)
{
cerr<<"File not found. \n\t\t";
}
		while(f19.read((char*)&st,sizeof(st)))
		{
		if((strcmp(st.nalalandaid,nalalanda))==0)
		 {
		 cout<<"\n\t\t staff found \n\t\t ";
		 cout<<"\n\t\t do you want the staff details:\n\t\t";
		 cout<<"if yes enter 1\n\t\t";
		 cout<<"if no enter 0 \n\t\t";
		 cin>>n;
		 if(n==1)
		 {
		  cout<<"\n\t\t  name : " ;
		  puts(name);
		  cout<<"\n\t\t  gender : ";
		  puts(gender);
		  cout<<"\n\t\t nalalanda ID : ";
		  puts(nalalandaid);
		  cout<<"\n\t\t  address : ";
		  puts(address);
		  cout<<"\n\t\t  contact no : ";
		  puts(contactno);

//for date of birth
		 cout<< "\n\t\t date of birth : ";
		 cout<<"\n\t\t  day   : ";
		 cout<<dayb;
		 cout<<"\n\t\t  month  : ";
		 cout<<monthb;
		 cout<<"\n\t\t  year  : ";
		 cout<< yearb;

//for date of join
		 cout<<"\n\t\t date of join : ";
		 cout<<" \n\t\t day : ";
		 cout<<dayj;
		 cout<<"\n\t\t  month   : ";
		 cout<<monthj;
		 cout<<"\n\t\t  year  : ";
		 cout<< yearj;

		 cout<<"\n\t\t  qualification : ";
		 puts(qualification);
		 cout<<"\n\t\t enter department : ";
		 puts(department);
		 cout<<"\n\t\t  job title : ";
		 puts(jobtitle);
		 cout<<"\n\t\t  basic pay : ";
		 puts(basicpay);
	  }
		f19.close();
		contniue();
}
}
}


 void staffdetails :: searchnamephoneno()
{
clrscr();
 int n;
char nam[10],num[10] ;
 for( int i=0;i<80;i++)
  cout<<"*";

			cout<<"\n\n\t\t enter name : ";
			gets(nam);
			cout<<"\n\t\t enter phone number : ";
			gets(num);
			cout<<" \n\t\t searching based on name and phone number :  " ;
		ifstream f20;
		f20.open("staff",ios::binary) ;
		while(!f20)
{
cerr<<"File not found. \n\t\t";
}
		while(f20.read((char*)&st,sizeof(st)))
		{
		if((strcmp(st.contactno,num))==0)
		 {if((strcmpi(name,nam))==0)
		 cout<<"\n\t\t staff found \n\t\t ";
		 cout<<"\n\t\t do you want the staff details:\n\t\t";
		 cout<<"if yes enter 1\n\t\t";
		 cout<<"if no enter 0 \n\t\t";
		 cin>>n;
		 if(n==1)
		 {
		  cout<<"\n\t\t  name : ";
		  puts(name);
		  cout<<"\n\t\t  gender : ";
		  puts(gender);
		  cout<<"\n\t\t nalalanda ID : " ;
		  puts(nalalandaid);
		  cout<<"\n\t\t  address : ";
		  puts(address);
		  cout<<"\n\t\t  contact no : ";
		  puts(contactno);

	 //for date of birth
		  cout<< "\n\t\t date of birth : ";
		  cout<<"\n\t\t  day   : ";
		  cout<<dayb;
		  cout<<"\n\t\t  month     : ";
		  cout<<monthb;
		  cout<<"\n\t\t  year  : ";
		  cout<< yearb;

//for date of join
		 cout<<"\n\t\t date of join : ";
		 cout<<"\n\t\t  day    : ";
		 cout<<dayj;
		 cout<<"\n\t\t  month : ";
		 cout<<monthj;
		 cout<<"\n\t\t  year  : ";
		 cout<< yearj;

		 cout<<"\n\t\t  qualification : ";
		 puts(qualification);
		 cout<<"\n\t\t enter department : ";
		 puts(department);
		 cout<<"\n\t\t  job title : ";
		 puts(jobtitle);
		 cout<<"\n\t\t  basic pay : ";
		 puts(basicpay);
	  }
		f20.close();


}
contniue();
}
}


void studetails :: searchregno()
{

clrscr();
int n;
char reno[10];
 for(int  i=0;i<80;i++)
  cout<<"*";
		cout<<"\n\n\t\t enter registration number\n\t\t ";
		gets(reno);
		cout<<"\n\t\t searching based on registration number \n\t\t  ";
		ifstream f21;
		f21.open("student",ios::binary) ;

		while(!f21)
{
cerr<<"File not found. \n\t\t";
}
		while(f21.read((char*)&sd,sizeof(sd)))
		{
		if((strcmp(sd.regno,reno))==0)
		 {
		 cout<<"\n\t\t student found \n\t\t ";
		 cout<<"\n\t\t do you want the staff details:\n\t\t";
		 cout<<"if yes enter 1\n\t\t";
		 cout<<"if no enter 0 \n\t\t";
		 cin>>n;
		 if(n==1)
		 {
		  cout<<"\n\t\t  name\n\t\t ";
		 puts(name);
		 cout<<"\n\t\t  registration number \n\t\t ";
		 puts(regno);
		 cout<<" \n\t\t gender \n\t\t ";
		 puts(gender);
		 cout<<"\n\t\t  address\n\t\t ";
		 puts(address);
		 cout<<"\n\t\t  parents contact no \n\t\t ";
		 puts(pcontactno);

//for date of birth
		cout<<"\n\t\t  date of birth \n\t\t ";
		cout<<"\n\t\t  day   \n\t\t ";
		cout<<dayb;
		cout<<"\n\t\t  month     \n\t\t ";
		cout<<monthb;
		cout<<"\n\t\t  year  \n\t\t ";
		cout<< yearb;

//for date of admission
		cout<<"\n\t\t date of admission \n\t\t ";
		cout<<"\n\t\t  day    \n\t\t ";
		cout<<daya;
		cout<<"\n\t\t  month   \n\t\t ";
		cout<<montha;
		cout<<"\n\t\t  year  \n\t\t ";
		cout<< yeara;

		cout<<"\n\t\t  section \n\t\t ";
		cout<<section;
		cout<<"\n\t\t class \n\t\t ";
		cout<< sclass;
		cout<<"\n\t\t  roll number\n\t\t ";
		puts(rollno);
	}
	}
	}

f21.close();
contniue();
}




void studetails :: searchnamepphoneno()
{
 clrscr();
 int n;
char nam[20],num[10] ;

		cout<<"\n\t\t enter name\n\t\t ";
		gets(nam);
		cout<<"\n\t\t enter phone number\n\t\t ";
		gets(num);
		cout<<"\n\t\t searching based on name and phone number \n\t\t  "  ;
		ifstream f22;
		f22.open("student",ios::binary) ;
		while(!f22)
{
cerr<<"File not found. \n\t\t";
}
		while(f22.read((char*)&sd,sizeof(sd)))
		{
		if(strcmp(sd.pcontactno,num)==0)
		 {if(strcmpi(name,nam)==0)
		cout<<"\n\t\t student found \n\t\t ";
		cout<<"\n\t\t do you want the student details if yes enter 1,if no enter 0. \n\t\t  ";
		cin>>n;
		 if(n==1)
		 {
		 cout<<"\n\t\t  name \n\t\t ";
		 puts(name);
		 cout<<"\n\t\t  registration number\n\t\t ";
		 puts(regno);
		 cout<<"\n\t\t  gender \n\t\t ";
		 puts(gender);
		 cout<<"\n\t\t  address\n\t\t ";
		 puts(address);
		 cout<<" \n\t\t parents contact no \n\t\t ";
		 puts(pcontactno);

//for date of birth
		 cout<<"\n\t\t  date of birth\n\t\t ";
		 cout<<"\n\t\t  day \n\t\t ";
		 cout<<dayb;
		 cout<<"\n\t\t  month    \n\t\t ";
		 cout<<monthb;
		 cout<<"\n\t\t  year \n\t\t ";
		 cout<< yearb;

//for date of admission
		cout<<"\n\t\t date of admission \n\t\t ";
		cout<<" \n\t\t day  \n\t\t ";
		cout<<daya;
		cout<<"\n\t\t  month    \n\t\t ";
		cout<<montha;
		cout<<"\n\t\t  year  \n\t\t ";
		cout<< yeara;

	  cout<<"\n\t\t  section \n\t\t ";
	  cout<<section;
	  cout<<"\n\t\t class \n\t\t ";
	  cout<< sclass;
	  cout<<"\n\t\t  roll number \n\t\t ";
	  puts(rollno);
	}
	f22.close();
	contniue();
}
}
}

  void studetails :: displaystudentdetails()
{


  ifstream f23;
		f23.open("student",ios::binary);
		while(!f23)
{
cerr<<"File not found. \n\t\t";
}
		while(f23.read((char*)&sd,sizeof(sd)))
		 {
		 cout<<"\n\t\t  name \n\t\t ";
		 puts(name);
		 cout<<"\n\t\t  registration number \n\t\t ";
		 puts(regno);
		 cout<<"\n\t\t  gender \n\t\t ";
		 puts(gender);
		 cout<<"\n\t\t  address\n\t\t ";
		 puts(address);
		 cout<<"\n\t\t  parents contact no \n\t\t ";
		 puts(pcontactno);

//for date of birth
		 cout<<"\n\t\t  date of birth \n\t\t ";
		 cout<<" \n\t\t day  \n\t\t ";
		 cout<<dayb;
		 cout<<" \n\t\t month   \n\t\t ";
		 cout<<monthb;
		 cout<<" year     \n";
	    cout<< yearb;

//for date of admission
		cout<<"\n\t\t date of admission \n\t\t ";
		cout<<"\n\t\t  day    \n\t\t ";
		cout<<daya;
		cout<<"\n\t\t  month  \n\t\t ";
		cout<<montha;
		cout<<"\n\t\t  year  \n\t\t ";
		cout<< yeara;

		cout<<"\n\t\t  section \n\t\t ";
		cout<<section;
		cout<<"\n\t\t class \n\t\t ";
		cout<< sclass;
		cout<<"\n\t\t  roll number \n\t\t ";
		puts(rollno);
		cout<<"marks";
		cout<<marks;
		cout<<"\n\t\t result\n\t\t ";
		cout<<result;
		cout<<"\n\t\t maximummark \n\t\t " ;
		cout<<maximummark;
		cout<<"\n\t\t passmark \n\t\t ";
		cout<<avg;
	}
	f23.close();
	contniue();
}

void contniue()
{

ax:
char a[3];
 cout<<"\n\t\t  do you want to go back to the main yes or no \n\t\t ";
 gets(a);
 if(strcmp(a,"yes")==0)
 { cout<< "\n\t\t  going back to main \n\t\t " ;
 }
 else
 if(strcmp(a,"no")==0)
 { goto ax ;
 }

  else
  {cout<<" \n\t\t invalid option \n\t\t ";
  goto ax;
 }
 }

  void staffdetails ::  entercontactno()
  { ax:
	 int i=0,l,flag=0;
	cout<<" \n\t\t enter contact no \n\t\t ";
	gets(contactno);
	l=strlen(contactno);
	for(i=0;i<l;i++)
	 if((isdigit(contactno[i])))
	 {if((l==8)||(l==10))
		flag=0;

	 else
	 flag=1;
	 }
	  else
	 flag=1;


	if(flag==1)
  {cout<<"\n\t\t invalid option \n\t\t ";
	 goto ax;
	 }
  }

  void staffdetails ::  enterbasicpay()
	 { ax:
	 int i=0,l,flag=0;
	cout<<"\n\t\t enter basic pay \n\t\t ";
	gets(basicpay);
	l=strlen(basicpay);
	for(i=0;i<l;i++)
	 if(!(isdigit(basicpay[i])))
	 flag=1;

	if(flag==1)
  {cout<<"\n\t\t invalid option \n\t\t ";
	 goto ax;
	 }
  }

  void studetails :: enterpcontactno()
	 {
	  ax:
	 int i=0,l,flag=0;
	cout<<"\n\t\t enter  parent contact no \n\t\t ";
	gets(pcontactno);
	l=strlen(pcontactno);
	for(i=0;i<l;i++)
	  if((isdigit(pcontactno[i])))
	 {if((l==8)||(l==10))
		flag=0;

	 else
	 flag=1;
	 }
	  else
	 flag=1;


	if(flag==1)
  {cout<<" \n\t\t invalid option \n\t\t ";
	 goto ax;
	 }
  }

  void studetails ::  enterrollno()
	 { ax:
	 int i=0,l,flag=0;
	cout<<"\n\t\t enter roll number \n\t\t ";
	gets(rollno);
	l=strlen(rollno);
	for(i=0;i<l;i++)
	 if(!(isdigit(rollno[i])))
	 flag=1;

	if(flag==1)
  {cout<<"\n\t\t invalid option \n\t\t ";
	 goto ax;
	 }
  }

  void staffdetails :: checkdob()
	{     aq:
	//for date of birth
	cout<<"\n\t\t enter date of birth \n ";
	cout<<"\n\t\t enter date  \n\t\t ";
	cin>>dayb;
	cout<<"\n\t\t enter month  \n\t\t ";
	cin>>monthb;
	cout<<"\n\t\t enter year  \n\t\t ";
	cin>> yearb;
	if((yearb/4)==0)
	{if(monthb==2)
	{ if(dayb<=29)
	{ cout<<"\n\t\t valid birth date \n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid \n\t\t ";
	 goto aq;
	 }
	 }
	 else
	 {
	 if(((monthb==1)||(monthb==3)||(monthb==5)||(monthb==7)||(monthb==8)||(monthb==10)||(monthb==12)))
	 {if(dayb<=31)
	 cout<<"\n\t\t valid birth date \n\t\t ";
	  else
	{ cout<<"\n\t\t invalid birth date \n\t\t ";
	 goto aq;
	 }
	 }
	else
	{

	if(dayb<=30)
	 {cout<<"\n\t\t valid birth date \n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid \n\t\t ";
	 goto aq;
	  }
	  }
	 }

	}
	 else
	 {
	 if((yearb/4)!=0)
	{if(monthb==2)
	{ if(dayb<=28)
	{ cout<<"\n\t\t valid birth date \n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid \n\t\t ";
	 goto aq;
	 }
	 }
	 else
	 {
	 if(((monthb==1)||(monthb==3)||(monthb==5)||(monthb==7)||(monthb==8)||(monthb==10)||(monthb==12)))
	 {if(dayb<=31)
	 cout<<" \n\t\t valid birth date \n\t\t ";
	  else
	 {cout<<"\n\t\t invalid birth date \n\t\t ";
	 goto aq;
	 }
	  }
	else
	{

	if(dayb<=30)
	 {cout<<"\n\t\t valid birth date \n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid\n\t\t ";
	 goto aq;
	  }
	  }
	 }
	 }
	  }
	  }
  void staffdetails :: checkdoj()
  {     aq:
  //for date of join

	cout<<"\n\t\t enter date of join \n\t\t ";
	cout<<"\n\t\t  enter day  \n\t\t ";
	cin>>dayj;
	cout<<"\n\t\t enter month  \n\t\t ";
	cin>>monthj;
	cout<<"\n\t\t enter year  \n\t\t ";
	cin>> yearj;

  if((yearj/4)==0)
	{if(monthj==2)
	{ if(dayj<=29)
	{ cout<<"\n\t\t  valid birth date \n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid \n\t\t ";
	 goto aq;
	 }
	 }
	 else
	 {
	 if(((monthj==1)||(monthj==3)||(monthj==5)||(monthj==7)||(monthj==8)||(monthj==10)||(monthj==12)))
	 {if(dayj<=31)
	 cout<<" \n\t\t valid birth date \n\t\t ";
	  else
	{ cout<<"\n\t\t invalid birth date \n\t\t ";
	 goto aq;
	 }
	 }
	else
	{

	if(dayj<=30)
	 {cout<<"\n\t\t valid birth date \n\t\t ";
	 }
	 else
	 {cout<<" \n\t\t invalid \n\t\t ";
	 goto aq;
	  }
	  }
	 }

	}
	 else
	 {
	 if((yearj/4)!=0)
	{if(monthj==2)
	{ if(dayj<=28)
	{ cout<<"\n\t\t valid birth date \n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid \n\t\t ";
	 goto aq;
	 }
	 }
	 else
	 {
	 if(((monthj==1)||(monthj==3)||(monthj==5)||(monthj==7)||(monthj==8)||(monthj==10)||(monthj==12)))
	 {if(dayj<=31)
	 cout<<"\n\t\t valid birth date \n\t\t ";
	  else
	{ cout<<"\n\t\t invalid birth date \n\t\t ";
	 goto aq;
	 }
	}
	else
	{

	if(dayj<=30)
	 {cout<<"\n\t\t valid birth date \n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid \n\t\t ";
	 goto aq;
	  }
	  }
	 }
	 }
	  }

  }


  void studetails :: checkdob()
  {     aq:
	//for date of birth
	cout<<"\n\t\t enter date of birth \n\t\t ";
	cout<<"enter date    \n\t\t ";
	cin>>dayb;
	cout<<"\n\t\t enter month    \n\t\t ";
	cin>>monthb;
	cout<<"\n\t\t enter year \n\t\t ";
	cin>> yearb;
	if((yearb/4)==0)
	{if(monthb==2)
	{ if(dayb<=29)
	{ cout<<"\n\t\t valid birth date\n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid\n\t\t ";
	 goto aq;
	 }
	 }
	 else
	 {
	 if(((monthb==1)||(monthb==3)||(monthb==5)||(monthb==7)||(monthb==8)||(monthb==10)||(monthb==12)))
	 {if(dayb<=31)
	 cout<<"\n\t\t valid birth date\n\t\t ";
	  else
	 {cout<<"\n\t\t invalid birth date\n\t\t ";
	 goto aq;
	 }
  }
	else
	{

	if(dayb<=30)
	 {cout<<"\n\t\t valid birth date\n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid\n\t\t ";
	 goto aq;
	  }
	  }
	 }

	}
	 else
	 {
	 if((yearb/4)!=0)
	{if(monthb==2)
	{ if(dayb<=28)
	{ cout<<"\n\t\t valid birth date \n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid\n\t\t ";
	 goto aq;
	 }
	 }
	 else
	 {
	 if(((monthb==1)||(monthb==3)||(monthb==5)||(monthb==7)||(monthb==8)||(monthb==10)||(monthb==12)))
	 {if(dayb<=31)
	 cout<<"\n\t\t valid birth date\n\t\t ";
	  else
	{ cout<<"\n\t\t invalid birth date\n\t\t" ;
	 goto aq;
	 }
	 }
	else
	{

	if(dayb<=30)
	 {cout<<"\n\t\t valid birth date\n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid\n\t\t ";
	 goto aq;
	  }
	  }
	 }
	 }
	  }
	  }

  void studetails :: checkdoa()
 {     aq:
 //for date of admission
	cout<<"\n\t\t enter date of admission \n\t\t ";
	 cout<<"\n\t\t enter date    \n\t\t ";
	 cin>>daya;
	 cout<<"\n\t\t enter month   \n\t\t ";
	 cin>>montha;
	 cout<<"\n\t\t enter year    \n\t\t ";
	 cin>> yeara;

	if((yeara/4)==0)
	{if(montha==2)
	{ if(daya<=29)
	{ cout<<"\n\t\t valid birth date\n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid\n\t\t ";
	 goto aq;
	 }
	 }
	 else
	 {
	 if(((montha==1)||(montha==3)||(montha==5)||(montha==7)||(montha==8)||(montha==10)||(montha==12)))
	 {if(daya<=31)
	 cout<<"\n\t\t valid birth date\n\t\t ";
	  else
	 {cout<<"\n\t\t invalid birth date\n\t\t ";
	 goto aq;
	 }
	  }
	else
	{

	if(daya<=30)
	 {cout<<"\n\t\t valid birth date\n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid\n\t\t ";
	 goto aq;
	  }
	  }
	 }

	}
	 else
	 {
	 if((yeara/4)!=0)
	{if(montha==2)
	{ if(daya<=28)
	{ cout<<"\n\t\t valid birth date\n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid\n\t\t ";
	 goto aq;
	 }
	 }
	 else
	 {
	 if(((montha==1)||(montha==3)||(montha==5)||(montha==7)||(montha==8)||(montha==10)||(montha==12)))
	 {if(daya<=31)
	 cout<<"\n\t\t valid birth date\n\t\t ";
	  else
	 {cout<<"\n\t\t invalid birth date\n\t\t ";
	 goto aq;
	 }
	  }
	else
	{

	if(daya<=30)
	 {cout<<"\n\t\t valid birth date\n\t\t ";
	 }
	 else
	 {cout<<"\n\t\t invalid \n\t\t ";
	 goto aq;
	  }
	  }
	 }
	 }
}
}

void displaylast()
{  int a4;
ao:    clrscr();

cout<<"\n\n";
for(int i=0;i<80;i++)
  cout<<"*";

cout<<"\n\n choose one of the below options\n\n";
for( i=0;i<80;i++)
  cout<<"*";

cout<<"\n\t\t 1.display based on date of join for staff\n";
cout<<"\t\t 2.display based on date of admission for student \n";
cout<<"\t\t 3.display based on the class of student \n";
cout<<"\t\t 4.display based on marks \n";
cout<<"\t\t enter any one of the above details \n";
cin>>a4;
 if(a4==1)
{
 st.dbodoj();
 goto ao;
}

else if(a4==2)
 {
sd.dbodoa() ;
 goto ao;
 }
else if(a4==3)
{
 sd.dboc();
 goto ao;
}

else if(a4==4)
 {
 sd.dbom();
 goto ao;
 }
else
{cout<<"invalid option";
goto ao;
}
}

void staffdetails :: dbodoj()
{
aq:
 clrscr();
int daj,montj,yeaj;
  //for date of join

	cout<<"\n\t\t enter date of join \n\t\t ";
	cout<<"\n\t\t  enter day  \n\t\t ";
	cin>>daj;
	cout<<"\n\t\t enter month  \n\t\t ";
	cin>>montj;
	cout<<"\n\t\t enter year  \n\t\t ";
	cin>> yeaj;

	ifstream fx22;
	fx22.open("staff",ios::binary);
	while(!fx22)
{
cerr<<"File not found. \n\t\t";
}
	while(fx22.read((char*)&st,sizeof(st)))
	{ if((dayj==daj)&&(monthj==montj)&&(yearj==yeaj))
	{
	cout<<"\n\t\t  name \n\t\t ";
	puts(name);
	cout<<"\n\t\t  gender \n\t\t ";
puts(gender);
 cout<<"\n\t\t nalalanda ID \n\t\t " ;
 puts(nalalandaid);
 cout<<"\n\t\t  address \n\t\t ";
	puts(address);
	 cout<<"\n\t\t  contact no \n\t\t ";
  puts(contactno);

//for date of birth
 cout<< "\n\t\t date of birth \n\t\t ";
	cout<<"\n\t\t  day   \n\t\t ";
	  cout<<dayb;
	 cout<<"\n\t\t  month     \n\t\t ";
	  cout<<monthb;
	 cout<<"\n\t\t  year  \n\t\t ";
	 cout<< yearb;

//for date of join
	cout<<"\n\t\t date of join \n\t\t ";
	cout<<"\n\t\t  day    \n\t\t ";
	  cout<<dayj;
	 cout<<"\n\t\t  month \n\t\t ";
	  cout<<monthj;
	 cout<<"\n\t\t  year  \n\t\t ";
	 cout<< yearj;

	  cout<<"\n\t\t  qualification \n\t\t ";
	puts(qualification);
	 cout<<"\n\t\t enter department \n\t\t ";
	puts(department);
	 cout<<"\n\t\t  job title \n\t\t ";
	puts(jobtitle);
	 cout<<"\n\t\t  basic pay \n\t\t ";
	 puts(basicpay);
	  }
		fx22.close();

 }

contniue();

}


void studetails :: dbodoa()
{
aq:
int daa,monta,yeaa;
  //for date of join

	cout<<"\n\t\t enter date of join \n\t\t ";
	cout<<"\n\t\t  enter day  \n\t\t ";
	cin>>daa;
	cout<<"\n\t\t enter month  \n\t\t ";
	cin>>monta;
	cout<<"\n\t\t enter year  \n\t\t ";
	cin>> yeaa;

	ifstream fx19;
	fx19.open("student",ios::binary);
	while(!fx19)
{
cerr<<"File not found. \n\t\t";
}
	while(fx19.read((char*)&sd,sizeof(sd)))
	{ if((daya==daa)&&(montha==monta)&&(yeara==yeaa))
	{ cout<<"\n\t\t  name \n\t\t ";
		 puts(name);
		cout<<"\n\t\t  registration number \n\t\t ";
	puts(regno);
	cout<<"\n\t\t  gender \n\t\t ";
	puts(gender);
	cout<<"\n\t\t  address\n\t\t ";
	puts(address);
	 cout<<"\n\t\t  parents contact no \n\t\t ";
	 puts(pcontactno);

//for date of birth
	cout<<"\n\t\t  date of birth \n\t\t ";
	cout<<" \n\t\t day  \n\t\t ";
	 cout<<dayb;
	 cout<<" \n\t\t month   \n\t\t ";
	 cout<<monthb;
	 cout<<" year     \n";
	 cout<< yearb;

//for date of admission
	cout<<"\n\t\t date of admission \n\t\t ";
	cout<<"\n\t\t  day    \n\t\t ";
	 cout<<daya;
	 cout<<"\n\t\t  month  \n\t\t ";
	 cout<<montha;
	 cout<<"\n\t\t  year  \n\t\t ";
	 cout<< yeara;

	  cout<<"\n\t\t  section \n\t\t ";
	 cout<<section;
	 cout<<"\n\t\t class \n\t\t ";
	 cout<< sclass;
	  cout<<"\n\t\t  roll number \n\t\t ";
	puts(rollno);
		 cout<<"marks";
	 cout<<marks;
	 cout<<"result";
	 cout<<result;
	 cout<<"maximummark" ;
	 cout<<maximummark;
	 cout<<"passmark";
	 cout<<avg;

	  }
		fx19.close();


}
contniue();
}

 void studetails :: dboc()
{

int clas;
	cout<<"enter class to be displayed";
	cin>>clas;
	ifstream fx20;
	fx20.open("student",ios::binary);
	while(!fx20)
{
cerr<<"File not found. \n\t\t";
}
	while(fx20.read((char*)&sd,sizeof(sd)))
	{ if(sclass==clas)
	{ cout<<"\n\t\t  name \n\t\t ";
		 puts(name);
		cout<<"\n\t\t  registration number \n\t\t ";
	puts(regno);
	cout<<"\n\t\t  gender \n\t\t ";
	puts(gender);
	cout<<"\n\t\t  address\n\t\t ";
	puts(address);
	 cout<<"\n\t\t  parents contact no \n\t\t ";
	 puts(pcontactno);

//for date of birth
	cout<<"\n\t\t  date of birth \n\t\t ";
	cout<<" \n\t\t day  \n\t\t ";
	 cout<<dayb;
	 cout<<" \n\t\t month   \n\t\t ";
	 cout<<monthb;
	 cout<<" year     \n";
	 cout<< yearb;

//for date of admission
	cout<<"\n\t\t date of admission \n\t\t ";
	cout<<"\n\t\t  day    \n\t\t ";
	 cout<<daya;
	 cout<<"\n\t\t  month  \n\t\t ";
	 cout<<montha;
	 cout<<"\n\t\t  year  \n\t\t ";
	 cout<< yeara;

	  cout<<"\n\t\t  section \n\t\t ";
	 cout<<section;
	 cout<<"\n\t\t class \n\t\t ";
	 cout<< sclass;
	  cout<<"\n\t\t  roll number \n\t\t ";
	puts(rollno);
		 cout<<"\n\t\t marks\n\t\t ";
	 cout<<marks;
	 cout<<"\n\t\t result\n\t\t ";
	 cout<<result;
	 cout<<"\n\t\t maximummark\n\t\t " ;
	 cout<<maximummark;
	 cout<<"\n\t\t passmark\n\t\t ";
	 cout<<avg;

	  }
		fx20.close();


}
contniue();
}





void studetails :: dbom()
{



	ifstream fx21;
	fx21.open("student",ios::binary);
	while(!fx21)
{
cerr<<"File not found. \n\t\t";
}
	while(fx21.read((char*)&sd,sizeof(sd)))
	{ if(marks>50)
	{cout<<"marks greater than 50";
	 cout<<"\n\t\t  name \n\t\t ";
		 puts(name);
		cout<<"\n\t\t  registration number \n\t\t ";
	puts(regno);
	cout<<"\n\t\t  gender \n\t\t ";
	puts(gender);
	cout<<"\n\t\t  address\n\t\t ";
	puts(address);
	 cout<<"\n\t\t  parents contact no \n\t\t ";
	 puts(pcontactno);

//for date of birth
	cout<<"\n\t\t  date of birth \n\t\t ";
	cout<<" \n\t\t day  \n\t\t ";
	 cout<<dayb;
	 cout<<" \n\t\t month   \n\t\t ";
	 cout<<monthb;
	 cout<<" year     \n";
	 cout<< yearb;

//for date of admission
	cout<<"\n\t\t date of admission \n\t\t ";
	cout<<"\n\t\t  day    \n\t\t ";
	 cout<<daya;
	 cout<<"\n\t\t  month  \n\t\t ";
	 cout<<montha;
	 cout<<"\n\t\t  year  \n\t\t ";
	 cout<< yeara;

	  cout<<"\n\t\t  section \n\t\t ";
	 cout<<section;
	 cout<<"\n\t\t class \n\t\t ";
	 cout<< sclass;
	  cout<<"\n\t\t  roll number \n\t\t ";
	puts(rollno);
		 cout<<"marks";
	 cout<<marks;
	 cout<<"result";
	 cout<<result;
	 cout<<"maximummark" ;
	 cout<<maximummark;
	 cout<<"passmark";
	 cout<<avg;

	  }
	  else
	  if(marks=50)

 {  	cout<<"marks lequal to 50";
 cout<<"\n\t\t  name \n\t\t ";
		 puts(name);
		cout<<"\n\t\t  registration number \n\t\t ";
	puts(regno);
	cout<<"\n\t\t  gender \n\t\t ";
	puts(gender);
	cout<<"\n\t\t  address\n\t\t ";
	puts(address);
	 cout<<"\n\t\t  parents contact no \n\t\t ";
	 puts(pcontactno);

//for date of birth
	cout<<"\n\t\t  date of birth \n\t\t ";
	cout<<" \n\t\t day  \n\t\t ";
	 cout<<dayb;
	 cout<<" \n\t\t month   \n\t\t ";
	 cout<<monthb;
	 cout<<" year     \n";
	 cout<< yearb;

//for date of admission
	cout<<"\n\t\t date of admission \n\t\t ";
	cout<<"\n\t\t  day    \n\t\t ";
	 cout<<daya;
	 cout<<"\n\t\t  month  \n\t\t ";
	 cout<<montha;
	 cout<<"\n\t\t  year  \n\t\t ";
	 cout<< yeara;

	  cout<<"\n\t\t  section \n\t\t ";
	 cout<<section;
	 cout<<"\n\t\t class \n\t\t ";
	 cout<< sclass;
	  cout<<"\n\t\t  roll number \n\t\t ";
	puts(rollno);
		 cout<<"marks";
	 cout<<marks;
	 cout<<"result";
	 cout<<result;
	 cout<<"maximummark" ;
	 cout<<maximummark;
	 cout<<"passmark";
	 cout<<avg;

	  }
  else
  {cout<<"marks less than 50";
  cout<<"\n\t\t  name \n\t\t ";
		 puts(name);
		cout<<"\n\t\t  registration number \n\t\t ";
	puts(regno);
	cout<<"\n\t\t  gender \n\t\t ";
	puts(gender);
	cout<<"\n\t\t  address\n\t\t ";
	puts(address);
	 cout<<"\n\t\t  parents contact no \n\t\t ";
	 puts(pcontactno);

//for date of birth
	cout<<"\n\t\t  date of birth \n\t\t ";
	cout<<" \n\t\t day  \n\t\t ";
	 cout<<dayb;
	 cout<<" \n\t\t month   \n\t\t ";
	 cout<<monthb;
	 cout<<" year     \n";
	 cout<< yearb;

//for date of admission
	cout<<"\n\t\t date of admission \n\t\t ";
	cout<<"\n\t\t  day    \n\t\t ";
	 cout<<daya;
	 cout<<"\n\t\t  month  \n\t\t ";
	 cout<<montha;
	 cout<<"\n\t\t  year  \n\t\t ";
	 cout<< yeara;

	 cout<<"\n\t\t  section \n\t\t ";
	 cout<<section;
	 cout<<"\n\t\t class \n\t\t ";
	 cout<< sclass;
	 cout<<"\n\t\t  roll number \n\t\t ";
	 puts(rollno);
	 cout<<"marks";
	 cout<<marks;
	 cout<<"result";
	 cout<<result;
	 cout<<"maximummark" ;
	 cout<<maximummark;
	 cout<<"passmark";
	 cout<<avg;

	  }
	  }



		fx21.close();


contniue();
}









