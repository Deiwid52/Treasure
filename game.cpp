#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() {
    srand(time(NULL));
}

void Game::initializeBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = emptyChar;
        }
    }
}

void Game::printBoard() const {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Position Game::placeTreasure() {
    Position treasurePos;
    treasurePos.x = rand() % boardSize;
    treasurePos.y = rand() % boardSize;
    board[treasurePos.x][treasurePos.y] = treasureChar;
    return treasurePos;
}

bool Game::isValidMove(int x, int y) const {
    return x >= 0 && x < boardSize && y >= 0 && y < boardSize;
}

bool Game::hasReachedTreasure(int x, int y) const {
    return board[x][y] == treasureChar;
}

void Game::play() {
    initializeBoard();
    treasurePos = placeTreasure();

    playerX = 0;
    playerY = 0;
    timeRemaining = 15;

    std::cout << "Welcome to the Treasure Hunter Game!\n";
    std::cout << "Your goal is to find the treasure marked as 'T'.\n";
    std::cout << "Move around the board using W, A, S, D keys.\n";
    std::cout << "You have 15 seconds to find the treasure!\n";

    while (true) {
        std::cout << "Time remaining: " << timeRemaining << " seconds.\n";
        std::cout << "Current board:\n";
        board[playerX][playerY] = playerChar;
        printBoard();
        board[playerX][playerY] = emptyChar;

        char move;
        std::cout << "Choose direction (W - up, A - left, S - down, D - right): ";
        std::cin >> move;

        int newX = playerX;
        int newY = playerY;
        if (move == 'W' || move == 'w') {
            newX--;
        } else if (move == 'A' || move == 'a') {
            newY--;
        } else if (move == 'S' || move == 's') {
            newX++;
        } else if (move == 'D' || move == 'd') {
            newY++;
        } else {
            std::cout << "Invalid move! Enter W, A, S, or D.\n";
            continue;
        }

        if (!isValidMove(newX, newY)) {
            std::cout << "Cannot make this move! Out of board.\n";
            continue;
        }

        playerX = newX;
        playerY = newY;

        if (hasReachedTreasure(playerX, playerY)) {
            std::cout << "Congratulations! You found the treasure!\n";
            break;
        }

        timeRemaining--;
        if (timeRemaining == 0) {
            std::cout << "Unfortunately, you ran out of time. Game over!\n";
            break;
        }
    }
}
