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
#include <fstream>
#include "unit.h"

using std::vector;
using std::string;

template<typename T>
void einlesen(std::ifstream& ifs, vector<T>& v) {
	while (!ifs.eof()) {
		T element;
		ifs >> element;
		if (!ifs.fail()) v.push_back(element);
	}
}

template<typename T>
void ausgeben(std::ostream& os, const vector<T>& v) {
	for (int i = 0; i < v.size(); i++) {
		os << v[i] << "\n";
	}
	os << "\n";
}

int main() {
	vector<Student> students;
	vector<double> doubles;
	vector<string> strings;

	std::ifstream ifs;
	ifs.open("studenten.txt");
	einlesen(ifs, students);
	ifs.close();

	ifs.open("strings.txt");
	einlesen(ifs, strings);
	ifs.close();

	ifs.open("doubles.txt");
	einlesen(ifs, doubles);
	ifs.close();

	char version = 'M';
	std::cout << "Bubblesort (B), Auswahlsortieren (A) oder Mergesort (M)? ";
	std::cin >> version;

	switch (version) {
		case 'B':
			bubbleSort(&students[0], students.size());
			bubbleSort(&strings[0], strings.size());
			bubbleSort(&doubles[0], doubles.size());
			break;
		case 'A':
			selectionSort(&students[0], students.size());
			selectionSort(&strings[0], strings.size());
			selectionSort(&doubles[0], doubles.size());
			break;
		case 'M':
		default:
			mergeSort(&students[0], students.size());
			mergeSort(&strings[0], strings.size());
			mergeSort(&doubles[0], doubles.size());
			break;
	}
	
	ausgeben(std::cout, students);
	ausgeben(std::cout, strings);
	ausgeben(std::cout, doubles);

	ergebnis(students);
	ergebnis(strings);
	ergebnis(doubles);
}
