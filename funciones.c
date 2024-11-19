// funciones.c
#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProducto(Producto productos[], int *numProductos) {
    if (*numProductos >= MAX_PRODUCTOS) {
        printf("No se pueden ingresar más productos.\n");
        return;
    }
    Producto nuevoProducto;
    printf("Ingrese el nombre del producto: ");
    scanf("%s", nuevoProducto.nombre);
    printf("Ingrese el tiempo de fabricación (en unidades): ");
    scanf("%d", &nuevoProducto.tiempoFabricacion);
    printf("Ingrese la cantidad de recursos requeridos: ");
    scanf("%d", &nuevoProducto.recursosRequeridos);
    printf("Ingrese la cantidad demandada: ");
    scanf("%d", &nuevoProducto.cantidad);
    productos[*numProductos] = nuevoProducto;
    (*numProductos)++;
}

void editarProducto(Producto productos[], int numProductos) {
    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i].nombre, nombreBuscar) == 0) {
            printf("Producto encontrado. Ingrese los nuevos datos:\n");
            printf("Nuevo nombre: ");
            scanf("%s", productos[i].nombre);
            printf("Nuevo tiempo de fabricación: ");
            scanf("%d", &productos[i].tiempoFabricacion);
            printf("Nuevos recursos requeridos: ");
            scanf("%d", &productos[i].recursosRequeridos);
            printf("Nueva cantidad demandada: ");
            scanf("%d", &productos[i].cantidad);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(Producto productos[], int *numProductos) {
    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(productos[i].nombre, nombreBuscar) == 0) {
            for (int j = i; j < *numProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            (*numProductos)--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

int calcularTiempoTotal(Producto productos[], int numProductos) {
    int tiempoTotal = 0;
    for (int i = 0; i < numProductos; i++) {
        tiempoTotal += productos[i].tiempoFabricacion * productos[i].cantidad;
    }
    return tiempoTotal;
}

int calcularRecursosTotales(Producto productos[], int numProductos) {
    int recursosTotal = 0;
    for (int i = 0; i < numProductos; i++) {
        recursosTotal += productos[i].recursosRequeridos * productos[i].cantidad;
    }
    return recursosTotal;
}

bool verificarFactibilidad(int tiempoTotal, int recursosTotal, int tiempoLimite, int recursosLimite) {
    return tiempoTotal <= tiempoLimite && recursosTotal <= recursosLimite;
}

void mostrarProductos(Producto productos[], int numProductos) {
    printf("\n--- Lista de productos ---\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto %d:\n", i + 1);
        printf("Nombre: %s\n", productos[i].nombre);
        printf("Tiempo de fabricación: %d\n", productos[i].tiempoFabricacion);
        printf("Recursos requeridos: %d\n", productos[i].recursosRequeridos);
        printf("Cantidad: %d\n\n", productos[i].cantidad);
    }
}
