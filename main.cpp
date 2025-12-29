#include <iostream>
#include <string> 
#include <chrono>
#include <thread> 

using namespace std; 

// == Color Codes(ANSI ESCAPE CODE) == 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define PURPLE   "\033[35m"


void typeText(const string& text,int delayMs=30){
    for(char c:text){
        cout << c;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}

void printTitle(const string& title){
    cout << CYAN << title << RESET << endl;
}


void printSubtitle(const string& subtitle){
    cout << YELLOW << subtitle << RESET << endl;
}


void printMessage(const string& message){
    cout << GREEN << message << RESET << endl;
}

void printError(const string& error){
    cout << RED << error << RESET << endl;
}

void printSuccess(const string& success){
    cout << GREEN << success << RESET << endl;
}

void printWarning(const string& warning){
    cout << YELLOW << warning << RESET << endl;
}

void printInfo(const string& info){
    cout << CYAN << info << RESET << endl;
}

void printDebug(const string& debug){
    cout << YELLOW << debug << RESET << endl;
}

void printHeader(const string& header){
    cout << CYAN << header << RESET << endl;
}

void printFooter(const string& footer){
    cout << CYAN << footer << RESET << endl;
}


