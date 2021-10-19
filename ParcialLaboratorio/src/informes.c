/*
 * informes.c
 *
 *  Created on: 19 oct. 2021
 *      Author: juanm
 */

#include "informes.h"


int MostrarListaDePedidosPendientes(ePedido listaPedidos[], int longitudPedidos, eCliente listaClientes[], int longitudClientes)
{
	int existeAlMenosUno;
	int indexCliente;

	existeAlMenosUno = 0;

	if(listaPedidos != NULL && longitudPedidos > 0)
	{
		for(int i=0; i<longitudPedidos; i++)
		{
			if(listaPedidos[i].estado == PENDIENTE)
			{
				if(existeAlMenosUno == 0)
				{
					printf("ID    CUIT Cliente   Direccion Cliente        Cantidad Kilos a Recolectar\n\n");
					existeAlMenosUno = 1;
				}
				indexCliente = BuscarClientePorId(listaClientes, longitudClientes, listaPedidos[i].idCliente);
				printf("%-4d  %11s    %-20s  %8.2f\n", listaPedidos[i].idPedido, listaClientes[indexCliente].cuit, listaClientes[indexCliente].direccion, listaPedidos[i].kilosARecolectar);
			}
		}
	}
	return existeAlMenosUno;
}


int MostrarListaDePedidosProcesados(ePedido listaPedidos[], int longitudPedidos, eCliente listaClientes[], int longitudClientes)
{
	int existeAlMenosUno;
	int indexCliente;

	existeAlMenosUno = 0;

	if(listaPedidos != NULL && longitudPedidos > 0)
	{
		for(int i=0; i<longitudPedidos; i++)
		{
			if(listaPedidos[i].estado == COMPLETADO)
			{
				if(existeAlMenosUno == 0)
				{
					printf("ID    CUIT Cliente    Direccion Cliente        Kilos HDPE  Kilos LDPE  Kilos PP\n\n");
					existeAlMenosUno = 1;
				}
				indexCliente = BuscarClientePorId(listaClientes, longitudClientes, listaPedidos[i].idCliente);
				printf("%-4d  %11s     %-20s  %8.2f    %8.2f    %8.2f\n", listaPedidos[i].idPedido, listaClientes[indexCliente].cuit, listaClientes[indexCliente].direccion, listaPedidos[i].kilosProcesadosHdpe, listaPedidos[i].kilosProcesadosLdpe, listaPedidos[i].kilosProcesadosPp);
			}
		}
	}
	return existeAlMenosUno;
}


int MostrarListaClientesYCantidadPedidosPendientes(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos)
{
	int existeAlMenosUno;
	int cantidadPedidosPendientesPorCliente;

	existeAlMenosUno = 0;

	if(listaClientes != NULL && longitudClientes > 0)
	{
		for(int i=0; i<longitudClientes; i++)
		{
			if(listaClientes[i].estado == CARGADO)
			{
				if(existeAlMenosUno == 0)
				{
					printf("ID   Nombre                                              CUIT           Direccion             Localidad            Cantidad Pedidos Pendientes \n\n");

					existeAlMenosUno = 1;
				}
				MostrarCliente(listaClientes[i]);
				cantidadPedidosPendientesPorCliente = ContarCantidadPedidosPendientesPorIdCliente(listaPedidos, longitudClientes, listaClientes[i].idCliente);
				printf("%d\n", cantidadPedidosPendientesPorCliente);
			}
		}
	}

	return existeAlMenosUno;
}


int MostrarPromedioKilosPolipropilenoProcesadoPorCliente(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos)
{
	int existeAlMenosUnCliente;
	float promedio;

	existeAlMenosUnCliente = 0;

	promedio = CalcularPromedioKilosPolipropilenoProcesadoPorCliente(listaClientes, longitudClientes, listaPedidos, longitudPedidos);
	if(promedio != -1)
	{
		existeAlMenosUnCliente = 1;
		printf("El promedio de kilogramos de Polipropileno Reciclados por Cantidad de Clientes es: %.2f \n", promedio);
	}

	return existeAlMenosUnCliente;
}


int MostrarCantidadPedidosPendientesEnUnaLocalidad(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos)
{
	int existeAlMenosUnCliente;
	int cantidadPedidos;
	char localidadIngresada[20];

	existeAlMenosUnCliente = 0;

	if(ContarCantidadClientes(listaClientes, longitudClientes) != 0)
	{
		existeAlMenosUnCliente = 1;
		PedirCadenaAlfanumericaTodoMinuscula("Ingrese la localidad a consultar: ", "ERROR. Solo puede ingresar letras y numeros \n", localidadIngresada, 20);
		cantidadPedidos = ContarCantidadDePedidosPendientesEnLocalidad(listaClientes, longitudClientes, listaPedidos, longitudPedidos, localidadIngresada);
		printf("La cantidad de Pedidos Pendientes en %s es: %d", localidadIngresada, cantidadPedidos);
	}

	return existeAlMenosUnCliente;
}


float CalcularPromedioKilosPolipropilenoProcesadoPorCliente(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos)
{
	int kilosPolipropilenoProcesado;
	int cantidadClientes;
	float promedio;

	promedio = -1;
	kilosPolipropilenoProcesado = ContarCantidadProcesadaPolipropileno(listaPedidos, longitudPedidos);
	cantidadClientes = ContarCantidadClientes(listaClientes, longitudClientes);

	if(cantidadClientes > 0)
	{
		promedio = (float)kilosPolipropilenoProcesado / cantidadClientes;
	}

	return promedio;
}


int ContarCantidadDePedidosPendientesEnLocalidad(eCliente listaClientes[], int longitudClientes, ePedido listaPedidos[], int longitudPedidos, char localidad[])
{
	int cantidadPedidosPendientes;
	cantidadPedidosPendientes = 0;

	if(listaClientes != NULL && longitudClientes > 0 && listaPedidos != NULL && longitudPedidos > 0)
	{
		for(int i=0; i<longitudClientes; i++)
		{
			if(strcmp(listaClientes[i].localidad, localidad) == 0 && listaClientes[i].estado == CARGADO)
			{
				for(int j=0; j<longitudPedidos; j++)
				{
					if(listaPedidos[j].idCliente == listaClientes[i].idCliente && listaPedidos[j].estado == PENDIENTE)
					{
						cantidadPedidosPendientes++;
					}
				}
			}
		}
	}

	return cantidadPedidosPendientes;
}
