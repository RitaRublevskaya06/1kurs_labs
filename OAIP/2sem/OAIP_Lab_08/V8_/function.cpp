#include "header.h"

void enqueue(Node** front, Node** rear, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (*rear == nullptr) {
        *front = *rear = newNode;
    }
    else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void dequeue(Node** front) {
    if (*front == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    Node* temp = *front;
    *front = (*front)->next;
    delete temp;
}

void display(Node* front) {
    if (front == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    Node* current = front;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int size_1(Node* front) {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue(Node** front) {
    while (*front != nullptr) {
        dequeue(front);
    }
}



void removeFirstNegativeAnywhere(Node** front) {
    Node* current = *front;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data < 0) {
            if (prev == nullptr) {
                dequeue(front); // Если первый элемент отрицательный
            }
            else {
                prev->next = current->next;
                delete current;
            }
            return;
        }
        prev = current;
        current = current->next;
    }

    std::cout << "Отрицательный элемент не найден." << std::endl;
}
