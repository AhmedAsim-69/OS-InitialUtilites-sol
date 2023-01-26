#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wzip_file(FILE *fr, int check_argc, int *count, char *first_word, char *sec_word);
int count_lines_in_file(FILE *fp);


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
    // char buffer[512];
    if((fr == NULL) ){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    int c = 0;
    int f = 1;
    while(!feof(fr)){
        c++;
        if(f == 1){
            *first_word = fgetc(fr);
            f = 0;
        }
        if(feof(fr)){
            // printf("EEEOOOOFFFFF!!!, c = %d", c);
            break;
        }
        *sec_word = fgetc(fr);
        if((*first_word == *sec_word) ){
                *count = *count + 1;
                *first_word = *sec_word;
            }
        else{
            if(check_argc == 1){
                // if(*first_word == '\n' && *sec_word == EOF){
                // break;
                // }
                *count = *count + 1;
                fwrite(count, 4, 1, stdout);
                fwrite(first_word, 1, 1, stdout);
                // if(*sec_word == EOF){
                //     printf("\n------ WHEN WROTE ------\n");
                //     printf("FIRST = %c, SEC = %c, COUNT = %d\n", *first_word, *sec_word, *count);
                // }
                *count = 0;
                *first_word = *sec_word;
            }
            else{
                *count = *count + 1;
            }
        }
    }
}

int count_lines_in_file(FILE *fp){
    int lines = 0;
    int ch = 0;
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if (ch == '\n'){
            lines++;
        }
    }
    return lines;
}
