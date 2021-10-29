#ifndef ECLIENTES_H_
#define ECLIENTES_H_

#define PENDIENTE 0
#define COMPLETADO 1
#define EMPTY 0
#define FULL 1
#define BAJA -1


#include "input.h"
#include "Localidad.h"

typedef struct
{
	int idCliente;
	char empresa[51];
	char cuit[14];
	char direccion[200];
	eLocalidad localidad;
	int isEmpty;
}eCliente;

#endif
/**
 * @fn int InicializarClientes(eCliente[], int)
 * @brief
 *
 * @pre
 * @post
 * @param clientes
 * @param tam
 * @return
 */
int inicializarClientes(eCliente clientes[], int tam);

/***
 * @fn int InicializarClientes(eCliente[], int)
 * @brief Inicializa el campo "isEmpty" de los clientes en 0 (EMPTY)
 *
 * @param clientes es el Array de clientes
 * @param tam es el tamano del array
 * @return Retorna -1 si algo salio mal, 0 si esta todo bien
 */
int cargarUnCliente(eCliente clientes[], int tam, int* ultimaIdIngresada);

/**
 * @fn int BuscarEspacioLibre(eCliente[], int)
 * @brief
 *
 * @pre
 * @post
 * @param clientes
 * @param tam
 * @return
 */
int buscarEspacioLibre(eCliente clientes[], int tam);
/**
 * @fn int IngresarUnCliente(eCliente*)
 * @brief
 *
 * @pre
 * @post
 * @param cliente
 * @return
 */
int ingresarUnCliente(eCliente* cliente);

int getDireccion(char* direccion);

int mostrarClientes(eCliente* cliente, int tam);
int mostrarUnCliente(eCliente cliente);
int fullCliente(eCliente clientes[], int tam);

int modificarCliente(eCliente clientes[], int tam, int id);
int buscarClienteId(eCliente clientes[], int tam, int id);

int eliminarCliente(eCliente clientes[], int tam, int id);

int mostrarClientePedido(eCliente clientes[], int tam, int idCliente);
int mostrarClientesEliminados(eCliente clientes[], int tam, int id);
