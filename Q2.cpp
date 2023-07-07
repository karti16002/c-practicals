#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.txt");    
    ofstream outputFile("output.txt");  

    if (!inputFile.is_open()) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    string line;
    int wordCount = 0;
    int lineCount = 0;
    int linesWithCPlusPlus = 0;

    while (getline(inputFile, line)) {
        lineCount++;
        if (line.find("C++") != string::npos) {
            linesWithCPlusPlus++;
        }

        string word;
        bool isFirstWord = true;
        for (char c : line) {
            if (isspace(c)) {
                if (!isFirstWord) {
                    wordCount++;
                }
                isFirstWord = true;
            } else {
                if (isFirstWord) {
                    isFirstWord = false;
                }
            }
        }

        wordCount++;
        outputFile << line << endl;
    }

    cout << "Number of words copied: " << wordCount << endl;
    cout << "Number of lines copied: " << lineCount << endl;
    cout << "Number of lines containing 'C++': " << linesWithCPlusPlus << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
