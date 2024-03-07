#include "Tests.h"
#include "Product.h"
#include "DynamicArray.h"
#include "Repository.h"
#include "Service.h"
#include "stdio.h"
#include "assert.h"


void testProduct()
{
    Expiration_date date, newDate;
    date.day = 1;
    date.month = 9;
    date.year = 2025;

    Product* product = createProduct("Product", "Category", 15, date);
    assert(strcmp(getName(product), "Product") == 0);
    assert(strcmp(getCategory(product), "Category") == 0);
    assert(getQuantity(product) == 15);
    setQuantity(product, 10);
    newDate.day = 20;
    newDate.month = 12;
    newDate.year = 2028;
    setDate(product, newDate);
    assert(getQuantity(product) == 10);
    assert(getDate(product).day == 20);
    assert(getDate(product).month == 12);
    assert(getDate(product).year == 2028);
    destroyProduct(product);

    printf("The Product test is ok!\n");
}

void testDynamicArray()
{
    DynamicArray* arr = createDynamicArray(10, (DestroyElementFunction)destroyProduct,
        (CopyElementFunction)copyProduct);
    Product* product = createProduct("Product", "Category", 30, createExpirationDate(1, 2, 2024));
    addElement(arr, product);
    assert(arr->length == 1);
    assert(getArrayLength(arr) == 1);
    Product* p = getElementAtIndex(arr, 0);
    assert(product->quantity == p->quantity);
    deleteElement(arr, 0);
    assert(arr->length == 0);
    destroyDynamicArray(arr);

    printf("The Dynamic array is ok!\n");
}


void testRepository()
{
    Repository* repository = createRepository(15);
    Product* product = createProduct("Product", "category", 13, createExpirationDate(2, 3, 2027));
    assert(getRepoProducts(repository) == repository->productsData);
    addProduct(repository, product);
    assert(repository->productsData->elements[0] == product);
    assert(getRepoLength(repository) == 1);
    updateProduct(repository, "Product", 10, createExpirationDate(4, 4, 2029));
    Product* p2 = createProduct("Product2", "category", 13, createExpirationDate(21, 3, 2024));
    addProduct(repository, p2);
    assert(getQuantity(repository->productsData->elements[0]) == 10);
    assert(strcmp(getCategory(repository->productsData->elements[0]), "category") == 0);
    deleteProduct(repository, "Product");
    assert(repository->productsData->length == 1);
    destroyRepository(repository);
    printf("The repository test is ok!\n");
}

void testService()
{

    Repository* repo = createRepository(15);

    Service* service = createService(repo);
    add(service, "Product", "category", 11, createExpirationDate(1, 2, 2029));
    assert(getRepoLength(service->repository) == 11);
    update(service, "Product", 100, createExpirationDate(3, 4, 2028));
    assert(getQuantity(service->repository->productsData->elements[10]) == 100);
    add(service, "Product2", "category2", 10, createExpirationDate(5, 6, 2025));
    assert(getQuantity(service->repository->productsData->elements[10]) == 100);
    printf("The service test is ok!\n");

    destroyService(service);
}

void testAll()
{
    testProduct();
    testDynamicArray();
    testRepository();
    testService();
}