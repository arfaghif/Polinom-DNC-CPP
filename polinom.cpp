#include "polinom.hpp"
#include <ctime>

int nmul_bf = 0;
int nplus_bf =0;
using namespace std;
//C
Polinom ::Polinom () : degree(0){
    data = new int[1];
    data[0] = 0;
}
Polinom :: Polinom(int d):degree(d){
    data = new int[degree+1];
    for(int i =0; i<=degree;++i){
        data[i] = (rand() % 201)-100;
    }
}
Polinom :: Polinom(int d, int* dat) : degree(d), data(dat){}
//CC
Polinom :: Polinom (const Polinom& P){
    this->degree = P.degree;
    this->data = new int[degree+1];
    for(int i =0; i<=degree;++i){
        this->data[i] = P.data[i];
    }  
}
//D
Polinom :: ~Polinom(){
    delete[] this->data;
}


//Operator
Polinom& Polinom ::operator=(const Polinom&  P){
    this->degree = P.degree;
    this->data = new int[degree+1];
    for(int i =0; i<=degree;++i){
        this->data[i] = P.data[i];
    }  
    return *this;  
}
Polinom Polinom :: operator+(const Polinom& P){
    int n_degree = this->degree >= P.degree ? this->degree : P.degree ;
    int* dat = new int[n_degree+1];
    if (this->degree >= P.degree ){
        for (int i =0 ; i<= P.degree ; ++i){
            dat[i] = this -> data[i] + P.data [i]; 
        }
        for (int i= P.degree +1; i<= this -> degree; ++i){
            dat[i] = this -> data[i];
        }
    }else{
        for (int i =0 ; i<= this->degree ; ++i){
            dat[i] = this -> data[i] + P.data [i]; 
        }
        for (int i= this -> degree +1 ; i<= P.degree; ++i){
            dat[i] = P.data[i];
        }     
    }

    return Polinom(n_degree, dat);
}
Polinom Polinom :: operator-(const Polinom& P){
    int n_degree = this->degree >= P.degree ? this->degree : P.degree ;
    int* dat = new int[n_degree+1];
    if (this->degree >= P.degree ){
        for (int i =0 ; i<= P.degree ; ++i){
            dat[i] = this -> data[i] - P.data [i]; 
        }
        for (int i= P.degree +1; i<= this -> degree; ++i){
            dat[i] = this -> data[i];
        }
    }else{
        for (int i =0 ; i<= this->degree ; ++i){
            dat[i] = this -> data[i] - P.data [i]; 
        }
        for (int i= this -> degree +1 ; i<= P.degree; ++i){
            dat[i] = 0 - P.data[i];
        }     
    }

    return Polinom(n_degree, dat);
}

Polinom Polinom::operator*(const Polinom& P){
    int n_degree = this->degree + P.degree;
    int* dat = new int[n_degree+1];
    for (int i =0; i<= n_degree; ++i){
        dat[i] = 0;
    }
    for(int i =0; i<=P.degree;++i){
        for(int j=0; j<= this->degree;++j){
            dat[i+j] += this->data[j] * P.data[i];
            nmul_bf++;
            nplus_bf++;
        }
    }   
    return Polinom(n_degree, dat);
}

//O
std::ostream& operator<<(std::ostream &os, const Polinom& P){
    int i;
    for( i =P.degree; i>=0;--i){
        if (i==0){
            P.data[i] < 0 ?  os << "- " << -1*P.data [i] : os << P.data[i];
        } else{
            if (P.data[i]!=0){
                P.data[i] > 0 ?  os << P.data [i] << " x^" << i<< " " : os << "- " << -1*P.data [i] << " x^" << i<< " ";
                break;
            }
        }
    }


    for(--i;i>0;--i){
        if (P.data[i]<0){
            os << "- " << P.data[i] * -1 << " x^" << i<< " ";
        }else if(P.data[i]>0){
            os << "+ "<< P.data [i] << " x^" << i<< " ";
        }
    } 

 
    if (i>=0){
        if(P.data[0]>0){
            os << "+ "<< P.data[0];
        }
        if (P.data[0]<0){
            os << "- "<< P.data[0]* -1;
        }
    }
    return os;  
}
