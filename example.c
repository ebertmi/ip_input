#include <stdio.h>
#include "ip_input.h"

int main (void)
{
  char eingabe;
  printf("Bitte geben Sie ein Zeichen ein.");
  eingabe = GetChar();
  printf("Sie haben %c eingegeben.", eingabe);

  return 0;
}
