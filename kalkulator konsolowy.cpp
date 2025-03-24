

#include <iostream>
using namespace std;


class Kalkulator {

//tutaj dodac paradygmaty private
	bool mem_used = false;
	double mem;

public:
	
	double add(double a, double b) {
		return a + b;
	}

	double sub(double a, double b) {
		return a - b;
	}

	double tim(double a, double b) {
		return a * b;
	}

	double div(double a, double b) {
		if (b == 0) {
			cout << "blad" << endl;
			return 0;
		}
		return a / b;
	}

	double mod(double a, double b) {
		return a - (int)(a / b) * b;
	}

	void erase() {
		mem = 0;
		mem_used = false;
		cout << "Akumulator jest pust" << endl;

	};


	void menu() {

		double a, b;

		char opcja;

		while (true) {
			cout << "Kalkulator" << endl;
			cout << " uzyj + aby dodac" << endl;
			cout << " uzyj - aby odjac" << endl;
			cout << " uzyj * aby ponozyc" << endl;
			cout << " uzyj / aby podzielic" << endl;
			cout << " uzyj % aby uzyskac reszte" << endl;
			cout << " napisz e aby wyczyscic" << endl;
			cout << " napisz q aby wyjsc" << endl;


			cout << "Podaj pierwsza liczbe ";
			cin >> a;
			cout << "Podaj opcje ";
			cin >> opcja;

			if (opcja == 'e') {
				erase();
			}

			if (opcja == 'q') {
				break;
			}

			cout << "Podaj druga liczbe ";
			cin >> b;

			switch (opcja) {

			case '+':
				mem = add(a, b);
				break;
			case '-':
				mem = sub(a, b);
				break;
			case '*':
				mem = tim(a, b);
				break;
			case '/':
				mem = div(a, b);
				break;
			case '%':
				mem = mod(a, b);
				break;
			default:
				cout << "???????" << endl;
				continue;

			}


			mem_used = true;
			cout << "Wynik: " << mem << endl;
		}


	};
};


int main()
{
	Kalkulator Projekt;
	Projekt.menu();
	return 0;

}
