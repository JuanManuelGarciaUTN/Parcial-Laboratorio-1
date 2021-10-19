/*
 * cliente.c
 *
 *  Created on: 17 oct. 2021
 *      Author: juanm
 */

#include "cliente.h"


void InicializarVacioClientes(eCliente listaClientes[], int longitud)
{
	for(int i=0; i<longitud; i++)
	{
		listaClientes[i].estado = VACIO;
	}
}

void InicializarTestingClientes(eCliente listaClientes[], int longitud, int* idNueva)
{
	int id;
	char ultimoNumero[2];
	for(int i=0; i<9; i++)
	{
		id = *idNueva;
		*idNueva += 1;

		itoa(id,ultimoNumero,10);

		listaClientes[i].idCliente = id;

		strcpy(listaClientes[i].cuit, "2010485960");
		strcat(listaClientes[i].cuit, ultimoNumero);

		strcpy(listaClientes[i].nombre, "Testing");
		strcat(listaClientes[i].nombre, ultimoNumero);

		listaClientes[i].idLocalidad = id;

		strcpy(listaClientes[i].direccion, "direccion ");
		strcat(listaClientes[i].direccion, ultimoNumero);

		listaClientes[i].estado = CARGADO;
	}
}


int BuscarClientePorId(eCliente listaClientes[], int longitud, int idBuscada)
{
	int indexCliente;

	indexCliente = -1;

	if(listaClientes != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaClientes[i].idCliente == idBuscada && listaClientes[i].estado == CARGADO)
			{
				indexCliente = i;
				break;
			}
		}
	}

	return indexCliente;
}

int BajaClienteEnIndice(eCliente listaClientes[], int indexCliente)
{
	int opcionElejida;

	if(indexCliente > -1)
	{
		printf("\n¿Seguro desea Dar de Baja al Cliente?\n"
				"	1 -> SI \n"
				"	2 -> NO, volver al menu principal \n\n");
		PedirEnteroValidado("Ingrese opcion a realizar: ", "ERROR, opcion invalida \n", &opcionElejida, 1, 2);

		switch(opcionElejida)
		{
			case 1:
				listaClientes[indexCliente].estado = VACIO;
				break;

			case 2:
				indexCliente = -1;
				break;
		}
	}

	return indexCliente;
}


int ContarCantidadClientes(eCliente listaClientes[], int longitud)
{
	int cantidadClientes;

	cantidadClientes = 0;

	if(listaClientes != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaClientes[i].estado == CARGADO)
			{
				cantidadClientes ++;
			}
		}
	}

	return cantidadClientes;
}



