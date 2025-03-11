#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXN 1000

// Функция за дешифриране с Цезаров шифър
void cezar_decipher(char* text, int key) {
    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        if (islower(text[i])) {
            text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
        } else if (isupper(text[i])) {
            text[i] = ((text[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
}

int main() {
    char text[MAXN];
    int key;

    // Отваряне на файла за четене
    FILE *file = fopen("cezar.txt", "r");
    if (file == NULL) {
        perror("Грешка при отваряне на файла");
        return EXIT_FAILURE;
    }

    // Четене на текста от файла
    if (fgets(text, MAXN, file) == NULL) {
        perror("Грешка при четене от файла");
        fclose(file);
        return EXIT_FAILURE;
    }
    fclose(file);

    // Премахване на новия ред, ако съществува
    text[strcspn(text, "\n")] = 0;

    // Въвеждане на ключа от потребителя
    printf("Въведете ключ: ");
    scanf("%d", &key);

    // Дешифриране на текста
    cezar_decipher(text, key);
    printf("Дешифриран текст: %s\n", text);

    return EXIT_SUCCESS;
}
