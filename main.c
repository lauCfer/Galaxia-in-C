//
//  main.c
//  practica labo2 2do parcial
//
//  Created by Laura Fernandez on 11/22/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nombrePlaneta [20];
    char estrella [20];
    int cantidadSatelites;
    float masa; ///(se mide en relaciÛn a la Tierra, por ejemplo Neptuno es 17,14 Tierras)
    int tempMax;
    int tempMin;
}Planeta;

typedef struct
{
     Planeta planeta;
struct nodoArbolPlaneta* izq;
struct nodoArbolPlaneta* der;
}nodoArbolPlaneta;

typedef struct
{
    char nombreGalaxia [20];
    char tipoGalaxia [20]; ///elÌptica, lenticular, espiral, irregular, etc
    char descubiertoPor [20];
    
}galaxia;

typedef struct
{
    galaxia gal;

    nodoArbolPlaneta * planetas;
}celdaGalaxia;

//1
nodoArbolPlaneta* iniciar_arbol();
nodoArbolPlaneta*crear_arbol(Planeta data);
nodoArbolPlaneta* insertar_nuevo(nodoArbolPlaneta* lista, nodoArbolPlaneta*nuevo);
Planeta cargaModularizada_();
void mostraModu(Planeta data);
void inOrden(nodoArbolPlaneta*lista);
//2
int buscarGalaxia(celdaGalaxia celda[], char buscarg[], int validos);
galaxia cargaGalaxia(char buscarg[]);
int alta(celdaGalaxia celda[],int validos);
int agregarCelda(celdaGalaxia celda[], char buscarg[], int validos);


//3

//5
void mostrarGalaxy(galaxia gal);
void mostrarTodo(celdaGalaxia celda[], int validos);
void mostrarGalaxy(galaxia gal);

int main()
{
    celdaGalaxia celda[1];
    int validos=0;
    validos=alta(celda, 1);
    mostrarTodo(celda, 1);
   
    
   
}

//1. Realizar las funciones necesarias para trabajar con arbol: iniciar crear, insertar, mostrar in orden




nodoArbolPlaneta* iniciar_arbol()
{
    return NULL;
}

nodoArbolPlaneta*crear_arbol(Planeta data)
{
    nodoArbolPlaneta*nuevo=(nodoArbolPlaneta*)malloc(sizeof(nodoArbolPlaneta));
    nuevo->planeta=data;
    nuevo->der=NULL;
    nuevo->izq=NULL;
    return nuevo;
}

nodoArbolPlaneta* insertar_nuevo(nodoArbolPlaneta* lista, nodoArbolPlaneta*nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }else
    {
        if(nuevo->planeta.masa>lista->planeta.masa)
        {
            lista->der=insertar_nuevo(lista->der, nuevo);
        }else
        {
            lista->izq=insertar_nuevo(lista->izq, nuevo);
        }
    }
    return lista;
}
void mostraModu(Planeta data)
{

    printf("\nNombre planeta: %s",data.nombrePlaneta);
    printf("\nEstrella: %s",data.estrella);
    printf("\nCantidad de satelites: %i",data.cantidadSatelites);
    printf("\nMasa: %f",data.masa);
    printf("\nTemperatura maxima: %i",data.tempMax);
    printf("\nTemperatura minima: %i",data.tempMin);
    
}

void inOrden(nodoArbolPlaneta*lista)
{
    if(lista!=NULL)
    {
        inOrden(lista->izq);
        mostraModu(lista->planeta);
        inOrden(lista->der);
    }
}
Planeta cargaModularizada_()
{
    Planeta data;
    
    
    printf("\nIngrese nombre del planeta: ");
    fflush(stdin);
    gets(data.nombrePlaneta);
    
    printf("\nestrellas: ");
    fflush(stdin);
    gets(data.estrella);
    
    printf("\nCantida de satelites: ");
    fflush(stdin);
    scanf("%i",&data.cantidadSatelites);
    
    printf("\nMasa: ");
    fflush(stdin);
    scanf("%f",&data.masa);
    
    printf("\nTemperatura minima: ");
    fflush(stdin);
    scanf("%i",&data.tempMin);
    
    
    printf("\nTemperatura maxima: ");
    fflush(stdin);
    scanf("%i",&data.tempMax);
    
    return data;
}
//2.Generar una funcion que nos permita agregar elementos al arreglo de galaxias correspondiente y solicitar datos del planeta. el progrmama debe buscar la celda correspondiente y solicitar los datos del plante. en caso de que la galaxia no exista, debe solictarle los datos de la galaxia para agregarla al arreglo, antes de pedirle los datos del plantea. MODULARIZAR
int alta(celdaGalaxia celda[], int validos)
{
    char letra='s';
    char buscarg[20];
  
   
    while (letra=='s')
    {
        printf("\nIngrese galaxia: ");
        fflush(stdin);
        scanf("%s",&buscarg);
       int pos=buscarGalaxia(celda, buscarg, validos);
        if(pos==-1)
        {
            validos=agregarCelda(celda, buscarg, validos);
            pos=validos-1;
        }
        nodoArbolPlaneta* nuevo= crear_arbol(cargaModularizada_());
        celda[pos].planetas=insertar_nuevo(celda[pos].planetas, nuevo);
        printf("\nDesea agregar mas datos a su arreglo?  ");
        fflush(stdin);
        scanf("%c",&letra);
    }
    
    return validos;
}
 int buscarGalaxia(celdaGalaxia celda[], char buscarg[], int validos)
{
     int pos=-1;
     int i=0;
     while(i<validos && pos==-1)
     {
         if(strcmp(celda[i].gal.nombreGalaxia, buscarg)==0)
         {
             pos=i;
         }
         i++;
     }
     return pos;
 }

int agregarCelda(celdaGalaxia celda[], char buscarg[], int validos)
{
    celda[validos].planetas=iniciar_arbol();
    celda[validos].gal=cargaGalaxia(buscarg);
    validos++;
    return validos;
}


galaxia cargaGalaxia(char buscarg[])
{
    galaxia dato;
 
    printf("\nGalaxia agregada con exito!");
    
    strcpy(dato.nombreGalaxia,buscarg);
    
    printf("\nTipo de galaxia: ");
    fflush(stdin);
    gets(dato.tipoGalaxia);
    
    printf("\nDescubierta por: ");
    fflush(stdin);
    gets(dato.descubiertoPor);
    
    return dato;
    
    
    
}





//3 Disenar una funcion que me permita contar la cantidad total de planteas que hay entre TODAS las galaxias, con mas de una luna

void mostrarTodo(celdaGalaxia celda[], int validos)
{
    int i=0;
    while(i<validos)
    {
        mostrarGalaxy(celda[i].gal);
        printf("\nPlanetas en la galaxia: %s",celda[i].gal.nombreGalaxia);
        inOrden(celda[i].planetas);
        i++;
    }
    
}
void mostrarGalaxy(galaxia gal)
{
    printf("\nNombre: %s",gal.nombreGalaxia);
    printf("\nNTipo: %s",gal.tipoGalaxia);
    printf("\nDescubierta por: %s",gal.descubiertoPor);
    
}


