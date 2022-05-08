#include <iostream>
#include <string>
#include "functions.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>





int main(int howMuch, char** params) {
	{
		cinema* g = NULL;
		std::string dataFile;
		if (howMuch == 1) {
			std::cout << "Nie podano zadnej nazwy pliku. Podaj ja jako parametr programu";
			return 0;
		}
		dataFile = params[1];
		addSort(dataFile, g);
		save(g);
		std::cout << "Zakonczono dzialanie programu";
	}
	_CrtDumpMemoryLeaks();
	return 0;

}