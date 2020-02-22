#ifndef POLINOM_HPP
#define POLINOM_HPP
#include <iostream>

class Polinom {
public:
    //Konstruktor
	Polinom();
    //Membuat polinom dengan derajat 0, nilai konstanta 0
    Polinom(int d);
    //Membuat polinom dengan derajat d, nilai koefesien dipilih acak dari bilangan bulat pada rentang -100 hingga 100 
    Polinom(int d, int* dat);
    //Membuat polinom dengan derajat d dan data seluruh koefesien dat
    
    //Copy Konstruktor
    Polinom(const Polinom&);

    //Destruktor
    ~Polinom();
    
    //Operator polinom
    Polinom& operator=(const Polinom&);//Operator =, meng-copy polinom
    Polinom operator+(const Polinom&);// Operator +, Menambahkan dua polinom
    Polinom operator-(const Polinom&);// Operator -, Mengurangi polinom ini dengan polinom masukan
    Polinom operator*(const Polinom&);// Operator *, Mengalikan polinom secara Brute Force
    
    //Output
    friend std::ostream& operator<<(std::ostream &os, const Polinom& P); //mencetak polinom
    
protected:
    int degree;// Merepresentasikan derajat polinom . >= 0
	int* data;// Merepresentasikan koefesien dan konstanta polinom dengan koefesien x^i = data[i]
};




#endif