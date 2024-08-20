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
    std::cout << "стек: ";
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

void splitStack(Stack* mainStack, Stack* positiveStack, Stack* negativeStack) {
    clear(positiveStack);
    clear(negativeStack);

    Node* current = mainStack->head;
    while (current != nullptr) {
        if (current->data > 0) {
            push(positiveStack, current->data);
        }
        else if (current->data < 0) {
            push(negativeStack, current->data);
        }
        current = current->next;
    }
}