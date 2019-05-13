/*
 * Fichero.cpp
 *
 *  Created on: May 10, 2019
 *      Author: maarten
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cartelera.h"
#include "Fichero.h"
using namespace std;
using namespace cartelera;

Cartelera leerCartelera(char *cine)
{

	Cartelera cart;
	FILE *f;
	char fichero[100];
	int numPelis = 0;

	strcpy(fichero, cine);
	strcat(fichero, "Cartelera.txt");

	f = fopen(fichero, "r");

	//cart.cine = malloc(sizeof(char)*TAMANYO_tit);

	numPelis = (lineasFichero(fichero)-1)/3;
	cart.setNumPelis(numPelis);

	Pelicula *pelis = new Pelicula[numPelis];

	//cart.peliculas = malloc(sizeof(Pelicula)*numPelis);

	char buff[255];
	string buff2 = "";
	double hora=0.0;
	int plazas = 0;
	int numSesiones = 0;

	fscanf(f, " %[^\t\n]s", buff);
	//strcpy(cart.cine, buff);
	buff2 = string(buff);

	cart.setCine(buff2);

	for(int i=0; i<numPelis; i++)
	{
		//cart.peliculas[i].titulo = malloc (sizeof(char)*TAMANYO_tit);
		fscanf(f, " %[^\t\n]s", buff);
		buff2.clear();
		buff2 = string(buff);
		//strcpy(cart.peliculas[i].titulo,buff);
		pelis[i].setTitulo(buff2);

		//cart.peliculas[i].descripcion = malloc (sizeof(char)*TAMANYO_descr);
		fscanf(f, " %[^\t\n]s", buff);
		buff2.clear();
		buff2 = string(buff);
		//strcpy(cart.peliculas[i].descripcion,buff);
		pelis[i].setDesc(buff2);

		fscanf(f, "%d", &numSesiones);

		//cart.peliculas[i].numSesiones = numSesiones;
		pelis[i].setNumSesiones(numSesiones);

		//cart.peliculas[i].sesiones = (Sesion*)malloc (sizeof(Sesion)*numSesiones);
		Sesion *sesiones= new Sesion[numSesiones];

		for(int j=0; j<numSesiones;j++)
		{
			fscanf(f, "%i", &plazas);
			fscanf(f, "%lf", &hora);
			//cart.peliculas[i].sesiones[j].plazas = plazas;
			sesiones[j].setPlazas(plazas);
			sesiones[j].setHora(hora);


		}

		pelis[i].setSesiones(sesiones);

	}

	cart.peliculas = pelis;

	return cart;
}

int lineasFichero(char *fichero)
{
    FILE *fileptr;
    int count_lines = 0;
    char filechar[40], chr;

    fileptr = fopen(fichero, "r");
   //extract character from file and store in chr
    chr = getc(fileptr);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fileptr);
    }
    fclose(fileptr); //close file.

    return count_lines;
}
