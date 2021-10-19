/*
 * eGenerico.c
 *
 *  Created on: 19 oct. 2021
 *      Author: juanm
 */


#include "eGenerico.h"


void InicializarGenerico(eGenerico listaGenerico[], int longitud)
{
	if(listaGenerico != NULL)
	{
		for(int i=0; i<longitud; i++)
		{
			listaGenerico[i].estado = VACIO;
		}
	}
}

int AltaGenerico(eGenerico listaGenerico[], int longitud, int* idNueva)
{
	int seCargoCorrectamente;
	seCargoCorrectamente = 0;

	if(listaGenerico != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaGenerico[i].estado == VACIO)
			{
				seCargoCorrectamente = 1;
				*idNueva += 1;
				break;
			}
		}
	}
	return seCargoCorrectamente;
}

int BuscarGenericoPorId(eGenerico listaGenerico[],int longitud, int idBuscada)
{
	int indexGenerico;
	indexGenerico = -1;

	if(listaGenerico != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaGenerico[i].idGenerico == idBuscada)
			{
				indexGenerico = i;
				break;
			}
		}
	}
	return indexGenerico;
}


int BajaDeGenericoEnIndice(eGenerico listaGenerico[],int indexBaja)
{
	int opcionElejida;

	if(indexBaja > -1)
	{
		printf("\n¿Seguro desea Dar de Baja Generico?\n"
				"	1 -> SI \n"
				"	2 -> NO, volver al menu principal \n\n");
		PedirEnteroValidado("Ingrese opcion a realizar: ", "ERROR, opcion invalida \n", &opcionElejida, 1, 2);

		switch(opcionElejida)
		{
			case 1:
				listaGenerico[indexBaja].estado = VACIO;
				break;

			case 2:
				indexBaja = -1;
				break;
		}
	}

	return indexBaja;
}

void MostrarGenerico(eGenerico Generico)
{
	printf("%d \n", Generico.idGenerico);
}

int MostrarListaGenerico(eGenerico listaGenerico[],int longitud)
{
	int existeAlMenosUno;
	existeAlMenosUno = 0;

	if(listaGenerico != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaGenerico[i].estado == CARGADO)
			{
				if(existeAlMenosUno == 0)
				{
					existeAlMenosUno = 1;
					printf("ID \n\n");
				}
				MostrarGenerico(listaGenerico[i]);
			}
		}
	}

	return existeAlMenosUno;
}

int ModificarGenericoEnIndice(eGenerico listaGenerico[],int indexModificar)
{
	int opcionElejida;

	if(indexModificar > -1)
	{
		printf("\n¿Que desea Modificar de Generico?\n"
				"	1 -> SI \n"
				"	2 -> NO, volver al menu principal \n\n");
		PedirEnteroValidado("Ingrese opcion a realizar: ", "ERROR, opcion invalida \n", &opcionElejida, 1, 2);

		switch(opcionElejida)
		{
			case 1:
				break;

			case 2:
				indexModificar = -1;
				break;
		}
	}

	return indexModificar;
}
