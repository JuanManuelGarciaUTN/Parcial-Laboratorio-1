/*
 * menu.c
 *
 *  Created on: 17 oct. 2021
 *      Author: juanm
 */


#include "menu.h"


void MostrarMenuPrincipal(void)
{
	printf("Menu Recoleccion de Basura: \n\n"
			"	1  -> ALTA de Cliente \n"
			"	2  -> MODIFICAR Datos de Cliente \n"
			"	3  -> BAJA de Cliente \n"
			"	4  -> CREAR Pedido de Recolección \n"
			"	5  -> PROCESAR Residuos \n"
			"	6  -> IMPRIMIR Clientes \n"
			"	7  -> IMPRIMIR Pedidos Pendientes\n"
			"	8  -> IMPRIMIR Pedidos Procesados \n"
			"	9  -> CONSULTAR Pedidos Pendientes en una Localidad \n"
			"	10 -> CONSULTAR Kilos de Polipropileno Reciclados Por Cliente \n"
			"	11 -> CONSULTAR Cliente con más Pedidos Pendientes. \n"
			"	12 -> CONSULTAR Cliente con más Pedidos Completados. \n"
			"	13 -> ALTA Localidad. \n"
			"	14 -> BAJA Localidad\n"
			"	15 -> SALIR del Programa \n\n");
}

void PresioneEnterParaContinuar(void)
{
	fflush(stdin);
	printf("\nPresione Enter para Continuar...\n");
	getchar();
}
