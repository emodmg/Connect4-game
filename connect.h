#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// game_state() returns 'X' or 'O' when player X won or 
// player O won respectively, returns NO_SPACE when the game
// ends in a draw, returns SPACE_AVAIL if the game still
// continues.
// effects: produce output.
char game_state(void);

// print_board() prints the game board.
// effects: produce output.
void print_board(void);

// move(drop_row_num, slot_num) places a 'X'or 'O' piece at 
// the designated spot.
// effects: may modify global variables slot0, slot1, slot2, 
// slot3 slot4, slot5, slot6.
void move(int, int);

// read_move() returns true if the move is read and valid,
// false otherwise.
// effects: produce output.
//          reads input.
//          may modify global variables.
bool read_move(void);



// global variables
////////////////////////////

// char slot0, slot1 ... slot6 represent the 7 slots
// on the game board.
extern char slot0[6];
extern char slot1[6];
extern char slot2[6];
extern char slot3[6];
extern char slot4[6];
extern char slot5[6];
extern char slot6[6];

// SLOT_0... const int SLOT6 represents 
// the slot number of each slot, providing index.
extern const int SLOT_0;
extern const int SLOT_1;
extern const int SLOT_2;
extern const int SLOT_3;
extern const int SLOT_4;
extern const int SLOT_5;
extern const int SLOT_6;

// ROW_0, ROW_5 represents the row number 
// of row0 and row5, providing index.
extern const int ROW_0;
extern const int ROW_5;

// X_PIECE and const char O_PIECE represent
// of char of the players' chess piece.
extern const char X_PIECE;
extern const char O_PIECE;

// NO_FOUR_SAME represents that there are 
// no four same characters in current slot, row, or 
// diagonal line.
extern const char NO_FOUR_SAME;

// SPACE_AVAIL represents there are still 
// avaibable space on the board for the game to continue;
extern const char SPACE_AVAIL;


// NO_SPACE represents there are not  
// avaibable space on the board for the game to continue;
extern const char NO_SPACE;


// player represents the current player's character
extern char player;


// slot represents the current slot's index
extern int slot;


// drop_row represents the row number that the piece
// will be dropped to.
extern int drop_row;

