#include <iostream>
#include <string>

using namespace std; //cin cout의 편의성 이유로 작성함

class Add {
private:
    int a, b;//문제에 쓰여진 매개변수와 멤버를 사용하기 위해 작성함
public://선언부와 구현부의 분리를 위해서 선언함
    void setValue(int x, int y);
    int calculate();
};
//선언부와 구현부를 분리하여 문제를 해결함
void Add::setValue(int x, int y) {
    a = x;
    b = y;
}
int Add::calculate() {
    return a + b;
}

class Sub {
private:
    int a, b;//문제에 쓰여진 매개변수와 멤버를 사용하기 위해 작성함
public://선언부와 구현부의 분리를 위해서 선언함
    void setValue(int x, int y);
    int calculate();
};
//선언부와 구현부를 분리하여 문제를 해결함
void Sub::setValue(int x, int y) {
    a = x;
    b = y;
}
int Sub::calculate() {
    return a - b;
}

class Mul {
private:
    int a, b;//문제에 쓰여진 매개변수와 멤버를 사용하기 위해 작성함
public://선언부와 구현부의 분리를 위해서 선언함
    void setValue(int x, int y);
    int calculate();
};
//선언부와 구현부를 분리하여 문제를 해결함
void Mul::setValue(int x, int y) {
    a = x;
    b = y;
}
int Mul::calculate() {
    return a * b;
}

class Div {
private:
    int a, b;//문제에 쓰여진 매개변수와 멤버를 사용하기 위해 작성함
public://선언부와 구현부의 분리를 위해서 선언함
    void setValue(int x, int y);
    int calculate();
};
//선언부와 구현부를 분리하여 문제를 해결함
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
    while (true) {//무한루프를 위해서 작성함
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