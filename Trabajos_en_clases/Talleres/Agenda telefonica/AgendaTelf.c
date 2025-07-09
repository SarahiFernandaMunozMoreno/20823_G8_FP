#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void agregar() {
    FILE *f = fopen("agenda.txt", "a");
    if (f == NULL) {
        printf("No se pudo abrir el fichero.\n");
        return;
    }

    char nombre[50];
    char telefono[20];
    char correo[50];
    char callePrincipal[50];
    char calleSecundaria[50];

    printf("Nombre: ");
    scanf("%s", nombre);
    printf("Telefono: ");
    scanf("%s", telefono);
    printf("Correo: ");
    scanf("%s", correo);
    printf("Direccion Calle Principal: ");
    scanf("%s", callePrincipal);
    printf("Direccion Calle Secundaria: ");
    scanf("%s", calleSecundaria);

    // Escribimos todos los datos
    fprintf(f, "%s %s %s %s %s\n", nombre, telefono, correo, callePrincipal, calleSecundaria);
    fclose(f);
    printf("Registro agregado.\n");
}

void listar() {
    FILE *f = fopen("agenda.txt", "r");
    if (f == NULL) {
        printf("No se pudo abrir el fichero.\n");
        return;
    }

    char nombre[50], telefono[20], correo[50], callePrincipal[50], calleSecundaria[50];
    printf("Registros:\n");

    while (fscanf(f, "%s %s %s %s %s", nombre, telefono, correo, callePrincipal, calleSecundaria) == 5) {
        printf("Nombre: %s\nTelefono: %s\nCorreo: %s\nCalle Principal: %s\nCalle Secundaria: %s\n",
               nombre, telefono, correo, callePrincipal, calleSecundaria);
    }

    fclose(f);
}

void actualizar() {
    FILE *f = fopen("agenda.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (f == NULL || temp == NULL) {
        printf("Error al abrir ficheros.\n");
        return;
    }

    char nombre[50], telefono[20], correo[50], callePrincipal[50], calleSecundaria[50];
    char nombreBuscado[50];
    int encontrado = 0;

    printf("Nombre a actualizar: ");
    scanf("%s", nombreBuscado);

    while (fscanf(f, "%s %s %s %s %s", nombre, telefono, correo, callePrincipal, calleSecundaria) == 5) {
        if (strcmp(nombre, nombreBuscado) == 0) {
            printf("Nuevo Telefono: ");
            scanf("%s", telefono);
            printf("Nuevo Correo: ");
            scanf("%s", correo);
            printf("Nueva Calle Principal: ");
            scanf("%s", callePrincipal);
            printf("Nueva Calle Secundaria: ");
            scanf("%s", calleSecundaria);
            encontrado = 1;
        }
        fprintf(temp, "%s %s %s %s %s\n", nombre, telefono, correo, callePrincipal, calleSecundaria);
    }

    fclose(f);
    fclose(temp);
    remove("agenda.txt");
    rename("temp.txt", "agenda.txt");

    if (encontrado)
        printf("Registro actualizado.\n");
    else
        printf("Registro no encontrado.\n");
}

void eliminar() {
    FILE *f = fopen("agenda.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (f == NULL || temp == NULL) {
        printf("Error al abrir ficheros.\n");
        return;
    }

    char nombre[50], telefono[20], correo[50], callePrincipal[50], calleSecundaria[50];
    char nombreBuscado[50];
    int encontrado = 0;

    printf("Nombre a eliminar: ");
    scanf("%s", nombreBuscado);

    while (fscanf(f, "%s %s %s %s %s", nombre, telefono, correo, callePrincipal, calleSecundaria) == 5) {
        if (strcmp(nombre, nombreBuscado) != 0) {
            fprintf(temp, "%s %s %s %s %s\n", nombre, telefono, correo, callePrincipal, calleSecundaria);
        } else {
            encontrado = 1;
        }
    }

    fclose(f);
    fclose(temp);
    remove("agenda.txt");
    rename("temp.txt", "agenda.txt");

    if (encontrado)
        printf("Registro eliminado.\n");
    else
        printf("Registro no encontrado.\n");
}

int main() {
    int opcion;
    do {
        printf("\nAgenda Telefonica:\n");
        printf("1. Agregar\n");
        printf("2. Listar\n");
        printf("3. Actualizar\n");
        printf("4. Eliminar\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: agregar(); break;
            case 2: listar(); break;
            case 3: actualizar(); break;
            case 4: eliminar(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion no válida.\n");
        }
    } while (opcion != 0);

    return 0;
}
