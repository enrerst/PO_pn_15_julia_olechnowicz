// kalkulator konsolowy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

double mem = 0;

bool mem_used = false;

double add(double a, double b) { 
	return a + b; 
}

double sub(double a, double b) { 
	return a - b; 
}

double tim(double a, double b) { 
	return a * b; 
}

double div(double a, double b){
	if (b == 0) {
		cout << "blad" << endl;
		return 0;
	}
	return a / b;
}

double mod(double a, double b) { 
	return a - (int)(a / b) * b; 
}

void erase(){
	mem = 0;
	mem_used = false;
	cout << "Akumulator jest pust" << endl;

}

void menu() {
	int opcja;
	cout << "Kalkulator" << endl;
	cout << " uzyj + aby dodac" << endl;
	cout << " uzyj - aby odjac" << endl;
	cout << " uzyj * aby ponozyc" << endl;
	cout << " uzyj / aby podzielic" << endl;
	cout << " uzyj % aby uzyskac reszte" << endl;
	cout << " napisz e aby wyczyscic" << endl;
	cin >> opcja;

	switch (opcja) {

	case '+':
		mem = add(a, b);
		break;
	case '-':
		mem = sub(a, b);
		break;
	case '*':
		mem = tim(a, b);
	case '/':
		mem = div(a, b);
	case '%':
		mem = mod(a, b);


	}

}


int main()
{

}
