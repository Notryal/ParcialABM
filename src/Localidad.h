#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include "input.h"


typedef struct{
	char localidad[51];
}eLocalidad;

/**
 * @fn int ingresarLocalidad(char*)
 * @brief permite ingresar la localidad
 *
 * @pre
 * @post
 * @param localidad puntero caracter para localidad
 * @return -1 algo salio mal 0 todo bien
 */
int ingresarLocalidad(char* localidad);



#endif /* LOCALIDAD_H_ */
