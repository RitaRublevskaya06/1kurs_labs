#pragma once

#include <iostream>
struct Node {
    int data;
    Node* next;
};

void enqueue(Node** front, Node** rear, int value);
void dequeue(Node** front);
void display(Node* front);
int size_1(Node* front);
void clearQueue(Node** front);
void removeFirstNegativeAnywhere(Node** front);