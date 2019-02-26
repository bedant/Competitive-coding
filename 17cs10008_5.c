//Bedant Agarwal 17cs10008 pc no. 36
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct _wordR {
  char word[100];
  double x, y;
} wordR;

typedef struct _node{
  wordR w;
  struct _node *next;
} node, *nodePointer;

typedef nodePointer **hashTable;

void insertH(hashTable H, int m, wordR w)
{
  int x=m*w.x , y=m*w.y ;
  node *temp,*prev;
  //x=(int)(floor(x));y=(int)(floor(y));
  if(H[x][y]==NULL)
    {
      H[x][y]=(node *)malloc(sizeof(node));
      H[x][y]->w=w;
      H[x][y]->next=NULL;
    }
  else
    {
      for(temp=H[x][y]->next,prev=H[x][y];temp!=NULL;prev=temp,temp=temp->next);
      prev->next=(node *)malloc(sizeof(node));
      prev->next->w=w;
      prev->next->next=NULL;
    }
}
double check(hashTable H, int x,int y,wordR w,int m,double min,wordR *ptr)
{
 //printf("xy %d %d",x,y);
 node *temp;
  double t_dist;
 if(x>=0 && y>=0 && x<m && y<m)
 {
 //printf("if 1 ");
  if(H[x][y]!=NULL)
   {
    //printf("if 2 ");
     for(temp=H[x][y];temp!=NULL;temp=temp->next)
     {
      t_dist=sqrt( pow( (temp->w.x-w.x),2)+pow( (temp->w.y-w.y),2) );
      if(t_dist<min && strcmp(temp->w.word,w.word)!=0)
       {
        printf(" $$$ in check %s %s %d\n",temp->w.word,w.word,strcmp(temp->w.word,w.word));
        min=t_dist;
        *ptr=temp->w;
       }
     }
    }
 }
 return min;
}
void findNN (hashTable H, int m, wordR w)
{
 int x=m*w.x,y=m*w.y,r,i;
 double ret_val=10;
 wordR *req_ptr,req_wrd;
 double min=10;
 ret_val=check(H,x,y,w,m,min,req_ptr);
 if(ret_val!=min)
   {
	min=ret_val;
	req_wrd=*req_ptr;
    //printf("%s\n",req_wrd.word);
    //return;
   }
//printf("  %lf\n",min);
 for(r=1;r<=m;r++)
 {
 //printf("r=%d ",r);
  for(i=-r;i<r;i++)
  {
    ret_val=check(H,x+i,y-r,w,m,min,req_ptr);
    if(ret_val!=min)
     {
	min=ret_val;
	req_wrd=*req_ptr;
     }
  }
  for(i=-r;i<r;i++)
  {
    ret_val=check(H,x+r,y+i,w,m,min,req_ptr);
    if(ret_val!=min)
     {
	min=ret_val;
	req_wrd=*req_ptr;
	}
  }
  for(i=r;i>-r;i--)
  {
    ret_val=check(H,x+i,y+r,w,m,min,req_ptr);
    if(ret_val!=min)
     {
	min=ret_val;
	req_wrd=*req_ptr;
	}
  }
  for(i=-r;i<r;i++)
  {
    ret_val=check(H,x-r,y-i,w,m,min,req_ptr);
    if(ret_val!=min)
     {
	min=ret_val;
	req_wrd=*req_ptr;
	}
  }
  //printf("  %lf\n",min);
  if(min!=10) break;
 }
 printf("r=%d\n",r);
 for(r=r+1;r<m;r++)
 {
    printf("r=%d\n",r);
    if(r>min*m) break;

   for(i=-r;i<r;i++)
  {
    ret_val=check(H,x+i,y-r,w,m,min,req_ptr);
    if(ret_val!=min)
     {
	min=ret_val;
	req_wrd=*req_ptr;
     }
  }
  for(i=-r;i<r;i++)
  {
    ret_val=check(H,x+r,y+i,w,m,min,req_ptr);
    if(ret_val!=min)
     {
	min=ret_val;
	req_wrd=*req_ptr;
	}
  }
  for(i=r;i>-r;i--)
  {
    ret_val=check(H,x+i,y+r,w,m,min,req_ptr);
    if(ret_val!=min)
     {
	min=ret_val;
	req_wrd=*req_ptr;
	}
  }
  for(i=-r;i<r;i++)
  {
    ret_val=check(H,x-r,y-i,w,m,min,req_ptr);
    if(ret_val!=min)
     {
	min=ret_val;
	req_wrd=*req_ptr;
	}
  }

 }
 printf("%s\n",req_wrd.word);
 return;
}






int main()
{
  int i,j,m,n,k;
  hashTable H;
  wordR t_word;
  node *temp;
  FILE *inpf, *outf;
  //int n, i;
  char tempW[100];
  double tempX, tempY;
  inpf=fopen("input.txt","r");
  if(inpf== NULL)
  {
   printf("Error opening\n");
   return(-1);
  }
  fscanf(inpf,"%d",&n);
  m=ceil(sqrt(n));
  H=(nodePointer **)malloc(m*sizeof(nodePointer *));
  for(i=0;i<m;i++)
    {
      H[i] = (nodePointer *)malloc(m * sizeof(nodePointer));
      for (j=0; j<m; ++j) H[i][j] = NULL;
    }
  for(i=0;i<n;i++)
  {
    fscanf(inpf,"%s%lf%lf",tempW,&tempX,&tempY);
    strcpy(t_word.word,tempW);
     t_word.x=tempX;
     t_word.y=tempY;
     insertH(H,m,t_word);
   }
 for(i=0;i<m;i++)
   {
     for(j=0;j<m;j++)
       {
	 printf("[%d,%d]::",i,j);
	 for(temp=H[i][j];temp!=NULL;temp=temp->next)
	   {
	     printf("%s ",temp->w.word);
	   }
	 printf("\n");
       }
   }
 fclose(inpf);
 printf("no. of words to be searched : ");
 scanf("%d",&k);
 for(i=1;i<=k;i++)
 {
  printf("enter the word tuple %d : ",i);
  scanf("%s%lf%lf",t_word.word,&t_word.x,&t_word.y);
  findNN(H,m,t_word);
 }
}


