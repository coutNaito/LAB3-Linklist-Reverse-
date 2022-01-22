#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(){
  int i,j,Temp_ID;
  char *Temp_Name;
  Temp_Name = (char*) malloc(sizeof(int)*30);
  NODE *head,*temp,*prev,*forw ;
  head=(NodePtr) malloc(sizeof(NODE));
  temp = head;
  prev = NULL;
  printf("Input ID and Name: ");

  while(1)
  {
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
      }
  }
  free(Temp_Name);
  
  for(temp=head; temp!=NULL ;temp=temp->next){
      prev = temp;
      printf("%d_%s --> ",temp->id,temp->name);
      free(prev);
  }
  free(temp);
  printf("NULL\n");
}