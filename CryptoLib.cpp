#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>

using namespace std;

string xor_encoder(string text, int key) {
    string res(text);

    for (int i = 0; i < (int)text.length(); i++) {
        res[i] = text[i] ^ key;
    }

    return res;
}

string ceasar_encrypt(string text, int key) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (c > 'A' && c < 'Z') {
            c = ((c - 'A' + key) % 26) + 'A';
        }

        if (c > 'a' && c < 'z') {
            c = ((c - 'a' + key) % 26) + 'a';
        }

        result += c;
    }

    return result;
}

string ceasar_decrypt(string text, int key) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (c > 'A' && c < 'Z') {
            c = ((c - 'A' - key) % 26) + 'A';
        }

        if (c > 'a' && c < 'z') {
            c = ((c - 'a' - key) % 26) + 'a';
        }

        result += c;
    }

    return result;
}

string bin_encrypt(string text) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        bitset<8> set(bitset<8>(text[i]));
        result += set.to_string();
    }

    return result;
}

string bin_decrypt(string text) {
    string result = "";

    for (int i = 0; i < text.length(); i+=8) {
        result += (char)stoi(text.substr(i, 8), 0, 2);
    }

    return result;
}

string encrypt(string text) {
    vector<char> word(text.begin(), text.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j < alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j + 3) % 26];

                break;
            }
        }
    }

    string str(word.begin(), word.end());
    return str;
}

string decrypt(string text) {
    vector<char> word(text.begin(), text.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j < alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j - 3) % 26];

                break;
            }
        }
    }

    string str(word.begin(), word.end());
    return str;
}
