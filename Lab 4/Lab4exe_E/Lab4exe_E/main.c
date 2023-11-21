
#include <stdio.h>
#include <limits.h>
#include "read_input.h"

#define SIZE 50

//THIS IS FROM READ_INPUT.C
int get_string(char* digits, int n)
{
  int i = 0, j;
  int length;
  if(fgets(digits, n, stdin) == NULL)
    return EOF;

  /* If there is a newline character in the string replace it with '\0'. */
  length = strlen(digits);
  if (digits[length - 1] == '\n') {
    digits[length - 1] = '\0';
    length--;
  }

  /* remove leading spaces */
  i = 0;
  while(digits[i] == ' ')
    i++;
  length -= i;                  /* number of leading spaces == i. */
  j = 0;
  while (j <= length) {
    digits[j] = digits[i];
    i++;
    j++;
  }

  /* remove trailing spaces */
  if (length > 0) {
    j = length - 1;
    while (digits[j] == ' ')
      j--;
    length = j + 1;
    digits[length] = '\0';
  }

  return 1;
}




//THIS IS FROM READ_INT.C

int read_integer(char* digits,int n, int* num)
{
  if(get_string(digits, n)== EOF)
    return EOF;

  if(is_valid_integer(digits)){
    if(digits[0] == '-')
      *num = -convert_to_integer(digits + 1);
    else if(digits[0] == '+')
      *num = convert_to_integer(digits + 1);
    else
      *num = convert_to_integer(digits);
    return 1;
  }

  return 0;
}


int is_valid_integer(const char* digits)
{
  int valid = 1;
  int i;

  /* i = index where first digit should be */
  if(digits[0] == '+' || digits[0] == '-')
    i = 1;
  else
    i = 0;

  /* Must have at least one digit, and no non-digits. */
  if (digits[i] == '\0')
    valid = 0;
  else
    while (valid && (digits[i] != '\0')) {
      if(digits[i] < '0' ||  digits[i] > '9')
        valid = 0;
      i++;
    }
  
  return valid;
}


int convert_to_integer(const char* digits)
{
  int sum = 0;
  int i = 0;
  while(digits[i] != '\0') {
    sum = 10 * sum + (digits[i] - '0');
    i++;
  }
  return sum;
}








int main(void)
{
  int n = 0;
  char digits[SIZE];

  int y = EOF;
  
  while (1)
    {
      printf("\n\nEnter an integer or press Ctrl-D to quit: ");
      y = read_integer(digits, SIZE, &n);
  
      if(y == 1)
    printf("\nYour integer value is: %d", n);
      else if(y == EOF){
    printf("\nGood Bye.\n");
    break;
      }
      else
    printf("\n%s is an invalid integer.", digits);
    }
    
  return 0;
}

