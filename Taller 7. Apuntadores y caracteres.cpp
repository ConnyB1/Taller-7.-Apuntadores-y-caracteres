#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirNombres(char* nombres[], int n);
void invertirCadena(char* cadena);

int main() {
    int opcion;
    int n = 3;
    char* nombres[n];
    
    while (1) {
        printf("\n\tMenú:\n");
        printf("1. Ingresar y mostrar 3 nombres\n");
        printf("2. Invertir una cadena\n");
        printf("3. Ordenar palabras alfabéticamente\n");
        printf("4. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) 
        {
            case 1:
            {
                for (int i = 0; i < n; i++) {
                    nombres[i] = (char*)malloc(50); //malloc me devuelve un puntero void y por así decir guarda la cadena que mande
                    printf("Ingrese un nombre: ");
                    scanf("%s", nombres[i]);
                }
                imprimirNombres(nombres, n);
                break;
            }

            case 2:
            {
                char palabra[50];
                printf("Ingrese una palabra: ");
                scanf("%s", palabra);
                invertirCadena(palabra);
                printf("Palabra invertida: %s\n", palabra);
                break;
            }

            case 3:
            {
                int m;
                printf("Ingrese el número de palabras: ");
                scanf("%d", &m);

                char **palabras = (char**)malloc(m * sizeof(char*));
                char **apuntadores = (char**)malloc(m * sizeof(char*));

                for (int i = 0; i < m; i++) {
                    palabras[i] = (char*)malloc(50);
                    printf("Ingrese una palabra: ");
                    scanf("%s", palabras[i]);
                    apuntadores[i] = palabras[i];
                }

                for (int i = 0; i < m - 1; i++) {
                    for (int j = i + 1; j < m; j++) {
                        if (strcmp(apuntadores[i], apuntadores[j]) > 0) {
                            char *temp = apuntadores[i];
                            apuntadores[i] = apuntadores[j];
                            apuntadores[j] = temp;
                        }
                    }
                }

                printf("Palabras ordenadas:\n");
                for (int i = 0; i < m; i++) 
                {
                    printf("%s\n", apuntadores[i]);
                }

                break;
            }
            case 4:
            {
                return 0;
            }
            default:
            {
                printf("Opción no válida.\n");
                break;
            }
        }
    }
}

void imprimirNombres(char* nombres[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%s\n", nombres[i]);
    }
}

void invertirCadena(char* cadena) 
{
    int len = strlen(cadena);
    for (int i = 0; i < len / 2; i++) 
    {
        char temp = cadena[i];
        cadena[i] = cadena[len - i - 1];
        cadena[len - i - 1] = temp;
    }
}