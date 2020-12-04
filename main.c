#include "connect.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void) {
  print_board();
  while (true) {
    if (read_move()) {
       move(drop_row, slot);
    } else {
      break;
    }
    print_board();
    if (game_state() == SPACE_AVAIL) {
      continue;
    } else {
      break;
    }
  }
  return EXIT_SUCCESS;
}
