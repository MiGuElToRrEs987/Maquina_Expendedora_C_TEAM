#include <stdio.h>

struct Producto {
    int id;
    char nombre[50];
    float precio;
    int cantidad;
};

// Sprint 1: Entrada y Salida de datos

// Función para mostrar el menú de la máquina expendedora
void mostrarMenu() {
    printf("----- Máquina Expendedora de Dulces -----\n");
    printf("1. Mostrar productos disponibles\n");
    printf("2. Seleccionar un producto\n");
    printf("3. Modo Administrador\n");
    printf("4. Realizar operación\n");
    printf("5. Salir\n");
    printf("-----------------------------------------\n");
}

// Función para mostrar los productos disponibles
void mostrarProductos(struct Producto productos[], int numProductos) {
    printf("----- Productos Disponibles -----\n");
    for (int i = 0; i < numProductos; i++) {
        printf("ID: %d\n", productos[i].id);
        printf("Nombre: %s\n", productos[i].nombre);
        printf("Precio: %.2f\n", productos[i].precio);
        printf("Cantidad: %d\n", productos[i].cantidad);
        printf("-----------------------\n");
    }
}

// Función para seleccionar un producto
void seleccionarProducto(struct Producto productos[], int numProductos) {
    int idProducto;
    printf("Ingrese el ID del producto: ");
    scanf("%d", &idProducto);

    // Validar la compra del producto
    validarCompra(productos, numProductos, idProducto);
}

// Sprint 2: Condicionales

// Función para validar la compra de un producto
void validarCompra(struct Producto productos[], int numProductos, int idProducto) {
    int indiceProducto = -1;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].id == idProducto) {
            indiceProducto = i;
            break;
        }
    }

    if (indiceProducto == -1) {
        printf("El ID del producto no existe.\n");
    } else {
        float precioProducto = productos[indiceProducto].precio;
        int cantidadProducto = productos[indiceProducto].cantidad;

        if (cantidadProducto == 0) {
            printf("El producto no está disponible en este momento.\n");
        } else {
            printf("Has comprado el producto: %s\n", productos[indiceProducto].nombre);
            // Realizar las operaciones de compra y entrega del producto
            // ...
        }
    }
}

// Sprint 3: Ciclos

// Función para mostrar los precios de los productos
void mostrarPrecios(struct Producto productos[], int numProductos) {
    printf("----- Lista de Precios -----\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Nombre: %s\n", productos[i].nombre);
        printf("Precio: %.2f\n", productos[i].precio);
        printf("-----------------------\n");
    }
}

// Función para gestionar el inventario de productos
void gestionInventario(struct Producto productos[], int numProductos) {
    int idProducto;
    int nuevaCantidad;

    printf("Ingrese el ID del producto: ");
    scanf("%d", &idProducto);

    int indiceProducto = -1;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].id == idProducto) {
            indiceProducto = i;
            break;
        }
    }

    if (indiceProducto == -1) {
        printf("El ID del producto no existe.\n");
    } else {
        printf("Ingrese la nueva cantidad: ");
        scanf("%d", &nuevaCantidad);

        productos[indiceProducto].cantidad = nuevaCantidad;
        printf("La cantidad del producto se actualizó correctamente.\n");
    }
}

// Función para gestionar el dinero de la máquina expendedora
void gestionDinero() {
    // ...
}

// Sprint 4: Pruebas de funcionamiento y manejo de errores

// Funciones de operaciones matemáticas básicas
float sumar(float a, float b) {
    return a + b;
}

float restar(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

// Función para realizar una operación matemática
void realizarOperacion() {
    int opcion;
    float num1, num2;

    printf("Seleccione una operación:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);

    printf("Ingrese el primer número: ");
    scanf("%f", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);

    float resultado;
    switch (opcion) {
        case 1:
            resultado = sumar(num1, num2);
            printf("El resultado de la suma es: %.2f\n", resultado);
            break;
        case 2:
            resultado = restar(num1, num2);
            printf("El resultado de la resta es: %.2f\n", resultado);
            break;
        case 3:
            resultado = multiplicar(num1, num2);
            printf("El resultado de la multiplicación es: %.2f\n", resultado);
            break;
        case 4:
            if (num2 == 0) {
                printf("No se puede dividir entre cero.\n");
            } else {
                resultado = dividir(num1, num2);
                printf("El resultado de la división es: %.2f\n", resultado);
            }
            break;
        default:
            printf("Opción inválida. Por favor, seleccione una opción válida.\n");
            break;
    }
}

// Función para acceder al modo administrador (oculto)
void modoAdministrador() {
    // ...
}

// Función principal
int main() {
    struct Producto productos[] = {
        {1, "Dulce 1", 1.50, 10},
        {2, "Dulce 2", 2.00, 5},
        {3, "Dulce 3", 0.75, 8}
    };
    int numProductos = sizeof(productos) / sizeof(productos[0]);

    int opcion;
    do {
        mostrarMenu();
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarProductos(productos, numProductos);
                break;
            case 2:
                seleccionarProducto(productos, numProductos);
                break;
            case 3:
                modoAdministrador();
                break;
            case 4:
                realizarOperacion();
                break;
            case 5:
                printf("¡Gracias por usar la máquina expendedora!\n");
                break;
            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
