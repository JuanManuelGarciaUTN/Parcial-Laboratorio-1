/*
 * pedido.c
 *
 *  Created on: 17 oct. 2021
 *      Author: juanm
 */

#include "pedido.h"


void InicializarVacioPedidos(ePedido listaPedidos[], int longitud)
{
	for(int i=0; i<longitud; i++)
	{
		listaPedidos[i].estado = SIN_CARCAR;
	}
}

void InicializarTestingPedidos(ePedido listaPedidos[], int longitud, int* idNueva)
{
	int id;
	for(int i=0; i<9; i++)
	{
		id = *idNueva;
		*idNueva += 1;

		listaPedidos[i].idPedido = id;
		listaPedidos[i].idCliente = id;

		listaPedidos[i].kilosARecolectar = 50;
		listaPedidos[i].estado = PENDIENTE;
	}
}

int BuscarPedidoPorId(ePedido listaPedidos[], int longitud, int id)
{
	int indexPedido;

	indexPedido = -1;
	if(listaPedidos != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaPedidos[i].idPedido == id && listaPedidos[i].estado != SIN_CARCAR)
			{
				indexPedido = i;
				break;
			}
		}
	}

	return indexPedido;
}

int ProcesarPedidoEnIndice(ePedido listaPedidos[], int indexPedido)
{
	int seProcesoElPedido;
	float cantidadProcesadaHdpe;
	float cantidadProcesadaLdpe;
	float cantidadProcesadaPp;

	seProcesoElPedido = 0;

	if(indexPedido > -1)
	{
		printf("Se recolectaron %.2f kilos de residuos\n", listaPedidos[indexPedido].kilosARecolectar);
		while(1)
		{
			PedirFloatMayorIgualQue("Ingrese cuantos kilos son de Polietileno de Alta densidad: ", "ERROR. Debe ingresar un numero positivo o 0 \n", &cantidadProcesadaHdpe, 0.0);
			PedirFloatMayorIgualQue("Ingrese cuantos kilos son de Polietileno de Baja densidad: ", "ERROR. Debe ingresar un numero positivo o 0 \n", &cantidadProcesadaLdpe, 0.0);
			PedirFloatMayorIgualQue("Ingrese cuantos kilos son de Polipropileno de alta densidad: ", "ERROR. Debe ingresar un numero positivo o 0 \n", &cantidadProcesadaPp, 0.0);
			if(cantidadProcesadaHdpe + cantidadProcesadaLdpe + cantidadProcesadaPp <= listaPedidos[indexPedido].kilosARecolectar)
			{
				seProcesoElPedido = 1;
				listaPedidos[indexPedido].kilosProcesadosHdpe = cantidadProcesadaHdpe;
				listaPedidos[indexPedido].kilosProcesadosLdpe = cantidadProcesadaLdpe;
				listaPedidos[indexPedido].kilosProcesadosPp = cantidadProcesadaPp;
				listaPedidos[indexPedido].kilosARecolectar = 0;
				listaPedidos[indexPedido].estado = COMPLETADO;
				break;
			}
			printf("ERROR. La sumatoria de los kilos ingresados supera el total de lo recolectado %.2f. Vuelva a Ingresarlo \n", listaPedidos[indexPedido].kilosARecolectar);
		}
	}

	return seProcesoElPedido;
}

int ContarCantidadPedidosPendientesPorIdCliente(ePedido listaPedidos[], int longitud, int idCliente)
{
	int cantidadPedidos;
	cantidadPedidos = 0;

	if(listaPedidos != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaPedidos[i].idCliente == idCliente && listaPedidos[i].estado == PENDIENTE)
			{
				cantidadPedidos ++;
			}
		}
	}

	return cantidadPedidos;
}

int DarDeBajaPedidoPorIdCliente(ePedido listaPedidos[], int longitud, int idCliente)
{
	int alMenosUno;
	alMenosUno = 0;
	if(listaPedidos != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaPedidos[i].idCliente == idCliente)
			{
				alMenosUno = 1;
				listaPedidos[i].estado = SIN_CARCAR;
			}
		}
	}

	return alMenosUno;
}

float ContarCantidadProcesadaPolipropileno(ePedido listaPedidos[], int longitud)
{
	float cantidadProcesada;
	cantidadProcesada = 0;
	if(listaPedidos != NULL && longitud > 0)
	{
		for(int i=0; i<longitud; i++)
		{
			if(listaPedidos[i].estado == COMPLETADO)
			{
				cantidadProcesada += listaPedidos[i].kilosProcesadosPp;
			}
		}
	}

	return cantidadProcesada;
}
