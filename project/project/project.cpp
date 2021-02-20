#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
using namespace std;
/*
ofstream - write into file
ifstream - read from file
fstream - both
*/

char directory[200];

int main()
{
    (cin >> directory).get();
    setlocale(LC_CTYPE, "ukr");//ua language in files
    _finddata_t data;
    intptr_t handle = _findfirst(directory, &data);
    do {
        cout << data.name << endl;
    } while (_findnext(handle, &data) == 0);
    cin.get();
    _findclose(handle);
}
