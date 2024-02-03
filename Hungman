#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MISTAKES 6

void draw_hangman(int mistakes) {
  printf("  ______\n");
  printf("  |     |\n");
  if (mistakes > 0) {
    printf("  O     |\n");
  } else {
    printf("        |\n");
  }
  if (mistakes > 3) {
    printf(" /|\\    |\n");
  } else if (mistakes > 2) {
    printf(" /|     |\n");
  } else if (mistakes > 1) {
    printf("  |     |\n");
  } else {
    printf("        |\n");
  }
  if (mistakes > 5) {
    printf(" / \\    |\n");
  } else if (mistakes > 4) {
    printf(" /      |\n");
  } else {
    printf("        |\n");
  }
  printf("=========\n");
}

int main(void) {
  char word[100];
  printf("Enter a word: ");
  scanf("%s", word);
  int word_length = strlen(word);

  char guess[100];
  for (int i = 0; i < word_length; i++) {
    guess[i] = '_';
  }
  guess[word_length] = '\0';

  int mistakes = 0;
  while (mistakes < MAX_MISTAKES) {
    draw_hangman(mistakes);
    printf("Word: %s\n", guess);
    printf("Enter a letter: ");
    char letter;
    scanf(" %c", &letter);
    int found = 0;
    for (int i = 0; i < word_length; i++) {
      if (tolower(word[i]) == tolower(letter)) {
        guess[i] = word[i];
        found = 1;
      }
    }
    if (found==0) {
      mistakes++;
    }
    if (strcmp(word, guess) == 0) {
      printf("You win!\n");
      break;
    }
  }
  if (mistakes == MAX_MISTAKES) {
    draw_hangman(mistakes);
    printf("You lose! The word was %s\n", word);
  }

  return 0;
}
