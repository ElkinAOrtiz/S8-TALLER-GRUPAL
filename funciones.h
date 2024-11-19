// funciones.h
#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

#include <stdbool.h>

// Definición de la estructura Producto
typedef struct {
    char nombre[MAX_NOMBRE];
    int tiempoFabricacion;
    int recursosRequeridos;
    int cantidad;
} Producto;

// Declaraciones de funciones
void ingresarProducto(Producto productos[], int *numProductos);
void editarProducto(Producto productos[], int numProductos);
void eliminarProducto(Producto productos[], int *numProductos);
int calcularTiempoTotal(Producto productos[], int numProductos);
int calcularRecursosTotales(Producto productos[], int numProductos);
bool verificarFactibilidad(int tiempoTotal, int recursosTotal, int tiempoLimite, int recursosLimite);
void mostrarProductos(Producto productos[], int numProductos);

#endif // FUNCIONES_H
