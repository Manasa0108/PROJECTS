#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>
void dash();
class spl
{
 char name[30];
 int vote;
 public:
 void disp()
 {
  cout<<"\t\t";
  cout.write(name,strlen(name));
  cout<<setw(40-strlen(name))<<vote;
 }
};
void dash()
{
 for(int i=0;i<80;i++)
	cout<<'-';
}
void main()
{
 spl a;
 ifstream f1,f2;
 f1.open("spl.dat",ios::binary);
 f2.open("aspl.dat",ios::binary);
 if(!f1||!f2)
 {
  cerr<<"cannot open file";
  exit(1);
 }
  dash();
 cout<<"\t\t\t\tSPL results\n";
 dash();
 while(f1.read((char*)&a,sizeof(a)))
 {
  a.disp();
  cout<<endl;
 }
 cout<<"\n\n";
 dash();
 cout<<"\t\t\t\tASPL results\n";
 dash();
 while(f2.read((char*)&a,sizeof(a)))
 {
  a.disp();
  cout<<endl;
 }
 f1.close();
 f2.close();
}
