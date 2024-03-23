#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
  List* lista = create_list();
  
  for(int i = 1; i <= 10; i++)
  {
    int *num = (int*)malloc(sizeof(int));
    *num = i;
    push(lista, num);
  } 

  return lista;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  int suma = 0;
  int *dato;
  dato = (int*)first(L);
  
  while(dato != NULL)
  {
    suma += *dato;
    dato = (int*)next(L);
  }
  
  return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
  int *num;
  num = (int*)first(L);
  
  while(num != NULL)
    {
      if (*num == elem)
      {
        popCurrent(L);
      }
      num = (int*)next(L);
    }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
  Stack* pila = create_stack();

  while (P1 != NULL)
  {
    int *num = (int*)pop(P1);
    push(pila, num);
  }
  while (pila != NULL)
  {
    int *num = (int*)pop(pila);
    push(P2, num);
  }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int juntos(char primero, char segundo)
{
  if ((primero == '(' && segundo == ')') ||(primero == '[' && segundo == ']') ||(primero == '{' && segundo == '}'))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int parentesisBalanceados(char *cadena) 
{
  Stack* pila = create_stack();
  char *elem = cadena;

  while (*elem != '\0')
  {
    if (*elem == '(' || *elem == '[' || *elem == '{')
    {
      char *num = (char*)malloc(sizeof(char));
      *num = *elem;
      push(pila, num);
    }
    else if (*elem == ')' || *elem == ']' || *elem == '}')
    {
      if (top(pila) == 0 || !juntos(*(char*) top(pila), *elem))
      {
        while (top(pila) != 0)
        {
          free(pop(pila));
        }
        free(pila);
        return 0;
      }
      else
      {
        free(pop(pila));
      }
    }
    elem++;
  }

  int dato = (top(pila) == 0);
  while (top(pila) != 0)
  {
    free(pop(pila));
  }
  free(pila);
  return dato;
}

