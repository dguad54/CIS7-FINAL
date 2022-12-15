#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

string Encrypt(string message, string key)
{
    string encryptedMessage;
    //transform(message.begin(), message.end(), message.begin(), ::toupper);
    for (int i = 0; i < message.size(); i++)
    {
        char a = (message[i] + key[i]) % 26;
        a += 'A';
        encryptedMessage.push_back(a);
    }
    return encryptedMessage;
}

string Decrypt(string message, string key)
{
    string decryptedMessage;
    //transform(message.begin(), message.end(), message.begin(), ::toupper);
    for (int i = 0; i < message.size(); i++)
    {
        char a = (message[i] - key[i]) % 26;
        a += 'A';
        decryptedMessage.push_back(a);
    }
    return decryptedMessage;
}

string keyMatch(string message, string key)
{
    int l = message.size();

    for (int i = 0; ; i++)
    {
        if (l == i)
            i = 0;
        if (key.size() == message.size())
            break;
        key.push_back(key[i]);
    }
    //transform(key.begin(), key.end(), key.begin(), ::toupper);
    return key;
}

int main()
{
    int choice;
    string message, key, fixedKey, encryptedmessage, decryptedmessage;
    cout << "Choose wheather to encrypt or decrypt: " << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter message to encrypt: " << endl;
        cin >> message;
        cout << "Enter the key: " << endl;
        cin >> key;
        fixedKey = keyMatch(message, key);
        encryptedmessage = Encrypt(message, key);
        cout << "Encrypted message: " << encryptedmessage << endl;
    }
    else if (choice == 2)
    {
        cout << "Enter message to decrypt: " << endl;
        cin >> message;
        cout << "Enter the key: " << endl;
        cin >> key;
        fixedKey = keyMatch(message, key);
        decryptedmessage = Decrypt(message, key);
        cout << "Decrypted message: " << decryptedmessage << endl;
    }

    else
        return 0;
}