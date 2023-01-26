//ALL TESTS PASSED

#include <stdio.h>
#include <stdlib.h>
void file_open(char *argv_value);

int main (int argc, char *argv[])
{
    if((argv[1] == NULL) ){
        return 0;
    }
    for(int x = 1; x < argc; x++){
        file_open(argv[x]);
    }
    return 0;
}

void file_open(char *argv_value){
    FILE *fp = fopen(argv_value, "r");
    char buffer[512];
    
    if(fp == NULL){
        printf("wcat: cannot open file\n");
        exit(1);
    }
    while( fgets(buffer, 512, fp) != NULL){
        printf("%s", buffer);
    }
    fclose(fp);
}