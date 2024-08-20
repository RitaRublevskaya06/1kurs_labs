#include "header.h"

void push(Stack* stack, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = stack->head;
    stack->head = newNode;
}

void pop(Stack* stack) {
    if (stack->head != nullptr) {
        Node* temp = stack->head;
        stack->head = stack->head->next;
        delete temp;
    }
}

void display(Stack* stack) {
    Node* current = stack->head;
    std::cout << "Стек: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void saveToFile(Stack* stack, const char* filename) {
    std::ofstream file(filename);
    Node* current = stack->head;
    while (current != nullptr) {
        file << current->data << std::endl;
        current = current->next;
    }
    file.close();
}

void readFromFile(Stack* stack, const char* filename) {
    clear(stack);
    std::ifstream file(filename);
    int data;
    while (file >> data) {
        push(stack, data);
    }
    file.close();
}

void clear(Stack* stack) {
    while (stack->head != nullptr) {
        pop(stack);
    }
}


void deleteFirstNegative(Stack* stack) {
    Node* current = stack->head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data < 0) {
            if (prev != nullptr) {
                prev->next = current->next;
                delete current;
                break;  // Удаляем только первый отрицательный элемент
            }
            else {
                Node* temp = current;
                stack->head = current->next;
                delete temp;
                break;  // Удаляем только первый отрицательный элемент
            }
        }
        prev = current;
        current = current->next;
    }
}
