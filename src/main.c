#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

int main() {
    FILE *file;
    char word[MAX_LEN];
    int count = 0;

    file = fopen("resource/bdd_wordle.txt", "r");
    if (file == NULL) {
        printf("Erreur ouverture fichier\n");
        return 1;
    }

    char letter;
    printf("Entrer une lettre: ");
    scanf(" %c", &letter);

    printf("Mots contenant '%c':\n", letter);

    while (fscanf(file, "%s", word) != EOF) {
        if (strchr(word, letter)) {
            printf("%s\n", word);
        }
        count++;
    }

    fclose(file);

    return 0;
}
