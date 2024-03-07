#include "Product.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include "assert.h"
#pragma once

Expiration_date createExpirationDate(int day, int month, int year)
{
    Expiration_date date;

    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

Product* createProduct(char* name, char* category, int quantity, Expiration_date expiration_date)
{
    Product* product = malloc(sizeof(Product));
    if (product == NULL)
        return NULL;
    product->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    product->category = (char*)malloc(sizeof(char) * (strlen(category) + 1));
    if (product->name != NULL)
        memcpy(product->name, name, strlen(name) + 1); // copies
    if (product->category != NULL)
        memcpy(product->category, category, strlen(category) + 1);
    product->quantity = quantity;
    product->expiration_date = expiration_date;
    return product;
}

void destroyProduct(Product* product)
{
    if (product == NULL)
    {
        return;
    }
    free(product->name);
    free(product->category);
    free(product);
    product = NULL;
}

Product* copyProduct(Product* product)
{
    if (product == NULL)
        return NULL;
    Product* product1 = createProduct(product->name, product->category, product->quantity, product->expiration_date);
    return product1;
}

char* getName(Product* product)
{
    if (product == NULL) {
        return NULL;
    }
    return product->name;
}

char* getCategory(Product* product)
{
    if (product == NULL) {
        return NULL;
    }
    return product->category;
}

int getQuantity(Product* product)
{
    if (product == NULL) {
        return -1;
    }
    return product->quantity;
}

Expiration_date getDate(Product* product)
{

    return product->expiration_date;
}

void setQuantity(Product* product, int newQuantity)
{
    product->quantity = newQuantity;
}

void setDate(Product* product, Expiration_date newDate)
{
    product->expiration_date = newDate;
}

void toString(Product* product, char str[])
{
    int day, month, year;
    if (product == NULL)
        return;
    day = product->expiration_date.day;
    month = product->expiration_date.month;
    year = product->expiration_date.year;

    sprintf(str, "Name: %s, Category: %s, Quantity: %d, Expiration date: %d/%d/%d", product->name, product->category, product->quantity, day, month, year);
}
