#include <iostream>
#include <string>
#include "routecipher.h"


bool isNumber(const std::string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    std::string key_str;
    int key;
    std::string text;
    unsigned op;

    std::cout << "The route transposition cipher is ready. Enter the key (number of columns):";
    std::cin >> key_str;

    if (!isNumber(key_str)) {
        std::cerr << "Error: The key must be a positive number.\n";
        return 1;
    }
    key = std::stoi(key_str);
    if (key <= 0) {
        std::cerr << "Error: The key must be a positive number.\n";
        return 1;
    }

    std::cout << "Key successfully set.\n";
    RouteCipher cipher(key);

    do {
        std::cout << "\nSelect an operation (0-Exit, 1-Encrypt, 2-Decrypt): ";
        std::cin >> op;

        if (op == 0) {
            std::cout << "Exiting the program.\n";
        } else if (op == 1 || op == 2) {
            std::cout << "Enter text: ";
            std::cin.ignore();
            std::getline(std::cin, text);

            if (op == 1) {
                std::string encrypted = cipher.encrypt(text);
                std::cout << "Encrypted text: " << encrypted << std::endl;
            } else {
                std::string decrypted = cipher.decrypt(text);
                std::cout << "Decrypted text: " << decrypted << std::endl;
            }
        } else {
            std::cout << "Error: Unknown operation.\n";
        }
    } while (op != 0);

    return 0;
}