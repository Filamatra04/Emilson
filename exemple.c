#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMS 100
#define TAILLE_MAX 100

int main() {
    char noms[MAX_NOMS][TAILLE_MAX];
    int n;
    char lettre;

    printf("Combien de prénoms voulez-vous entrer ? ");
    scanf("%d", &n);

    // Vider le buffer du clavier après scanf
    getchar();

    // Lecture des prénoms
    for (int i = 0; i < n; i++) {
        printf("Entrez le prénom #%d : ", i + 1);
        fgets(noms[i], TAILLE_MAX, stdin);

        // Retirer le saut de ligne si présent
        noms[i][strcspn(noms[i], "\n")] = '\0';
    }

    printf("Entrez une lettre : ");
    scanf(" %c", &lettre);
    lettre = tolower(lettre); // Pour rendre la recherche insensible à la casse

    printf("Prénoms commençant par '%c' :\n", lettre);
    int trouve = 0;
    for (int i = 0; i < n; i++) {
        if (tolower(noms[i][0]) == lettre) {
            printf("- %s\n", noms[i]);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun prénom ne commence par la lettre '%c'.\n", lettre);
    }

    return 0;

