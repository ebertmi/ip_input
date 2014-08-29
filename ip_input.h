/****************************************************************************
 * ip_input library for Informatik und Programmieren I course at the
 * university of coburg.
 *
 * Based on cs50 library by Glenn Holloway
 * Based on Eric Roberts' genlib.c and simpio.c.
 *
 * Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
 * http://creativecommons.org/licenses/by-nc-sa/3.0/
 ***************************************************************************/

#ifndef _IP_INPUT_H
#define _IP_INPUT_H

#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


/* Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
 * eingelesenen char zurück. Falls kein Text eingegeben wurde, wird der
 * Benutzer zur wiederholten Eingabe aufgefordert. Leerzeichen am Anfang
 * und am Ende der Zeile werden ignoriert. Falls die Zeile nicht gelesen
 * werden kann wird CHAR_MAX zurückgegeben.
 */
char GetChar(void);


/* Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
 * eingelesenen double Wert (so genau wie möglich) zurück. Falls der
 * eingegebene Text nicht als double interpretiert werden kann, wird
 * der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
 * und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
 * underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
 * DBL_MAX zurückgegeben.
 */
double GetDouble(void);


/* Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
 * eingelesenen float Wert (so genau wie möglich) zurück. Falls der
 * eingegebene Text nicht als float interpretiert werden kann, wird
 * der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
 * und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
 * underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
 * FLT_MAX zurückgegeben.
 */
float GetFloat(void);


/* Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
 * eingelesenen int Wert im Bereich von [-2^31 + 1, 2^31 - 2] zurück. Falls der
 * eingegebene Text nicht als int interpretiert werden kann, wird
 * der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
 * und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
 * underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
 * INT_MAX zurückgegeben. Der Parameter char base steht für das zu lesende
 * Zahlenformat (Basis). 'd'
 * - 'd' für dezimal
 * - 'o' für oktal
 * - 'x' für hex
 */
int GetInt(char base);


/* Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
 * eingelesenen long long Wert im Bereich von [-2^63 + 1, 2^63 - 2] zurück. Falls der
 * eingegebene Text nicht als long long interpretiert werden kann, wird
 * der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
 * und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
 * underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
 * LLONG_MAX zurückgegeben.
 */
long long GetLongLong(void);


/* Liest eine Zeile aus dem Standard-Input-Stream und gibt diese
 * als char *, zurück. "Return" (Neue Zeile) wird abgeschnitten.
 * Falls nur eine "Return" eingegeben wird, liefert die Funktion
 * "" zurück. Der char * wird auf dem Heap abgespeichert und muss
 * dementsprechend mit free gelöscht werden.
 */
char * GetString(void);



#endif
