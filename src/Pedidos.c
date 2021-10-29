#include "Pedidos.h"



int contadorPedidosPendientes(ePedido pedidos[], int tam, int idCliente)
{
	int contador;
	contador = 0;

	if(pedidos != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(pedidos[i].isEmpty == FULL && pedidos[i].idCliente == idCliente && pedidos[i].estado == PENDIENTE )
			{
				contador++;
			}
		}
	}

	return contador;
}

int contadorPedidosCompletados(ePedido pedidos[], int tam, int idCliente)
{
	int contador;
	contador = 0;

	if(pedidos != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(pedidos[i].isEmpty == FULL && pedidos[i].idCliente == idCliente && pedidos[i].estado == COMPLETADO )
			{
				contador++;
			}
		}
	}

	return contador;
}



int inicializarPedidos(ePedido pedidos[], int tam){
	int retorno;
	int i;

	retorno = 0;

	if(pedidos != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			pedidos[i].isEmpty = EMPTY;
		}
		retorno = 1;
	}

	return retorno;

}

int buscarPedidosEspacioLibre(ePedido pedidos[], int tam)
{
	int index;
	int i;

	index = -1;

	if(pedidos != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(pedidos[i].isEmpty == EMPTY)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int buscarPedidoId(ePedido pedidos[], int tam, int id)
{
	int index;
	int i;

	index = -1;

	if(pedidos != NULL && tam > 0 && id <= tam)
	{
		for(i = 0; i < tam; i++)
		{
			if(pedidos[i].idPedido == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int cargarUnPedido(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int* ultimaIdPedido)
{
	int retorno;
	int idPedido;
	int idCliente;
	int index;
	float kilosAuxiliar;

	retorno = -1;
	idPedido = *ultimaIdPedido;


	if(pedidos != NULL && tamPedidos > 0)
	{
		index = buscarPedidosEspacioLibre(pedidos, tamPedidos);

		if(index != -1 &&
		utn_getInt(&idCliente,1,tamClientes,3,"Ingrese el ID del cliente: ","El ID es incorrecto, intente nuevamente" ) == 0)
		{
			if(buscarClienteId(clientes,tamClientes,idCliente) != -1)
				{
					retorno = 0;
				if(utn_getFloat(&kilosAuxiliar,0, 2000, 3,"Ingrese el total de kg a reciclar (2000 Maximo): ", "Error, ingrese un peso valido")==0)
					{
						idPedido++;
						*ultimaIdPedido = idPedido;
						pedidos[index].kilosTotales = kilosAuxiliar;
						pedidos[index].idPedido = idPedido;
						pedidos[index].idCliente = idCliente;
						pedidos[index].estado = PENDIENTE;
						pedidos[index].isEmpty = FULL;
						retorno = 1;
					}
				}
			}
		}


	return retorno;
}



int mostrarUnPedido(ePedido pedido, int flag)
{
	int retorno;

	retorno = 0;

	if(flag == 1 && pedido.estado == 0)
	{
		printf("ID Pedido : %d \tKg Totales: %f \tEstado: Pendiente\n",pedido.idPedido, pedido.kilosTotales);
		retorno = 1;
	}

	if(flag == 2 && pedido.estado == 1)
	{
		printf("ID Pedido : %d \tKg HDPE: %f \tKg LDPE: %f \tKg PP: %f \tEstado: Completado\n",pedido.idPedido, pedido.HDPE, pedido.LDPE , pedido.PP);
		retorno = 1;
	}

	return retorno;
}

int mostrarPedidos(ePedido pedidos[], int tam, int flag)
{
	int retorno;
	int retornoAuxiliar;

	retorno = -1;

	if(pedidos != NULL && tam > 0)
	{
		printf("Pedidos: \n");
		for(int i = 0; i < tam; i++)
		{
			if(pedidos[i].isEmpty == FULL && pedidos[i].estado ==0)
			{
				retornoAuxiliar = mostrarUnPedido(pedidos[i],flag);
				printf("\n");
				retorno = 1;
			}

			if(retornoAuxiliar == 0)
			{
				retorno = -1;
			}

		}
	}

	return retorno;
}


int procesarPlasticos(ePedido pedidos[],int tam)
{
	int retorno;
	int id;
	int retornoAuxiliar;
	int index;
	ePedido pedidoAuxiliar;

	retorno = 0;

	if(pedidos != NULL && tam > 0)
	{

		if(utn_getInt(&id,1,tam,3,"Ingrese el ID del Pedido : ","Error, numero es incorrecto, intente nuevamente.") == 0)
		{
			index = buscarPedidoId(pedidos,tam,id);

			if(index != -1 && pedidos[index].estado == PENDIENTE)
			{
				pedidoAuxiliar = pedidos[index];
				retornoAuxiliar = cargarPlasticos(&pedidoAuxiliar);
				retorno = -1;

				if(retornoAuxiliar == 1)
				{
					pedidos[index] = pedidoAuxiliar;
					pedidos[index].estado = COMPLETADO;
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

int cargarPlasticos(ePedido* pedido)
{
	ePedido pedidoAuxiliar;
	int retorno;
	float acumulador;
	float totalKgAuxiliar;

	pedidoAuxiliar = *pedido;
	retorno = -1;
	acumulador = 0;

	if(pedido != NULL)
	{
		totalKgAuxiliar = pedidoAuxiliar.kilosTotales;
		printf("El total de kilos es de %2f\n", totalKgAuxiliar);

		for(int i=0;i<3;i++){

			utn_getFloat(&pedidoAuxiliar.HDPE,0,totalKgAuxiliar,3, "Ingrese la cantidad de kilos de HDPE: \n", "Numero incorrecto o mayor que los kilos totales.");
			acumulador += pedidoAuxiliar.HDPE;

			utn_getFloat(&pedidoAuxiliar.LDPE,0,totalKgAuxiliar,3, "Ingrese la cantidad de kilos de LDPE: \n", "Numero incorrecto o mayor que los kilos totales.");
			acumulador += pedidoAuxiliar.LDPE;

			utn_getFloat(&pedidoAuxiliar.PP,0,totalKgAuxiliar,3, "Ingrese la cantidad de kilos de PP: \n", "Numero incorrecto o mayor que los kilos totales.");
			acumulador += pedidoAuxiliar.PP;

			if(acumulador <= totalKgAuxiliar){
				*pedido = pedidoAuxiliar;
				retorno = 1;
				break;
			}else{
				printf("Incorrecto, la suma de los plasticos no es igual a %2f\n",totalKgAuxiliar);
				retorno = 0;
			}
		}
	}

	return retorno;
}
