#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;
using std::getline;

bool IsSSN(const string& ssn);
string ExtractSSN(const string& line);

int main() {
//    ExtractSSN("Johny, 123");
//    ExtractSSN("Alexander, 39999392920");

    string filename;
    cout << "What is the input filename: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (inputFile.fail()){
        cerr << "Cannot open file " << filename << endl;
        return 1;
    }
    string line, ssn;
    while (getline(inputFile, line)){
        ssn = ExtractSSN(line);
        if (IsSSN(ssn))
            cout << line << endl;
    }
    inputFile.close();
    return 0;
}

bool IsSSN(const string& ssn){
    string format = "###-##-####";
    if (ssn.length() != format.length())
        return false;
    for (size_t i = 0; i < format.length(); ++i) {
        if (format[i] == '#') {
            if (!isdigit(ssn[i]))
                return false;
        }else if (ssn[i] != '-')
            return false;
    }
    return true;
}

string ExtractSSN(const string &line) {
    size_t spacePosition = line.find(' ');
    return line.substr(spacePosition + 1, line.length() - spacePosition + 1) ;
}



















