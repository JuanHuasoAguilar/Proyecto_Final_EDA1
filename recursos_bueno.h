#ifndef recursos_buenos_h
#define  recursos_buenos_h

#include <stdbool.h>

typedef char INFO;   //ALIAS DE LA INFORMACIÓN DEL NODO
typedef struct _nodo nodo;  //ALIAS DE LA ESTRUCTURA DEL NODO

struct _nodo{   //ESTRUCTURA DEL NODO
    INFO info;  //INFORMACIÓN DEL NODO
    nodo *sig;  //APUNTADOR/ENLACE AL NODO SIGUIENTE
    float valor;
};

typedef struct _cola cola;  //ALIAS DE LA ESTRUCTURA DE LA COLA
struct _cola{   //ESTRUCTURA DE LA COLA
    nodo* head; //APUNTADOR/ENLACE A LA CABEZA DE LA COLA
    nodo* tail; //APUNTADOR/ENLACE A LA COLA DE LA COLA
    int num;    //CONTADOR DE NODOS EN AL COLA
};

//PILA

typedef struct _pila pila;  //ALIAS DE LA ESTRUCTURA DE LA PILA
struct _pila{   //ESTRUCTURA DE LA PILA
    nodo* head; //APUNTADOR/ENLACE A LA CABEZA DE LA PILA
    nodo* tail; //APUNTADOR/ENLACE A LA COLA DE LA PILA
    int num;    //CONTADOR DE NODOS EN AL PILA
};

nodo* crear_nodo(INFO info);    //PROTOTIPO DE LA FUNCIÓN PARA CREAR UN NODO; RETORNA UN APUNTADOR TIPO nodo
void liberar_nodo(nodo *n); //PROTOTIPO DE LA FUNCIÓN PARA LIBERAR MEMORIA PARA UN NODO
pila* crear_pila(); //PROTOTIPO DE LA FUNCIÓN PARA CREAR LA PILA; RETORNA UN APUNTADOR TIPO pila
void liberar_lista(pila *l);    //PROTOTIPO DE LA FUNCIÓN PARA LIBERAR MEMORIA DE LA PILA


bool push(pila *l, INFO info);  //PROTOTIPO DE LA FUNCIÓN PARA APILAR UN NODO; RETORNA true O false
void pop(pila *l);  //PROTOTIPO DE LA FUNCIÓN PARA DESAPILAR UN NODO
INFO* cabezaP(pila *l); //PROTOTIPO DE LA FUNCIÓN PARA RETORNAR EL NODO SUPERIOR DE LA PILA; RETORNA UN APUNTADOR TIPO INFO

bool es_vacia(pila *l); //PROTOTIPO DE LA FUNCIÓN PARA DETERMINAR SI LA PILA ESTÁ VACÍA; RETORNA true O false
bool vaciar(pila *l);   //PROTOTIPO DE LA FUNCIÓN PARA VACIAR LA PILA; RETORNA true O false

void imprimir_pila(pila *l);    //PROTOTIPO DE LA FUNCIÓN PARA IMPRIMIR LA PILA


//COLA
nodo* crear_nodoC(INFO info);   //PROTOTIPO DE LA FUNCIÓN PARA CREAR UN NODO; RETORNA UN APUNTADOR TIPO nodo
void liberar_nodoC(nodo *n);    //PROTOTIPO DE LA FUNCIÓN PARA LIBERAR MEMORIA PARA UN NODO
cola* crear_cola(); //PROTOTIPO DE LA FUNCIÓN PARA CREAR LA COLA; RETORNA UN APUNTADOR TIPO cola
void liberar_cola(cola *l); //PROTOTIPO DE LA FUNCIÓN PARA LIBERAR MEMORIA DE LA COLA

bool enqueue(cola *l, INFO info);   //PROTOTIPO DE LA FUNCIÓN PARA ENCOLAR UN NODO; RETORNA true O false
void dequeue(cola *l);  //PROTOTIPO DE LA FUNCIÓN PARA DESENCOLAR UN NODO
INFO* colaC(cola *l);   //PROTOTIPO DE LA FUNCIÓN PARA RETORNAR EL ÚLTIMO NODO DE LA COLA; RETORNA UN APUNTADOR TIPO INFO

bool es_vaciaC(cola *l);    //PROTOTIPO DE LA FUNCIÓN PARA DETERMINAR SI LA COLA ESTÁ VACÍA; RETORNA true O false
bool vaciarC(cola *l);  //PROTOTIPO DE LA FUNCIÓN PARA VACIAR LA COLA; RETORNA true O false

void imprimir_cola(cola *l);    //PROTOTIPO DE LA FUNCIÓN PARA IMPRIMIR LA PILA

bool es_parentesis_izquierdo(char m);
bool es_operando(char t);
bool es_operador(char e);
int prioridad_dentro_de_la_pila(char pd);
int prioridad_fuera_de_la_pila(char pf);

void valoresXteclado(cola* c);
void evaluarExpresion(cola* c);

void guardarNotacion(cola* c);
void evaluarArchivo(cola* c);

bool buscarInfo(cola* c, INFO ala);

#endif