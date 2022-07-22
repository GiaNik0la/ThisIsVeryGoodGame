#include <iostream>
#include <conio.h>

using namespace std;

struct Player {
    int x;
    int y;
    int speed;
    bool isAlive;
};

void move(Player player) {
    char input = getch();

    switch(input) {
        case 'W':
        case 'w':
            player.y -= player.speed;
            break;
        case 'A':
        case 'a':
            player.x -= player.speed;
            break;
        case 's':
        case 'S':
            player.y += player.speed;
            break;
        case 'D':
        case 'd':
            player.x += player.speed;
        break;
    }

}

int main() {
    char board[25][50];

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 50; j++) {
            board[i][j] = '.';
        }
    }

    Player player;
    player.x = 25;
    player.y = 24;
    player.speed = 1;
    player.isAlive = true;

    // game loop
    do {
        cout << player.x << " " << player.y << endl;
        for (int y = 0; y < 25; y++) {
            for (int x = 0; x < 50; x++) {
                board[y][x] = ".";
            }
        }
        board[player.y][player.x] = "#";

        for (int y = 0; y < 25; y++) {
            for (int x = 0; x < 50; x++) {
                cout << board[y][x];
            }
            cout << "\n";
        }
        move(player);
        system("cls");
    } while (player.isAlive);
}