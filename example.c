#include <stdio.h>
#include "ip_input.h"

int main (void)
{
  char* firstname;
  printf("Bitte geben Sie ihren Vornamen ein: ");
  firstname = GetString();
  printf("Hallo %s!", firstname);

  free(firstname); // Speicher wieder freigeben
  return 0;
}
