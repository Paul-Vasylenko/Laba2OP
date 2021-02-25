# Laba2OP
Vasylenko-Paul&amp;Lytvyn-Anastasia

char directory[200];               --- a directory with .csv files;
char* getFileRoute(char*, char*);  --- gets path to file from directory and name of file
int countElem(char*);              --- count length of char*
int findSlash(char* arr, int size);--- finds index of last '\'

void countAveragePointsAndWrite(char* path, int *numOfStudents):
    1)Opens student1.csv (student2.csv) for reading
    2)Finds surname, marks and isContract information. 
    3)Count average mark for every student
    4)writes to 'result.csv' every student whose isContract == false; whose mark >=60
    
 void createRating(int numOfStudents, char* dir);:
    1)gets file route to rating.csv
    2)makes rating.csv empty
    3)PROCESS:
        3.1)finds student with the highes mark
        3.2)counts how many students with the same mark are there
        3.3)writes all of them to rating.csv
        3.4)Writes only 40% of all students in result.csv

float findMaxMark(float* lessthan, string* student1); --- finds the highest mark and the student with it.

int countStudents(float mark);            --- counts how many students with this mark are there

void writeAll(int number, float mark, char* root) --- writes all the students with this mark to rating.csv

main:
      1)gets directory
      2)creates/makes empty result and rating .csv files
      3)do... while() loop that works for every file.csv in directory
          LOOP:
          1)finds path to the file (getFileRoute() )
          2)countAveragePointsAndWrite ()
      4)after the loop we have numOfStudents in result.csv --> count 40% of it.
      5)deletes result.csv as unnecessary file
