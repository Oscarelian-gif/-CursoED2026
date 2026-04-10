#include <stdio.h>

#define MAX 100

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void burbuja(int arr[], int n) {
    printf("\n--- METODO BURBUJA ---\n");

    for (int i = 0; i < n - 1; i++) {
        printf("\nPasada %d:\n", i + 1);

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                printf("Intercambio: %d <-> %d\n", arr[j], arr[j + 1]);

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                imprimir(arr, n);
            }
        }
        printf("Fin de la pasada %d: ", i + 1);
        imprimir(arr, n);
    }
}

void seleccion(int arr[], int n) {
    printf("\n--- METODO SELECCION ---\n");

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            printf("Intercambio: %d <-> %d\n", arr[i], arr[minIndex]);

            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            imprimir(arr, n);
        }

        printf("Fin de la pasada %d: ", i + 1);
        imprimir(arr, n);
    }
}



void insercion(int arr[], int n) {
    printf("\n--- METODO INSERCION ---\n");

    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;

        printf("\nPasada %d:\n", i);

        while (j >= 0 && arr[j] > clave) {
            printf("Movimiento: %d -> posicion %d\n", arr[j], j + 1);

            arr[j + 1] = arr[j];
            j--;
            imprimir(arr, n);
        }

        arr[j + 1] = clave;

        printf("Insertar %d en posicion %d\n", clave, j + 1);
        imprimir(arr, n);
    }
}


int main() {
    int arr[MAX];
    int n = 0;
    int opcion;
    int datosCargados = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Registrar datos\n");

        if (datosCargados) {
            printf("2. Mostrar arreglo\n");
            printf("3. Ordenar Burbuja\n");
            printf("4. Ordenar Seleccion\n");
            printf("5. Ordenar Insercion\n");
        }

        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                printf("Cantidad de datos: ");
                scanf("%d", &n);

                for (int i = 0; i < n; i++) {
                    printf("Elemento %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }

                datosCargados = 1;
                break;

            case 2:
                if (datosCargados) {
                    printf("Arreglo original: ");
                    imprimir(arr, n);
                } else {
                    printf("Primero debes ingresar datos.\n");
                }
                break;

            case 3:
                if (datosCargados) {
                    burbuja(arr, n);
                } else {
                    printf("Primero debes ingresar datos.\n");
                }
                break;

            case 4:
                if (datosCargados) {
                    seleccion(arr, n);
                } else {
                    printf("Primero debes ingresar datos.\n");
                }
                break;

            case 5:
                if (datosCargados) {
                    insercion(arr, n);
                } else {
                    printf("Primero debes ingresar datos.\n");
                }
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 6);

    return 0;
}