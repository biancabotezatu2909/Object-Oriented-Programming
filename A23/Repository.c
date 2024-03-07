#include "Repository.h"
#include "stdio.h"
#include <string.h>
#include "assert.h"
#include "stdlib.h"
#pragma once

Repository* createRepository(int capacity)
{
    Repository* repository = (Repository*)malloc(sizeof(Repository));
    if (repository == NULL)
        return NULL;
    repository->productsData = createDynamicArray(capacity, (DestroyElementFunction)destroyProduct,
        (CopyElementFunction)copyProduct);
    return repository;
}

void destroyRepository(Repository* repository)
{
    if (repository == NULL)
        return;
    destroyDynamicArray(repository->productsData);
    free(repository);
    repository = NULL;
}

int getRepoLength(Repository* repository)
{
    return repository->productsData->length;
}

int findProduct(Repository* repository, char name[])
{
    char* string;
    string = malloc(sizeof(char*));
    int length = getRepoLength(repository);
    for (int i = 0; i < length; i++)
    {
        if (strcmp(getName(repository->productsData->elements[i]), name) == 0)
            return i;
    }
    return -1;
}
void addOnlyQuantity(Repository* repository, Product* product, int newQuantity)
{
    int old_quantity = 0;
    for (int i = 0; i < repository->productsData->length; i++)
        if (strcmp(getName(repository->productsData->elements[i]), product->name) == 0)
            old_quantity = getQuantity(repository->productsData->elements[i]);
    updateProduct(repository, product->name, old_quantity + newQuantity, product->expiration_date);
}
int addProduct(Repository* repository, Product* product)
{
    int position = findProduct(repository, product->name);
    if (position == -1)
    {
        addElement(repository->productsData, product);
        return 1;
    }
    else
    {
        addOnlyQuantity(repository, product, product->quantity);
    }

}

void addTenElements(Repository* repository)
{
    Expiration_date date; 
    addProduct(repository, createProduct("milk", "dairy", 5, createExpirationDate(1, 2, 2027)));
    addProduct(repository, createProduct("apple", "fruit", 1, createExpirationDate(13, 12, 2025)));
    addProduct(repository, createProduct("chicken", "meat", 8, createExpirationDate(5, 5, 2026)));
    addProduct(repository, createProduct("blueberries", "fruit", 9, createExpirationDate(10, 7, 2024)));
    addProduct(repository, createProduct("chocolate", "sweets", 3, createExpirationDate(21, 8, 2028)));
    addProduct(repository, createProduct("mango", "fruit", 7, createExpirationDate(1, 2, 2027)));
    addProduct(repository, createProduct("cheese", "dairy", 2, createExpirationDate(5, 12, 2025)));
    addProduct(repository, createProduct("candy", "sweets", 3, createExpirationDate(4, 2, 2029)));
    addProduct(repository, createProduct("beef", "meat", 5, createExpirationDate(10, 2, 2027)));
    addProduct(repository, createProduct("yoghurt", "dairy", 8, createExpirationDate(8, 9, 2028)));
}

int deleteProduct(Repository* repository, char name[])
{
    int position = findProduct(repository, name);
    if (position != -1)
    {
        deleteElement(repository->productsData, position);
        return 1;
    }
    else
        return 0;
}

int updateProduct(Repository* repository, char* name, int newQuantity, Expiration_date newDate)
{
    int count = getArrayLength(repository->productsData);
    for (int i = 0; i < count; i++)
    {
        Product* product = getElementAtIndex(repository->productsData, i);
        if (strcmp(getName(product), name) == 0)
        {
            setQuantity(product, newQuantity);
            setDate(product, newDate);
            return 1;
        }
    }
    return 0;
}

DynamicArray* getRepoProducts(Repository* repository)
{
    if (repository == NULL)
        return NULL;
    return repository->productsData;
}

Repository* copyRepo(Repository* repository)
{
    Repository* newRepo = createRepository(repository->productsData->capacity);
    destroyDynamicArray(newRepo->productsData);
    newRepo->productsData = copyDynamicArray(repository->productsData);
    return newRepo;
}
