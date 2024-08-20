#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void permute(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        for (int i = start; i <= end; i++) {
            swap(arr[start], arr[i]);
            permute(arr, start + 1, end);
            swap(arr[start], arr[i]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 5;
    int numbers[n] = { 1, 2, 3, 4, 5 };

    permute(numbers, 0, n - 1);

    return 0;
}
