//ALL TESTS PASSED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wzip_file(FILE *fr, int check_argc, int *count, char *first_word, char *sec_word);

int main (int argc, char *argv[])
{   
    if( (argv[1] == NULL) ){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    int count = 0;
    int check_argc = argc;
    char first_word = ' ', sec_word = ' ';
    for(int x = 1; x < argc; x++){
        FILE *fread = fopen(argv[x], "r");
        check_argc--;
        wzip_file(fread, check_argc, &count, &first_word, &sec_word);
        fclose(fread);
    }
    return 0;
}

void wzip_file(FILE *fr, int check_argc, int *count, char *first_word, char *sec_word){
    if((fr == NULL) ){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    int f = 1;
    while(!feof(fr)){
        if(feof(fr)){
            break;
        }
        if(f == 1){
            *first_word = fgetc(fr);
            f = 0;
        }
        *sec_word = fgetc(fr);
        if((*first_word == *sec_word) ){
                *count = *count + 1;
                *first_word = *sec_word;
            }
        else{
            if(check_argc == 1 && *first_word != '\0'){
                *count = *count + 1;
                fwrite(count, 4, 1, stdout);
                fwrite(first_word, 1, 1, stdout);
                *count = 0;
                *first_word = *sec_word;
            }
            else{
                *count = *count + 1;
            }
        }
    }
}