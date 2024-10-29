#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH 1000

/*
    Primer punto para resolver el problema con recursos infinitos:
        * Se realiza un recorrido principal de a un numero sumando con el resto dentro de otro recorrido interno.
        * Hasta encontrar la suma de ambos sea igual al numero requerido.
*/
int puede_formarse_v1(int nums[], int longitud, int requiredSum) {
    for (int i = 0; i < longitud - 1; i++) {
        for (int j = i + 1; j < longitud; j++) {
            if (nums[i] + nums[j] == requiredSum) {
                return 1;
            }
        }
    }
    return 0;
}

/*
    Segundo punto para resolver el problema siendo que los recursos son un bien preciado:
        * Se setea un valor maximo esperado de valores posibles.
        * Se instancia un arr llamado hashSet con este maximo inicializado por un valor 0.
            - Este arr contendra los numeros encontrados dentro de los valores pasados por parametros asigandole un valor booleano.
        * Se recorre el los valores pasados.
            - Guardo el numero necesario cual sumandolo con el numero que se encuentra parado en el bucle de igual al requiredSum.
            - Compruebo que el el numero necesario sera mayor que 0, no supere el valor maximo esperado y se encuentre dentro dentro del arr hashSet con un valor de 1.
            * Si se cumple cierta condicion retorna un 1.
            - En el caso que no se cumpla la condicion compruebo si el numero de esa posicion del recorrido es mayor igual a 0 y este dentro del maximo esperado.
            - Si se cumple que es lo esperado, dentro del arr hashSet utilizo ese numero como indice de posicion para asignarle un valor de 1 siendo este un numero encontrado para la siguiente vuelta/numero.
        * Si no se encuentra la suma retorna un 0.
*/
int puede_formarse_v2(int nums[], int longitud, int requiredSum) {
    int hashSet[MAX_HASH] = {0};

    for (int i = 0; i < longitud; i++) {
        int necesario = requiredSum - nums[i];
        if (necesario > 0 && necesario < MAX_HASH && hashSet[necesario]) {
            return 1;
        }
        if (nums[i] >= 0 && nums[i] < MAX_HASH) {
            hashSet[nums[i]] = 1;
        }
    }
    return 0;
}


// LLamado de las funciones
int main() {
    int nums[5];
    int requiredSum;

    printf("Ingrese 5 numeros distintos separados por espacios: \n");
    scanf("%d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);

    printf("Ingrese un numero esperado con la suma de 2 valores ingresados: \n");
    scanf("%d", &requiredSum);

    //if (puede_formarse_v1(nums, 5, requiredSum)) {
    if (puede_formarse_v2(nums, 5, requiredSum)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
