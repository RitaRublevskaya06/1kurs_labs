#pragma once

#include <iostream>
#include <fstream>

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* head;
};

void push(Stack* stack, int data);
void pop(Stack* stack);
void display(Stack* stack);
void saveToFile(Stack* stack, const char* filename);
void readFromFile(Stack* stack, const char* filename);
void clear(Stack* stack);
void splitStack(Stack* mainStack, Stack* positiveStack, Stack* negativeStack);