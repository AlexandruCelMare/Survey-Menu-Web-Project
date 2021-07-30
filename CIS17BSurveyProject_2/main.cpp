/* 
 * File:   main.cpp
 * Modified by: Alexander Butarita
 * Created on March 19, 2021
 * Professor: Dr. Lehr
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "handleUsers.h"

using namespace std;


void menu();


// Website used for ASCII art: http://patorjk.com/software/taag/#p=display&f=Modular&t=E-Shop
int main(int argc, char** argv) {
    menuSystem c;
    cout << " _______  _______  ______    __   __  _______         _______ TM\n";
    cout << "|       ||       ||    _ |  |  | |  ||       |       |   _   |\n";
    cout << "|  _____||    ___||   | ||  |  |_|  ||    ___| ____  |  |_|  |\n";
    cout << "| |_____ |   |___ |   |_||_ |       ||   |___ |____| |       |\n";
    cout << "|_____  ||    ___||    __  ||       ||    ___|       |       |\n";
    cout << " _____| ||   |___ |   |  | | |     | |   |___        |   _   |\n";
    cout << "|_______||_______||___|  |_|  |___|  |_______|       |__| |__|\n";
    cout << "Serving Before surveying." << endl << endl;
    
    c.menu();
    
    return 0;
}
