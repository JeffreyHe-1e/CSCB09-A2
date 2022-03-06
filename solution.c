#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUT_STREAM stdout
#define ERR_STREAM stderr

#define MAX_LN_LEN 80
#define SINGLE_CMT "//"


// ### Utility Functions ### 
/*
Print the data given to the specified output stream using fprintf.
- stream: the output stream to print the output
- name, scope, type, size: data to be printed 
*/
void fprintObjData(FILE *stream, char *name, char *scope, char *type, int size) {
    fprintf(stream, "%s\t%s\t%s\t%d\n", name, scope, type, size);
} // end of fprintfObjData


// ### Helper Functions ### 
/*
Print the Exce // Text section of Analysis to the specified output stream.
- stream: the output stream to print the output
- progName: the name of the program to analyze
*/
void fprintExecText(FILE *stream, char *progName) {
    fprintf(stream, "*** exec // text ***\n");
    fprintf(stream, "\t%s\n", progName);
} // end of fprintProgName


void fprintROData(FILE *stream, FILE* progFile) {
    fprintf(stream, "### ROData ###\tscope\ttype\tsize\n");
    
    char *line = (char *)malloc( (MAX_LN_LEN + 1)*sizeof(char) );
    while(fgets(line, MAX_LN_LEN, progFile) != NULL) {
        /* // check for #define statements
        if( strncmp(line, DEFINE, strlen(DEFINE)) == 0 ) {
            fprintf(stream, "[define] found: %s", line);
            // TODO find data
        } */
            
        // check for string literals
        // TODO
    
    }

    free(line);
    rewind(progFile);
} // end of fprintROData

void fprintStaticData(FILE *stream, FILE* progFile) {
    fprintf(stream, "### static data ###\n");
    
    char *line = (char *)malloc( (MAX_LN_LEN + 1)*sizeof(char) );
    while(fgets(line, MAX_LN_LEN, progFile) != NULL) {
        // check for global variables
        // TODO

        // check for static variables
        // TODO
    }

    free(line);
    rewind(progFile);
} // end of fprintStaticData

void fprintHeap(FILE *stream, FILE* progFile) {
    fprintf(stream, "### heap ###\n");
    
    char *line = (char *)malloc( (MAX_LN_LEN + 1)*sizeof(char) );
    while(fgets(line, MAX_LN_LEN, progFile) != NULL) {
        // check for malloc
        // TODO

        // check for calloc
        // TODO
    }

    free(line);
    rewind(progFile);
} // end of fprintHeap

void fprintUnused(FILE *stream, ) {
    fprintf(stream, "####################\n");
    fprintf(stream, "### unused space ###\n");
    fprintf(stream, "####################\n");
}

void fprintStack(FILE *stream, FILE* progFile) {
    fprintf(stream, "### stack ###\n");
    
    char *line = (char *)malloc( (MAX_LN_LEN + 1)*sizeof(char) );
    while(fgets(line, MAX_LN_LEN, progFile) != NULL) {
        // check for arguements
        // TODO

        // check for local variables
        // TODO
    }

    free(line);
    rewind(progFile);
} // end of fprintStack

void fprintNumLines(FILE *stream, FILE* progFile) {
    fprintf(stream, "  - Total number of lines in the file: ");
    
    // TODO count num lines
    fprintf(stream, "\n");

    rewind(progFile);
}

void fprintNumFuncs(FILE *stream, FILE* progFile) {
    fprintf(stream, "  - Total number of functions: ");
    
    // TODO count num functions
    fprintf(stream, "\n");

    rewind(progFile);
}

void fprintNumLinesPerFunc(FILE *stream, FILE* progFile) {
    fprintf(stream, "  - Total number of lines per functions:");
    
    // TODO count num lines per each function
    fprintf(stream, "\n");

    rewind(progFile);
}

void fprintNumVarPerFunc(FILE *stream, FILE* progFile) {
    fprintf(stream, "  - Total number of variables per function: ");
    
    // TODO count num variables per each function
    fprintf(stream, "\n");

    rewind(progFile);
}

void fprintStats(FILE *stream, FILE* progFile) {
    fprintf(stream, "**** STATS ****\n");
    
    fprintNumLines(progFile);
    fprintNumFuncs(progFile);
    fprintNumLinesPerFunc(progFile);
    fprintNumVarPerFunc(progFile);
} // end of fprintStats


// ### Main Function ###  
int main (int argc, char *argv[]) {

    if(argc != 2) {
        fprintf(stderr, "Please enter one file as input.\n");
        return 1;
    }

    FILE *progFile = fopen(argv[1], "r");
    
    if(progFile == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }
    
    fprintExecText(OUT_STREAM, argv[1]);
    fprintf(OUT_STREAM, "\n");

    fprintROData(OUT_STREAM, progFile);
    fprintf(OUT_STREAM, "\n");

    fprintStaticData(OUT_STREAM, progFile);
    fprintf(OUT_STREAM, "\n");

    fprintHeap(OUT_STREAM, progFile);
    fprintf(OUT_STREAM, "\n");

    fprintUnused(OUT_STREAM);
    fprintf(OUT_STREAM, "\n");

    fprintStack(OUT_STREAM, progFile);
    fprintf(OUT_STREAM, "\n");

    fprintStats(OUT_STREAM, progFile);
    fprintf(OUT_STREAM, "//////////////////////////////\n");


   /*  char *line = (char *)malloc((MAX_LN_LEN + 1)*sizeof(char));
    char *token;

    while(fgets(line, MAX_LN_LEN + 1, progFile) != NULL) {
        if(*line == '/' && *(line + 1) == '/') {
            fprintf("comment\n");
            continue;
        }

        fprintf(OUT_STREAM, "%s", line);
        
        token = strtok(line, " ");
        while(token != NULL) {
            fprintf("%s\n", token);
            token = strtok(NULL, " ");
        }
        fprintf("-------\n");
    } */

    if(fclose(progFile) != 0) {
        fprintf(stderr, "Error closing file.\n");
    } 

    return 0;
} // end of main