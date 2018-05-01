#include "student.h"

// Eingabeoperator ">>"
std::istream& operator>> ( std::istream& s, Student& a)
{
    s >> a.Vorname >> a.Nachname >> a.MatNr >> a.Note;
    return s;
}

// Ausgabeoperator "<<"
std::ostream& operator<< ( std::ostream& s, const Student& a)
{
	s << a.Vorname << " " << a.Nachname << " " << a.MatNr << " " << a.Note << std::endl;
	return s;
}

// Vergleichsoperator "<"
bool operator< ( const Student& s1, const Student& s2)
{
	if (s1.Nachname < s2.Nachname) {
		return true;
	} else if (s1.Nachname == s2.Nachname) {
		if (s1.Vorname < s2.Vorname) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

// Vergleichsoperatoren "==" bzw. "!="
bool operator== ( const Student& s1, const Student& s2)
{
	if (!(s1 < s2) && !(s2 < s1)) {
		return true;
	} else {
		return false;
	}
}

bool operator!= ( const Student& s1, const Student& s2)
{
	if ((s1 < s2) || (s2 < s1)) {
		return true;
	} else {
		return false;
	}
}
