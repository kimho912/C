//Hyun Ho Kim 1001967176

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

  char *singer_name;
  int *albums_sold;
  int number_tour_cities;
  char** tour_cities_name;
  struct node *left;
  struct node *right;
}Node;

Node* addNode(char line[])
{
  char *token;
  Node* temp= malloc(sizeof(Node));

  token=strtok(line,",");
  temp->singer_name=malloc(20);
  strcpy(temp->singer_name,token);
  token=strtok(NULL,",");
  temp->albums_sold=malloc(sizeof(int));
  *(temp->albums_sold)=atoi(token);
  token=strtok(NULL,",");
  temp->number_tour_cities=atoi(token);
  token=strtok(NULL,",");
  temp->tour_cities_name=malloc(sizeof(char*)*3);
  *(temp->tour_cities_name)=malloc(30);
  strcpy(temp->tour_cities_name[0],token);
  token=strtok(NULL,",\n");
  if (token)
  {
    strcpy(temp->tour_cities_name[1],token);
    token=strtok(NULL,",\n");
    if (token)
    {
      strcpy(temp->tour_cities_name[2],token);
    }
  }
  temp->left=NULL;
  temp->right=NULL;
  // printf("singer:%s sold:%d citynum:%d %s",temp->singer_name,*(temp->albums_sold),
  //   temp->number_tour_cities,temp->tour_cities_name[0]);

  return temp;
}
void insert(Node* root,char *line)
{
  char *token;
  char *temp=line;
  token=strtok(temp,",");
  token=strtok(NULL,",");

  if(atoi(token)<= *(root->albums_sold))
  {
      if(!root->left)
      {
        root->left=addNode(line);
      }
      else
      {
        insert(root->left,line);
      }
  }
  else
  {
    if(!root->right)
    {
      root->right=addNode(line);
    }
    else
    {
      insert(root->right,line);
    }
  }
}
Node* read_info(Node *root,char *f)
{
  char line[100];
  FILE *fp=fopen(f,"r");

  while (fgets(line,100,fp))
  {
    if (!root)
    {
      root = addNode(line);
    }
    else
    {
        insert(root,line);
    }
  }
  return root;
}

void preorder(Node *root,char *cityname,int *counter)
{
  if(!root)
  {
    return;
  }
  if(!strcmp(cityname,root->tour_cities_name[0]))
  {
    *counter++;
  }
  preorder(root->left,cityname,counter);
  preorder(root->right,cityname,counter);
}
int city_check(Node* root, char *cityname)
{
  int counter=0;
  preorder(root,cityname,&counter);
  return counter;
}
int main(int argc,char **argv)
{
  Node *root=NULL;

  root = read_info(root,argv[1]);
  int n=city_check(root,"Berlin");
}
