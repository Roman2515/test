#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

class Test{
public:
    Test(const string & fname = "") { filename = fname; }
    void setFile(const string & fname) { filename = fname; }
    int wordSum(const string & findword);
    uint32_t checkSum();
    void printText();
private:
    ifstream clientfile;
    string filename;
    void openFile();
};



void Test::openFile()
{

     clientfile.open(filename, ios::in);
     if (!clientfile)
     {
         cerr << "File could not be opened" << endl;
         exit(1);
     }
}

void Test::printText()
{
    openFile();
    string buffstring;
    while(clientfile >> buffstring)
    {
        cout << buffstring << ' ';
    }
    clientfile.close();
}

int Test::wordSum(const string & findword)
{
    openFile();
    string buffstring;
    int entry = 0;
    while (!clientfile.eof())
    {
        getline(clientfile, buffstring);
        size_t pos = 0;
        while (true)
        {
            pos = buffstring.find(findword, pos);
            if (pos != string::npos)
            {
                entry++;
                pos += findword.size();
            } else break;
        }
    }

    clientfile.close();
    return entry;
}

uint32_t Test::checkSum()
{
    ifstream clientfilebinary(filename, ios_base::binary);
    if (!clientfilebinary)
    {
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    uint32_t word, sum = 0;
    while(!clientfilebinary.eof())
    {
        clientfilebinary.read((char*)&word, 4);
        sum += word;
    }

    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    clientfilebinary.close();
    return sum;
}

#endif // TEST_H
