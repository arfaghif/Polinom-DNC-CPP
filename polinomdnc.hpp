#ifndef POLINOMDNC_HPP
#define POLINOMDNC_HPP
#include "polinom.hpp"

class PolinomDnC : public Polinom {
public:
    //Konstruktor
	PolinomDnC();
    //Membuat polinomdnc dengan derajat 0, nilai konstanta 0
    PolinomDnC(int d);
    //Membuat polinomdnc dengan derajat d, nilai koefesien dipilih acak dari bilangan bulat pada rentang -100 hingga 100 
    PolinomDnC(int d, int* dat);
    //Membuat polinomdnc dengan derajat d dan data seluruh koefesien dat
    
    //Copy Konstruktor
    PolinomDnC(const PolinomDnC&);

    //Operator
    PolinomDnC& operator=(const PolinomDnC&);//Operator =, meng-copy polinomdnc
    PolinomDnC operator+(const PolinomDnC&);// Operator +, Menambahkan dua polinomdnc
    PolinomDnC operator-(const PolinomDnC&);// Operator -, Mengurangi polinomdnc ini dengan polinomdnc masukan
    PolinomDnC operator*(const PolinomDnC&);// Operator *, Mengalikan polinom secara DIVIDE AND CONQUER
    
    //Fungsi kawan
    friend PolinomDnC Geser(const PolinomDnC& P, int n);//Mengembalikan Polinomdnc P yang sudah digeser pangkatnya sebanyak n
    friend void splitP (const PolinomDnC& P, PolinomDnC* P1, PolinomDnC* P2); // Membagi polinomdnc menjadi dua bagian berderajat sama
    

};




#endif