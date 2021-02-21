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
void workWithFile(char*, char*);
int countElem(char*);
int findStar(char*, int);

int main()
{
    (cin >> directory).get();//getting the directory and putting it into the char*
    setlocale(LC_CTYPE, "ukr");//ua language in files

    //loop that does smth for every file .csv
    _finddata_t data;
    intptr_t handle = _findfirst(directory, &data);
    do {
        workWithFile(data.name, directory);
    } while (_findnext(handle, &data) == 0);
    _findclose(handle);
    return 0;
}

void workWithFile(char* fName, char* dir) {
    int countDir = countElem(dir);
    int starDir = findStar(dir, countDir);
    cout << starDir << endl;
    //// fName = students1.csv;
    //int count = 0;
    ////calculating the size of dir
    //for (int i = 0; i < 20; i++)
    //{
    //    if (dir[i] != dir[21])
    //    {
    //        count++;
    //    }
    //}
    //cout << count;
    ////count = 11
    //int countfile = 0;
    ////calculating the size of fName
    //for (int i = 0; i < 20; i++)
    //{
    //    if (fName[i] != fName[21])
    //    {
    //        countfile++;
    //    }
    //}
    ////countfile = 12
    //string numberofStudents;
    //ifstream fIn;
    //int k = 0;
    ////find the position of * (files\\*.csv --> files\\)
    //for (int i = 0; i < count; i++) {
    //    if (dir[i] == '*') {
    //        for (int j = i; j < count; j++) {
    //            dir[j] = fName[k];
    //            k++;
    //        } 
    //    }
    //    
    //}
    //k++;
    //for (k; k < countfile; k++) {
    //    dir[count] = fName[k];
    //    count++;
    //}
    //    cout << dir << endl;
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

int findStar(char* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == '*') return i;
    }
}