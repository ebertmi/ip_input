/****************************************************************************
 * ip_input library for Informatik und Programmieren I course at the
 * university of coburg.
 *
 * Based on cs50 library by Glenn Holloway
 * Based on Eric Roberts' genlib.c and simpio.c.
 *
 * Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
 * http://creativecommons.org/licenses/by-nc-sa/3.0/
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ip_input.h"

/* Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
 * eingelesenen char zurück. Falls kein Text eingegeben wurde, wird der
 * Benutzer zur wiederholten Eingabe aufgefordert. Leerzeichen am Anfang
 * und am Ende der Zeile werden ignoriert. Falls die Zeile nicht gelesen
 * werden kann wird CHAR_MAX zurückgegeben.
 */
char GetChar(void)
{
    // try to get a char from user
    while (true)
    {
        // get line of text, returning CHAR_MAX on failure
        char * line = GetString();
        if (line == NULL)
            return CHAR_MAX;

        // return a char if only a char (possibly with
        // leading and/or trailing whitespace) was provided
        char c1, c2;
        if (sscanf(line, " %c %c", &c1, &c2) == 1)
        {
            free(line);
            return c1;
        }
        else
        {
            free(line);
            printf("Wiedeholen: ");
        }
    }
}


/* Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
 * eingelesenen double Wert (so genau wie möglich) zurück. Falls der
 * eingegebene Text nicht als double interpretiert werden kann, wird
 * der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
 * und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
 * underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
 * DBL_MAX zurückgegeben.
 */
double GetDouble(void)
{
    // try to get a double from user
    while (true)
    {
        // get line of text, returning DBL_MAX on failure
        char * line = GetString();
        if (line == NULL)
            return DBL_MAX;

        // return a double if only a double (possibly with
        // leading and/or trailing whitespace) was provided
        double d; char c;
        if (sscanf(line, " %lf %c", &d, &c) == 1)
        {
            free(line);
            return d;
        }
        else
        {
            free(line);
            printf("Wiedeholen: ");
        }
    }
}

/* Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
 * eingelesenen float Wert (so genau wie möglich) zurück. Falls der
 * eingegebene Text nicht als float interpretiert werden kann, wird
 * der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
 * und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
 * underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
 * FLT_MAX zurückgegeben.
 */
float GetFloat(void)
{
    // try to get a float from user
    while (true)
    {
        // get line of text, returning FLT_MAX on failure
        char * line = GetString();
        if (line == NULL)
            return FLT_MAX;

        // return a float if only a float (possibly with
        // leading and/or trailing whitespace) was provided
        char c; float f;
        if (sscanf(line, " %f %c", &f, &c) == 1)
        {
            free(line);
            return f;
        }
        else
        {
            free(line);
            printf("Wiedeholen: ");
        }
    }
}

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
 * - 'u' für unsigned int
 */
int GetInt(char base)
{
    // try to get an int from user
    while (true)
    {
        // get line of text, returning INT_MAX on failure
        char * line = GetString();
        if (line == NULL)
            return INT_MAX;

        // return an int if only an int (possibly with
        // leading and/or trailing whitespace) was provided
        int n; char c;
        int ret_val;
        switch(base){
            case 'o': ret_val = sscanf(line, " %o %c", &n, &c); break;
            case 'x': ret_val = sscanf(line, " %x %c", &n, &c); break;
						case 'u': ret_val = sscanf(line, " %u %c", &n, &c); break;
            case 'd':
            default: ret_val = sscanf(line, " %d %c", &n, &c); break;
        }
        if (ret_val == 1)
        {
            free(line);
            return n;
        }
        else
        {
            free(line);
            printf("Wiedeholen: ");
        }
    }
}

/* Liest eine Zeile Text aus dem Standard-Input-Stream und gibt den
 * eingelesenen long long Wert im Bereich von [-2^63 + 1, 2^63 - 2] zurück. Falls der
 * eingegebene Text nicht als long long interpretiert werden kann, wird
 * der Benutzer zur erneuten Eingabe aufgefordert. Leerzeichen am Anfang
 * und am Ende der Zeile werden ignoriert. Es wird nicht auf overflow und
 * underflow geprüft. Falls die Zeile nicht gelesen werden konnte, wird
 * LLONG_MAX zurückgegeben.
 */
long long GetLongLong(void)
{
    // try to get a long long from user
    while (true)
    {
        // get line of text, returning LLONG_MAX on failure
        char * line = GetString();
        if (line == NULL)
            return LLONG_MAX;

        // return a long long if only a long long (possibly with
        // leading and/or trailing whitespace) was provided
        long long n; char c;
        if (sscanf(line, " %lld %c", &n, &c) == 1)
        {
            free(line);
            return n;
        }
        else
        {
            free(line);
            printf("Wiedeholen: ");
        }
    }
}

/* Liest eine Zeile aus dem Standard-Input-Stream und gibt diese
 * als char*, zurück. "Return" (Neue Zeile) wird abgeschnitten.
 * Falls nur eine "Return" eingegeben wird, liefert die Funktion
 * "" zurück. Der string wird auf dem Heap abgespeichert und muss
 * dementsprechend mit free gelöscht werden.
 */
char * GetString(void)
{
    // growable buffer for chars
    char * buffer = NULL;

    // capacity of buffer
    unsigned int capacity = 0;

    // number of chars actually in buffer
    unsigned int n = 0;

    // character read or EOF
    int c;

    // iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        // grow buffer if necessary
        if (n + 1 > capacity)
        {
            // determine new capacity: start at 32 then double
            if (capacity == 0)
                capacity = 32;
            else if (capacity <= (UINT_MAX / 2))
                capacity *= 2;
            else
            {
                free(buffer);
                return NULL;
            }

            // extend buffer's capacity
            char * temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        // append current character to buffer
        buffer[n++] = c;
    }

    // return NULL if user provided no input
    if (n == 0 && c == EOF)
        return NULL;

    // minimize buffer
    char * minimal = malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    // terminate string
    minimal[n] = '\0';

    // return string
    return minimal;
}
