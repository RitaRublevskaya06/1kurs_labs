#include "Dictionary.h"

Dictionary::Instance Dictionary::Create(std::string name, int size) {

	if (DICTNAMEMAXSIZE < name.size()) { throw THROW01; }
	if (DICTMAXSIZE < size) { throw THROW02; }

	Instance newDictionary;

	newDictionary.name = name;
	newDictionary.maxSize = size;

	newDictionary.dictionary = new Entry[size];

	for (int i = 0; i < size; i++) {

		(newDictionary.dictionary + i)->id = NULL;
		(newDictionary.dictionary + i)->name = "";
	}

	newDictionary.size = 0;

	return newDictionary;
}

void Dictionary::AddEntry(Instance& inst, Entry ed) {

	if (inst.size >= inst.maxSize) { throw THROW03; }

	for (int i = 0; i < inst.maxSize; i++) {

		if ((inst.dictionary + i)->id == ed.id) { throw THROW04; }

	}

	int addID{};

	++inst.size;

	for (int i = 0; i < inst.maxSize; i++) {

		if ((inst.dictionary + i)->id == NULL) {

			addID = i;
			break;

		}
	}

	(inst.dictionary + addID)->id = ed.id;
	(inst.dictionary + addID)->name = ed.name;
}

void Dictionary::DelEntry(Instance& inst, int id) {

	int deleteID = -1;

	for (int i = 0; i < inst.maxSize; i++) {

		if ((inst.dictionary + i)->id == id) {

			deleteID = i;
			break;
		}
	}

	if (deleteID == -1) { throw THROW06; }

	(inst.dictionary + deleteID)->id = NULL;
	(inst.dictionary + deleteID)->name = "";

	inst.size--;
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) {

	int updID = -1;

	for (int i = 0; i < inst.maxSize; i++) {

		if ((inst.dictionary + i)->id == id) {

			updID = i;
			break;
		}
	}

	for (int i = 0; i < inst.maxSize; i++) {

		if (updID == i) { continue; }

		if ((inst.dictionary + i)->id == new_ed.id) { throw THROW08; }
	}

	if (updID == -1) { throw THROW07; }

	(inst.dictionary + updID)->id = new_ed.id;
	(inst.dictionary + updID)->name = new_ed.name;
}

Dictionary::Entry Dictionary::GetEntry(Instance inst, int id)
{
	int getID = -1;

	for (int i = 0; i < inst.maxSize; i++) {

		if ((inst.dictionary + i)->id == id) {

			getID = i;
			break;
		}
	}

	if (getID == -1) { throw THROW05; }

	return *(inst.dictionary + getID);
}

void Dictionary::Print(Instance d) {

	std::cout << "--------- " << d.name << " ---------" << std::endl;

	for (int i = 0; i < d.maxSize; i++) {

		if ((d.dictionary + i)->id == NULL) { continue; }

		std::cout << (d.dictionary + i)->id << " " << (d.dictionary + i)->name << std::endl;
	}
}

void Dictionary::Delete(Instance& d) {

	delete[] d.dictionary;
	d.dictionary = nullptr;

	d.name = "";
	d.size = NULL;
	d.maxSize = NULL;
}