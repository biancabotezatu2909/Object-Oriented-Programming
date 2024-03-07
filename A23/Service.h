

#ifndef UNTITLED_SERVICE_H
#define UNTITLED_SERVICE_H
#pragma once
#include "Repository.h"

typedef struct {
    Repository* repository;
    DynamicArray* undoStack;
    int undoPointer;
}Service;

/*
 * creates an instance of a service and returns it
 */
Service* createService(Repository* repository);

/*
 * destroys the given service
 */
void destroyService(Service* service);

/*
 * returns the repository for the given service
 */
Repository* getRepository(Service* service);

/*
 * returns 1 if the product was successfully added
 * 0 otherwise
 */
int add(Service* service, char* name, char* category, int quantity, Expiration_date date);

/*
 * returns 1 if a product with a given name was deleted
 * 0 otherwise
 */
int deleteProductServ(Service* service, char* name);

/*
 * returns 1 if the update of a product given by the name was successfully done
 * 0 otherwise
 */
int update(Service* service, char* name, int newQuantity, Expiration_date date);


/*
 *returns the countries for a given service
 */
DynamicArray* getProducts(Service* service);

/*
 * Sorts the elements of a dynamic array containing products based on the quantity,
 * the sort is done in ascending order
 */
void sortProductsVectorAscendingByQuantity(DynamicArray* arr);
int undo(Service* service);
int redo(Service* service);

#endif //UNTITLED_SERVICE_H
