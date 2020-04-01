#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>                
#include<iomanip.h>           
char loginname[20];             
void space(int,int);              
void dash(int);                   
void back(int);
void header(int);
void introscreen();                                // welcome screen
void homepage();                                 // home page
void credits();                                        // credits page
void userscreen();                                // user menu (before login)
void usermode();                                 // user home(after login)
void admin_login();                             // admin page(to get admin password)
void adminmode();                             // admin options menu
void addtrain();                                   // to add a new train
void getpass(char[]);                          // to input password
int checkdoj(int,int,int);                    // to check date validity
int checktime(int,int);                       // to check time validity
int captcha();                                       // to generate captcha
int payment_gateway(float);           // to get payment details like card no, etc.
void delay(int);                                   // for time delay


void main()
{
 introscreen();
}

void delay(int a)
{
 long int i;
 int j;
 for(j=0;j<a;j++)
   {
     for(i=0;i<99999999;i++);
     for(i=0;i<99999999;i++);
   }
 }

void space(int x,int y=0)
{
  for(int i=0;i<y;i++)
       cout<<endl;
  for(i=0;i<x;i++)
       cout<<' ';
}

void dash(int x)
{
  for(int i=0;i<x;i++)
       cout<<'-';
}

void header(int x)
{
  clrscr();
  cout<<endl;
  dash(80);
  switch(x)
  {
	 case 1:    space(34);
		       cout<<"LOGIN\n";
		       break;
	 case 2:    space(30);
		       cout<<"TICKET BOOKING\n";
		        break;
	 case 3:    space(30);
		        cout<<"BOOKING HISTORY\n";
		        break;
	 case 4:    space(28);
		        cout<<"TICKET CANCELLATION\n";
		        break;
	 case 5:    space(31);
		        cout<<"TRAIN SEARCH\n";
		        break;
	 case 6:    space(33);
		        cout<<"ADD TRAIN\n";
		        break;
	 case 7:    space(32);
		        cout<<"REMOVE TRAIN\n";
		        break;
	 case 8:    space(32);
		        cout<<"ADMIN HOME\n";
		        break;
	 case 9:    space(33);
		        cout<<"HOMEPAGE\n";
		        break;
	 case 10:    space(33);
		        cout<<"REGISTER\n";
		        break;
	 case 11:    space(32);
		        cout<<"MODIFY TRAIN\n";
		        break;
	 case 12:    space(33);
		        cout<<"PAYMENT\n";
		        break;
   }
    dash(80);
}

class user
{
 char username[25];
 char password[25];
 int age;
 char addr[80];
 double phno;
 public:
 user()
 {
   strcpy(username,"0000");
   strcpy(password,"0000");
 }
 user(char usname[],char pword[],int a,char add[],double pno)
 {
  strcpy(username,usname);
  strcpy(password,pword);
  age=a;
  strcpy(addr,add);
  phno=pno;
 }
 void user_register();                   // member function(mf) for new user registration
 void user_login();                        // mf for login of existing user
};

int checktime(int h,int m)
{
  if(h<24&&h>=0&&m<60&&m>=0)
	 return 1;
  else return 0;
}

class train
{
  double ticketno;
  int seatno;
  char username[30];
  long int trainno;
  char trainname[30];
  char from[30];
  char to[30];
  int dojd;                                       // variables for date of journey date, month and year
  int dojm;
  int dojy;
  int dthour;                                  // variables for departure and arrival hour, minutes
  int dtmin;
  int athour;
  int atmin;
  float fare; 
  int seats;
  public:
  train()
  {
	seats=100;
	fare=500;
  }
  void addtrain2();                                  // mf to input new train details
  void display(int x);                               // mf to display a train record
  void changeseat(long int,int);          /* mf to increment/decrement total seats in a train after                                                                          .                                                                    cancelling/booking a ticket */
  void cancelticket();                              // mf to cancel a ticket
  void bookticket();                                 // mf to book a ticket
  void searchtrain();                               // mf to search a particular train
  void deletetrain();                               // mf to delete a train record
  void modifytrain();                              // mf to modify a train record
  void bookinghistory(int);                   // mf to view booking history
};

void train::changeseat(long int trno,int x)
{
  train t;
  ifstream f1;
  ofstream f2;
  f1.open("tf.dat",ios::binary);
  f2.open("tempfile.dat",ios::binary);
  while(f1.read((char*)&t,sizeof(t)))
	if(trno==t.trainno)
	{
	  t.seats+=x;
	  f2.write((char*)&t,sizeof(t));
	}
	else
	  f2.write((char*)&t,sizeof(t));

  remove(("tf.dat"));
  rename("tempfile.dat","tf.dat");
  f1.close();
  f2.close();
}

void train::addtrain2()
{
  dash(80);
  cout<<" ENTER TRAIN DETAILS:\n";
  dash(80);
  cout<<" Train No: ";
  cin>>trainno;
  cout<<"\n From:  ";
  gets(from);
  cout<<"\n To:    ";
  gets(to);
  cout<<"\n Train Name: ";
  gets(trainname);
  repeat:
  cout<<"\n Departure Time: (24 hr format)";
  cout<<"\n   Hours: ";
  cin>>dthour;
  cout<<"   Minutes: ";
  cin>>dtmin;
  if(checktime(dthour,dtmin)==0)
  {
       cout<<" Invalid time! Enter again\n";
       goto repeat;
  }
  repeat2:
  cout<<"\n Arrival Time: (24 hr Format)";
  cout<<"\n   Hours: ";
  cin>>athour;
  cout<<"   Minutes: ";
  cin>>atmin;
  if(checktime(athour,atmin)==0)
  {
         cout<<"Invalid time! Enter again\n";
         goto repeat2;
  }
  cout<<"\n Fare: ";
  cin>>fare;
  cout<<"\n Total Seats: ";
  cin>>seats;
}

void train::display(int x)
{
  if(x==1)
  {
	 cout<<" Ticket No: "<<ticketno;
	 space(3,1);
	 cout<<"Passenger Name: ";
	 puts(username);
	 space(3);
	 cout<<"Date Of Journey: ";
	 if(dojd<10)
		cout<<"0";
	 cout<<dojd<<'\-';
	 if(dojm<10)
		cout<<"0";
	 cout<<dojm<<'\-'<<dojy;
	 cout<<"\n  ";
  }
  cout<<" Train No: "<<trainno;
  if(x==0)
       cout<<endl;
  cout<<"   Train Name: ";   puts(trainname);  space(3);
  cout<<"From: ";   cout.write(from,strlen(from));  space(3);
  cout<<"To: ";   puts(to);   space(3);
  cout<<"Departure: ";
  if(dthour<10)
        cout<<"0";
  cout<<dthour<<':';
  if(dtmin<10)
        cout<<"0";
  cout<<dtmin;space(3);
  cout<<"Arrival: ";
  if(athour<10)
        cout<<"0";
  cout<<athour<<':';
  if(atmin<10)
        cout<<"0";
  cout<<atmin;  space(3,1);
  if(x==1)
  {
           cout<<"Seat No: "<<seatno;
           space(3);
  }
  cout<<"Fare: "<<fare;space(3); 
  if(x==0)
           cout<<"Seats Available: "<<seats;
  cout<<endl;
}

void credits()
{
  clrscr();
  cout<<endl;
  dash(80);
  space(34);
  cout<<"CREDITS\n";
  dash(80);
  space(30,3);
  cout<<"PROJECT MADE BY";
  delay(2);
  space(33,4);
  cout<<"A.S.Kavin";
  space(35,2);
  cout<<"XII-B";
  delay(3);
  space(28,6);
  cout<<"Press any key to exit ";
  getch();
  homepage();
}

void introscreen()
{
 clrscr();
 cout<<"\n\n";
 dash(80);
 dash(80);
 space(25);
 cout<<"WELCOME TO INDIAN RAILWAYS\n\n";
 space(24);
 cout<<"PASSENGER RESERVATION SYSTEM\n";
 dash(80);
 dash(80);
 delay(2);
 space(25,3);
 cout<<"Press any key to continue ";
 getch();
 homepage();
}

void homepage()
{
 hp:
 clrscr();
 cout<<endl;
 header(9);
 int i=0;
 char ch;
 space(30,3);
 cout<<"1. USER MODE\n";
 space(30);
 cout<<"2. ADMIN MODE\n";
 space(30);
 cout<<"3. CREDITS\n";
 space(30);
 cout<<"4. EXIT\n";
 space(30,4);
 cout<<"Enter Option  ";
 cin>>i;
 switch(i)
 {
  case 1:    clrscr();
	    userscreen();
  case 2:    clrscr();
	    admin_login();
  case 3:    credits();
  case 4:    header(9);
	          space(21,6);
	          cout<<"Do you want to exit the portal? (y/n)  ";
	          cin>>ch;
	          if(ch=='y'||ch=='Y')
	               introscreen();
	          else
	               goto hp;
  default:      space(19,3);
		 cout<<"Invalid option! Press any key to enter again";
		 getch();
		 goto hp; 
   }
}

void userscreen()
{
 usmode:
 user u;
 clrscr();
 int a=0;
 char ch;
 cout<<endl;
 dash(80);
 space(33);
 cout<<"USER MENU\n";
 dash(80);
 space(30,4);
 cout<<"1. REGISTER\n";
 space(30);
 cout<<"2. LOGIN\n";
 space(30);
 cout<<"3. EXIT\n";
 space(30,4);
 cout<<"Enter Option  ";
 cin>>a;
 switch(a)
 {
  case 1: clrscr();
	        u.user_register();
  case 2: clrscr();
	        u.user_login();
  case 3: space(20,3);
		 cout<<"Do you want to exit user mode? (y/n)  ";
		 cin>>ch;
		 if(ch=='y'||ch=='Y')
		        homepage();
		 else
		        goto usmode;
  default:     space(19,3);
		  cout<<"Invalid option! Press any key to enter again ";
		  getch();
		  goto usmode;
   }
}

void user::user_register()
{
 fail:
 user u;
 int check1,check2;
 char p2[25];
 cout<<endl;
 header(10);
 space(15,3);
 cout<<"Enter Username: ";
 gets(username);
 ofstream temp("uf.dat",ios::binary|ios::app);
 temp.close();
 ifstream f3;
 f3.open("uf.dat",ios::binary);
 if(!f3)
 {
    check1=1;
 }
 else
 {
  while(f3.read((char*)&u,sizeof(u)))
  {
	check1=strcmp(u.username,username);
	if(check1==0)
	{
	  f3.close();
	  break;
	}
  }
 }
 if(check1==0)
 {
  space(22,2);
  cout<<"Entered username already exists!";
  space(24,2);
  cout<<"Press any key to enter again ";
  getch();
  clrscr();
  goto fail;
 }
 space(15,1);
 cout<<"Enter Age: ";
 cin>>age;
 space(15,1);
 cout<<"Enter Contact Number: ";
 cin>>phno;
 space(15,1);
 cout<<"Enter Residential Address: ";
 gets(addr);
 space(15,1);
 cout<<"Enter Password  : ";
 getpass(password);
 space(15,2);
 cout<<"Confirm Password: ";
 getpass(p2);
 space(32);
 check2=strcmp(password,p2);
 if(check2!=0)
 {
  space(18,2);
  cout<<"Password match error! Press any key to enter again ";
  getch();clrscr();
  goto fail;
 }
 if(check1!=0&&check2==0)
 {
	ofstream f4;
	f4.open("uf.dat",ios::binary|ios::app);
	f4.write((char*)this,sizeof(u));
	f4.close();
	header(10);
	space(27,5);
	cout<<"REGISTERED SUCCESSFULLY!\n";
	delay(3);
	userscreen();
 }

}
void user::user_login()
{
 again:
 user u;
 ifstream f;
 f.open("uf.dat",ios::binary);
 int c1,c2,c3;
 header(1);
 space(30,4);
 cout<<"Enter Username\n";
 space(32);
 gets(username);
 space(30,1);
 cout<<"Enter Password\n";
 space(32);
 getpass(password);
 while(f.read((char*)&u,sizeof(u)))
 {
	c1=strcmp(username,u.username);
	c2=strcmp(password,u.password);
	if(c1==0&&c2==0)
	  break;
 }
 cout<<endl;
 c3=captcha(); //captcha call and check
 if(c1!=0||c2!=0)
 {
  space(22,2);
  cout<<"Incorrect username or password!";
  space(24,2);
  cout<<"Press any key to enter again ";
  getch();
  clrscr();
  goto again;
 }
 if(c3!=1)
 {
  space(24,2);
  cout<<"Incorrect captcha! Enter again ";
  getch();
  goto again;
 }
 if(c1==0&&c2==0&&c3==1)
 {
  strcpy(loginname,username);
  clrscr();
  header(1);
  space(25,6);
  cout<<"LOGGED IN SUCCESSFULLY!\n";
  delay(3);
  clrscr();
  usermode();
 }

}
int captcha()
{
 cout<<endl;
 char a[6],choice[10];
 char num,ch1,ch2,i=0;
 randomize();
 for(i=0;i<6;i+=3)
 {
  num=random(10)+48;
  ch1=random(25)+65;
  ch2=random(25)+97;
  a[i]=ch1;
  a[i+1]=num;
  a[i+2]=ch2;
 }
 space(31);
 cout<<"Enter Captcha";
 space(20,1);
 cout<<"(Captcha letters are case sensitive)\n\n";
 space(33);
 for(i=0;i<6;i++)
       cout<<a[i];
 space(33,2);
 gets(choice);
 int flag=0;
 for(i=0;i<6;i++)
      if(a[i]!=choice[i])
      {
             flag=1;
	break;
      }
 if(flag==0)
     return 1;
 else
     return 0;
}

void usermode()
{
 repeat:
 train t;
 clrscr();
 char ch;
 int choice;
 dash(80);
 space(33);
 cout<<"HOME MENU\n";
 dash(80);
 space(3);
 cout<<"WELCOME \'"<<loginname<<"\'\n";
 dash(80);
 space(30,3);
 cout<<"1. BOOK TICKET\n";
 space(30);
 cout<<"2. BOOKING HISTORY\n";
 space(30);
 cout<<"3. CANCEL TICKET\n";
 space(30);
 cout<<"4. LOGOUT\n";
 space(30,3);
 cout<<"Enter option  ";
 cin>>choice;
 switch(choice)
 {
	case 1:    clrscr();
		         t.bookticket();
	case 2:    clrscr();
		         t.bookinghistory(0);
	case 3:    clrscr();
	                      t.cancelticket();
	case 4:    space(26,3);
		         cout<<"Do you want to logout? (y/n)  ";
		         cin>>ch; 
		         if(ch=='Y'||ch=='y')
			 homepage();
		         else
		  	 goto repeat;
	default:    space(19,3);
			cout<<"Invalid option! Press any key to enter again ";
			getch();
			clrscr();
			goto repeat;
    } 
}

void train::bookinghistory(int x)
{
  clrscr();
  header(3);
  train t;
  int flag=0,flag2=0;
  ifstream f;
  f.open("ticket.dat",ios::binary);
  if(!f)
  {
	 header(3);
	 space(22,4);
	 cout<<"NO RECENT BOOKING HISTORY FOUND!\n";
	 delay(3);
	 usermode();
  }
 else
 {
  char choice;
  if(x!=2)
  {
	 space(15,4);
	 cout<<"Do you want to view booking histroy? (y/n)  ";
	 cin>>choice;
	 clrscr();
  }
  else if(x==2)
	 choice='y';
  while(f.read((char*)&t,sizeof(t)))
	 flag2=1; 
  f.close();
  ifstream f2;
  f2.open("ticket.dat",ios::binary);
  if(choice=='y'||choice=='Y')
  {
	 if(flag2==1)
	 {
		header(3);
		cout<<"\n\n";
		cout<<" RECENT BOOKING HISTORY:\n";
		dash(80);
		cout<<endl;
		while(f2.read((char*)&t,sizeof(t)))
		 if(strcmp(t.username,loginname)==0)
		 {
			flag=1;
			t.display(1);
			cout<<endl;
			delay(1);
		 }
		 dash(80);
		 if(x!=2)
		 {
		 cout<<" Press any key to go back \n ";
		 getch();
		 usermode();
		 }
	 }
	 if(flag==0||flag2==0)
	 {
		clrscr();
		header(3);
		space(22,4);
		cout<<"NO RECENT BOOKING HISTORY FOUND!\n";
		delay(3);
		clrscr();
		usermode();
	 }

  }
  else
  {
	 header(3);
	 space(25,2);
	 cout<<" Press any key to exit  ";
	 getch();
	 clrscr();
	 usermode();
	}
    }
}

void train::cancelticket()
{
  repeat:
  header(4);
  train t;
  double tcno;
  char choice;
  ifstream f1;
  ofstream f2;
  f1.open(("ticket.dat"),ios::binary);
  f2.open("tempfile2.dat",ios::binary);
  if(!f1)
  {
	 header(4);
	 space(25,6);
	 cout<<"SORRY! NO BOOKED TICKETS FOUND!";
	 delay(3);
	 usermode();
  }
 else
 {
  space(15,4);
  cout<<"Do you want to view booking histroy? (y/n)  ";
  cin>>choice;
  if(choice=='y'||choice=='Y')
	  bookinghistory(2);
  else
  {
	 clrscr();
	 header(4);
	 space(20,4);
  }
  cout<<" Enter ticket no. to be cancelled \n ";
  cin>>tcno;
  clrscr();
  header(4);
  space(16,5);
  cout<<"Do you want to cancel ticket no. "<<tcno<<"? (y/n) ";
  cin>>choice;
  f1.close();
  if(choice=='Y'||choice=='y')
  {
	 int flag=0;
	 long int y;
	 ifstream f3;
	 f3.open("ticket.dat",ios::binary);
	 while(f3.read((char*)&t,sizeof(t)))
	 {
		if(tcno==t.ticketno)
		{
			flag=1;
			y=t.trainno;
		}
		else
		 f2.write((char*)&t,sizeof(t));
	 }
	 if (flag==1)
	 {
		remove(("ticket.dat"));
		rename("tempfile2.dat","ticket.dat");
		f3.close();
		f2.close();
		train t2;
		ifstream f5;
		f5.open("tf.dat",ios::binary);
		while(f5.read((char*)&t2,sizeof(t2)))
		{
		    if(y==t2.trainno)
		    {
			 t2.changeseat(y,1);
			 break;
		     }
		}
		clrscr();
		f5.close();
		header(4);
		space(20,5);
		cout<<"TICKET NO. "<<tcno<<" CANCELLED SUCCESSFULLY!\n";
		delay(3);
		header(4);
		space(18,6);
		cout<<"Do you want to cancel another ticket? (y/n)  ";
		cin>>choice;
		if(choice=='y'||choice=='Y')
		{
			clrscr();
			goto repeat;
		}
		else
		{
		     clrscr();
		     usermode();
		}
	 }
	 else
	 {
		clrscr();
		header(4);
		space(22,6);
		cout<<"SORRY! TICKET NO. "<<tcno<<" NOT FOUND!";
		delay(3);
		clrscr();
		usermode();
	 }
  }
  else
  {
	 clrscr();
	 header(4);
	 space(16,4);
	 cout<<"Do you want to exit ticket cancellation? (y/n)  ";
	 cin>>choice;
	 if(choice=='y'||choice=='Y')
	        usermode();
	 else
	        goto repeat; 
     }
  }
}

void admin_login()
{
  int tries=3;
  retry:
  clrscr();
  cout<<endl;
  header(1);
  cout<<"\n\n";
  char adminpword[]="admin";
  char pword1[30],pword2[30];
  if(tries!=3)
  {
	 space(30,2);
	 cout<<"Tries left = "<<tries;
	 delay(2);
	 cout<<"\n\n";
  }
  space(30,1);
  cout<<"Enter password\n";
  space(32);
  getpass(pword1);
  space(28,2);
  cout<<"Enter password again\n";
  space(32);
  getpass(pword2);
  if(strcmp(pword1,adminpword)!=0||strcmp(pword2,adminpword)!=0)
  {
	 tries--;
	 if(tries==0)
	 {
		clrscr();
		header(1);
		space(25,6);
		cout<<"Login failed! Try again later...\n";
		delay(3);
		homepage();
	 }
	 else if(tries!=0) 
	 {
		space(16,3);
		cout<<"Incorrect password! Press any key to enter again ";
		getch();
		goto retry;
	 }
  }
  else
    {
	 clrscr();
	 header(1);
	 space(25,6);
	 cout<<"ADMIN LOGIN SUCCESSFUL!\n";
	 delay(3);
	 clrscr();
	 adminmode();
    }
}
void adminmode()
{
 repeat:
 train t;
 clrscr();
 char ch;
 int choice;
 cout<<endl;
 header(8);
 space(30,3);
 cout<<"1. ADD TRAIN\n";
 space(30);
 cout<<"2. SEARCH TRAIN\n";
 space(30);
 cout<<"3. MODIFY TRAIN\n";
 space(30);
 cout<<"4. DELETE TRAIN\n";
 space(30);
 cout<<"5. EXIT\n";
 space(30,4);
 cout<<"Enter option ";
 cin>>choice;
 switch(choice)
 {
	case 1:   clrscr();
		       addtrain();
	case 2:   clrscr();
		       t.searchtrain();
	case 3:   clrscr();
		       t.modifytrain();
	case 4:   clrscr();
		       t.deletetrain();
	case 5:   header(8);
		       space(24,6);
		       cout<<"Do you want to logout? (y/n) ";
		       cin>>ch;
		       if(ch=='Y'||ch=='y')
		   	homepage();
		       else
			 goto repeat;
	default:  space(19,3);
			cout<<"Invalid option! Press any key to enter again ";
			getch();
			clrscr();
			goto repeat;
    }
}

void addtrain()                              
{
  masterrepeat:
  header(6);
  train t;
  ofstream f;
  f.open(("tf.dat"),ios::binary|ios::app);
  cout<<endl;
  t.addtrain2();
  f.write((char*)&t,sizeof(t));  
  f.close();
  clrscr();
  header(6);
  space(19,5);
  cout<<"TRAIN RECORD CREATED SUCCESSFULLY!";
  delay(3);
  header(6);
  space(16,6); 
  char choice='y';
  cout<<"Do you want to create another train record? (y/n)  ";
  cin>>choice;
  if(choice=='y'||choice=='Y')
  {
	clrscr();
	goto masterrepeat;
  }
  else
    {
	 clrscr();
	 adminmode();
    }
}

void train::searchtrain()
{
  repeat:
  cout<<endl;
  header(5);
  int choice;
  char choice1;
  long int trainno;
  char from[30],to[30];
  space(20,2);
  cout<<"How do you want to search a train?";
  space(27,3);
  cout<<"1. SEARCH BY \"FROM\" \n";
  space(27);
  cout<<"2. SEARCH BY \"TO\" \n";
  space(27);
  cout<<"3. SEARCH BY \"TRAIN NO\" \n";
  space(27);
  cout<<"4. VIEW ALL TRAINS \n";
  space(27);
  cout<<"5. EXIT ";
  space(27,3);
  cout<<"Enter option  ";
  cin>>choice;
  train t;
  int flag=0;
  ifstream f; 
  f.open(("tf.dat"),ios::binary);
  if(!f)
  {
	header(5);
	space(25,5);
	cout<<"Sorry! No trains found!";
	delay(3);
	adminmode();
  }
  else
  {
	if(choice==1)                                   //search by from
	{
	 header(5);
	 space(20,5);
	 cout<<"Enter \"from\" station to be searched\n";
	 space(30);
	 gets(from);
	 while(f.read((char*)&t,sizeof(t)))
  {
	  if(strcmpi(t.from,from)==0)
	  {
		  flag=1;
		  break;
	  }
	 }
	 f.seekg(0);
	 if(flag==0)
	 {
		header(5);
		space(17,5);
		cout<<" Sorry! No trains found from \"";
		cout.write(from,strlen(from)); cout<<'\"';
		delay(3);
		goto repeat;
	 }
	 else
	 {
		header(5);
		cout<<endl;
		dash(80);
		cout<<" SEARCH RESULTS:\n";
		dash(80); 
		cout<<endl;
		while(f.read((char*)&t,sizeof(t)))
		  if(strcmpi(t.from,from)==0)
		  {
			 t.display(0);
			 cout<<endl;
			 delay(1);
		  }
		dash(80);
		f.close();
	 }
	 cout<<" Do you want to search again? (y/n)  ";
	 cin>>choice1;
	 if(choice1=='y'||choice1=='Y')
	 {
		clrscr();
		goto repeat;
	 }
	 else
	 {
		clrscr();
		adminmode();
	 }
	}
	else if(choice==2)                                 //search by to
	{
	 header(5);
	 space(20,5);
	 cout<<"Enter \"to\" station to be searched";
	 space(30,1);
	 gets(to);
	 while(f.read((char*)&t,sizeof(t)))
		if(strcmpi(t.to,to)==0)
		{
			flag=1;
			break;
		}
	 f.seekg(0,ios::beg);
	 if(flag==0)
	 {
		header(5);
		space(20,5);
		cout<<" Sorry! No trains found to \"";
		cout.write(to,strlen(to)); cout<<'\"';
		delay(3);
		goto repeat;
	 }
	 else
	 {
		f.seekg(0);
		header(5);
		cout<<endl;
		dash(80);
		cout<<" SEARCH RESULTS:\n";
		dash(80);
		cout<<endl;
		while(f.read((char*)&t,sizeof(t)))
		  if(strcmpi(t.to,to)==0)
		  {
			 t.display(0);
			 cout<<endl;
			 delay(1);
		  }
		dash(80);
		f.close();
	 }
	 cout<<" Do you want to search again? (y/n)  ";
	 cin>>choice1;
	 if(choice1=='y'||choice1=='Y')
	 {
		clrscr();
		goto repeat;
	 }
	 else
	 {
		clrscr();
		adminmode();
	 }
	}
	else if(choice==3)                                        //search by train no.
	{
	 header(5);
	 space(18,5); 
	 cout<<"Enter \"train no\" to be searched";
	 space(30,1); 
	 cin>>trainno;
	 while(f.read((char*)&t,sizeof(t)))
		if(t.trainno==trainno)
		{
			flag=1;
			break;
		}
	 f.seekg(0);
	 if(flag==0)
	 {
		header(5);
		space(20,5);
		cout<<" Sorry! Train no \""<<trainno<<"\" not found!";
		delay(3);
		goto repeat;
	 }
	 else
	 {
		f.seekg(0);
		header(5);
		cout<<endl;
		dash(80);
		cout<<" SEARCH RESULTS:\n";
		dash(80);
		cout<<endl;
		while(f.read((char*)&t,sizeof(t)))
		  if(t.trainno==trainno)
		  {
			 t.display(0);
			 cout<<endl;
			 delay(1);
		  }
		dash(80);
		f.close();
	 }
	 cout<<" Do you want to search again? (y/n)  ";
	 cin>>choice1;
	 if(choice1=='y'||choice1=='Y')
	 {
		clrscr();
		goto repeat;
	 }
	 else
	 {
		f.close();
		clrscr();
		adminmode();
	 }
	}
	else if(choice==4)                                               //to view all trains
	{
	 flag=0;
	 header(5);
	 while(f.read((char*)&t,sizeof(t)))
		flag=1;
	 f.seekg(0);
	 if(flag==0)
	 {
		header(5);
		space(25,6);
		cout<<" Sorry! No trains found!";
		delay(3);
		goto repeat;
	 }
	 else
	 {
		f.close();
		ifstream f1("tf.dat",ios::binary);
		header(5);
		cout<<endl;
		dash(80);
		cout<<" SEARCH RESULTS:\n";
		dash(80);
		cout<<endl;
		while(f1.read((char*)&t,sizeof(t)))
		{
		  t.display(0);
		  cout<<endl;
		  delay(1);
		}
		dash(80);
		f1.close();
	 }
	 cout<<" Do you want to search again? (y/n) \n ";
	 cin>>choice1; 
	 if(choice1=='y'||choice1=='Y')
	 {
		clrscr();
		goto repeat;
	 }
	 else
	 {
	  f.close();
	  clrscr();
	  adminmode();
	 }
	}
	else if(choice==5)
	{
	  adminmode();
	}
	else
	{
	  space(25,1);
	  cout<<"Invalid input! Enter again ";
	  getch();
	  goto repeat;
	}
    }
}

void train::deletetrain()
{
  repeat:
  header(7);
  train t;
  char choice;
  long int tno;
  int flag2=0;
  ifstream f1;
  ofstream f2;
  f1.open(("tf.dat"),ios::binary);
  f2.open("tempfile.dat",ios::binary);
  while(f1.read((char*)&t,sizeof(t)))
  {
	flag2=1;
  }
  f1.close();
  if(flag2==0)
  {
	clrscr();
	header(7);
	space(27,6);
	cout<<"NO TRAIN RECORDS EXIST!";
	delay(3);
	adminmode();
  }
  else
  {
	 ifstream f4;
	 f4.open(("tf.dat"),ios::binary);
	 cout<<endl;
	 dash(80);
	 cout<<" EXISTING TRAINS: \n";
	 dash(80);
	 while(f4.read((char*)&t,sizeof(t)))
	 {
		cout<<endl;
		t.display(0);
		delay(1);
	 }
	 f4.close();
  }
  cout<<endl;
  dash(80);
  cout<<" Enter train no. to be deleted: \n ";
  cin>>tno;
  clrscr();
  header(7);
  space(10,5);
  cout<<"Do you want to remove train no. "<<tno<<" from train list? (y/n) ";
  cin>>choice;
  if(choice=='Y'||choice=='y')
  {
	 int flag=0;
	 ifstream f3; 
	 f3.open("tf.dat",ios::binary);
	 while(f3.read((char*)&t,sizeof(t)))
	 {
		if(t.trainno==tno) 
			 flag=1;
		else
		 f2.write((char*)&t,sizeof(t));
	 }
	 if (flag==1)
	 {
		remove(("tf.dat"));
		rename("tempfile.dat","tf.dat");
		f3.close();
		f2.close();
		header(7);
		space(18,4);
		cout<<"TRAIN NO. "<<tno<<" REMOVED FROM TRAIN LIST!\n";
		delay(3);
		header(7);
		space(11,6);
		cout<<"Do you want to delete another train record? (y/n) ";
		cin>>choice;
		if(choice=='y'||choice=='Y')
		{
			clrscr();
			goto repeat;
		}
		else
		{
		  clrscr();
		  adminmode();
		}
	 }
	 else
	 {
		header(7);
		space(25,6);
		cout<<"Train no. "<<tno<<" not found!";
		delay(3);
		adminmode();
	 }
  }
  else
  {
	 space(24,2);
	 cout<<"Press any key to go back  ";
	 getch();
	 clrscr();
	 adminmode();
  }
}

void train::modifytrain()
{
  repeat:
  header(11);
  train t,t2;
  char choice;
  long int tno;
  int flag2=0;
  ifstream f1;
  ofstream f2;
  f1.open(("tf.dat"),ios::binary);
  f2.open("tempfile.dat",ios::binary);
  while(f1.read((char*)&t,sizeof(t)))
  {
	flag2=1;
  }
  f1.close();
  if(flag2==0)
  {
	clrscr();
	header(11);
	space(27,4);
	cout<<"NO TRAIN RECORDS EXIST!";
	space(27,3);
	delay(3);
	adminmode();
  }
  else
  {
	 ifstream f4;
	 f4.open(("tf.dat"),ios::binary);
	 cout<<endl; 
	 dash(80);
	 cout<<" EXISTING TRAINS: \n";
	 dash(80);
	 while(f4.read((char*)&t,sizeof(t)))
	 {
		cout<<endl;
		t.display(0);
		delay(1);
	 }
	 f4.close();
  }
  cout<<endl;
  dash(80);
  cout<<" Enter train no. to be modified: \n ";
  cin>>tno;
  clrscr();
  header(11);
  space(10,5);
  cout<<"Do you want to modify train no. "<<tno<<" in train list? (y/n) ";
  cin>>choice;
  ifstream f3;
  if(choice=='Y'||choice=='y')
  {
	f3.open("tf.dat",ios::binary);
	int flag3=0;
	 header(11);
	 cout<<endl;
	 while(f3.read((char*)&t,sizeof(t)))
	 {
		if(t.trainno==tno)
		{
		  flag3=1;
		  cout<<" EXISTING DETAILS: \n";
		  dash(80);
		  cout<<endl;
		  t.display(0);
		  delay(1);
		  cout<<endl;
		  t2.addtrain2();
		  f3.close();
		  ifstream f5;
		  f5.open("tf.dat",ios::binary);
		  while(f5.read((char*)&t,sizeof(t)))
		  {
			 if(t.trainno==tno)
			 {
				f2.write((char*)&t2,sizeof(t2));
			 }
			 else
				f2.write((char*)&t,sizeof(t));
		  }
		  remove(("tf.dat"));
		  rename("tempfile.dat","tf.dat");
		  f5.close();
		  f2.close();
		  break;
		}
	 }
	 if (flag3==0)
	 {
		space(25,5);
		cout<<"Train no. "<<tno<<" not found! ";
		delay(3);
		clrscr();
		adminmode();
	 }
	 else
	 {
		header(7);
		space(18,5);
		cout<<"TRAIN NO. "<<tno<<" MODIFIED IN TRAIN LIST!\n";
		delay(3);
		header(7);
		space(14,6);
		cout<<"Do you want to modify another train record? (y/n) ";
		cin>>choice;
		if(choice=='y'||choice=='Y')
		{
			clrscr();
			goto repeat;
		}
		else
		{
		  clrscr();
		  adminmode();
		}
	 }
  }
  else
    {
	 space(24,2);
	 cout<<"Press any key to go back  ";
	 getch();
	 clrscr();
	 adminmode();
    }
}

int checkdoj(int x,int y,int z)
{
 if((z>=2017)&&(x>0)&&(y>0))
 {
	if((x<=28)&&(y==2))
	      return 1;
	else if((x<=30)&&(y==4||y==6||y==9||y==11))
	     return 1;
	else if((x<=31)&&(y==1||y==3||y==5||y==7||y==8||y==10||y==12))
	     return 1;
	else
	     return 0;
  }
  else
	 return 0;
}

void train::bookticket()
{
  repeat:
  header(2);
  train t,t2;
  int check,c;
  long int trainno;
  cout<<"\n Enter date of journey:\n  Day: ";
  cin>>dojd;
  cout<<"  Month: ";
  cin>>dojm;
  cout<<"  Year: ";
  cin>>dojy;
  check=checkdoj(dojd,dojm,dojy);
  if(check==0)
  {
	 cout<<"\nInvalid date! Press any key to enter again ";
	 getch();
	 goto repeat;
  }
  cout<<"\n Enter 'from' station: ";
  gets(from);
  cout<<" Enter 'to' station: ";
  gets(to);
  ifstream f1,f4;
  ofstream f2;
  f2.open("ticket.dat",ios::binary|ios::app);
  f1.open("tf.dat",ios::binary);
  int flag1=0;
  cout<<endl;
  dash(80);
  cout<<"SEARCH RESULTS: \n";
  dash(80);
  cout<<endl;
  while(f1.read((char*)&t,sizeof(t)))
	 if((strcmpi(t.from,from)==0)&&(strcmpi(t.to,to)==0))
	 {
		flag1=1;
		t.display(0);
		cout<<endl;
		delay(1);
	 }
  f1.close();
  if(flag1==0)
  {
	 cout<<" Sorry! No trains found from \""<<from<<"\" to \""<<to<<'\"';
	 cout<<"\n\n Press any key to go back  ";
	 getch();
	 clrscr();
	 usermode();
  }
  else
  {
	 dash(80);
	 cout<<" Enter train no. to book a ticket: \n ";
	 cin>>trainno;
	 ifstream f3;
	 f3.open("tf.dat",ios::binary);
	 int flag2=0;
	 char choice;
	 long int checktno;
	 f3.seekg(0);
	 while(f3.read((char*)&t,sizeof(t)))
	 {
		if(trainno==t.trainno)
		{
		  checktno=t.trainno;
		  flag2=1;
		  break;
		}
	 }
	 if(flag2==0)
	 {
		cout<<"\n Invalid train no! Press any key to enter again ";
		getch();
		goto repeat;
	 }
	 else
	 {
		header(2);
		space(15,6);
		cout<<"Are you sure you want to book this ticket? (y/n) ";
		cin>>choice;
		if(choice=='y'||choice=='Y')
		{
		  c=payment_gateway(t.fare);
		  if(c==1)
		  {
		  strcpy(t.username,loginname);
		  randomize();
		  t.ticketno=(10000+unsigned(random(89999)));
		  fail2:
		  int y=unsigned(random(t.seats)+1);
		  f4.open("ticket.dat",ios::binary);
		  while(f4.read((char*)&t2,sizeof(t2)))
			 if((checktno==t2.trainno)&&(y==t2.seatno))
				goto fail2;
		  t.seatno=y;
		  t.dojd=dojd;
		  t.dojm=dojm;
		  t.dojy=dojy;
		  f2.write((char*)&t,sizeof(t));
		  f2.close();
		  f3.close();
		  header(2);
		  space(23,5);
		  cout<<"TICKET BOOKED SUCCESSFULLY!\n";
		  this->changeseat(checktno,-1);
		  delay(2);
		  space(24,3);
		  cout<<"YOUR SEAT NUMBER IS \'"<<y<<"\'\n";
		  delay(5);
		  header(2);
		  space(17,5);
		  cout<<"Do you want to book another ticket? (y/n)   ";
		  cin>>choice;
		     if(choice=='y'||choice=='Y')
		     {
		           clrscr();
		           goto repeat;
		     }
		     else
		     {
		           clrscr();
		           usermode();
		     }
		  }
		  else
		  {
			 header(2);
			 space(23,6);
			 cout<<"TICKET BOOKING UNSUCCESSFUL...\n";
			 delay(3);
			 usermode();
		  }
		}
		else
		{
		  header(2);
		  space(23,6);
		  cout<<"TICKET BOOKING UNSUCCESSFUL...\n";
		  delay(3);
		  usermode();
		}
	 }
      }
}

int payment_gateway(float p)
{
 repeat:
 double cardno;
 int edm,edy,choice;
 char cvv[3];
 header(12);
 space(21,4);
 cout<<"How do you want to make payment?";
 space(25,3);
 cout<<"1. PAY BY \"CREDIT CARD\" \n";
 space(25);
 cout<<"2. PAY BY \"DEBIT CARD\" \n";
 space(25);
 cout<<"3. CANCEL PAYMENT \n";
 space(28,2);
 cout<<"Enter Option ";
 cin>>choice;
 if(choice==1||choice==2)
 {
	header(12);
	space(15,3);
	if(choice==1)
		cout<<"Enter 16-digit credit card no: ";
	else
		cout<<"Enter 16-digit debit card no: ";
	cin>>cardno;
	space(15,1);
	cout<<"Enter expiry date :";
	space(18,1);
	cout<<"Month: "; cin>>edm;
	space(18);
	cout<<"Year : "; cin>>edy;
	space(15,1);
	cout<<"Enter 3-digit CVV: "; getpass(cvv);
	space(15,2);
	cout<<"Transaction Amount: "; cout<<p;
	space(10,4);
	cout<<"Press 'enter' to make payment and 'backspace' to go back ";
	int ch=getch();
	if(ch==8)
	  return 0;
	header(12);
	space(27,4);
	cout<<"Processing Payment...";
	delay(3);
	space(22,2);
	cout<<"Do not hit refresh or backspace....";
	delay(4);
	return 1;
 }
 else if(choice==3)
 {
	return 0;
 }
 else
   {
        space(28,2);
        cout<<"Invalid Option...Press any key to enter again ";
        getch();
        goto repeat;
   }
}

void getpass(char* p1)
{
 int j=0;
 char t='65';
 while(t!=13)
 {
	t=getch();
	if(t!=8&&t!=13) 
	{
	 p1[j]=char(t); 
	 cout<<'*';
	 j+=1;
	}
	else if(t==13)
	 p1[j]='\0';
	else if(t==8)
	{
	  cout<<'\b';
	  cout<<' ';
	  cout<<'\b';
	  j-=1;
	  p1[j]='\0';
	}
   }
}



