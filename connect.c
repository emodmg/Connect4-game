#include "connect.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// global variables
//////////////////////////
// char slot0, slot1 ... slot6 represent the 7 slots
// on the game board.
char slot0[6]={0,0,0,0,0,0};
char slot1[6]={0,0,0,0,0,0};
char slot2[6]={0,0,0,0,0,0};
char slot3[6]={0,0,0,0,0,0};
char slot4[6]={0,0,0,0,0,0};
char slot5[6]={0,0,0,0,0,0};
char slot6[6]={0,0,0,0,0,0};

// const int SLOT_0... const int SLOT6 represents 
// the slot number of each slot, providing index.
const int SLOT_0 = 0;
const int SLOT_1 = 1;
const int SLOT_2 = 2;
const int SLOT_3 = 3;
const int SLOT_4 = 4;
const int SLOT_5 = 5;
const int SLOT_6 = 6;

// const int ROW_0, ROW_5 represents the row number 
// of row0 and row5, providing index.
const int ROW_0 = 0;
const int ROW_5 = 5;

// const char X_PIECE and const char O_PIECE represent
// of char of the players' chess piece.
const char X_PIECE = 'X';
const char O_PIECE = 'O';

// const char NO_FOUR_SAME represents that there are 
// no four same characters in current slot, row, or 
// diagonal line.
const char NO_FOUR_SAME = 'N';

// const char SPACE_AVAIL represents there are still 
// avaibable space on the board for the game to continue;
const char SPACE_AVAIL = 'A';

// const char NO_SPACE represents there are not  
// avaibable space on the board for the game to continue;
const char NO_SPACE = 'B';

// char player represents the current player's character
char player = 0;

// int slot represents the current slot's index
int slot = 0;

// int drop_row represents the row number that the piece
// will be dropped to.
int drop_row = 0;


//helper functions
///////////////////////////////////////////////////////////

// still_space() return true if there is space on the board
// false otherwise.
bool still_space(void) {
  for (int i = ROW_0; i <= ROW_5; i += 1) {
    if (slot0[i] == 0) {
      return true;
    } else if (slot1[i] == 0) {
      return true;
    } else if (slot2[i] == 0) {
      return true;
    } else if (slot3[i] == 0) {
      return true;
    } else if (slot4[i] == 0) {
      return true;
    } else if (slot5[i] == 0) {
      return true;
    } else if (slot6[i] == 0) {
      return true;
    } else {
      continue;
    }
  }
  return false;
}

// can_drop_piece(slot_num) returns true if the given
// slot still has space. false otherwise.
// requires: slot_num must be between 1 and 6 
// (both inclusive).
// effects: may modify global variable drop_row.
bool can_drop_piece(int slot_num) {
  if (slot_num == SLOT_0) {
    for (int i = ROW_0; i <= ROW_5; i += 1) {
      if (slot0[i] == 0) {
        drop_row = i;
        return true;
      }
    }
    return false;
  } else if (slot_num == SLOT_1) {
    for (int i = ROW_0; i <= ROW_5; i += 1) {
      if (slot1[i] == 0) {
        drop_row = i;
        return true;
      }
    }
    return false;
  } else if (slot_num == SLOT_2) {
    for(int i = ROW_0; i <= ROW_5; i += 1) {
      if (slot2[i] == 0) {
        drop_row = i;
        return true;
      }
    }
    return false;
  } else if (slot_num == SLOT_3) {
    for (int i = ROW_0; i <= ROW_5; i += 1) {
      if (slot3[i] == 0) {
        drop_row = i;
        return true;
      }
    }
    return false;
  } else if (slot_num == SLOT_4) {
    for (int i = ROW_0; i <= ROW_5; i += 1) {
      if (slot4[i] == 0) {
        drop_row = i;
        return true;
      }
    }
    return false;
  } else if (slot_num == SLOT_5) {
    for (int i = ROW_0; i <= ROW_5; i += 1) {
      if (slot5[i] == 0) {
        drop_row = i;
        return true;
      }
    }
    return false;
  } else {
    for (int i = ROW_0; i <= ROW_5; i += 1) {
      if (slot6[i] == 0) {
        drop_row = i;
        return true;
      }
    }
    return false;
  }
}

// what_four_vertical_helper(slot) returns the charater if 
// there are four or more this character straight in the 
// given slot, returns NO_FOUR_SAME otherwise.
// requires: slot must not be a NULL pointer.
char what_four_vertical_helper(const char *slot) {
  assert(slot);
  if (((slot)[0] == (slot)[1]) && 
      ((slot)[1] == (slot)[2]) && 
      ((slot)[2] == (slot)[3])) {
    return (slot)[0];
  } else if (((slot)[1] == (slot)[2]) &&
             ((slot)[2] == (slot)[3]) &&
             ((slot)[3] == (slot)[4])) {
    return (slot)[1];
  } else if (((slot)[2] == (slot)[3]) &&
             ((slot)[3] == (slot)[4]) &&
             ((slot)[4] == (slot)[5])) {
    return (slot)[2];
  } else {
    return NO_FOUR_SAME;
  }
}

// what_four_vertical() returns the charater 'X' if 
// there are four or more 'X' straight in a slot, 'O' if 
// there are four or more 'O' straight in a slot, returns 
// NO_FOUR_SAME otherwise.
char what_four_vertical(void) {
  if ((what_four_vertical_helper(slot0) == 'X') ||
      (what_four_vertical_helper(slot1) == 'X') ||
      (what_four_vertical_helper(slot2) == 'X') || 
      (what_four_vertical_helper(slot3) == 'X') ||
      (what_four_vertical_helper(slot4) == 'X') ||
      (what_four_vertical_helper(slot5) == 'X') || 
      (what_four_vertical_helper(slot6) == 'X')) {
    return 'X';
  } else if ((what_four_vertical_helper(slot0) == 'O') ||
             (what_four_vertical_helper(slot1) == 'O') ||
             (what_four_vertical_helper(slot2) == 'O') || 
             (what_four_vertical_helper(slot3) == 'O') ||
             (what_four_vertical_helper(slot4) == 'O') ||
             (what_four_vertical_helper(slot5) == 'O') || 
             (what_four_vertical_helper(slot6) == 'O')) {
    return 'O';
  } else {
    return NO_FOUR_SAME;
  }
}

// what_four_horizontal() returns the charater 'X' if 
// there are four or more 'X' straight in a row, 'O' if 
// there are four or more 'O' straight in a row, returns 
// NO_FOUR_SAME otherwise.
char what_four_horizontal(void) {
  for (int row = ROW_0; row <= ROW_5; row += 1) {
    if ((slot0[row] == slot1[row]) && (slot1[row] == slot2[row]) &&
        (slot2[row] == slot3[row])) {
      return slot0[row];
    } else if ((slot1[row] == slot2[row]) && 
               (slot2[row] == slot3[row]) &&
               (slot3[row] == slot4[row])) {
      return slot1[row];
    } else if ((slot2[row] == slot3[row]) &&
               (slot3[row] == slot4[row]) &&
               (slot4[row] == slot5[row])) {
      return slot2[row];
    } else if ((slot3[row] == slot4[row]) &&
               (slot4[row] == slot5[row]) &&
               (slot5[row] == slot6[row])) {
      return slot3[row];// row test
    } else {
      continue;
    }
  }
  return NO_FOUR_SAME;
}

// what_four_diagonal() returns the charater 'X' if 
// there are four or more 'X' straight in a diagonal line,
// 'O' if there are four or more 'O' straight in a diagonal 
// line, returns NO_FOUR_SAME otherwise.
char what_four_diagonal(void) {
  for (int i = 0; i <=2; i += 1) {
    if ((slot0[i] == slot1[i + 1]) && (slot1[i + 1] == slot2[i + 2]) &&
        (slot2[i + 2] == slot3[i + 3])) {
      return slot0[i];// group 1 left
    } else if ((slot0[i + 3] == slot1[i + 2]) && 
               (slot1[i + 2] == slot2[i + 1]) && (slot2[i + 1] == slot3[i])) {
      return slot3[i];// group 1 right
    } else if ((slot1[i] == slot2[i + 1]) && (slot2[i + 1] == slot3[i + 2]) &&
               (slot3[i + 2] == slot4[i + 3])) {
      return slot1[i];// group 2 left
    } else if ((slot1[i + 3] == slot2[i + 2]) && 
               (slot2[i + 2] == slot3[i + 1]) && (slot3[i + 1] == slot4[i])) {
      return slot4[i];// group 2 right
    } else if ((slot2[i] == slot3[i + 1]) && (slot3[i + 1] == slot4[i + 2]) &&
               (slot4[i + 2] == slot5[i + 3])) {
      return slot2[i];// group 3 left
    } else if ((slot2[i + 3] == slot3[i + 2]) && 
               (slot3[i + 2] == slot4[i + 1]) && (slot4[i + 1] == slot5[i])) {
      return slot5[i];// group 3 right
    } else if ((slot3[i] == slot4[i + 1]) && (slot4[i + 1] == slot5[i + 2]) &&
               (slot5[i + 2] == slot6[i + 3])) {
      return slot3[i];// group 4 left
    } else if ((slot3[i + 3] == slot4[i + 2]) && 
               (slot4[i + 2] == slot5[i + 1]) && (slot5[i + 1] == slot6[i])) {
      return slot6[i];// group 4 right
    } else {
      continue;
    }
  }
  return NO_FOUR_SAME;
}



// major functions
////////////////////////////////////////////////////////////////////

// read_move() returns true if the move is read and valid,
// false otherwise.
// effects: produce output.
//          reads input.
//          may modify global variables.
bool read_move(void) {
  if (scanf(" %c", &player) != 1) {
    printf("ERROR: cannot read player code\n");
    return false;
  } else if (scanf("%d", &slot) != 1) {
    printf("ERROR: cannot read slot number\n");
    return false;
  } else if ((player != X_PIECE) && (player != O_PIECE)) {
    printf("ERROR: invalid player code: %c\n", player);
    return false;
  } else if ((slot < SLOT_0) || (slot > SLOT_6) || (!can_drop_piece(slot))) {
    printf("ERROR: invalid slot number: %d\n", slot);
    return false;
  } else {
    can_drop_piece(slot);
    return true;
  }
}


// move(drop_row_num, slot_num) places a 'X'or 'O' piece at 
// the designated spot.
// effects: may modify global variables slot0, slot1, slot2, 
// slot3 slot4, slot5, slot6.
void move(int drop_row_num, int slot_num) {
  if (slot_num == SLOT_0) {
    slot0[drop_row_num] = player;
  } else if (slot_num == SLOT_1) {
    slot1[drop_row_num] = player;
  } else if (slot_num == SLOT_2) {
    slot2[drop_row_num] = player;
  } else if (slot_num == SLOT_3) {
    slot3[drop_row_num] = player;
  } else if (slot_num == SLOT_4) {
    slot4[drop_row_num] = player;
  } else if (slot_num == SLOT_5) {
    slot5[drop_row_num] = player;
  } else {
    slot6[drop_row_num] = player;
  }
}

// print_board() prints the game board.
// effects: produce output.
void print_board(void) {
  for(int row = ROW_5; row >= ROW_0; row -= 1) {
    for (int column = SLOT_0; column <= SLOT_6; column += 1) {
      printf("|");
      if (column == SLOT_0) {
        if (slot0[row] == 0) {
          printf("_");
        } else {
          printf("%c", slot0[row]);
        }
      } else if (column == SLOT_1) {
        if (slot1[row] == 0) {
          printf("_");
        } else {
          printf("%c", slot1[row]);
        }
      } else if (column == SLOT_2) {
        if (slot2[row] == 0) {
          printf("_");
        } else {
          printf("%c", slot2[row]);
        }
      } else if (column == SLOT_3) {
        if (slot3[row] == 0) {
          printf("_");
        } else {
          printf("%c", slot3[row]);
        }
      } else if (column == SLOT_4) {
        if (slot4[row] == 0) {
          printf("_");
        } else {
          printf("%c", slot4[row]);
        }
      } else if (column == SLOT_5) {
        if (slot5[row] == 0) {
          printf("_");
        } else {
          printf("%c", slot5[row]);
        }
      } else {
        if (slot6[row] == 0) {
          printf("_");
        } else {
          printf("%c", slot6[row]);
        }
      }
    }
    printf("|\n");
  }
  printf(" 0 1 2 3 4 5 6\n\n");
}


// game_state() returns 'X' or 'O' when player X won or 
// player O won respectively, returns NO_SPACE when the game
// ends in a draw, returns SPACE_AVAIL if the game still
// continues.
// effects: produce output.
char game_state(void) {
  char vertical = what_four_vertical();
  char horizontal = what_four_horizontal();
  char diagonal = what_four_diagonal();
  if ((vertical == X_PIECE) || (vertical == O_PIECE)) {
    printf("Victory! Player %c has won!\n", vertical);
    return vertical;
  } else if ((horizontal == X_PIECE) || 
             (horizontal == O_PIECE)) {
    printf("Victory! Player %c has won!\n", horizontal);
    return horizontal;
  } else if ((diagonal == X_PIECE) ||
             (diagonal == O_PIECE)) {
    printf("Victory! Player %c has won!\n", diagonal);
    return diagonal;
  } else if (!still_space()) {
    printf("Draw! No player has won!\n");
    return NO_SPACE;
  } else {
    return SPACE_AVAIL;// continue game;
  }
}




