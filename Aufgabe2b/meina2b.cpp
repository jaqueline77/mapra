/*
 * Name: meina2b.cpp
 * Verwendung: Lösung von Aufgabe 2
 * Autor: Emma Ahrens und Jaqueline Reuter
 * Datum: 28.4.2018
 * Sprache: C++
 */
 
#include "student.h"
#include "sort.h"
#include <iostream>

int main() {
	Student emma;
	emma.Vorname = "Emma";
	emma.Nachname = "Ahrens";
	emma.MatNr = 371063;
	emma.Note = 1.0;

	Student flo;
	flo.Vorname = "Florian";
	flo.Nachname = "Behrens";
	flo.MatNr = 356348;
	flo.Note = 1.0;

	std::cout << flo << emma << (emma < flo) << std::endl << std::endl;

	Student * feld = new Student [2];
	feld[0] = flo;
	feld[1] = emma;

	size_t laenge = 2;

	selectionSort(feld, laenge);

	for (int i = 0; i < 2; i++) {
		std::cout << feld[i];
	}

	delete [] feld;
	return 0;
}
