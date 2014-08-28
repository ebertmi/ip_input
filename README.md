# Einfache Eingabe-Bibliothek für C

## Beschreibung
Die Bibliothek stellt einfache Funktionen zum Einlesen der
Standarddatentypen aus dem Standard-Input-Puffer zur Verfügung.
Die Bibliothekt ist für die Verwendung in der *Vorlesung Informatik
und Programmieren I* an der Hochschule Coburg gedacht.

## Verwendung
Binden Sie einfach die Datei ```ip_input.h``` ein. Die VM findet die
Datei automatisch. Falls Sie die Datei selbst verwenden möchten, müssen
Sie diese beim kompilieren mit angeben. Zum Beispiel so:
```cmd
>> gcc example.c ip_input.c
```

<br/>

## GetChar
```c
char GetChar(void);
```

Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
eingelesenen char zurück. Falls kein Text eingegeben wurde, wird der
Benutzer zur wiederholten Eingabe aufgefordert. Leerzeichen am Anfang
und am Ende der Zeile werden ignoriert. Falls die Zeile nicht gelesen
werden kann wird ```CHAR_MAX``` zurückgegeben.

**Beispiel:**

```c
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
```

<br/>
## GetDouble

```c
double GetDouble(void);
```

Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
eingelesenen double Wert (so genau wie möglich) zurück. Falls der
eingegebene Text nicht als double interpretiert werden kann, wird
der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
```DBL_MAX``` zurückgegeben.

**Beispiel:**

```c
#include <stdio.h>
#include "ip_input.h"

int main (void)
{
  double height;
  printf("Bitte geben Sie ihre Koerpergroeße in Meter ein: ");
  height = GetDouble();
  height = height * 100; // in cm
  printf("Ihre Groeße beträgt %.2lf cm.", height);

  return 0;
}
```

<br />

## GetFloat

Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
eingelesenen float Wert (so genau wie möglich) zurück. Falls der
eingegebene Text nicht als float interpretiert werden kann, wird
der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
```FLT_MAX``` zurückgegeben.

**Beispiel**
 ```c
 #include <stdio.h>
 #include "ip_input.h"

 int main (void)
 {
   float weight;
   printf("Bitte geben Sie ihre Gewicht in Kilogramm ein: ");
   weight = GetFloat();
   weight *= 1000; // in g
   printf("Ihre Gewicht betraegt %f g.", weight);

   return 0;
 }
 ```

<br />

## GetInt

```c
int GetInt(void);
```
Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
eingelesenen int Wert im Bereich von ```[-2^31 + 1, 2^31 - 2]``` zurück. Falls der
eingegebene Text nicht als int interpretiert werden kann, wird
der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
```INT_MAX``` zurückgegeben.

**Beispiel:**

```c
#include <stdio.h>
#include "ip_input.h"

int main (void)
{
  int num;
  int divisor;
  printf("Bitte geben Sie eine Zahl und einen Teiler ein: ");
  num = GetInt();
  divisor = GetInt();
  printf("Zahl %% Teiler = %d", num % divisor);

  return 0;
}
```

<br/>
## GetLong

```c
long long GetLongLong(void);
```

Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
eingelesenen long long Wert im Bereich von ```[-2^63 + 1, 2^63 - 2]``` zurück. Falls der
eingegebene Text nicht als long long interpretiert werden kann, wird
der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
```LLONG_MAX``` zurückgegeben.
<br/>

## GetString

Liest eine Zeile aus dem Standard-Input-Stream und gibt diese
als char *, zurück. "Return" (Neue Zeile) wird abgeschnitten.
Falls nur eine "Return" eingegeben wird, liefert die Funktion
```""``` zurück. Der char * wird auf dem Heap abgespeichert und muss
dementsprechend mit ```free``` gelöscht werden.

**Beispiel:**
```c
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
```
