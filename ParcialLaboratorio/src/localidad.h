
/*
 * eLocalidad.h
 *
 *  Created on: 19 oct. 2021
 *      Author: juanm
 */

#ifndef eLocalidad_H_
#define eLocalidad_H_

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

#define VACIO 0
#define CARGADO 1

#define LONGITUD_NOMBRE_LOCALIDAD 20

typedef struct{

	int idLocalidad;
	char nombre[LONGITUD_NOMBRE_LOCALIDAD];
	int estado;
}eLocalidad;


/// @brief Inicializa todas las posiciones del vector Localidad en VACIO
///
/// @param listaLocalidad eLocalidad - vector de Localidad
/// @param longitud int - longitud del vector
void InicializarVacioLocalidad(eLocalidad listaLocalidades[], int longitud);

void InicializarTestingLocalidad(eLocalidad listaLocalidades[], int longitud, int* idNueva);


/// @brief Permite cargar un nuevo eLocalidad en el vector de Localidad
///
/// @param listaLocalidad eLocalidad - vector de Localidad
/// @param longitud int - longitud del vector
/// @param idNueva int* - puntero a la nueva Id de Localidad
/// @return int (1)[se cargo correctamente] - (0)[hubo un error]
int AltaLocalidad(eLocalidad listaLocalidades[], int longitud, int* idNueva);

int BajaLocalidad( eLocalidad listaLocalidades[], int longitudLocalidades);


/// @brief Dada un idLocalidad busca en el vector y si la encuentra devuelve su indice en el mismo
///
/// @param listaLocalidad eLocalidad - vector de Localidad
/// @param longitud int - longitud del vector
/// @param idBuscada int - el idLocalidad a buscar
/// @return int [indice en el vector que posee dicha id] - (-1)[no encontro el Id o vector apunta a NULL]
int BuscarLocalidadPorId(eLocalidad listaLocalidades[],int longitud, int idBuscada);


/// @brief Da de baja el Localidad en el indice dado por parametro
///
/// @param listaLocalidad eLocalidad - vector de Localidad
/// @param indexBaja int - indice del Localidad a dar de baja
/// @return int [indice del Localidad dado de baja] - (-1)[el usuario decidio no dar de baja Localidad o si indexCliente es menor a 0]
int BajaDeLocalidadEnIndice(eLocalidad listaLocalidades[],int indexBaja);


/// @brief Dado un eLocalidad lo muestra en pantalla
///
/// @param Localidad eLocalidad - Localidad a mostrar
void MostrarLocalidad(eLocalidad Localidad);


/// @brief Muestra todos los Localidads con estado CARGADO
///
/// @param listaLocalidad eLocalidad - vector de Localidad
/// @param longitud int - longitud del vector
/// @return int (1)[existe al menos un Localidad] - (0)[No existe ningun Localidad o vector apunta a NULL]
int MostrarListaLocalidades(eLocalidad listaLocalidades[],int longitud);


/// @brief Dado un indice en vector de eLocalidad permite modificar los datos del Localidad
///
/// @param listaLocalidad eLocalidad - vector de Localidad
/// @param indexModificar int - indice del Localidad a modificar
/// @return int [indice del Localidad modificado] - (-1)[el usuario decidio no modificar Localidad o indexModificar es menor a 0]
int ModificarLocalidadEnIndice(eLocalidad listaLocalidades[],int indexModificar);


#endif /* LOCALIDAD_H_ */
