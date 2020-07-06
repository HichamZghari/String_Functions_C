#ifndef _STRING_H
#define _STRING_H


int Len(char *s);

void Concat(char *original, char *add);

void Capitalize(char *s);

void Casefold(char *s);

void Center(char *s, int length, char caracter);

int Count(char *s, char *value);

int Endswith(char *s, char *ending);

void Expandstabs(char *s, int n);

int Index(char *s, char *value, int a, int b);

int Isalnum(char *s);

int Isalpha(char *s);

int Isdecimal(char *s);

int Isprintable(char *s);

int Islower(char *s);

int Isupper(char *s);

int Istitle(char *s);

void Replace(char *orig, char *s1, char *s2);

void Rjust(char *orig, int n, char c);

void Zfill(char *orig, int n);

void Title(char *orig);

void Swapcase(char *orig);

int Startswith(char *orig, char *start);

void Strip(char *orig);

char **Rsplit(char *orig, char sep);

char **Splitlines(char *orig);

char **Rpartition(char *orig, char *part);

int Rfind(char *orig, char *value);

char *Join(char **string_array, int len);

#endif
