#include "Informes.h"


int informeClientesPedidosPendientes(eCliente clientes[], int tamClientes, ePedido pedidos[], int tamPedidos, int ultimoPedido)
{
	int retorno;
	int cantidadPedidos;
	retorno = -1;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && fullCliente(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = 0;
		}
		else
		{
			puts("\nClientes Con Pedidos: \n");

			for(int i = 0; i < tamClientes; i++)
			{
				if(clientes[i].isEmpty == FULL)
				{

					puts("ID - Empresa - CUIT - Direccion - Localidad\n");
					mostrarUnCliente(clientes[i]);
					cantidadPedidos = contadorPedidosPendientes(pedidos,tamPedidos, clientes[i].idCliente);
					retorno = 1;

					if(cantidadPedidos == 0)
					{
						puts("No hay clientes con pedidos pendientes.\n");
					}else{
						printf("\n Cantidad de Clientes con pedidos pendientes : %d\n",cantidadPedidos);
					}


				}
			}
		}
	}

	return retorno;
}

int informePedidosPendientes(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido)
{
	int retorno;

	retorno = -1;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && fullCliente(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = 0;
		}
		else
		{
			printf("\nPedidos pendientes: \n");

			for(int i = 0; i < tamPedidos; i++)
			{
				if(pedidos[i].isEmpty == FULL && pedidos[i].estado == PENDIENTE)
				{
					mostrarClientePedido(clientes,tamClientes,pedidos[i].idCliente);
					mostrarUnPedido(pedidos[i],1);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}


int informePedidosCompletados(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido)
{
	int retorno;
	int retornoAuxiliar;

	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && fullCliente(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = -1;
		}
		else
		{
			printf("\nPedidos completados: \n");

			for(int i = 0; i < tamPedidos; i++)
			{
				if(pedidos[i].isEmpty == FULL && pedidos[i].estado == COMPLETADO)
				{
					mostrarUnPedido(pedidos[i],2);
					retornoAuxiliar = mostrarClientePedido(clientes,tamClientes,pedidos[i].idCliente);
					retorno = 1;

					if(retornoAuxiliar == 0)
					{
						printf("El cliente fue dado de baja\n");
					}
				}

			}

		}
	}

	return retorno;
}


int informePedidosPendientesLocalidad(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido)
{
	int retorno;
	int acumuladorPedidos;
	int cantidadPedidos;
	char localidad[sizeof(clientes[0].localidad)];

	acumuladorPedidos = 0;
	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && fullCliente(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = -1;
		}
		else
		{
			if(utn_getString(localidad,sizeof(localidad),3,"Ingrese una localidad : ","El dato ingresado es incorrecto."))
			{
				for(int i = 0; i < tamClientes; i++)
				{
					if(clientes[i].isEmpty == FULL && stricmp(clientes[i].localidad.localidad, localidad) == 0)
					{
						cantidadPedidos = contadorPedidosPendientes(pedidos,tamPedidos,clientes[i].idCliente);
						acumuladorPedidos += cantidadPedidos;
						retorno = 1;

					}
				}

				if(acumuladorPedidos == 0)
				{
					puts("\nNo hay pedidos pendientes en la localidad ingresada.\n");
				}
				else
				{
					printf("\n%s : \nPedidos pendientes : %d\n\n",localidad,acumuladorPedidos);
				}

			}
		}
	}

	return retorno;
}

int informePromedioPP(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente)
{
	int retorno;
	float acumuladorPP;
	float promedioPP;

	retorno = 0;
	acumuladorPP = 0;

	if(pedidos != NULL && tamPedidos > 0 && fullCliente(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = -1;
		}
		else
		{
			for(int i = 0; i < tamPedidos; i++)
			{
				retorno = 1;

				if(pedidos[i].isEmpty == FULL && pedidos[i].estado == COMPLETADO)
				{
					acumuladorPP += pedidos[i].PP;
				}
			}
			if(acumuladorPP == 0)
			{
				printf("\nNo hay kilos de Polipropileno ingresados.\n\n");

			}
			else
			{
				promedioPP = acumuladorPP / ultimoCliente;
				printf("\nEl promedio de Polipropileno por cliente es : %.2f\n\n",promedioPP);
			}

		}
	}

	return retorno;
}



int informeClientesMayorPendientes(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente)
{

	int contadorPedidos;
	int retorno;
	int i;
	int cantidadPedidos;
	int mayorCantidad;
	int flag;
	int index;

	flag = 0;
	retorno = 0;
	mayorCantidad=0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && fullCliente(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0 || ultimoCliente == 0)
		{
			retorno = -1;
		}
		else
		{
			for(i = 0; i < tamClientes; i++)
			{
				if(clientes[i].isEmpty == FULL)
				{
					cantidadPedidos = contadorPedidosPendientes(pedidos,tamPedidos, clientes[i].idCliente);
					contadorPedidos = cantidadPedidos;

					if(flag == 0 || mayorCantidad < cantidadPedidos)
					{
						mayorCantidad = cantidadPedidos;
						index = i;
						flag = 1;
						retorno = 1;
					}
				}
			}

			if(flag == 1)
			{
				printf("El cliente con mayor cantidad de pedidos pendientes: ");
				for(i = 0; i < tamClientes; i++)
				{
					if(clientes[index].isEmpty == FULL && contadorPedidos == mayorCantidad)
					{
						printf("%d - %s\n",clientes[index].idCliente,clientes[index].empresa);
					}
				}
			}

		}
	}

	return retorno;
}



int informeClientesMayorCompletados(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente)
{

	int contadorPedidos;
	int retorno;
	int i;
	int cantidadPedidos;
	int mayorCantidad;
	int flag;
	int index;

	flag = 0;
	retorno = 0;
	mayorCantidad=0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && fullCliente(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0 || ultimoCliente == 0)
		{
			retorno = -1;
		}
		else
		{
			for(i = 0; i < tamClientes; i++)
			{
				if(clientes[i].isEmpty == FULL)
				{
					cantidadPedidos = contadorPedidosCompletados(pedidos,tamPedidos, clientes[i].idCliente);
					contadorPedidos = cantidadPedidos;

					if(flag == 0 || mayorCantidad < cantidadPedidos)
					{
						mayorCantidad = cantidadPedidos;
						index = i;
						flag = 1;
						retorno = 1;
					}
				}
			}

			if(flag == 1)
			{
				printf("El cliente con mayor cantidad de pedidos completados: ");
				for(i = 0; i < tamClientes; i++)
				{
					if(clientes[index].isEmpty == FULL && contadorPedidos == mayorCantidad)
					{
						printf("%d - %s\n",clientes[index].idCliente,clientes[index].empresa);
					}
				}
			}

		}
	}

	return retorno;
}












