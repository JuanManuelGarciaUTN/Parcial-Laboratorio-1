/*
 * nexoEstructuras.c
 *
 *  Created on: 17 oct. 2021
 *      Author: juanm
 */


#include "nexoEstructuras.h"

int AltaDePedidoRecoleccion(ePedido listaPedidos[], int longitudPedidos, eCliente listaClientes[], int longitudClientes, int* idNueva)
{
	int seCargoPedido;
	int idCliente;
	int indexCliente;
	int respuesta;

	seCargoPedido = -1;

	if(listaPedidos != NULL && longitudPedidos > 0)
	{
		for(int i=0; i<longitudPedidos; i++)
		{
			if(listaPedidos[i].estado == SIN_CARCAR)
			{
				respuesta = MostrarListaClientes(listaClientes, longitudClientes);
				if(respuesta == TRUE)
				{
					seCargoPedido = 0;
					while(1)
					{
						PedirEnteroMayorQue("Ingrese el ID del cliente del pedido: ", "ERROR. Debe ingresar un numero entero positivo \n", &idCliente, 0);
						indexCliente = BuscarClientePorId(listaClientes, longitudClientes, idCliente);
						if(indexCliente != -1)
						{
							listaPedidos[i].idPedido = *idNueva;
							*idNueva += 1;

							listaPedidos[i].idCliente = idCliente;

							PedirFloatMayorQue("Ingrese la cantidad de kilos que se recolectaran del cliente: ", "ERROR. Debe ingresar un numero positovo \n", &listaPedidos[i].kilosARecolectar, 0);
							listaPedidos[i].estado = PENDIENTE;

							seCargoPedido = 1;
							break;
						}
						printf("Cliente Ingresado Inexistente, ¿Desea volver a intentarlo? \n"
								"	1 -> SI\n"
								"	2 -> NO, volver a Menu Principal\n");
						PedirEnteroValidado("Ingrese respuesta: ", "ERROR. valor invalido \n", &respuesta, 1, 2);
						if(respuesta == 2)
						{
							break;
						}
					}
				}
				else
				{
					seCargoPedido = -2;
				}
				break;
			}
		}
	}

	return seCargoPedido;
}


int ProcesarPedidoDeRecoleccion(ePedido listaPedidos[], int longitudPedidos, eCliente listaClientes[], int longitudClientes)
{
	int seProcesoElPedido;
	int idPedidoProcesar;
	int indexPedido;
	int respuesta;

	seProcesoElPedido = -1;

	if(listaPedidos != NULL && longitudPedidos > 0 && listaClientes != NULL && longitudClientes > 0)
	{
		if(MostrarListaDePedidosPendientes(listaPedidos, longitudPedidos, listaClientes, longitudClientes))
		{
			while(1)
			{
				PedirEnteroMayorQue("Ingrese el ID del pedido a Procesar: ", "ERROR. Debe ingresar un numero entero positivo \n", &idPedidoProcesar, 0);
				indexPedido = BuscarPedidoPorId(listaPedidos, longitudPedidos, idPedidoProcesar);
				if(indexPedido == -1 || listaPedidos[indexPedido].estado != PENDIENTE)
				{
					printf("ID de Pedido Ingresado Inexistente, ¿Desea volver a intentarlo? \n"
							"	1 -> SI\n"
							"	2 -> NO, volver a Menu Principal\n");
					PedirEnteroValidado("Ingrese respuesta: ", "ERROR. valor invalido \n", &respuesta, 1, 2);
					if(respuesta == 1)
					{
						continue;
					}
				}
				break;
			}
			seProcesoElPedido = ProcesarPedidoEnIndice(listaPedidos, indexPedido);
		}
	}

	return seProcesoElPedido;
}


int DarDeBajaCliente(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos)
{
	int idClienteBaja;
	int indexClienteBaja;
	int respuesta;
	indexClienteBaja = -2;

	if(listaClientes!= NULL && longitudClientes > 0)
	{
		if(MostrarListaClientes(listaClientes, longitudClientes))
		{
			while(1)
			{
				PedirEnteroMayorQue("\nIngrese el ID del cliente que desea Dar de Baja: ", "ERROR. Debe ingresar un numero positivo. ", &idClienteBaja, 0);
				indexClienteBaja = BuscarClientePorId(listaClientes,longitudClientes, idClienteBaja);
				if(indexClienteBaja == -1)
				{
					printf("Cliente Ingresado Inexistente, ¿Desea volver a intentarlo? \n"
							"	1 -> SI\n"
							"	2 -> NO, volver a Menu Principal\n");
					PedirEnteroValidado("Ingrese respuesta: ", "ERROR. valor invalido \n", &respuesta, 1, 2);
					if(respuesta == 1)
					{
						continue;
					}
				}
				break;
			}
			indexClienteBaja = BajaClienteEnIndice(listaClientes, indexClienteBaja);
			if(indexClienteBaja != -1)
			{
				DarDeBajaPedidoPorIdCliente(listaPedidos, longitudPedidos, idClienteBaja);
			}
		}
	}

	return indexClienteBaja;
}

