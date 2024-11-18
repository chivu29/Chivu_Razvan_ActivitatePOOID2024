// Primul meu proiect Chivu Dorian Razvan 
// POO
#define _CRT_SECURE_NO_WARNINGS
#include <iostream.h>

using namespace std;

int x;

int y = 10;



int suma(int a, int b) {
	int sum = 0;
	return a + b;
}


float suma(float a, float b) {
	return a + b;
}


void afisare(string mesaj) {
	cout << mesaj << endl;
}

int functie(int x) {
	return 2 * x + 3;
}

int f1(int* p) {

}

int f1(int& p) {

}

void main() {
	x = 1;
	
	afisare("Buna!");

	
	int rezultat = functie(2);
	cout << rezultat << endl;
	
	cout << functie(7) << endl;
	cout << functie(3) << endl;
	cout << functie(120) << endl;
	cout << functie(-12) << endl;

	char c = '?';
	cout << c << endl;
	

	int z = 10;
	cout << z << endl;
	cout << &z << endl;
	int* p1 = &z;
	cout << p1 << endl;
	cout << *p1 << endl;


	float vs[5]{ 1.2,2,3.3,4.2,5 };
	cout << vs[3] << endl;

	
	int dim = 5;
	int* vd = new int[dim];
	for (int i = 0; i < dim; i++) {
		vd[i] = 8;
	}
	for (int i = 0; i < dim; i++) {
		cout << vd[i] << ", ";
	}

	int dim1 = 7;
	float* vd1 = new float[dim1];

	char* cuvant = new char[strlen("specializare") + 1];
	strcpy(cuvant, "specializare");
	cout << cuvant << endl;


	
	int v[5] = { 4,2,7,3,9 };

	cout << v << endl;
	cout << v + 1 << endl;
	cout << v + 2 << endl;
	cout << v + 3 << endl;
	cout << v + 4 << endl;
	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;
	cout << v[3] << endl;
	cout << v[4] << endl;
	cout << *v << endl;
	cout << *v + 1 << endl;
	cout << *(v + 1) << endl;
	cout << *(v + 2) << endl;
	cout << *(v + 3) << endl;

	int* p = NULL;
	p = v;
	cout << p << endl;
	cout << *p << endl;
	*p = 13;
	cout << *p << endl;
	cout << v[0] << endl;

	p++;
	*p = 22;
	cout << *p << endl;
	cout << v[1] << endl;

	cout << v[2] << endl;
	cout << &v[2] << endl;


	p = &v[2];
	*p = 17;
	p = v + 3;
	*p = 33;

	
	p = v;
	p--;
	cout << p << endl;
	
	*(v + 4) = 33;
	for (int i = 0; i < dim; i++) {
		cout << v[i] << endl;
	}


	int a = 48;
	int* pointerLaA = &a;
	f1(pointerLaA);
	f1(&a);

}