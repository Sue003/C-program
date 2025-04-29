
#include<stdio.h>
// this function will print the grid 

void print(char point[]) {
    printf("%c|%c|%c\n", point[0], point[1], point[2]);
    printf("- - -\n");
    printf("%c|%c|%c\n", point[3], point[4], point[5]);
    printf("- - -\n");
    printf("%c|%c|%c\n", point[6], point[7], point[8]);
    return;
}

int main() {
//this part will print spaces as characters in the grid
    char point[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    print(point);
    char psign1, psign2;

    while (1) {
//Here both players will chose there sign they want to play with

        printf("Enter the sign of the first player example: x \n");
        scanf(" %c", &psign1);
        printf("Enter the sign of the second player example: o \n");
        scanf(" %c", &psign2);

        if (psign1 == psign2) {
            printf("Enter a valid character\n");
        } else {
            break;
        }
    }

    char p1, p2;
    int d = 0;
    int i = 1;

    while (i < 10) {
//Chosing the box they want to check 

        if (i % 2 == 1) {
            re:
            printf("Enter the box of the first player \n");
            scanf(" %c", &p1);
            if (point[p1 - 'a'] == ' ') {
                point[p1 - 'a'] = psign1;
                i++;
                print(point);
            } else {
                printf("Invalid box\n");
                goto re;
            }
// checking if the player is wining

            if ((point[0] == point[1] && point[1] == point[2] && point[0] == psign1) ||
                (point[2] == point[4] && point[4] == point[6] && point[2] == psign1)) {
                d = 1;
                printf("First player wins !");
                break;
            }

        } else {
            printf("Enter the box of the second player\n");
            scanf(" %c", &p2);
            if (point[p2 - 'a'] == ' ') {
                point[p2 - 'a'] = psign2;
                i++;
                print(point);
            } else {
                printf("Invalid box\n");
                continue;
            }
// same as the first player
            if ((point[0] == point[1] && point[1] == point[2] && point[0] == psign2) ||
                //... (other win conditions)
                (point[2] == point[4] && point[4] == point[6] && point[2] == psign2)) {
                printf("Second player wins !");
                d = 1;
                break;
            }
        }
    }
//end of the loop checking if there is a draw
    if (d == 0) {
        printf("It's a draw !");
    }

    return 0;
}



