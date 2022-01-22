#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(){
  NODE *head,*temp,*prev,*forw ;
  head=(NodePtr) malloc(sizeof(NODE));
  temp = head;
  prev = NULL;
  int NODE_count = 1;
  printf("Input ID and Name: ");

  while(1)
  {
    int i,j,Temp_ID;
    char Temp_Name[20];
    Temp_ID = 0;
    fflush(stdin);
    scanf("%d %s",&Temp_ID,Temp_Name);
    temp->id   = Temp_ID;
    strcpy(temp->name,Temp_Name);
    if(Temp_ID == 0)
    {
      head = prev;
      break;
    }
    else
      {
        temp->next = (NodePtr)malloc(sizeof(NODE));
        forw = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forw;
        NODE_count++;
      }
  }
  
  for(temp=head; temp!=NULL ;temp=temp->next){
      prev = temp;
      printf("%d_%s --> ",temp->id,temp->name);
      free(prev);
      NODE_count--;
      //printf("%d NODE left\n",NODE_count);
  }
  free(temp);
  //NODE_count--;
  //printf("Number of NODE after free is %d \n",NODE_count);
  printf("NULL\n");
}