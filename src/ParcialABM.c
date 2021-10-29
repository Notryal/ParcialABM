/*
 ============================================================================
 Name        : ParcialABM.c
 Author      : Ayrton
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "Pedidos.h"
#include "Informes.h"

#define TAMCLIENTES 100
#define TAMPEDIDOS 1000

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int retornoAuxiliar;
	int ultimaIdCliente;
	int ultimaIdPedido;
	int id;

	eCliente clientes[TAMCLIENTES];
	ePedido pedidos[TAMCLIENTES];

	ultimaIdCliente= 0;
	ultimaIdPedido = 0;

	inicializarClientes(clientes, TAMCLIENTES);
	inicializarPedidos(pedidos, TAMPEDIDOS);
	do
	{
		opcion = -1;

		puts("ABM");
		puts("1. ALTA");
		puts("2. MODIFICAR");
		puts("3. BAJA");
		puts("\n");
		puts("PEDIDOS");
		puts("4. Generar pedidos");
		puts("5. Procesar basura");
		puts("\n");
		puts("INFORMES");
		puts("6. Mostrar clientes con pedidos");
		puts("7. Mostrar pedidos pendientes");
		puts("8. Mostrar pedidos completados");
		puts("9. Mostrar pedidos pendientes por localidad");
		puts("10. Promedio de kilos de PP reciclado por cliente");
		puts("11. Clientes con mas pedidos pendientes");
		puts("12. Clientes con mas pedidos completados");
		puts("13. Clientes dados de baja");
		puts("0 - Salir");


		utn_getInt(&opcion,0,13,0,"\nIngrese una opcion : \n", "Opcion incorrecta");
		switch(opcion)
		{
			case 1:
				retornoAuxiliar = cargarUnCliente(clientes,TAMCLIENTES,&ultimaIdCliente);

				if(retornoAuxiliar == -1)
				{
					puts("\nHay muchos clientes cargados.\n");
				}
				else if(retornoAuxiliar == 0)
				{
					puts("\nNo se pudo ingresar el cliente.\n");
				}else
					{
					puts("\nSe ingreso el cliente exitosamente.\n");
					}
			break;
			case 2:
				retornoAuxiliar = mostrarClientes(clientes,TAMCLIENTES);

				if(retornoAuxiliar == 0)
				{
					puts("\nNo hay clientes.\n");
				}
				else
				{
					utn_getInt(&id,1,100,2,"Ingrese el ID del cliente: ", "Error, intente nuevamente");
					retornoAuxiliar = modificarCliente(clientes, TAMCLIENTES,id);
						if(retornoAuxiliar == 1)
						{
							puts("\nSe modifico el cliente exitosamente.\n");
						}
						else
						{
							puts("\nNo se pudo modificar el cliente.\n");
						}
				}
			break;
			case 3:

				retornoAuxiliar = mostrarClientes(clientes, TAMCLIENTES);

				if(retornoAuxiliar == 0)
				{
					puts("\nNo hay clientes.\n");
				}else{
					utn_getInt(&id,1,100,2,"Ingrese el ID del cliente: ", "Error, intente nuevamente");

					retornoAuxiliar = eliminarCliente(clientes, TAMCLIENTES, id);

					if(retornoAuxiliar == -1)
					{
						puts("\nEl cliente no existe o ya se dio de baja.\n\n");
					}
				}
			break;
			case 4:
				retornoAuxiliar = mostrarClientes(clientes,TAMCLIENTES);

				if(retornoAuxiliar == 0)
				{
					puts("\nNo hay clientes.\n");
				}
				else
				{
					retornoAuxiliar = cargarUnPedido(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, &ultimaIdPedido);

					if(retornoAuxiliar == -1)
					{
						puts("\nEl cliente no existe.\n");
					}
					else if(retornoAuxiliar == 0)
					{
						puts("\nNo se ha podido ingresar el pedido.\n");
					}else
						{
						puts("\nSe ingreso el cliente exitosamente.\n");
						}
					}

			break;
			case 5:
			if(ultimaIdPedido == 0)
			{
				puts("\nNo hay pedidos cargados.\n");
			}
			else
			{
				if(mostrarPedidos(pedidos, TAMPEDIDOS,1) ==-1)
				{
					puts("\nNo hay pedidos a mostrar.\n");
				}
				else
				{
					retornoAuxiliar = procesarPlasticos(pedidos, TAMPEDIDOS);

					if(retornoAuxiliar == -1)
					{
						puts("\nEl total de kg a reciclar no coincide con el total ingresado.\n\n");
					}
					else if (retornoAuxiliar == 0)
					{
						puts("\nNo se pudo procesar el pedido o ya ha sido procesado.\n\n");
					}
					else
					{
						puts("\nEl pedido se proceso correctamente.\n\n");
					}
				}
			}
			break;
			case 6:
				if(informeClientesPedidosPendientes(clientes, TAMCLIENTES, pedidos, TAMPEDIDOS, ultimaIdPedido) == -1)
				{
					puts("\nNo hay clientes cargados.\n\n");
				}
			break;
			case 7:
				retornoAuxiliar = informePedidosPendientes(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimaIdPedido);

				if(retornoAuxiliar == 0)
				{
					puts("\nNo hay pedidos cargados.\n\n");
				}
				else if(retornoAuxiliar == -1)
				{
					puts("\nNo hay pedidos pendientes.\n\n");
				}
			break;
			case 8:
				retornoAuxiliar = informePedidosCompletados(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimaIdPedido);

				if(retornoAuxiliar == -1)
				{
					puts("\nNo hay pedidos cargados.\n");
				}
				else if(retornoAuxiliar == 0)
				{
					puts("\nNo hay pedidos completados.\n");
				}
			break;
			case 9:
				retornoAuxiliar = informePedidosPendientesLocalidad(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimaIdPedido);

				if(retornoAuxiliar == -1)
				{
					puts("\nNo hay pedidos cargados.\n");
				}
				else if(retornoAuxiliar == 0)
				{
					puts("\nNo se encontraron registros con la localidad ingresada.\n");
				}

			break;
			case 10:
				retornoAuxiliar = informePromedioPP(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimaIdCliente, ultimaIdPedido);

				if(retornoAuxiliar == -1)
				{
					puts("\nNo hay pedidos cargados.\n");
				}
				else if(retornoAuxiliar == 0)
				{
					puts("\nNo se encontraron clientes ingresados.\n");
				}

				break;
			case 11:
				retornoAuxiliar = informeClientesMayorPendientes(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimaIdCliente, ultimaIdPedido);

				if(retornoAuxiliar == -1)
				{
					puts("\nNo hay pedidos cargados.\n");
				}
				else if(retornoAuxiliar == 0)
				{
					puts("\nNo se encontraron clientes ingresados.\n");
				}

			break;
			case 12:
				retornoAuxiliar = informeClientesMayorCompletados(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimaIdCliente, ultimaIdCliente);

				if(retornoAuxiliar == -1)
				{
					puts("\nNo hay pedidos cargados.\n");
				}
				else if(retornoAuxiliar == 0)
				{
					puts("\nNo se encontraron clientes ingresados.\n");
				}

			break;
			case 13:
				retornoAuxiliar = mostrarClientes(clientes,TAMCLIENTES);

				if(retornoAuxiliar == 0)
				{
					puts("\nNo hay registro de clientes dados de baja.\n");
				}

			break;


		}

	}while(opcion != 0);

	return EXIT_SUCCESS;
}

