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
	char localidad[LONGITUD_LOCALIDAD];
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


/// @brief Permite cargar un nuevo cliente en el vector de clientes
///
/// @param listaClientes eCliente - vector de clientes
/// @param longitud int - la longitud del vector de clientes
/// @param idNueva int* - puntero a variable que almacena la nueva Id de clientes generada automaticamente
/// @return (1) [se cargo el cliente correctamente] - (0) [no se pudo cargar, porque el vector esta lleno y apunta a NULL]
int AltaDeCliente(eCliente listaClientes[], int longitud, int* idNueva);


/// @brief Dado un cliente imprime en pantalla los datos del mismo.
/// 		Tener en cuenta que no termina en un salto de linea.
///
/// @param cliente eCliente - el cliente a mostrar
void MostrarCliente(eCliente cliente);


/// @brief Muestra encolumnado de todos los clientes cargados
///
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @return int (1)[existe al menos un cliente] - (0)[el vector esta vacio o apunta NULL]
int MostrarListaClientes(eCliente listaClientes[], int longitud);


/// @brief Permite modificar los datos localidad o direccion de un cliente y retorna el indece del cliente modificado
///
/// @param listaClientes eCliente - vector de clientes
/// @param longitud int - la longitud del vector de clientes
/// @return int [si se modifico un cliente, el indice en el vector] - (-2) [El vector esta vacio o apunta a NULL] - (-1) [El usuario cancelo la modificacion de un cliente]
int ModificarDatosCliente(eCliente listaClientes[], int longitud);


/// @brief Dada un Id por parametro devuelve el indice dentro del vector que posee dicha idCliente
///
/// @param listaClientes eCliente - vector de clientes
/// @param longitud int - la longitud del vector de clientes
/// @param idBuscada int - el idCliente a buscar
/// @return int [si encontro un cliente, el indice del mismo en el vector] - (-1)[No encontro el cliente o la vector apunta a NULL]
int BuscarClientePorId(eCliente listaClientes[], int longitud, int idBuscada);


/// @brief Dado un vector eCliente y el indice dentro del mismo, permite modificar los datos localidad o dirección
///
/// @param listaClientes eCliente - vector de clientes
/// @param indexCliente int - indice en el vector del cliente a modificar
/// @return int - [el indice del cliente que se modifico] - (-1)[si el usuario decide no modificar un cliente o si el parametro indexCliente es menor a 0]
int ModificarClienteEnIndice(eCliente listaClientes[], int indexCliente);


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
