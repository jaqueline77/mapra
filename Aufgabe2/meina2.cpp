/*
 * Name: meina2.cpp
 * Verwendung: Lösung von Aufgabe 2
 * Autor: Emma Ahrens und Jaqueline Reuter
 * Datum: 25.4.2018
 * Sprache: C++
 */

#include "unit.h"
#include <iostream>
#include <algorithm>
#include <climits>

void printArray(unsigned int * feld, size_t echteLaenge) {
	for (int i = 0; i < echteLaenge; i++) {
		std::cout << feld[i] << " ";
	}
	std::cout << std::endl;
}

void heapify(unsigned int * &feld, size_t index, size_t laenge) {
	size_t left = 2*index + 1, right = 2*index + 2;
	size_t biggestIndex = index;
	if ((left < laenge) && (feld[left] > feld[index])) {
		biggestIndex = left;
	}
	if ((right < laenge) && (feld[right] > feld[biggestIndex])) {
		biggestIndex = right;
	}
	if (biggestIndex != index) {
		tausche(feld, index, biggestIndex);
		heapify(feld, biggestIndex, laenge);
	}
}

void buildHeap(unsigned int * &feld, size_t laenge) {
	for (int i = laenge/2; i >= 0; i--) {
		heapify(feld, i, laenge);
	}
}
	
void heapSort(unsigned int * &feld, size_t laenge) {
	buildHeap(feld, laenge);

	while (laenge > 1) {
		tausche(feld, 0, laenge-1);
		laenge = laenge - 1;
		heapify(feld, 0, laenge);
	}
}

size_t medianOfThree(unsigned int * &feld, size_t start, size_t end) {
	size_t result = end;
	size_t middle = (start + end)/2;
	if ((feld[start] < feld[result]) && (feld[middle] < feld[result])) {
		result = middle;
		if (feld[result] < feld[start])	result = start;
	} else if ((feld[start] > feld[result]) && (feld[middle] > feld[result])) {
		result = middle;
		if (feld[result] > feld[start]) result = start;
	}
	return result;
}


void partition(unsigned int * &feld, size_t &start, size_t &end, size_t laenge, bool einfach = true) {
	unsigned int pivot;
	size_t pivotIndex, originStart = start, originEnd = end;
	if (einfach) {
		pivotIndex = end,
		pivot = feld[end];
	} else {
		pivotIndex = medianOfThree(feld, start, end);
		pivot = feld[pivotIndex];
		tausche(feld, pivotIndex, end);
		pivotIndex = end;
	}

	while (start < end) {
		while ((feld[start] < pivot) && (start < end)) {
			start += 1;
		}
		while ((feld[end] >= pivot) && (end > start)) {
			end -= 1;
		}
		tausche(feld, start, end);
	}
	tausche(feld, start, pivotIndex);

	if (start < originEnd) start++;
	if (end > originStart) end--;
}

void quickSortRecursive(unsigned int * &feld, size_t start, size_t end, size_t laenge, bool einfach = true) {
	size_t left = start, right = end;
	if (left < right) {
		partition(feld, left, right, laenge, einfach);
		if (left > right) {
			quickSortRecursive(feld, start, right, laenge, einfach);
			quickSortRecursive(feld, left, end, laenge, einfach);
		}
	}
}

void quickSort(unsigned int * &feld, size_t laenge, bool einfach = true) {
	size_t start = 0, end = laenge-1;
	quickSortRecursive(feld, start, end, laenge, einfach);
}

void splitArray(unsigned int *feld, unsigned int * &left, unsigned int * &right, size_t laenge, size_t &laengeLeft, size_t &laengeRight) {
	laengeLeft = laenge/2, laengeRight = laenge - laengeLeft;
	left = new unsigned int [laengeLeft];
	right = new unsigned int [laengeRight];

	for (int i = 0; i < laengeLeft; i++) {
		left[i] = feld[i];
	}
	for (int i = 0; i < laengeRight; i++) {
		right[i] = feld[i + laengeLeft];
	}
}

void mergeArray(unsigned int * &feld, unsigned int * left, unsigned int *  right, size_t laenge, size_t laengeLeft, size_t laengeRight) {
	size_t iLeft = 0, iRight = 0;

	for (int i = 0; i < laenge; i++) {
		unsigned int vLeft, vRight;
		if (iLeft < laengeLeft) {
			vLeft = left[iLeft];
		} else {
			vLeft = UINT_MAX;
		}

		if (iRight < laengeRight) {
			vRight = right[iRight];
		} else {
			vRight = UINT_MAX;
		}

		if (vRight < vLeft) {
			feld[i] = vRight;
			iRight++;
		} else {
			feld[i] = vLeft;
			iLeft++;
		}
	}
}

void mergeSort(unsigned int * &feld, size_t laenge) {
	if (laenge > 1) {
		unsigned int * left, * right;
		size_t laengeLeft = 0, laengeRight = 0;

		splitArray(feld, left, right, laenge, laengeLeft, laengeRight);
		mergeSort(left, laengeLeft);
		mergeSort(right, laengeRight);

		mergeArray(feld, left, right, laenge, laengeLeft, laengeRight);

		delete left, right;
	}
}

int main() {
	unsigned int * feld;
	size_t laenge;

	std::cout << "HEAP SORT" << std::endl;
	for (int i = 1; i <= AnzahlBeispiele; i++) {
		laenge = 10000;

		start(i, laenge, feld);
		heapSort(feld, laenge);
		ergebnis(feld);
	}

	std::cout << std::endl << std::endl << "QUICK SORT" << std::endl;
	for (int i = 1; i <= AnzahlBeispiele; i++) {
		laenge = 10000;

		start(i, laenge, feld);
		quickSort(feld, laenge);
		ergebnis(feld);
	}

	std::cout << std::endl << std::endl << "QUICK SORT MEDIAN OF THREE" << std::endl;
	for (int i = 1; i <= AnzahlBeispiele; i++) {
		laenge = 10000;

		start(i, laenge, feld);
		quickSort(feld, laenge, false);
		ergebnis(feld);
	}

	std::cout << std::endl << std::endl << "MERGE SORT" << std::endl;
	for (int i = 1; i <= AnzahlBeispiele; i++) {
		laenge = 10000;

		start(i, laenge, feld);
		mergeSort(feld, laenge);
		ergebnis(feld);
	}

	return 0;
}
