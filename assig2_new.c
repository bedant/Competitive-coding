#include<stdio.h>
#include<stdlib.h>
typedef struct {
struct node *head ;
} STACK ;
typedef struct rm{
  int hInd;
  int vInd;
}room;
typedef struct node{
  room data;
  struct node *next;
}node,*list;
void createmaze(list maze[][20],int n,int H[][20],int V[][21])
{
 int  k=0;
  node *prev,*ptr,*head;
  int l,r,u,d,i,j,flag;
  for(i=0;i<n;i++)
    {
      // printf(" %d\n",i);
      for(j=0;j<n;j++)
	{
	  head=prev=NULL;

	  flag=0;u=d=l=r=0;
	  // printf("okay1\n");
		{
		  if(H[i][j] && i>0)
		    {
		      // printf("  okay1\n");
		      head=malloc(sizeof(node));
		      prev=head;
		      head->data.hInd=i-1;head->data.vInd=j;
		      flag=1;u=1;
		      prev=head;

		    }


		  else if(i<n-1 && H[i+1][j] && i<n-1)
		    {
		      // printf("  2okay1\n");
		      head=malloc(sizeof(node));
		      prev=head;
		      head->data.hInd=i+1;head->data.vInd=j;
		      flag=1;d=1;
		      prev=head;

		    }

		  else if(V[i][j] && j>0)
		     {
		       // printf(" 3okay1\n");
		      head=malloc(sizeof(node));
		      prev=head;
		      head->data.hInd=i;head->data.vInd=j-1;
		      flag=1;l=1;
		      prev=head;

		    }

		   else if(V[i][j+1] && j<n-1)
		     {
		       //      printf("  4okay1\n");
		      head=malloc(sizeof(node));
		      prev=head;
		      head->data.hInd=i;head->data.vInd=j+1;
		      flag=1;r=1;
		      prev=head;

		    }

		  head->next=NULL;
	      	}
		//printf("okay2\n");
		{
		  if(H[i][j] && u==0 && i>0)
		    {
		      ptr=malloc(sizeof(node));
		      prev->next=ptr;
		      ptr->data.hInd=i-1;ptr->data.vInd=j;
		      flag=1;u=1;
		       ptr->next=NULL;
		      prev=ptr;
		    }
		   if(H[i+1][j] && d==0 &&i<n-1 )
		    {
		      ptr=malloc(sizeof(node));
		      prev->next=ptr;
		      ptr->data.hInd=i+1;ptr->data.vInd=j;
		      flag=1;d=1;
		       ptr->next=NULL;
		      prev=ptr;
		    }
		   if(V[i][j] && l==0 && j>0)
		     {
		      ptr=malloc(sizeof(node));
		      prev->next=ptr;
		      ptr->data.hInd=i;ptr->data.vInd=j-1;
		      flag=1;l=1;
		       ptr->next=NULL;
		      prev=ptr;
		    }
		    if(V[i][j+1] && r==0 && j<n-1)
		     {
		      ptr=malloc(sizeof(node));
		      prev->next=ptr;
		      ptr->data.hInd=i;ptr->data.vInd=j+1;
		      flag=1;r=1;
		      ptr->next=NULL;
		      prev=ptr;
		    }
		}
		//printf("okay3 %d\n",k++);
		maze[i][j]=head;
	}

    }
}
void printmaze(int H[][20],int V[][21],int n)
{
  int i,j;
  for(i=0;i<n+1;i++)
    {
      for(j=0;j<n;j++)
	{
	  printf("+");

	  if( H[i][j]==0) printf("---");
	  else printf("   ");
	}
      printf("+\n");
      for(j=0;j<n+1 && i<n;j++)
	{
	  if(V[i][j]==0) printf("|   ");
	  else printf("    ");
	}
      printf("\n");
    }
}

void init(STACK *s)
{
    printf("in init\n");
   (s->head) = NULL;
    printf("afetr \n");
    return;
}
int isempty(STACK s)
{
    if(s.head==NULL) return 1;
    return 0;
}
void push(STACK *s, room data)
{
    node *temp_ptr,*ptr;
    temp_ptr=malloc(sizeof(node));
    temp_ptr->data=data;temp_ptr->next=NULL;

    if(s->head==NULL) {s->head=temp_ptr;return;}
    else
        {
            ptr=s->head;
            for(;;ptr=ptr->next)
            {
                if(ptr->next==NULL)
                {
                    ptr->next=temp_ptr;
                    return;
                }
            }
        }
}
void pop(STACK *s)
{
    node *ptr;
    for(ptr=s->head;ptr!=NULL;ptr=ptr->next)
    {
        printf("    %d %d\n",ptr->data.hInd,ptr->data.vInd);
    }
    ptr=s->head;
    printf("in pop\n");
    if(s->head->next==NULL) {printf("in if\n");s->head=NULL;return;}
    for(;;ptr=ptr->next)
    {
        printf("in for %d\n",ptr->next);
        if(ptr->next->next==NULL)
        {
            printf("%d %d\n",ptr->data.hInd,ptr->data.vInd);
            ptr->next=NULL;
            return;
        }
    }
}
node* find_last(STACK *s)
{
    node *ptr;
    ptr=s->head;
    if(s->head->next==NULL) {return s->head;}
    for(;;ptr=ptr->next)
    {
        if(ptr->next==NULL)
        {
            return ptr;
        }
    }
}
int strategy1(list maze[][20], int n, room start, room end)
{
    room temprm;
    int check[20][20]={0},flag;
    STACK *a;
    printf("bef init\n");
    a=malloc(sizeof(STACK));
    init(a);
    printf("aft\n");
    //push(a,start);
    node *curr_ptr,*temp_ptr;
    curr_ptr->data.hInd=start.hInd;curr_ptr->data.vInd=start.vInd;
    curr_ptr->next=NULL;
    flag=0;
    printf("bef while\n");
    while(1)
    {
        if(curr_ptr!=NULL) printf("in while %d %d\n",curr_ptr->data.hInd,curr_ptr->data.vInd);
        else printf("in while\n");
        if(flag && isempty(*a)) {printf("empty\n");return 0;}
        if(curr_ptr!=NULL && check[curr_ptr->data.hInd][curr_ptr->data.vInd]==0)
        {
            printf("not null not checked\n");
            check[curr_ptr->data.hInd][curr_ptr->data.vInd]=1;
            temprm.hInd=curr_ptr->data.hInd;temprm.vInd=curr_ptr->data.vInd;
            push(a,temprm);
            if(temprm.hInd==end.hInd && temprm.vInd==end.vInd) return 1;
            curr_ptr=maze[curr_ptr->data.hInd][curr_ptr->data.vInd];
        }
        else if(curr_ptr!=NULL && check[curr_ptr->data.hInd][curr_ptr->data.vInd]==1)
        {
            printf(" %d %d\n",curr_ptr->data.hInd,curr_ptr->data.vInd);
            printf("not null but checked\n");
            curr_ptr=curr_ptr->next;
        }
        else if(curr_ptr==NULL)
        {
            printf(" null \n");
            pop(a);
            printf("aft pop\n");
            if(isempty(*a)) return 0;
            curr_ptr=find_last(a);
            curr_ptr=maze[curr_ptr->data.hInd][curr_ptr->data.vInd];
        }
        for(temp_ptr=a->head;temp_ptr!=NULL;temp_ptr=temp_ptr->next)
            printf("  %d %d\n",temp_ptr->data.hInd,temp_ptr->data.vInd);
        printf("again\n");
        flag=1;
    }
}
int main()
{
  int n,i,j,H[21][20],V[20][21],s,t,u,v;
  // list maze[20][20];
  printf("enter the value of n ");
  scanf("%d",&n);
  printf("%d\nenter horizontal doors\n",n);
  for(i=0;i<n+1;i++)
    {
      for(j=0;j<n;j++)
	{
	  scanf("%d",&H[i][j]);
	}
    }
  printf("enter verticalal doors\n");
   for(i=0;i<n;i++)
    {
      for(j=0;j<n+1;j++)
	{
	  scanf("%d",&V[i][j]);
	}
    }
   for(i=0;i<n+1;i++)
    {
      for(j=0;j<n;j++)
	{
	  printf("%d ",H[i][j]);
	}
      printf("\n");
    }
   for(i=0;i<n;i++)
    {
      for(j=0;j<n+1;j++)
	{
	  printf("%d ",V[i][j]);
	}
      printf("\n");
    }
   printf("enter indices of starting room\n");
   scanf("%d%d",&s,&t);
   printf("%d %d \n",s,t);
   printf("enter indices of end room\n");
   scanf("%d%d",&u,&v);
   printf("%d %d \n",u,v);
   printmaze(H,V,n);
   list maze[20][20],ptr;
   createmaze(maze,n,H,V);
   // printf("okay\n");
   for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
	 {
	   printf("(%d,%d)::",i,j);
	   for(ptr=maze[i][j];ptr!=NULL;ptr=ptr->next)
	     { printf("-->(%d,%d)",(ptr->data).hInd,(ptr->data).vInd);}
	   printf("\n");
	 }
     }
	 room st_room,end_room;
	 st_room.hInd=s;st_room.vInd=t;
	 end_room.hInd=u;end_room.vInd=v;
	 printf("okay\n");
    int resl=strategy1(maze,n,st_room,end_room);
    printf("%d",resl);
    return 0;
}
