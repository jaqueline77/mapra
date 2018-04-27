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

	printArray(feld, laenge);

	while (start < end) {
		while ((feld[start] < pivot) && (start < end)) {
			start += 1;
		}
		while ((feld[end] >= pivot) && (end > start)) {
			end -= 1;
		}
		tausche(feld, start, end);
		start < originEnd ? start += 1 : start = originEnd;
		end > originStart ? end -= 1 : end = originStart;

		std::cout << start << " " << end << "    ";
		printArray(feld, laenge);
	}
	if ((start > originStart) && (start < originEnd) && (feld[start-1] < pivot)) {
		end = start - 1;
		start = start + 1;
	}
	tausche(feld, start-1, pivotIndex);

	std::cout << start << " " << end << "        ";
	printArray(feld, laenge);
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

void mergeSortRecursive(unsigned int * &feld, size_t laenge) {
	unsigned int * left [laenge/2], right [laenge - (laenge/2)];
	std::copy(feld, feld+(laenge/2)-1, left);
	std::copy(feld+(laenge/2), feld+(laenge-1), right);

	printArray(feld, laenge);
}

void mergeSort(unsigned int * &feld, size_t laenge) {
	mergeSortRecursive(feld, laenge);
}

int main() {
	unsigned int * feld;
	size_t laenge = 10;

	for (int i = 1; i <= AnzahlBeispiele; i++) {
		start(i, laenge, feld);
		//quickSort(feld, laenge, true);
		mergeSort(feld, laenge);
		ergebnis(feld);
	}

	return 0;
}
