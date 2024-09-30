#include <iostream>
#include <string>
#include "calculator.h"//클래스 선언부의 헤더파일을 불러옴

using namespace std;//cin cout의 편의성 이유로 작성함
//클래스의 구현부 코드
void Add::setValue(int x, int y) {
    a = x;
    b = y;
}

int Add::calculate() {
    return a + b;
}

void Sub::setValue(int x, int y) {
    a = x;
    b = y;
}

int Sub::calculate() {
    return a - b;
}

void Mul::setValue(int x, int y) {
    a = x;
    b = y;
}

int Mul::calculate() {
    return a * b;
}

void Div::setValue(int x, int y) {
    a = x;
    b = y;
}

int Div::calculate() {
    return a / b;
}

int main() {
    //문제에 작성된 표기법
    Add a;
    Sub s;
    Mul m;
    Div d;
    while (true) {//프로그램의 무한루프를 구현
        //문제에 작성된 표기법
        cout << "두 정수와 연산자를 입력하세요>>";
        int x, y;
        char op;
        cin >> x >> y >> op;

        //연산자의 구분을 위해서 IF문이 아닌 Switch문을 사용하여 구분을 용이하게함
        switch (op) {
        case '+':
            a.setValue(x, y);
            cout << a.calculate() << endl;
            break;
        case '-':
            s.setValue(x, y);
            cout << s.calculate() << endl;
            break;
        case '*':
            m.setValue(x, y);
            cout << m.calculate() << endl;
            break;
        case '/':
            d.setValue(x, y);
            cout << d.calculate() << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}