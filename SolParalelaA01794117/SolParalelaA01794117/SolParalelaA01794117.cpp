// SolParalelaA01794117.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Librerias
#include "pch.h"
#include <iostream>
#include <omp.h>

#define N 5000 // Cantidad de elementos a manejar en los arreglos
#define chunk 500 // Tamaño que tendrán los pedazos de arreglos para que cada hilo creado se encargue de esta cantidad de elementos
#define mostrar 7 // cantidad de datos a imprimir 

void imprimeArreglo(float *d); // función para imprimer arreglos

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n"; 
	float a[N], b[N], c[N]; //Creación de arreglos a, b y c, arreglos a y b serán el resultado de un calculo y c será el arreglo donde se almacene el resultado de los arreglos anteriores
	int i;

	for (i = 0; i < N; i++)
	{
		a[i] = (i - 1.5) * 10; //definición de arreglo a
		b[i] = (i + 3) * 3.7; // definición de arreglo b
	}
	int pedazos = chunk;

	#pragma omp parallel for \
	shared(a, b, c, pedazos) private(i) \
	schedule(static, pedazos) // definición estática de planificación

	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];


	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);
}

void imprimeArreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
