//ALL TESTS PASSED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wunzip_file(FILE *fr);

int main (int argc, char *argv[])
{   
    if( (argv[1] == NULL) ){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    for(int x = 1; x < argc; x++){
        FILE *fread = fopen(argv[x], "r");
        wunzip_file(fread);
        fclose(fread);
    }
    return 0;
}

void wunzip_file(FILE *fr){
    if((fr == NULL) ){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    int count;
    char word;
    while(fread(&count, 4, 1, fr)){
        fread(&word, 1, 1, fr);
        for (int q = 0; q < count; q++){
            fwrite(&word, 1, 1, stdout);
        }
    }
}