/*
 * pedido.h
 *
 *  Created on: 17 oct. 2021
 *      Author: juanm
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

#define SIN_CARCAR -1
#define PENDIENTE 0
#define COMPLETADO 1

typedef struct{
	int idPedido;
	int idCliente;
	float kilosARecolectar;
	float kilosProcesadosHdpe;
	float kilosProcesadosLdpe;
	float kilosProcesadosPp;
	int estado;
}ePedido;


/// @brief Inicializa todas los posiciones del vector de ePedidos en estado = SIN_CARGAR
///
/// @param listaPedidos ePedido - el vector de pedidos
/// @param longitud int - la longitud del vector
void InicializarVacioPedidos(ePedido listaPedidos[], int longitud);


/// @brief Inicializa el vector de pedidos con datos y estado = PENDIENTE para testear el ABM
///
/// @param listaPedidos ePedido - el vector de pedidos
/// @param longitud int - la longitud del vector
/// @param idNueva int* - puntero a variable que almacena la nueva Id de pedido
void InicializarTestingPedidos(ePedido listaPedidos[], int longitud, int* idNueva);


/// @brief Dado un id busca dentro del vector que pedido tiene la misma id y retorna el indice del mismo
///
/// @param listaPedidos ePedido - el vector de pedidos
/// @param longitud int - la longitud del vector
/// @param id int - id a buscar
/// @return int - [si encontro un pedido con dicha id, retorna el indice] - (-1)[no encontro pedido con dicha id o vector apunta a NULL]
int BuscarPedidoPorId(ePedido listaPedidos[], int longitud, int id);


/// @brief Permite procesar el pedido en el indice dado. Permitiendo ingresar cuantos kilos de cada
/// 		plastico se reciclaron tras la recoleccion
///
/// @param listaPedidos ePedido - el vector de pedidos
/// @param indexPedido int - indice dentro del vector del pedido a procesar
/// @return int - [si se proceso el pedido, el indice del pedido en el vector] - (-1)[indexPedido es menor a 0]
int ProcesarPedidoEnIndice(ePedido listaPedidos[], int indexPedido);


/// @brief Dado un idCliente cuenta cuantos pedidos pendientes son de dicho cliente
///
/// @param listaPedidos ePedido - el vector de pedidos
/// @param longitud int - la longitud del vector
/// @param idCliente int - el id del cliente al cual se desea saber cuantos pedidos pendientes posee
/// @return int - [la cantidad de pedidos asociados a dicha id]
int ContarCantidadPedidosPendientesPorIdCliente(ePedido listaPedidos[], int longitud, int idCliente);


/// @brief Dada un idCliente da de baja todos los pedidos que poseen dicha idCliente
///
/// @param listaPedidos ePedido - el vector de pedidos
/// @param longitud int - la longitud del vector
/// @param idCliente int - el id del cliente al cual se daran de baja todos sus pedidos
/// @return int - (0)[no se dio de baja ningun pedido] - (1)[se dio de baja al menos un pedido]
int DarDeBajaPedidoPorIdCliente(ePedido listaPedidos[], int longitud, int idCliente);


/// @brief Cuenta cuantos kilos de polipropileno fueron reciclados en los pedidos completados
///
/// @param listaPedidos ePedido - el vector de pedidos
/// @param longitud int - la longitud del vector
/// @return float - [la cantidad de kilos de polipropileno que fueron reciclados]
float ContarCantidadProcesadaPolipropileno(ePedido listaPedidos[], int longitud);

#endif /* PEDIDO_H_ */
