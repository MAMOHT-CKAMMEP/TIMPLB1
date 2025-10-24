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

    std::cout << "Шифр маршрутной перестановки готов. Введите ключ (число-столбцов): ";
    std::cin >> key_str;

    if (!isNumber(key_str)) {
        std::cerr << "Ошибка: Ключ должен быть положительным числом.\n";
        return 1;
    }
    key = std::stoi(key_str);
    if (key <= 0) {
        std::cerr << "Ошибка: Ключ должен быть положительным числом.\n";
        return 1;
    }

    std::cout << "Ключ успешно установлен.\n";
    RouteCipher cipher(key);

    do {
        std::cout << "\nВыберите операцию (0-выход, 1-зашифровать, 2-расшифровать): ";
        std::cin >> op;

        if (op == 0) {
            std::cout << "Выход из программы.\n";
        } else if (op == 1 || op == 2) {
            std::cout << "Введите текст: ";
            std::cin.ignore();
            std::getline(std::cin, text);

            if (op == 1) {
                std::string encrypted = cipher.encrypt(text);
                std::cout << "Зашифрованный текст: " << encrypted << std::endl;
            } else {
                std::string decrypted = cipher.decrypt(text);
                std::cout << "Расшифрованный текст: " << decrypted << std::endl;
            }
        } else {
            std::cout << "Ошибка: Неизвестная операция.\n";
        }
    } while (op != 0);

    return 0;
}