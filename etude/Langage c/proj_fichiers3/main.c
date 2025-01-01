#include <stdio.h>
int main()
{
    FILE *fp;
    char *ptrStr;
    char chaine[] = "Ligne 1 écrite dans le fichier.\n";
    char chaineOut[100];
    ptrStr = chaine + 6;
    fp = fopen("file.txt", "w+");
    for (int i = 0; i <= 3; i++)
    {
        fwrite(chaine, 1, sizeof(chaine), fp);
        printf("%s", chaine);
        *ptrStr = *ptrStr + 1;
    }
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i <= 3; i++)
    {
        fread(chaineOut, 1, sizeof(chaine), fp);
        printf("%s", chaineOut);
    }
    fclose(fp);
    return (0);
}