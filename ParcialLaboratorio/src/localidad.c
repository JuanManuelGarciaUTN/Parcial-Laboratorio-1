/*
 * localidad.c
 *
 *  Created on: 19 oct. 2021
 *      Author: juanm
 */


#include "localidad.h"

void InicializarVacioLocalidad(eLocalidad listaLocalidades[], int longitud)
{
	if(listaLocalidades != NULL)
	{
		for(int i=0; i<longitud; i++)
		{
			listaLocalidades[i].estado = VACIO;
		}
	}
}


void InicializarTestingLocalidad(eLocalidad listaLocalidades[], int longitud, int* idNueva)
{
	int id;
	char ultimoNumero[2];
	for(int i=0; i<9; i++)
	{
		id = *idNueva;
		*idNueva += 1;

		itoa(id,ultimoNumero,10);

		listaLocalidades[i].idLocalidad = id;

		strcpy(listaLocalidades[i].nombre, "localidad ");
		strcat(listaLocalidades[i].nombre, ultimoNumero);

		listaLocalidades[i].estado = CARGADO;
	}
}

int BajaLocalidad( eLocalidad listaLocalidades[], int longitudLocalidades)
{
	int seDioDeBaja;
	int idBaja;
	int indexBaja;
	seDioDeBaja = 0;

	if(MostrarListaLocalidades(listaLocalidades, longitudLocalidades))
	{
		while(1)
		{
			PedirEnteroMayorQue("Ingrese el Id a dar de baja: ", "ERROR. SOLO ACEPTA ENTEROS POSITIVOS\n", &idBaja, 0);
			indexBaja = BuscarLocalidadPorId(listaLocalidades, longitudLocalidades, idBaja);
			if(indexBaja != -1)
			{
				break;
			}
			printf("ERROR ID INVALIDO\n");
		}
		BajaDeLocalidadEnIndice(listaLocalidades, indexBaja);

	}


	return seDioDeBaja;
}

int AltaLocalidad(eLocalidad listaLocalidades[], int longitud, int* idNueva)
{
	int seCargoCorrectamente;
	seCargoCorrectamente = 0;

	if(listaLocalidades != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaLocalidades[i].estado == VACIO)
			{
				PedirCadenaAlfanumericaTodoMinuscula("Ingrese el nombre de la localidad: ", "ERROR. Solo puede ingresar letras, espacio o numeros \n", listaLocalidades[i].nombre, 20);
				listaLocalidades[i].idLocalidad = *idNueva;
				seCargoCorrectamente = 1;
				*idNueva += 1;
				break;
			}
		}
	}
	return seCargoCorrectamente;
}

int BuscarLocalidadPorId(eLocalidad listaLocalidades[],int longitud, int idBuscada)
{
	int indexLocalidad;
	indexLocalidad = -1;

	if(listaLocalidades != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaLocalidades[i].idLocalidad == idBuscada)
			{
				indexLocalidad = i;
				break;
			}
		}
	}
	return indexLocalidad;
}


int BajaDeLocalidadEnIndice(eLocalidad listaLocalidades[],int indexBaja)
{
	int opcionElejida;

	if(indexBaja > -1)
	{
		printf("\n¿Seguro desea Dar de Baja Localidad?\n"
				"	1 -> SI \n"
				"	2 -> NO, volver al menu principal \n\n");
		PedirEnteroValidado("Ingrese opcion a realizar: ", "ERROR, opcion invalida \n", &opcionElejida, 1, 2);

		switch(opcionElejida)
		{
			case 1:
				listaLocalidades[indexBaja].estado = VACIO;
				break;

			case 2:
				indexBaja = -1;
				break;
		}
	}

	return indexBaja;
}

void MostrarLocalidad(eLocalidad localidad)
{
	printf("%d %s\n", localidad.idLocalidad, localidad.nombre);
}

int MostrarListaLocalidades(eLocalidad listaLocalidades[],int longitud)
{
	int existeAlMenosUno;
	existeAlMenosUno = 0;

	if(listaLocalidades != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaLocalidades[i].estado == CARGADO)
			{
				if(existeAlMenosUno == 0)
				{
					existeAlMenosUno = 1;
					printf("ID \n\n");
				}
				MostrarLocalidad(listaLocalidades[i]);
			}
		}
	}

	return existeAlMenosUno;
}

int ModificarLocalidadEnIndice(eLocalidad listaLocalidades[],int indexModificar)
{
	int opcionElejida;

	if(indexModificar > -1)
	{
		printf("\n¿Que desea Modificar de Localidad?\n"
				"	1 -> Nombre \n"
				"	2 -> NADA, volver al menu principal \n\n");
		PedirEnteroValidado("Ingrese opcion a realizar: ", "ERROR, opcion invalida \n", &opcionElejida, 1, 2);

		switch(opcionElejida)
		{
			case 1:
				PedirCadenaAlfanumericaTodoMinuscula("Ingrese el nuevo nombre de la localidad: ", "ERROR. Debe ingresar solo letras, espacios o numeros \n", listaLocalidades[indexModificar].nombre, 20);
				break;

			case 2:
				indexModificar = -1;
				break;
		}
	}

	return indexModificar;
}
