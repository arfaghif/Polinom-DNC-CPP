#include <iostream>
#include "polinomdnc.hpp"
#include <chrono> 
#include <ctime>
using namespace std;
using namespace std::chrono;
int main(){
    int n;
    //I
    cout << "Masukkan derajat d :"<<endl;
    cin >> n;
    srand((int)time(0));
    
    PolinomDnC P1(n);
    Polinom PP1 = P1;

    cout <<"Nilai P1 : " << P1 << endl;

    PolinomDnC P2(n);
    Polinom PP2 = P2;
    cout << "Nilai P2 : " << P2 << endl;

    //BF
    auto start = high_resolution_clock::now();
    Polinom PP = PP1 * PP2;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Hasil P1 x P2 secara Brute force : \n" << PP<< endl;
    cout << "Waktu eksekusi : "<< duration.count() << " microseconds" << endl; 
    cout <<  "Jumlah operasi penjumlahan = " << nplus_bf << endl;
    cout <<  "Jumlah operasi perkalian = " << nmul_bf << endl;
    
    //D&C
    auto start2 = high_resolution_clock::now();
    PolinomDnC P = P1 * P2;
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2-start2);

    cout<< "Hasil P1 x P2 secara Divide and Conquer : \n" <<P<< endl;
    cout << "Waktu eksekusi : "<< duration2.count() << " microseconds" << endl; 
    cout <<  "Jumlah operasi penjumlahan = " << nplus_dc << endl;
    cout <<  "Jumlah operasi perkalian = " << nmul_dc << endl;

}
