#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
 struct node0{
	char uid[20];
	char passwd[20];
	char name[20];
	char location[20];
	long phone;
	char messages[30][20];
    int newc[30];
};
typedef struct node0 *User;
struct node{
	User user;
	int visit;
	struct node *next; 
};
struct node2{
	User user;
	int visit;
	struct node *head;
};
typedef struct node2 *Adjlist;
struct node3{
	int vertices;
	Adjlist adjlist;
	int size;
};
typedef struct node3 *Graph;
struct node0* createUser(char *uid,char *passwd,char *name,char *location,long *phone)
{
	struct node0 *temp=(struct node0*)malloc(sizeof(struct node0));
	strcpy(temp->uid,uid);
	strcpy(temp->passwd,passwd);
	strcpy(temp->name,name);
	strcpy(temp->location,location);
  for(int i=0; i<30; i++)
    temp->newc[i]=0;
	temp->phone=phone;
	return temp;
}
struct node* createNode(User user)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->user=user;
	temp->visit=0;
	temp->next=NULL;
	return temp;
}
struct node2 createList(User user)
{
	struct node2 temp;
	temp.user=user;
	temp.visit=0;
	temp.head=NULL;
	return temp;
}
Graph createGraph(int v)
{
	Graph graph=(struct node3*)malloc(sizeof(struct node3));
	graph->vertices=v;
	graph->adjlist=(struct node2*)malloc(v*sizeof(struct node2));
	for(int i=0; i<v; i++)
         graph->adjlist[i].visit=0;
     graph->size=0;
    return graph;
}
int search(Graph graph,char *uid)
 {
 	for(int i=0; i<graph->size; i++)
 		if(strcmp(graph->adjlist[i].user->uid,uid)==0)
 		{
 			return i;
 		}
    return -1;
 }
Graph addEdge(Graph graph,char* uid1,char* uid2)
{
	int pos1,pos2;
	for(int i=0; i<graph->size; i++)
	    if(strcmp(graph->adjlist[i].user->uid,uid1)==0)
	       pos1=i;
        else if(strcmp(graph->adjlist[i].user->uid,uid2)==0)
          pos2=i;

        struct node *n1=createNode(graph->adjlist[pos2].user);
        n1->next=graph->adjlist[pos1].head;
        graph->adjlist[pos1].head=n1;
        return graph;
 }


 int isNode(Graph graph,char *uid1, char *uid2)
 {     
      int p1=search(graph,uid1);
      int p2=search(graph,uid2);
      struct node *temp=graph->adjlist[p1].head;
      while(temp!=NULL)
      {
      	if(strcmp(temp->user->uid,uid2)==0)
      		{ return 1;
      		}
        temp=temp->next;
      }
      return -1;
   }
     


 Graph Unfriend(Graph graph,char *uid1,char *uid2)
 {
 	int pos=search(graph,uid1);
    struct node *temp=graph->adjlist[pos].head;
    if(strcmp(temp->user->uid,uid2)==0)
    {
       struct node *t=graph->adjlist[pos].head;
       graph->adjlist[pos].head=graph->adjlist[pos].head->next;
       free(t);
       
         
    }
    else
    {
    while(temp!=NULL)
    {
    	if(strcmp(temp->next->user->uid,uid2)==0)
           {
           	  struct node *t=temp->next;
           	  temp->next=temp->next->next;
           	  free(t);
           	  break;
           }
      temp=temp->next;

    }
  }
    
    return graph;
 }
 int isFriends(Graph graph,char *uid1,char *uid2)
 {  
    if(isNode(graph,uid1,uid2)==1 && isNode(graph,uid2,uid1)==1)
    	return 1;
    else return -1;
 }
 void udetails(Graph graph,char *uid1,char *uid2,int def)
 {   int pos1=search(graph,uid1);
     int pos2=search(graph,uid2);
     char ch; int status=0;
    if(isFriends(graph,uid1,uid2)==1)
    {printf("\n****************************************\n");
     printf("\n%s",graph->adjlist[pos2].user->name);
     printf("\nLives in: %s",graph->adjlist[pos2].user->location);
     printf("\nMutual friends:");
     struct node *temp1=graph->adjlist[pos1].head;
     struct node *temp2=graph->adjlist[pos2].head;
     for(struct node *temp1=graph->adjlist[pos1].head; temp1!=NULL; temp1=temp1->next)
     	for(struct node *temp2=graph->adjlist[pos2].head; temp2!=NULL; temp2=temp2->next)
     		if(strcmp(temp1->user->name,temp2->user->name)==0 && isFriends(graph,uid1,temp1->user->uid)==1 && isFriends(graph,uid2,temp1->user->uid)==1)
     			{ printf("\n%s",temp1->user->name);
            status=1;
          }
      if(status==0)
      {
        printf("\nNo mutual friends");
      }
   if(def!=0)
    { printf("\nUnfriend %s ?",graph->adjlist[pos2].user->name);
      scanf(" %c",&ch);
     if(ch=='y')
         {graph=Unfriend(graph,uid1,uid2);
          printf("\nRemoved from friends list");
          graph=Unfriend(graph,uid2,uid1);
        }
     else 
     	return ;
      }
    }
 }
 void display(Graph graph)
 {
     for(int i=0; i<graph->size; i++)
     {
         printf("\nFriends of %s :",graph->adjlist[i].user->name);
         struct node *temp=graph->adjlist[i].head;
         if(temp==NULL)
            printf("\nYou got no friends");
      else
         while(temp)
         {
            printf("\n %s ",temp->user->name);
            temp=temp->next;
          }
     }

 }
 int main()
 {   int ch_1; int k;int stat;
     char uid[20],passwd[20],ch,name[20],location[20];
     char in_ch,out_ch;
     char status[30][20];
     for(int i=0; i<30; i++)
      strcpy(status[i]," ");
     int cp=0; long int phone; int swt_ch;
 	 printf("\n******************************come GNAT with us***********************");
     int user_ind;
     system("clear");
 	 Graph graph=createGraph(30);
   User user[4];
   long ph=9597700;
   user[0]=createUser("krishna","passwd","Krishna","Chennai",&ph);
   graph->adjlist[graph->size++]=createList(user[0]);
   user[1]=createUser("manasa","passwd","Manasa","Hyderabad",&ph);
      graph->adjlist[graph->size++]=createList(user[1]);
  
   user[2]=createUser("kshitij","passwd","Kshitij","Delhi",&ph);
      graph->adjlist[graph->size++]=createList(user[2]);

   user[3]=createUser("mahesh","passwd","Mahesh","Chennai",&ph);
      graph->adjlist[graph->size++]=createList(user[3]);
  user[4]=createUser("poku","passwd","Sai Asish","Hyderabad",&ph);
      graph->adjlist[graph->size++]=createList(user[4]);
      user[5]=createUser("sam","passwd","Sameera","Chennai",&ph);
      graph->adjlist[graph->size++]=createList(user[5]);    
      user[6]=createUser("disha","passwd","Patani","Chennai",&ph);
      graph->adjlist[graph->size++]=createList(user[6]);
      user[7]=createUser("sara","passwd","Sara Ali khan","Punjab",&ph);
      graph->adjlist[graph->size++]=createList(user[7]);

   graph=addEdge(graph,"krishna","manasa");
   graph=addEdge(graph,"manasa","krishna");
   graph=addEdge(graph,"poku","krishna");
   graph=addEdge(graph,"poku","mahesh");
    graph=addEdge(graph,"mahesh","poku");
    graph=addEdge(graph,"manasa","sam");
    graph=addEdge(graph,"sam","manasa");
    graph=addEdge(graph,"manasa","disha");
    graph=addEdge(graph,"disha","manasa");
    graph=addEdge(graph,"kshitij","poku");
    graph=addEdge(graph,"poku","kshitij");
   graph=addEdge(graph,"disha","mahesh");
   graph=addEdge(graph,"mahesh","disha");
   
 	 do{
    system("clear");
 	 	printf("\n1.Sign up\n2.Log in\n");
 	 	scanf(" %d",&ch_1);
 	 	     if(ch_1==1)
             {    cp=0;   
             	  printf("\nEnter a valid userid : ");
                    scanf("\n%[^\n]",uid);
                    printf("\n");
                    strcpy(passwd,getpass("Enter your Password: "));
                   printf("\nEnter your name: ");
                   scanf("\n%[^\n]",name);
                   printf("\nEnter your location: ");
                   scanf("\n%[^\n]",location);
                   printf("\nEnter ur phone number: ");
                   scanf("\n%ld",&phone);
                   printf("\nAccount created successfully ");
                   system("clear");
                   user_ind=graph->size;
                   User user=createUser(uid,passwd,name,location,&phone);
                   graph->adjlist[graph->size++]=createList(user);
                    printf("\nPeople who live in: %s",graph->adjlist[user_ind].user->location);
                    for(int i=0; i<graph->size; i++)
                    {
                       if(strcmp(graph->adjlist[i].user->location,graph->adjlist[user_ind].user->location)==0 && i!=user_ind)
                          { 
                            if(isFriends(graph,graph->adjlist[i].user->uid,graph->adjlist[user_ind].user->uid)!=1)
                            {  char cho;
                              printf("\n%s ",graph->adjlist[i].user->name);
                               printf("\nSend a friend request to %s ",graph->adjlist[i].user->name);
                               scanf(" %c",&cho);
                               if(cho=='y')
                                graph=addEdge(graph,graph->adjlist[user_ind].user->uid,graph->adjlist[i].user->uid);

                            }
                         }
                       }

                }
              
                else if(ch_1==2)
                   { cp=0;
                    system("clear");
                   	printf("\nEnter your userid: ");
                    scanf(" %[^\n]",uid);
                    printf("\n");
                    while(cp==0)
                    { /*printf("\nEnter your password: ");*/
                      strcpy(passwd,getpass("Enter your Password: "));
                      int pos=search(graph,uid);
                      if(strcmp(graph->adjlist[pos].user->passwd,passwd)==0)
                      {
                      	cp=1;
                      	user_ind=pos;
                        printf("\nLogged in successfully");
                        break;
                      }
                     if(cp==0)
                     	printf("\nPassword Incorrect:\n ");


                   }
               }
                   
            

                   do
                   {  
                    
                   int freqs=0;
                   printf("\n*******************************************************************");
                   system("clear");
                   printf("\n1.See friends request\n2.Post your status\n3.See your friends status\n4.See your friends list \n5.Gnat with your friends \n6.Recieved messages\n7.People you may know \n8.Lookup a friend's info \n9.Search for a gnatter\n10.Display the network \nEnter choice : ");
                   scanf("\n%d",&swt_ch);
                   switch(swt_ch)
                   {
                    case 1:

                         system("clear");
                         for(int i=0; i<graph->size; i++)
                         {  
                            struct node *temp=graph->adjlist[i].head;
                            while(temp!=NULL)
                            { 
                               if(strcmp(temp->user->name,graph->adjlist[user_ind].user->name)==0)
                               {   
                                if(isFriends(graph,graph->adjlist[i].user->uid,graph->adjlist[user_ind].user->uid)!=1)
                                {  printf("\n%s has sent you a friend request ",graph->adjlist[i].user->name);
                                  printf("\n Accept their friend request? ");
                                  char fc;
                                   freqs=1;
                                  scanf(" %c",&fc);
                                  if(fc=='y')
                                  {  
                                    graph=addEdge(graph,graph->adjlist[user_ind].user->uid,graph->adjlist[i].user->uid);
                                    printf("\nYou are now friends with %s ",graph->adjlist[i].user->name);
                                  }
                                }
                                
                              }
                             
                               temp=temp->next;
                            }
                          }
                          
                         
                         if(freqs==0)
                          printf("\nNo friend requests ");
                      
                         break;
                   	case 2:
                    system("clear");
                   	     printf("\nHow do u feel? ");
                   	     scanf(" %[^\n]",status[user_ind]);
                   	     break;
                   	case 3:
                         
                          system("clear");
                         {  stat=0;
                          struct node *tp=graph->adjlist[user_ind].head;
                          while(tp)
                          { if(isFriends(graph,graph->adjlist[user_ind].user->uid,tp->user->uid)==1)
                          	{int posi=search(graph,tp->user->uid);
                              if(strcmp(status[posi]," ")!=0)
                          	{ printf("\n%s Feels %s ",tp->user->name,status[posi]);
                              stat=1;
                            }
                            }
                            tp=tp->next;
                          }
                        }
                        if(stat==0)
                          printf("\nNo one has posted anything yet");
                          break;
                      
                      
                      case 4:
                      
                      system("clear");
                      { stat=0;
                         struct node *temp=graph->adjlist[user_ind].head;
                          while(temp)
                          {  
                              if(isFriends(graph,graph->adjlist[user_ind].user->uid,temp->user->uid)==1)

                          	{ udetails(graph,graph->adjlist[user_ind].user->uid,temp->user->uid,1);
                              stat=1;
                            }
                             temp=temp->next;

                            }
                          }
                          if(stat==0)
                            printf("\nYou got no friends");

                            break;
                      case 5:
                       
                      system("clear");
                      {  char ct;
                        stat=0;
                         struct node *temp=graph->adjlist[user_ind].head;
                          while(temp)
                          {  
                              if(isFriends(graph,graph->adjlist[user_ind].user->uid,temp->user->uid)==1)
                              { stat=1;
                                printf("\nText %s ?",temp->user->name);
                                scanf(" %c",&ct);
                                if(ct=='y')
                                {    char msg[30];
                                     int pos=search(graph,temp->user->uid);

                                     printf("\nEnter the message: ");
                                     scanf(" %[^\n]",msg);
                                     strcpy(graph->adjlist[pos].user->messages[user_ind],msg);
                                     printf("\nMessage sent");
                                     graph->adjlist[pos].user->newc[user_ind]=1;
                                    
                                 
                                }
                            
                              }
                              temp=temp->next;
                            }
                          }
                          if(stat==0)
                            printf("\nYou got no friends");
                          break;
                      case 6:
                        
                         system("clear");
                           {      char ct;
                            stat=0;
                            int status=0;
                                  for(int i=0; i<graph->size; i++)
                                  {
                                    if(graph->adjlist[user_ind].user->newc[i]==1)
                                    {  stat=1;
                                       printf("\nYou got a new text from %s :",graph->adjlist[i].user->name);
                                       printf("\n%s",graph->adjlist[user_ind].user->messages[i]);
                                       printf("\n Reply to %s ?",graph->adjlist[i].user->name);
                                      scanf(" %c",&ct);
                                if(ct=='y')
                                {    char msg[30];
                                     printf("\nEnter the message: ");
                                     scanf(" %[^\n]",msg);
                                     strcpy(graph->adjlist[i].user->messages[user_ind],msg);
                                     printf("\nMessage sent");
                      
                                     graph->adjlist[i].user->newc[user_ind]=1;
                                    }
                                       graph->adjlist[user_ind].user->newc[i]==0;
                                    }
                                  }
                           }
                           if(stat==0)
                            printf("\nYou have not recieved any text");
                           break;
                      case 7:
                        system("clear");
                           {  char cho;
                              struct node *temp=graph->adjlist[user_ind].head;
                              while(temp)
                              {
                                 int pos=search(graph,temp->user->uid);
                                 struct node *temp2=graph->adjlist[pos].head;
                                 while(temp2)
                                { if(isFriends(graph,graph->adjlist[user_ind].user->uid,temp2->user->uid)!=1 && isFriends(graph,temp->user->uid,temp2->user->uid)==1 && strcmp(graph->adjlist[user_ind].user->name,temp2->user->name)!=0)
                                 {
                                    printf("\n%s is a friend of %s",temp2->user->name,temp->user->name);
                                    printf("\n Want to send a friend request: ");
                                     scanf(" %c",&cho);
                               if(cho=='y')
                                graph=addEdge(graph,graph->adjlist[user_ind].user->uid,temp2->user->uid);
                              printf("\nFriend request sent");

                                 }
                                 temp2=temp2->next;
                               }
                              temp=temp->next;
                              }

                           }
                           break;
                      case 8:
                      
                      system("clear");
                      {    char fname[20];
                         stat=0;
                           printf("\nEnter the name of the friend: ");
                           scanf(" %[^\n]",fname);
                           struct node *temp=graph->adjlist[user_ind].head;
                          while(temp)
                          {  
                              if(isFriends(graph,graph->adjlist[user_ind].user->uid,temp->user->uid)==1 && strcmp(temp->user->name,fname)==0)

                             udetails(graph,graph->adjlist[user_ind].user->uid,temp->user->uid,1);
                             temp=temp->next;

                            }
                          }
                      break;
                      case 9:
                        system("clear");
                         {
                           char name[20],cho;
                           printf("\nEnter the name of the gnatter: ");
                          scanf(" %[^\n]",name);
                          for(int i=0; i<graph->size; i++)
                          {
                             if(strcmp(graph->adjlist[i].user->name,name)==0)
                             {
                                udetails(graph,graph->adjlist[user_ind].user->uid,graph->adjlist[i].user->uid,0);
                                printf("\nSend a friend request to %s ",graph->adjlist[i].user->name);
                               scanf(" %c",&cho);
                               if(cho=='y')
                                graph=addEdge(graph,graph->adjlist[user_ind].user->uid,graph->adjlist[i].user->uid);
                              printf("\nFriend request sent");
                              break;
                             }
                          }

                         }
                         break; 
                      case 10:
                         display(graph);
                         break;                          
                   }
                   printf("\nDo u want to continue? ");
                   scanf("\n %c",&ch);
               }while(ch=='y');
               printf("\nChange user account? ");
               scanf("\n %c",&ch);
           }while(ch=='y');
       }
                           
             
