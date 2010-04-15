#include "useful.h"

/*
 * TODO
 * aus der Datei "IO.txt" alle Buchstaben m,o,d,e,l,c,h,e,c,k,i,n und g auslesen
 * alle Buchstaben in Arrays ablegen
 * Anzahl der erkannten Buchstaben getrennt zählen
 * aus dem Inhalt der Arrays eine doppelt verkettete Liste bilden
 * alle Elemente aus anything löschen
 * die Liste so sortieren, dass "model checking" zu lesen ist (solange Vorrat reicht)
 * Liste in die Ausgabedatei schreiben
 */

#define LENGTH 13   //Laenge von "modelchecking"
#define ELEM 1000   //Anzahl der maximalen Haeufigkeit der Buchstaben

int main(int argc, char **argv)
{
    FILE    *f;
    int     c;
    int     count[LENGTH];
    char    letters[LENGTH] = "modelchecking";
    int     i;

    for (i = 0; i < LENGTH; i++) {
        count[i] = 0;
    }

    f = fopen("IO.txt","r");

    while ( (c=fgetc(f)) != EOF ) {
        for (i = 0; i < LENGTH; i++) {
            if (c == letters[i]) {
                count[i] += 1;
            }
        }
    }

    fclose(f);

    for (i = 0; i < LENGTH; i++) {
        printf("%c: %d\n",letters[i],count[i]);
    }

    return 0;
}
