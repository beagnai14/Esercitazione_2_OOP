#include <iostream>
#include <iomanip>

template<typename T>
class complex_number {
private: 
	T Reale;
	T Immaginaria;
	
public: 
	//dichiarazione e descrizione costruttore default
	complex_number() 
		: Reale(0),Immaginaria(0) 
	{}
	
	//dichiarazione e descrizione costruttore parametrico
	complex_number(T r, T i)
		: Reale(r), Immaginaria(i)
	{}
	
	//overload operatore +
	complex_number operator+(const complex_number& other) {
		return complex_number(Reale + z2.Reale, Immaginaria + z2.Immaginaria);
		
	complex_number& operator+=(const complex_number& other) {
		Reale += other.Reale;
		Immaginaria += other.Immaginaria;
	return *this;}
		
	complex_number operator+(const T& val) {
	return complex_number(Reale + val, Immaginaria);}
		
	// Overload operatore *
	complex_number operator*(const complex_number& other) {
		T newReale = Reale * z2.Reale - Immaginaria * z2.Immaginaria;
		T newImmaginaria = Reale * z2.Immaginaria + Immaginaria * z2.Reale;
	return complex_number(newReale, newImmaginaria);}
		
	
	//restituzione dei valori dalla classe	
	T getReale() const { return Reale; }
	T getImmaginaria() const { return Immaginaria; }
	

	
	
};
	//overload operatore <<	
    std::ostream& operator<<(std::ostream& os, const complex_number<T>& z) {
		os << z.getReale();
        if (z.getImmaginaria() < 0)
			os << "-" << abs(z.getImmaginaria()) << "i";
		else
			os << "+" << z.getImmaginaria() << "i";
        return os;
		
		
		
 	complex_number<T> operator+(const T& val, const  complex_number<T>& z) {
		return complex_number(z.getReale() + val, z.getImmaginaria());

int main() {
	std::cout << std::fixed << std::setprecision(2);
	complex_number<float> z1, z2, z3;   //crea un oggetto nella classe dei complex_number
	z1.input(); 				// input utente
	std::cout << "La parte reale del numero complesso z1 è: " << z1.getReale() << std::endl;
	std::cout << "La parte immaginaria del numero complesso z1 è: " << z1.getImmaginaria() << std::endl;
	
	//operatore << per stampare z1 
	std::cout << "Il numero complesso è: " << z1 << std::endl;
	
	//coniugato
	std::cout << "Il coniugato del numero complesso z1 è: " << z1.getReale();
	if (z1.getImmaginaria() < 0) {
		std::cout <<  "+" << abs(z1.getImmaginaria()) << "i" << std::endl;	
	} else {
		std::cout <<  "-" << z1.getImmaginaria() << "i" << std::endl;
	};
	
	z2.input();
	//richiesta numero complesso z2
	std::cout << "Il numero complesso è: " << z2 << std::endl;
	
	//somma numeri complessi +
	z3=z1+z2;
	std::cout << "La somma dei numeri complessi z1 e z2 è: " << z3 << std::endl;
	
	// Moltiplicazione dei due numeri complessi
	z3 = z1 * z2;
	std::cout << "Il prodotto dei numeri complessi z1 e z2 è: " << z3 << std::endl;
	

return 0;
	
	
};

	


		