#ifndef GAME_H
#define GAME_H

struct Position {
    int x;
    int y;
};

class Game {
public:
    Game();
    void initializeBoard();
    void printBoard() const;
    Position placeTreasure();
    bool isValidMove(int x, int y) const;
    bool hasReachedTreasure(int x, int y) const;
    void play();

private:
    static const int boardSize = 5;
    static const char playerChar = 'P';
    static const char treasureChar = 'T';
    static const char emptyChar = '.';
    char board[boardSize][boardSize];
    int playerX;
    int playerY;
    int timeRemaining;
    Position treasurePos;
};

#endif
