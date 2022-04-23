#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    cout << "Hello, World!" << endl;

    if (argc < 3) {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    ofstream out(argv[2]);
    if (!out) {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    return 0;
}
