#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
  int count;
}node;
node *start=NULL;
int data;
//fucntion for geting random numbers below 20
int numbers()
{
  data=rand()%20;
  return data;
}
//Adding the number into a linked list
node *newnode(int n)
{
  node *temp=(node*)malloc(sizeof(node));
  temp->data=n;
  temp->next=NULL;  
  return temp;

}
void add_at_end(int num)
{

  node *temp=start;
  if(start==NULL)
  {
    start=newnode(num);
    return;
  }
 
  while(temp->next!=NULL)
  {
    
    temp=temp->next;
  }
  temp->next=newnode(num);

}
//Function to check the number of time a number is repating
int check(int value,node*temp1)
{
  node *temp=start;
  while(temp->next!=NULL)
  {
    if(temp->data==value)
    {
      temp1->count++;
    }
    
    temp=temp->next;
  }
  printf("%d  -  %d\n",temp1->data,temp1->count);
 
}
  

int main()
{
  int n,i,num,ac;
  printf("How many numbers of integer do you want:\n");
  scanf("%d",&n);
   printf("\n----------------------------------\n");
  FILE *fp = fopen("/home/ashrith/Desktop/intDoc.txt","w");
  if(fp==NULL)
  printf("Error!");
  else
  {
    for(i=0;i<=n;i++)
  { 
    num=numbers();
    //Wrting the random numbers into the file.
    fprintf(fp,"%d\n",num);
    add_at_end(num);

  }  
  //add_at_end(num);
  fclose(fp);
  
  } 
  node *temp=start;
  while(temp->next!=NULL)
  {
    check(temp->data,temp);
    temp=temp->next;
  }  
  
}
