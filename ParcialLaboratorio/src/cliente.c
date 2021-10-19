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

		strcpy(listaClientes[i].localidad, "localidad ");
		strcat(listaClientes[i].localidad, ultimoNumero);

		strcpy(listaClientes[i].direccion, "direccion ");
		strcat(listaClientes[i].direccion, ultimoNumero);

		listaClientes[i].estado = CARGADO;
	}
}

int AltaDeCliente(eCliente listaClientes[], int longitud, int* idNueva)
{
	int seCargoCliente;

	seCargoCliente = 0;

	if(listaClientes != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaClientes[i].estado == VACIO)
			{
				listaClientes[i].idCliente = *idNueva;
				PedirSustantivoPropio("Ingrese el nombre del cliente: ", "ERROR. Debe ingrasar un nombre.\n", listaClientes[i].nombre, LONGITUD_NOMBRE);
				IngresarCuit("Ingrese el CUIT (solamente numeros sin simbolos o espacio) del cliente : ", "ERROR. Debe Ingresar los 11 numeros del CUIT sin simbolos o espacios\n", listaClientes[i].cuit);
				PedirCadenaAlfanumericaTodoMinuscula("Ingrese la direccion del cliente: ", "ERROR. Solo puede ingresar letras o numeros \n", listaClientes[i].direccion, LONGITUD_DIRECCION);
				PedirCadenaAlfanumericaTodoMinuscula("Ingrese la localidad del cliente: ", "ERROR. Solo puede ingresar letras o numeros \n", listaClientes[i].localidad, LONGITUD_LOCALIDAD);
				listaClientes[i].estado = CARGADO;
				seCargoCliente = 1;
				*idNueva += 1;
				break;
			}
		}
	}

	return seCargoCliente;
}


void MostrarCliente(eCliente cliente)
{
	printf("%-3d  %-50s  %s    %-20s  %-20s ", cliente.idCliente, cliente.nombre, cliente.cuit, cliente.direccion, cliente.localidad);
}


int MostrarListaClientes(eCliente listaClientes[], int longitud)
{
	int existeAlMenosUno;

	existeAlMenosUno = 0;

	if(listaClientes != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaClientes[i].estado == CARGADO)
			{
				if(existeAlMenosUno == 0)
				{
					printf("ID   Nombre                                              CUIT           Direccion             Localidad\n\n");

					existeAlMenosUno = 1;
				}
				MostrarCliente(listaClientes[i]);
				printf(" \n");
			}
		}
	}

	return existeAlMenosUno;
}


int ModificarDatosCliente(eCliente listaClientes[], int longitud)
{
	int idClienteAMdoficar;
	int indexClienteModificar;
	int respuesta;
	indexClienteModificar = -2;

	if(listaClientes!= NULL && longitud > 0)
	{
		respuesta = MostrarListaClientes(listaClientes, longitud);
		if(respuesta == TRUE)
		{
			while(1)
			{
				PedirEnteroMayorQue("\nIngrese el ID del cliente que desea modificar: ", "ERROR. Debe ingresar un numero positivo. ", &idClienteAMdoficar, 0);
				indexClienteModificar = BuscarClientePorId(listaClientes,longitud, idClienteAMdoficar);
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
			indexClienteModificar = ModificarClienteEnIndice(listaClientes, indexClienteModificar);
		}
	}
	return indexClienteModificar;
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

int ModificarClienteEnIndice(eCliente listaClientes[], int indexCliente)
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
				PedirCadenaAlfanumericaTodoMinuscula("Ingrese la nueva localidad del cliente: ", "ERROR. Solo puede ingresar letras o numeros \n", listaClientes[indexCliente].localidad, LONGITUD_LOCALIDAD);
				break;

			case 3:
				indexCliente = -1;
				break;
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



