//Hyun Ho Kim 1001967176
#ifndef LINE_HEADER
#define LINE_HEADER

struct Node{
  int age;
  struct Node *next;
};

struct Node* enter_info(int n);
struct Node* combine(struct Node* line_one, struct Node* line_two);
void print_list(struct Node* head, char *message);
struct Node* reverse_list_rec(struct Node* head_ref);

#endif
