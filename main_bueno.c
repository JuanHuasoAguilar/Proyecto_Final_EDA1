/*Programa realizado el 19/08/2021 por:
    Aguilar Ramos Enrique Alejandro
    Huaso Aguilar Juan Manuel
    Muñoz Cruz Juan Carlos
    Vázquez Reyes Sebastián
*/

#include "funciones_bueno.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pila *pila = crear_pila();
    cola *final = crear_cola();
    int lonCadenaChida, k;
    int selector;
    char *str;
    str = argv[1];
    lonCadenaChida = strlen(str);

    for (k = 0; k < lonCadenaChida; k++)
    {

        if (es_parentesis_izquierdo(str[k])) // PARENTESIS IZQUIERDO (
        {
            push(pila, str[k]);
        }

        else if (es_operando(str[k])) // ES OPERANDO
        {
            enqueue(final, str[k]);
        }

        else if (es_operador(str[k])) //ES OPERADOR
        {

            if (/*es_vacia(pila)*/pila->num==0) //CASO 1 LA PILA ESTÁ VACIA
            {
                push(pila, str[k]);
            }
            else if (es_vacia(pila) != true)
            {
                if (prioridad_fuera_de_la_pila(str[k]) > prioridad_dentro_de_la_pila(*cabezaP(pila)))
                {
                    push(pila, str[k]);
                }
                else
                {
                    if (prioridad_fuera_de_la_pila(str[k]) <= prioridad_dentro_de_la_pila(*cabezaP(pila)))
                    {
                        enqueue(final, *cabezaP(pila));
                        pop(pila);
                        push(pila, str[k]);
                    }
                }
            }
        }

        else if (str[k] == 41) //  ) SACAR HASTA (
        {
            while (*cabezaP(pila) != 40)
            {
                enqueue(final, *cabezaP(pila));
                pop(pila);
            }
            pop(pila);
        }
    } //FIN FOR

    if (es_vacia(pila) != true)
    {
        while (pila->num != 0)
        {
            enqueue(final, *cabezaP(pila));
            pop(pila);
        }
    }

    printf("\nNOTACION INFIJA: ");
    for (k = 0; k < lonCadenaChida; k++)
    {
        printf("%c", str[k]);
    }

    printf("\nNOTACION POSTFIJA:");
    imprimir_cola(final);

    printf("\n\nQUIERES GUARDAR LA NOTACION \n\t1)SI\n\t2)NO\n");
    scanf("%d", &selector);
    if(selector==1)
        guardarNotacion(final);

    
    
    printf("\n\nEVALUAR LA NOTACION POSTFIJA\n\t1)DESDE ARCHIVO\n\t2)DESDE TECLADO\n");
    scanf("%d", &selector);
    
    switch (selector)
    {
    case 1:
        printf("\nEVALUACION POR ARCHIVO\n");
            evaluarArchivo(final);
            break;

    case 2:
            printf("\nEVALUACION POR TECLADO\n");
            valoresXteclado(final);
            evaluarExpresion(final);
            break;

    default:
        printf("\nVALOR FUERA DEL RANGO!!!");
        break;
    }
    
    free(pila);
    vaciarC(final);
    free(final);

    printf("\nFIN PROGRAMA ;)\n");
    return 0;
}