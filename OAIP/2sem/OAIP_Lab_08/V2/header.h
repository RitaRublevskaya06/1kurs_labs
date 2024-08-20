#pragma once


#include <iostream>
struct Node {
    int data;
    Node* next;
};

void enqueue(Node** front, Node** rear, int value);
int dequeue(Node** front);
void display(Node* front);
void clearQueue(Node** front);
int findMax(Node* front);
int findMin(Node* front);
int countElementsBetween(Node* front, int minVal, int maxVal);