#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	char symbol;
	cout << "������� ������: ";
	cin >> symbol;

	int code = static_cast<int>(symbol);

	if (code >= 48 && code <= 57) {
		cout << "��������� ������ - �����" << endl;
	}
	else if ((code >= 65 && code <= 90) || (code >=97 &&  code <= 122)) {
		cout << "��������� ������ - ����� ���������� ��������" << endl;
	}
	else if ((code >= 1040 && code <= 1071) || (code >= 1072 && code <= 1103)) {
		cout << "��������� ������ - ����� �������� ��������" << endl;
	} 
	else {
		std::cout << "��������� ������ - ������ ������" << std::endl;
	}
	std::cout << "��� �������: " << code << std::endl;
	return 0;
}