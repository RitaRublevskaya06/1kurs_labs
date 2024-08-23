#pragma once

#include <string>
#include <iostream>

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной емкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идетификатора"

namespace Dictionary {

	struct Entry {

		int id;
		std::string name;
	};

	struct Instance {

		std::string name;
		int maxSize;
		int size;
		Entry* dictionary;
	};

	Instance Create(std::string name, int size);
	void AddEntry(Instance& inst, Entry ed);
	void DelEntry(Instance& inst, int id);
	void UpdEntry(Instance& inst, int id, Entry new_ed);
	Entry GetEntry(Instance inst, int id);
	void Print(Instance d);
	void Delete(Instance& d);

};
