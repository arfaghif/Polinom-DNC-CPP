#include "polinomdnc.hpp"
int nplus_dc=0;
int nmul_dc=0;

//C
PolinomDnC :: PolinomDnC() : Polinom(){}
PolinomDnC :: PolinomDnC(int d) : Polinom(d){}
PolinomDnC :: PolinomDnC(int d, int* dat) : Polinom(d,dat){}
//CC
PolinomDnC :: PolinomDnC(const PolinomDnC& P){
    this->degree = P.degree;
    this->data = new int[degree+1];
    for(int i =0; i<=degree;++i){
        this->data[i] = P.data[i];
    }
} 

//Operator
PolinomDnC&  PolinomDnC :: operator=(const PolinomDnC& P){
    this->degree = P.degree;
    this->data = new int[degree+1];
    for(int i =0; i<=degree;++i){
        this->data[i] = P.data[i];
    }  
    return *this;  
}
PolinomDnC PolinomDnC :: operator+(const PolinomDnC& P){
    int n_degree = this->degree >= P.degree ? this->degree : P.degree ;
    int* dat = new int[n_degree+1];
    if (this->degree >= P.degree ){
        for (int i =0 ; i<= P.degree ; ++i){
            dat[i] = this -> data[i] + P.data [i]; 
            nplus_dc++;
        }
        for (int i= P.degree +1; i<= this -> degree; ++i){
            dat[i] = this -> data[i];
        }
    }else{
        for (int i =0 ; i<= this->degree ; ++i){
            dat[i] = this -> data[i] + P.data [i];
            nplus_dc++; 
        }
        for (int i= this -> degree +1 ; i<= P.degree; ++i){
            dat[i] = P.data[i];
        }     
    }

    return PolinomDnC(n_degree, dat);
}
PolinomDnC PolinomDnC :: operator-(const PolinomDnC& P){
    int n_degree = this->degree >= P.degree ? this->degree : P.degree ;
    int* dat = new int[n_degree+1];
    if (this->degree >= P.degree ){
        for (int i =0 ; i<= P.degree ; ++i){
            dat[i] = this -> data[i] - P.data [i]; 
            nplus_dc++;
        }
        for (int i= P.degree +1; i<= this -> degree; ++i){
            dat[i] = this -> data[i];
        }
    }else{
        for (int i =0 ; i<= this->degree ; ++i){
            dat[i] = this -> data[i] - P.data [i];
            nplus_dc++; 
        }
        for (int i= this -> degree +1 ; i<= P.degree; ++i){
            dat[i] = 0 - P.data[i];
        }     
    }

    return PolinomDnC(n_degree, dat);
}
PolinomDnC PolinomDnC ::  operator*(const PolinomDnC& P){
    //Exception
    if (this ->degree != P.degree){
        throw "Derajat polinom harus sama";
    }
    //basis
    if (this->degree ==0){
        int * dat = new int[1];
        dat[0]= this->data[0] * P.data [0];
        nmul_dc++;
        return PolinomDnC (0,dat);
    }
    else{
    //rekurens 
        int div_P = this->degree / 2 +1;
        PolinomDnC A0,A1;
        splitP(*this, &A0, &A1);
        PolinomDnC B0, B1;
        splitP(P, &B0, &B1); 
        PolinomDnC Y = (A0+A1 ) * (B0+B1);
        
        PolinomDnC U =  A0  * B0;
        
        PolinomDnC Z = A1 * B1 ;
        
        return (U  + Geser(Y-Z-U, div_P) + Geser(Z,div_P+div_P));
    }
}


//Fungsi kawan
PolinomDnC  Geser(const PolinomDnC& P, int x){
    int n_degree = P.degree + x;
    int *dat = new int[n_degree+1];
    for (int i=0; i< x;++i){
        dat[i] = 0;
    }
    for(int i =0; i<=P.degree;++i){
        dat[i+x] =  P.data[i];
    } 
    return PolinomDnC(n_degree, dat);
}
void splitP (const PolinomDnC& P, PolinomDnC* P1, PolinomDnC* P2){
    P1 -> degree = P.degree / 2;
    P2 -> degree = P.degree /2;
    
    P1 -> data = new int[P1-> degree +1];
    P2 -> data = new int[P2 -> degree +1];
    for (int i=0; i<= P1->degree;++i){
        P1 -> data[i] = P.data[i];
    }
    for (int i=P1 ->degree+1; i<= P.degree;++i){
        P2 -> data[i- P1 -> degree-1] = P.data[i];
    }
    if (P.degree%2 == 0){
        P2 -> data [P.degree/2] = 0;
    } 

}


