#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const string BARCODES[] = {
    "||:::", // 0
    ":::||", // 1
    "::|:|", // 2
    "::||:", // 3
    ":|::|", // 4
    ":|:|:", // 5
    ":||::", // 6
    "|:::|", // 7
    "|::|:", // 8
    "|:|::", // 9
};

int computeCheckDigit(const string& zipcode) {
    int sum = 0;
    for (char c : zipcode) {
        if (!isdigit(c)) {
            cerr << "Invalid character: " << c << endl;
            exit(1);
        }
        sum += c - '0';
    }
    int check = (10 - (sum % 10)) % 10;
    return check;
}

string generateBarcode(const string& zipcode) {
    int check = computeCheckDigit(zipcode);
    string barcode = "|";
    for (char c : zipcode) {
        if (!isdigit(c)) {
            cerr << "Invalid character: " << c << endl;
            exit(1);
        }
        int digit = c - '0';
        barcode += BARCODES[digit];
    }
    barcode += BARCODES[check] + "|";
    return barcode;
}

int main() {
    string zipcode;
    while (true) {
        cout << "Enter a 5-digit zip code (or 'q' to quit): ";
        cin >> zipcode;
        if (zipcode == "q") {
            break;
        }
        if (zipcode.size() != 5) {
            cerr << "Invalid length: " << zipcode.size() << endl;
            continue;
        }
        string barcode = generateBarcode(zipcode);
        cout << barcode << endl;
    }
    return 0;
}