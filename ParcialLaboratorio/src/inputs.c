/*
 * input.c
 *
 *  Created on: 12 oct. 2021
 *      Author: juanm
 */

#include"inputs.h"

int PedirCadenaAlfanumericaTodoMinuscula(char mensaje[], char mensajeError[], char cadena[], int longitud)
{
	int retorno;
	char buffer[longitud];

	retorno = 0;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGets(buffer, longitud) && EsAlfanumerico(buffer))
		{
			retorno = 1;
			FormatearTodoMinuscula(buffer);
			strcpy(cadena,buffer);
			break;
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int PedirSustantivoPropio(char mensaje[], char mensajeError[], char cadena[], int longitud)
{
	int retorno;
	char buffer[longitud];

	retorno = 0;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGets(buffer, longitud) && EsSustantivo(buffer))
		{
			retorno = 1;
			FormatearSustantivoPropio(buffer);
			strcpy(cadena,buffer);
			break;
		}
		printf("%s", mensajeError);
	}

	return retorno;
}


int PedirEnteroValidado(char mensaje[], char mensajeError[], int* pEntero, int minimo, int maximo)
{
	int retorno = 0;
	int enteroIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetInt(&enteroIngresado))
		{
			if(enteroIngresado >= minimo && enteroIngresado <= maximo)
			{
				*pEntero = enteroIngresado;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int PedirEnteroMayorQue(char mensaje[], char mensajeError[], int* pEntero, int mayorQue)
{
	int retorno = 0;
	int enteroIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetInt(&enteroIngresado))
		{
			if(enteroIngresado > mayorQue)
			{
				*pEntero = enteroIngresado;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int PedirEntero(char mensaje[], char mensajeError[], int* pEntero)
{
	int retorno = 0;
	int enteroIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetInt(&enteroIngresado))
		{
			*pEntero = enteroIngresado;
			retorno = 1;
			break;
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int PedirFloatMayorQue(char mensaje[], char mensajeError[], float* pFloat, float mayorQue)
{
	int retorno = 0;
	float floatIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetFloat(&floatIngresado))
		{
			if(floatIngresado > mayorQue)
			{
				*pFloat = floatIngresado;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int PedirFloatMayorIgualQue(char mensaje[], char mensajeError[], float* pFloat, float mayorIgualQue)
{
	int retorno = 0;
	float floatIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetFloat(&floatIngresado))
		{
			if(floatIngresado >= mayorIgualQue)
			{
				*pFloat = floatIngresado;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int MiGetInt(int* pEntero)
{
	int respuesta;
	char buffer[TAMANIO_BUFFER];

	respuesta = 0;

	if(pEntero != NULL)
	{
		if(MiGets(buffer, TAMANIO_BUFFER) && EsEntero(buffer))
		{
			*pEntero = atoi(buffer);
			respuesta = 1;
		}
	}

	return respuesta;
}

int MiGetFloat(float* pFlotante)
{
	int respuesta;
	char buffer[TAMANIO_BUFFER];

	respuesta = 0;

	if(pFlotante != NULL)
	{
		if(MiGets(buffer, TAMANIO_BUFFER) && EsFloat(buffer))
		{
			*pFlotante = atof(buffer);
			respuesta = 1;
		}
	}

	return respuesta;
}

int MiGets(char cadena[], int longitud)
{
	fflush(stdin);
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
			return 1;
		}
	}
	return 0;
}

//Funciones para validar si una cadena es de un tipo segun el formato Es[validacio] ej EsEntero, etc
int EsEntero(char cadena[])
{
	int i;
	int esNumerica;

	i = 0;
	esNumerica = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] < '0' || cadena[i] > '9')  && !(i==0 && cadena[0] == '-'))
			{
				esNumerica = 0;
				break;
			}
			i++;
		}
	}
	else
	{
		esNumerica = 0;
	}

	return esNumerica;
}

int EsFloat(char cadena[])
{
	int i;
	int esFlotante;
	int flagPrimerComa;

	i = 0;
	flagPrimerComa = 0;
	esFlotante = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] == '.' || cadena[i] == ',') && flagPrimerComa == 0 )
			{
				flagPrimerComa = 1;
				cadena[i] = '.';
			}
			else
			{
				if((cadena[i] < '0' || cadena[i] > '9')  && !(i==0 && cadena[0] == '-'))
				{
					esFlotante = 0;
					break;
				}
			}
			i++;
		}
	}
	else
	{
		esFlotante = 0;
	}

	return esFlotante;
}

int EsAlfanumerico(char cadena[])
{
	int i;
	int esAlfanumerico;

	i = 0;
	esAlfanumerico = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(iscntrl(cadena[i]) || ispunct(cadena[i]))
			{
				esAlfanumerico = 0;
				break;
			}
			i++;
		}
	}
	else
	{
		esAlfanumerico = 0;
	}

	return esAlfanumerico;
}

int EsSustantivo(char cadena[])
{
	int i;
	int esSustantivoPropio;

	i = 0;
	esSustantivoPropio = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(iscntrl(cadena[i]) || isdigit(cadena[i]) || ispunct(cadena[i]))
			{
				esSustantivoPropio = 0;
				break;
			}
			i++;
		}
	}
	else
	{
		esSustantivoPropio = 0;
	}

	return esSustantivoPropio;
}

int EsNumerico(char cadena[])
{
	int i;
	int esNumerico;

	i = 0;
	esNumerico = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(isdigit(cadena[i]) == FALSE)
			{
				esNumerico = 0;
				break;
			}
			i++;
		}
	}
	else
	{
		esNumerico = 0;
	}

	return esNumerico;
}

void FormatearSustantivoPropio(char cadena[])
{
	int i;
	i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(i==0 || isspace(cadena[i-1]))
			{
				cadena[i] = toupper(cadena[i]);
			}
			else
			{
				cadena[i] = tolower(cadena[i]);
			}
			i++;
		}
	}
}

void FormatearTodoMinuscula(char cadena[])
{
	int i;
	i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			cadena[i] = tolower(cadena[i]);
			i++;
		}
	}
}

int IngresarCuit(char mensaje[], char mensajeError[], char cadena[])
{
	int retorno;
	char buffer[13];

	retorno = 0;
	while(1)
	{
		printf("%s", mensaje);
		if(MiGets(buffer, 13) && EsNumerico(buffer) && strlen(buffer) == 11)
		{
			retorno = 1;
			strcpy(cadena, buffer);
			break;
		}

		printf("%s", mensajeError);
	}

	return retorno;
}
