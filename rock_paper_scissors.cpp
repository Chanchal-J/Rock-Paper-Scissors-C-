# include <iostream>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>

# define STONE 1
# define PAPER 2
# define SCISSOR 3
# define ONE_SECOND 1

using namespace std ;

// Function to randomly choose computer's move.
int getRandomChoice () {
    return rand() % 3 + 1;
}

// Function to convert the choice into string form.
const char* toString( int choice ) {
    switch( choice ) {
        case STONE: return "Stone";
        case PAPER: return "Paper";
        case SCISSOR: return "Scissor";
        default: return "";
    }
}

// Function to check if the user has won. It returns 1, if 'u' has won,
// and returns 0 otherwise.
int checkResult( int u, int c ) {
    if( ( u == STONE && c == SCISSOR ) ||
    ( u == PAPER && c == STONE ) ||
    ( u == SCISSOR && c == PAPER ) )
        return 1;
    return 0;
}

// Main function of the code.
int main(){

    int playerScore = 0 ,computerScore = 0;
    int playerChoice, computerChoice, round = 1;

    system( "CLS" );
    // Initialize the random function seed.
    srand(time(0));

    // Loop continuously untill the user chooses to exit.
    while(true) {
    
        cout << "\n\n\n\t\t\tROUND " << round << "\n\n";
        cout << "Enter your choice:\n 1 - Stone\n 2 - Paper\n 3 - Scissors\n 4 - Quit\n";
        cout << "\nYour choice : " ;
        cin >> playerChoice ;
        if( playerChoice == 4 ) {
            // Exit Game
            break;
        }

        if( toString( playerChoice ) == "" ) {
            // Invalid Choice
            cout << "\n\nInvalid Choice. Please enter a correct choice.\n";
            sleep( ONE_SECOND );
            continue;
        }


        round++;
        cout << "\n\n  Player's Choice : " << toString( playerChoice );
        sleep( ONE_SECOND );
    
        computerChoice = getRandomChoice() ;
        cout << "\nComputer's Choice : " << toString( computerChoice );
        sleep( ONE_SECOND );

        if( checkResult( playerChoice, computerChoice ) ) {
            playerScore += 1;
            cout << "\n\n\t\t PLAYER WINS\n";
        } else if( checkResult( computerChoice, playerChoice ) ) {
            computerScore += 1;
            cout << "\n\n\t\t COMPUTER WINS\n";
        } else {
            cout << "\n\n\t\t MATCH TIES";
        }
        sleep( ONE_SECOND );
    }

    // Display the final score and the winner.
    system( "CLS" );
    cout << "\n\nFinal Result after " << round-1 << " rounds\n\n";
    sleep( ONE_SECOND );
    if(playerScore > computerScore) {
        cout << "\n\nYou won the match !!";
    }
    else if(computerScore > playerScore) {
        cout << "\n\nComputer won the match !!" ;
    }
    else {
        cout << "\n\nIt is a Tie " ;
    }

    cout << "\n\nComputer's score : "<< computerScore ;
    cout << "\n  Player's score : " << playerScore ;
    cout << "\n\n";

    return 0;

}

