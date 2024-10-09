#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player {
    string name;
public:
    Player() { name = ""; };
    ~Player() {};
    void setName(string name) { this->name = name; }
    string getName() { return name; }
};

class GamblingGame {
    Player* p;
    string name;
public:
    GamblingGame() {
        p = new Player[2];
        srand((unsigned)time(0));
        cout << "****���� ������ �����մϴ�.****" << endl;
    };
    ~GamblingGame() { delete[]p; };
    void setPlayer() {
        cout << "ù��° ���� �̸�>>";
        cin >> name;
        p[0].setName(name);
        cout << "�ι�° ���� �̸�>>";
        cin >> name;
        p[1].setName(name);
    }
    string rand_num(string n) {
        int r[3];
        cout << "\t\t";
        for (int i = 0; i < 3; i++) {
            r[i] = rand() % 3;
            cout << r[i] << '\t';
        }
        if (r[0] == r[1] && r[0] == r[2]) {
            n += "�� �¸�!!";
            return n;
        }
        else
            return "�ƽ�����!";
    }
    void game_start() {
        string str;
        int i = 0;
        while (true)
        {
            string plm;
            cout << p[i % 2].getName() << ":\n";
            getline(cin, str);
            plm = p[i % 2].getName();
            str = rand_num(str);
            if (str == "�� �¸�!!") {
                cout << plm + str;
                break;
            }
            else
                cout << str << endl;
            i++;
        }
    }
};

int main()
{
    GamblingGame game;
    game.setPlayer();
    game.game_start();
}