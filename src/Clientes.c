#include "Clientes.h"

int inicializarClientes(eCliente clientes[], int tam)
{
	int retorno;
	int i;

	retorno = -1;

	if(clientes != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			clientes[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}

	return retorno;
}

int cargarUnCliente(eCliente clientes[], int tam, int* ultimaIdIngresada) {
	int retorno;
	int id;
	eCliente clienteAuxiliar;
	int index;
	int retornoAuxiliar;

	retorno = -1;
	id = *ultimaIdIngresada;

	if(clientes != NULL && tam > 0)
	{
		index = buscarEspacioLibre(clientes, tam);


		if(index != -1)
		{
			retorno = 0;
			retornoAuxiliar = ingresarUnCliente(&clienteAuxiliar);
			if(retornoAuxiliar == 1)
			{
				id++;
				*ultimaIdIngresada = id;
				clientes[index] = clienteAuxiliar;
				clientes[index].idCliente = id;
				clientes[index].isEmpty = FULL;
				retorno = 1;
			}
		}
	}


	return retorno;
}


int buscarEspacioLibre(eCliente clientes[], int tam)
{
	int index;
	int i;

	index = -1;

	if(clientes != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(clientes[i].isEmpty == EMPTY)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int getDireccion(char* direccion){
	int retorno;
	char direccionAux[200];
	char altura[51];
	int numero;

	retorno = -1;

	if(
		utn_getString(direccionAux,51,3,"\nIngrese direccion: \n", "Error, intente nuevamente") == 0 &&
		utn_getInt(&numero, 0,9000,3,"Ingrese la altura: \n", "Error, intente nuevamente") ==0
	){
		itoa(numero,altura,10);
			strcat(direccionAux, " ");
			strcat(direccionAux, altura);
			strcat(direccion, direccionAux);
			retorno = 0;

	}

	return retorno;


}


int ingresarUnCliente(eCliente* cliente)
{
	int retorno;
	eCliente clienteAuxiliar;

	retorno = 0;

	if(cliente != NULL)
	{
		if(
			utn_getString(clienteAuxiliar.empresa, 51,3,"\nIngrese el nombre de la empresa: \n", "\nError, intente nuevamente") ==0 &&
			utn_GetCuit(clienteAuxiliar.cuit,sizeof(clienteAuxiliar.cuit),3,"\nIngrese su CUIT 11 numeros, guiones incluidos  00-00000000-0 : \n", "Error, intente nuevamente") ==0 &&

			getDireccion(clienteAuxiliar.direccion) == 0 &&

			ingresarLocalidad(clienteAuxiliar.localidad.localidad) == 0
		  )
		{
			printf("%s", clienteAuxiliar.direccion);
			retorno = 1;
			*cliente = clienteAuxiliar;
		}
	}

	return retorno;
}

int mostrarUnCliente(eCliente cliente)
{
	int retorno;

	retorno = 0;

	printf("%d - \t%s - \t%s - \t%s",cliente.idCliente,cliente.empresa,cliente.cuit,cliente.direccion);
	printf(" - \t%s\n",cliente.localidad.localidad);
	retorno = 1;

	return retorno;
}



int mostrarClientes(eCliente* clientes, int tam)
{
	int retorno;

	retorno = 0;

	if(clientes != NULL && tam > 0 && fullCliente(clientes,tam) == 1)
	{
		puts("\nClientes activos: \n");
		puts("ID - Empresa - CUIT - Direccion - Localidad\n");
		for(int i = 0; i < tam; i++)
		{
			if(clientes[i].isEmpty == FULL)
			{
				mostrarUnCliente(clientes[i]);
			}

		}
		retorno = 1;
	}

	return retorno;
}

int fullCliente(eCliente clientes[], int tam)
{
	int retorno;

	retorno = 0;

	if(clientes != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(clientes[i].isEmpty == FULL)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}
int mostrarClientePedido(eCliente clientes[], int tam, int idCliente)
{
	int retorno;
	int index;

	retorno = 0;

	if(clientes != NULL && tam > 0)
	{
		index = buscarClienteId(clientes, tam, idCliente);

		if(index != -1)
		{
			printf("%s - \t%s",clientes[index].cuit,clientes[index].direccion);

			retorno = 1;
		}
	}


	return retorno;
}

int buscarClienteId(eCliente clientes[], int tam, int id)
{
	int index;
	int i;

	index = -1;

	if(clientes != NULL && tam > 0 && id <= tam)
	{
		for(i = 0; i < tam; i++)
		{
			if(clientes[i].idCliente == id && clientes[i].isEmpty == FULL)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int modificarCliente(eCliente clientes[], int tam, int id)
{
	int retorno;
	int index;
	char respuesta[24];

	eCliente clienteAuxiliar;

	retorno = 0;

	if(clientes != NULL && tam > 0)
	{
		index = buscarClienteId(clientes, tam, id);

		if(
				index != -1 && clientes[index].isEmpty == FULL &&
				getDireccion(clienteAuxiliar.direccion) == 0 &&
				ingresarLocalidad(clienteAuxiliar.localidad.localidad) == 0
			)
		{
			printf("\nVas a modificar al cliente %s \n",clientes[index].empresa);
			utn_getString(respuesta,24,3,"\n Estas seguro? (si/no) : \n","La opcion ingresada no es valida, intente nuevamente.");

				if(strcmp(respuesta,"si") == 0)
				{
					puts("\nModifico al cliente exitosamente\n");
					clientes[index] = clienteAuxiliar;
					retorno = 1;
		        }
		}
	}
	return retorno;
}
int eliminarCliente(eCliente clientes[], int tam, int id)
{
	int retorno;
	char respuesta[24];
	int index;

	retorno = -1;

	if(clientes != NULL && tam > 0)
	{
		index = buscarClienteId(clientes, tam, id);

		if(index != -1 && clientes[index].isEmpty == FULL)
		{
			retorno = 0;
			printf("\nVas a eliminar al cliente %s \n",clientes[index].empresa);

			utn_getString(respuesta,24,3,"\n Estas seguro? (si/no) : ","La opcion ingresada no es valida, intente nuevamente.");

			if(strcmp(respuesta,"si") == 0)
			{
				clientes[index].isEmpty = BAJA;
				puts("Elimino al cliente exitosamente");
				retorno = 1;
			}else{
				puts("Se cancelo la BAJA");
				retorno = 0;
			}
		}
	}
	return retorno;
}

int mostrarClientesEliminados(eCliente clientes[], int tam, int id)
{
	int index;
	int i;

	index = -1;

	if(clientes != NULL && tam > 0 && id <= tam)
	{
		for(i = 0; i < tam; i++)
		{
			if(clientes[i].idCliente == id && clientes[i].isEmpty == BAJA)
			{
				mostrarUnCliente(clientes[i]);
			}
		}
	}
	return index;
}







