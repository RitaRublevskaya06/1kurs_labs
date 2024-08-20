#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Flight {
    int flightNumber;
    string destination;
    string departureTime;
    string departureDate;
    float ticketPrice;
    int availableSeats;
};

void inputFlightInfo(Flight& flight) {
    cout << "Введите номер рейса: ";
    cin >> flight.flightNumber;
    cin.ignore();
    cout << "Введите пункт назначения: ";
    getline(cin, flight.destination);
    cout << "Введите время вылета: ";
    getline(cin, flight.departureTime);
    cout << "Введите дату вылета: ";
    getline(cin, flight.departureDate);
    cout << "Введите стоимость билета: ";
    cin >> flight.ticketPrice;
    cout << "Введите количество мест: ";
    cin >> flight.availableSeats;
}

void writeFlightToFile(const Flight& flight, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << flight.flightNumber << ", " << flight.destination << ", " << flight.departureTime << ", " << flight.departureDate << ", " << flight.ticketPrice << ", " << flight.availableSeats << "\n";
        file.close();
    }
    else {
        cout << "Ошибка открытия файла для записи." << endl;
    }
}

void displayAllFlights(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "Информация о всех рейсах:" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Ошибка открытия файла для чтения." << endl;
    }
}

void searchFlightByDestination(const string& destination, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        bool found = false;
        cout << "Рейсы с пунктом назначения '" << destination << "':" << endl;
        while (getline(file, line)) {
            size_t foundPos = line.find(destination);
            if (foundPos != string::npos) {
                cout << line << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Рейсов с заданным пунктом назначения не найдено." << endl;
        }
        file.close();
    }
    else {
        cout << "Ошибка открытия файла для чтения." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    const string filename = "flights.txt";
    Flight flights[3];

    cout << "Введите информацию о 3 рейсах" << endl << endl;

    for (int i = 0; i < 3; i++) {
        inputFlightInfo(flights[i]);
        writeFlightToFile(flights[i], filename);
        cout << endl;
    }

    displayAllFlights(filename);

    string destinationToSearch;
    cout << "Введите пункт назначения для поиска: ";
    getline(cin, destinationToSearch);
    searchFlightByDestination(destinationToSearch, filename);

    return 0;
}