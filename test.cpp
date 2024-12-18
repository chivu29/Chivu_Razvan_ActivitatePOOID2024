#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Scoala {
private:
    const int id;
    char* nume;
    int nrClase;
    int* nrElevi;
    int nrTotalElevi;
    bool stat;
    static int nrMaxPersInClasa;

public:
    Scoala() : id(1) {
        this->nume = new char[strlen(" ") + 1];
        strcpy(this->nume, " ");
        this->nrClase = 0;
        this->nrElevi = new int[nrClase];
        for (int i = 0; i < nrClase; i++) {
            this->nrElevi[i] = nrElevi[i];
        }
        this->nrTotalElevi = 0;
        this->stat = true;
    }

    Scoala(const int idScoala, const char* nume, int nrClase, int* nrElevi, int nrTotalElevi, bool stat) :id(idScoala) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->nrClase = nrClase;
        this->nrElevi = new int[nrClase];
        for (int i = 0; i < nrClase; i++) {
            this->nrElevi[i] = nrElevi[i];
        }
        this->nrTotalElevi = nrTotalElevi;
        this->stat = stat;
    }

    Scoala(const Scoala& s) :id(s.id) {
        this->nume = new char[strlen(s.nume) + 1];
        strcpy(this->nume, s.nume);
        this->nrClase = s.nrClase;
        this->nrElevi = new int[nrClase];
        for (int i = 0; i < nrClase; i++) {
            this->nrElevi[i] = s.nrElevi[i];
        }
        this->nrTotalElevi = s.nrTotalElevi;
        this->stat = s.stat;
    }

    Scoala& operator=(const Scoala& s) {
        if (nume != NULL) {
            delete[] nume;
        }
        if (nrElevi != NULL) {
            delete[] nrElevi;
        }
        this->nume = new char[strlen(s.nume) + 1];
        strcpy(this->nume, s.nume);
        this->nrClase = s.nrClase;
        this->nrElevi = new int[nrClase];
        for (int i = 0; i < nrClase; i++) {
            this->nrElevi[i] = s.nrElevi[i];
        }
        this->nrTotalElevi = s.nrTotalElevi;
        this->stat = s.stat;
        return *this;
    }

    char* getNume() {
        return nume;
    }

    int* getNrElevi() {
        return nrElevi;
    }

    void setNume(const char* nume) {
        if (this->nume != NULL) {
            delete[] this->nume;
            this->nume = new char[strlen(nume) + 1];
            strcpy(this->nume, nume);
        }

    }

    void setNrElevi(int nrClase, int* nrElevi) {
        if (this->nrElevi != NULL) {
            delete[] this->nrElevi;
            this->nrClase = nrClase;
            this->nrElevi = new int[this->nrClase];
            for (int i = 0; i < this->nrClase; i++) {
                this->nrElevi[i] = nrElevi[i];
            }
        }

    }

    friend ostream& operator<<(ostream& out, Scoala& s) {
        out << s.id << endl;
        out << s.nume << endl;
        out << s.nrClase << endl;
        for (int i = 0; i < s.nrClase; i++) {
            out << s.nrElevi[i] << endl;
        }
        out << s.nrTotalElevi << endl;
        out << s.stat << endl;
        return out;
    }




    ~Scoala() {
        if (nume != NULL) {
            delete[] nume;
        }
        if (nrElevi != NULL) {
            delete[] nrElevi;
        }
    }

    //operatori unari
    //++, --, !
    //op ++ Si -- se pot scrie in doua forme: postfixat si prefixat
    //post inseamna ca punem ++ dupa element, 
    //pre inseamna ca punem ++ in fata elementului
    //varianta prefixata: (nu necesita parametru
    int operator++() {
        return nrTotalElevi++;
    }

    //varianta post fixata: prima data afiseaza, apoi creste valoarea 
    int operator++(int) { //acest int ajuta compiloatorul sa faca diferenta dintre cele doua functii
        int copie = nrTotalElevi;
        nrTotalElevi++;
        return copie;
    }

    //operatorul de negare
    bool operator!() {
        if (stat == true) {
            stat = false;
            return true;
        }
        else {
            return false;
            stat = true;
        }
    }

    //operatori binari: +, -, +=, -=, *, /, %, *=
    //+ si - se supraincarca in 3 forme: 
    //ob+val
    Scoala& operator+(int valoare) {
        nrTotalElevi = nrTotalElevi + valoare;
        return *this;
    }
    //ob + ob
    Scoala& operator+(Scoala& s) {
        nrTotalElevi = nrTotalElevi + s.nrTotalElevi;
        return *this;
    }

    //val+ob
    friend int operator+(int valoare, Scoala& s) {
        s.nrTotalElevi = valoare + s.nrTotalElevi;
        return s.nrTotalElevi;
    }



    //operator bool - binar
    //operator ==
    bool operator==(Scoala& s) {
        if (this->id == s.id && strcmp(this->nume, nume) == 0 && this->nrClase == s.nrClase) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator!=(Scoala& s) {
        if (this->id != s.id && strcmp(this->nume, nume) != 0 && this->nrClase != s.nrClase) {
            return true;
        }
        else {
            return false;
        }
    }
    //operator <;>;<=;>=
    bool operator<=(Scoala& s) {
        if (this->nrTotalElevi <= s.nrTotalElevi) {
            return true;
        }
        else {
            return false;
        }
    }



    //cazuri exceptate
    //operatorul de indexare
    int operator[](int pozitie) {
        if (pozitie >= 0 && pozitie < nrClase && nrElevi != NULL) {
            return nrElevi[pozitie];
        }
    }
    // operatorul functie op()(), este el mai flexibil dintre toate, 
    int operator()(int valoare) {
        return valoare * nrTotalElevi;

    }
    //operatorul functie, sa facem o suma pe vector, supraincarcati operatorul functie care sa determina totalul elevilor din clase
    /*int operator ()() {
        int suma = 0;
        for (int i = 0; i < nrClase; i++) {
            suma = suma + nrElevi[i];
     }   
        return suma;

    }*/

    //ex cu operatorul functie de returneze bool;
    bool operator()() {
        if (this->stat == true)
            return true;
        else {
            return false;
        }

    }
    // operatorul cast prin pierdere, se apekeaza intr-o alta metoda in cadrul clasei; 
    //media elevilor per clasa;->am facut un cast implicit

    float nrMedieElevi() {
        float suma = 0;
        float medie = 0;
        for (int i = 0; i < nrClase; i++) {
            suma += nrElevi[i];
        }
        medie = suma / nrClase;
        return(int)medie;
    }
    //cast explicit, cand ii explicitam noi pe cine sa se aplice
    explicit operator int() {
        return nrTotalElevi;
    }

    //operatorul de inmultire/impartire/modulo %(restul impartirii)/inmultire*:
    int operator*(int nr) {
        return nr * nrTotalElevi;
    }

    //operatorul modulo
    int operator %(int nr) {
        return nrTotalElevi % nr;

    }
};

int Scoala::nrMaxPersInClasa = 35;

int main()
{
    cout << "Constructor implicit: " << endl;
    Scoala s0;
    cout << s0 << endl;

    cout << "Constructor cu parametrii: " << endl;
    Scoala s1(2, "Bucuresti", 4, new int[4] {25, 24, 27, 28}, 104, 1);
    cout << s1 << endl;

    cout << "Constructor de copiere: " << endl;
    Scoala s2(s1);
    cout << s2 << endl;

    cout << "Operator = " << endl;
    //s0 = s1;
    cout << s0 << endl;

    cout << s1.getNrElevi() << endl;
    cout << s1.getNume() << endl;
    s1.setNume("Iasi");
    cout << s1.getNume() << endl;
    s1.setNrElevi(3, new int[3] {33, 21, 22});
    cout << s1.getNrElevi() << endl;

    int x = 10;
    cout << x << endl;
    cout << ++x << endl;
    cout << x << endl;
    cout << x++ << endl;
    cout << x << endl;



    ++s1;
    s1++;

    cout << s1 << endl;
    // s1.operator+(34);
    s1 + (100);
    cout << s1 << endl;

    s1 + s0;
    cout << s1 << endl;


    //fara operator 
    cout << s1.getNrElevi()[0] << endl;

    //cu operator
    cout << s1[1] << endl;

    //operatorul functie
    cout << s1.operator()(5) << endl;

    //operatorul functie fara parametrii
    cout << s1 << endl;

    cout << s1.operator()() << endl;

    //operatorul cast 
    cout << s1[1] << endl;
    float a= 17.5;
    cout << (int)a << endl;
    cout << s1.nrMedieElevi() << endl;

    //operatorul *
    cout << s1 * 2 << endl;

    //opratorul %
    cout << s1 & 2 << endl;

    //metode statice plus mosteniri, +=,-= au mai ramas ca operatori

}
