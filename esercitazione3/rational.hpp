#include <concepts>
#include <numeric>
#include <iostream>
/*
Nota per l'esercitazione 3:
  Per realizzare l'es. 3 ho utilizzato un modello IA esclusivamente come 
  strumento di supporto didattico: ossia per chiarire la teoria dietro 
  l'overload degli operatori e l'uso dei template.
*/

template<typename I>
requires std::integral<I>
   
class rational {
    I num_;
    I den_;

public:
    /* Costruttore di default */
    rational()
        : num_(I{0}), den_(I{1})
    {}


    /* Costruttore user-defined */
    rational(const I& num, const I& den)
        : num_(num), den_(den)
    {
        simplify();
    }


    /* Restituiscono i valori di num e den */
    I num() const { return num_; }
    I den() const { return den_; }


    /* Implementazione canonica dell'incremento */
    rational& operator+=(const rational& other) {
        if ((num_!=0 && den_ == 0) && (other.num_ != 0 && other.den_ == 0)) {
            num_ = 1;
            den_ = 0;
        }
        else {
            I nuovo_num = num_ * other.den_ + other.num_ * den_;
            I nuovo_den = den_ * other.den_;
            num_ = nuovo_num;
            den_ = nuovo_den;
            simplify();
        }
        return *this;
    }
    
    /* Implementazione canonica della somma */
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }


    /* Implementazione canonica del decremento */
    rational& operator-=(const rational& other) {
        I nuovo_num = num_ * other.den_ - other.num_ * den_;
        I nuovo_den = den_ * other.den_;
        num_ = nuovo_num;
        den_ = nuovo_den;
        simplify();
        return *this;
    }


    /* Implementazione canonica della differenza */
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    } 
    
    
    /* Implementazione canonica di *= tra frazioni */
    rational& operator*=(const rational& other) {
        I nuovo_num = num_ * other.num_;
        I nuovo_den = den_ * other.den_;
        num_ = nuovo_num;
        den_ = nuovo_den;
        simplify();
        return *this;
    }
    
    /* Implementazione canonica del prodotto tra frazioni */
    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }


    /* Implementazione canonica di /= tra frazioni */
     rational& operator/=(const rational& other) {
        I nuovo_num = num_ * other.den_;
        I nuovo_den = den_ * other.num_;
        num_ = nuovo_num;
        den_ = nuovo_den;
        simplify();
        return *this;
    }


    /* Implementazione canonica della divisione tra frazioni */
    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }


    /* Semplificazione della frazione */
    void simplify() {
        if (den_ == 0 && num_ == 0) {
        return;
    }
        I g = std::gcd(num_, den_);
        num_ /= g;
        den_ /= g;
    }
};

template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r)
{
    if (r.den()==0) {
        if (r.num()==0) {
            os << "NaN";
        }
        else {
            os << "Inf";
        }
    }
    else {
    os << r.num() << "/" << r.den();
    }
    return os;
}