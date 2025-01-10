#include "shell.h"

/* Comparer deux chaînes de caractères */
int compare_strings(char *str1, char *str2)
{
    return strcmp(str1, str2);
}

/* Concaténer deux chaînes de caractères */
int concat_strings(char *dest, char *src)
{
    return strcat(dest, src) != NULL;
}

/* Copier une chaîne dans une autre */
int copy_string(char *dest, char *src)
{
    return strcpy(dest, src) != NULL;
}

/* Dupliquer une chaîne */
char *duplicate_string(char *source)
{
    return strdup(source);
}

/* Retourner la longueur d'une chaîne */
int string_length(char *str)
{
    return strlen(str);
}

/* Trouver un caractère dans une chaîne */
char *find_char(char *str, char character)
{
    return strchr(str, character);
}
