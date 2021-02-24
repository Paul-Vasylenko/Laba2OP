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
void countAveragePointsAndWrite(char*m, int*);

int main()
{
	
    (cin >> directory).get();//getting the directory and putting it into the char*
    setlocale(LC_ALL, " ");//ua language in files
    ofstream fOut;
    fOut.open("files\\result.csv", ios::trunc);//либо создаем файл, либо очищаем если он есть.
    fOut.close();
    //loop that does smth for every file .csv
    _finddata_t data;
    intptr_t handle = _findfirst(directory, &data);
    int numOfStudents=0;
    do {
        char* routeToFile = getFileRoute(data.name, directory);//e.g. of result -> "files\\students1.csv"
        countAveragePointsAndWrite(routeToFile, &numOfStudents);
    } while (_findnext(handle, &data) == 0);
    _findclose(handle);
    numOfStudents = numOfStudents * 0.4;
    cout << numOfStudents;
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

void countAveragePointsAndWrite(char* path, int *numOfStudents) {
   
    //на входе имеем пустой файл result.csv
    ifstream fIn;
    fIn.open(path);
    if (!fIn.is_open()) cout << "Error";
    else {
        fstream fOut;
        fOut.open("files\\result.csv", ios::app);
        string student;
        string surname;
        string isContract;
        string marks;
        
        while (!fIn.eof()) 
        {
            getline(fIn, student);
            int toSurname = student.find(',');
            surname = student.substr(0, toSurname);// student's surname
            int toContract = student.rfind(',');
            isContract = student.substr(toContract + 1, student.length());//is he contract? true:false
            marks = student.substr(toSurname + 1, toContract);
            int start = 0, end = 0;
            int mark; float result = 0;
            for (int i = 0; i < 5; i++) {
                end = marks.find(',', start);
                if (end > 0) {
                    mark = stoi(marks.substr(start, end));
                    result += mark;
                    start = end + 1;
                }
            }
            result = float(result) / 5.0;
            if (isContract == "FALSE" && result >= 60.0) {
                (*numOfStudents)++;
                fOut << surname << ";" << result << ";" << isContract << endl;
                
            }
        }
        fOut.close();
        
    }
    fIn.close();
    
}