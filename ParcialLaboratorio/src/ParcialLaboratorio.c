/*
 ============================================================================
 Name        : ParcialLaboratorio.c
 Author      : Juan Manuel Garcia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "informes.h"
#include "nexoEstructuras.h"
#include "menu.h"

#define CANTIDAD_MAX_CLIENTE 100
#define CANTIDAD_MAX_PEDIDOS 1000
#define CANTIDAD_MAX_LOCALIDADES 100


int main(void) {
	setbuf(stdout, NULL);

	int opcionElejida;
	int respuesta;
	int idNuevaClientes;
	int idNuevaPedidos;
	int idNuevaLocalidades;

	eCliente listaClientes[CANTIDAD_MAX_CLIENTE];
	ePedido listaPedidos[CANTIDAD_MAX_PEDIDOS];
	eLocalidad listaLocalidades[CANTIDAD_MAX_LOCALIDADES];

	idNuevaClientes = 1;
	idNuevaPedidos = 1;
	idNuevaLocalidades = 1;

	InicializarVacioLocalidad(listaLocalidades, CANTIDAD_MAX_LOCALIDADES);
	InicializarTestingLocalidad(listaLocalidades, CANTIDAD_MAX_LOCALIDADES, &idNuevaLocalidades);

	InicializarVacioClientes(listaClientes, CANTIDAD_MAX_CLIENTE);
	InicializarTestingClientes(listaClientes, CANTIDAD_MAX_CLIENTE, &idNuevaClientes);

	InicializarVacioPedidos(listaPedidos, CANTIDAD_MAX_PEDIDOS);
	InicializarTestingPedidos(listaPedidos, CANTIDAD_MAX_PEDIDOS, &idNuevaPedidos);



	do
	{
		MostrarMenuPrincipal();
		PedirEnteroValidado("Ingrese accion a realizar: ", "ERROR. Valor Invalido \n", &opcionElejida, 1, 13);
		system("cls");
		switch(opcionElejida)
		{
			case 1:
				respuesta = AltaDeCliente(listaClientes, CANTIDAD_MAX_CLIENTE, listaLocalidades, CANTIDAD_MAX_LOCALIDADES, &idNuevaClientes);
				system("cls");
				if(respuesta == 1)
				{
					printf("Se Cargo Correctamente el Cliente ID: %d  \n\n", idNuevaClientes-1);
				}
				else
				{
					printf("No se Pudo Cargar un Cliente porque la Lista esta Completa \n\n");
				}
				break;

			case 2:
				respuesta = ModificarDatosCliente(listaClientes, CANTIDAD_MAX_CLIENTE, listaLocalidades, CANTIDAD_MAX_LOCALIDADES);
				system("cls");
				switch(respuesta)
				{
					case -2:
						printf("No se Puede Modificar los datos de los Clientes porque la Lista esta Vacia \n\n");
						break;

					case -1:
						break;

					default:
						printf("Se Modificaron Correctamente los datos del cliente ID %d \n\n", listaClientes[respuesta].idCliente);
						break;
				}
				break;

			case 3:
				respuesta = DarDeBajaCliente(listaClientes, CANTIDAD_MAX_CLIENTE, listaPedidos, CANTIDAD_MAX_PEDIDOS, listaLocalidades, CANTIDAD_MAX_LOCALIDADES);
				system("cls");
				switch(respuesta)
				{
					case -2:
						printf("No se Puede Dar de Baja un Cliente porque la Lista esta Vacia \n\n");
						break;

					case -1:
						break;

					default:
						printf("Se Dio de Baja al Cliente Correctamente \n\n");
						break;
				}
				break;

			case 4:
				respuesta = AltaDePedidoRecoleccion(listaPedidos, CANTIDAD_MAX_PEDIDOS, listaClientes, CANTIDAD_MAX_CLIENTE, listaLocalidades, CANTIDAD_MAX_LOCALIDADES, &idNuevaPedidos);
				system("cls");
				switch(respuesta)
				{
				case 1:
					printf("Se Cargo Correctamente el Pedido de Recoleccion ID: %d  \n\n", idNuevaPedidos-1);
					break;

				case -1:
					printf("No se Pudo Cargar un Pedido de Recoleccion porque la Lista de Pedidos esta Completa \n\n");
					break;

				case -2:
					printf("No se Puede Cargar un Pedido de Recoleccion porque No hay Clientes Cargados \n\n");
					break;
				}
				break;

			case 5:
				respuesta = ProcesarPedidoDeRecoleccion(listaPedidos, CANTIDAD_MAX_PEDIDOS, listaClientes, CANTIDAD_MAX_CLIENTE);
				system("cls");
				switch(respuesta)
				{
				case 1:
					printf("Se Proceso Correctamente el Pedido de Recoleccion: \n\n");
					break;

				case -1:
					printf("No se Puede Procesar un Pedido de Recoleccion porque la Lista esta Vacia \n\n");
					break;
				}
				break;

			case 6:
				respuesta = MostrarListaClientesYCantidadPedidosPendientes(listaClientes, CANTIDAD_MAX_CLIENTE, listaPedidos, CANTIDAD_MAX_PEDIDOS, listaLocalidades, CANTIDAD_MAX_LOCALIDADES);
				switch(respuesta)
				{
				case 1:
					PresioneEnterParaContinuar();
					system("cls");
					break;

				case 0:
					system("cls");
					printf("No se Puede Mostrar los Clientes porque la Lista esta Vacia \n\n");
					break;
				}
				break;

			case 7:
				respuesta = MostrarListaDePedidosPendientes(listaPedidos, CANTIDAD_MAX_PEDIDOS, listaClientes, CANTIDAD_MAX_CLIENTE);
				switch(respuesta)
				{
				case 1:
					PresioneEnterParaContinuar();
					system("cls");
					break;

				case 0:
					system("cls");
					printf("No se Puede Mostrar los Pedidos de Recoleccion Pendientes porque la Lista esta Vacia \n\n");
					break;
				}
				break;

			case 8:
				respuesta = MostrarListaDePedidosProcesados(listaPedidos, CANTIDAD_MAX_PEDIDOS, listaClientes, CANTIDAD_MAX_CLIENTE);
				switch(respuesta)
				{
				case 1:
					PresioneEnterParaContinuar();
					system("cls");
					break;

				case 0:
					system("cls");
					printf("No se Puede Mostrar los Pedidos Procesados porque la Lista esta Vacia \n\n");
					break;
				}
				break;

			case 9:
				respuesta = MostrarCantidadPedidosPendientesEnUnaLocalidad(listaClientes, CANTIDAD_MAX_CLIENTE, listaPedidos, CANTIDAD_MAX_PEDIDOS, listaLocalidades, CANTIDAD_MAX_LOCALIDADES);
				if(respuesta == TRUE)
				{
					PresioneEnterParaContinuar();
					system("cls");
				}
				else
				{
					printf("No se Puede Consultar la Cantidad de Pedidos Pendientes en una Localidad porque la Lista de Clientes esta Vacia \n\n");
				}
				break;

			case 10:
				respuesta = MostrarPromedioKilosPolipropilenoProcesadoPorCliente(listaClientes, CANTIDAD_MAX_CLIENTE, listaPedidos, CANTIDAD_MAX_PEDIDOS);
				switch(respuesta)
				{
				case 1:
					PresioneEnterParaContinuar();
					system("cls");
					break;

				case 0:
					system("cls");
					printf("No se Puede Mostrar el Promedio de Kilos de Polipropileno Procesado por Cliente porque la Lista de Clientes esta Vacia \n\n");
					break;
				}
				break;

			case 11:
				respuesta = MostrarListaDePedidosProcesados(listaPedidos, CANTIDAD_MAX_PEDIDOS, listaClientes, CANTIDAD_MAX_CLIENTE);
				switch(respuesta)
				{
				case 1:
					PresioneEnterParaContinuar();
					system("cls");
					break;

				case 0:
					system("cls");
					printf("No se Puede Mostrar los Pedidos Procesados porque la Lista esta Vacia \n\n");
					break;
				}
				break;

			case 12:
				respuesta = MostrarListaDePedidosProcesados(listaPedidos, CANTIDAD_MAX_PEDIDOS, listaClientes, CANTIDAD_MAX_CLIENTE);
				switch(respuesta)
				{
				case 1:
					PresioneEnterParaContinuar();
					system("cls");
					break;

				case 0:
					system("cls");
					printf("No se Puede Mostrar los Pedidos Procesados porque la Lista esta Vacia \n\n");
					break;
				}
				break;

			case 13:
				system("cls");
				printf("Gracias, Vuelva Pronto \n");
				PresioneEnterParaContinuar();
				break;
		}

	} while(opcionElejida != 13);

	return EXIT_SUCCESS;
}
