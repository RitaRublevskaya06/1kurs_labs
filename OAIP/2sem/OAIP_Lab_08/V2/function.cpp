#include "header.h"

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

int findMin(Node* front) {
    if (front == nullptr) {
        std::cout << "Очередь пуста." << std::endl;
        return -1;
    }

    int min = front->data;
    Node* current = front->next;
    while (current != nullptr) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }

    return min;
}

int countElementsBetween(Node* front, int minVal, int maxVal) {
    if (front == nullptr) {
        std::cout << "Очередь пуста." << std::endl;
        return 0;
    }

    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        if (current->data > minVal && current->data < maxVal) {
            count++;
        }
        current = current->next;
    }

    return count;
}
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

int dequeue(Node** front) {
    if (*front == nullptr) {
        std::cout << "Очередь пуста." << std::endl;
        return -1;
    }

    Node* temp = *front;
    int value = temp->data;
    *front = (*front)->next;

    delete temp;
    return value;
}

void display(Node* front) {
    Node* current = front;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void clearQueue(Node** front) {
    while (*front != nullptr) {
        Node* temp = *front;
        *front = (*front)->next;
        delete temp;
    }
}