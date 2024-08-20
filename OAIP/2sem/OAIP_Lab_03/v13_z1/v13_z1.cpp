#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {

	setlocale(LC_CTYPE, "Russian");
	char a;
	int i = 0, j, sz = 0, sz_str = 0, kol = 0;
	ifstream read("FILE1.txt");
	ofstream write("FILE2.txt");
	read.seekg(0, ios_base::end);
	sz = read.tellg();
	read.seekg(0);
	j = 0;
	int poz1 = 0, poz2 = 0;
	for (i = 0; i < sz; i++) {
		a = read.get();
		if (a == ' ')
			kol++;
		if (a == '\n') {
			read.seekg(-1, ios_base::cur);
			poz2 = read.tellg();
			read.seekg(poz1);
			if (kol >= 2) {
				for (j = poz1 + 1; j <= poz2; j++) {
					a = read.get();
					write << a;
				}
			}
			poz1 = poz2 + 1;
			kol = 0;
		}
	}

	read.close();
	write.close();
	ifstream read1("FILE2.txt");
	int max = 0, nomer_sl = 0, nomer_max = 0;
	char glasn[] = { "aeiouy" };
	read1.seekg(0, ios_base::end);
	sz = read1.tellg();
	read1.seekg(0);
	kol = 0;
	for (i = 0; i < sz; i++) {
		a = read1.get();
		for (j = 0; j < 6; j++) {
			if (a == glasn[j])
				kol++;
		}
		if (a == '\n' || a == ' ') {
			nomer_sl++;
			if (kol > max) {
				max = kol;
				nomer_max = nomer_sl;
			}
			kol = 0;
		}
	}
	cout << "Ќомер слова с максимальным количеством гласных - " << nomer_max;
	read1.close();
}