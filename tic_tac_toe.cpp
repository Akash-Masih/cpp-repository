#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Board; // Forward declaration

class Player {
protected:
    char mark;
public:
    Player(char m) : mark(m) {}
    virtual ~Player() {}
    virtual int getMove() = 0;
    char getMark() const { return mark; }
};

class HumanPlayer : public Player {
public:
    HumanPlayer(char mark) : Player(mark) {}
    int getMove() override {
        int index;
        cout << "Enter box number (1-9) to place " << getMark() << ": ";
        cin >> index;
        return index;
    }
};

class NonsenseComputerPlayer : public Player {
public:
    NonsenseComputerPlayer(char mark) : Player(mark) {}
    int getMove() override {
        int index = rand() % 9 + 1;
        cout << "Random Computer selects " << index << endl;
        return index;
    }
};

class SensibleComputerPlayer : public Player {
    Board* board;
public:
    SensibleComputerPlayer(char mark, Board* b) : Player(mark), board(b) {}
    int getMove() override;
};

class Board {
    char cells[9];
public:
    Board() { reset(); }
    void reset() {
        for (int i = 0; i < 9; i++) {
            cells[i] = '1' + i;
        }
    }
    bool makeMove(int pos, char mark) {
        if (pos < 1 || pos > 9) return false;
        if (cells[pos-1] == 'X' || cells[pos-1] == 'O') return false;
        cells[pos-1] = mark;
        return true;
    }
    bool isCellEmpty(int pos) const {
        return (cells[pos-1] != 'X' && cells[pos-1] != 'O');
    }
    void getBoardState(char state[9]) const {
        for (int i = 0; i < 9; i++) {
            state[i] = cells[i];
        }
    }
    void display() const {
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            cout << " " << cells[i] << " ";
            if (i % 3 == 2 && i != 8) cout << "\n-----------\n";
            else if (i != 8) cout << "|";
        }
        cout << "\n\n";
    }
    friend class SensibleComputerPlayer;
};

int SensibleComputerPlayer::getMove() {
    char boardState[9];
    board->getBoardState(boardState);
    char opponentMark = (mark == 'X') ? 'O' : 'X';

    // Check for winning move
    for (int i = 0; i < 9; i++) {
        if (board->isCellEmpty(i+1)) {
            boardState[i] = mark;
            // Check rows
            if ((i/3 == 0 && boardState[0] == boardState[1] && boardState[1] == boardState[2]) ||
                (i/3 == 1 && boardState[3] == boardState[4] && boardState[4] == boardState[5]) ||
                (i/3 == 2 && boardState[6] == boardState[7] && boardState[7] == boardState[8]) ||
                // Check columns
                (i%3 == 0 && boardState[0] == boardState[3] && boardState[3] == boardState[6]) ||
                (i%3 == 1 && boardState[1] == boardState[4] && boardState[4] == boardState[7]) ||
                (i%3 == 2 && boardState[2] == boardState[5] && boardState[5] == boardState[8]) ||
                // Check diagonals
                (i == 0 && boardState[0] == boardState[4] && boardState[4] == boardState[8]) ||
                (i == 2 && boardState[2] == boardState[4] && boardState[4] == boardState[6])) {
                cout << "Smart Computer chooses " << i+1 << " to win\n";
                return i+1;
            }
            boardState[i] = '1' + i; // Reset
        }
    }

    // Block opponent's winning move
    for (int i = 0; i < 9; i++) {
        if (board->isCellEmpty(i+1)) {
            boardState[i] = opponentMark;
            if ((i/3 == 0 && boardState[0] == boardState[1] && boardState[1] == boardState[2]) ||
                (i/3 == 1 && boardState[3] == boardState[4] && boardState[4] == boardState[5]) ||
                (i/3 == 2 && boardState[6] == boardState[7] && boardState[7] == boardState[8]) ||
                (i%3 == 0 && boardState[0] == boardState[3] && boardState[3] == boardState[6]) ||
                (i%3 == 1 && boardState[1] == boardState[4] && boardState[4] == boardState[7]) ||
                (i%3 == 2 && boardState[2] == boardState[5] && boardState[5] == boardState[8]) ||
                (i == 0 && boardState[0] == boardState[4] && boardState[4] == boardState[8]) ||
                (i == 2 && boardState[2] == boardState[4] && boardState[4] == boardState[6])) {
                cout << "Smart Computer blocks at " << i+1 << "\n";
                return i+1;
            }
            boardState[i] = '1' + i; // Reset
        }
    }

    // Take center if available
    if (board->isCellEmpty(5)) {
        cout << "Smart Computer takes center\n";
        return 5;
    }

    // Take a corner if available
    int corners[] = {1, 3, 7, 9};
    for (int corner : corners) {
        if (board->isCellEmpty(corner)) {
            cout << "Smart Computer takes corner " << corner << "\n";
            return corner;
        }
    }

    // Take any available edge
    int edges[] = {2, 4, 6, 8};
    for (int edge : edges) {
        if (board->isCellEmpty(edge)) {
            cout << "Smart Computer takes edge " << edge << "\n";
            return edge;
        }
    }

    // Fallback (shouldn't happen)
    int index = rand() % 9 + 1;
    cout << "Smart Computer randomly selects " << index << "\n";
    return index;
}

class Game {
    Board board;
    Player* player1;
    Player* player2;

    bool checkWin(char mark) {
        char b[9];
        board.getBoardState(b);
        for (int i = 0; i < 9; i += 3) {
            if (b[i] == mark && b[i+1] == mark && b[i+2] == mark) return true;
        }
        for (int i = 0; i < 3; i++) {
            if (b[i] == mark && b[i+3] == mark && b[i+6] == mark) return true;
        }
        return (b[0] == mark && b[4] == mark && b[8] == mark) ||
                (b[2] == mark && b[4] == mark && b[6] == mark);
        }

    bool isBoardFull() {
        char b[9];
        board.getBoardState(b);
        for (int i = 0; i < 9; i++) {
            if (b[i] != 'X' && b[i] != 'O') return false;
        }
        return true;
}


public:
    Game() : player1(nullptr), player2(nullptr) {
        srand(time(0));
    }

    ~Game() {
        delete player1;
        delete player2;
    }

    void setupPlayers() {
        int gameMode;
        cout << "\nTIC-TAC-TOE GAME\n";
        cout << "1. Human vs Human\n";
        cout << "2. Human vs Random Computer\n";
        cout << "3. Human vs Smart Computer\n";
        cout << "4. Random Computer vs Smart Computer\n";
        cout << "Select game mode (1-4): ";
        cin >> gameMode;

        char mark1, mark2;
        cout << "Choose mark for Player 1 (X/O): ";
        cin >> mark1;
        mark1 = toupper(mark1);
        mark2 = (mark1 == 'X') ? 'O' : 'X';

        // Toss to decide who goes first
        bool swapPlayers = (rand() % 2) == 0;
        if (swapPlayers) {
            cout << "Player 2 goes first (won toss)\n";
            swap(mark1, mark2);
        } else {
            cout << "Player 1 goes first (won toss)\n";
        }

        switch (gameMode) {
            case 1:
                player1 = new HumanPlayer(mark1);
                player2 = new HumanPlayer(mark2);
                break;
            case 2:
                player1 = new HumanPlayer(mark1);
                player2 = new NonsenseComputerPlayer(mark2);
                break;
            case 3:
                player1 = new HumanPlayer(mark1);
                player2 = new SensibleComputerPlayer(mark2, &board);
                break;
            case 4:
                player1 = new NonsenseComputerPlayer(mark1);
                player2 = new SensibleComputerPlayer(mark2, &board);
                break;
            default:
                cout << "Invalid choice, defaulting to Human vs Human\n";
                player1 = new HumanPlayer('X');
                player2 = new HumanPlayer('O');
        }
    }

    void play() {
        board.reset();
        Player* currentPlayer = player1;
        board.display();

        while (true) {
            int move;
            do {
                move = currentPlayer->getMove();
            } while (!board.makeMove(move, currentPlayer->getMark()));

            board.display();

            if (checkWin(currentPlayer->getMark())) {
                cout << "Player with " << currentPlayer->getMark() << " wins!\n";
                break;
            } else if (isBoardFull()) {
                cout << "Game ended in a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == player1) ? player2 : player1;
        }
    }

    bool playAgain() {
        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;
        return (toupper(choice) == 'Y');
    }
};

int main() {
    Game game;
    do {
        game.setupPlayers();
        game.play();
    } while (game.playAgain());

    cout << "Thanks for playing!\n";
    return 0;
}