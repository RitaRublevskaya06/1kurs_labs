#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	char symbol;
	cout << "Введите символ: ";
	cin >> symbol;

	int code = static_cast<int>(symbol);

	if (code >= 48 && code <= 57) {
		cout << "Введенный символ - цифра" << endl;
	}
	else if ((code >= 65 && code <= 90) || (code >=97 &&  code <= 122)) {
		cout << "Введенный символ - буква латинского алфавита" << endl;
	}
	else if ((code >= 1040 && code <= 1071) || (code >= 1072 && code <= 1103)) {
		cout << "Введенный символ - буква русского алфавита" << endl;
	} 
	else {
		std::cout << "Введенный символ - другой символ" << std::endl;
	}
	std::cout << "Код символа: " << code << std::endl;
	return 0;
}