#include <stdio.h>
#include "ip_input.h"

int main (void)
{
  int input;
  printf("Bitte geben Sie eine Zahl im Oktal-Format ein: ");
  input = GetInt('o');
  printf("in dezimal: %d", input);

  return 0;
}
