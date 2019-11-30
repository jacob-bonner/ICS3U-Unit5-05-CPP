// Copyright (c) 2019 Jacob Bonner All rights reserved.
//
// Created by: Jacob Bonner
// Created on: November 2019
// This program prints a mailing address in proper format

#include <iostream>
#include <string>

std::string MailingAddress(std::string recipientName,
                      std::string recipientAddress,
                      std::string recipientMunicipality,
                      std::string recipientProvince,
                      std::string recipientPostalCode,
                      std::string recipientApartmentNumber = "") {
    // This function makes a mailing address in proper format

    // Variables
    std::string postAddress;

    // Process
    if (recipientApartmentNumber.size() != 0) {
        postAddress = recipientName + "\n" + recipientApartmentNumber + \
                      + "-" + recipientAddress + "\n" + recipientMunicipality \
                      + " " + recipientProvince + "  " + recipientPostalCode;
    } else {
        postAddress = recipientName + "\n" + recipientAddress + "\n" + \
                      recipientMunicipality + " " + recipientProvince + \
                      "  " + recipientPostalCode;
    }
    return postAddress;
}

int main() {
    // This function collects mailing details then outputs a mailing address

    // Variables
    std::string userRecipientName;
    std::string userAddress;
    std::string question;
    std::string userMunicipality;
    std::string userProvince;
    std::string userPostalCode;
    std::string post;
    std::string userApartmentNumber = "";

    // Input
    std::cout << "Enter the recipient's full name:" << std::endl;
    std::getline(std::cin, userRecipientName);
    std::cout << "Enter the recipient's address (road & street number):"
              << std::endl;
    std::getline(std::cin, userAddress);
    std::cout << "Does the recipient live in an apartment (y/n):" << std::endl;
    std::getline(std::cin, question);
    if (question == "y" || question == "yes") {
        std::cout << "Enter the recipient's apartment number:" << std::endl;
        std::getline(std::cin, userApartmentNumber);
    }
    std::cout << "Enter the recipient's municipality:" << std::endl;
    std::getline(std::cin, userMunicipality);
    std::cout << "Enter the recipient's province/territory (abbreviate):"
              << std::endl;
    std::getline(std::cin, userProvince);
    std::cout << "Enter the recipient's postal code:" << std::endl;
    std::getline(std::cin, userPostalCode);;

    // Process
    if (userApartmentNumber != "") {
        post = MailingAddress(userRecipientName, userAddress, userMunicipality,
                              userProvince, userPostalCode,
                              userApartmentNumber);
    } else {
        post = MailingAddress(userRecipientName, userAddress, userMunicipality,
                              userProvince, userPostalCode);
    }

    // Output
    std::cout << "" << std::endl;
    std::cout << post << std::endl;
}
