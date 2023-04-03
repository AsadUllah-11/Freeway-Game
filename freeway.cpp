// Library Files
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

// Global Arrays and Variables
bool gameRunning = true;
int playerX = 2;
int playerY = 32;
int enemyOneX = 100;
int enemyOneY = 30;
int enemyTwoX = 93;
int enemyTwoY = 23;
int enemyThreeX = 92;
int enemyThreeY = 16;
int enemyFourX = 97;

int enemyFourY = 9;
int enemyFiveX = 93;
int enemyFiveY = 1;
int enemyHealthX = 130;
int enemyHealthY = 5;
int livesX = 130;
int livesY = 10;
int enemyOneHeal = 0;
int enemyTwoHeal = 0;
int enemyThreeHeal = 0;
int enemyFourHeal = 0;
int enemyFiveHeal = 0;
int livesCount = 3;
bool moveEnemy1 = true;
bool moveEnemy2 = true;
bool moveEnemy3 = true;
bool moveEnemy4 = true;
bool moveEnemy5 = true;
int timer = 0, timer2 = 0, timer3 = 0, timer4 = 0, timer5 = 0;
int checkOne = 0, checkTwo = 0, checkThree = 0, checkFour = 0, checkFive = 0;
int enemyDieCount = 0;

// Player Bullets
int bulletX[1000];
int bulletY[1000];
bool isBulletActive[1000];
int bulletCount = 0;
int choice;

// Function Prototypes
void printHeader();
int printMenu();
void printPlayer();
void erasePlayer();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void printMaze();
void clearScreen();
void movePlayerRight();
void movePlayerLeft();
void movePlayerUp();
void movePlayerDown();
void generateBullet();
void moveBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int index);
void printEnemyOne();
void moveEnemyOne();
void reduceEnemyOneHealth();
void bulletCollisionWithEnemyOne();
void showEnemyOneHealth();
void showLives();
void checkEnemyOneHealth();
void eraseEnemyOne();
void borderLineOne();
void checkMaze();
void printEnemyTwo();
void moveEnemyTwo();
void eraseEnemyTwo();
void showEnemyTwoHealth();
void bulletCollisionWithEnemyTwo();
void reduceEnemyTwoHealth();
void checkEnemyTwoHealth();
void printEnemyThree();
void printEnemyFour();
void keysSpecs();
void printEnemyFive();
void changeLives();
void eraseEnemyThree();
void moveEnemyThree();
void checkEnemyThreeHealth();
void reduceEnemyThreeHealth();
void bulletCollisionWithEnemyThree();
void showEnemyThreeHealth();
void eraseEnemyFour();
void moveEnemyFour();
void checkEnemyFourHealth();
void reduceEnemyFourHealth();
void bulletCollisionWithEnemyFour();
void showEnemyFourHealth();
void eraseEnemyFive();
void moveEnemyFive();
void checkEnemyFiveHealth();
void reduceEnemyFiveHealth();
void bulletCollisionWithEnemyFive();
void showEnemyFiveHealth();
void speedEnemies();
void generateColors(int k);
void saveData();
void loadData();
void game();
void checkEnemies();

main()
{
    generateColors(6);
    clearScreen();
    printHeader();
    int result = printMenu();
    if (result == 1)
    {
        game();
    }
    if (result == 2)
    {
        keysSpecs();
    }
    if (result == 3)
    {
        loadData();
        checkMaze();
        // enemiesDieCount();
        game();
    }
    if (result == 4)
    {
        gameRunning = false;
    }
}

void game()
{
    clearScreen();
    printMaze();
    // checkBorderLines();
    gotoxy(120, 20);
    cout << "Press ESCAPE Key to SAVE the Game Data";
    gotoxy(playerX, playerY);
    printPlayer();
    printEnemyOne();
    printEnemyTwo();
    printEnemyThree();
    printEnemyFour();
    printEnemyFive();
    showEnemyOneHealth();
    showLives();
    while (gameRunning)
    {
        checkEnemies();
        changeLives();
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            saveData();
            gameRunning = false;
        }
        if (enemyFiveHeal >= 150)
        {
            gotoxy(60, 10);
            cout << "YOU WON!!!";
            gameRunning = false;
        }
        speedEnemies();
        moveBullet();
        bulletCollisionWithEnemyOne();
        bulletCollisionWithEnemyTwo();
        bulletCollisionWithEnemyThree();
        bulletCollisionWithEnemyFour();
        bulletCollisionWithEnemyFive();
        Sleep(20);
        showLives();
        if (enemyOneHeal <= 100)
        {
            checkEnemyOneHealth();
            showEnemyOneHealth();
        }
        if (enemyOneHeal >= 100)
        {
            checkEnemyTwoHealth();
            showEnemyTwoHealth();
        }
        if (enemyTwoHeal >= 120)
        {
            checkEnemyThreeHealth();
            showEnemyThreeHealth();
        }
        if (enemyThreeHeal >= 130)
        {
            checkEnemyFourHealth();
            showEnemyFourHealth();
        }
        if (enemyFourHeal >= 135)
        {
            checkEnemyFiveHealth();
            showEnemyFiveHealth();
        }
        checkMaze();
    }
}
void loadData()
{
    fstream file;
    file.open("gameData.txt", ios::in);
    file >> playerX;
    file >> playerY;
    file >> enemyOneX;
    file >> enemyOneY;
    file >> enemyTwoX;
    file >> enemyTwoY;
    file >> enemyThreeX;
    file >> enemyThreeY;
    file >> enemyFourX;

    file >> enemyFourY;
    file >> enemyFiveX;
    file >> enemyFiveY;
    file >> enemyHealthX;
    file >> enemyHealthY;
    file >> livesX;
    file >> livesY;
    file >> enemyOneHeal;
    file >> enemyTwoHeal;
    file >> enemyThreeHeal;
    file >> enemyFourHeal;
    file >> enemyFiveHeal;
    file >> livesCount;

    file >> moveEnemy1;
    file >> moveEnemy2;
    file >> moveEnemy3;
    file >> moveEnemy4;
    file >> moveEnemy5;
    file.close();
}
void saveData()
{
    fstream file;
    file.open("gameData.txt", ios::out);
    file << playerX << endl;
    file << playerY << endl;
    file << enemyOneX << endl;
    file << enemyOneY << endl;
    file << enemyTwoX << endl;
    file << enemyTwoY << endl;
    file << enemyThreeX << endl;
    file << enemyThreeY << endl;
    file << enemyFourX << endl;
    file << enemyFourY << endl;
    file << enemyFiveX << endl;
    file << enemyFiveY << endl;
    file << enemyHealthX << endl;
    file << enemyHealthY << endl;
    file << livesX << endl;
    file << livesY << endl;
    file << enemyOneHeal << endl;
    file << enemyTwoHeal << endl;
    file << enemyThreeHeal << endl;
    file << enemyFourHeal << endl;
    file << enemyFiveHeal << endl;
    file << livesCount << endl;
    file << moveEnemy1 << endl;
    file << moveEnemy2 << endl;
    file << moveEnemy3 << endl;
    file << moveEnemy4 << endl;
    file << moveEnemy5 << endl;
    file.close();
}
void checkEnemies()
{
    if (enemyOneHeal >= 100 && checkOne == 0)
    {
        eraseEnemyOne();
        checkOne++;
    }
    if (enemyTwoHeal >= 120 && checkTwo == 0)
    {
        eraseEnemyTwo();
        checkTwo++;
    }
    if (enemyThreeHeal >= 130 && checkThree == 0)
    {
        eraseEnemyThree();
        checkThree++;
    }
    if (enemyFourHeal >= 135 && checkFour == 0)
    {
        eraseEnemyFour();
        checkFour++;
    }
    if (enemyFiveHeal >= 150 && checkFive == 0)
    {
        eraseEnemyFive();
        checkFive++;
    }
}
void generateColors(int k)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}
void speedEnemies()
{
    if (timer == 10)
    {
        moveEnemyOne();
        // moveEnemyTwo();
        // moveEnemyThree();
        // moveEnemyFour();
        // moveEnemyFive();
        timer = 0;
    }
    if (timer2 == 6)
    {
        moveEnemyTwo();
        timer2 = 0;
    }
    if (timer3 == 5)
    {
        moveEnemyThree();
        timer3 = 0;
    }
    if (timer4 == 4)
    {
        moveEnemyFour();
        timer4 = 0;
    }
    if (timer5 == 3)
    {
        moveEnemyFive();
        timer5 = 0;
    }

    timer++;
    timer2++;
    timer3++;
    timer4++;
    timer5++;
}
void showEnemyFiveHealth()
{
    if (enemyFiveHeal <= 150 && enemyFiveHeal >= 0)
    {
        gotoxy(enemyHealthX, enemyHealthY);
        cout << "                                 ";
        gotoxy(enemyHealthX, enemyHealthY);
        cout << "Enemy Health: ";
        char healthBox = 254;
        gotoxy(enemyHealthX + 14, enemyHealthY);
        cout << enemyFiveHeal;
    }
}
void bulletCollisionWithEnemyFive()
{
    char next = getCharAtxy(enemyFiveX - 1, enemyFiveY);
    char next1 = getCharAtxy(enemyFiveX - 1, enemyFiveY + 1);
    char next2 = getCharAtxy(enemyFiveX - 1, enemyFiveY + 2);
    char next3 = getCharAtxy(enemyFiveX - 1, enemyFiveY + 3);
    char next4 = getCharAtxy(enemyFiveX - 1, enemyFiveY + 4);
    char next5 = getCharAtxy(enemyFiveX - 1, enemyFiveY + 5);
    if (next == '.' || next1 == '.' || next2 == '.' || next3 == '.' || next4 == '.' || next5 == '.')
    {
        reduceEnemyFiveHealth();
    }
}
void reduceEnemyFiveHealth()
{
    enemyFiveHeal++;
}
void checkEnemyFiveHealth()
{
    if (enemyFiveHeal == 150)
    {
        eraseEnemyFive();
        moveEnemy5 = false;
    }
}
void moveEnemyFive()
{
    if (enemyFourHeal >= 135)
    {
        if (moveEnemy5 == true)
        {
            generateColors(4);
            gotoxy(enemyFiveX, enemyFiveY);
            char next = getCharAtxy(enemyFiveX - 1, enemyFiveY);
            if (next == ' ' || next == '.')
            {
                eraseEnemyFive();
                enemyFiveX = enemyFiveX - 1;
                gotoxy(enemyFiveX, enemyFiveY);
                printEnemyFive();
                Sleep(40);
            }
            if (next == '#')
            {
                eraseEnemyFive();
                enemyFiveX = 93;
                enemyFiveY = 1;
            }
            generateColors(2);
        }
    }
}
void eraseEnemyFive()
{
    gotoxy(enemyFiveX, enemyFiveY);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
    gotoxy(enemyFiveX, enemyFiveY + 1);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
    gotoxy(enemyFiveX, enemyFiveY + 2);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
    gotoxy(enemyFiveX, enemyFiveY + 3);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
    gotoxy(enemyFiveX, enemyFiveY + 4);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
    gotoxy(enemyFiveX, enemyFiveY + 5);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
}
void showEnemyFourHealth()
{
    if (enemyFourHeal <= 135 && enemyFourHeal >= 0)
    {
        gotoxy(enemyHealthX, enemyHealthY);
        cout << "                                 ";
        gotoxy(enemyHealthX, enemyHealthY);
        cout << "Enemy Health: ";
        char healthBox = 254;
        gotoxy(enemyHealthX + 14, enemyHealthY);
        cout << enemyFourHeal;
    }
}
void bulletCollisionWithEnemyFour()
{
    char next = getCharAtxy(enemyFourX - 1, enemyFourY);
    char next1 = getCharAtxy(enemyFourX - 1, enemyFourY + 1);
    char next2 = getCharAtxy(enemyFourX - 1, enemyFourY + 2);
    char next3 = getCharAtxy(enemyFourX - 1, enemyFourY + 3);
    if (next == '.' || next1 == '.' || next2 == '.' || next3 == '.')
    {
        reduceEnemyFourHealth();
    }
}
void reduceEnemyFourHealth()
{
    enemyFourHeal++;
}
void checkEnemyFourHealth()
{
    if (enemyFourHeal == 135)
    {
        eraseEnemyFour();
        moveEnemy4 = false;
    }
}
void moveEnemyFour()
{
    if (enemyThreeHeal >= 130)
    {
        if (moveEnemy4 == true)
        {
            generateColors(4);
            gotoxy(enemyFourX, enemyFourY);
            char next = getCharAtxy(enemyFourX - 1, enemyFourY);
            if (next == ' ' || next == '.')
            {
                eraseEnemyFour();
                enemyFourX = enemyFourX - 1;
                gotoxy(enemyFourX, enemyFourY);
                printEnemyFour();
                Sleep(50);
            }
            if (next == '#')
            {
                eraseEnemyFour();
                enemyFourX = 97;
                enemyFourY = 9;
            }
            generateColors(2);
        }
    }
}
void eraseEnemyFour()
{
    gotoxy(enemyFourX, enemyFourY);
    for (int x = 0; x < 13; x++)
    {
        cout << " ";
    }
    gotoxy(enemyFourX, enemyFourY + 1);
    for (int x = 0; x < 13; x++)
    {
        cout << " ";
    }
    gotoxy(enemyFourX, enemyFourY + 2);
    for (int x = 0; x < 13; x++)
    {
        cout << " ";
    }
    gotoxy(enemyFourX, enemyFourY + 3);
    for (int x = 0; x < 13; x++)
    {
        cout << " ";
    }
}
void showEnemyThreeHealth()
{
    if (enemyThreeHeal <= 130 && enemyThreeHeal >= 0)
    {
        gotoxy(enemyHealthX, enemyHealthY);
        cout << "                                 ";
        gotoxy(enemyHealthX, enemyHealthY);
        cout << "Enemy Health: ";
        char healthBox = 254;
        gotoxy(enemyHealthX + 14, enemyHealthY);
        cout << enemyThreeHeal;
    }
}
void checkEnemyThreeHealth()
{
    if (enemyThreeHeal == 130)
    {
        eraseEnemyThree();
        moveEnemy3 = false;
    }
}
void reduceEnemyThreeHealth()
{
    enemyThreeHeal++;
}
void bulletCollisionWithEnemyThree()
{
    char next = getCharAtxy(enemyThreeX - 1, enemyThreeY);
    char next1 = getCharAtxy(enemyThreeX - 1, enemyThreeY + 1);
    char next2 = getCharAtxy(enemyThreeX - 1, enemyThreeY + 2);
    char next3 = getCharAtxy(enemyThreeX - 1, enemyThreeY + 3);
    if (next == '.' || next1 == '.' || next2 == '.' || next3 == '.')
    {
        reduceEnemyThreeHealth();
    }
}
void moveEnemyThree()
{
    if (enemyTwoHeal >= 120)
    {
        if (moveEnemy3 == true)
        {
            generateColors(4);
            gotoxy(enemyThreeX, enemyThreeY);
            char next = getCharAtxy(enemyThreeX - 1, enemyThreeY);
            if (next == ' ' || next == '.')
            {
                eraseEnemyThree();
                enemyThreeX = enemyThreeX - 1;
                gotoxy(enemyThreeX, enemyThreeY);
                printEnemyThree();
                Sleep(70);
            }
            if (next == '#')
            {
                eraseEnemyThree();
                enemyThreeX = 92;
                enemyThreeY = 16;
            }
            generateColors(2);
        }
    }
}
void eraseEnemyThree()
{
    gotoxy(enemyThreeX, enemyThreeY);
    for (int x = 0; x < 18; x++)
    {
        cout << " ";
    }
    gotoxy(enemyThreeX, enemyThreeY + 1);
    for (int x = 0; x < 18; x++)
    {
        cout << " ";
    }
    gotoxy(enemyThreeX, enemyThreeY + 2);
    for (int x = 0; x < 18; x++)
    {
        cout << " ";
    }
    gotoxy(enemyThreeX, enemyThreeY + 3);
    for (int x = 0; x < 18; x++)
    {
        cout << " ";
    }
}
void changeLives()
{
    if (livesCount >= 0)
    {
        int check = 0;
        char next = getCharAtxy(playerX, playerY);
        char next2 = getCharAtxy(playerX + 5, playerY + 1);
        char next3 = getCharAtxy(playerX + 5, playerY + 3);
        if (next != '.' && next != ' ' && next != '#')
        {
            livesCount--;
            check++;
        }
        else if (next2 != '.' && next2 != ' ' && next2 != '#')
        {
            livesCount--;
            check++;
        }
        else if (next3 != '.' && next3 != ' ' && next3 != '#')
        {
            livesCount--;
            check++;
        }
        // if ((livesCount == 2 || livesCount == 1) && enemyOneHeal < 100)
        // {
        //     int check = 0;
        //     eraseEnemyOne();
        //     if (check == 0)
        //     {
        //         enemyOneX = 100;
        //         enemyOneY = 30;
        //         check++;
        //     }
        //     moveEnemyOne();
        // }
        if (livesCount < 3)
        {
            gotoxy(livesX + 17, livesY);
            cout << "   ";
            showLives();
        }
        if (livesCount > 0 && livesCount <= 3)
        {
            if (check > 0 && check <= 3)
            {
                erasePlayer();
                playerX = 2;
                playerY = 32;
                gotoxy(playerX, playerY);
                printPlayer();
                check = 0;
            }
        }
        if (livesCount == 0)
        {
            gameRunning = false;
            gotoxy(60, 10);
            cout << "GAME OVER!!!";
        }
    }
}
void printEnemyFive()
{
    gotoxy(enemyFiveX, enemyFiveY);
    cout << "  ._________.   " << endl;
    gotoxy(enemyFiveX, enemyFiveY + 1);
    cout << " /-----------\\ " << endl;
    gotoxy(enemyFiveX, enemyFiveY + 2);
    cout << "| (@)    (@)  | " << endl;
    gotoxy(enemyFiveX, enemyFiveY + 3);
    cout << "*      |      * " << endl;
    gotoxy(enemyFiveX, enemyFiveY + 4);
    cout << " *     -     *  " << endl;
    gotoxy(enemyFiveX, enemyFiveY + 5);
    cout << "   * * * * *    " << endl;
}
void keysSpecs()
{
    clearScreen();
    printHeader();
    cout << "1) Enter Arrow Keys for Player Movement" << endl;
    cout << "2) Enter Space for Firing" << endl;
    cout << "        Press any Key to Continue...";
    getch();
    clearScreen();
    printHeader();
    printMenu();
}
int printMenu()
{
    cout << " ______________________________________________________" << endl;
    cout << " 1) Start New Game" << endl;
    cout << " 2) Press Keys Specifications" << endl;
    cout << " 3) Resume Game" << endl;
    cout << " 4) Exit" << endl;
    cout << "Enter Your Choice...";
    cin >> choice;
    return choice;
}
void printEnemyFour()
{
    gotoxy(enemyFourX, enemyFourY);
    cout << " ___       " << endl;
    gotoxy(enemyFourX, enemyFourY + 1);
    cout << "  |_-___-_  " << endl;
    gotoxy(enemyFourX, enemyFourY + 2);
    cout << " /___|___\\" << endl;
    gotoxy(enemyFourX, enemyFourY + 3);
    cout << "(@)     (@)" << endl;
}
void printHeader()
{
    cout << "*****************************************************************************************************" << endl;
    cout << "*                                                                                                   *  " << endl;
    cout << "*  $$$$$$$$$$$ $$$$$$$$$$$  $$$$$$$$$$ $$$$$$$$$$ $$      $$       $$       $$      $$         $$   * " << endl;
    cout << "*  $$          $$       $$  $$         $$         $$     $$ $$     $$      $$ $$      $$     $$     * " << endl;
    cout << "*  $$          $$      $$   $$         $$         $$    $$   $$    $$     $$   $$       $$ $$       *" << endl;
    cout << "*  $$$$$$$     $$$$$$$$     $$$$$$$$   $$$$$$$$   $$   $$     $$   $$    $$$$$$$$$        $$        *" << endl;
    cout << "*  $$          $$     $$    $$         $$         $$  $$       $$  $$   $$       $$       $$        *   " << endl;
    cout << "*  $$          $$      $$   $$         $$         $$ $$         $$ $$  $$         $$      $$        *  " << endl;
    cout << "*  $$          $$       $$  $$$$$$$$$$ $$$$$$$$$$  $$             $$  $$           $$     $$        *            " << endl;
    cout << "*                                                                                                   *  " << endl;
    cout << "*****************************************************************************************************" << endl;
}
void printEnemyThree()
{
    gotoxy(enemyThreeX, enemyThreeY);
    cout << "      __________ " << endl;
    gotoxy(enemyThreeX, enemyThreeY + 1);
    cout << "<====(..........)" << endl;
    gotoxy(enemyThreeX, enemyThreeY + 2);
    cout << "     \\(@)___(@)/" << endl;
    gotoxy(enemyThreeX, enemyThreeY + 3);
    cout << "      *********  " << endl;
}
void bulletCollisionWithEnemyTwo()
{
    char next = getCharAtxy(enemyTwoX - 1, enemyTwoY);
    char next1 = getCharAtxy(enemyTwoX - 1, enemyTwoY + 1);
    char next2 = getCharAtxy(enemyTwoX - 1, enemyTwoY + 2);
    char next3 = getCharAtxy(enemyTwoX - 1, enemyTwoY + 3);
    if (next == '.' || next1 == '.' || next2 == '.' || next3 == '.')
    {
        reduceEnemyTwoHealth();
    }
}
void checkEnemyTwoHealth()
{
    if (enemyTwoHeal == 120)
    {
        eraseEnemyTwo();
        moveEnemy2 = false;
    }
}
void reduceEnemyTwoHealth()
{
    enemyTwoHeal++;
}
void showEnemyTwoHealth()
{
    if (enemyTwoHeal <= 120 && enemyTwoHeal >= 0)
    {
        gotoxy(enemyHealthX, enemyHealthY);
        cout << "                                 ";
        gotoxy(enemyHealthX, enemyHealthY);
        cout << "Enemy Health: ";
        char healthBox = 254;
        gotoxy(enemyHealthX + 14, enemyHealthY);
        cout << enemyTwoHeal;
    }
}
void moveEnemyTwo()
{
    if (enemyOneHeal >= 100)
    {
        if (moveEnemy2 == true)
        {
            generateColors(4);
            gotoxy(enemyTwoX, enemyTwoY);
            char next = getCharAtxy(enemyTwoX - 1, enemyTwoY);
            if (next == ' ' || next == '.')
            {
                eraseEnemyTwo();
                enemyTwoX = enemyTwoX - 1;
                gotoxy(enemyTwoX, enemyTwoY);
                printEnemyTwo();
                Sleep(70);
            }
            if (next == '#')
            {
                eraseEnemyTwo();
                enemyTwoX = 93;
                enemyTwoY = 23;
            }
            generateColors(2);
        }
    }
}
void eraseEnemyTwo()
{
    gotoxy(enemyTwoX, enemyTwoY);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
    gotoxy(enemyTwoX, enemyTwoY + 1);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
    gotoxy(enemyTwoX, enemyTwoY + 2);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
    gotoxy(enemyTwoX, enemyTwoY + 3);
    for (int x = 0; x < 17; x++)
    {
        cout << " ";
    }
}
void printEnemyTwo()
{
    gotoxy(enemyTwoX, enemyTwoY);
    cout << " ____ ____ ____" << endl;
    gotoxy(enemyTwoX, enemyTwoY + 1);
    cout << "|____|____|____|" << endl;
    gotoxy(enemyTwoX, enemyTwoY + 2);
    cout << "|____|____|____|" << endl;
    gotoxy(enemyTwoX, enemyTwoY + 3);
    cout << " 0  0      0  0" << endl;
}
void checkMaze()
{
    int check = enemyOneHeal;
    int check2 = enemyTwoHeal;
    int check3 = enemyThreeHeal;
    int checkFour = enemyFourHeal;
    int checkFive = enemyFiveHeal;
    if (check >= 100)
    {
        gotoxy(0, 28);
        borderLineOne();
        check++;
    }
    if (check2 >= 120)
    {
        gotoxy(0, 21);
        borderLineOne();
        check2++;
    }
    if (check3 >= 130)
    {
        gotoxy(0, 14);
        borderLineOne();
        check3++;
    }
    if (checkFour >= 135)
    {
        gotoxy(0, 7);
        borderLineOne();
        checkFour++;
    }
    if (checkFive >= 150)
    {
        checkFive++;
    }
}
void checkEnemyOneHealth()
{
    if (enemyOneHeal == 100)
    {
        eraseEnemyOne();
        moveEnemy1 = false;
    }
}
void borderLineOne()
{
    generateColors(8);
    cout << "#------>            <-----------------------------------------------------------------------------------------#" << endl;
    generateColors(2);
}
void eraseEnemyOne()
{
    gotoxy(enemyOneX, enemyOneY);
    for (int x = 0; x < 9; x++)
    {
        cout << " ";
    }
    gotoxy(enemyOneX, enemyOneY + 1);
    for (int x = 0; x < 9; x++)
    {
        cout << " ";
    }
    gotoxy(enemyOneX, enemyOneY + 2);
    for (int x = 0; x < 9; x++)
    {
        cout << " ";
    }
    gotoxy(enemyOneX, enemyOneY + 3);
    for (int x = 0; x < 9; x++)
    {
        cout << " ";
    }
}
void showLives()
{
    char live = 3;
    gotoxy(livesX, livesY);
    cout << "Lives Remaining: ";
    gotoxy(livesX + 17, livesY);
    generateColors(4);
    for (int x = 0; x < livesCount; x++)
    {
        cout << live;
    }
    generateColors(2);
}
void showEnemyOneHealth()
{
    if (enemyOneHeal <= 100 && enemyOneHeal >= 0)
    {
        gotoxy(enemyHealthX, enemyHealthY);
        cout << "Enemy Health: ";
        char healthBox = 254;
        gotoxy(enemyHealthX + 14, enemyHealthY);
        cout << enemyOneHeal;
    }
}
void reduceEnemyOneHealth()
{
    enemyOneHeal = enemyOneHeal + 1;
}
void bulletCollisionWithEnemyOne()
{
    char next = getCharAtxy(enemyOneX - 1, enemyOneY);
    char next1 = getCharAtxy(enemyOneX - 1, enemyOneY + 1);
    char next2 = getCharAtxy(enemyOneX - 1, enemyOneY + 2);
    char next3 = getCharAtxy(enemyOneX - 1, enemyOneY + 3);
    if (next == '.' || next1 == '.' || next2 == '.' || next3 == '.')
    {
        reduceEnemyOneHealth();
    }
    // for (int x = 0; x < bulletCount; x++)
    // {
    //     if (isBulletActive[x] == true)
    //     {
    //         if (bulletX[x] + 1 == enemyOneX && (bulletY[x] == enemyOneY || bulletY[x] == enemyOneY + 1 || bulletY[x] == enemyOneY + 2 || bulletY[x] == enemyOneY + 3))
    //         {
    //             reduceEnemyOneHealth();
    //         }
    //         if (enemyOneX - 1 == bulletX[x] && enemyOneY + 1 == bulletY[x])
    //         {
    //             reduceEnemyOneHealth();
    //         }
    //     }
    // }
}
void printPlayer()
{
    char head = 254, head2 = 16, box = 219, foot = 124, armLeft = 47, armRight = 92;
    char line1[5] = {' ', ' ', head, ' ', ' '};
    char line2[5] = {armLeft, box, box, box, armRight};
    char line3[5] = {' ', foot, ' ', foot, ' '};
    generateColors(3);
    gotoxy(playerX, playerY);
    for (int index = 0; index < 5; index++)
    {
        cout << line1[index];
    }
    cout << endl;
    gotoxy(playerX, playerY + 1);
    for (int index = 0; index < 5; index++)
    {
        cout << line2[index];
    }
    cout << endl;
    gotoxy(playerX, playerY + 2);
    for (int index = 0; index < 5; index++)
    {
        cout << line3[index];
    }
    generateColors(6);
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void printMaze()
{
    string maze[36][112] = {{"###############################################################################################################"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#-------------------------------------------------------------------------------------------------------------#"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#-------------------------------------------------------------------------------------------------------------#"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#-------------------------------------------------------------------------------------------------------------#"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#-------------------------------------------------------------------------------------------------------------#"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"#                                                                                                             #"},
                            {"###############################################################################################################"}};
    for (int row = 0; row < 36; row++)
    {
        for (int column = 0; column < 112; column++)
        {
            cout << maze[row][column];
        }
        cout << endl;
    }
}
void clearScreen()
{
    system("cls");
}
void movePlayerRight()
{
    char next = getCharAtxy(playerX + 5, playerY);
    if (next == ' ')
    {
        erasePlayer();
        playerX = playerX + 1;
        gotoxy(playerX, playerY);
        printPlayer();
        Sleep(100);
    }
}
void movePlayerLeft()
{
    char next = getCharAtxy(playerX - 1, playerY);
    if (next == ' ')
    {
        erasePlayer();
        playerX = playerX - 1;
        gotoxy(playerX, playerY);
        printPlayer();
        Sleep(100);
    }
}
void movePlayerUp()
{
    char next = getCharAtxy(playerX, playerY - 1);
    if (next == ' ')
    {
        erasePlayer();
        playerY = playerY - 1;
        gotoxy(playerX, playerY);
        printPlayer();
        Sleep(100);
    }
}
void movePlayerDown()
{
    char next = getCharAtxy(playerX, playerY + 3);
    if (next == ' ')
    {
        erasePlayer();
        playerY = playerY + 1;
        gotoxy(playerX, playerY);
        printPlayer();
        Sleep(100);
    }
}
void generateBullet()
{
    bulletX[bulletCount] = playerX + 5;
    bulletY[bulletCount] = playerY + 1;
    isBulletActive[bulletCount] = true;
    gotoxy(playerX + 5, playerY + 1);
    cout << ".";
    bulletCount++;
}
void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
            }
            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x] += 1;
                printBullet(bulletX[x], bulletY[x]);
            }
        }
    }
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBulletInactive(int index)
{
    isBulletActive[index] = false;
}
void printEnemyOne()
{
    gotoxy(enemyOneX, enemyOneY);
    char line[9] = {' ', ' ', '_', '_', ' ', '_', '_', ' ', ' '};
    char line1[9] = {' ', '|', '_', '_', '|', '_', '_', '|', ' '};
    char line2[9] = {'(', '_', '_', '_', '|', '_', '_', '_', ')'};
    char line3[9] = {' ', '0', ' ', ' ', ' ', ' ', ' ', '0', ' '};
    for (int x = 0; x < 9; x++)
    {
        cout << line[x];
    }
    cout << endl;
    gotoxy(enemyOneX, enemyOneY + 1);
    for (int x = 0; x < 9; x++)
    {
        cout << line1[x];
    }
    cout << endl;
    gotoxy(enemyOneX, enemyOneY + 2);
    for (int x = 0; x < 9; x++)
    {
        cout << line2[x];
    }
    cout << endl;
    gotoxy(enemyOneX, enemyOneY + 3);
    for (int x = 0; x < 9; x++)
    {
        cout << line3[x];
    }
}
void moveEnemyOne()
{
    if (moveEnemy1 == true)
    {
        generateColors(4);
        gotoxy(enemyOneX, enemyOneY);
        char next = getCharAtxy(enemyOneX - 1, enemyOneY);
        if (next == ' ' || next == '.')
        {
            eraseEnemyOne();
            enemyOneX = enemyOneX - 1;
            gotoxy(enemyOneX, enemyOneY);
            printEnemyOne();
        }
        if (next == '#')
        {
            eraseEnemyOne();
            enemyOneX = 100;
            enemyOneY = 30;
        }
        generateColors(2);
    }
}
void erasePlayer()
{
    gotoxy(playerX, playerY);
    for (int x = 0; x < 5; x++)
    {
        cout << " ";
    }
    gotoxy(playerX, playerY + 1);
    for (int x = 0; x < 5; x++)
    {
        cout << " ";
    }
    gotoxy(playerX, playerY + 2);
    for (int x = 0; x < 5; x++)
    {
        cout << " ";
    }
}