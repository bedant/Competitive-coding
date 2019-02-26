//Bedant Agarwal ROLL NO- 17cs10008 PC No. 36
#include<stdio.h>
#include<stdlib.h>
typedef struct rm{
  int hInd;
  int vInd;
}room;
typedef struct node{
  room data;
  struct node *next;
}node,*list;
typedef struct {
struct node *front, *rear ;
} QUEUE ;
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
void init(QUEUE *qP)
{
    qP->front=qP->rear=NULL;
    //printf("in init\n");
}
int isempty(QUEUE qP)
{
    //printf("in fun empty\n");
    if(qP.front==NULL)
        return 1;
    return 0;
}
void enqueue(QUEUE *qP, room data)
{
    node *ptr;
    ptr=malloc(sizeof(node));
    //printf("enq\n");
    ptr->next=NULL;
    ptr->data.hInd=data.hInd;
    ptr->data.vInd=data.vInd;
    //printf("enq  %d %d\n",qP->rear->data.hInd,qP->rear->data.vInd);
    //printf("   %d %d",data.hInd,data.vInd);
    qP->rear->next=ptr;
    qP->rear=qP->rear->next;
    //printf("enq 2\n");
}
void dequeue(QUEUE *qP)
{
    //printf("deq\n");
    qP->front=qP->front->next;
}
int strategy2(list maze[][20], int n, room start, room end)
{
    QUEUE *qP;
    node *ptr,*temp_ptr;
    room temp_rm;
    qP=malloc(sizeof(QUEUE));
    ptr=malloc(sizeof(QUEUE));
    init(qP);
    ptr->data=start;
    ptr->next=NULL;
    qP->front=ptr;
    qP->rear=ptr;
    qP->front->next=qP->rear->next=NULL;
    int check[20][20]={0};
    check[ptr->data.hInd][ptr->data.vInd]=1;
    //printf("stast 2\n");
    while(1)
    {
        //printf("in while\n");
        if(isempty(*qP))
        {
            //printf("empty \n");
            return 0;
        }
        for(temp_ptr=maze[qP->front->data.hInd][qP->front->data.vInd];temp_ptr!=NULL;temp_ptr=temp_ptr->next)
        {
            //printf("in for\n");
            if(check[temp_ptr->data.hInd][temp_ptr->data.vInd]==0)
            {
                //printf(" if\n");
                check[temp_ptr->data.hInd][temp_ptr->data.vInd]=1;
                temp_rm.hInd=temp_ptr->data.hInd;
                temp_rm.vInd=temp_ptr->data.vInd;
                enqueue(qP,temp_rm);
                if(temp_rm.hInd==end.hInd && temp_rm.vInd==end.vInd) return 1;
            }
            /*for(ptr=qP->front;ptr!=NULL;ptr=ptr->next)
            {
                printf(" %d %d\n",ptr->data.hInd,ptr->data.vInd);
            }
            */
        }
        dequeue(qP);
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
	 //printf("okay\n");
	 printf("using strategy 2...\n");
    int res2=strategy2(maze,n,st_room,end_room);
    if(res2)
        printf("A path is found using stategy 2 from (%d,%d) to (%d,%d)\n",s,t,u,v);
    else printf("A path is  NOT  found using stategy 2 from (%d,%d) to (%d,%d)\n",s,t,u,v);
    return 0;
}

