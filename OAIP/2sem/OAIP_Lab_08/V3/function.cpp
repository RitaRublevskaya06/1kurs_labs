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
        std::cout << "Очередь пуста." << std::endl;
        return;
    }

    Node* temp = *front;
    *front = (*front)->next;
    delete temp;
}

void display(Node* front) {
    if (front == nullptr) {
        std::cout << "Очередь пуста." << std::endl;
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

int findMax(Node* front) {
    if (front == nullptr) {
        std::cout << "Очередь пуста." << std::endl;
        return -1;
    }

    int max = front->data;
    Node* current = front->next;
    while (current != nullptr) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }

    return max;
}