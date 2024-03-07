#include "Ui.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


Ui* createUi(Service* service)
{
    Ui* ui = malloc(sizeof(Ui));
    if (ui == NULL)
        return NULL;
    ui->service = service;
    return ui;
}

void destroyUi(Ui* ui)
{
    if (ui == NULL)
        return;
    destroyService(ui->service);
    free(ui);
}

int undoUi(Ui* ui) {
    return undo(ui->service);
}

int redoUi(Ui* ui) {
    return redo(ui->service);
}

void printMenu()
{
    printf("--------Menu---------\n");
    printf("0. Quit\n");
    printf("1. Print all products\n");
    printf("2. Add a product\n");
    printf("3. Delete a product\n");
    printf("4. Update a product\n");
    printf("5. Search by a substring\n");
    printf("6. Display products on a given category, in ascending order based on quantity\n");
    printf("7. Undo\n");
    printf("8. Redo\n");
    printf("........................\n");
}

void printSmallerMenu()
{
    printf("-------Categories-------\n");
    printf("0. No category\n");
    printf("1. Dairy\n");
    printf("2. Meat\n");
    printf("3. Sweets\n");
    printf("4. Fruit\n");
    printf("-------------------------\n");
}

void printAllProducts(Ui* ui) {
    int length = ui->service->repository->productsData->length;
    for (int i = 0; i < length; i++) {
        char str[100];
        toString(ui->service->repository->productsData->elements[i], str);
        printf("%d: %s \n", i + 1, str);
    }
}

int handleAddProduct(Ui* ui)
{
    char name[50], category[50];
    int quantity, day, month, year;
    Expiration_date date;
    printf("Please enter the name of the product: ");
    scanf("%49s", name);
    do {
        printf("Please enter a valid category: ");
        scanf("%s", category);
    } while (strcmp("dairy", category) != 0 && strcmp("meat", category) != 0 &&
        strcmp("sweets", category) != 0 && strcmp("fruit", category));
    do {
        printf("Please enter the quantity: ");
        scanf("%d", &quantity);
    } while (quantity <= 0);
    do {
        printf("Please enter the expiration date:\n ");
        printf("day: ");
        scanf("%d", &day);
        printf("month: ");
        scanf("%d", &month);
        printf("year: ");
        scanf("%d", &year);

    } while ((day > 31) || (month > 12));
    date = createExpirationDate(day, month, year);
    return add(ui->service, name, category, quantity, date);
}

int handleDeleteProduct(Ui* ui)
{
    char name[50];
    printf("Please enter the name of the product you want to be deleted: ");
    scanf("%s", name);
    return deleteProductServ(ui->service, name);
}


int handleUpdateProduct(Ui* ui) {
    char name[50];
    int newQuantity, day, month, year;
    Expiration_date newDate;
    printf("Please enter the name of the product you want to be updated: ");
    scanf("%s", name);

    do {
        printf("Please enter the quantity: ");
        scanf("%d", &newQuantity);
    } while (newQuantity <= 0);

    do {
        printf("Please enter the expiration date: ");
        printf("%day: ");
        scanf("%d", &day);
        printf("%month: ");
        scanf("%d", &month);
        printf("%year: ");
        scanf("%d", &year);
    } while ((day > 31) || (month > 12));
    newDate = createExpirationDate(day, month, year);
    return update(ui->service, name, newQuantity, newDate);
}

void start(Ui* ui) {
    while (1) {
        printMenu();
        printf(">>>");
        int option;
        scanf("%d", &option);
        if (option == 0) {
            return;
        }
        else if (option == 1) {
            printAllProducts(ui);
        }
        else if (option == 2) {
            int addResult = handleAddProduct(ui);
            if (addResult == 1)
                printf("Product successfully added! \n");
            else
                printf("Product can not be added! \n");
        }
        else if (option == 3) {
            int deleteResult = handleDeleteProduct(ui);
            if (deleteResult == 1)
                printf("Product successfully deleted! \n");
            else
                printf("Product can not be deleted \n");
        }
        else if (option == 4) {
            int updateResult = handleUpdateProduct(ui);
            if (updateResult == 1)
                printf("Product successfully updated! \n");
            else
                printf("Product can not be updated! \n");
        }

        else if (option == 5) {
            {
                char subString[100], str[100];
                subString[0] = '\0';
                printf("Enter substring: ");
                scanf("%c", &subString[0]);
                int i = -1;
                do {
                    i++;
                    scanf("%c", &subString[i]);
                    subString[i + 1] = '\0';
                } while (subString[i] != '\n');
                subString[i] = '\0';
                for (int k = 0; k < ui->service->repository->productsData->length; k++)
                {
                    if (strstr(getName(ui->service->repository->productsData->elements[k]), subString) != NULL)
                    {
                        toString(ui->service->repository->productsData->elements[k], str);
                        printf("%s\n", str);
                    }
                }
            }
        }
        else if (option == 6) {
            char str[100], category[100];
            int option_category, X;

            sortProductsVectorAscendingByQuantity(ui->service->repository->productsData);

            printf("Please enter the number of days until expiration date: ");
            scanf("%d", &X);
            Expiration_date today, expiration_date;
            today.day = 31;
            today.month = 3;
            today.year = 2023;
            expiration_date.month = today.month;
            expiration_date.day = today.day + X;
            while (expiration_date.day > 30)
            {
                expiration_date.day -= 31; //for every overflow of days in a month
                expiration_date.month += 1;
            }
            expiration_date.year = today.year;
            printSmallerMenu();
            scanf("%d", &option_category);
            if (option_category == 0)
                for (int i = 0; i < ui->service->repository->productsData->length; i++) {
                    if (getDate(ui->service->repository->productsData->elements[i]).year == expiration_date.year)
                        if (getDate(ui->service->repository->productsData->elements[i]).month < expiration_date.month)
                        {
                            toString(ui->service->repository->productsData->elements[i], str);
                            printf("%s\n", str);
                        }
                        else if (getDate(ui->service->repository->productsData->elements[i]).month == expiration_date.month)
                            if ((getDate(ui->service->repository->productsData->elements[i]).day < expiration_date.day))
                            {
                                toString(ui->service->repository->productsData->elements[i], str);
                                printf("%s\n", str);
                            }
                }

            if (option_category == 1)
                strcpy(category, "dairy");
            else if (option_category == 2)
                strcpy(category, "meat");
            else if (option_category == 3)
                strcpy(category, "sweets");
            else if (option_category == 4)
                strcpy(category, "fruit");
            for (int i = 0; i < ui->service->repository->productsData->length; i++) {
                if (strcmp(getCategory(ui->service->repository->productsData->elements[i]), category) == 0)
                    if(getDate(ui->service->repository->productsData->elements[i]).year == expiration_date.year)
                        if(getDate(ui->service->repository->productsData->elements[i]).month < expiration_date.month)
                    {
                        toString(ui->service->repository->productsData->elements[i], str);
                        printf("%s\n", str);
                    }
                        else if (getDate(ui->service->repository->productsData->elements[i]).month == expiration_date.month)
                            if((getDate(ui->service->repository->productsData->elements[i]).day < expiration_date.day))
                            {
                                toString(ui->service->repository->productsData->elements[i], str);
                                printf("%s\n", str);
                            }
            }

        }
        else if (option == 7) {
            int undoResult = undoUi(ui);
            if (undoResult == 1)
                printf("Operation successfully undone! \n");
            else
                printf("Operation cannot be undone! \n");
        }
        else if (option == 8) {
            int redoResult = redoUi(ui);
            if (redoResult == 1)
                printf("Operation successfully redone! \n");
            else
                printf("Operation cannot be redone \n");
        }
        else
            printf("Not a valid option! \n");
    }
}
