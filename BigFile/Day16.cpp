//
// Created by rebek on 4/29/2022.
//

#include "Day16.h"

string convertToBITS(string hexa){
    string BITS = "";
    for (int i = 0; i < hexa.length(); i++){
        char currChar = hexa.at(i);
        if (currChar == '0'){
            BITS += "0000";
        } else if (currChar == '1'){
            BITS += "0001";
        } else if (currChar == '2'){
            BITS += "0010";
        } else if (currChar == '3'){
            BITS += "0011";
        } else if (currChar == '4'){
            BITS += "0100";
        } else if (currChar == '5'){
            BITS += "0101";
        } else if (currChar == '6'){
            BITS += "0110";
        } else if (currChar == '7'){
            BITS += "0111";
        } else if (currChar == '8'){
            BITS += "1000";
        } else if (currChar == '9'){
            BITS += "1001";
        } else if (currChar == 'A'){
            BITS += "1010";
        } else if (currChar == 'B'){
            BITS += "1011";
        } else if (currChar == 'C'){
            BITS += "1100";
        } else if (currChar == 'D'){
            BITS += "1101";
        } else if (currChar == 'E'){
            BITS += "1110";
        } else if (currChar == 'F'){
            BITS += "1111";
        } else if (currChar == 'G'){
            BITS += "1111";
        }
    }
    return BITS;
}

//string Day16::parseOperatorPacket(string packet){
//
//}

string Day16::parseLiteralPacket(string subpacket){
    //110100101111111000101000
    //VVVTTTAAAAABBBBBCCCCC
    int version = stoi(subpacket.substr(0,3),0,2);
    versionNumbers.push_back(version);
    int typeID = stoi(subpacket.substr(3,3), 0, 2);
    if (typeID != 4) cout << "error" << endl;
    string literal = subpacket.substr(6);

    string literalValue = "";
    bool cont = true;
    do {
        string fiveBits = literal.substr(0, 5);
        literalValue += fiveBits.substr(1);
        if (fiveBits.at(0) == '0') cont = false;
        literal = literal.substr(5);

    } while (cont);
    //int number = stoi(literalValue, 0, 2);
    //numbersFromString.push_back(number);

    return literal;
}
string Day16::parseSubpacket(string subpacket){
    int typeID = stoi(subpacket.substr(3,3), 0, 2);
    int version = stoi(subpacket.substr(0,3), 0, 2);

    versionNumbers2.push_back(version);
    int vers = addVersions(versionNumbers2);
    cout << vers << endl;
    if (vers == 53) {
        cout << "here" << endl;
    }
    string returning;
    if (typeID == 4){
        returning = parseLiteralPacket(subpacket);
    } else {
        returning = parsePacket(subpacket);
    }
    return returning;
}

string Day16::parsePacket(string packet){
    //00111000000000000110111101000101001010010001001000000000
    //VVVTTTILLLLLLLLLLLLLLLAAAAAAAAAAABBBBBBBBBBBBBBBB
    int version = stoi(packet.substr(0,3), 0, 2);
    versionNumbers.push_back(version);
    int typeID = stoi(packet.substr(3,3), 0, 2);

    int lengthIDType =  stoi(packet.substr(6,1) );
    string literal = packet.substr(7);
    if (lengthIDType == 0){
        string lengthOfSubpacket = literal.substr(0, 15);
        literal = literal.substr(15);
        int lengthOfSubPackets = stoi(lengthOfSubpacket, 0, 2);
        string subPackets = literal.substr(0, lengthOfSubPackets);
        literal = literal.substr(lengthOfSubPackets);
        bool cont = true;
        while(cont) {
            string leftOver = parseSubpacket(subPackets);
            subPackets = leftOver;
            if (subPackets == "") cont = false;
            //cout << subPackets << endl;
        }

    } else if (lengthIDType == 1){
        string numberOfSubPackets = literal.substr(0, 11);
        literal = literal.substr(11);
        int numberOfPackets = stoi(numberOfSubPackets, 0, 2);
        for (int i = 0; i < numberOfPackets; i++){
            string leftOver = parseSubpacket(literal);
            literal = leftOver;
            //cout << literal << endl;
        }
    }

    return literal;
}

int Day16::addVersions(vector<int> versions){
    int total = 0;
    for (int i = 0; i < versions.size(); i++){
        total += versions[i];
        //cout << versions[i] << endl;
    }
    return total;
}

int Day16::solve(){
    //cout << origString << endl;
    //string literalValue = "011011111011010011010101100110011101";
    //int number = stoi(literalValue, 0, 2);
    //cout << number << endl;

    string bits = convertToBITS(origString);
    //cout << bits;
    //parsePacket(bits);
    parseSubpacket(bits);
    int answer = addVersions(versionNumbers2);
    int otherAnswer = addVersions(versionNumbers);

    cout << "answer" << endl;
    return answer;
}