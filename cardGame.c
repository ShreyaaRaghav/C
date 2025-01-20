// make a prgram of card game, generate 100 random cards  to 5 players and then print the winner    
/* 1) generate rand 100 times b/w 1 - 13
2) distribute 20 x 5
4) Find the largest
5) print all and winner
*/
/* card[CARDS] to store all generated cards, max, winner, player_cards[PLAYERS][CARDS_PER] for player number and card number */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CARDS 100
#define PLAYERS 5
#define CARDS_PER 20

void generate(int card[], int num_cards) {
    for(int i = 0; i < num_cards; i++) {
        card[i] = (rand() % 13) + 1;
    }
}

void distribute(int card[], int num_cards, int cards_per_player, int num_players, int player_cards[][CARDS_PER]) {
    int index = 0;
    for(int i = 0; i < num_players; i++) {
        for(int j = 0; j < cards_per_player; j++) {
            player_cards[i][j] = card[index++];
        }
    }
}

void find_winner(int player_cards[][CARDS_PER], int num_players, int cards_per_player) {
    int max = 0, winner = 0;
    for(int i = 0; i < num_players; i++) {
        for(int j = 0; j < cards_per_player; j++) {
            if (player_cards[i][j] > max) {
                max = player_cards[i][j];
                winner = i;
            }
        }
    }
 printf("Winner: Player %d\n", winner + 1);
}

int main() {
    int card[CARDS], player_cards[PLAYERS][CARDS_PER];
   
    srand(time(0));
    generate(card, CARDS);
    distribute(card, CARDS, CARDS_PER, PLAYERS, player_cards);

    printf("The cards are distributed as:\n");
    for(int i = 0; i < PLAYERS; i++) {
        printf("[%d] person: ", i + 1);
        for(int j = 0; j < CARDS_PER; j++) {
            printf("%d ", player_cards[i][j]);
        }
        printf("\n");
    }
    
find_winner(player_cards, PLAYERS, CARDS_PER);
    return 0;
}
