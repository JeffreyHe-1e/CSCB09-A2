#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUT_STREAM stdout
#define ERR_STREAM stderr

typedef struct {
    char name[3];
    char scope[3];
    char type[3];
    int size;
} objData;

// ### Utility Functions ###  
objData *allocObjData() {
    objData *temp = (objData *)malloc(sizeof(objData));
    if(temp != NULL) return temp;
    fprintf(ERR_STREAM, "Error allocating memory\n");
    exit(1);
}

void printObjData(objData *data) {
    fprintf(OUT_STREAM, "%s\t%s\t%s\t%d\n", 
            data->name,
            data->scope, 
            data->type,
            data->size);
}

int main() {
    /* char s[10] = "12345";
    char *d = (char *)malloc( 10*sizeof(char) );
    strncpy(d, s, 10);

    printf("s: %s\n", s);
    printf("d: %s\n", d);
    
    s[0] = 'a';

    printf("s: %s\n", s);
    printf("d: %s\n", d); */

    /* objData *data = allocObjData();
    strcpy(data->name, "a");
    strcpy(data->scope, "b"); 
    strcpy(data->type, "c");
    data->size = 1;

    printObjData(data); */

    char string[10];
    string = "1234567";

    printf("string: %s\n", string);
}