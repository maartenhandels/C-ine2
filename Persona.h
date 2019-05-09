/*
 * Persona.h
 *
 *  Created on: 9 may. 2019
 *      Author: ALUMNO
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#include <iostream>
#include <string>
using namespace std;

namespace persona
{
	class Persona
	{
	private:
		string nombre, apellido, dni;

	public:
		Persona();
		Persona (string nombre, string apellido, string dni);
		~Persona();

	};
}


#endif /* PERSONA_H_ */