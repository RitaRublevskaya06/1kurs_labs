#include <iostream>
#include "stdafx.h"
#include "C:\KPO\KPO_lab_06S\KPO_Lab_06L\Dictionary.h"

int main() {

#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1
#error "Only one macro from the list can be defined"
#endif

	setlocale(LC_ALL, "rus");

	try
	{

#ifdef TEST_CREATE_01
		Dictionary::Instance d8 = Dictionary::Create("Преподавателииииииииииииииииии", 120);
#endif 

#ifdef TEST_CREATE_02
		Dictionary::Instance d8 = Dictionary::Create("Преподаватели", 120);
#endif

		Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 5);
		Dictionary::Entry e1 = { 1, "Гадкий" }, e2 = { 2, "Веялкин" },
			e3 = { 3,"Смелов" }, e4 = { 4, "Урбманович" }, e5 = { 2, "Пацей" };

#ifdef TEST_GETENTRY_05
		Dictionary::Entry test05 = Dictionary::GetEntry(d1, 5);
#endif

#ifdef TEST_GETENTRY_06
		Dictionary::DelEntry(d1, 5);
#endif

#ifdef TEST_UPDENTRY_07
		Dictionary::UpdEntry(d1, 3, e5);
#endif

		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
		Dictionary::AddEntry(d1, e3);
		Dictionary::AddEntry(d1, e4);

#ifdef TEST_ADDENTRY_03
		Dictionary::Entry e6 = { 5, "Наркевич" }, e7 = { 6, "Наркевич" };
		Dictionary::AddEntry(d1, e6);
		Dictionary::AddEntry(d1, e7);
#endif

#ifdef TEST_ADDENTRY_04
		Dictionary::Entry e6 = { 1, "Наркевич" };
		Dictionary::AddEntry(d1, e6);
#endif

#ifdef TEST_UPDENTRY_08
		Dictionary::Entry e6 = { 1, "Наркевич" };
		Dictionary::UpdEntry(d1, 4, e6);
#endif
		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);
		Dictionary::DelEntry(d1, 2);
		Dictionary::Entry newEntry1 = { 6, "Гурин" };
		Dictionary::UpdEntry(d1, 3, newEntry1);
		Dictionary::Print(d1);
		Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
		Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };
		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::Entry newEntry3 = { 3, "Николаев" };
		Dictionary::UpdEntry(d2, 3, newEntry3);
		Dictionary::Print(d2);
		Dictionary::Delete(d1);
		Dictionary::Delete(d2);

#ifdef TEST_DICTIONARY

		Dictionary::Instance teachersDictionary = Dictionary::Create("Преподаватели", 7);
		Dictionary::Instance studentsDictionary = Dictionary::Create("Студенты", 7);

		Dictionary::Entry student1 = { 1, "Иванов" }, student2 = { 2, "Сидоров" },
			student3 = { 3, "Зайцев" }, student4 = { 4, "Голубев" }, student5 = { 5, "Шилов" },
			student6 = { 6, "Орлов" }, student7 = { 7, "Белов" };

		Dictionary::AddEntry(studentsDictionary, student1);
		Dictionary::AddEntry(studentsDictionary, student2);
		Dictionary::AddEntry(studentsDictionary, student3);
		Dictionary::AddEntry(studentsDictionary, student4);
		Dictionary::AddEntry(studentsDictionary, student5);
		Dictionary::AddEntry(studentsDictionary, student6);
		Dictionary::AddEntry(studentsDictionary, student7);

		Dictionary::Entry student15 = { 15, "Кузьмин" };
		Dictionary::UpdEntry(studentsDictionary, 3, student15);

		Dictionary::Entry teacher1 = { 1, "Сорокин" }, teacher2 = { 2, "Лапин" },
			teacher3 = { 3, "Рябов" }, teacher4 = { 4, "Крылов" }, teacher5 = { 5, "Королёв" },
			teacher6 = { 6, "Ершов" }, teacher7 = { 7, "Зимин" };

		Dictionary::AddEntry(teachersDictionary, teacher1);
		Dictionary::AddEntry(teachersDictionary, teacher2);
		Dictionary::AddEntry(teachersDictionary, teacher3);
		Dictionary::AddEntry(teachersDictionary, teacher4);
		Dictionary::AddEntry(teachersDictionary, teacher5);
		Dictionary::AddEntry(teachersDictionary, teacher6);
		Dictionary::AddEntry(teachersDictionary, teacher7);

		Dictionary::DelEntry(teachersDictionary, 3);
		Dictionary::Entry teacher8 = { 8, "Бобров" };
		Dictionary::AddEntry(teachersDictionary, teacher8);

		Dictionary::Print(studentsDictionary);
		Dictionary::Print(teachersDictionary);

		Dictionary::Entry teacher = Dictionary::GetEntry(teachersDictionary, 1);

		std::cout << "Данные студента:" << std::endl;
		std::cout << "Имя: " << teacher.name << std::endl;
		std::cout << "ID: " << teacher.id << std::endl;


		Dictionary::Delete(teachersDictionary);
		Dictionary::Delete(studentsDictionary);
#endif



	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	};

	system("pause");

	return 0;

}
