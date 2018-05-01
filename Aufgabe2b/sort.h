/*
 * Name: sort.h
 * Verwendung: Beinhaltet die typunabhaengigen Sortieralgorithmen fuer Aufgabe 2b
 * Autor: Emma Ahrens und Jaqueline Reuter
 * Datum: 28.4.2018
 * Sprache: C++
 */
 
#ifndef SORT
#define SORT

#include <iostream>
#include <climits>
#include "unit.h"

using std::size_t;

template<typename T>
void tausche(T * &feld, size_t i, size_t j) {
	T tmp = feld[i];
	feld[i] = feld[j];
	feld[j] = tmp;
}

template<typename T>
void bubbleSort(T * &feld, size_t laenge) {
	for(int i=0; i<laenge; i++) {
		for(int j=laenge-1; j>i; j--) {
			if(feld[j]<feld[j-1]) {
				tausche(feld, j, j-1);
			}
		}	
	}
}

template<typename T>
void selectionSort(T * &feld, size_t laenge) {
	for(int i=1; i<laenge; i++) {
		for(int j=i; j>=1; j--) {		
			if(feld[j]<feld[j-1]) {
				tausche(feld, j, j-1);
			}
		}
	}
}

template<typename T>
void splitArray(T * feld, T * &left, T * &right, size_t laenge, size_t &laengeLeft, size_t &laengeRight) {
	laengeLeft = laenge/2, laengeRight = laenge - laengeLeft;
	left = new T [laengeLeft];
	right = new T [laengeRight];

	for (int i = 0; i < laengeLeft; i++) {
		left[i] = feld[i];
	}
	for (int i = 0; i < laengeRight; i++) {
		right[i] = feld[i + laengeLeft];
	}
}

template<typename T>
void mergeArray(T * &feld, T * left, T *  right, size_t laenge, size_t laengeLeft, size_t laengeRight) {
	size_t iLeft = 0, iRight = 0;

	for (int i = 0; i < laenge; i++) {
		if (iLeft < laengeLeft) {
			if (iRight < laengeRight) {
				if (right[iRight] < left[iLeft]) {
					feld[i] = right[iRight];
					iRight++;
				} else {
					feld[i] = left[iLeft];
					iLeft++;
				}
			} else {
				feld[i] = left[iLeft];
				iLeft++;
			}
		} else if (iRight < laengeRight) {
			feld[i] = right[iRight];
			iRight++;
		}
	}
}

template<typename T>
void mergeSort(T * feld, size_t laenge) {
	if (laenge > 1) {
		T * left, * right;
		size_t laengeLeft = 0, laengeRight = 0;

		splitArray(feld, left, right, laenge, laengeLeft, laengeRight);
		mergeSort(left, laengeLeft);
		mergeSort(right, laengeRight);

		mergeArray(feld, left, right, laenge, laengeLeft, laengeRight);

		delete [] left, right;
	}
}

#endif
