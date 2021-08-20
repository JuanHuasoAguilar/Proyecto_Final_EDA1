#include "recursos_bueno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


nodo* crear_nodo(INFO info)     // FUNCIÓN crear_nodo PARA RESERVAR MEMORIA PARA UN NODO. PARÁMETROS: VARIABLE TIPO INFO. RETORNA UN APUNTADOR TIPO nodo
{
    nodo *t=(nodo*)malloc(sizeof(nodo));    //DECLARA UNA VARIABLE APUNTADOR TIPO nodo Y RESERVA MEMORIA CON LA FUNCIÓN malloc
    t->sig=NULL;    //IGUALA EL APUNTADOR AL NODO SIGUIENTE A NULO;
    t->info=info;   //IGUALA LA INFORMACIÓN DEL NODO AL PARÁMETRO QUE RECIVE LA INFORMACIÓN
    t->valor=0;
    return t;   //RETORNA EL APUNTADOR DEL NODO
}

void liberar_nodo(nodo *n)  //FUNCIÓN liberar_nodo PARA LIBERAR MEMORIA DE UN NODO. PARÁMETROS: APUNTADOR TIPO nodo
{
    if(n->sig==NULL)    //CONDICIÓN PARA LIBERAR MEMORIA DEL NODO;
    {
        free(n);    //FUNCIÓN FREE PARA LIBERAR LA MEMORIA DEL NODO
        n=NULL; //LA VARIBLE APUNTA A NULO
    }
}

//----------------------PILA--------------------

pila* crear_pila()  //FUNCIÓN crear_pila PARA CREAR/RESERVAR MEMORIA DE UNA PILA
{
    pila *l=(pila*)malloc(sizeof(pila));    //RESERVA MEMORIA PARA LA VARIABLE APUNTADOR TIPO pila CON LA FUCIÓN MALLOC
    l->head=l->tail=NULL;   //APUNTA LOS APUNTADORES DE LA CABEZA Y LA COLA DE LA PILA A NULO
    l->num=0;   //IGULA EL CONTADOR DE LA PILA A CERO; INICIA EL CONTADOR EN CERO
    return l;   //RETORNA EL APUNTADOR DE LA PILA
}

void liberar_pila(pila *l)  //FUNCIÓN liberar_pila PARA LIBERAR MEMORIA DE LA PILA, PARÁMETROS: VARIABLE APUNTADOR TIPO pila; APUNTADOR A LA PILA
{
    if(l==NULL) return; //RETORNA NULO EN CASO DE QUE LA PILA NO EXISTA
    if(es_vacia(l))     //CODICIÓN PARA LIBERAR MEMORIA DE LA PILA; LA PILA DEBE ESTAR VACÍA
    {
        free(l);    //LIBERA LA MEMORIA RESERVADA DE LA VARIABLE PILA
        l=NULL; //APUNTA A NULO LA VARIABLE DE LA PILA
        return;  //TERMINA LA FUNCIÓN
    }
    else   //LA PILA TIENE ELEMENTOS
    {
        vaciar(l);  //LLAMA A LA FUNCIÓN vaciar PARA VACIAR LA PILA
        free(l);    //LIBERA LA MEMORIA RESERVADA DE LA VARIABLE PILA
        l=NULL; //APUNTA A NULO LA VARIABLE DE LA PILA
        return; //TERMINA LA FUNCIÓN
    }
}

bool push(pila *l, INFO info)
{
    /*FUNCIÓN push PARA INSERTAR UN NODO EN LA PARTE SUPERIOR DE LA PILA,
    PARÁMETROS: VARIBALE APUNTADOR TIPO pila; APUNTADOR A LA PILA, VARIABLE TIPO INFO, INFORMACIÓN DE NODO*/

    nodo* nuevo=crear_nodo(info);   //DECLARA Y CREA UN NODO NUEVO CON LA FUNCIÓN crear_nodo
    if(l->head == NULL && l->tail==NULL)    //CONDICIÓN PARA INSERTAR SI LA PILA ESTA VACÍA, EL APUNTADOR A CABEZA Y LA COLA APUNTAN A NULO
    {
        l->head=l->tail=nuevo;  //LOS APUNTADORES A LA CABEZA Y COLA DE LA PILA APUNTAN AL NUEVO Y ÚNICO NODO
        l->num++;   //AUMENTA EL CONTADOR DE NODOS DE LA PILA EN UNO
        return true;    //TERMINA LA FUNCIÓN HABIENDO INSERTADO UN NODO, RETORNA TRUE
    }
    else    //EXISTE ALMENOS UN NODO EN LA PILA
    {
        nuevo->sig=l->head; //IGUALA EL APUNTADOR AL SIGUIENTE NODO DEL NODO NUEVO A LA CABEZA
        l->head=nuevo;  //IGULA EL APUNTADOR CABEZA AL NUEVO NODO; RECORRE EL APUNTADOR DE LA CABEZA DE LA PILA AL NODO NUEVO
        l->num++;   //AUMENTA EL CONTADOR DE NODOS DE LA PILA EN UNO
        return true;    //TERMINA LA FUNCIÓN HABIENDO INSERTADO UN NODO, RETORNA TRUE
    }
    return false;   //RETORNA FALSE EN CASO DE NO CUMPLIR ALGUNA DE LAS CONDICIONES ANTERIORES
}

void pop(pila *l)   //FUNCIÓN pop PARA ELIMINAR EL NODO DE LA PARTE SUPERIOR DE LA PILA, PARÁMETROS: VARIABLE APUNTADOR TIPO pila, APUNTADOR A LA PILA
{
    if(es_vacia(l)) return; //CONDICIÓN PARA RETORNAR EL CONTROL A LA FUNCIÓN QUE LA MANDO LLAMAR SI LA PILA ESTÁ VACÍA; NO ELIMINA
    nodo* temporal=l->head; //DECLARA Y CREA UN NODO TEMPORAL Y LO IGUALA A LA CABEZA DE LA PILA
    l->head=l->head->sig;   //IGUALA EL APUNTADOR DE LA CABEZA DE LA PILA AL NODO QUE APUNTA EL APUNTADOR AL SIGUIENTE NODO DE LA CABEZA; RECORRE LA CABEZA AL SIGUIENTE NODO
    temporal->sig=NULL; //IGUALA EL APUNTADOR AL SIGUIENTE NODO DE TEMPORAL A NULO, CONDICIÓN PARA LIBERAR MEMORIA
    liberar_nodo(temporal); //LLAMA LA FUNCIÓN liberar_nodo PARA LIBERAR LA MEMORIA DEL NODO TEMPORAL
    l->num--;   //DECREMENTA EL CONTADOR DE NODOS DE LA PILA EN UNO

}

INFO* cabezaP(pila *l)
{
    /*FUNCIÓN cabezaP PARA RETORNAR LA DIRECCIÓN DE MEMORIA DE LA INFORMACIÓN DE NODO SUPERIOR DE LA PILA,
    PARÁMETROS: APUNTADOR TIPO pila; APUNTADOR A LA PILA*/

    if(es_vacia(l)) return NULL;    //CONDICIÓN PARA RETORNAR NULO SI LA PILA ESTÁ VACÍA
    else return &l->head->info; //RETONA LA DIRECCIÓN DE LA INFORMACIÓN DEL NODO SUPERIOR DE LA PILA
}

bool es_vacia(pila *l)  //FUNCIÓN es_vacia PARA DETERMINAR SI LA PILA ESTÁ VACÍA, PARÁMETROS: VARIABLE APUNTADOR TIPO pila;APUNTADOR A LA PILA
{
    if(l->head == NULL && l->tail == NULL) return true; /*CONDICÓN PARA DETERMINAR SI LA LISTA ESTÁ VACÍA,
    LOS APUTNADORES DE LA CABEZA Y COLA TIENEN QUE APUNTAR A NULO, RETORNA TRUE*/
    return false;   //RETORNA FALSE EN CASO DE QUE LA LISTA NO ESTÉ VACÍA
}

bool vaciar(pila *l)
{
    /*FUNCIÓN vaciar PARA VACIAR LA PILA,
    PARÁMETROS: VARIABLE APUNTADOR TIPO pila; APUNTADOR A LA PILA, ELIMINA DE LA PARTE SUPERIOR A LA INFERIOR*/

    if(es_vacia(l)) return false;   //CONDICIÓN PARA RETORNAR FALSE EN CASO DE QUE LA LISTA ESTÉ VACÍA

    nodo *temporal=l->head; //DECLARA UN APUNTADOR TIPO nodo TEMPORAL Y LA IGUALA A LA CABEZA DE LA PILA
    while(temporal != NULL) //CICLO WHILE, SE REPITE HASTA QUE LA VARIABLE TEMPORAL SEA IGUAL A NULO
    {
        l->head=temporal->sig;  //IGUALA EL APUNTDO DE LA CABEZA AL APUNTADOR AL SIGUIENTE NODO DE TEMPORAL, RECORRE LA CABEZA AL SIGUIENTE NODO
        temporal->sig=NULL; //IGUALA EL APUTNADOR AL SIGUIENTE NODO DE TEMPORAL A NULO, CONDICIÓN PARA LIBERAR MEMORIA DEL NODO
        liberar_nodo(temporal); //LLAMA A LA FUNCIÓN liberar_nodo PARA LIBERAR LA MEMORIA DE TEMPORAL
        temporal=l->head;   //IGUALA TEMPORAL A LA CABEZA
    }
    l->head=l->tail=NULL;   //IGUALA LOS APUNTADORES DE CABEZA Y COLA A NULO
    l->num=0;   //IGUALA EL CONTADOR DE NODOS DE LA LISTA A CERO
    return true;    //RETORNA TRUE, LA PILA SE VACIÓ
}

void imprimir_pila(pila *l) //FUNCIÓN imprimir_pila PARA IMPRIMIR LA PILA, PARÁMTROS: VARIABLE APUNTADOR TIPO pila; APUNTADOR A LA PILA
{
    if(l==NULL) //CODICIÓN PARA EJECUTAR EL BLOQUE EN CASO DE QUE LA PILA APUNTE A NULO, NO EXISTE LA PILA
    {
        printf("NO EXISTE LA PILA \n");  //MANDA UN MENSAJE AL USUARIO
        return; //TERMINA LA FUNCIÓN
    }   
    if(es_vacia(l))   //CONDICIÓN PARA EJECUTAR EL BLOQUE EN CASO DE QUE LA PILA ESTÉ VACÍA
    {
        printf("PILA VACIA\n"); //MANDA UN MENSAJE AL USUARIO
        return; //TERMINA LA FUNCIÓN
    }
    nodo* t=NULL;   //DECLARA UNA VARIABLE APUNTADOR TIPO nodo Y LA IGUALA A NULO
    for(t=l->head; t != NULL; t=t->sig) //CICLO FOR PARA RECORRER CADA DEL ÚLTIMO AL PRIMERO
    {
        printf("%c %f\n", t->info, t->valor);    //IMPRIME LA INFORMACIÓN DEL NODO
    }
    printf("\n\n"); //IMPRIME UN SALTO DE LÍNEA
    return; //TERMINA LA FUNCIÓN
}

//COLA

cola* crear_cola()  //FUNCIÓN crear_cola PARA CREAR/RESERVAR MEMORIA DE UNA cola
{
    cola *l=(cola*)malloc(sizeof(cola));    //RESERVA MEMORIA PARA LA VARIABLE APUNTADOR TIPO cola CON LA FUCIÓN MALLOC
    l->head=l->tail=NULL;   //APUNTA LOS APUNTADORES DE LA CABEZA Y LA COLA DE LA COLA A NULO
    l->num=0;   //IGULA EL CONTADOR DE LA COLA A CERO; INICIA EL CONTADOR EN CERO
    return l;   //RETORNA EL APUNTADOR DE LA COLA
}

void liberar_cola(cola *l)  //FUNCIÓN liberar_cola PARA LIBERAR MEMORIA DE LA COLA, PARÁMETROS: VARIABLE APUNTADOR TIPO cola; APUNTADOR A LA COLA
{
    if(l==NULL) return; //RETORNA NULO EN CASO DE QUE LA PILA NO EXISTA
    if(!es_vaciaC(l))   //CONDICIÓN PARA DETERMINAR SI LA COLA NO ESTÁ VACÍA
        vaciarC(l); //LLAMA A LA FUNCIÓN vaciasC PARA VACIAR LA COLA
    free(l);    //LLAMA A LA FUNCIÓN free PARA LIBERAR LA MEMORIA RESERVADA PARA LA COLA
    l=NULL; //APUNTA A NULO LA VARIBALE DE LA COLA

}

bool enqueue(cola *l, INFO info)
{
    /*FUNCIÓN enqueue PARA INSERTAR UN NODO AL FINAL DE LA COLA,
    PARÁMETROS: VARIBALE APUNTADOR TIPO cola; APUNTADOR A LA COLA, VARIABLE TIPO INFO, INFORMACIÓN DE NODO*/

    nodo* nuevo=crear_nodo(info);  //DECLARA Y CREA UN NODO NUEVO CON LA FUNCIÓN crear_nodo
    if(l->head == NULL && l->tail==NULL)    //CONDICIÓN PARA INSERTAR SI LA COLA ESTA VACÍA, EL APUNTADOR A CABEZA Y LA COLA APUNTAN A NULO
    {
        l->head=l->tail=nuevo;  //LOS APUNTADORES A LA CABEZA Y COLA DE LA PILA APUNTAN AL NUEVO Y ÚNICO NODO
        l->num++;   //AUMENTA EL CONTADOR DE NODOS DE LA COLA EN UNO
        return true;    //TERMINA LA FUNCIÓN HABIENDO INSERTADO UN NODO, RETORNA TRUE
    }
    else    //EXISTE ALMENOS UN NODO EN LA PILA
    {
        l->tail->sig=nuevo; //IGUALA EL APUNTADOR AL SIGUIENTE NODO DE LA COLA AL NUEVO NODO
        l->tail=nuevo;  //IGUALA LA COLA AL NUEVO NODO; RECORRE LA COLA AL NUEVO NODO
        l->num++;   //AUMENTA EL CONTADOR DE NODOS DE LA COLA EN UNO
        return true;    //TERMINA LA FUNCIÓN HABIENDO INSERTADO UN NODO, RETORNA TRUE
    }
    return false;   //RETORNA FALSE EN CASO DE NO CUMPLIR ALGUNA DE LAS CONDICIONES ANTERIORES
}

void dequeue(cola *l)   //FUNCIÓN pop PARA ELIMINAR EL ÚLTIMO NODO DE LA COLA, PARÁMETROS: VARIABLE APUNTADOR TIPO cola, APUNTADOR A LA COLA
{
    if(es_vaciaC(l)) return; //CONDICIÓN PARA RETORNAR EL CONTROL A LA FUNCIÓN QUE LA MANDO LLAMAR SI LA COLA ESTÁ VACÍA; NO ELIMINA
    nodo* temporal=l->head; //DECLARA Y CREA UN NODO TEMPORAL Y LO IGUALA A LA CABEZA DE LA COLA
    l->head=l->head->sig;   //IGUALA LA CABEZA AL APUNTADOR AL SIGUIENTE NODO DE LA CABEZA; RECORRE LA CABEZA AL SIGUIENTE NODO
    temporal->sig=NULL; //IGUALA EL APUNTADOR AL SIGUIENTE NODO DE TEMPORAL A NULO
    liberar_nodo(temporal);    //LLAMA A LA FUNCIÓN liberar_nodoC PARA LIBERAR MEMORIA DE TEMPORAL
    l->num--;   //DECREMENTA EL CONTADOR DE NODOS DE LA COLA EN UNO

}

INFO* colaC(cola *l)
{
    /*FUNCIÓN colaC PARA RETORNAR LA DIRECCIÓN DE MEMORIA DE LA INFORMACIÓN ÚLTIMO NODO DE LA COLA,
    PARÁMETROS: APUNTADOR TIPO cola; APUNTADOR A LA COLA*/

    if(es_vaciaC(l)) return NULL;   //CONDICIÓN PARA RETORNAR NULO SI LA COLA ESTÁ VACÍA
    else return &l->tail->info; //RETONA LA DIRECCIÓN DE LA INFORMACIÓN DEL NODO SUPERIOR DE LA COLA
}

bool es_vaciaC(cola *l) //FUNCIÓN es_vacia PARA DETERMINAR SI LA COLA ESTÁ VACÍA, PARÁMETROS: VARIABLE APUNTADOR TIPO cola; APUNTADOR A LA COLA
{
    if(l->head == NULL && l->tail == NULL) return true; /*CONDICÓN PARA DETERMINAR SI LA LISTA ESTÁ VACÍA,
    LOS APUTNADORES DE LA CABEZA Y COLA TIENEN QUE APUNTAR A NULO, RETORNA TRUE*/
    return false;   //RETORNA FALSE EN CASO DE QUE LA LISTA NO ESTÉ VACÍA
}

bool vaciarC(cola *l)
{
    /*FUNCIÓN vaciarC PARA VACIAR LA COLA,
    PARÁMETROS: VARIABLE APUNTADOR TIPO cola; APUNTADOR A LA COLA, ELIMINA DEL PRIMER AL ÚLTIMO NODO*/

    if(es_vaciaC(l)) return false;  //CONDICIÓN PARA RETORNAR FALSE EN CASO DE QUE LA LISTA ESTÉ VACÍA

    nodo *temporal=l->head; //DECLARA UN APUNTADOR TIPO nodo TEMPORAL Y LA IGUALA A LA CABEZA DE LA COLA
    while(temporal != NULL) //CICLO WHILE, SE REPITE HASTA QUE LA VARIABLE TEMPORAL SEA IGUAL A NULO
    {
        l->head=temporal->sig;  //IGUALA EL APUNTDO DE LA CABEZA AL APUNTADOR AL SIGUIENTE NODO DE TEMPORAL, RECORRE LA CABEZA AL SIGUIENTE NODO
        temporal->sig=NULL; //IGUALA EL APUTNADOR AL SIGUIENTE NODO DE TEMPORAL A NULO, CONDICIÓN PARA LIBERAR MEMORIA DEL NODO
        liberar_nodo(temporal); //LLAMA A LA FUNCIÓN liberar_nodo PARA LIBERAR LA MEMORIA DE TEMPORAL
        temporal=l->head;   //IGUALA TEMPORAL A LA CABEZA
    }
    l->head=l->tail=NULL;   //IGUALA LOS APUNTADORES DE CABEZA Y COLA A NULO
    l->num=0;   //IGUALA EL CONTADOR DE NODOS DE LA LISTA A CERO
    return true;    //RETORNA TRUE, LA COLA SE VACIÓ
}

void imprimir_cola(cola *l) //FUNCIÓN imprimir_cola PARA IMPRIMIR LA COLA, PARÁMTROS: VARIABLE APUNTADOR TIPO cola; APUNTADOR A LA COLA
{
    if(es_vaciaC(l))    //CONDICIÓN PARA EJECUTAR EL BLOQUE EN CASO DE QUE LA COLA ESTÉ VACÍA
    {
        printf("\nCOLA VACIA\n");    //MANDA UN MENSAJE AL USUARIO
        return; //TERMINA LA FUNCIÓN
    }
    if(l==NULL) //CODICIÓN PARA EJECUTAR EL BLOQUE EN CASO DE QUE LA PILA APUNTE A NULO, NO EXISTE LA PILA
    {
        printf("\nLA COLA NO EXISTE\n"); //MANDA UN MENSAJE AL USUARIO
        return; //TERMINA LA FUNCIÓN
    }

    nodo* t=NULL;   //DECLARA UNA VARIABLE APUNTADOR TIPO nodo Y LA IGUALA A NULO
    for(t=l->head; t != NULL; t=t->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
    {
        printf(" %c", t->info);    //IMPRIME LA INFORMACIÓN DEL NODO
    }
    printf("\n\n"); //IMPRIME UN SALTO DE LÍNEA
    return; //TERMINA LA FUNCIÓN

}

bool es_parentesis_izquierdo(char m)
{
    if(m == '(') 
        return true;
    return false;
}

bool es_operando(char t)
{
    if((t >= 'a' && t <='z') || (t >= 'A' && t <= 'Z'))
        return true;
    return false;
}

bool es_operador(char e)
{
    if((e =='+' ) || (e == '-') || (e == '*') || (e == '/') || (e == '%') || (e == '^'))
        return true;
    return false;
}

int prioridad_dentro_de_la_pila(char pf)
{
    if(pf=='(') return 0; //(
    else if(pf == '+') return 1; //+
    else if(pf== '-') return 1; //-
    else if(pf== '*') return 2; //*
    else if(pf== '/') return 2; // /
    else if(pf== '%') return 2; // %
    else if(pf== '^') return 3; // ^
    else {
        printf("VALOR NO VALIDO");
    }
}

int prioridad_fuera_de_la_pila(char pf)
{
    if(pf=='(') return 5; //(
    else if(pf=='+') return 1; //+
    else if(pf=='-') return 1; //-
    else if(pf=='*') return 2; //*
    else if(pf=='/') return 2; // /
    else if(pf=='%') return 2; // %
    else if(pf=='^') return 4; // ^
    else {
        printf("VALOR NO VALIDO");
    }
}

bool buscarInfo(cola* c, INFO ala)
{
    int i;
    nodo* t=NULL;   //DECLARA UNA VARIABLE APUNTADOR TIPO nodo Y LA IGUALA A NULO
    
    if(c->num==0) return false;
    for(t=c->head; t != NULL; t=t->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
    {
        if(t->info==ala ) return true;
    }
    return false;
    
}

void valoresXteclado(cola* c)
{
    nodo* t=NULL;
    nodo* t2=NULL;   //DECLARA UNA VARIABLE APUNTADOR TIPO nodo Y LA IGUALA A NULO
    float valorTeclado;
    /*for(t=c->head; t != NULL; t=t->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
    {
        if(t->info>=65 && t->info<=90 || t->info>=97 && t->info<=122)
        {
            printf("\n Dame valor de %c: ", t->info);
            scanf("%f", &valorTeclado);
            t->valor=valorTeclado;
        }
    }*/

    cola* variables=crear_cola();
    for(t=c->head; t != NULL; t=t->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
    {
        if(t->info>=65 && t->info<=90 && buscarInfo(variables, t->info)==false || t->info>=97 && t->info<=122 && buscarInfo(variables, t->info)==false)
        {
            enqueue(variables, t->info);
        }
    }

    for(t=variables->head; t != NULL; t=t->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
    {
        if(t->info>=65 && t->info<=90 || t->info>=97 && t->info<=122 )
        {
            printf("\n Dame valor de %c: ", t->info);
            scanf("%f", &valorTeclado);
            t->valor=valorTeclado;   
        }
    }

    for(t=c->head; t != NULL; t=t->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
    {
        if(t->info>=65 && t->info<=90 || t->info>=97 && t->info<=122)
        {
            for(t2=variables->head; t2 != NULL; t2=t2->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
            {
                if(t->info==t2->info)
                {
                    t->valor=t2->valor;
                }
            }
        }
    }//FIN FOR     
    vaciarC(variables);
    free(variables);
}

void evaluarExpresion(cola* c)
{
    pila* pilaa=crear_pila();
    nodo* t=NULL;   //DECLARA UNA VARIABLE APUNTADOR TIPO nodo Y LA IGUALA A NULO
    float abajo, arriba;
    int abajo2, arriba2;
    char caracter=144;
    for(t=c->head; t != NULL; t=t->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
    {
        if(t->info>=65 && t->info<=90 || t->info>=97 && t->info<=122)
        {
            push(pilaa, t->info);
            pilaa->head->valor=t->valor;


        }
        if(t->info==37 || t->info==42 || t->info==43 || t->info==45 || t->info==47 || t->info==94)
        {
            if(t->info==37) // %
            {
                arriba2=pilaa->head->valor;
                pop(pilaa);
                abajo2=pilaa->head->valor;
                pop(pilaa);
                arriba2=abajo2%arriba2;
                push(pilaa, caracter);
                pilaa->head->valor=arriba2;
            }
            else if (t->info==42) // *
            {
                arriba=pilaa->head->valor;
                pop(pilaa);
                abajo=pilaa->head->valor;
                pop(pilaa);
                arriba=abajo*arriba;
                push(pilaa, caracter);
                pilaa->head->valor=arriba;
            }
            else if (t->info==43)// +
            {
                arriba=pilaa->head->valor;
                pop(pilaa);
                abajo=pilaa->head->valor;
                pop(pilaa);
                arriba=abajo+arriba;
                push(pilaa, caracter);
                pilaa->head->valor=arriba;
            }
            else if (t->info==45)// -
            {
                arriba=pilaa->head->valor;
                pop(pilaa);
                abajo=pilaa->head->valor;
                pop(pilaa);
                arriba=abajo-arriba;
                push(pilaa, caracter);
                pilaa->head->valor=arriba;
            }
            else if (t->info==47)// /
            {
                arriba=pilaa->head->valor;
                pop(pilaa);
                abajo=pilaa->head->valor;
                pop(pilaa);
                arriba=abajo/arriba;
                push(pilaa, caracter);
                pilaa->head->valor=arriba;
            }
            else if (t->info==94)// ^
            {
                arriba=pilaa->tail->valor;
                pop(pilaa);
                abajo=pilaa->head->valor;
                pop(pilaa);
                arriba=pow(abajo,arriba);
                push(pilaa, caracter);
                pilaa->head->valor=arriba;
            }
            
        }
    }
    printf("Resultado: %.2f", pilaa->head->valor);
    pop(pilaa);
    free(pilaa);

}

void guardarNotacion(cola* c)
{
    FILE* pt;
    pt=fopen("NotPosfija.txt", "w+");

    nodo *t = NULL; //DECLARA UNA VARIABLE APUNTADOR TIPO nodo Y LA IGUALA A NULO
    for (t = c->head; t != NULL; t = t->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
    {
        fputc(t->info, pt);
    }
    fclose(pt);
    printf("GUARDADO");
}

void evaluarArchivo(cola* c)
{    
    int ab, i=0;
    float num;
    char caracter[2];
    char variables[50];
    float numeros[50];

    FILE *doc=fopen("entrada.txt", "r");

    while (feof(doc)==0)
    {
        fscanf(doc, "%s %f", &caracter, &num);
        variables[i]=caracter[0];
        numeros[i]=num;
        i++;
    }
    
    nodo* t=NULL;   //DECLARA UNA VARIABLE APUNTADOR TIPO nodo Y LA IGUALA A NULO
    for(t=c->head; t != NULL; t=t->sig) //CICLO FOR PARA RECORRER CADA NODO DE INICIO A FIN
    {
        for(ab=0; ab < c->num; ab++)
        {
            if(t->info== variables[ab])
                t->valor=numeros[ab];
        }
    }
    evaluarExpresion(c);
    
}
//
//  Prioridades:
//  Dentro |^ sqrt = 3|  |*/% = 2|   |+- = 1|    |( = 0|
//  Fuera  |^ sqrt = 4|  |*/% = 2|   |+- = 1|    |( = 5|
//