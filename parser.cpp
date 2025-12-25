#include <iostream>
#include <string>

using namespace std;

string input;
int pos = 0;

// Function declarations
void S();
void A();
void B();

void match(char expected) {
    if (input[pos] == expected)
        pos++;
    else {
        cout << "Syntax Error at position " << pos << endl;
        exit(1);
    }
}

// S → AB
void S() {
    A();
    B();
}

// A → aA | ε
void A() {
    if (input[pos] == 'a') {
        match('a');
        A();
    }
    // ε-production: do nothing
}

// B → bB | b
void B() {
    if (input[pos] == 'b') {
        match('b');
        if (input[pos] == 'b')
            B();
    } else {
        cout << "Syntax Error at position " << pos << endl;
        exit(1);
    }
}

int main() {
    cout << "Enter string: ";
    cin >> input;
    input += '$';   // End marker

    S();

    if (input[pos] == '$')
        cout << "String accepted ✔" << endl;
    else
        cout << "String rejected ✖" << endl;

    return 0;
}
