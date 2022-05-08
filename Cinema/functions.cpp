#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


int calculateWeight(std::string date, std::string hour) {
	std::stringstream splitDate(date);
	std::stringstream splitHour(hour);
	std::string target;
	int i = 0, year = 0, month = 0, day = 0, hours = 0, minutes = 0, weight = 0;

	while (getline(splitDate, target, '.')) {
		if (i == 0) {
			i++;
			day = stoi(target);
		}
		else if (i == 1) {
			i++;
			month = stoi(target);
		}
		else if (i == 2) {
			i = 0;
			year = stoi(target) - 1800;	
		}
	}
	while (getline(splitHour, target, ':')) {
		if (i == 0) {
			i++;
			hours = stoi(target);
		}
		else if (i == 1) {
			i = 0;
			minutes = stoi(target);
		}
	}
	weight = minutes + hours * 60 + day * 1440 + month * 46100 + year * 600000;
	return weight;
}

void removeFirst(cinema*& g) {
	cinema* tmp;
	tmp = g->next;
	delete g;
	g = NULL;
	g = tmp;
}

void addSort(std::string dataFile, cinema*& g) {
	std::ifstream file(dataFile);
	if (file) {
		std::string data, cinemaName, movieName, date, hour;
		int i = 0, waga = 0;
		g = new cinema;
		cinema* tmp;
		g->next = new cinema;
		g->next->next = NULL;
		g->next->weight = 2147483647;	//maksymalna wartosc int, to bedzie jednoczesnie ostatni element listy

		while (file >> data) {
			if (i == 0) {
				cinemaName = data;
				i++;
			}
			else if (i == 1) {
				movieName = data;
				i++;
			}
			else if (i == 2) {
				date = data;
				i++;
			}
			else if (i == 3) {
				hour = data;
				i = 0;
				waga = calculateWeight(date, hour);	//liczy wage do sortowania
				for (tmp = g; waga > tmp->next->weight; tmp = tmp->next); //sortowanie przez wstawianie, szuka elementu ktory jest wiekszy od tego co chcemy dodac do listy
				cinema* insert = new cinema;
				insert->cinemaName = cinemaName;
				insert->movieName = movieName;
				insert->date = date;
				insert->hour = hour;
				insert->weight = waga;
				insert->next = tmp->next;
				tmp->next = insert;
			}
		}
		removeFirst(g);
		//usuwa ostatni element listy 
		tmp = g;		
		if (tmp->next) {
			while (tmp->next->next)
				tmp = tmp->next;
		}
		
		delete tmp->next;
		tmp->next = NULL;
		file.close();
	}
	else 
		std::cout << "Nie udalo sie otworzyc pliku lub " << dataFile <<  " nie istnieje.";	
}

void save(cinema*& g) {
	while (g) {
		cinema* tmp;
		cinema* tmp2;
		std::string city = g->cinemaName;
		std::ofstream save(city + ".txt");
		save << g->movieName << " " << g->date << " " <<  g->hour << std::endl;
		removeFirst(g);

		while (g) {
			if (g->cinemaName == city) {
				save << g->movieName << " " << g->date << " " << g->hour << std::endl;
				removeFirst(g);
			}
			else {
				tmp = g;
				if (tmp->next == NULL) {
					break;
				}
				int przerw = 0;
				//przesuwa sie po liscie w poszukiwaniu miasta
				while (tmp->next->cinemaName != city) {		
					tmp = tmp->next;
					if (tmp->cinemaName != city && tmp->next == NULL) {
						przerw = 1;
						break;
					}
				}
				if (przerw == 1)
					break;
				//sprawdza czy to jest ostatni element listy
				if (tmp->next->cinemaName == city && tmp->next->next == NULL) { 
					save << tmp->next->movieName << " " << tmp->next->date << " " << tmp->next->hour << std::endl;
					delete tmp->next;
					tmp->next = NULL;
					continue;
				}
				save << tmp->next->movieName << " " << tmp->next->date << " " << tmp->next->hour << std::endl;
				//usuwa element, ktory jest w srodku listy
				tmp2 = tmp->next;	
				tmp->next = tmp2->next;
				delete tmp2;
				tmp2 = NULL;
			}
		}
		save.close();
	}
}
