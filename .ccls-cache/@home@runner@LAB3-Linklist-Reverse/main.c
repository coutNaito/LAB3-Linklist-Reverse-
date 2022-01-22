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
  //emergency break
  int handbreak=0;

  while(1)
  {
    //emegency break
    if(handbreak > 20)
    {
      break;
    }
    int i,j,word;
    char convert[7];
    char input[200];
    word = 0;
    printf("Input ID and Name\n");
    fflush(stdin);
    gets(input);

    for(i=0; i<strlen(input)+1; i++)
    {
        if(input[i]==' ')
        {
            if(input[i+1]==' ')
              break;
            if(word%2!=0)
              temp->id = atoi(convert);
              j=0;
              word++;
        }
        else if(word%2!=0)
        {
            convert[j] = input[i];
            j++;
        }
        else if(word%2==0)
        {
            temp->name[j] = input[i];
            j++;
        }

        if(word==2)
        {
            if(i==strlen(input))
              temp->next = NULL;
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
        
    }
    handbreak++;
  }
  
  for(temp=head; temp!=NULL ;temp=temp->next){
       printf("%d->",temp->id);
  }
     printf("NULL\n");
}