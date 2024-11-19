// main.c
#include <stdio.h>
#include "funciones.h"

int main() {
    Producto productos[MAX_PRODUCTOS];
    int numProductos = 0;
    int tiempoLimite, recursosLimite;
    int opcion;

    // Configuración de los límites de producción
    printf("Ingrese el tiempo límite de producción disponible: ");
    scanf("%d", &tiempoLimite);
    printf("Ingrese la cantidad total de recursos disponibles: ");
    scanf("%d", &recursosLimite);

    do {
        printf("\n--- Menú ---\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Calcular tiempo y recursos totales\n");
        printf("6. Verificar factibilidad de producción\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarProducto(productos, &numProductos);
                break;
            case 2:
                editarProducto(productos, numProductos);
                break;
            case 3:
                eliminarProducto(productos, &numProductos);
                break;
            case 4:
                mostrarProductos(productos, numProductos);
                break;
            case 5: {
                int tiempoTotal = calcularTiempoTotal(productos, numProductos);
                int recursosTotal = calcularRecursosTotales(productos, numProductos);
                printf("Tiempo total de producción: %d unidades\n", tiempoTotal);
                printf("Recursos totales necesarios: %d unidades\n", recursosTotal);
                break;
            }
            case 6: {
                int tiempoTotal = calcularTiempoTotal(productos, numProductos);
                int recursosTotal = calcularRecursosTotales(productos, numProductos);
                if (verificarFactibilidad(tiempoTotal, recursosTotal, tiempoLimite, recursosLimite)) {
                    printf("La producción es factible.\n");
                } else {
                    printf("La producción no es factible.\n");
                }
                break;
            }
            case 7:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 7);

    return 0;
}
