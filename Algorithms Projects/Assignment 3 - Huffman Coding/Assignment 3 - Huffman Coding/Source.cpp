#include<iostream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include"huffMan.h"
using namespace std;

int main()
{
    /*
    "The program reads a text paragraph, counts character occurrences, computes Huffman codes,
    then encodes and decodes strings using the generated codes, also outputting the total bits needed for encoding."
    */

    string paragraph;
    cout << "Enter a text paragraph: ";
    getline(cin, paragraph);

    Huffman huffman(paragraph);
    huffman.printoccurrences();
    huffman.printCodes();



    // Encode and print text
    cout << "Enter a string to encode: ";
    string newText;
    getline(cin, newText);
    string encodedString = huffman.encode(newText);
    cout << "Encoded string: " << encodedString << endl;
    cout << "Total bits : " << encodedString.length() << endl;


    // Decode and print binary sequence
    cout << "Enter binary sequence to decode: ";
    string binarySequence;
    cin >> binarySequence;
    string decodedText = huffman.decode(binarySequence);
    cout << "Decoded Text: " << decodedText << endl;

    return 0;
}