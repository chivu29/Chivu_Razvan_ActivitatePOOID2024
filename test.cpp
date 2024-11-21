#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
using namespace std;


class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	//Constructor fara parametrii
	Autobuz() :idAutobuz(++nrAutobuze) {
		this->capacitate = 40;
		this->nrPersoaneImbarcate = 35;
		this->producator = new char[strlen("PRODUCATOR") + 1];
		strcpy(producator, "Audi");
	}

	//Constructor cu parametrii
	Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) :idAutobuz(++nrAutobuze) {
		if (capacitate <= 0) {
			this->capacitate = 40; 
		}
		else {
			this->capacitate = capacitate;
		}

		if (nrPersoaneImbarcate < 0 || nrPersoaneImbarcate > this->capacitate) {
			this->nrPersoaneImbarcate = this->capacitate; 
		}
		else {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}

		if (producator == nullptr) {
			this->producator = new char[strlen("UNKNOWN") + 1];
			strcpy(this->producator, "UNKNOWN");
		}
		else {
			this->producator = new char[strlen(producator) + 1];
			strcpy(this->producator, producator);
		}
	}

	//Constructor de copiere
	Autobuz(const Autobuz& a) :idAutobuz(++nrAutobuze) {
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);
	}

	// Operator de atribuiere (=)
	Autobuz& operator= (const Autobuz& a) {
		if (this == &a) {
			return *this; // evita auto-atribuirea
		}
		delete[] producator;
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);

		return *this;
	}
	// destructor
	~Autobuz() {
		delete[] producator;
	}

	//Operator << (afisare)
	friend ostream& operator << (ostream& out, Autobuz a) {
		out << a.capacitate << "; " << a.nrPersoaneImbarcate << "; " << a.producator << "; ";
		return out;
	}

	// getter 1
	int getcapacitate() {
		return capacitate;
	}

	// getter 2
	char* getproducator() {
		return producator;
	}

	//setter 1
	void setcapacitate(int capacitate) {
		this->capacitate = capacitate;

	}

	//setter 2
	void setproducator(const char* producator) {
		delete[] this->producator;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}

	// Metoda: numar locuri libere
	int getNumarLocuriLibere() {
		return capacitate - nrPersoaneImbarcate;
	}

	// Operator de cast la int
	operator int() {
		return nrPersoaneImbarcate;
	}

	// Operator >
	bool operator>(const Autobuz& a) {
		return capacitate > a.capacitate;
	}

};

// Initializare membru static
int Autobuz::nrAutobuze = 0;

void main() {
	// Testarea constructor fara parametrii
	Autobuz a1;
	cout << "Autobuz 1: " << a1 << endl;

	// Testarea constructor cu parametrii
	Autobuz a2(20, 15, "Mercedez");
	cout << "Autobuz 2: " << a2 << endl;

	// Testare constructor de copiere
	Autobuz a3(a2);
	cout << "Autobuz 3 (copiat din a2): " << a3 << endl;

	// Testare operator= (atribuire)
	a3 = a1;
	cout << "Autobuz 3 dupa atribuire (a3 = a1): " << a3 << endl;

	// Testare metode accesor (get si set)
	cout << "Capacitatea lui a2: " << a2.getcapacitate() << endl;
	a2.setcapacitate(50);
	cout << "Noua capacitate a lui a2 (dupa set): " << a2.getcapacitate() << endl;

	cout << "Producatorul lui a2: " << a2.getproducator() << endl;
	a2.setproducator("Volvo");
	cout << "Noul producator al lui a2 (dupa set): " << a2.getproducator() << endl;

	// Testare metoda getNumarLocuriLibere
	cout << "Locuri libere in a2: " << a2.getNumarLocuriLibere() << endl;

	// Testare operator de cast la int
	cout << "Numar persoane urcate in a2 (cast la int): " << (int)a2 << endl;

	// Testare operator >
	if (a1 > a2) {
		cout << "Autobuzul a1 are o capacitate mai mare decat a2." << endl;
	}
	else {
		cout << "Autobuzul a2 are o capacitate mai mare sau egala decat a1." << endl;
	}

}