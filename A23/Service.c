#include "Service.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

Service* createService(Repository* repository)
{
    Service* service = (Service*)malloc(sizeof(Service));
    if (service == NULL)
        return NULL;
    service->repository = repository;
    addTenElements(service->repository);
    service->undoStack = createDynamicArray(10, (DestroyElementFunction)destroyRepository,
        (CopyElementFunction)copyRepo);
    addElement(service->undoStack, copyRepo(service->repository));
    service->undoPointer = -1;
    return service;
}

void destroyService(Service* service)
{
    if (service == NULL)
        return;
    destroyRepository(service->repository);
    destroyDynamicArray(service->undoStack);

    free(service);
    service = NULL;
}

Repository* getRepository(Service* service)
{
    return service->repository;
}

void correctUndoPointer(Service* service)
{
    while (getArrayLength(service->undoStack) - 2 != service->undoPointer)
        deleteElement(service->undoStack, getArrayLength(service->undoStack) - 1);
}

void addToUndoList(Service* service)
{
    correctUndoPointer(service);
    addElement(service->undoStack, copyRepo(service->repository));
    service->undoPointer++;
}

int add(Service* service, char* name, char* category, int quantity, Expiration_date date)
{
    Product* product = createProduct(name, category, quantity, date);
    int returnValue = addProduct(service->repository, product);
    if (returnValue == 1)
        addToUndoList(service);
    return returnValue;
}

int deleteProductServ(Service* service, char* name)
{
    int returnValue = deleteProduct(service->repository, name);
    if (returnValue == 1)
        addToUndoList(service);
    return returnValue;
}

int update(Service* service, char* name, int newQuantity, Expiration_date newDate)
{
    int returnValue = updateProduct(service->repository, name, newQuantity, newDate);
    if (returnValue == 1)
        addToUndoList(service);
    return  returnValue;
}

DynamicArray* getProducts(Service* service)
{
    if (service == NULL)
        return NULL;
    return getRepoProducts(service->repository);
}

void sortProductsVectorAscendingByQuantity(DynamicArray* arr)
{
    if (arr == NULL)
        return;
    int ok = 0;
    do {
        ok = 1;
        for (int i = 1; i < arr->length; i++)
            if (getQuantity(arr->elements[i]) < getQuantity(arr->elements[i - 1]))
            {
                ok = 0;
                void* temp = arr->elements[i];
                arr->elements[i] = arr->elements[i - 1];
                arr->elements[i - 1] = temp;
            }
    } while (!ok);
}

int undo(Service* service)
{
    int undoStackLength = getArrayLength(service->undoStack);
    if (undoStackLength <= 1 || service->undoPointer < 0)
        return 0;
    else
    {
        destroyRepository(service->repository);
        service->repository = copyRepo(getElementAtIndex(service->undoStack, service->undoPointer));
        service->undoPointer--;
        return 1;
    }
}

int redo(Service* service)
{
    int undoStackLenght = getArrayLength(service->undoStack);
    if (service->undoPointer == undoStackLenght - 2 || service->undoPointer < -1)
        return 0;
    else
    {
        destroyRepository(service->repository);
        service->repository = copyRepo(getElementAtIndex(service->undoStack, service->undoPointer + 2));
        service->undoPointer++;
        return 1;
    }
}
