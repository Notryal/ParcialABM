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
 * @brief Inicializa el array de clientes
 *
 * @pre
 * @post
 * @param clientes Array clientes
 * @param tam tamano del array
 * @return -1 salio todo mal 0 todo bien
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
 * @brief busca un espacio libre en el array clientes
 *
 * @pre
 * @post
 * @param clientes es el Array de clientes
 * @param tam es el tamano del array
 * @return -1 salio todo mal 0 todo bien
 */
int buscarEspacioLibre(eCliente clientes[], int tam);
/**
 * @fn int IngresarUnCliente(eCliente*)
 * @brief permite ingresar datos de un cliente
 *
 * @pre
 * @param clientes es el Array de clientes
 * @param tam es el tamano del array
 * @return -1 salio todo mal 0 todo bien
 */
int ingresarUnCliente(eCliente* cliente);

/**
 * @fn int getDireccion(char*)
 * @brief permite ingresar altura y direccion
 *
 * @pre
 * @post
 * @param direccion datos del cliente
 * @return -1 salio todo mal 0 todo bien
 */
int getDireccion(char* direccion);

/**
 * @fn int mostrarClientes(eCliente*, int)
 * @brief muestra todos los clientes con datos
 *
 * @pre
 * @post
 * @param clientes es el Array de clientes
 * @param tam es el tamano del array
 * @return -1 salio todo mal 0 todo bien
 */
int mostrarClientes(eCliente* cliente, int tam);

/**
 * @fn int mostrarUnCliente(eCliente)
 * @brief muestra los datos de un solo cliente
 *
 * @pre
 * @post
 * @param cliente array de cliente de una posicion
 * @return -1 salio todo mal 0 todo bien
 */
int mostrarUnCliente(eCliente cliente);

/**
 * @fn int fullCliente(eCliente[], int)
 * @brief verifica que el espacio de un cliente tenga datos
 *
 * @pre
 * @post
 * @param clientes es el Array de clientes
 * @param tam es el tamano del array
 * @return -1 salio todo mal 0 todo bien
 */
int fullCliente(eCliente clientes[], int tam);

/**
 * @fn int modificarCliente(eCliente[], int, int)
 * @brief modifica la direccion y localidad de un cliente
 *
 * @pre
 * @post
 * @param clientes es el Array de clientes
 * @param tam es el tamano del array
 * @param id id de cliente
 * @return -1 salio todo mal 0 todo bien
 */
int modificarCliente(eCliente clientes[], int tam, int id);

/**
 * @fn int buscarClienteId(eCliente[], int, int)
 * @brief busca a un por su ID y valida que este ocupado
 *
 * @pre
 * @post
 * @param clientes es el Array de clientes
 * @param tam es el tamano del array
 * @param id id de cliente
 * @return -1 salio todo mal 0 todo bien
 */
int buscarClienteId(eCliente clientes[], int tam, int id);

/**
 * @fn int eliminarCliente(eCliente[], int, int)
 * @brief da de baja a un cliente
 *
 * @pre
 * @post
 * @param clientes es el Array de clientes
 * @param tam es el tamano del array
 * @param id id de cliente
 * @return -1 salio todo mal 0 todo bien
 */
int eliminarCliente(eCliente clientes[], int tam, int id);

/**
 * @fn int mostrarClientePedido(eCliente[], int, int)
 * @brief muestra los clientes con pedido
 *
 * @pre
 * @post
 * @param clientes es el Array de clientes
 * @param tam es el tamano del array
 * @param id id de cliente
 * @return -1 salio todo mal 0 todo bien
 */
int mostrarClientePedido(eCliente clientes[], int tam, int idCliente);

/**
 * @fn int mostrarClientesEliminados(eCliente[], int, int)
 * @brief Muestra todos los clientes dados de baja
 *
 * @pre
 * @post
 * @param clientes array clientes
 * @param tam tamano del array clientes
 * @param id id de los clientes
 * @return -1 salio todo mal 0 todo bien
 */
int mostrarClientesEliminados(eCliente clientes[], int tam, int id);
