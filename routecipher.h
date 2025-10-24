#pragma once
#include <string>
#include <vector>

class RouteCipher
{
private:
    int key; // Количество столбцов
public:
    RouteCipher() = delete; // Запрещаем конструктор без параметров
    RouteCipher(int k); // Конструктор с ключом
    std::string encrypt(const std::string& open_text); // Зашифрование
    std::string decrypt(const std::string& cipher_text); // Расшифрование
};