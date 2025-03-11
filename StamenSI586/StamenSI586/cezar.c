#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 1000
char* cezar_cipher(char* text, int key)
{
    int lenght = strlen(text);
    char* cipher = (char*)malloc(sizeof(char)*(lenght +1));
    for(int i =0;i<lenght;i++)
    {
        cipher[i] = (text[i] - 'a' + key) % 26 + 'a';
    }
    cipher[lenght]='\0';
    return cipher;
}
int main()
{
    char text[MAXN];
    scanf("%s",text);
    int key;
    scanf("%d",&key);
    char* cipher = cezar_cipher(text,key);
    printf("%s",cipher);
    free(cipher);
    return EXIT_SUCCESS;
}