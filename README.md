# Teacher Portal in C++

## Overview

This is a Teacher Portal implemented in C++, designed to manage and analyze students' academic data. The portal allows teachers to read student data from a CSV file provided by users, calculate grades based on custom weightages, display class results, and generate results in a new CSV file.

## Features

### 1. **Reading Student Data from User-Provided CSV File**

Users can provide a CSV file containing student data. Ensure the CSV file follows the following format:

```csv
Name,Roll Number,Q1,Q2,Q3,A1,A2,A3,Midterm,Final,Project
John Doe,12345,80,85,90,75,80,85,90,95,100
Jane Doe,67890,75,80,85,70,75,80,85,90,95
```

### 2. **Weightage Configuration**

Teachers can configure the weightages for quizzes, assignments, midterm, final exam, and the project. The total weightage must be 100%.

### 3. **Grade Calculation**

The program calculates total marks for each student and assigns grades based on predefined grade ranges.

### 4. **Display Class Result**

Teachers can choose to display the overall class result on the console, showing each student's average marks, total marks, and grade.

### 5. **Generate Results in CSV**

The program can generate a new CSV file ("NCA_result.csv") containing the calculated results for each student.

### 6. **Search Individual Student Result**

Teachers can search for an individual student's result by entering their roll number.

## Prerequisites

- C++ compiler
- Windows operating system (due to the use of `windows.h` for clear screen)

## How to Use

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/your-username/teacher-portal-cpp.git
   cd teacher-portal-cpp
   ```

2. **Compile and Run**:

   ```bash
   g++ main.cpp -o teacher_portal
   ./teacher_portal
   ```

3. **Follow On-Screen Instructions**:

   The program will guide you through options to read data, configure weightages, calculate grades, and display or generate results.

4. **Provide Your CSV File**:

   When prompted, provide your CSV file with student data in the specified format.

## Important Functions and Features

- `readDataFromFile`: Reads student data from the provided CSV file and calculates the total marks for each student.
- `Weightage`: Allows users to configure weightages for different components.
- `calculateClassAverage`: Calculates the class average of total marks.
- `assignGrades`: Assigns grades to students based on their total marks.
- `generateResultsCSV`: Generates a new CSV file containing the calculated results.

## Contributing

If you'd like to contribute to this project, feel free to fork the repository and submit a pull request.
