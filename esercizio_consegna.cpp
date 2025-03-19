#include <iostream>

template<typename T>
class complex_number {
private: 
	T Reale;
	T Immaginaria;
	
public: 
	//costruttore di default:
	complex_number() : Reale(0),Immaginaria(0) {}


	//funzione per chiedere in input parte reale e parte immaginaria
	void input(){
			
		std::cout << "Inserisci la parte reale del numero complesso z: " << std::endl;
		std::cin >> Reale;
		
		std::cout << "Inserisci la parte immaginaria del numero complesso z: " << std::endl;
		std::cin >> Immaginaria;
	}
	
	//funzione per accedere alla classe	
	T getReale() const { return Reale; }
    T getImmaginaria() const { return Immaginaria; }
	

};

int main() {
	complex_number<int> z;   //crea un oggetto nella classe dei complex_number
	z.input(); 				// input utente
	
	std::cout << "La parte reale del numero complesso z è: " << z.getReale() << std::endl;
	std::cout << "La parte immaginaria del numero complezzo z è: " << z.getImmaginaria() << std::endl;
	std::cout << "Il coniugato del numero complesso z è: " << z.getReale() << " + "<< z.getImmaginaria() << "i" << std::endl;
	return 0;
};
	


		