//Hyun Ho Kim 1001967176
#include "stack_queue6.h"
#include "hw6.h"

int main(int argc, char **argv)
{
  //Prompt 1/////////////////////////////////
  int top;
  float stack[MAXSIZE];

  top = jar(stack);
  pop_jar(stack,top);
  //Prompt 2/////////////////////////////////
  QUEUE queue_one;
  read_info(&queue_one,argv[1]);
  search(&queue_one);

}
