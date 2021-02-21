#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <locale>
using namespace std;
/*
ofstream - write into file
ifstream - read from file
fstream - both
*/

char directory[200];
char* getFileRoute(char*, char*);
int countElem(char*);
int findSlash(char*, int);
void countAveragePoints(char*);

int main()
{
    (cin >> directory).get();//getting the directory and putting it into the char*
    setlocale(LC_ALL, " ");//ua language in files

    //loop that does smth for every file .csv
    _finddata_t data;
    intptr_t handle = _findfirst(directory, &data);
    do {
        char* routeToFile = getFileRoute(data.name, directory);//e.g. of result -> "files\\students1.csv"
        countAveragePoints(routeToFile);
    } while (_findnext(handle, &data) == 0);
    _findclose(handle);
    return 0;
}

char* getFileRoute(char* fName, char* dir) {
    int countDir = countElem(dir);//elements in char* dir
    int countFileName = countElem(fName);//elements in char* fName
    int slashDir = findSlash(dir, countDir);// position of last \ in dir
    for (int i = 0; i < countFileName; i++) {
        dir[i + slashDir + 1] = fName[i];
    }
    return dir;
}

int countElem(char* arr) {
    int count = 0;
    for (int i = 0; i < 200; i++)
    {
        if (arr[i] != arr[200]) {
            count++;
        }
    }
    return count;
}

int findSlash(char* arr, int size) {
    int position = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == '\\') position = i;
    }
    return position;
}

void countAveragePoints(char* path) {
    ifstream fIn;
    fIn.open(path);
    ofstream fOut;
    fOut.open("files\\result.csv");
    string student;
    while (!fIn.eof()) {
        getline(fIn, student);
        if (isdigit(4)) {
            cout << student << endl;
        }
        else {
            cout << student <<endl;
        }
    }
    
    
}