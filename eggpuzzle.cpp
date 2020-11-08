
#include <iostream>
using namespace std;

/* Function prototypes */
void printPuzzle(int state);
int missingTile(int state);
bool isMoveValid(int state, char dir);
void moveMissingTile(int& state, char dir);
int randGenPuzzle();
int inversion(int puzzle);

/* Prints the puzzle state to the screen. */
void printPuzzle(int state) {
    int i = 0;
    int p = state;
    int rev = 0;
    while (p != 0) {
        rev = rev * 10 + p % 10;
        p /= 10;
    }
    if (state < 100000000) {
        cout << ". ";
        for(int i =0; i< 8; i++){
            cout << (rev % 10) << " ";
            rev /= 10;
            if (i == 1 || i == 4 || i == 7){
                cout << "\n";
            }
        }
    }
    else {
        for (i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (rev % 10 == 0) {
                    cout << ". ";
                    rev /= 10;
                }
                else {
                    cout << (rev % 10) << " ";
                    rev /= 10;
                }
            }
            cout << "\n";
        }
    }
}

/* Returns the position of the missing tile in the puzzle state. */
int missingTile(int state) {
    int p = state;
    for (int i = 9; i >0; i--) {
        //cout << (p % 10);
        if (p % 10 == 0) {
            return i;
        }
        p /= 10;
    }
    return 0;
}

/* Returns true if the missing tile in the puzzle state can move towards the
   direction dir; returns false otherwise. */
bool isMoveValid(int state, char dir) {
    char move = dir;
    int p = state;
    int miss = missingTile(p);
    if(miss == 1){
        if (move == 'u' || move == 'l') {
            return false;
        }
    }
    else if (miss == 3) {
        if (move == 'u' || move == 'r') {
            return false;
        }
    }
    else if (miss == 7) {
        if (move == 'd' || move == 'l') {
            return false;
        }
    }
    else if (miss == 9) {
        if (move == 'd' || move == 'r') {
            return false;
        }
    }
    else if (miss == 2) {
        if (move == 'u') {
            return false;
        }
    }
    else if (miss == 4) {
        if (move == 'l') {
            return false;
        }
    }
    else if (miss == 6) {
        if (move == 'r') {
            return false;
        }
    }
    else if (miss == 8) {
        if (move == 'd') {
            return false;
        }
    }
    return true;
}

/* Moves the missing tile in the puzzle state towards the direction dir. */
void moveMissingTile(int& state, char dir) {
    int p = state;
    //cout << "p:" << p << endl;
    int move = dir;
    int miss = missingTile(p);
    int index = 0;
    int org = 1;
    int change = 1;
    int mod = 0;
    bool moveOk = isMoveValid(p, move);
    if (moveOk) {
        if (move == 'u') {
            index = 9 - (miss - 3) + 1;
            for (int i = 0; i < index; i++) {
                mod = p % 10;
                p /= 10;
            }
            //cout << mod << endl;
            for (int i = 9; i > (miss); i--) {
                org = org * 10;
            }
            org *= mod;
            //cout << "m:" << miss << endl;
            //cout << org << endl;
            for (int i = 9; i > 9 - (index - 1); i--) {
                change = change * 10;
            }
            change *= mod;
            //cout << "c:" << change << endl;
            state = (state - change + org);
            //cout << "s:" << state << endl;
            printPuzzle(state);
        }
        else if (move == 'd') {
            index = 9 - (miss + 3) + 1;
            for (int i = 0; i < index; i++) {
                mod = p % 10;
                p /= 10;
            }
            //cout << mod << endl;
            for (int i = 9; i > (miss); i--) {
                org = org * 10;
            }
            org *= mod;
            //cout << "m:" << miss << endl;
            //cout << org << endl;
            for (int i = 9; i > 9 - (index - 1); i--) {
                change = change * 10;
            }
            change *= mod;
            //cout << "c:" << change << endl;
            state = (state - change + org);
            //cout << "s:" << state << endl;
            printPuzzle(state);
        }
        else if (move == 'l') {
            index = 9 - (miss - 1) + 1;
            for (int i = 0; i < index; i++) {
                mod = p % 10;
                p /= 10;
            }
            //cout << mod << endl;
            for (int i = 9; i > (miss); i--) {
                org = org * 10;
            }
            org *= mod;
            //cout << "m:" << miss << endl;
            //cout << org << endl;
            for (int i = 9; i > 9 - (index - 1); i--) {
                change = change * 10;
            }
            change *= mod;
            //cout << "c:" << change << endl;
            state = (state - change + org);
            //cout << "s:" << state << endl;
            printPuzzle(state);
        }
        else {
            index = 9 - (miss + 1) + 1;
            for (int i = 0; i < index; i++) {
                mod = p % 10;
                p /= 10;
            }
            //cout << mod << endl;
            for (int i = 9; i > (miss); i--) {
                org = org * 10;
            }
            org *= mod;
            //cout << "m:" << miss << endl;
            //cout << org << endl;
            for (int i = 9; i > 9 - (index - 1); i--) {
                change = change * 10;
            }
            change *= mod;
            //cout << "c:" << change << endl;
            state = (state - change + org);
            //cout << "s:" << state << endl;
            printPuzzle(state);
        }
    }
    else {
        cout << "Invalid move. Try again!" << endl;
    }
}

/* Returns a solvable randomly generated 8-puzzle. Do NOT modify! */
int randGenPuzzle() {
    int mask, p, divp, s, divm, j, inv;
    do {
        mask = 0;
        p = 0;
        divp = 1;
        while (mask != 111111111) {
            s = rand() % 9;
            divm = 1;
            for (j = 1; j <= s; j++)
                divm *= 10;
            if (mask / divm % 10 == 0) {
                p += s * divp;
                mask += divm;
                divp *= 10;
            }
        }
        inv = inversion(p);
    } while (inv % 2 != 0);
    return p;
}

/* Returns the number of inversions of the puzzle state. */
int inversion(int state) {
    int rev = 0;
    int p = state;
    int d1, d2;
    int  count = 0;
    int times = 10;
    for (int i =1; i <= 9; i++) {
        int p1 = state / times;
        d1 = p % 10;
        p /= 10;
        //cout << "d1 " << d1<<endl;
        if (d1 == 0) {
            continue;
        }
        for (int j=i+1; j <=9; j++) {
            p1 /= 10;
            d2 = p1 % 10;
            //cout <<"d2 " <<d2 << endl;
            if (d2 == 0) {
                continue;
            }
            if (d2 > d1) {
                count++;
                //cout << "count  " << count<<endl;
            }
        }
        times *= 10;
    }
    
    return count;
}

int main() {
    int seed= 0;
    char dir;
    cout << "Seed: ";
    cin >> seed;
    srand(seed);
    int puzzle = randGenPuzzle();
    printPuzzle(puzzle);
    int miss = missingTile(puzzle);
    int times = 0;
    while (times <= 100) {
        cout << "Make a move [udlr]: ";
        cin >> dir;
        moveMissingTile(puzzle, dir);
        times++;
        if (puzzle == 123456780) {
            if (times <= 30) {
                cout << "Well done!" << endl;
                return 0;
            }
            else if (times > 30 && times <= 100) {
                cout << "Good enough!" << endl;
                return 0;
            }
        }
        if (times == 100) {
            cout << "Too bad!" << endl;
            return 0;
        }
    }
    //cout << "p:" << puzzle << endl;
    return 0;
}
