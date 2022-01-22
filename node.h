struct node
{
  int id;
  char name[20];
  struct node *next;
};
typedef struct node NODE;
typedef NODE* NodePtr;