#include <iostream>
#include <getopt.h>
#include "test.h"
using namespace std;

int main(int argc, char *argv[])
{
    const string words("words");
    const string checksum("checksum");
    bool select_file = false;
    bool select_word = false;
    Test testclass("");

    int rez = 0;
    while ( (rez = getopt(argc,argv,"hf:m:v:")) != -1)
    {
        switch (rez)
        {
            case 'h':
                cout << "Using: test -h | -f filename -m option [-v word]"
                         "\n\t-h the output current reference"
                         "\n\t-f file name"
                         "\n\t-m It takes an argument"
                         "\n\t\t \"checksum\" to output checksum"
                         "\n\t\t \"words\" It displays the number of words, the word is listed after the key \"-v\"";

                return 0;

            case 'f': testclass.setFile(optarg);
                select_file = true;
                break;

            case 'm':
                if (select_file)
                    if (optarg == checksum)
                    {
                        cout << "Checksum : " << testclass.checkSum();
                        return 0;
                    }
                    else
                        if (optarg == words)
                        {
                            select_word = true;
                        }
                break;

            case 'v':
                if (select_word)
                    cout << "number of word \"" << optarg << "\" : " << testclass.wordSum(optarg);
                    return 0;
        };
    }
    cout << "invalid arguments, please use -h to help";
    return 0;
}
