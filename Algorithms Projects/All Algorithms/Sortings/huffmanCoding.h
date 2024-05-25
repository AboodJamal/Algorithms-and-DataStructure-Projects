#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

// Node structure for Huffman tree
struct Node
{
    char letter;
    int frequency; // occurrences of the letter
    Node* left, * right; //Node pointers to the left and right children 

    Node(char Character, int frequency) : letter(Character), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue 
// we can do it using struct 
// there should be an "operator()" function in the class or struct 
// or we can use a normal function with small differences in  syntax when calling it down in the declaration of the Priority Queue
class CompareNodes
{
public:
    bool operator()(Node* n1, Node* n2) {
        return n1->frequency > n2->frequency;
    }


};
class Huffman {
private:
    Node* root; // root Node 
    map<char, string> huffCodes;// Computes the binary code for each character using Huffman Coding Algorithm.
    map<char, int> huffCharFrequency; // Counts the occurrences for each character that appears in a paragraph 

    //used to generate Huffman codes
    void codeGenerator(Node* root, string code)
    {
        if (root == nullptr)
            return;

        // checking if the current node is a leaf node or not .. 
        //If it's a leaf node, it means that we've reached a character node in the Huffman tree.
        if (root->left == nullptr && root->right == nullptr)
        {
            huffCodes[root->letter] = code;
        }

        //the function makes recursive calls to visit its left and right children.
        codeGenerator(root->left, code + "0");
        codeGenerator(root->right, code + "1");
    }

public:
    Huffman(const string& text) {
        // Counting occurrences of each character
        for (char singleChar : text) {
            huffCharFrequency[singleChar]++;
        }

        // Huffman Coding Algorithm

        // the priority queue holds pointers of nodes with a vector container 
        // "CompareNodes" is comparison function used to order the elements in the priority queue.
        priority_queue<Node*, vector<Node*>, CompareNodes> huffManQueue;
        for (auto& nodeBucket : huffCharFrequency)
        {
            Node* newNodeBucket = new Node(nodeBucket.first, nodeBucket.second);
            huffManQueue.push(newNodeBucket);
        }
        //The loop ends when there's only one node left in the queue, which would be the root of the Huffman tree.
        while (huffManQueue.size() > 1)
        {
            Node* leftNode = huffManQueue.top();
            huffManQueue.pop();
            Node* rightNode = huffManQueue.top();
            huffManQueue.pop();

            int totalFrequency = leftNode->frequency + rightNode->frequency;
            Node* newNode = new Node(NULL, totalFrequency);
            newNode->left = leftNode;
            newNode->right = rightNode;

            huffManQueue.push(newNode);
        }

        root = huffManQueue.top();

        // Generate Huffman codes for each letter
        codeGenerator(root, "");
    }

    ~Huffman() {
        cleanup(root);
    }

    // deallocating memory for each node.
    void cleanup(Node* node)
    {
        if (node == nullptr)
            return;
        cleanup(node->left);
        cleanup(node->right);
        delete node;
    }

    //responsible for encoding a given text using the Huffman codes generated during the construction of the Huffman tree up.
    string encode(const string& newText)
    {
        string theEncode;
        for (char singleChar : newText)
        {
            theEncode += huffCodes[singleChar];
        }
        return theEncode;
    }

    // responsible for decoding a given encoded text using the Huffman tree. 
    string decode(const string& theEncode)
    {
        string theDecode;
        Node* currentNode = root;
        for (char bit : theEncode)
        {
            if (bit == '0') {
                currentNode = currentNode->left; // moves to the left child
            }
            else if (bit == '1') {
                currentNode = currentNode->right; // moves to the right child
            }
            // checks if  the current node is a leaf node (it has a character), it appends the character
            if (currentNode->letter != NULL)
            {
                theDecode += currentNode->letter;
                currentNode = root;
            }
        }
        return theDecode;
    }

    void printCodes()
    {
        cout << "Huffman Codes:" << endl;
        for (auto& entry : huffCodes) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }


    void printoccurrences()
    {
        cout << "Occurrences : " << endl;
        for (auto& entry : huffCharFrequency)
        {
            cout << entry.first << ": " << entry.second << endl;
        }
    }

};

// Done ÇáÍãÏááå


/*
int main()
{
    
    //"The program reads a text paragraph, counts character occurrences, computes Huffman codes,
    //then encodes and decodes strings using the generated codes, also outputting the total bits needed for encoding."
    

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

*/