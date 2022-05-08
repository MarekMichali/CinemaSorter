/** @file */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "cinema.h"

/** Funkcja liczy "wagê" na podstawie daty i godziny, która jest wykorzystywana do sortowania.
@param date data seansu potrzebna do obliczenia wagi
@param hour godzina seansu potrzebna do obliczenia wagi
@return waga
*/
int calculateWeight(std::string date, std::string hour);

/** Funkcja usuwa pierwszy element listy jednokierunkowej.
@param g wskaŸnik na pocz¹tek listy jednokierunkowej 
*/
void removeFirst(cinema*& g); 

/** Funkcja odczytuje seanse z pliku, którego nazwa podana jest jako parametr i dodaje je do listy jednokierunkowej od najwczeœniejszego.
@param dataFile nazwa pliku, z którego maj¹ zostaæ odczytane seanse
@param g wskaŸnik na pocz¹tek listy jednokierunkowej
*/
void addSort(std::string dataFile, cinema*& g);

/** Funkcja zapisuje elementy z listy jednokierunkowej do oddzielnych plików txt na podstawie nazwy kina i zwalnia pamiêæ.
@param g wskaŸnik na pocz¹tek listy jednokierunkowej
*/
void save(cinema*& g);

#endif
