#include <iostream>
#include <string>

using namespace std;

class Printer {
    string model, manuf;
    int  avlcount;
protected:
    Printer(string model, string manuf, int avlcount){
        this->model = model; 
        this->manuf = manuf;
        this->avlcount = avlcount;
    }
    bool print(int pCount) {
        if (pCount < 0) {
            cout << "잘못된 입력입니다.\n";
            return false;
        }
        if (avlcount < pCount) {
            cout << "용지가 부족하여 프린트할 수 없습니다.\n";
            return false;
        }
        avlcount -= pCount;
        return true;
    }
    string get_model() const { return model; }
    string get_manuf() const { return manuf; }
    int get_avlcount() const { return avlcount; }
};

class InkJetPrinter : public Printer {
    int avlink;
public:
    InkJetPrinter(string model, string manuf, int avlcount, int avlink) : Printer(model, manuf, avlcount) {
        this->avlink = avlink;
    }
    bool InkJetprint(int pCount){
        if (avlink < pCount) {
            cout << "잉크가 부족하여 프린트 할 수 없습니다.\n";
            return false;
        }
        if (!print(pCount))
            return false;
        avlink -= pCount;
        return true;
    }
    void show() {
        cout << get_model() << ", " << get_manuf() << ", 남은 종이: " << get_avlcount() << "장, 남은 잉크: " << avlink << endl;
    }
};

class LaserPrinter : public Printer {
    int avltoner;
public:
    LaserPrinter(string model, string manuf, int avlcount, int avltoner) : Printer(model, manuf, avlcount) {
        this->avltoner = avltoner;
    }
    bool Laserprint(int pCount){
        if (avltoner < pCount) {
            cout << "토너가 부족하여 프린트 할 수 없습니다.\n";
            return false;
        }
        if (!print(pCount))
            return false;
        avltoner -= pCount;
        return true;
    }
    void show(){
        cout << get_model() << ", " << get_manuf() << ", 남은 종이: " << get_avlcount() << "장, 남은 토너: " << avltoner << endl;
    }
};

int main() {
    int pNum, pCount;
    char yon;
    InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "Hp", 7, 5);
    LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 5);

    cout << "현재 작동중인 2 대의 프린터는 아래와 같다\n";
    cout << "잉크젯 : ";
    inkjet->show();
    cout << "레이저 : ";
    laser->show();
    cout << endl;

    while (true) {
        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> pNum >> pCount;

        bool success = false;
        if (pNum == 1) 
            success = inkjet->InkJetprint(pCount);
        else if (pNum == 2) 
            success = laser->Laserprint(pCount);
        else 
            cout << "프린터를 잘못 선택하셨습니다.\n";

        if (success) 
            cout << "프린트가 완료되었습니다.\n";
        inkjet->show();
        laser->show();

        while (true) {
            cout << "계속 프린트 하시겠습니까(y/n)>>";
            cin >> yon;
            if (yon == 'y')
                break;
            else if (yon == 'n') 
                return 0;
            else 
                cout << "잘못 입력하셨습니다.\n";
        }
    }
    delete inkjet;
    delete laser;
    return 0;
}