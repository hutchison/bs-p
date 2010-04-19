#include "useful.h"

/*
 * TODO
 * + aus der Datei "IO.txt" alle Buchstaben m,o,d,e,l,c,h,e,c,k,i,n und g auslesen
 * + alle Buchstaben in einem Array ablegen
 * + Anzahl der erkannten Buchstaben getrennt zählen
 * aus dem Inhalt der Arrays eine doppelt verkettete Liste bilden
 * alle Elemente aus anything löschen
 * die Liste so sortieren, dass "model checking" zu lesen ist (solange Vorrat reicht)
 * Liste in die Ausgabedatei schreiben
 */

#define LENGTH  11   //Laenge von "modelchecking"

int main(int argc, char **argv)
{
    FILE    *f;                                     //Eingabedatei
    char    c;                                      //aktuelles Zeichen
    int     count[LENGTH];                          //Anzahl eines bestimmten Buchstaben
    int     sum = 0;                                //Gesamtanzahl der Buchstaben
    char    chkletters[LENGTH] = "modelchking";     //zu ueberpruefende Buchstaben
    char    *let;                                   //Array mit allen gespeicherten Buchstaben
    int     i;
    //static char *anything ={"Please try to commit suicide, please!!!"};

    for (i = 0; i < LENGTH; i++) count[i] = 0;

    f = fopen("IO.txt","r");
    let = malloc(sizeof(char));

    while ( (c=fgetc(f)) != EOF ) {
        for (i = 0; i < LENGTH; i++) {
            if (c == chkletters[i]) {
                //abspeichern:
                let[sum] = c;

                //neuen Speicher fuer das naechste Element anfordern:
                let = realloc(let, strlen(let) + sizeof(char));

                //Anzahl hochzaehlen:
                count[i] += 1;
                sum++;
            }
        }
    }

    fclose(f);

    //Anzahl der gesuchten Buchstaben ausgeben::
    for (i = 0; i < LENGTH; i++) {
        printf("%c: %d\n",chkletters[i],count[i]);
    }

    //Array mit den eingelesenen Buchstaben ausgeben:
    printf("%s\n",let);

    //Speicher freigeben:
    free(let);

    //erster Test:
    //free(anything);

    return 0;
}
