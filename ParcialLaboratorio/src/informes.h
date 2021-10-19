/*
 * informes.h
 *
 *  Created on: 19 oct. 2021
 *      Author: juanm
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "pedido.h"
#include "cliente.h"


/// @brief Muestra encolumnado todos los pedidos pendientes, la direccion del cliente y su CUIT
///
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @return int (1)[existe al menos un pedido pendiente] - (0)[el vector esta vacio o apunta a NULL]
int MostrarListaDePedidosPendientes(ePedido listaPedidos[], int longitudPedidos, eCliente listaClientes[], int longitudClientes);


/// @brief Muestra encolumnado todos los pedidos procesados, la direccion del cliente y su CUIT
///
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @return int (1)[existe al menos un pedido procesado] - (0)[el vector esta vacio o apunta a NULL]
int MostrarListaDePedidosProcesados(ePedido listaPedidos[], int longitudPedidos, eCliente listaClientes[], int longitudClientes);


/// @brief Muestra encolumnado de todos los clientes cargados junto con la cantidad de pedidos pendientes que poseen
///
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @return int (1)[existe al menos un cliente] - (0)[el vector esta vacio o apunta NULL]
int MostrarListaClientesYCantidadPedidosPendientes(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos);


/// @brief Muestra en pantalla el promedio de kilos de polipropileno reciclados por cliente
///
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @return int (1)[existe al menos un cliente] - (0)[el vector esta vacio o apunta NULL]
int MostrarPromedioKilosPolipropilenoProcesadoPorCliente(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos);


/// @brief Muestra la cantidad de pedidos pendientes hay en una localidad que ingrese el usuario
///
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @return int (1)[existe al menos un cliente] - (0)[el vector esta vacio o apunta NULL]
int MostrarCantidadPedidosPendientesEnUnaLocalidad(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos);


/// @brief
///
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @return float (-1)[vector de clientes vacio o apunta a NULL] - [el promedio de kilos de polipropileno reciclado por cliente]
float CalcularPromedioKilosPolipropilenoProcesadoPorCliente(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos);

/// @brief Dada una locildad cuenta cuantos pedidos en estado PENDIENTE hay en la misma
///
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @param localidad char - la localidad a la cual se desea contar los pedidos pendientes
/// @return [la cantidad de pedidos pendientes en dicha localidad]
int ContarCantidadDePedidosPendientesEnLocalidad(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos, char localidad[]);


#endif /* INFORMES_H_ */
