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
void createRating(int, char*);
float findMaxMark(float*, string*);
int countStudents(float);
void writeAll(int, float, char*);

int main()
{
    (cin >> directory).get();//getting the directory and putting it into the char*
    setlocale(LC_ALL, " ");//ua language in files
    ofstream fOut1;
    fOut1.open("files\\result.csv", ios::trunc);//либо создаем файл, либо очищаем если он есть.
    fOut1.close();
    ofstream fOut2;
    fOut2.open("files\\rating.csv", ios::trunc);//либо создаем файл, либо очищаем если он есть.
    fOut2.close();
    //loop that does smth for every file .csv
    _finddata_t data;
    intptr_t handle = _findfirst(directory, &data);
    int numOfStudents = 0;
    do {
        char* routeToFile = getFileRoute(data.name, directory);//e.g. of result -> "files\\students1.csv"
        countAveragePointsAndWrite(routeToFile, &numOfStudents);
    } while (_findnext(handle, &data) == 0);
    _findclose(handle);
    numOfStudents = numOfStudents * 0.4;
    //here we have numOfStudents = 16.
    createRating(numOfStudents, directory);

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
                fOut << surname << ";";
                fOut.setf(ios::fixed);
                fOut.precision(3);
                fOut<< result << ";" << isContract << endl;
                (*numOfStudents)++;
            }
        }
        fOut.close();        
    }
    fIn.close();
}

void createRating(int numOfStudents, char* dir) {
    char ratingF[] = "rating.csv";
    char* fileRoute = getFileRoute(ratingF, dir); // result is files\\rating.csv
    ofstream fOut;
    fOut.open(fileRoute, ios::trunc);//create or empty file
    fOut.close();
    ifstream fIn;
    fIn.open("files\\result.csv");
    string student;
    if (!fIn.is_open())cout << "Error11";
    else {

        float max = 100.1;
        float mark=0;
        for (int i = 0; i < numOfStudents;) {
            getline(fIn, student);
            mark = findMaxMark(&max, &student); // max mark, 91.400 e.g.

            int number = countStudents(mark); // how many students with mark 91.400 ?
            if (number == 1) {//if there is only 1 student - write it down
                ofstream fOut;
                fOut.open(fileRoute, ios::app);
                if (!fOut.is_open())cout << "Error1";
                else {
                    fOut << student << endl;
                    i += number;
                }
                fOut.close();
            }
            else if (number > 1) { // if there are >=2 --> write every of them in func. writeAll()
                ofstream fOut;
                fOut.open(fileRoute, ios::app);
                if (!fOut.is_open())cout << "Error1";
                else {
                    writeAll(number, mark, fileRoute);//writing *number* of students with *mark* in *fileRoute* 
                    i += number;
                }
                fOut.close();
            }
        }
        cout.setf(ios::fixed);
        cout.precision(3);
        cout << "Min mark for scolarship: " << mark << endl;
    }
    fIn.close();
}


float findMaxMark(float* lessthan, string* student1) {
    ifstream fIn;
    fIn.open("files\\result.csv");
    if (!fIn.is_open())
        cout << "Error11";
    else {
        string student;
        float mark;
        string maxstudent;
        float max = 0;
        while (!fIn.eof()) {
            getline(fIn, student);
            if (student != "") {
                int start = student.find(';');
                int end = student.rfind(';');
                mark = stof(student.substr(start + 1, end - start - 1));
                if (mark<(*lessthan) && mark>max) {
                    max = mark;
                    maxstudent = student;
                }
            }
        }
        (*lessthan) = max;
        (*student1) = maxstudent;
        return max;
    }

}

int countStudents(float mark) {
    ifstream fIn;
    fIn.open("files\\result.csv");
    if (!fIn.is_open())cout << "Error11";
    else {
        string student;
        int count = 0;
        float stdMark;
        while (!fIn.eof()) {
            getline(fIn, student);
            if (student != "") {
                int start = student.find(';');
                int end = student.rfind(';');
                stdMark = stof(student.substr(start + 1, end - start - 1));
                if (stdMark == mark) {
                    count++;
                }
            }
        }
        return count;
    }
}

void writeAll(int number, float mark, char* root) {
    ifstream fIn;
    fIn.open("files\\result.csv");
    if (!fIn.is_open())cout << "Error11";
    else {
        string student;
        float stdMark;
        while (!fIn.eof()) {
            getline(fIn, student);
            if (student != "") {
                int start = student.find(';');
                int end = student.rfind(';');
                stdMark = stof(student.substr(start + 1, end - start - 1)); // student's mark
                if (stdMark == mark) {
                    ofstream fOut4;
                    fOut4.open(root, ios::app);
                    if (!fOut4.is_open()) cout << "Error";
                    else {
                        fOut4 << student << endl;
                        fOut4.close();
                    }
                }
            }
        }

    }
}