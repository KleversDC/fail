#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//void CompareFiles(const char* file1, const char* file2) {
//    ifstream f1(file1);
//    ifstream f2(file2);
//
//    if (!f1.is_open() || !f2.is_open()) {
//        cout << "Error opening one of the files." << endl;
//        return;
//    }
//
//    string line1, line2;
//    int lineNumber = 1;
//    bool filesAreIdentical = true;
//
//    while (getline(f1, line1) && getline(f2, line2)) {
//        if (line1 != line2) {
//            cout << "Difference at line " << lineNumber << ":" << endl;
//            cout << "File 1: " << line1 << endl;
//            cout << "File 2: " << line2 << endl;
//            filesAreIdentical = false;
//        }
//        lineNumber++;
//    }
//    while (getline(f1, line1)) {
//        cout << "File 1 has extra line " << lineNumber << ": " << line1 << endl;
//        lineNumber++;
//        filesAreIdentical = false;
//    }
//
//    while (getline(f2, line2)) {
//        cout << "File 2 has extra line " << lineNumber << ": " << line2 << endl;
//        lineNumber++;
//        filesAreIdentical = false;
//    }
//
//    if (filesAreIdentical) {
//        cout << "The files are identical." << endl;
//    }
//
//    f1.close();
//    f2.close();
//}
//
//int main() {
//    CompareFiles("file1.txt", "file2.txt");
//}





//bool IsVowel(char c) {
//    char vowels[] = "AEIOUYaeiouyАЕЁИОУЫЭЮЯаеёиоуыэюя";
//    for (int i = 0; vowels[i] != '\0'; i++) {
//        if (c == vowels[i]) return true;
//    }
//    return false;
//}
//
//bool IsConsonant(char c) {
//    return isalpha(c) && !IsVowel(c);
//}
//
//void FileStatistics(const char* inputFile, const char* outputFile) {
//    ifstream in(inputFile);
//    ofstream out(outputFile);
//
//    if (!in.is_open()) {
//        cout << "Error opening input file." << endl;
//        return;
//    }
//
//    int characters = 0, lines = 0, vowels = 0, consonants = 0, digits = 0;
//    char c;
//
//    while (in.get(c)) {
//        characters++;
//        if (c == '\n') lines++;
//        if (isdigit(c)) digits++;
//        if (IsVowel(c)) vowels++;
//        if (IsConsonant(c)) consonants++;
//    }
//
//    out << "Characters: " << characters << endl;
//    out << "Lines: " << lines + 1 << endl;
//    out << "Vowels: " << vowels << endl;
//    out << "Consonants: " << consonants << endl;
//    out << "Digits: " << digits << endl;
//
//    in.close();
//    out.close();
//}
//
//int main() {
//    FileStatistics("input.txt", "statistics.txt");
//}




char CaesarCipher(char c, int shift) {
    if (isalpha(c)) {
        char base = islower(c) ? 'а' : 'А';
        return base + (c - base + shift) % 32;
    }
    return c;
}

void EncryptFileCaesar(const char* inputFile, const char* outputFile, int shift) {
    ifstream in(inputFile);
    ofstream out(outputFile);

    if (!in.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    char c;
    while (in.get(c)) {
        out.put(CaesarCipher(c, shift));
    }

    in.close();
    out.close();
}

int main() {
    int shift = 3;
    EncryptFileCaesar("plain.txt", "encrypted.txt", shift);
}

