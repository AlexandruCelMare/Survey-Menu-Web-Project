#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "handleUsers.h"
using namespace std;

// Menu System function headers
void menuReturn();

void users::addUser(){
    menuSystem c;
    fstream ofile; // File setup
    string username;
    string password;
    int accountNum;
    
    bool pass;
    
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

    ofile.close();
    cout << "Please enter username: " << endl << endl;
    getline(cin, username);
    
    cout << "\nPlease enter password:" << endl << endl;
    getline(cin, password);
    cout << endl;
    do{
        pass = true;
        for (int i = 0; i < password.length(); i++){
            if (password[i] == 32){
                pass = false;
            }
        }
        if (pass == false){
            cout << "\nPassword contains whitespaces." << endl;
            cout << "Please try another password:" << endl << endl;
            getline(cin, password);
        }
    } while (pass == false);
    
    
    ofile.open("user.txt", ios::out);
    accountNum++;
    ofile << accountNum << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    ofile << username << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    ofile << password << endl;
    
    delete []passList;
    delete []userList;
    
    c.menuReturn();
}

void users::deleteUser(){
    menuSystem c;
    fstream ofile; // File setup
    int username;
    int accountNum;
    int delInput;
    
    ofile.open("user.txt", ios::in); 
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    
    string *userList = new string[accountNum]; // For adding usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For adding passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
    ofile.close();
    
    cout << "\nChoose username to delete (enter #):" << endl << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << endl;
    }
    
    cout << endl;
    cin >> delInput;
    delInput--;
    
    for (int i = delInput; i < (accountNum - 1); i++){
        userList[i] = userList[i + 1];
    }
    for (int i = delInput; i < (accountNum - 1); i++){
        passList[i] = passList[i + 1];
    }
    
    ofile.open("user.txt", ios::out);
    --accountNum;
    ofile << accountNum << endl; 
    for (int i = 0; i < (accountNum); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    for (int i = 0; i < (accountNum); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    ofile.close();
    
    delete []userList;
    delete []passList;
    
    c.menuReturn();
}

void users::editUser(){
    menuSystem c;
    fstream ofile;
    int editInput;
    int editOption;
    string newVal;
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
    
    ofile.close();
    
    cout << "\nChoose the username to edit (enter #):" << endl << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << endl; 
    }
    cout << endl;
    cin >> editInput;
    cout << endl << "| 1. Edit User | 2. Edit Password | " << endl << endl;
    cin >> editOption;
    if (editOption == 1 || editOption == 2) {
        switch (editOption){
            case 1: 
                cout << "Please enter the new username: " << endl << endl;
                cin >> newVal;
                userList[editInput - 1] = newVal;
                break;
            case 2:
                cout << "Please enter the new password: " << endl << endl;
                cin >> newVal;
                passList[editInput - 1] = newVal;
                break;
            default: 
                cout << "Default path" << endl;
        }    
    }
    else {
       cout << "Not a number 1-2, try again" << endl;
       editUser();
       return;
    }   

    ofile.open("user.txt", ios::out);
    ofile << accountNum << endl;
    
    for (int i = 0; i < (accountNum); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    
    ofile.close();
    delete []userList;
    delete []passList;
    
    c.menuReturn();
}

//---------------FUNCTIONS FOR MODIFYING SURVEYS--------------
// UNDER CONSTRUCTION
void survey::addSurvey(){
    menuSystem c;
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
    
    string newSurvey;
    string* newQuestions;
    string** newAnswers;
    int qNum; // number of questions
    int* aNum; // number of answers
    
    ofile.open("survey.txt", ios::out);
    cout << endl;
    cin.ignore();
    cout << "Please enter a survey name: " << endl << endl;
    getline(cin, newSurvey);
    cout << "Please enter the number of questions:" << endl << endl;
    cin >> qNum;
    newQuestions = new string[qNum];
    newAnswers = new string*[qNum];
    aNum = new int[qNum];
    
    cin.ignore();
    for (int i = 0; i < qNum; i++){
        cout << "Please enter the question " << i + 1 << " :" << endl << endl;
        getline(cin, newQuestions[i]);
        cout << "Please enter the number possible"
                " answers for question " << i + 1 << " :" << endl << endl;
        cin >> aNum[i];
        cin.ignore();
        newAnswers[i] = new string[aNum[i]];
        for (int j = 0; j < aNum[i]; j++){
            cout << "Please enter the possible answer " 
                    << j + 1 << " :" << endl << endl;
            getline(cin, newAnswers[i][j]);
        }
    }
    ofile<<surveyNum+1<<endl; 
    if(surveyNum>0){
        //cout<<"here: "<<surveyNum<<endl;
        for (int i = 0; i < surveyNum; i++){
            ofile<<'x'<<surveys[i]<<endl;
            ofile<<questionNum[i]<<endl;
            for (int j = 0; j < questionNum[i]; j++){
                ofile<<'x'<<questions[i][j]<<endl;
                ofile<<answerNum[i][j]<<endl;
                for (int k = 0; k < answerNum[i][j]; k++){              
                    ofile<<'x'<<answers[i][j][k]<<endl;
                    ofile<<surveyAns[i][j][k]<<endl;
                }
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
    }
    ofile<<'x'<<newSurvey<<endl;
    ofile<<qNum<<endl;
    for (int j = 0; j < qNum; j++){
            ofile<<'x'<<newQuestions[j]<<endl;
            ofile<<aNum[j]<<endl;
            for (int k = 0; k < aNum[j]; k++){              
                ofile<<'x'<<newAnswers[j][k]<<endl;
                ofile<<0<<endl;
            }
            delete []newAnswers[j];
        }
    ofile.close();
    delete []newQuestions;
    delete []aNum; // number of answers
    delete []newAnswers;
    c.menuReturn();
}

void survey::deleteSurvey(){
    menuSystem c;
    fstream ifile;
    fstream ofile;
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
    
    ifile.close();
    int delIndex;
    
    for (int i = 0; i < surveyNum; i++){
        cout << i + 1 << ". " << surveys[i] << endl;
    }
    
    ofile.open("survey.txt", ios::out);
    cout << endl;
    cin.ignore();
    cout << "Please enter a survey to delete (enter number, ie. 3): " << endl << endl;
    cin >> delIndex;
    

    ofile<<surveyNum-1<<endl; 
    for (int i = 0; i < surveyNum; i++){
        if (i == delIndex - 1) continue;
        ofile<<'x'<<surveys[i]<<endl;
        ofile<<questionNum[i]<<endl;
        for (int j = 0; j < questionNum[i]; j++){
            ofile<<'x'<<questions[i][j]<<endl;
            ofile<<answerNum[i][j]<<endl;
            for (int k = 0; k < answerNum[i][j]; k++){              
                ofile<<'x'<<answers[i][j][k]<<endl;
                ofile<<surveyAns[i][j][k]<<endl;
               
            }
        }
    }
    ofile.close();
    
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

void survey::editSurvey(){
    menuSystem c;
    fstream ifile;
    fstream ofile;
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
    
    ifile.close();

    int delIndex;
    string surveyName;
    for (int i = 0; i < surveyNum; i++){
        cout << i + 1 << ". " << surveys[i] << endl;
    }
    
    ofile.open("survey.txt", ios::out);
    cout << endl;
    cin.ignore();
    cout << "Please enter a survey to edit (enter number, ie. 3): " << endl << endl;
    cin >> delIndex;
    cout << "Please enter the new survey name: " << endl << endl;
    cin >> surveyName;
    surveys[delIndex-1] = surveyName;
    ofile<<surveyNum<<endl; 
    for (int i = 0; i < surveyNum; i++){
        ofile<<'x'<<surveys[i]<<endl;
        ofile<<questionNum[i]<<endl;
        for (int j = 0; j < questionNum[i]; j++){
            ofile<<'x'<<questions[i][j]<<endl;
            ofile<<answerNum[i][j]<<endl;
            for (int k = 0; k < answerNum[i][j]; k++){              
                ofile<<'x'<<answers[i][j][k]<<endl;
                ofile<<surveyAns[i][j][k]<<endl;
               
            }
        }
    }
    ofile.close();
    
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

// Question modification functions

void survey::deleteQuestion(){
    menuSystem c;
    fstream ifile;
    fstream ofile;
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
    
    ifile.close();

    int delIndex;
    int delQuestion;
    for (int i = 0; i < surveyNum; i++){
        cout << i + 1 << ". " << surveys[i] << endl;
    }
    
    ofile.open("survey.txt", ios::out);
    cout << endl;
    cin.ignore();
    cout << "Please enter a survey to view questions (enter number, ie. 3): " << endl << endl;
    cin >> delIndex;
    for (int i = 0; i < questionNum[delIndex - 1]; i++){
        cout << i + 1 << ". " << questions[delIndex-1][i] << endl;
    }
    cout << "Please enter a qustion to delete (enter number, ie. 3): " << endl << endl;
    cin >> delQuestion;
    ofile<<surveyNum<<endl; 
    for (int i = 0; i < surveyNum; i++){
        ofile<<'x'<<surveys[i]<<endl;
        if (i == delIndex - 1){
            ofile<< questionNum[i] - 1 <<endl;
        }
        else{
            ofile<<questionNum[i]<<endl;
        }
        for (int j = 0; j < questionNum[i]; j++){
            if (i == delIndex - 1 && delQuestion - 1 == j) continue;
            ofile<<'x'<<questions[i][j]<<endl;
            ofile<<answerNum[i][j]<<endl;
            for (int k = 0; k < answerNum[i][j]; k++){              
                ofile<<'x'<<answers[i][j][k]<<endl;
                ofile<<surveyAns[i][j][k]<<endl;
               
            }
        }
    }
    ofile.close();
    
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

void survey::addQuestion(){
    menuSystem c;
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
    
    string newQuestions;
    string* newAnswers;
    int aNum; // number of answers
    int delIndex;
    ofile.open("survey.txt", ios::out);
    for (int i = 0; i < surveyNum; i++){
        cout << i + 1 << ". " << surveys[i] << endl;
    }
    cout << endl;
    cin.ignore();
    cout << "Enter a survey to view (enter number, ie. 3): " << endl << endl;
    cin >> delIndex;
    cin.ignore();
    cout << "Enter your new question: " << endl << endl;
    getline(cin,newQuestions);
    cout << "Enter the number of possible answers (enter number, ie. 3)" << endl << endl;
    cin >> aNum;
    cin.ignore();
    newAnswers = new string[aNum];
    for (int i = 0; i < aNum; i++){
        cout << "Enter possible answer #" << i + 1 << endl;
        getline(cin,newAnswers[i]);
    }
    
    ofile<<surveyNum<<endl; 
    for (int i = 0; i < surveyNum; i++){
        ofile<<'x'<<surveys[i]<<endl;
        if (i == delIndex - 1){
            ofile<<questionNum[i] + 1 <<endl;
            ofile<<'x'<< newQuestions << endl;
            ofile << aNum << endl;
            for (int j = 0; j < aNum; j++){
                ofile<<'x' << newAnswers[j] << endl;
                ofile << 0 << endl;
            }
        }
        else{
            ofile<<questionNum[i]<<endl;
        }
        for (int j = 0; j < questionNum[i]; j++){
            ofile<<'x'<<questions[i][j]<<endl;
            ofile<<answerNum[i][j]<<endl;
            for (int k = 0; k < answerNum[i][j]; k++){              
                ofile<<'x'<<answers[i][j][k]<<endl;
                ofile<<surveyAns[i][j][k]<<endl;
            }
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
  
    ofile.close();
    delete []newAnswers;
    c.menuReturn();
}

// Function for logging in as user

void users::userLogin(){
//    menuSystem c;
    fstream ofile;
    string username;
    string password;
    int accountNum;
    int userLocation;
    
    bool userValid = false;
    bool passValid = false;
    
    ofile.open("user.txt", ios::in);
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    
    string *userList = new string[accountNum]; // For grabbing usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For grabbing passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
    
    ofile.close();
    cout << "Please enter username: " << endl << endl;
    getline(cin, username);
    
    do{
        for (int i = 0; i < (accountNum); i++){
            if (userList[i] == username){
                userValid = true;
                userLocation = i;
            }
        }
        if (userValid == false){
            cout << "\nUsername does not exist, try again:" << endl << endl;
            getline(cin, username);
        }
    } while (userValid == false);
    
    cout << "\nPlease enter password: " << endl << endl;
    getline(cin, password);
    
    do{
        if (passList[userLocation] == password){
                passValid = true;
            }
    
        if (passValid == false){
            cout << "\nIncorrect password, try again:" << endl << endl;
            getline(cin, password);
        }
    } while (passValid == false);
    
    
    delete []passList;
    delete []userList;
//    c.menuReturn();
}

// For taking surveys
void survey::takeSurvey(){
    menuSystem c;
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
    
    
    cout << "\nChoose a survey to take (enter number, ie. 3): " << endl << endl;
    
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
            cout << i + 1 << ". " << surveys[i] << endl;
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
    int choose;
    ofile.open("survey.txt", ios::out);
    cout << endl;
    
    
    cin >> delIndex;
    cout << surveys[delIndex - 1] << endl;
    
    for (int i = 0; i < questionNum[delIndex - 1]; i++){
        cout << questions[delIndex - 1][i] << endl;
        for (int j = 0; j < answerNum[delIndex - 1][i]; j++){
            cout << "\t" << j+1 << ". " << answers[delIndex - 1][i][j] << endl;
        }
        cout << "\nEnter a number (ie. 3)" << endl << endl;
        cin >> choose;
        surveyAns[delIndex-1][i][choose-1]++;
    }
    ofile<<surveyNum<<endl; 
    //cout<<"here: "<<surveyNum<<endl;
    for (int i = 0; i < surveyNum; i++){
        ofile<<'x'<<surveys[i]<<endl;
        ofile<<questionNum[i]<<endl;
        for (int j = 0; j < questionNum[i]; j++){
            ofile<<'x'<<questions[i][j]<<endl;
            ofile<<answerNum[i][j]<<endl;
            for (int k = 0; k < answerNum[i][j]; k++){              
                ofile<<'x'<<answers[i][j][k]<<endl;
                ofile<<surveyAns[i][j][k]<<endl;
            }
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
    
  
    ofile.close();
    c.menuReturn();
}