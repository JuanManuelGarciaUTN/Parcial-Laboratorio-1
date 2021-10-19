/*
 * nexoEstructuras.h
 *
 *  Created on: 17 oct. 2021
 *      Author: juanm
 */

#ifndef NEXOESTRUCTURAS_H_
#define NEXOESTRUCTURAS_H_

#include "cliente.h"
#include "pedido.h"
#include "informes.h"


/// @brief Genera un nuevo pedido de recoleccion en el primer espacio libre del vector de ePedidos como PENDIENTE
/// 		y permite ingresar los datos del mismo
///
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @param idNueva int* - puntero a variable que almacena la nueva id de pedido
/// @return int (-2)[el vector de cliente esta vacio] - (-1)[el vector de pedidos esta lleno] - (0)[el usuario cancelo la carga del pedido] - (1)[se cargo el pedido correctamente]
int AltaDePedidoRecoleccion(ePedido listaPedidos[], int longitudPedidos, eCliente listaClientes[], int longitudClientes, int* idNueva);


/// @brief Procesa un pedido de recoleccion de residuos como COMPLETADO
/// 		y permite ingresar los kilos que fueron reciclados en el mismo
///
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @return int [el indice del pedido procesado dentro del vector] - (-1)[No hay pedidos con estado PENDIENTE o vector apunta a NULL]
int ProcesarPedidoDeRecoleccion(ePedido listaPedidos[], int longitudPedidos, eCliente listaClientes[], int longitudClientes);


/// @brief Da de baja un cliente elejido por el usuario y todos los pedidos asociados a dicho cliente
///
/// @param listaClientes eCliente - el vector de eCliente que contiene todos los clientes
/// @param longitudClientes int - la longitud del vector de eCliente
/// @param listaPedidos ePedido - el vector de ePedido que contiene todos los pedidos
/// @param longitudPedidos int - la longitud del vector de ePedido
/// @return int (-2)[el vector de cliente esta vacio] - (-1)[el usuario decidio no dar de baja el cliente] - [el indice en el vector del cliente que se dio de baja]
int DarDeBajaCliente(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos);


#endif /* NEXOESTRUCTURAS_H_ */
