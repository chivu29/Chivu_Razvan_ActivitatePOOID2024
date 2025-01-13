#include <iostream>
#include <string> 
using namespace std;

class SalaDeFitness {
private:
    string nume;          
    int capacitate;      
    float pretAbonament;  

public:
    
    SalaDeFitness() {
        nume = "Necunoscut";
        capacitate = 0;
        pretAbonament = 0.0f;
        cout << "Constructor fără parametri apelat." << endl;
    }

    
    SalaDeFitness(string numeSala, int capacitateSala, float pret) {
        nume = numeSala;
        capacitate = capacitateSala;
        pretAbonament = pret;
        cout << "Constructor cu parametri apelat." << endl;
    }

    
    SalaDeFitness(const SalaDeFitness& other) {
        nume = other.nume;
        capacitate = other.capacitate;
        pretAbonament = other.pretAbonament;
        cout << "Constructor de copiere apelat." << endl;
    }

    
    SalaDeFitness& operator=(const SalaDeFitness& other) {
        cout << "Operator de atribuire apelat." << endl;
        if (this != &other) { 
            nume = other.nume;
            capacitate = other.capacitate;
            pretAbonament = other.pretAbonament;
        }
        return *this;
    }

    
    ~SalaDeFitness() {
        cout << "Destructor apelat pentru: " << nume << endl;
    }

    
    void afisare() const {
        cout << "Sala: " << nume << ", Capacitate: " << capacitate
            << ", Pret abonament: " << pretAbonament << " RON" << endl;
    }
};

int main() {
    SalaDeFitness sala1;
    sala1.afisare();

    
    SalaDeFitness sala2("Fitness Pro", 50, 200.0f);
    sala2.afisare();

    
    SalaDeFitness sala3 = sala2;
    sala3.afisare();

   
    SalaDeFitness sala4;
    sala4 = sala2;
    sala4.afisare();

    return 0;
}
