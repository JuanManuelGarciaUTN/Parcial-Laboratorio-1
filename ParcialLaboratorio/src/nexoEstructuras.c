/*
 * nexoEstructuras.c
 *
 *  Created on: 17 oct. 2021
 *      Author: juanm
 */


#include "nexoEstructuras.h"

int AltaDePedidoRecoleccion(ePedido listaPedidos[], int longitudPedidos, eCliente listaClientes[], int longitudClientes, eLocalidad listaLocalidades[], int longitudLocalidades , int* idNueva)
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
				respuesta = MostrarListaClientes(listaClientes, longitudClientes, listaLocalidades, longitudLocalidades);
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

int AltaDeCliente(eCliente listaClientes[], int longitudClientes, eLocalidad listaLocalidades[], int longitudLocalidades, int* idNueva)
{
	int seCargoCliente;

	seCargoCliente = 0;

	if(listaClientes != NULL && longitudClientes > 0)
	{
		for(int i=0; i<longitudClientes; i++)
		{
			if(listaClientes[i].estado == VACIO)
			{
				listaClientes[i].idCliente = *idNueva;
				PedirSustantivoPropio("Ingrese el nombre del cliente: ", "ERROR. Debe ingrasar un nombre.\n", listaClientes[i].nombre, LONGITUD_NOMBRE);
				IngresarCuit("Ingrese el CUIT (solamente numeros sin simbolos o espacio) del cliente : ", "ERROR. Debe Ingresar los 11 numeros del CUIT sin simbolos o espacios\n", listaClientes[i].cuit);
				PedirCadenaAlfanumericaTodoMinuscula("Ingrese la direccion del cliente: ", "ERROR. Solo puede ingresar letras o numeros \n", listaClientes[i].direccion, LONGITUD_DIRECCION);
				listaClientes[i].idLocalidad = IngresarLocalidadDelCliente(listaLocalidades, longitudLocalidades);
				listaClientes[i].estado = CARGADO;
				seCargoCliente = 1;
				*idNueva += 1;
				break;
			}
		}
	}

	return seCargoCliente;
}

int IngresarLocalidadDelCliente(eLocalidad listaLocalidades[], int longitud)
{
	int idLocalidad;
	int indexLocalidad;
	idLocalidad = -1;

	if(MostrarListaLocalidades(listaLocalidades, longitud))
	{
		while(1)
		{
			PedirEnteroMayorQue("Ingrese el Id de la localidad: ", "ERROR. Debe ingresar un numero entero positivo \n", &idLocalidad, 0);
			indexLocalidad = BuscarLocalidadPorId(listaLocalidades, longitud, idLocalidad);
			if(indexLocalidad != -1)
			{
				break;
			}
			printf("ID inexistente, vuelva a ingresarlo \n");
		}

		idLocalidad = listaLocalidades[indexLocalidad].idLocalidad;
	}

	return idLocalidad;
}


int ModificarDatosCliente(eCliente listaClientes[], int longitudClientes, eLocalidad listaLocalidades[], int longitudLocalidades)
{
	int idClienteAMdoficar;
	int indexClienteModificar;
	int respuesta;
	indexClienteModificar = -2;

	if(listaClientes!= NULL && longitudClientes > 0)
	{
		respuesta = MostrarListaClientes(listaClientes, longitudClientes, listaLocalidades, longitudLocalidades);
		if(respuesta == TRUE)
		{
			while(1)
			{
				PedirEnteroMayorQue("\nIngrese el ID del cliente que desea modificar: ", "ERROR. Debe ingresar un numero positivo. ", &idClienteAMdoficar, 0);
				indexClienteModificar = BuscarClientePorId(listaClientes,longitudClientes, idClienteAMdoficar);
				if(indexClienteModificar == -1)
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
			indexClienteModificar = ModificarClienteEnIndice(listaClientes, indexClienteModificar, listaLocalidades, longitudLocalidades);
		}
	}
	return indexClienteModificar;
}

int ModificarClienteEnIndice(eCliente listaClientes[], int indexCliente, eLocalidad listaLocalidades[], int longitudLocalidades)
{
	int opcionElejida;

	if(indexCliente > -1)
	{
		printf("\n¿Que desea modificar?\n"
				"	1 -> Direccion \n"
				"	2 -> Localidad \n"
				"	3 -> Nada, volver a menu principal\n\n");
		PedirEnteroValidado("Ingrese opcion a realizar: ", "ERROR, opcion invalida \n", &opcionElejida, 1, 3);

		switch(opcionElejida)
		{
			case 1:
				PedirCadenaAlfanumericaTodoMinuscula("Ingrese la nueva direccion del cliente: ", "ERROR. Solo puede ingresar letras o numeros \n", listaClientes[indexCliente].direccion, LONGITUD_DIRECCION);
				break;

			case 2:
				listaClientes[indexCliente].idLocalidad = IngresarLocalidadDelCliente(listaLocalidades, longitudLocalidades);
				break;

			case 3:
				indexCliente = -1;
				break;
		}
	}

	return indexCliente;
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


int DarDeBajaCliente(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos, eLocalidad listaLocalidades[], int longitudLocalidades)
{
	int idClienteBaja;
	int indexClienteBaja;
	int respuesta;
	indexClienteBaja = -2;

	if(listaClientes!= NULL && longitudClientes > 0)
	{
		if(MostrarListaClientes(listaClientes, longitudClientes, listaLocalidades, longitudLocalidades))
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

