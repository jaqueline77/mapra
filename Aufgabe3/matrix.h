/***********************************************
 *  Name        : matrix.h                      *
 *  Verwendung  : Header zu Matrixklasse        *
 *  Autor       : Emma Ahrens, Jaqueline Reuter *
 *  Datum       : Nov '96 - Mai '00             *
 *  Aktualisiert: K. Brix, Apr '07              *
 *                Y. Zhang, Feb '14             *
 *                F. Gruber, Apr '16            *
 ***********************************************/


#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>
#include <vector>
#include <string>

class Vektor;

class Matrix
{
  private:
    std::vektor<Vektor> Matx;                            // vektor=Breite, Vektor=Laenge //Daten
    
  public:
    explicit Matrix (size_t, size_t)                     //Konstruktor mit Laenge und Breite
    ~Matrix () {};                                       //Destruktor
    Matrix (const Matrix&);                              //Kopierkonstruktor
    
    double& operator () (size_t, size_t);                // Zugriff auf Einträge der Matrix
    double operator () (size_t, size_t) const;           // Zugriff falls Matrix const
    
    
    Matrix& operator = (const Matrix&);                  // Zuweisung
    Matrix& operator += (const Matrix&);
    Matrix& operator -= (const Matrix&);
    Matrix& operator *= (const Matrix&);
    Matrix& operator *= (const double);
    Vektor& operator *= (const Vektor&);
    Matrix& operator /= (const double);
    
    Matrix& ReDim (size_t, size_t);
    size_t Laenge () { return Matx[0].Laenge(); }
    size_t Breite () { return Matx.size(); }
    double Norm2 () const;
    double NormMax() const;
    
    static void MatxFehler (const std::string& str);
    
    friend Matrix operator + (const Matrix&, const Matrix&);
    friend Matrix operator - (const Matrix&, const Matrix&);
    friend Matrix operator * (const double, const Matrix&);
    friend Matrix operator * (const Matrix&, const double);
    friend Matrix operator * (const Matrix&, const Matrix&);
    friend Vektor operator * (const Matrix&, const Vektor&);
    friend Vektor operator * (const Vektor&, const Matrix&);
    friend Matrix operator / (const Matrix&, const double);
    
    friend bool operator == (const Matrix&, const Matrix&);
    friend bool operator != (const Matrix&, const Matrix&);
    
    
    
    
    
    
};




#endif /* matrix_hpp */
