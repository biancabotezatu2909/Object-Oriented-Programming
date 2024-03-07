#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
#include "string.h"

#pragma once

using namespace std;

class Validator
{
public:
    /// With this function we validate the color of the product
    /// \param color the color of the product
    /// \return returns true if the color is valid and false otherwise
    bool validateGenre(string genre);

    /// With this function we validate the size of the product
    /// \param size the size of the product
    /// \return it returns true if the size is valid and false otherwise
    bool validateYearOfRelease(int year);

    /// With this function we validate the price of the product
    /// \param price the price of the product
    /// \return it returns the integer form of the price if it is valid or -1 otherwise
    bool validateNumberOfLikes(int likes);

    /// With this function we validate the quantity of the product
    /// \param quantity the quantity of the product
    /// \return it returns the integer form of the quantity if it is valid and -1 otherwise
    bool validateSource(string source);

    /// With this function we validate the link of the photograph
    /// \param photograph the link to the photograph of the product
    /// \return it returns true if the link is valid and false otherwise
    //bool validate_photograph_product(string photograph);
};


#endif