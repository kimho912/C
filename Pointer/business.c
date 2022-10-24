// Hyun Ho Kim 1001967176

#include <stdio.h>

float print_out(float* salary, int* num_of_emps)
{
  float total;
  int manager,director;
  if (*num_of_emps>=6)
  {
    if(*num_of_emps % 2 == 0)
    {
      manager=*num_of_emps/2;
    }
    else
    {
      manager=(*num_of_emps-1)/2;
    }
    if(manager<3)
    {
      director=0;
    }
    else
    {
      if((manager % 3 == 0)||(manager % 3 == 1)||(manager % 3 == 2))
      {
        director=manager/3;
      }
    }
    total=(*num_of_emps * *salary + manager * *salary*5/2 + director * *salary*5);

    printf("\n\n**Employee info:**\n");
    printf("Total workers: %-1d Monthly salary: $%.2f\n",*num_of_emps,*salary);
    printf("Total managers: %-1d Monthly salary: $%.2f\n",manager,*salary*5/2);
    printf("Total directors: %-1d Monthly salary: $%.2f\n",director,*salary*5);
    printf("Total spent: $%.2f\n",total);
  }
  else
  {
    printf("No fewer than 6 workers are allowed\n");
  }

  return total;
}
int rebudget(float* d, float *budget)
{
  int answer;

  if(d<budget)
  {
    printf("-- This goes UNDER your budget by $%.2f.\n\n",*budget - *d);
  }
  else if(d==budget)
  {
    printf("-- This matches your budget.\n");
  }
  else
  {
   printf("-- This goes OVER your budget by $%.2f.\n\n",*d - *budget);
  }
  printf("------");
  printf("\nWould you like to rebudget? 1 for yes 2 for no.\n");
  scanf ("%d",&answer);

  if (answer==1)
  {
    answer=1;
  }
  else if (answer==2)
  {
    printf("Bye!\n");
    answer=0;
  }
  return answer;
}
int main(int argc, char ** argv)
{
  int i=1;
  float budget, total, salary;
  float *money_ptr=&salary;
  float *total_ptr=&total;
  int employees;

  printf("Enter monthly budget: $");
  scanf("%f",&budget);

  while(i)
  {
    printf("Enter Monthly worker salary: $");
    scanf("%f",&salary);

    printf("Enter total workers:");
    scanf("%d", &employees);

    total=print_out(money_ptr, &employees);
    i=rebudget(total_ptr, &budget);
  }
}
