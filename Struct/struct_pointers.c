//Hyun Ho Kim 1001967176

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct all_values{
  char word[40];
  float numbers[1][2];
  int** int_dblptr;
  int* int_ptr;
};

typedef struct all_values RANDOM;

void fill_in_struct_info(RANDOM *r,int** n1,int* n2);
void print_out_struct_info(RANDOM *ran);

int main(int argc, char** argv)
{
  int num=atoi(argv[1]);
  int* number=&num;

  int num_two=atoi(argv[2]);
  int* number_two=&num_two;

  RANDOM random_stuff[2];
  RANDOM* random_ptr=random_stuff;

  fill_in_struct_info(random_stuff, &number, &num);
  random_ptr++;
  fill_in_struct_info(random_ptr, &number_two, &num_two);

  print_out_struct_info(&random_stuff[0]);
  print_out_struct_info(random_ptr);
}
void fill_in_struct_info(RANDOM *r,int** n1,int* n2)
{
  char answer[20];

  printf("Enter a word to put in random.word: ");
  scanf("%s",answer);
  strcpy(r->word,answer);
  printf("Enter a float for random.numbers[0][0] random.word: ");
  scanf("%f",&(r->numbers[0][0]));
  printf("Enter a float for random.numbers[0][1] random.word: ");
  scanf("%f",&(r->numbers[0][1]));
  printf("Assigning parameter val_one to random.int_dblptr...\n");
  r->int_dblptr=n1;
  printf("Assigning parameter val_two to random.int_ptr...\n");
  r->int_ptr=n2;
  printf("\n");
}
void print_out_struct_info(RANDOM *ran)
{
  printf("In random.word: %s\n",ran->word);
  printf("In random.number[0][0]: %.2f\n",ran->numbers[0][0]);
  printf("In random.number[0][1]: %.2f\n",ran->numbers[0][1]);
  printf("Value held at random.int_dblptr: %p, actual value: %d\n",ran->int_dblptr,**(ran->int_dblptr));
  printf("Value held at random.int_ptr: %p, actual value: %d\n",ran->int_ptr,*(ran->int_ptr));
  printf("\n");
}
