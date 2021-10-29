#ifndef INFORMES_H_
#define INFORMES_H_

#include "Clientes.h"
#include "Pedidos.h"

/**
 * @fn int informeClientesPedidosPendientes(eCliente[], int, ePedido[], int, int)
 * @brief Imprime todos los clientes con pedidos pendientes
 *
 * @param clientes Array de clientes
 * @param tamClientes es el tamano del Array de clientes
 * @param pedidos Array de pedidos
 * @param tamPedidos tamano de Array de pedidos
 * @param ultimoPedido es el ultimo pedido generado
 * @return devuelve 1 hay pedidos -1 no hay pedidos
 */
int informeClientesPedidosPendientes(eCliente clientes[], int tamClientes, ePedido pedidos[], int tamPedidos, int ultimoPedido);

/**
 * @fn int informePedidosPendientes(ePedido[], int, eCliente[], int, int)
 * @brief Imprime los pedidos pendientes junto con
 * Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar del cliente.
 *
 * @param pedidos Array de pedidos
 * @param tamPedidos tamano de Array de pedidos
 * @param clientes Array de clientes
 * @param tamClientes es el tamano del Array de clientes
 * @param ultimoPedido es el ultimo pedido generado
 * @return devuelve 1 hay pedidos -1 no hay pedidos
 */
int informePedidosPendientes(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido);

/**
 * @fn int informePedidosCompletados(ePedido[], int, eCliente[], int, int)
 * @brief Imprime los pedidos completados junto con
 * Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar del cliente.
 *
 * @param pedidos Array de pedidos
 * @param tamPedidos tamano de Array de pedidos
 * @param clientes Array de clientes
 * @param tamClientes es el tamano del Array de clientes
 * @param ultimoPedido es el ultimo pedido generado
 * @return devuelve 1 hay pedidos -1 no hay pedidos
 */
int informePedidosCompletados(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido);

/**
 * @fn int informePedidosPendientesLocalidad(ePedido[], int, eCliente[], int, int)
 * @brief Imprime los pedidos pendientes por localidad
 *
 * @param pedidos Array de pedidos
 * @param tamPedidos tamano de Array de pedidos
 * @param clientes Array de clientes
 * @param tamClientes es el tamano del Array de clientes
 * @param ultimoPedido es el ultimo pedido generado
 * @return devuelve 1 hay pedidos -1 no hay pedidos
 */
int informePedidosPendientesLocalidad(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido);

/**
 * @fn int informePromedioPP(ePedido[], int, eCliente[], int, int, int)
 * @brief Calcula e imprime el promedio de plastico PP de todos los clientes
 *
 * @param pedidos Array de pedidos
 * @param tamPedidos tamano de Array de pedidos
 * @param clientes Array de clientes
 * @param tamClientes es el tamano del Array de clientes
 * @param ultimoPedido es el ultimo pedido generado
 * @param ultimoCliente es el ultimo cliente ingresado
 * @return devuelve 1 si esta bien  -1 algo salio mal
 */
int informePromedioPP(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);

/**
 * @fn int informeClientesMayorPendientes(ePedido[], int, eCliente[], int, int, int)
 * @brief Imprime el cliente con mayor cantidad de pedidos pendiente
 *
 * @param pedidos Array de pedidos
 * @param tamPedidos tamano de Array de pedidos
 * @param clientes Array de clientes
 * @param tamClientes es el tamano del Array de clientes
 * @param ultimoPedido es el ultimo pedido generado
 * @param ultimoCliente es el ultimo cliente ingresado
 * @return devuelve 1 si esta bien  -1 algo salio mal
 */
int informeClientesMayorPendientes(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);

/**
 * @fn int informeClientesMayorCompletados(ePedido[], int, eCliente[], int, int, int)
 * @brief Imprime el cliente con mayor cantidad de pedidos completados
 *
 * @param pedidos Array de pedidos
 * @param tamPedidos tamano de Array de pedidos
 * @param clientes Array de clientes
 * @param tamClientes es el tamano del Array de clientes
 * @param ultimoPedido es el ultimo pedido generado
 * @param ultimoCliente es el ultimo cliente ingresado
 * @return devuelve 1 si esta bien  -1 algo salio mal
 */
int informeClientesMayorCompletados(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);


#endif /* INFORMES_H_ */
