/** @file  */

#ifndef CINEMA_H
#define CINEMA_H
#include <string>

/** Lista jednokierunkowa. */
struct cinema {
	std::string cinemaName;	///< nazwa kina
	std::string movieName;	///< nazwa filmu
	std::string date;	///< data seansu
	std::string hour;	///< godzina sensu
	int weight;	///< waga seansu u¿ywana do sortowania
	cinema* next;	///< wskaŸnik na nastêpny element listy jednokierunkowej
};

#endif
