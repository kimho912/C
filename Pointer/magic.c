//Hyun ho Kim 1001967176
#include <stdio.h>
#include <stdlib.h>

int check_tickets_valid(int* all_tickets, int* max_ticket, int** size_of_tickets)
{
  int valid=0;
  int i;
  for (i=0;i<**size_of_tickets;i++)
  {
    if (all_tickets[i] < *max_ticket)
    {
      printf("Ticket %d: is welcome!\n",all_tickets[i]);
      valid++;
    }
    else
    {
      printf(" Ticket %d: You are not allowed in the show Please leave.\n",all_tickets[i]);
      all_tickets[i]=0;
    }
  }

  return valid;
}
int find_magic_number(int* all_tickets, int* num_valid_tickets, int** size_of_tickets)
{
  int largest=0;
  int j;
  for (j=0; j< **size_of_tickets; j++)
  {
    if ((all_tickets[j] != 0) && (all_tickets[j] > largest))
    {
      largest=all_tickets[j];
    }
  }
  printf("\nLargest number is...%d\n",largest);

  int magic;
  magic = (largest % *num_valid_tickets);

  FILE* fp= fopen("magic.txt","w");
  fprintf(fp,"***magic number: %d\n",magic);
  fclose(fp);

  return magic;
}
int main(int argc, char **argv)
{
  int max_ticket_number=atoi(argv[1]);
  int ticket_numbers[5]={120,625,345,700,300};
  int size_tickets=5;
  int* ptr_size=&size_tickets;

  int total_valid=check_tickets_valid(ticket_numbers, &max_ticket_number, &ptr_size);
  printf("Total valid tickets: %d\n\n", total_valid);
  int* ptr_total=&total_valid;

  if (1<total_valid)
  {
  int magic_number=find_magic_number(ticket_numbers, ptr_total, &ptr_size);
  printf("Magic number is: %d\n", magic_number);
  }
  printf("Writing to file magic.txt...");

}
