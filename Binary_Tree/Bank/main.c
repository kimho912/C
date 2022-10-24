//Hyun Ho Kim 1001967176
#include <stdio.h>
#include "line_header.h"

int main()
{
  struct Node* line_one=enter_info(3);
  struct Node* line_two=enter_info(3);

  line_one = combine(line_one, line_two);
  print_list(line_one, "Info as entered: ");

  struct Node* reversed=reverse_list_rec(line_one);
  print_list(reversed, "Reverse: ");
}
