// CMP.BIN
// # cmp command for Gramado OS.

// The cmp command from unix v7
// compare, or compare skipping.
// $ cmp file1 file2

#include <ctype.h>
#include <stdio.h>


FILE *file1; 
FILE *file2;
int eflg=0;
int lflg = 1;
long line= 1;
long chr=0;
long skip1=0;
long skip2=0;

// ----------------------------
static long otoi(char *s);

// ----------------------------


// #todo: Explain it better.
static long otoi(char *s)
{
    long v=0;
    int base=0;
    v = 0;
    base = 10;

    if (*s == '0')
        base = 8;

// #ugly
    while (isdigit(*s)){
        v = v*base + *s++ - '0';
    };

    return (v);
}


int main ( int argc, char *argv[] )
{
    register char c1=0;
    char c2=0;
    char *arg;

    if (argc < 3)
        goto narg;

    arg = argv[1];
    if (arg[0] == '-' && arg[1] == 's')
    {
        lflg--;
        argv++;
        argc--;
    }

    arg = argv[1];
    if (arg[0] == '-' && arg[1] == 'l') 
    {
        lflg++;
        argv++;
        argc--;
    }

    if (argc < 3){
        goto narg;
    }

    arg = argv[1];
    if ( arg[0]=='-' && arg[1]==0 ){
        file1 = stdin;
    } else if((file1 = fopen(arg, "a+")) == NULL){
        goto barg;
    }

    arg = argv[2];
    if ((file2 = fopen(arg, "a+")) == NULL){
        goto barg;
    }

    if (argc>3){
        skip1 = otoi(argv[3]);
    }
    if (argc>4){
        skip2 = otoi(argv[4]);
    }

    while (skip1)
    {
        if ((c1 = getc(file1)) == EOF)
        {
            arg = argv[1];
            goto earg;
        }
        skip1--;
    };

    while (skip2)
    {
        if ((c2 = getc(file2)) == EOF) 
        {
            arg = argv[2];
            goto earg;
        }
        skip2--;
    };

loop:
    chr++;
    c1 = getc(file1);
    c2 = getc(file2);

    if (c1 == c2)
    {
        if (c1 == '\n')
            line++;
        if (c1 == EOF) 
        {
            if (eflg)
                exit(1);
            exit(0);
        }
        goto loop;
    }

    if (lflg == 0)
        exit(1);
    if (c1 == EOF) {
        arg = argv[1];
        goto earg;
    }
    if (c2 == EOF)
        goto earg;
    if (lflg == 1) 
    {
        //printf("%s %s differ: char %ld, line %ld\n", argv[1], arg, chr, line);
        printf("%s %s differ: char %d, line %d\n",
            argv[1], arg, chr, line);
        exit(1);
    }
    eflg = 1;
    //printf("%6ld %3o %3o\n", chr, c1, c2);
    //printf("%6ld %3o %3o\n", chr, c1, c2);
    goto loop;

narg:
    printf("cmp: arg count\n");
    exit(2);
barg:
    if (lflg){
        printf("cmp: cannot open %s\n", arg);
    }
    exit(2);
earg:
    printf("cmp: EOF on %s\n", arg);
    exit(1);
// Not reached
    return 0;
}

