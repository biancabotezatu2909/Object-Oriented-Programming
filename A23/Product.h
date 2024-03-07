#pragma once

#ifndef UNTITLED_PRODUCT_H
#define UNTITLED_PRODUCT_H


/*
 * Creates a product which has 3 attributes - name, category, quantity, expiration date
 */

typedef struct
{
    int day;
    int month;
    int year;
}Expiration_date;

typedef struct
{
    char* name;
    char* category;
    int quantity;
    Expiration_date expiration_date;
}Product;

/*
 * Input: 3 parameters , 2 chars, an int, an Expiration_date type
 * Returns a product
 */

Expiration_date createExpirationDate(int day, int month, int year);
Product* createProduct(char* name, char* category, int quantity, Expiration_date expiration_date);

/*
 *Deletes a product and frees the memory
 */
void destroyProduct(Product* product);

/*
 * Returns a copy for a given product
 */
Product* copyProduct(Product* product);


/*
 * Getter functions for name, category, quantity, expiration_date
 */
char* getName(Product* product);
char* getCategory(Product* product);
int getQuantity(Product* product);
Expiration_date getDate(Product* product);


/*
 * Setter functions for continent and population
 */

void setQuantity(Product* product, int newQuantity);
void setDate(Product* product, Expiration_date newDate);

/*
 *Copy into the str[] parameter the format needed to print a product
 */
void toString(Product* product, char str[]);

#endif //UNTITLED_PRODUCT_H
