/*
 * Pedidos.h
 *
 *  Created on: 28 oct. 2021
 *      Author: Usuario
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "Clientes.h"

typedef struct
{
	int idPedido;
	int idCliente;
	float kilosTotales;
	int estado;
	float HDPE;
	float LDPE;
	float PP;
	int isEmpty;
}ePedido;


int inicializarPedidos(ePedido pedidos[], int tam);
int buscarPedidosEspacioLibre(ePedido pedidos[], int tam);
int cargarUnPedido(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int* ultimaIdPedido);
int mostrarUnPedido(ePedido pedido, int flag);
int mostrarPedidos(ePedido pedidos[], int tam, int flag);
int procesarPlasticos(ePedido pedidos[],int tam);
int cargarPlasticos(ePedido* pedido);
int contadorPedidosPendientes(ePedido pedidos[], int tam, int idCliente);
int contadorPedidosCompletados(ePedido pedidos[], int tam, int idCliente);


#endif /* PEDIDOS_H_ */
