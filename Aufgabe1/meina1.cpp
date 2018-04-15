/***********************************************************
*  Name       : meina1.cpp                                 *
*  Verwendung : Loesung der ersten Praktikumsaufgabe,      *
*               Nullstellen eines quadratischen Polynoms   *
*  Autor      : Jaqueline Reuter und Emma Ahrens           *
*  Datum      : 13.04.2018                                 *
*  Sprache    : C++                                        *
***********************************************************/

#include "unit.h"
#include <cfloat>
#include <cmath>

using namespace std;

// ===== Hauptprogramm =====

bool isComplexCalculateR(double p, double q, double &r) {
	bool result = false;
	
	if (abs(p) > 2*sqrt(DBL_MAX)) {
		r = 0.25 - (q/p)/p;
		if (r < 0) {
			result = true;
			r = abs(p)*sqrt(-r);
		} else {
			r = abs(p)*sqrt(r);
		}
	} else {
		r = pow(p/2,2) - q;
		if (r < 0) {
			result = true;
			r = sqrt(-r);
		} else r = sqrt(r);
	}
	
	return result;
}

void ErgebnisTwoRealRoots(double x, double y) {
	if (abs(x) > abs(y)) Ergebnis(2, false, x, y);
	else Ergebnis(2, false, y, x);
}

int main()
{
	double a, b, c;

	for (int i = 1; i < AnzahlBeispiele; i++) {
		Start(i, a, b, c);
		
		if (a == 0) { //lineares Polynom
			if (b == 0) { //konstantes Polynom
				if (c != 0) {
					Ergebnis(0);
				} else {
					Ergebnis(Unendlich);
				}
			} else {
				Ergebnis(1, false, -(c/b));
			}
		} else { //nichtlineares Polynom
			// p-q-Form bestimmen
			double p = b/a, q = c/a, r = 0;
			
			bool x2first = true;
			if (p < 0) { //p<0, also explizite Berechnung von x1
				x2first = false;
			}
				
			//Berechne r und sage, ob komplex
			if (isComplexCalculateR(p, q, r)) {
				Ergebnis(2, true, -(p/2), r);
			} else {
				double y;
				x2first ? y = -(p/2) - r : y = -(p/2) + r;
				if (y == 0) Ergebnis(1, false, y);
				else {
					double x = q/y;
					ErgebnisTwoRealRoots(x, y);
				}
			}
		}
	}
	
	return 0;
}
