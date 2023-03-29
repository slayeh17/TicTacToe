#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void boardInit(int n, char board[n][n]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(int n, char board[n][n]) {
    for(int i=0; i<n; i++)
    printf("  %d",i);
    printf("\n");
    for(int i=0; i<n; i++) {
        printf("%d",i);
        for(int j=0; j<n; j++) {
            printf("|%c|",board[i][j]);
        }
        printf("\n");
    }
}

bool checkWinner(int n, char board[n][n], int P) {
    //column-wise
    int count=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[j][i] == P)
            count++;
        }
        if(count==3)
        return true;
        else
        count=0;
    }

    //row-wise
    count=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == P)
            count++;
        }
        if(count==3)
        return true;
        else
        count=0;
    }

    //diagonal-wise
    count=0;
    for(int i=0; i<n; i++) {
        if(board[i][i] == P)
        count++;
    }
    if(count==3)
    return true;

    count=0;
    for(int i=n-1; i>=0; i--) {
        if(board[i][n-i-1] == P)
        count++;
    }
    if(count==3)
    return true;

    return false;
}

// void play(int n, char board[n][n], char P)

void playGame(int n, char board[n][n], char P1, char P2) {
    int x, y, countP1=0, countP2=0;
    bool p1Play, p2Play;
    while(true) {
        p1Play=true, p2Play=true;
        while(p1Play) {
            printf("P1: Enter the coordinates: ");
            scanf("%d%d",&x,&y);
            if(board[x][y]==' ') {
                p1Play=false;
                board[x][y] = P1;
                printBoard(n, board);
                countP1++;
                if(checkWinner(n, board, P1)) {
                    printf("P1 won the game!");
                    return;
                }
            }
            else {
            printf("Invalid Input!\n");
            p1Play=true;
            }
        }  
        if((countP1+countP2) == n*n) {
            printf("--------The Game Is A Tie--------");
            return;
        } 
        while(p2Play) {
            printf("P2: Enter the coordinates: ");
            scanf("%d%d",&x,&y);
            if(board[x][y]==' ') {
                p2Play=false;
                board[x][y] = P2;
                printBoard(n, board);
                countP2++;
                if(checkWinner(n, board, P2)) {
                    printf("P2 won the game!");
                    return;
                }
            }
            else {
            printf("Invalid Input!\n");
            p2Play=true;
            }
        }   
        if((countP1+countP2) == n*n) {
            printf("--------The Game Is A Tie--------");
            return;
        }
    }
}

int main() {
    char P1, P2;
    printf("Enter the symbol for P1: ");
    scanf(" %c",&P1);
    printf("Enter the symbol for P2: ");
    scanf(" %c",&P2);
    printf("\n\n");

    char board[3][3];
    boardInit(3, board);
    printBoard(3, board);
    playGame(3, board, P1, P2);
}
