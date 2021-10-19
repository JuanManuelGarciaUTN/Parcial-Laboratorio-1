/*
 * eGenerico.h
 *
 *  Created on: 19 oct. 2021
 *      Author: juanm
 */

#ifndef EGENERICO_H_
#define EGENERICO_H_

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

#define VACIO 0
#define CARGADO 1

typedef struct{

	int idGenerico;
	int estado;
}eGenerico;


/// @brief Inicializa todas las posiciones del vector Generico en VACIO
///
/// @param listaGenerico eGenerico - vector de Generico
/// @param longitud int - longitud del vector
void InicializarGenerico(eGenerico listaGenerico[], int longitud);


/// @brief Permite cargar un nuevo eGenerico en el vector de Generico
///
/// @param listaGenerico eGenerico - vector de Generico
/// @param longitud int - longitud del vector
/// @param idNueva int* - puntero a la nueva Id de Generico
/// @return int (1)[se cargo correctamente] - (0)[hubo un error]
int AltaGenerico(eGenerico listaGenerico[], int longitud, int* idNueva);


/// @brief Dada un idGenerico busca en el vector y si la encuentra devuelve su indice en el mismo
///
/// @param listaGenerico eGenerico - vector de Generico
/// @param longitud int - longitud del vector
/// @param idBuscada int - el idGenerico a buscar
/// @return int [indice en el vector que posee dicha id] - (-1)[no encontro el Id o vector apunta a NULL]
int BuscarGenericoPorId(eGenerico listaGenerico[],int longitud, int idBuscada);


/// @brief Da de baja el Generico en el indice dado por parametro
///
/// @param listaGenerico eGenerico - vector de Generico
/// @param indexBaja int - indice del Generico a dar de baja
/// @return int [indice del Generico dado de baja] - (-1)[el usuario decidio no dar de baja Generico o si indexCliente es menor a 0]
int BajaDeGenericoEnIndice(eGenerico listaGenerico[],int indexBaja);


/// @brief Dado un eGenerico lo muestra en pantalla
///
/// @param Generico eGenerico - Generico a mostrar
void MostrarGenerico(eGenerico Generico);


/// @brief Muestra todos los Genericos con estado CARGADO
///
/// @param listaGenerico eGenerico - vector de Generico
/// @param longitud int - longitud del vector
/// @return int (1)[existe al menos un Generico] - (0)[No existe ningun Generico o vector apunta a NULL]
int MostrarListaGenerico(eGenerico listaGenerico[],int longitud);


/// @brief Dado un indice en vector de eGenerico permite modificar los datos del Generico
///
/// @param listaGenerico eGenerico - vector de Generico
/// @param indexModificar int - indice del Generico a modificar
/// @return int [indice del Generico modificado] - (-1)[el usuario decidio no modificar Generico o indexModificar es menor a 0]
int ModificarGenericoEnIndice(eGenerico listaGenerico[],int indexModificar);


#endif /* EGENERICO_H_ */
