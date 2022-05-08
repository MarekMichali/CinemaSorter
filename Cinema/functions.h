/** @file */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "cinema.h"

/** Funkcja liczy "wag�" na podstawie daty i godziny, kt�ra jest wykorzystywana do sortowania.
@param date data seansu potrzebna do obliczenia wagi
@param hour godzina seansu potrzebna do obliczenia wagi
@return waga
*/
int calculateWeight(std::string date, std::string hour);

/** Funkcja usuwa pierwszy element listy jednokierunkowej.
@param g wska�nik na pocz�tek listy jednokierunkowej 
*/
void removeFirst(cinema*& g); 

/** Funkcja odczytuje seanse z pliku, kt�rego nazwa podana jest jako parametr i dodaje je do listy jednokierunkowej od najwcze�niejszego.
@param dataFile nazwa pliku, z kt�rego maj� zosta� odczytane seanse
@param g wska�nik na pocz�tek listy jednokierunkowej
*/
void addSort(std::string dataFile, cinema*& g);

/** Funkcja zapisuje elementy z listy jednokierunkowej do oddzielnych plik�w txt na podstawie nazwy kina i zwalnia pami��.
@param g wska�nik na pocz�tek listy jednokierunkowej
*/
void save(cinema*& g);

#endif
