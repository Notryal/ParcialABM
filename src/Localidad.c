#include "Localidad.h"

int ingresarLocalidad(char* localidad)
{
	char auxLocalidad[51];
	int retorno;

	retorno = -1;

		if(
			utn_getString(auxLocalidad,sizeof(auxLocalidad),3,"\nIngrese la localidad: \n", "La localidad ingresada no es valida")==0
		){
			retorno = 0;
			strcpy(localidad,auxLocalidad);
		}

		return retorno;
}



