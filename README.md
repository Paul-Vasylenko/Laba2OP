# Laba2OP
Vasylenko-Paul&amp;Lytvyn-Anastasia

char directory[200];               --- a directory with .csv files;<br/>
char* getFileRoute(char*, char*);  --- gets path to file from directory and name of file<br/>
int countElem(char*);              --- count length of char*<br/>
int findSlash(char* arr, int size);--- finds index of last '\'<br/>

void countAveragePointsAndWrite(char* path, int *numOfStudents):<br/>
    <br/>1)Opens student1.csv (student2.csv) for reading<br/>
   <br/> 2)Finds surname, marks and isContract information. <br/>
    <br/>3)Count average mark for every student<br/>
   <br/> 4)writes to 'result.csv' every student whose isContract == false; whose mark >=60<br/>
    <br/>
 void createRating(int numOfStudents, char* dir);:<br/>
    1)gets file route to rating.csv<br/>
    2)makes rating.csv empty<br/>
    3)PROCESS:<br/>
        3.1)finds student with the highes mark<br/>
        3.2)counts how many students with the same mark are there<br/>
        3.3)writes all of them to rating.csv<br/>
        3.4)Writes only 40% of all students in result.csv<br/>
<br/>
float findMaxMark(float* lessthan, string* student1); --- finds the highest mark and the student with it.<br/>
<br/>
int countStudents(float mark);            --- counts how many students with this mark are there<br/>
<br/>
void writeAll(int number, float mark, char* root) --- writes all the students with this mark to rating.csv<br/>
<br/>
main:<br/>
      1)gets directory<br/>
      2)creates/makes empty result and rating .csv files<br/>
      3)do... while() loop that works for every file.csv in directory<br/>
          LOOP:<br/>
          1)finds path to the file (getFileRoute() )<br/>
          2)countAveragePointsAndWrite ()<br/>
      4)after the loop we have numOfStudents in result.csv --> count 40% of it.<br/>
      5)deletes result.csv as unnecessary file<br/>
