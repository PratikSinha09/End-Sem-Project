#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>
#include<time.h>

#define MAX_QUESTION 256
#define MAX_ANSWER 128
#define TOTAL_QUESTIONS 30
#define CONTROL_PACKET 0
#define DATA_PACKET 1
#define MAX_PACKET 5

// Casino Game Functions
int rules();
int round1();

// Snake Game Functions
void control();
void input();
void setup();
void draw();

// Quiz Game Functions
typedef struct {
    char question[MAX_QUESTION];
    char answerA[MAX_ANSWER];
    char answerB[MAX_ANSWER];
    char answerC[MAX_ANSWER];
    char answerD[MAX_ANSWER];
    char correct_answer;
} quiz_question;

// Global Variables for Snake Game
int height = 20, width = 40, x, y, fruitx, fruity, flag, gameEnd, score;
int tailx[100], taily[100];
int piece = 0;

// Casino Game Functions
int rules() {
    printf("----------------------------------------------------------------------------\n");
    printf("                         RULES\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("         1. Choose any number between 1 to 10\n");
    printf("         2. If you win you will get 10 times of money you bet\n");
    printf("         3. if you bet on wrong number you will lose your betting amount\n");
    printf("------------------------------------------------------------------------------\n");
    return 0;
}

int round1() {
    char name[50];
    printf("Enter your name : ");
    scanf("%s", name);

    printf("\n\n");

    int deposit1;
    printf("Enter the amount of money to deposit for the game : $");
    scanf("%d", &deposit1);

    printf("\n\n");

    printf("Your current balance is $%d", deposit1);

    printf("\n\n");

    int bet1;
    printf("%s, Enter the money to bet : $", name);
    scanf("%d", &bet1);

    printf("\n\n");

    if (bet1 > deposit1) {
        printf("Money Exceeds,\n");
        printf("Enter Again : $");
        scanf("%d", &bet1);
    }

    printf("\n\n");

    int computer1;
    computer1 = rand() % 10;

    int guess1;
    printf("Guess a number from 1 to 10 : ");
    scanf("%d", &guess1);

    printf("\n\n");

    if (guess1 > 10) {
        printf("Number Exceeds,\n");
        printf("Enter Again : ");
        scanf("%d", &guess1);
    }

    printf("\n\n");

    if (guess1 == computer1) {
        printf("You have won $%d", bet1);
        printf("\n\n");

        int bet2;
        bet2 = bet1 * 10;

        int new_won;
        if (bet1 == deposit1) {
            new_won = bet2;
        } else {
            new_won = bet2 + deposit1;
        }

        printf("You have won $%d as total", new_won);

    } else if (guess1 != computer1) {
        printf("You have loss $%d", bet1);
        printf("\n\n");

        printf("The correct number is : %d", computer1);
        printf("\n\n");

        int new_los;
        new_los = deposit1 - bet1;

        printf("Now you have $%d as a balance", new_los);

        printf("\n\n");

        if (new_los == 0) {
            printf("You have $0 as a balance\n");
            printf("You have no more money to play\n");
            printf("Have a nice day");
        } else {
            int decision;
            printf("Press 1 for YES\n");
            printf("Press 2 for NO\n\n");

            printf("Do you want continue(Y/N) : ");
            scanf("%d", &decision);
            printf("\n\n");

            if (decision == 1) {
                rules();

                printf("\n\n");

                printf("Now you have $%d as a balance", new_los);

                printf("\n\n");

                int bet3;
                printf("%s, Enter the money to bet : $", name);
                scanf("%d", &bet3);
                printf("\n\n");

                if (bet3 > new_los) {
                    printf("Money Exceeds,\n");
                    printf("Enter Again : $");
                    scanf("%d", &bet3);
                }

                int guess2;
                printf("Enter a number from 1 to 10 : ");
                scanf("%d", &guess2);
                printf("\n\n");

                int computer2;
                computer2 = rand() % 10;

                if (guess2 > 10) {
                    printf("Number Exceeds,\n");
                    printf("Enter Again : $");
                    scanf("%d", &guess2);
                    printf("\n\n");
                }

                if (guess2 == computer2) {
                    printf("You have won $%d", bet3);
                    printf("\n\n");

                    int b;
                    b = bet3 * 10;

                    int b1;
                    if (bet3 == new_los) {
                        b1 = b + 0;
                    } else {
                        b1 = b + new_los;
                    }

                    printf("You have won $%d as total", b1);
                } else if (guess2 != computer2) {
                    printf("You have loss $%d", bet3);
                    printf("\n\n");

                    int b2;
                    b2 = new_los - bet3;

                    printf("You have $%d as a total", b2);

                    printf("\n\n");

                    if (b2 == 0) {
                        printf("You have $0 as a balance\n");
                        printf("You have no more money to play\n");
                        printf("Have a nice day");
                    }
                }

            } else if (decision == 2) {
                printf("Have a good day sir");

            }
        }

    }
    return 0;
}

// Snake Game Functions
void control() {
    int i;
    int prevx, prevy, prev2x, prev2y;
    prevx = tailx[0];
    prevy = taily[0];
    tailx[0] = x;
    taily[0] = y;
    for (i = 1; i < piece; i++) {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    Sleep(50);
    switch (flag) {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
    }
    if (x == 0 || x == height || y == 0 || y == width)
        gameEnd = 1;
    if (x == fruitx && y == fruity) {
        label3:
        fruitx = rand() % 20;
        if (fruitx == 0)
            goto label3;

        label4:
        fruity = rand() % 40;
        if (fruity == 0)
            goto label4;
        score += 10;
        piece++;
    }
}

void input() {
    if (kbhit()) {
        switch (getch()) {
            case 'w':
                flag = 1;
                break;
            case 's':
                flag = 2;
                break;
            case 'a':
                flag = 3;
                break;
            case 'd':
                flag = 4;
                break;
        }
    }
}

void setup() {
    x = height / 2;
    y = width / 2;

    label1:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1;

    label2:
    fruity = rand() % 40;
    if (fruity == 0)
        goto label2;

    gameEnd = 0;
    score = 0;
    piece = 0;
}

void draw() {
    int ch;
    system("cls");
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            if (i == 0 || i == height || j == 0 || j == width)
                printf("*");
            else {
                if (i == x && j == y)
                    printf("O");
                else if (i == fruitx && j == fruity)
                    printf("0");
                else {
                    ch = 0;
                    for (int k = 0; k < piece; k++) {
                        if (i == tailx[k] && j == taily[k]) {
                            printf("O");
                            ch = 1;
                        }
                    }
                    if (ch == 0)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Your score is: %d", score);
}

// Quiz Game Function
void play_quiz() {
    quiz_question quiz[TOTAL_QUESTIONS];
    strcpy(quiz[0].question, "What is the capital of France?");
    strcpy(quiz[0].answerA, "Berlin");
    strcpy(quiz[0].answerB, "Madrid");
    strcpy(quiz[0].answerC, "Paris");
    strcpy(quiz[0].answerD, "Rome");
    quiz[0].correct_answer = 'C';

    strcpy(quiz[1].question, "Who painted the Mona Lisa?");
    strcpy(quiz[1].answerA, "Leonardo da Vinci");
    strcpy(quiz[1].answerB, "Vincent van Gogh");
    strcpy(quiz[1].answerC, "Pablo Picasso");
    strcpy(quiz[1].answerD, "Michelangelo");
    quiz[1].correct_answer = 'A';

    strcpy(quiz[2].question, "What is the largest mammal in the world?");
    strcpy(quiz[2].answerA, "Elephant");
    strcpy(quiz[2].answerB, "Blue whale");
    strcpy(quiz[2].answerC, "Giraffe");
    strcpy(quiz[2].answerD, "Hippo");
    quiz[2].correct_answer = 'B';

    strcpy(quiz[3].question, "Who wrote 'To Kill a Mockingbird'?");
    strcpy(quiz[3].answerA, "Harper Lee");
    strcpy(quiz[3].answerB, "Mark Twain");
    strcpy(quiz[3].answerC, "J.K. Rowling");
    strcpy(quiz[3].answerD, "Ernest Hemingway");
    quiz[3].correct_answer = 'A';

    strcpy(quiz[4].question, "Which planet is known as the 'Red Planet'?");
    strcpy(quiz[4].answerA, "Earth");
    strcpy(quiz[4].answerB, "Venus");
    strcpy(quiz[4].answerC, "Mars");
    strcpy(quiz[4].answerD, "Jupiter");
    quiz[4].correct_answer = 'C';

    strcpy(quiz[5].question, "What is the capital of Japan?");
    strcpy(quiz[5].answerA, "Beijing");
    strcpy(quiz[5].answerB, "Seoul");
    strcpy(quiz[5].answerC, "Tokyo");
    strcpy(quiz[5].answerD, "Bangkok");
    quiz[5].correct_answer = 'C';

        strcpy(quiz[6].question, "Who wrote 'Romeo and Juliet'?");
    strcpy(quiz[6].answerA, "William Shakespeare");
    strcpy(quiz[6].answerB, "Jane Austen");
    strcpy(quiz[6].answerC, "Charles Dickens");
    strcpy(quiz[6].answerD, "F. Scott Fitzgerald");
    quiz[6].correct_answer = 'A';

    strcpy(quiz[7].question, "What is the largest ocean on Earth?");
    strcpy(quiz[7].answerA, "Indian Ocean");
    strcpy(quiz[7].answerB, "Arctic Ocean");
    strcpy(quiz[7].answerC, "Pacific Ocean");
    strcpy(quiz[7].answerD, "Atlantic Ocean");
    quiz[7].correct_answer = 'C';

    strcpy(quiz[8].question, "Who discovered penicillin?");
    strcpy(quiz[8].answerA, "Alexander Fleming");
    strcpy(quiz[8].answerB, "Marie Curie");
    strcpy(quiz[8].answerC, "Isaac Newton");
    strcpy(quiz[8].answerD, "Albert Einstein");
    quiz[8].correct_answer = 'A';

    strcpy(quiz[9].question, "Which country is known as the 'Land of the Rising Sun'?");
    strcpy(quiz[9].answerA, "China");
    strcpy(quiz[9].answerB, "India");
    strcpy(quiz[9].answerC, "Japan");
    strcpy(quiz[9].answerD, "Australia");
    quiz[9].correct_answer = 'C';

    strcpy(quiz[10].question, "What is the chemical symbol for gold?");
    strcpy(quiz[10].answerA, "Go");
    strcpy(quiz[10].answerB, "Au");
    strcpy(quiz[10].answerC, "Ag");
    strcpy(quiz[10].answerD, "Go");
    quiz[10].correct_answer = 'B';

    strcpy(quiz[11].question, "Who is known as the 'Father of Computers'?");
    strcpy(quiz[11].answerA, "Bill Gates");
    strcpy(quiz[11].answerB, "Charles Babbage");
    strcpy(quiz[11].answerC, "Steve Jobs");
    strcpy(quiz[11].answerD, "Alan Turing");
    quiz[11].correct_answer = 'B';

    strcpy(quiz[12].question, "Which planet is known as the 'Blue Planet'?");
    strcpy(quiz[12].answerA, "Mars");
    strcpy(quiz[12].answerB, "Earth");
    strcpy(quiz[12].answerC, "Venus");
    strcpy(quiz[12].answerD, "Mercury");
    quiz[12].correct_answer = 'B';

    strcpy(quiz[13].question, "Who wrote 'Hamlet'?");
    strcpy(quiz[13].answerA, "William Shakespeare");
    strcpy(quiz[13].answerB, "Leo Tolstoy");
    strcpy(quiz[13].answerC, "Fyodor Dostoevsky");
    strcpy(quiz[13].answerD, "Jane Austen");
    quiz[13].correct_answer = 'A';

    strcpy(quiz[14].question, "What is the chemical symbol for water?");
    strcpy(quiz[14].answerA, "H2O");
    strcpy(quiz[14].answerB, "CO2");
    strcpy(quiz[14].answerC, "O2");
    strcpy(quiz[14].answerD, "H2O2");
    quiz[14].correct_answer = 'A';

    strcpy(quiz[15].question, "What is the capital of Australia?");
    strcpy(quiz[15].answerA, "Melbourne");
    strcpy(quiz[15].answerB, "Sydney");
    strcpy(quiz[15].answerC, "Canberra");
    strcpy(quiz[15].answerD, "Perth");
    quiz[15].correct_answer = 'C';

    strcpy(quiz[16].question, "Who painted 'Starry Night'?");
    strcpy(quiz[16].answerA, "Pablo Picasso");
    strcpy(quiz[16].answerB, "Vincent van Gogh");
    strcpy(quiz[16].answerC, "Leonardo da Vinci");
    strcpy(quiz[16].answerD, "Claude Monet");
    quiz[16].correct_answer = 'B';

    strcpy(quiz[17].question, "What is the currency of Brazil?");
    strcpy(quiz[17].answerA, "Peso");
    strcpy(quiz[17].answerB, "Dollar");
    strcpy(quiz[17].answerC, "Real");
    strcpy(quiz[17].answerD, "Euro");
    quiz[17].correct_answer = 'C';

    strcpy(quiz[18].question, "Which country is famous for the Great Wall?");
    strcpy(quiz[18].answerA, "Japan");
    strcpy(quiz[18].answerB, "China");
    strcpy(quiz[18].answerC, "Russia");
    strcpy(quiz[18].answerD, "India");
    quiz[18].correct_answer = 'B';

    strcpy(quiz[19].question, "What is the tallest animal on Earth?");
    strcpy(quiz[19].answerA, "Elephant");
    strcpy(quiz[19].answerB, "Giraffe");
    strcpy(quiz[19].answerC, "Lion");
    strcpy(quiz[19].answerD, "Rhino");
    quiz[19].correct_answer = 'B';

    strcpy(quiz[20].question, "Who wrote 'The Great Gatsby'?");
    strcpy(quiz[20].answerA, "F. Scott Fitzgerald");
    strcpy(quiz[20].answerB, "Ernest Hemingway");
    strcpy(quiz[20].answerC, "Harper Lee");
    strcpy(quiz[20].answerD, "Mark Twain");
    quiz[20].correct_answer = 'A';

    strcpy(quiz[21].question, "Which country is known as the 'Land of the Rising Sun'?");
    strcpy(quiz[21].answerA, "Japan");
    strcpy(quiz[21].answerB, "China");
    strcpy(quiz[21].answerC, "India");
    strcpy(quiz[21].answerD, "Korea");
    quiz[21].correct_answer = 'A';

    strcpy(quiz[22].question, "Who is the author of '1984'?");
    strcpy(quiz[22].answerA, "George Orwell");
    strcpy(quiz[22].answerB, "Aldous Huxley");
    strcpy(quiz[22].answerC, "F. Scott Fitzgerald");
    strcpy(quiz[22].answerD, "Ernest Hemingway");
    quiz[22].correct_answer = 'A';

    strcpy(quiz[23].question, "What is the chemical symbol for iron?");
    strcpy(quiz[23].answerA, "Fe");
    strcpy(quiz[23].answerB, "Ir");
    strcpy(quiz[23].answerC, "In");
    strcpy(quiz[23].answerD, "I");
    quiz[23].correct_answer = 'A';

    strcpy(quiz[24].question, "What is the smallest country in the world?");
    strcpy(quiz[24].answerA, "Monaco");
    strcpy(quiz[24].answerB, "Maldives");
    strcpy(quiz[24].answerC, "Vatican City");
    strcpy(quiz[24].answerD, "San Marino");
    quiz[24].correct_answer = 'C';

    strcpy(quiz[25].question, "Who invented the telephone?");
    strcpy(quiz[25].answerA, "Thomas Edison");
    strcpy(quiz[25].answerB, "Alexander Graham Bell");
    strcpy(quiz[25].answerC, "Nikola Tesla");
    strcpy(quiz[25].answerD, "Michael Faraday");
    quiz[25].correct_answer = 'B';

    strcpy(quiz[26].question, "What is the chemical symbol for silver?");
    strcpy(quiz[26].answerA, "S");
    strcpy(quiz[26].answerB, "Si");
    strcpy(quiz[26].answerC, "Ag");
    strcpy(quiz[26].answerD, "Au");
    quiz[26].correct_answer = 'C';

    strcpy(quiz[27].question, "Who wrote 'The Lord of the Rings'?");
    strcpy(quiz[27].answerA, "George R.R. Martin");
    strcpy(quiz[27].answerB, "J.R.R. Tolkien");
    strcpy(quiz[27].answerC, "C.S. Lewis");
    strcpy(quiz[27].answerD, "J.K. Rowling");
    quiz[27].correct_answer = 'B';

    strcpy(quiz[28].question, "What is the largest organ in the human body?");
    strcpy(quiz[28].answerA, "Brain");
    strcpy(quiz[28].answerB, "Liver");
    strcpy(quiz[28].answerC, "Skin");
    strcpy(quiz[28].answerD, "Heart");
    quiz[28].correct_answer = 'C';

    strcpy(quiz[29].question, "Who developed the theory of relativity?");
    strcpy(quiz[29].answerA, "Isaac Newton");
    strcpy(quiz[29].answerB, "Albert Einstein");
    strcpy(quiz[29].answerC, "Stephen Hawking");
    strcpy(quiz[29].answerD, "Galileo Galilei");
    quiz[29].correct_answer = 'B';
    
    double total_correct = 0;
    char answer;

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("Question %d: %s\n\n", (i + 1), quiz[i].question);
        printf("A) %s\n", quiz[i].answerA);
        printf("B) %s\n", quiz[i].answerB);
        printf("C) %s\n", quiz[i].answerC);
        printf("D) %s\n", quiz[i].answerD);
        printf("\nEnter Answer (A, B, C, or D): ");
        scanf(" %c", &answer);

        if (toupper(answer) == quiz[i].correct_answer) {
            total_correct++;
            printf("\n\nCorrect Answer!");
        } else {
            printf("\n\nIncorrect Answer!");
            printf("\n\nThe correct answer was %c.", quiz[i].correct_answer);
        }
        printf("\n\n\n");
    }

    printf("%d/%d questions answered correctly", (int) total_correct, TOTAL_QUESTIONS);
    printf(" (%.2f%%)\n\n", (total_correct / TOTAL_QUESTIONS) * 100);
}

//tic-tac-toe

char board[3][3]; // 3x3 connectboard

// Function to initialize the connectboard with empty spaces
void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the current connectboard
void print_board() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if a player has won
int check_win(char mark) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return 1;
        }
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
            return 1;
        }
    }
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return 1;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full
int check_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Not full
            }
        }
    }
    return 1; // Full
}

// Function to play the game
void play_game() {
    char player1 = 'X';
    char player2 = 'O';
    char current_player = player1;
    int row, col;
    int game_over = 0;

    initialize_board();

    printf("Let's play Tic-Tac-Toe!\n");
    print_board();

    while (!game_over) {
        printf("Player %c's turn. Enter row and column (0-2): ", current_player);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = current_player;
        print_board();

        if (check_win(current_player)) {
            printf("Player %c wins!\n", current_player);
            game_over = 1;
        } else if (check_draw()) {
            printf("It's a draw!\n");
            game_over = 1;
        }

        // Switch players
        current_player = (current_player == player1) ? player2 : player1;
    }
}

//Connect 4
#define ROWS 6
#define COLS 7

char connectboard[ROWS][COLS];

// Function to initialize the game connectboard
void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            connectboard[i][j] = ' ';
        }
    }
}

// Function to print the game connectboard
void printBoard() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            printf("%c|", connectboard[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
    printf(" 1 2 3 4 5 6 7\n");
}

// Function to check if a column is full
bool isColumnFull(int col) {
    return connectboard[0][col] != ' ';
}

// Function to drop a disc into a column
void dropDisc(int col, char disc) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (connectboard[i][col] == ' ') {
            connectboard[i][col] = disc;
            break;
        }
    }
}

// Function to check if there's a winner
bool checkWin(char disc) {
    // Check horizontally
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (connectboard[i][j] == disc &&
                connectboard[i][j+1] == disc &&
                connectboard[i][j+2] == disc &&
                connectboard[i][j+3] == disc) {
                return true;
            }
        }
    }
    // Check vertically
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            if (connectboard[i][j] == disc &&
                connectboard[i+1][j] == disc &&
                connectboard[i+2][j] == disc &&
                connectboard[i+3][j] == disc) {
                return true;
            }
        }
    }
    // Check diagonally (positive slope)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (connectboard[i][j] == disc &&
                connectboard[i+1][j+1] == disc &&
                connectboard[i+2][j+2] == disc &&
                connectboard[i+3][j+3] == disc) {
                return true;
            }
        }
    }
    // Check diagonally (negative slope)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 3; j < COLS; j++) {
            if (connectboard[i][j] == disc &&
                connectboard[i+1][j-1] == disc &&
                connectboard[i+2][j-2] == disc &&
                connectboard[i+3][j-3] == disc) {
                return true;
            }
        }
    }
    return false;
}

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 20
#define MAX_TRIES 6


char *words[MAX_WORDS] = {
"sucide",
"college",
"fest",
"reservation",
"hostel",
"mess",
"fees",
"friends",
"depression",
"exams",
"vacations",
"semester"
};

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

void displayHangman(int tries) {
    printf("\n");
    printf("  +---+\n");
    printf("  |   |\n");
    
    if (tries < MAX_TRIES)
        printf("      |\n");
    else
        printf("  O   |\n");

    if (tries < MAX_TRIES - 1)
        printf("      |\n");
    else if (tries < MAX_TRIES)
        printf("  |   |\n");
    else
        printf(" /|   |\n");

    if (tries < MAX_TRIES - 3)
        printf("      |\n");
    else if (tries < MAX_TRIES - 2)
        printf(" /    |\n");
    else if (tries < MAX_TRIES)
        printf(" /|\\  |\n");
    else
        printf(" /|\\  |\n");

    if (tries < MAX_TRIES - 4)
        printf("      |\n");
    else if (tries < MAX_TRIES - 3)
        printf(" /    |\n");
    else if (tries < MAX_TRIES - 2)
        printf(" / \\  |\n");
    else if (tries < MAX_TRIES)
        printf(" / \\  |\n");
    else
        printf(" / \\  |\n");

    printf("|\n");
    printf("\n");
}

// stone paper scissor

void sps() {
    int Player_Score = 0;
    int Computer_score = 0;
    int Player_choice, Computer_choice;

    printf("\n\n\t\t**********Stone, Paper, scissors Game*********\n\n");
    printf("You will have a five round game with the computer,lets start\n\n");
    printf("\tPress 1 for Stone:\n\tPress 2 for Paper:\n\tPress 3 for Scissors:\n");
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &Player_choice);
        Computer_choice = (rand() % 3) + 1;

        if (Player_choice == 1)
        {
            if (Computer_choice == 1)
            {
                printf("Player chose stone and computer chose stone\n");
                printf("Draw\n");
            }
            else if (Computer_choice == 2)
            {
                printf("Player chose stone and computer chose paper\n");
                printf("Computer wins\n");
                Computer_score = Computer_score + 1;
            }
            else
            {
                printf("Player chose stone and computer chose scissors\n");
                printf("Player wins\n");
                Player_Score++;
            }
        }
        else if (Player_choice == 2)
        {
            if (Computer_choice == 1)
            {
                printf("Player chose paper and computer chose stone\n");
                printf("Player wins\n");
                Player_Score++;
            }
            else if (Computer_choice == 2)
            {
                printf("Player chose paper and computer chose paper\n");
                printf("Draw\n");
            }
            else
            {
                printf("Player chose paper and computer chose scissors\n");
                printf("Computer wins\n");
                Computer_score++;
            }
        }
        else if (Player_choice == 3)
        {
            if (Computer_choice == 1)
            {
                printf("Player chose scissors and computer chose stone\n");
                printf("Computer wins\n");
                Computer_score++;
            }
            else if (Computer_choice == 2)
            {
                printf("Player chose scissors and computer chose paper\n");
                printf("Player wins\n");
                Player_Score++;
            }
            else
            {
                printf("Player chose scissors and computer chose scissors\n");
                printf("Draw\n");
            }
        }
        else
        {
            printf("Wrong answer\n");
        }
        printf("\n\tPlayer score: %d , Computer score: %d\n", Player_Score, Computer_score);
    }
    if (Computer_score > Player_Score)
        printf("Computer wins %d to %d", Computer_score, Player_Score);

    else if (Computer_score < Player_Score)
        printf("Player wins %d to %d", Player_Score, Computer_score);

    else if (Computer_score = Player_Score)
        printf("No winner, it is a draw");

    printf("\n\t\tGAME OVER\nPress enter to quit");
    getch();
}

// Main function
int main() {
    int choice;
    printf("Choose the game you want to play:\n");
    printf("1. Casino Game\n");
    printf("2. Snake Game\n");
    printf("3. Quiz Game\n");
    printf("4. Tic-tac-toe\n");
    printf("5. Connect Four\n");
    printf("6. Hangman\n");
    printf("7. Stone-paper-scissor\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            rules();
            round1();
            break;
        case 2:
            setup();
            while (gameEnd != 1) {
                input();
                draw();
                control();
            }
            break;
        case 3:
            play_quiz();
            break;
        case 4:
            play_game();
            break;
        case 5:
            initializeBoard();
            printBoard();

            bool player1Turn = true;
            int moves = 0;
            while (true) {
                int column;
                char disc = (player1Turn) ? 'X' : 'O';

                do {
                    printf("Player %c, enter column number (1-7): ", disc);
                    scanf("%d", &column);
                    column--; // Adjusting to 0-based index
                } while (column < 0 || column >= COLS || isColumnFull(column));

                dropDisc(column, disc);
                printBoard();

                if (checkWin(disc)) {
                    printf("Player %c wins!\n", disc);
                    break;
                }

                moves++;
                if (moves == ROWS * COLS) {
                    printf("It's a draw!\n");
                    break;
                }

                player1Turn = !player1Turn;
            }
            break;
        
        case 6:
            srand(time(NULL));

            int randomIndex = getRandomNumber(0, MAX_WORDS - 1);
            char *word = words[randomIndex];
            int wordLength = strlen(word);

            char *hiddenWord = malloc((wordLength + 1) * sizeof(char));
            strcpy(hiddenWord, word);

            // Initialize hiddenWord with underscores
            for (int i = 0; i < wordLength; i++) {
                hiddenWord[i] = '_';
            }
            hiddenWord[wordLength] = '\0';

            int tries = 0;
            int correctGuesses = 0;
            char guess;
            char guessedLetters[26] = {0};

            printf("Welcome to Hangman!\n");

            while (tries < MAX_TRIES && correctGuesses < wordLength) {
                printf("\nWord: %s\n", hiddenWord);
                printf("Tries left: %d\n", MAX_TRIES - tries);
                printf("Enter a letter: ");
                scanf(" %c", &guess);

                guess = tolower(guess);

                if (!isalpha(guess)) {
                    printf("Please enter a valid letter.\n");
                    continue;
                }

                if (guessedLetters[guess - 'a']) {
                    printf("You've already guessed that letter.\n");
                    continue;
                }

                guessedLetters[guess - 'a'] = 1;

                int found = 0;
                for (int i = 0; i < wordLength; i++) {
                    if (word[i] == guess) {
                        hiddenWord[i] = guess;
                        found = 1;
                        correctGuesses++;
                    }
                }

                if (!found) {
                    tries++;
                    displayHangman(tries);
                }
            }

            if (correctGuesses == wordLength) {
                printf("\nCongratulations! You guessed the word: %s\n", word);
            } else {
                printf("\nSorry, you ran out of tries. The word was: %s\n", word);
            }

            free(hiddenWord);
            break;

        case 7:
            sps();
            break;

        default:
            printf("Invalid choice! Please choose 1, 2, or 3.\n");
            break;
    }

    return 0;
}



