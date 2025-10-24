#include "routecipher.h"
#include <vector>
#include <string>

RouteCipher::RouteCipher(int k) : key(k) {
}

std::string RouteCipher::encrypt(const std::string& open_text)
{
    int len = open_text.length();
    int rows = (len + key - 1) / key;

    std::vector<std::vector<char>> table(rows, std::vector<char>(key, ' '));

    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < key; ++j) {
            if (index < len) {
                table[i][j] = open_text[index];
                index++;
            }
        }
    }

    std::string cipher_text;
    for (int j = key - 1; j >= 0; --j) {
        for (int i = 0; i < rows; ++i) {
            if (table[i][j] != ' ' || (i * key + j) < len) {
                cipher_text += table[i][j];
            }
        }
    }
    return cipher_text;
}

std::string RouteCipher::decrypt(const std::string& cipher_text)
{
    int len = cipher_text.length();
    int rows = (len + key - 1) / key;
    int total_cells = rows * key;
    int empty_cells = total_cells - len;

    std::vector<std::vector<char>> table(rows, std::vector<char>(key, '\0'));

    int text_index = 0;
    for (int j = key - 1; j >= 0; --j) {
        for (int i = 0; i < rows; ++i) {
            bool is_empty = (i == rows - 1) && (j >= (key - empty_cells));
            if (!is_empty && text_index < len) {
                table[i][j] = cipher_text[text_index];
                text_index++;
            }
        }
    }

    std::string open_text;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < key; ++j) {
            if (table[i][j] != '\0') {
                open_text += table[i][j];
            }
        }
    }
    return open_text;
}