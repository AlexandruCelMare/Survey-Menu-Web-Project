#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "handleUsers.h"

using namespace std;


// Menu System function headers
void administrator();
void user();
void menuReturn();
void userLogin();

// Student Modification function headers
void addUser();
void deleteUser();
void editUser();
void viewUser();
// Survey Modification function headers
void addSurvey();
void deleteSurvey();
void editSurvey();
void viewSurvey();
void viewResults();
void takeSurvey();
// Question Modification function headers
void addQuestion();
void deleteQuestion();
//-----------------FUNCTIONS FOR MENU SYSTEM-------------------
void adminUsers(int);
void adminSurveys(int);
void adminQuestions(int);
void adminResults(int);

void menuSystem::menu(){
    int initialInput = 0;
    cout << "\n| 1. Login as User | 2. Login as Administrator | 3. Exit Program |" << endl << endl;
    cout << "(Enter a number 1-3)" << endl << endl;
    cin >> initialInput;
    if (initialInput == 1 || initialInput == 2 || initialInput == 3){
        switch (initialInput){
            case 1: 
                user();
                break;
            case 2:
                administrator();
                break;
            case 3:
                exit(0);
            default: 
                cout << "Default path" << endl;
        }
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-3, try again" << endl;
        menu();
    }
 }

void menuSystem::administrator(){
    int viewUsers = 0;
    int adminInput = 0;
    cout << "\n| 1. View Users | 2. View Surveys | 3. View User-Survey"
            " Results | 4. Question List | 5. Return to Menu |" << endl << endl;
    cout << "(Enter a number 1-5)" << endl << endl;
    cin >> adminInput;
    cout << endl;
    if (adminInput == 1 || adminInput == 2 || adminInput == 3 ||
            adminInput == 4 || adminInput == 5) {
        switch (adminInput){
            case 1: 
                adminUsers(viewUsers);
                break;
            case 2:
                adminSurveys(viewUsers);
                break;
            case 3:
                adminResults(viewUsers);
                break;
            case 4:
                adminQuestions(viewUsers);
                break;
            case 5: 
                menu();
            default: 
                cout << "Default path" << endl;
        }
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-5, try again" << endl;
        administrator();
    }   
}

void menuSystem::adminUsers(int viewUsers){
    users a;
    cout << "| 1. Delete | 2. Edit |"
        " 3. View Only | 4. Return to Menu |" << endl << endl;
    cin >> viewUsers;
    if (viewUsers == 1){
        a.deleteUser();
    }
    else if (viewUsers == 2){
        a.editUser();
    }
    else if (viewUsers == 3){
        a.viewUser();
    }
    else if (viewUsers == 4){
        menu();
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-4, try again" << endl;
        adminUsers(viewUsers);
    }
}

void menuSystem::adminSurveys(int viewUsers){
    survey s;
    cout << "| 1. Delete | 2. Edit | 3. Add |"
        " 4. View Only | 5. Return to Menu |" << endl << endl;
    cin >> viewUsers;
    if (viewUsers == 1){
        s.deleteSurvey();
    }
    else if (viewUsers == 2){
        s.editSurvey();
    }
    else if (viewUsers == 3){
        s.addSurvey();
    }
    else if (viewUsers == 4){
        s.viewSurvey();
    }
    else if (viewUsers == 5){
        menu();
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-5, try again" << endl;
        adminSurveys(viewUsers);
    }
}


void menuSystem::adminQuestions(int viewUsers){
    survey s;
    cout << "| 1. Delete questions | 2. Add questions | 3. View Only | 4. Return to Menu |" << endl << endl;
    cin >> viewUsers;
    if (viewUsers == 1){
        s.deleteQuestion();
    }
    else if (viewUsers == 2){
        s.addQuestion();
    }
    else if (viewUsers == 3){
        s.viewSurvey();
    }
    else if (viewUsers == 4){
        menu();
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-4, try again" << endl;
        adminQuestions(viewUsers);
    }    
}

void menuSystem::adminResults(int viewUsers){
    survey s;
    cout << "| 1. View overall results | 2. View individual results |" << endl << endl;
    cin >> viewUsers;
    if (viewUsers == 1){
        s.viewSurvey();
    }
    else if (viewUsers == 2){
        viewResults();
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-2, try again" << endl;
        adminResults(viewUsers);
    }    
}

void menuSystem::user(){
    users a;
    survey s;
    int userInput = 0;
    cout << endl << "| 1. Log in as User | 2. Create User Account | 3. Return to Menu |" << endl << endl;
    cout << "(Enter a number 1-3)" << endl << endl;
    cin >> userInput;
    cout << endl;
    if (userInput == 1 || userInput == 2 || userInput == 3) {
        switch (userInput){
            case 1: 
                a.userLogin();
                s.takeSurvey();  
                break;
            case 2:
                a.addUser();
                break;
            case 3:
                menu();
            default: 
                cout << "Not a number 1-3, try again" << endl << endl;
                user();
        }
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-3, try again" << endl;
        user();
    }   
}

//--To view Users--

void users::viewUser(){
    menuSystem c;
    fstream ofile;
    string view;
    int viewInput;
    int counter = 0;
    int accountNum = 0;

    
    ofile.open("user.txt", ios::in); 
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    // User and pass
    string *userList = new string[accountNum]; // For adding usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For adding passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }

    
    cout << "\nUsernames:" << endl << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << endl;
    }
    

    ofile.close();
    delete []userList;
    delete []passList;

    c.menuReturn();
}


//--To view Surveys--

void survey::viewSurvey(){
    menuSystem c;
    fstream ifile;
    int surveyNum;
    
    
    ifile.open("survey.txt", ios::in); // opening survey file for input
    ifile>>surveyNum;  // get total number of surveys
    if(surveyNum==0){
        cout<<"There is nothing to delete"<<endl;
        c.menuReturn();
    }
    string* surveys = new string[surveyNum]; // initialized string array for individual surveys
    string** questions = new string*[surveyNum]; // initialized 2d string array for individual questions
    string*** answers = new string**[surveyNum];
    int* questionNum = new int[surveyNum]; // initialized int array for number of questions
    int** answerNum = new int*[surveyNum]; // initialized 3d int array for number of answers
    int*** surveyAns = new int**[surveyNum]; // initialized 3d array for the number individuals 
    
    ifile.ignore(500,'x');
    for (int i = 0; i < surveyNum; i++){
        getline(ifile, surveys[i]);
        cout << i + 1 << ". " << surveys[i] << endl;
        ifile >> questionNum[i];
        ifile.ignore(500,'x');
        questions[i] = new string[questionNum[i]];
        surveyAns[i] = new int*[questionNum[i]];
        answers[i] = new string*[questionNum[i]];
        answerNum[i] = new int[questionNum[i]];
        for (int j = 0; j < questionNum[i]; j++){
            getline(ifile, questions[i][j]);
            cout << "\t" << j + 1 << ". " << questions[i][j] << endl;
            ifile >> answerNum[i][j];
            ifile.ignore(500,'x');
            surveyAns[i][j] = new int[answerNum[i][j]];
            answers[i][j] = new string[answerNum[i][j]];
            for (int k = 0; k < answerNum[i][j]; k++){              
                getline(ifile,answers[i][j][k]);
                ifile >> surveyAns[i][j][k];
                ifile.ignore(500,'x');
                //answers[i][j][k].pop_back();
                cout << surveyAns[i][j][k] << "\t\t" << k + 1 << ". " << answers[i][j][k] << endl;
            }
        }
    }
    ifile.close();
    
    for (int i = 0; i < surveyNum; i++){
        for (int j = 0; j < questionNum[i]; j++){
            delete []surveyAns[i][j];
            delete []answers[i][j];
        }
        delete []answers[i];
        delete []surveyAns[i];
        delete []answerNum[i];
        delete []questions[i];
    }
    delete []surveyAns;
    delete []answerNum;
    delete []questions;
    delete []answers;
    delete []surveys;
    delete []questionNum;
    
    c.menuReturn();
}

//--To view Survey results--

void menuSystem::viewResults(){
    fstream ifile;
    fstream ofile;
    int surveyNum;
    
    string* surveys; // initialized string array for individual surveys
    string** questions; // initialized 2d string array for individual questions
    string*** answers;
    int* questionNum; // initialized int array for number of questions
    int** answerNum; // initialized 3d int array for number of answers
    int*** surveyAns; // initialized 3d array for the number individuals 
                                                              // that chose an answer 
    
    cout << endl;
    ifile.open("survey.txt", ios::in); // opening survey file for input
    ifile>>surveyNum;  // get total number of surveys
    if(surveyNum>0){
        surveys = new string[surveyNum]; // initialized string array for individual surveys
        questions = new string*[surveyNum]; // initialized 2d string array for individual questions
        answers = new string**[surveyNum];
        questionNum = new int[surveyNum]; // initialized int array for number of questions
        answerNum = new int*[surveyNum]; // initialized 3d int array for number of answers
        surveyAns = new int**[surveyNum]; // initialized 3d array for the number individuals 
                                                                  // that chose an answer 
        ifile.ignore(500,'x');
        for (int i = 0; i < surveyNum; i++){
            getline(ifile, surveys[i]);

            ifile >> questionNum[i];
            ifile.ignore(500,'x');
            questions[i] = new string[questionNum[i]];
            surveyAns[i] = new int*[questionNum[i]];
            answers[i] = new string*[questionNum[i]];
            answerNum[i] = new int[questionNum[i]];
            for (int j = 0; j < questionNum[i]; j++){
                getline(ifile, questions[i][j]);
                
                ifile >> answerNum[i][j];
                ifile.ignore(500,'x');
                surveyAns[i][j] = new int[answerNum[i][j]];
                answers[i][j] = new string[answerNum[i][j]];
                for (int k = 0; k < answerNum[i][j]; k++){              
                    getline(ifile,answers[i][j][k]);
                    ifile >> surveyAns[i][j][k];
                    ifile.ignore(500,'x');
                   
                }
            }
        }
    }
    ifile.close();
  
    int delIndex;
    for (int i = 0; i < surveyNum; i++){
        cout << i + 1 << ". " << surveys[i] << endl;
    }
    cout << endl;
    cin.ignore();
    cout << "Enter a survey to view results (enter number, ie. 3): " << endl << endl;
    cin >> delIndex;
    cout << surveys[delIndex - 1] << endl;
    
    for (int i = 0; i < questionNum[delIndex - 1]; i++){
        cout << "\t" << questions[delIndex - 1][i] << endl;
        for (int j = 0; j < answerNum[delIndex - 1][i]; j++){
            cout << surveyAns[delIndex - 1][i][j] << "\t\t" << j+1 << ". " << answers[delIndex - 1][i][j] << endl;
        }
    }
    for (int i = 0; i < surveyNum; i++){
        for (int j = 0; j < questionNum[i]; j++){
            delete []surveyAns[i][j];
            delete []answers[i][j];
        }
        delete []answers[i];
        delete []surveyAns[i];
        delete []answerNum[i];
        delete []questions[i];
    }
    delete []surveyAns;
    delete []answerNum;
    delete []questions;
    delete []answers;
    delete []surveys;
    delete []questionNum;
  
    menuReturn();
}



