//ALL TESTS PASSED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wgrep_file_open(char *word, FILE *fp);

int main (int argc, char *argv[])
{
    if( (argv[1] == NULL) ){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    if(argv[2] == NULL)
    {   FILE *fp = stdin;
        for(int x = 0; x < argc; x+=3){
            wgrep_file_open(argv[x+1], fp);
        }
    }
    else{
        FILE *fp = fopen(argv[2], "r");
        for(int x = 0; x < argc; x+=3){
            wgrep_file_open(argv[x+1], fp);
        }
    }
    return 0;
}

void wgrep_file_open(char *word, FILE *fp){
    char buffer[512];
    if(fp == NULL){
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    while( fgets(buffer, 512, fp) != NULL){
        if(strstr(buffer, word)){
            printf("%s", buffer);
        }
    }
    fclose(fp);
}