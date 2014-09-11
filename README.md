# Einfache Eingabe-Bibliothek für C

## Beschreibung
Die Bibliothek stellt einfache Funktionen zum Einlesen der
Standarddatentypen aus dem Standard-Input-Puffer zur Verfügung.
Die Bibliothek ist für die Verwendung in der *Vorlesung Informatik
und Programmieren I* an der Hochschule Coburg gedacht.

## Verwendung
Binden Sie einfach die Datei ```ip_input.h``` ein. Die VM findet die
Datei automatisch. Falls Sie die Datei selbst verwenden möchten, müssen
Sie diese beim Kompilieren mit angeben. Zum Beispiel so:

###Ohne Installation
Bei der Verwendung ohne Installation muss beim Kompilieren die Datei ip_input.c
direkt mit angegeben werden.
```cmd
>> gcc example.c ip_input.c
```
Zusätzlich sollte diese folgendermaßer eingebunden sein:
```c
#include "ip_input.h"
```

###Vorinstalliert (Virtuelle Maschine IP1)
Auf der virtuellen Maschine, die Sie verwenden können, ist die Bibliothek
bereits vorinstalliert. Diese kann nun folgendermaßen eingebunden werden:
```c
#include <ip_input.h>
```
Dabei ist zu beachten, dass beim Kompilieren auf der Konsole noch folgendes Flag
gesetzt werden muss (kein Leerzeichen zwischen -l und dem Namen):
```bash
gcc example.c -lip_input
```

Bei der Verwendung mit Eclipse, muss die Bibliothek noch in den Project Properties hinzugefügt werden.
Dazu sind folgende Schritte nötig:

1. Auf den Reiter *Projects* klicken
2. Auf Properties (ganz unten) klicken
3. Es öffnet sich ein Dialog
4. Unter *C/C++ General* auf *Paths and Symbols* klicken
5. Im Reiter Libraries auf *Add* klicken
6. Unter *File:* nur *ip_input* eingeben und mit *OK* bestätigen
7. Unten rechts auf *Apply* klicken und ggf. einen Dialog bestätigen
8. Abschließend den Hauptdialog mit *OK* unten rechts schließen

###Installation
Sie finden eine Anleitung zur Installation [hier](INSTALL.md)

## GetChar
```c
char GetChar(void);
```

Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
eingelesenen char zurück. Falls kein Text eingegeben wurde, wird der
Benutzer zur wiederholten Eingabe aufgefordert. Leerzeichen am Anfang
und am Ende der Zeile werden ignoriert. Falls die Zeile nicht gelesen
werden kann, wird ```CHAR_MAX``` zurückgegeben.

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
int GetInt(char base);
```
Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
eingelesenen int Wert im Bereich von ```[-2^31 + 1, 2^31 - 2]``` zurück. Falls der
eingegebene Text nicht als int interpretiert werden kann, wird
der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
```INT_MAX``` zurückgegeben.Der Parameter ```char base``` steht für das zu lesende
Zahlenformat (Basis).
- 'd' für dezimal
- 'o' für oktal
- 'x' für hex

**Beispiel:**

```c
#include <stdio.h>
#include "ip_input.h"

int main (void)
{
  int num;
  int divisor;
  printf("Bitte geben Sie eine Zahl und einen Teiler ein: ");
  num = GetInt('d'); // Ganzahl zur Basis 10
  divisor = GetInt('d'); // Ganzahl zur Basis 10
  printf("Zahl %% Teiler = %d", num % divisor);

  return 0;
}
```

<br/>
## GetLongLong

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
