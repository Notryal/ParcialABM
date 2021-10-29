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

/**
 * @fn int inicializarPedidos(ePedido[], int)
 * @brief inicializa todo el array de pedidos
 *
 * @pre
 * @post
 * @param pedidos array de pedidos
 * @param tam tamano del array pedidos
 * @return 0 todo bien -1 algo salio mal
 */
int inicializarPedidos(ePedido pedidos[], int tam);

/**
 * @fn int buscarPedidosEspacioLibre(ePedido[], int)
 * @brief busca un espacio libre en array de pedidos
 *
 * @pre
 * @post
 * @param pedidos array de pedidos
 * @param tam tamano del array pedidos
 * @return 0 todo bien -1 algo salio mal
 */
int buscarPedidosEspacioLibre(ePedido pedidos[], int tam);

/**
 * @fn int cargarUnPedido(ePedido[], int, eCliente[], int, int*)
 * @brief
 *
 * @pre
 * @post
 * @param pedidos array de pedidos
 * @param tam tamano del array pedidos
 * @param clientes array de clientes
 * @param tamClientes tamano de array clientes
 * @param ultimaIdPedido ultimo pedido generado
 * @return 0 todo bien -1 algo salio mal
 */
int cargarUnPedido(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int* ultimaIdPedido);

/**
 * @fn int mostrarUnPedido(ePedido, int)
 * @brief imprime los pedidos pendientes o completados de un cliente
 *
 * @pre
 * @post
 * @param pedido array de pedidos
 * @param flag bandera para mostrar pedido completado o pendiente
 * @return 0 todo bien -1 algo salio mal
 */
int mostrarUnPedido(ePedido pedido, int flag);

/**
 * @fn int mostrarPedidos(ePedido[], int, int)
 * @brief muestra todos los pedidos
 *
 * @pre
 * @post
 * @param pedido array de pedidos
 * @param tam tamano del array pedidos
 * @param flag bandera para mostrar pedido completado o pendiente
 * @return 0 todo bien -1 algo salio mal
 */
int mostrarPedidos(ePedido pedidos[], int tam, int flag);

/**
 * @fn int procesarPlasticos(ePedido[], int)
 * @brief llena un array con datos de los plasticos
 *
 * @pre
 * @post
 * @param pedido array de pedidos
 * @param tam tamano del array pedidos
 * @return 0 todo bien -1 algo salio mal
 */
int procesarPlasticos(ePedido pedidos[],int tam);

/**
 * @fn int cargarPlasticos(ePedido*)
 * @brief permite ingresar las cantidades de plasticos
 *
 * @pre
 * @post
 * @param pedido puntero de pedidos
 * @return 0 todo bien -1 algo salio mal
 */
int cargarPlasticos(ePedido* pedido);

/**
 * @fn int contadorPedidosPendientes(ePedido[], int, int)
 * @brief cuenta todos los pedidos pendientes
 *
 * @pre
 * @post
 * @param pedidos array de pedidos
 * @param tam tamano de array pedidos
 * @param idCliente id de cliente ingresado
 * @return 0 todo bien -1 algo salio mal
 */
int contadorPedidosPendientes(ePedido pedidos[], int tam, int idCliente);

/**
 * @fn int contadorPedidosCompletados(ePedido[], int, int)
 * @brief cuenta todos los pedidos completados
 *
 * @pre
 * @post
 * @param pedidos array de pedidos
 * @param tam tamano de array pedidos
 * @param idCliente id de cliente ingresado
 * @return 0 todo bien -1 algo salio mal
 */
int contadorPedidosCompletados(ePedido pedidos[], int tam, int idCliente);


#endif /* PEDIDOS_H_ */
