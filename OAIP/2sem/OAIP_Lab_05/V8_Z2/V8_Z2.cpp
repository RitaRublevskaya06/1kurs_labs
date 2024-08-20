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
    cout << "������� ����� �����: ";
    cin >> flight.flightNumber;
    cin.ignore();
    cout << "������� ����� ����������: ";
    getline(cin, flight.destination);
    cout << "������� ����� ������: ";
    getline(cin, flight.departureTime);
    cout << "������� ���� ������: ";
    getline(cin, flight.departureDate);
    cout << "������� ��������� ������: ";
    cin >> flight.ticketPrice;
    cout << "������� ���������� ����: ";
    cin >> flight.availableSeats;
}

void writeFlightToFile(const Flight& flight, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << flight.flightNumber << ", " << flight.destination << ", " << flight.departureTime << ", " << flight.departureDate << ", " << flight.ticketPrice << ", " << flight.availableSeats << "\n";
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

void displayAllFlights(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "���������� � ���� ������:" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

void searchFlightByDestination(const string& destination, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        bool found = false;
        cout << "����� � ������� ���������� '" << destination << "':" << endl;
        while (getline(file, line)) {
            size_t foundPos = line.find(destination);
            if (foundPos != string::npos) {
                cout << line << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "������ � �������� ������� ���������� �� �������." << endl;
        }
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    const string filename = "flights.txt";
    Flight flights[3];

    cout << "������� ���������� � 3 ������" << endl << endl;

    for (int i = 0; i < 3; i++) {
        inputFlightInfo(flights[i]);
        writeFlightToFile(flights[i], filename);
        cout << endl;
    }

    displayAllFlights(filename);

    string destinationToSearch;
    cout << "������� ����� ���������� ��� ������: ";
    getline(cin, destinationToSearch);
    searchFlightByDestination(destinationToSearch, filename);

    return 0;
}