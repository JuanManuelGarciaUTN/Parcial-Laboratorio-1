/*
 * cliente.h
 *
 *  Created on: 17 oct. 2021
 *      Author: juanm
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"

#define LONGITUD_NOMBRE 51
#define LONGITUD_DIRECCION 20
#define LONGITUD_LOCALIDAD 20
#define LONGITUD_CUIT 13
#define CARGADO 1
#define VACIO 0

typedef struct{

	int idCliente;
	char nombre[LONGITUD_NOMBRE];
	char cuit[LONGITUD_CUIT];
	char direccion[LONGITUD_DIRECCION];
	int idLocalidad;
	int estado;
}eCliente;

/// @brief Inicializa el vertor de clientes en todas sus posiciones con estado = VACIO
///
/// @param listaClientes eCliente - vector de clientes
/// @param longitud int - la longitud del vector de clientes
void InicializarVacioClientes(eCliente listaClientes[], int longitud);


/// @brief Inicializacion del vector de clientes para testeo del ABM
/// 		Inicializa los parametros con datos y  estado = CARGADO
///
/// @param listaClientes eCliente - vector de clientes
/// @param longitud int - la longitud del vector de clientes
/// @param idNueva int* - puntero a variable que almacena la nueva Id de clientes generada automaticamente
void InicializarTestingClientes(eCliente listaClientes[], int longitud, int* idNueva);



/// @brief Dada un Id por parametro devuelve el indice dentro del vector que posee dicha idCliente
///
/// @param listaClientes eCliente - vector de clientes
/// @param longitud int - la longitud del vector de clientes
/// @param idBuscada int - el idCliente a buscar
/// @return int [si encontro un cliente, el indice del mismo en el vector] - (-1)[No encontro el cliente o la vector apunta a NULL]
int BuscarClientePorId(eCliente listaClientes[], int longitud, int idBuscada);


/// @brief Dado un vector eCliente y un indice, da de baja dicho cliente cambiando su estado a VACIO
///
/// @param listaClientes eCliente - vector de clientes
/// @param indexCliente int - indice en el vector del cliente a dar de baja
/// @return int - [el indice del cliente que se dio de baja] - (-1)[si el usuario decide no dar de baja al cliente o si el parametro indexCliente es menor a 0]
int BajaClienteEnIndice(eCliente listaClientes[], int indexCliente);

/// @brief Cuenta cuantos clientes dentro del vector tienen estado CARGADO
///
/// @param listaClientes eCliente - vector de clientes
/// @param longitud int - la longitud del vector de clientes
/// @return int - [cantidad de clientes con estado CARGADO]
int ContarCantidadClientes(eCliente listaClientes[], int longitud);


#endif /* CLIENTE_H_ */
