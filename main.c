#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(){
  int i,Temp_ID;
  char *Temp_Name;
  Temp_Name = (char*) malloc(sizeof(char)*30); //temporary array
  NODE *head,*temp,*prev,*forw ;
  head=(NodePtr) malloc(sizeof(NODE));
  temp = head;
  prev = NULL;
  //printf("Input ID and Name: ");
  //////////////////////////////
  // head = point to head of NODE
  // temp = current pointer point to present NODE and next NODE
  // prev = point to NODE before current NODE
  // forw = point to next NODE
  // i    = count the loop (NODE that created)
  //////////////////////////////
  for(i=1 ; i>-1; i++)
  {
    Temp_ID = 0;
    printf("Input ID :");
    fflush(stdin);
    if(scanf("%d",&Temp_ID)){};

    if(Temp_ID!=0){
    printf("Input Name :");
    fflush(stdin);
    if(scanf(" %s",Temp_Name)){};
    temp->id   = Temp_ID;
    strcpy(temp->name,Temp_Name);
    }

    if(Temp_ID == 0)
    {
      free(temp);   //free next one that already create by loop befor this loop
      //i--;        //just for check NODE   
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
    //////////////////////////////////////////////////
    //when finish 1 loop in will auto creat next NODE
    //forw and temp will point at that NODE
    //prev will point at present NODE (NODE with current input)
    //////////////////////////////////////////////////
  }
  free(Temp_Name);
  
  ///////print output & free after print///////
  for(temp=head; temp!=NULL ;temp=forw){
      forw = temp->next;
      printf("%d_%s --> ",temp->id,temp->name);
      free(temp);
      //i--;        //just for check NODE
  }
  printf("NULL\n");
}