#include <stdio.h>
int main()
{
    FILE *filePtr;
    if ((filePtr = fopen("test_file", "r")) == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir en lecture le fichier test_file\n");
    }
    else
    {
        printf("Ouverture en lecture du fichier test_file réussie\n");
        fclose(filePtr);
    }
    return 0;
}