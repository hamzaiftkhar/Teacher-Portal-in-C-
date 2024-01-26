#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<cmath>
#include<iomanip>
#include<windows.h>

using namespace std;

const int MAX_QUIZZES = 10;      // Maximum number of quizzes
const int MAX_ASSIGNMENTS = 10;  // Maximum number of assignments
const int NUM_WEIGHTAGES = 5;

struct student_data {
    string name;
    string rollNumber;
    int quizzes[MAX_QUIZZES];
    int assignments[MAX_ASSIGNMENTS];
    int midterm;
    int finalExam;
    int project;
    double quiz_avg;
    double assignment_avg;
    int totalMarks;
    string grade;
};

void readDataFromFile(const string& fileName, student_data students[],int numstudents,int weightages[], int quizCount, int assignmentCount, double& quiz_total, double& assignmnet_total, double& mids_total, double& final_total, double& project_total) {
    system("cls");
	ifstream file(fileName);
    int quiz_marks, assignment_marks;
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    cout<<"\n\n\n\t\t\tFetching Data from file";
    for(int i=0;i<10;i++){
    	cout<<".";
    	Sleep(100);
	}
	cout<<"\n\n\n";
    string line;
    getline(file, line); // Read the first line (header)
	getline(file, line); //Read the second line(header)
		istringstream aa(line);
        string token;
        getline(aa,token,',');
        getline(aa,token,',');
        for (int i = 0; i < quizCount; ++i) {
            getline(aa, token, ',');
            quiz_marks = stoi(token);
            quiz_total+=quiz_marks;
        }
//        cout<<"total quiz marks are :"<<quiz_total<<endl;
        for (int i = 0; i < assignmentCount; ++i) {
            getline(aa, token, ',');
            assignment_marks = stoi(token);
            assignmnet_total+=assignment_marks;
        }
//        cout<<"Total assignment marks are :"<<assignmnet_total<<endl;
        getline(aa,token,',');
        mids_total=stoi(token);
//        cout<<"Total mids marks are :"<<mids_total<<endl;
        getline(aa,token,',');
        final_total=stoi(token);
//        cout<<"Total final marks are :"<<final_total<<endl;
        getline(aa,token,',');
        project_total=stoi(token);
//        cout<<"Total project marks are :"<<project_total<<endl;
        
    int studentIndex = 0;
    while (getline(file, line)) {
        istringstream ss(line);
        string token;

        // Assuming the CSV format is consistent with the structure
        getline(ss, students[studentIndex].name, ',');
        getline(ss, students[studentIndex].rollNumber, ',');

        for (int i = 0; i < quizCount; ++i) {
            getline(ss, token, ',');
            students[studentIndex].quizzes[i] = stoi(token);
        }

        for (int i = 0; i < assignmentCount; ++i) {
            getline(ss, token, ',');
            students[studentIndex].assignments[i] = stoi(token);
        }

        getline(ss, token, ',');
        students[studentIndex].midterm = stoi(token);

        getline(ss, token, ',');
        students[studentIndex].finalExam = stoi(token);

        getline(ss, token, ',');
        students[studentIndex].project = stoi(token);

		
        // Calculate total marks and grade (you need to implement this logic)
        // students[studentIndex].totalMarks = ...;
        // students[studentIndex].grade = ...;

        ++studentIndex;
    }
    for (int i = 0; i < numstudents; ++i) {
        int quizes_marks = 0;
        for (int j = 0; j < quizCount; ++j) {
            quizes_marks += students[i].quizzes[j];
        }
        students[i].quiz_avg= quizes_marks/quiz_total;
//    	cout<<"total all quiz marks for student "<<i<<"\t"<<students[i].quiz_avg*weightages[0]<<endl;
        int assignments_marks = 0.0;
        for (int j = 0; j < assignmentCount; ++j) {
            assignments_marks += students[i].assignments[j];
        }
        students[i].assignment_avg=assignments_marks/assignmnet_total;
//		cout<<"total all assignment marks for student "<<i<<"\t"<<students[i].assignment_avg*weightages[1]<<endl;
        students[i].totalMarks = round(((students[i].quiz_avg) * weightages[0])+
                                 ((students[i].assignment_avg) * weightages[1]) +
                                 ((students[i].midterm / mids_total) * weightages[2]) +
                                 ((students[i].finalExam / final_total) * weightages[3]) +
                                 ((students[i].project / project_total) * weightages[4]));
    	
//		cout<<"Total marks of student is : "<< students[i].totalMarks<<endl;
		}
	cout<<"\t\t\tSucessfully fetched data.."<<"\n\n";	
    
}

int student_count(const string& fileName) {
	system("cls");
    ifstream file(fileName);

    // Check if the file is open
    if (!file.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }
    
    cout<<"\n\n\n\t\t\tReading file";
    for(int i=0;i<10;i++){
    	cout<<".";
    	Sleep(100);
	}
	cout<<"\n\n\t\t\tCounting students";
	for(int i=0;i<10;i++){
    	cout<<".";
    	Sleep(100);
	}
    string line;
    int student_count = 0;
    while (getline(file, line) && !line.empty()) {
        // Increment student count for each line
        ++student_count;
    }
    student_count = student_count - 2; // Assuming the first line is the header
    cout<<"\n\n\t\t\tTotal number of students in file are : "<<student_count<<endl;
    return student_count;
}

void count(const string& fileName, int& quizCount, int& assignmentCount) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    getline(file, line); // Read the first line

    istringstream ss(line);
    string token;

    while (getline(ss, token, ',')) {
        if (token.find("Q") != string::npos) {
            quizCount++;
        } else if (token.find("A") != string::npos) {
            assignmentCount++;
        }
    }
}

void Weightage(int weightages[]){
	system("cls");
	int sum;
	do {
    system("cls");
    cout<<"\n\n";
    cout << "\n\t\tEnter weightages for quizzes, assignments, midterm, final, and project (total must be 100): " << endl;
    cout << "\n\t\tWeightage of quizes :";
    cin >> weightages[0];
    cout << "\n\t\tWeightage of assignments :";
    cin >> weightages[1];
    cout << "\n\t\tWeightage of mid Exam :";
    cin >> weightages[2];
    cout << "\n\t\tWeightage of Final Exam :";
    cin >> weightages[3];
    cout << "\n\t\tWeightage of Final Project :";
    cin >> weightages[4];
    cout<<"\n\n";
    sum = 0; // Reset sum to zero before re-evaluating

    for (int i = 0; i < 5; i++) {
        sum += weightages[i];
    }

    if (sum != 100) {
        cout << "\n\tTotal weightage is not equal to 100, Please Enter the correct Weightage" << endl;
        system("pause");
    }
    else{
    	cout<<"\n\tWeightages Entred sucessfully !.."<<endl;
	}
} while (sum != 100);
}

double calculateClassAverage(student_data students[], int numStudents) {
    double total = 0.0;
    for (int i = 0; i < numStudents; ++i) {
        total += students[i].totalMarks;
    }
    return round(total / numStudents);
}

void assignGrades(student_data students[], int numStudents, double classAverage) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].totalMarks < classAverage-2-20 && students[i].totalMarks > 0) {
            students[i].grade = "F";
        } else if (students[i].totalMarks < classAverage-2-15 && students[i].totalMarks >= classAverage-2-20) {
            students[i].grade = "D";
        } else if (students[i].totalMarks < classAverage-2-10 && students[i].totalMarks >= classAverage-2-15) {
            students[i].grade = "C-";
        } else if (students[i].totalMarks < classAverage-2-5 && students[i].totalMarks >= classAverage-2-10) {
            students[i].grade = "C";
        } else if (students[i].totalMarks < classAverage-2 && students[i].totalMarks >= classAverage-2-5) {
            students[i].grade = "C+";
        } else if (students[i].totalMarks <= classAverage+2 && students[i].totalMarks >= classAverage-2) {
            students[i].grade = "B-";
        } else if (students[i].totalMarks <= classAverage+2+5 && students[i].totalMarks > classAverage+2) {
            students[i].grade = "B";
        } else if (students[i].totalMarks <= classAverage+2+10 && students[i].totalMarks > classAverage+2+5) {
            students[i].grade = "B+";
        } else if (students[i].totalMarks <= classAverage+2+15 && students[i].totalMarks > classAverage+2+10) {
            students[i].grade = "A-";
        } else if(students[i].totalMarks >= classAverage-2+20 && students[i].totalMarks <= 100) {
            students[i].grade = "A";
        }
    }
}

void generateResultsCSV(student_data students[], int numStudents,int weightage[5] ,double& mids_total, double& final_total, double& project_total) {
    system("cls");
	ofstream outputFile("NCA_result.csv");
    cout<<"\n\n\n\t\t\tWriting your result in file";
    for(int i=0;i<10;i++){
    	cout<<".";
    	Sleep(100);
	}
    if (outputFile.is_open()) {
        // Write header
        outputFile << "Name,Roll Number,Quiz,Assignment,Mid,Final,Project,Total Marks,Grade\n";
        for (int i = 0; i < numStudents; ++i) {
            outputFile << students[i].name << "," << students[i].rollNumber << ","<<(students[i].quiz_avg)*weightage[0]<< ","<<(students[i].assignment_avg)*weightage[1]
                       << ","<<(students[i].midterm/mids_total)*weightage[2]<<","<<(students[i].finalExam/final_total)*weightage[3]<<","<<(students[i].project/project_total)*weightage[4]<<","<< students[i].totalMarks << "," << students[i].grade << "\n";
        }

        cout << "\n\n\n\t\t\tResults written to NCA_result.csv\n";

        outputFile.close();
    } else {
        cerr << "\n\n\n\\t\t\tUnable to open output file: NCA_result.csv\n";
    }
    system("pause");
}

// Function to search for a student by roll number
void searchStudent(const string& rollNumber, const student_data students[], int numStudents, int weightage[5], int quiz_count, int assignment_count) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].rollNumber == rollNumber) {
            // Display student data
            cout << "\n\n\t\tStudent Found:" << endl;
            cout << "\t\tName: " << students[i].name << endl;
            cout << "\t\tRoll Number: " << students[i].rollNumber << endl;

            // Display quiz marks
            cout << "\n\t\tQuiz Marks: ";
            for (int j = 0; j < quiz_count; ++j) {
                cout << students[i].quizzes[j] << " ";
            }
            cout << endl;

            // Display assignment marks
            cout << "\t\tAssignment Marks: ";
            for (int j = 0; j < assignment_count; ++j) {
                cout << students[i].assignments[j] << " ";
            }
            cout << endl;

            cout << "\t\tMidterm: " << students[i].midterm<< endl;
            cout << "\t\tFinal Exam: " << students[i].finalExam<< endl;
            cout << "\t\tProject: " << students[i].project<< endl;

            // Display calculated averages, total marks, and grade
            cout << "\n\t\tQuiz Average: " << students[i].quiz_avg*weightage[0] <<" Out of "<<weightage[0]<< endl;
            cout << "\t\tAssignment Average: " << students[i].assignment_avg*weightage[1] <<" Out of "<<weightage[1]<< endl;
            cout << "\t\tTotal Marks: " << students[i].totalMarks << endl;
            cout << "\n\t\tGrade: " << students[i].grade << endl;

            return;  // Student found, exit the function
        }
    }

    // If the function reaches here, the student was not found
    cout << "Student with Roll Number " << rollNumber << " not found." << endl;
}

void displayAllResults(const student_data students[], int numStudents, int weightage[5], double& mids_total, double& final_total, double& project_total) {
	system("cls");
    // Display header
    cout << setw(30) << left << "Name" << setw(20) << left << "Roll Number";
    cout << setw(10) << left << "Quiz Avg" << setw(15) << left << "Assignment Avg";
    cout << setw(10) << left << "Midterm" << setw(10) << left << "Final Exam";
    cout << setw(10) << left << "Project" << setw(10) << left << "Total Marks" << setw(10) << left << "Grade" << endl;

    // Display each student's results
    for (int i = 0; i < numStudents; ++i) {
        cout << setw(30) << left << students[i].name;
        cout << setw(20) << left << students[i].rollNumber;
        cout << setw(10) << left << students[i].quiz_avg*weightage[0];
        cout << setw(15) << left << students[i].assignment_avg*weightage[1];
        cout << setw(10) << left << (students[i].midterm/mids_total)*weightage[2];
        cout << setw(10) << left << (students[i].finalExam/final_total)*weightage[3];
        cout << setw(10) << left << (students[i].project/project_total)*weightage[4];
        cout << setw(10) << left << students[i].totalMarks;
        cout << setw(10) << left << students[i].grade << endl;
    }
    system("pause");
}

void main_display(){
	system("cls");
	cout<<"\n\n\n\n";
	cout<<"\t\t\t****************************************************************\n";
	cout<<"\t\t\t****************************************************************\n";
	cout<<"\t\t\t****                                                        ****\n";
	cout<<"\t\t\t****                                                        ****\n";
	cout<<"\t\t\t****               TEACHER PORTAL IN C++                    ****\n";
	cout<<"\t\t\t****                                                        ****\n";
	cout<<"\t\t\t****                                                        ****\n";
	cout<<"\t\t\t****************************************************************\n";
	cout<<"\t\t\t****************************************************************\n";
	cout<<"\n\n\n\n";
	Sleep(2000);
}


int main() {
	main_display();
    const int MAX_ROWS = 1000;
    const int MAX_COLS = 20; // Assuming a maximum of 14 columns in the CSV

    int quizCount = 0;
    int assignmentCount = 0;
    double quiz_total=0.0,assignment_total=0.0;
	double mids_total=0.0,final_total=0.0,project_total=0.0 ;
	int weightages[NUM_WEIGHTAGES]; 
	student_data students[MAX_ROWS];
    
    count("NCA+csv.csv", quizCount, assignmentCount);
	int total_student = student_count("NCA+csv.csv");
	system("pause");
    Weightage(weightages);
    system("pause");
	readDataFromFile("NCA+csv.csv", students,total_student,weightages, quizCount, assignmentCount, quiz_total, assignment_total, mids_total, final_total, project_total);
	system("pause");
	double average = calculateClassAverage(students, total_student);
	assignGrades(students, total_student, average);
	
	
	string rollNumber;
    int option;
    do{
    	system("cls");
    	 cout << "\n\n\t\t\tChoose an option:\n";
    cout << "\t\t\t1. Display Class Result on the console.\n";
    cout << "\t\t\t2. Generate Class Result in a new CSV file.\n";
    cout << "\t\t\t3. Search Result of an individual student by roll number on console.\n";
    cout << "\t\t\t4. Exit.\n";
    cout << "\n\n\n\t\t\tEnter option: ";
    cin >> option;

    switch (option) {
        case 1:
            displayAllResults(students, total_student, weightages,mids_total,final_total,project_total);
            break;
        case 2:
            generateResultsCSV(students, total_student,weightages, mids_total, final_total, project_total);
            break;
        case 3:
        	system("cls");
            cout << "\n\n\t\tEnter roll number to search: ";
            cin >> rollNumber;
            searchStudent(rollNumber, students, total_student, weightages, quizCount, assignmentCount);
            system("pause");
            break;
        case 4:
            // Exit the program
            system("cls");
            cout<<"\n\n\n\t\t\tExiting";
            for(int i=0; i<5; i++)
            {
            	cout<<".";
            	Sleep(100);
			}
			cout<<"\n\n\t\t\tThanks for using!"<<endl;
            break;
        default:
            cout << "\n\n\t\tInvalid option.\n";
    }
    
	}while(option!=4);
    
//Extra testings outputs

    
//    cout << "Total students: " << total_student << endl;
//        system("pause");
//    for(int i=0; i<NUM_WEIGHTAGES; i++){
//    	cout<<weightages[i]<<endl;
//	}	
//	for(int k=0; k<total_student; k++){
//       		cout << "Total marks of student " << k + 1 << ": " << students[k].totalMarks<<"\tGrade\t"<<students[k].grade<<"\n";
//		}
//	
//	cout<<"File generated sucessfully!"<<endl;	
//	cout<<"class Average = "<<average<<endl;
//	
// print function

//    for(int j=0; j<total_student; j++){
//    	cout<<"Student"<<j+1<<endl;
//    	for (int i = 0; i < quizCount; ++i) {
//        cout << "Quiz " << i + 1 << ": " << students[j].quizzes[i] << "\t";
//    	}
//    	for(int k=0; k<assignmentCount; k++){
//       		cout << "Assignment " << k + 1 << ": " << students[j].assignments[k]<<"\t";
//		}
//		
//		cout<<"Total marks of student "<<j<<"\t"<<students[j].totalMarks<<"\tGrade\t"<<students[j].grade<<endl;
//		
//    cout<<endl;
//	}
	

    return 0;
}

