#ifndef INFORMES_H_
#define INFORMES_H_

#include "Clientes.h"
#include "Pedidos.h"

int informeClientesPedidosPendientes(eCliente clientes[], int tamClientes, ePedido pedidos[], int tamPedidos, int ultimoPedido);
int informePedidosPendientes(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido);
int informePedidosCompletados(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido);
int informePedidosPendientesLocalidad(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido);
int informePromedioPP(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);
int informeClientesMayorPendientes(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);
int informesClientesMayorCompletados(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);


#endif /* INFORMES_H_ */
