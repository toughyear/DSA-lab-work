#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("source file is: %s \n", argv[1]);
    printf("Destination file is: %s \n", argv[2]);
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "w");
    if (file1 == NULL)
    {
        printf("ERROR OPENING FILE!");
        exit(1);
    }
    // now to copy contents

    char c = fgetc(file1);
    while (c != EOF)
    {
        fputc(c, file2);
        c = fgetc(file1);
    }
    fclose(file2);
    fclose(file1);

    return 0;
}