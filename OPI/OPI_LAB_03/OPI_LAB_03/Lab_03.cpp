#include <iostream>
// RublevskayaMargarita2006
//52 75 62 6c 65 76 73 6b 61 79 61 4d 61 72 67 61 72 69 74 61 32 30 30 36 
//52 75 62 6c 65 76 73 6b 61 79 61 4d 61 72 67 61 72 69 74 61 32 30 30 36
//00 52 00 75 00 62 00 6c 00 65 00 76 00 73 00 6b 00 61 00 79 00 61 00 4d 00 61 00 72 00 67 00 61 00 72 00 69 00 74 00 61 00 32 00 30 00 30 00 36


//РублевскаяМаргаритаВладимиовна2006
//d0 f3 e1 eb e5 e2 f1 ea e0 ff cc e0 f0 e3 e0 f0 e8 f2 e0 c2 eb e0 e4 e8 ec e8 ee e2 ed e0 32 30 30 36 
//d0a0 d183 d0b1 d0bb d0b5 d0b2 d181 d0ba d0b0 d18f d09c d0b0 d180 d0b3 d0b0 d180 d0b8 d182 d0b0 d092 d0bb d0b0 d0b4 d0b8 d0bc d0b8 d0be d0b2 d0bd d0b0 32 30 30 36
//04 20 04 43 04 31 04 3b 04 35 04 32 04 41 04 3a 04 30 04 4f 04 1c 04 30 04 40 04 33 04 30 04 40 04 38 04 42 04 30 04 12 04 3b 04 30 04 34 04 38 04 3c 04 38 04 3e 04 32 04 3d 04 30 00 32 00 30 00 30 00 36

//Рублевская2006Margarita
//d0 f3 e1 e5 e2 f1 ea e0 ff 32 30 30 36 4d 61 72 67 61 72 69 74 61 
//d0a0 d183 d0b1 d0b5 d0b2 d181 d0ba d0b0 d18f 32 30 30 36 4d 61 72 67 61 72 69 74 61
//04 20 04 43 04 31 04 35 04 32 04 41 04 3a 04 30 04 4f 00 32 00 30 00 30 00 36 00 4d 00 61 00 72 00 67 00 61 00 72 00 69 00 74 00 61

int main()
{
	int number = 0x12345678;
	char hello[] = "Hello, ";
	char lfie[] = "RublevskayaMargarita2006";
	char rfie[] = "РублевскаяМаргаритаВладимиовна2006";
	char lr[] = "Рубевская2006Margarita";

	wchar_t Lfie[] = L"RublevskayaMargarita2006";
	wchar_t Rfie[] = L"РублевскаяМаргаритаВладимиовна2006";
	wchar_t LR[] = L"Рубевская2006Margarita";

	std::cout << hello << lfie << std::endl;
	return 0;
}