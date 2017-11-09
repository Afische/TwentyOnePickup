// TwentyOnePickup.java
# include <stdio.h>
  /**
  * Play the game of Twenty-One Pickup. 
  * The user and the computer take turns removing
  * from 1 to 3 stones from a pile. There are 21
  * stones in the pile to start with. 
  * The last one to remove a stone wins.
  */
  int main(void) {
    printInstructions();
    // create the initial pile with 21 stones
    int numberOfStones = 21;
    // keep track of who moved last
    int playerMovedLast = 0;
    while (numberOfStones > 0) {
      numberOfStones = playerMove(numberOfStones);
      playerMovedLast = 1;
      if (numberOfStones > 0){
        numberOfStones = computerMove(numberOfStones);
        playerMovedLast = 0;
      }
    }
    // print the outcome
    if (playerMovedLast)
      printf("Congratulations, you won.\n");
    else
      printf("Better luck next time.\n");
  }
  /**
  * printInstructions prints the initial instructions
  */
  int printInstructions(void) {
    printf("The object of this game is to remove the last stone.\n"
      "There are 21 stones in the pile to start with.\n"
      "You may remove from 1 to 3 stones on each move.\n"
      "Good Luck!\n");
  }
  /**
  * playerMove completes one move by the player.
  * @param numberOfStones 
  *     The number of stones reamining in the pile.
  * @return 
  *    The number of stones remaining after the user's move.
  */
  int playerMove(int numberOfStones) {
    int move = getUserMove(numberOfStones);
    numberOfStones = numberOfStones - move;
    printf("There are %d stones remaining.\n", numberOfStones);
    return numberOfStones;
  }
  /**
  * computerMove completes one move by the computer.
  * @param numberOfStones 
  *    The number of stones reamining in the pile.
  * @return 
  *    The numberOfStones remaining after the
  *    computer's move.
  */
  int computerMove(int numberOfStones) {
    int move;
    if (numberOfStones <= 3) {
      move = numberOfStones; /* remove the rest */
    }
    else {
      move = numberOfStones % 4;
      if (move == 0) move = 1;
    }
    numberOfStones = numberOfStones - move;
    printf("The computer removes %d stones leaving %d.\n", move,
     numberOfStones);
    return numberOfStones;
  }
  /**
  * getUserMove reads in the user's move, only
  *    accepting legal inputs.
  * @param numberOfStones 
  *    The number of stones reamining in the pile.
  * @return 
  *    The number of stones selected for removal by
  *    the user.
  */
  int getUserMove(int numberOfStones) {
    printf("Your move - how many stones do you wish to remove?\n");
    int move;
    scanf("%d", &move);
    while (move > numberOfStones || move < 1 || move > 3) {
      if (numberOfStones >= 3)
        printf("Sorry, you can only remove 1 to 3 stones.\n");
      else
        printf("Sorry, you can only remove 1 to %d stones.\n", 
          numberOfStones);
      printf("How many stones do you wish to remove?\n");
      scanf("%d", &move);
    }
    return move;
  }
  

