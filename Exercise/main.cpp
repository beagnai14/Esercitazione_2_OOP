#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
class complex_number {
private: 
	T Reale;
	T Immaginaria;
	
public: 
	//costruttore default
	complex_number() 
		: Reale(0),Immaginaria(0) 
	{}
	
	//costruttore parametrico
	complex_number(T r, T i)
		: Reale(r), Immaginaria(i)
	{}

	//metodi di accesso 
	T getReale() const { 
		return(Reale); 
		}
	T getImmaginaria() const {
		return(Immaginaria);
		}
	
	//coniugato 
	complex_number coniugato()
	const {
		return complex_number(Reale, -Immaginaria);
	}
	
	//Overload operatore + tra complessi
	complex_number operator+(const complex_number& z2) {
		return complex_number(Reale + z2.Reale, Immaginaria + z2.Immaginaria);   
	}

	// Overload operatore * tra complessi
	complex_number operator*(const complex_number& z2) {
		T newReale = Reale * z2.Reale - Immaginaria * z2.Immaginaria;
		T newImmaginaria = Reale * z2.Immaginaria + Immaginaria * z2.Reale;
	return complex_number(newReale, newImmaginaria);
	}
	
	// Overload operatore += tra complessi
	complex_number& operator+=(const complex_number& other) {
		Reale += other.Reale;
		Immaginaria += other.Immaginaria;
	return *this;
	}
	
	//Overload operatore *= tra complessi
	complex_number& operator*=(const complex_number& other) {
		T newReale = Reale * other.Reale - Immaginaria * other.Immaginaria;
		T newImmaginaria = Reale * other.Immaginaria + Immaginaria * other.Reale;
		Reale =  newReale;
		Immaginaria = newImmaginaria;
		return *this;
	}
	
	//Overload operatore +: complesso e T
	complex_number operator+(const T& val) 
	{
		return complex_number(Reale + val, Immaginaria);
	}
	
	//Overload operatore *: complesso e T
	complex_number operator*(const T& val) 
	{
		return complex_number(Reale * val, Immaginaria * val);
	}

};

//overload operatore <<	
template<typename T>
ostream& operator<<(ostream& output, const complex_number<T>& z) 
{
	output << z.getReale();
	if (z.getImmaginaria() < 0)
		output << "-" << abs(z.getImmaginaria()) << "i";
	else
		output << "+" << z.getImmaginaria() << "i";
	return output;
}

//Overload operatore +: T e complesso 
template<typename T> 
complex_number<T> operator+(const T val, const complex_number<T>& z)
{
	return complex_number<T>(z.getReale() + val, z.getImmaginaria());
}

//Overload operatore *: T e complesso 
template<typename T> 
complex_number<T> operator*(const T val, const complex_number<T>& z)
{
	return complex_number<T>(z.getReale() * val, z.getImmaginaria() * val);
}



int main() {
	
	using cpx = complex_number<int>;
	
	cpx z1(2,5);
	cpx z2(6,7);
	
	cout << "Parte Reale : " << z1.getReale() << endl;
	cout << "Parte Immaginaria : " << z1.getImmaginaria() << endl;
	cout << "Coniugato : " << z1.coniugato() << endl;
	cout << "z2 : " << z2 << endl;
	
	cout << "OPERAZIONI SOMMA" << endl;
	cpx somma = z1 + z2;
	cout << "Somma : " << somma << endl;
	
	cpx somma_c = z1 += z2;
	cout << "Somma con += : " << somma_c << endl;
	
	cpx somma_C_T = z1 + 2;
	cout << "Somma Complesso + T: " << somma_C_T << endl;
	
	cpx somma_T_C = 2 + z1;
	cout << "Somma T + Complesso : " << somma_T_C << endl;
	
	
	
	cout << endl;
	cout << "OPERAZIONI PRODOTTO" << endl;
	cpx prodotto = z1 * z2;
	cout << "Prodotto : " << prodotto << endl;
	
	cpx prodotto_c = z1 *= z2;
	cout << "Prodotto con *= : " << prodotto_c << endl;
	
	cpx prodotto_C_T = z1 * 2;
	cout << "Prodotto Complesso * T : " << prodotto_C_T << endl;
	
	cpx prodotto_T_C = 2 * z1;
	cout << "Prodotto T * Complesso : " << prodotto_T_C << endl;

	return 0;
}
	


		
