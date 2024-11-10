#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
const int NumberOfStudent = 20 ;


struct StudentData {
     string Student_FirstName;
    string Student_LastName;
    int Test_Score;
    char Grade;
};

//loop for max score
int findtop_studentInd (StudentData students[], int numStudents){
    int highest_score = 0;
    int top_studentInd = 0;
    

for (int i = 0 ; i < numStudents ; i++){
    if (students[i].Test_Score > highest_score) {
            highest_score = students[i].Test_Score;
            top_studentInd = i;
}
}
return top_studentInd;
}



//put student data into array
StudentData MappedStudent [NumberOfStudent];

// determine grades for scores 
char getGrade (int Test_Score){
    //find the Type grade 
    if (Test_Score >= 90){
        return 'A';
    }
    else if (Test_Score >=80 ){
        return 'B';
    }
    else if (Test_Score >= 70){
        return 'C';
    }
    else if (Test_Score >= 60){
        return 'D';
    }
    else {
        return 'E';}

}

int main(){



//open the file 
ifstream file ("studentdata.txt");
if (!file ){
    cout << "No data can be read" << endl;
    return 1;
}

//read each line from the file

string Student_FirstName , Student_LastName;
int Test_Score;
int i = 0 ;

while (file >> Student_FirstName >> Student_LastName >> Test_Score ){
    //populate struct data

    MappedStudent [i].Student_FirstName = Student_FirstName;
    MappedStudent [i].Student_LastName = Student_LastName;
    MappedStudent [i].Test_Score = Test_Score;
    MappedStudent [i].Grade =  getGrade (Test_Score) ;
    i++;
}

//find top student 
int top_studentInd = findtop_studentInd(MappedStudent , NumberOfStudent);

//close the file
file.close();

//output the file 

for (i = 0; i <= 19; i++) {
    cout << left << setw(20) << MappedStudent[i].Student_LastName + ", "
         << left << setw(20) << MappedStudent[i].Student_FirstName;

    cout << left << setw(20) <<MappedStudent[i].Test_Score;
        
    cout << right << setw(10) << MappedStudent[i].Grade << "\n"; 



}

cout << "\n" << "Student with the highest score:\n";
    cout << MappedStudent[top_studentInd].Student_FirstName << " "
         << MappedStudent[top_studentInd].Student_LastName << " with a score of "
         << MappedStudent[top_studentInd].Test_Score << " / " 
         << MappedStudent[top_studentInd].Grade << "\n";
return 0;
}
