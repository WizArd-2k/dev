#include <stdio.h>
int main()
{
    FILE *filePtr;
    if ((filePtr = fopen("test_file", "r")) == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir en écriture le fichier test_file\n");
        fopen("test_file","w");
    }
    else
    {
        printf("Ouverture en écriture du fichier test_file réussie\n");
        fclose(filePtr);
    }
    return 0;
}
