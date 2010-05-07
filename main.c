#include "useful.h"

/*
 * TODO
 * + aus der Datei "IO.txt" alle Buchstaben m,o,d,e,l,c,h,e,c,k,i,n und g auslesen
 * + alle Buchstaben in einem Array ablegen
 * + Anzahl der erkannten Buchstaben getrennt zählen
 * + aus dem Inhalt der Arrays eine doppelt verkettete Liste bilden
 * + (quasi) alle Elemente aus anything löschen
 * die Liste so sortieren, dass "model checking" zu lesen ist (solange Vorrat reicht)
 * Liste in die Ausgabedatei schreiben
 */

void swapc(char *x, char *y)
{
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(int argc, char **argv)
{
    FILE                *f_in;                                     //Eingabedatei
    FILE                *f_out;                                 //Ausgabedatei
    char                c;                                      //aktuelles Zeichen
    int                 sum = 0;                                //Gesamtanzahl der Buchstaben
    static char         *chkletters = {"modelchecking"};        //zu ueberpruefende Buchstaben
    int                 laenge_chkletters = strlen(chkletters);
    int                 count[laenge_chkletters];               //Anzahl eines bestimmten Buchstaben
    char                *let;                                   //Array mit allen gespeicherten Buchstaben
    struct letter_list  mylist;
    struct letter_list  sortedlist;
    struct letter_list  *temp;
    //struct list_head    *pos;

    int                 i;

    static char         *anything = {"Please try to commit suicide, please!!!"};

    for (i = 0; i < laenge_chkletters; i++) count[i] = 0;

    f_in = fopen("IO.txt","r");
    let = malloc(sizeof(char));

    while ( (c=fgetc(f_in)) != EOF ) {
        for (i = 0; i < laenge_chkletters; i++) {
            if (c == chkletters[i]) {
                let[sum] = c;
                let = realloc(let, strlen(let) + sizeof(char));
                count[i] += 1;
                sum++;
            }
        }
    }

    fclose(f_in);

    //Anzahl der gesuchten Buchstaben ausgeben:
    for (i = 0; i < laenge_chkletters; i++) {
        printf("%c: %d\n",chkletters[i],count[i]);
    }

    INIT_LIST_HEAD(&mylist.list);
    for (i = 0; i < sum; i++) {
        temp = malloc( sizeof(struct letter_list) );
        temp->curr = let[i];
        list_add_tail( &(temp->list), &(mylist.list) );
    }

    //Array mit den eingelesenen Buchstaben ausgeben:
    printf("Array der eingelesenen Buchstaben:\n");
    //printf("%s",let);
    printf("\n");

    //Liste mit Buchstaben ausgeben:
    printf("Liste mit Buchstaben ausgeben:\n");
    //list_for_each_entry( temp, &mylist.list, list ) printf("%c",temp->curr);
    printf("\n");

    i = 0;
    INIT_LIST_HEAD(&sortedlist.list);

    list_for_each_entry( temp, &mylist.list, list ){
        if( chkletters[i] == temp->curr ){
            printf("%c",temp->curr);
            i = (i+1) % laenge_chkletters;
            //list_move_tail( &(temp->list), &(sortedlist.list) );
            //list_add( &(temp->list), &(sortedlist.list) );
        }
    }
    //list_move_tail( &(mylist.list), &(sortedlist.list) );
    //list_for_each_entry( temp, &mylist.list, list ) list_move_tail( &(temp->list), &(sortedlist.list));
    //list_del_init( &(mylist.list) );
    printf("\n");

    //Liste in Datei schreiben:
    f_out = fopen("out.txt","w");
    list_for_each_entry( temp, &sortedlist.list, list ) fputc( temp->curr, f_out );
    fclose(f_out);

    free(let);

    anything[0] = '\0';
    if(strlen(anything)) printf("anything ist noch nicht leer: %s\n",anything);

    return 0;
}
