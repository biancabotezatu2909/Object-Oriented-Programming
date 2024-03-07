

#ifndef UNTITLED_UI_H
#define UNTITLED_UI_H
#pragma once
#include "Service.h"
#include "Product.h"

typedef struct {
    Service* service;
}Ui;

Ui* createUi(Service* service);
void destroyUi(Ui* ui);

void printMenu();
int handleAddProduct(Ui* ui);
int handleDeleteProduct(Ui* ui);


void start(Ui* ui);
#endif //UNTITLED_UI_H
