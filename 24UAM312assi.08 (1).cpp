#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileEncryptor {
private:
    string filename;
    int encryptionKey;

    // XOR encryption/decryption
    string xorEncryptDecrypt(const string& input) {
        string output = input;
        for (size_t i = 0; i < input.length(); ++i) {
            output[i] = input[i] ^ encryptionKey;
        }
        return output;
    }

public:
    // Constructor
    FileEncryptor(string file, int key) {
        filename = file;
        encryptionKey = key;
    }

    // Encrypt and write to file
    void writeEncrypted(string message) {
        ofstream outFile(filename.c_str(), ios::binary); // .c_str() for older compilers
        if (!outFile) {
            cout << "Cannot open file for writing!" << endl;
            return;
        }

        string encrypted = xorEncryptDecrypt(message);
        outFile.write(encrypted.c_str(), encrypted.length());
        outFile.close();

        cout << "Message encrypted and saved." << endl;
    }

    // Read from file and decrypt
    void readDecrypted() {
        ifstream inFile(filename.c_str(), ios::binary); // .c_str() for older compilers
        if (!inFile) {
            cout << "Cannot open file for reading!" << endl;
            return;
        }

        string encrypted;
        char ch;
        while (inFile.get(ch)) {
            encrypted += ch;
        }
        inFile.close();

        string decrypted = xorEncryptDecrypt(encrypted);
        cout << "Decrypted message: " << decrypted << endl;
    }
};

// Main function
int main() {
    FileEncryptor encryptor("data.txt", 123); // filename and encryption key

    string message;
    cout << "Enter a message to encrypt: ";
    getline(cin, message);

    encryptor.writeEncrypted(message);

    cout << "\nReading from file and decrypting...\n";
    encryptor.readDecrypted();

    return 0;
}

