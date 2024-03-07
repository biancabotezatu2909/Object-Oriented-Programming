
#ifndef UNTITLED_REPOSITORY_H
#define UNTITLED_REPOSITORY_H
#include "Product.h"
#include "DynamicArray.h"
#include "stdlib.h"

typedef struct {
    DynamicArray* productsData;
}Repository;

/*
 * Creates a repository, only parameter represents the capacity of the repo
 */
Repository* createRepository(int capacity);

/*
 * destroys an existing repo
 */
void destroyRepository(Repository* repo);

/*
 * returns the length of the dynamic array in the repo
 */
int getRepoLength(Repository* repo);

/*
 * returns 1 if there exists an element in the dynamic array with the given name
 * 0 otherwise
 */
int findProduct(Repository* repository, char name[]);

/*
 * returns 1 if the given product was added successfully
 * 0 otherwise
 */
int addProduct(Repository* repository, Product* product);

/*
 * adds ten preset elements to a given repository
 */
void addTenElements(Repository* repository);

/*
 * returns 1 if a product with a given name was deleted
 * 0 otherwise
 */
int deleteProduct(Repository* repository, char name[]);

/*
 * returns 1 if the update of a product given by the name was successfully done
 * 0 otherwise
 */
int updateProduct(Repository* repository, char* name, int newQuantity, Expiration_date newDate);

/*
 * returns 1 if the migration process worked properly
 * 0 otherwise
 */
DynamicArray* getRepoProducts(Repository* repository);
Repository* copyRepo(Repository* repository);


#endif //UNTITLED_REPOSITORY_H
