/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   handleUsers.h
 * Author: alex
 *
 * Created on April 20, 2021, 7:08 PM
 */

#ifndef HANDLEUSERS_H
#define HANDLEUSERS_H

class users {
public:
    void addUser();
    void deleteUser();
    void editUser();
    void viewUser();
    void userLogin();
};

class survey {
public:
    void addSurvey();
    void deleteSurvey();
    void editSurvey();
    void deleteQuestion();
    void addQuestion();
    void takeSurvey();
    void viewSurvey();
};

class menuSystem {
public:
    void menuReturn();
    void menu();
    void administrator();
    void user();
    void adminUsers(int);
    void adminSurveys(int);
    void adminQuestions(int);
    void adminResults(int);
    void viewResults();
};

#endif /* HANDLEUSERS_H */

