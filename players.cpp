//Player class to enter details of players, display average runs, display list of players
#include<iostream>
#include<algorithm>
using namespace std;

class Cricket {
    char pcode[10],name[25];
    int no_mpl,total_runs,no_not_out;

public:
    Cricket() {
        get_details();
    }

    void average() {
        cout << "Average of " << name << " = " <<(double) (total_runs) / no_mpl << endl;
    }

    double average(Cricket players[], int n) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += players[i].total_runs;
        }
        return double(total / n);
    }

    friend bool sort_totalruns(Cricket&, Cricket&);

    void display() {
        cout <<pcode <<"\t\t"<<name << "\t\t"<< no_mpl <<"\t\t"<< total_runs << "\t\t"<< no_not_out << endl;
    }

    void get_details() {
        cout << "\nEnter the player code: ";
        cin >> pcode;
        cout << "Enter the player name: ";
        cin>>name;
        cout << "Enter the no. of matches played: ";
        cin >> no_mpl;
        cout << "Enter the total runs: ";
        cin >> total_runs;
        cout << "Enter the no. of not outs: ";
        cin >> no_not_out;
    }
};

bool sort_totalruns(Cricket &c1, Cricket &c2) {
    return c1.total_runs < c2.total_runs;
}

int main() {
    
    int ch, n;

    cout << "Enter the number of players (up to 10): ";
    cin >> n;
    Cricket players[n];

    while (ch != 4) {
        cout << "\n1. Display average runs of a single player" << endl;
        cout << "2. Display average runs of all players" << endl;
        cout << "3. Display the list of players(sort by total runs)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch) {
            case 1:
                int pindex;
                cout << "Enter the player index (0-" << n - 1 << "): ";
                cin >> pindex;
                if (pindex >= 0 && pindex < n) {
                    players[pindex].average();
                } else {
                    cout << "Invalid player index." << endl;
                }
                break;

            case 2:
                cout <<"Average runs of all players = " << players[0].average(players, n) << endl;
                break;

            case 3:
                sort(players, players + n, sort_totalruns);
                cout <<"Player pcode\tPlayer Name\tMatches Played\tTotal Runs\tNot Outs" << endl;
                for (int i = 0; i < n; i++) {
                    players[i].display();
                }
                break;

            case 4:
                break;

            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
