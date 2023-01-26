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














// /*
//     GREP with wide character support.
//     This program handles only immediate pattern.
//     Set environment variable LANG before invokind this command.
//     e.g.  LANG=ja_JP.eucJP ./wgrep PATTERN FILE...
// */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/types.h>
// #include <locale.h>
// #include <wchar.h>


// int main(int argc, char *argv[]){

// }



// static void do_grep(wchar_t *pattern, FILE *f, char *argv);

// int
// main(int argc, char *argv[])
// {
//     wchar_t pattern[1024];
//     int i;

//     setlocale(LC_CTYPE, "");
//     if (argc < 2) {
//         fputs("no pattern\n", stderr);
//         exit(1);
//     }
//     if (mbstowcs(pattern, argv[1], 1024) == (size_t)(-1)) {
//         fprintf(stderr, "wgrep: searchterm %s\n", argv[2]);
//         exit(1);
//     }
//     if (argc == 2) {
//         do_grep(pattern, stdin, argv[2]);
//     }
//     else {
//         for (i = 2; i < argc; i++) {
//             FILE *f;
            
//             f = fopen(argv[i], "r");
//             if (!f) {
//                 perror(argv[i]);
//                 exit(1);
//             }
//             do_grep(pattern, f, argv[2]);
//             fclose(f);
//         }
//     }
//     exit(0);
// }

// static void
// do_grep(wchar_t *pattern, FILE *src, char *argv)
// {
//     char buf[4096];
//     wchar_t wbuf[4096];

//     while (fgets(buf, sizeof buf, src)) {
//         if (mbstowcs(wbuf, buf, 4096) == (size_t)(-1)) {
//             fprintf(stderr, "wgrep: searchterm %s\n", argv);
//             exit(1);
//         }
//         if (wcsstr(wbuf, pattern)) {
//             fputs(buf, stdout);
//         }
//     }
// }