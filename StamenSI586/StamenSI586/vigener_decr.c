#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXN 1024

char* vigenere_decrypt(char* cipher, char* key) {
    int cipher_length = strlen(cipher);
    int key_length = strlen(key);

    char* plaintext = (char*) malloc(sizeof(char) * (cipher_length + 1));
    if (!plaintext) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memset(plaintext, '\0', sizeof(char) * (cipher_length + 1));

    for (int i = 0; i < cipher_length; i++) {
        if (isalpha(cipher[i])) {
            int shift = tolower(key[i % key_length]) - 'a';
            if (islower(cipher[i])) {
                plaintext[i] = 'a' + (cipher[i] - 'a' - shift + 26) % 26;
            } else {
                plaintext[i] = 'A' + (cipher[i] - 'A' - shift + 26) % 26;
            }
        } else {
            plaintext[i] = cipher[i];
        }
    }

    return plaintext;
}

int main() {
    char cipher[MAXN];
    char key[MAXN];

    FILE *cipherFile = fopen("cipher.txt", "r");
    if (!cipherFile) {
        printf("Error opening cipher.txt\n");
        return EXIT_FAILURE;
    }
    fgets(cipher, MAXN, cipherFile);
    fclose(cipherFile);

    FILE *keyFile = fopen("key.txt", "r");
    if (!keyFile) {
        printf("Error opening key.txt\n");
        return EXIT_FAILURE;
    }
    fgets(key, MAXN, keyFile);
    fclose(keyFile);

    cipher[strcspn(cipher, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    char* plaintext = vigenere_decrypt(cipher, key);

    FILE *outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        printf("Error opening output.txt\n");
        return EXIT_FAILURE;
    }
    fprintf(outputFile, "%s", plaintext);
    fclose(outputFile);


    free(plaintext);

    printf("Decryption complete. Check output.txt\n");

    return EXIT_SUCCESS;
}