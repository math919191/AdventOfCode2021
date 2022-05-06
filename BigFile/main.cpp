#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Day20.h"
#include "Day15.h"
#include "Day16.h"
#include "Day18.h"
//#include "Day14.h"

using namespace std;

int main(int argc, char* argv[]) {

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
    vector<string> input;

    for (string line; getline(in, line);) {
        input.push_back(line);
    }

    Day15 puzzle(input);
    cout << endl << endl << puzzle.solve() << endl;
    //puzzle.part2();
    return 0;
}
