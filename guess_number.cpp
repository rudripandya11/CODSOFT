#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    int secretNumber = rand() % 100 + 1;

    int guess;
    do {
       
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;

    
        if (guess == secretNumber) {
            cout << "Congratulations You guessed the number.\n";
        }
     
        else if (guess > secretNumber) {
            cout << "Your guess is too high. Try again.\n";
        }
       
        else {
            cout << "Your guess is too low. Try again.\n";
        }
    } while (guess != secretNumber);

    return 0;
}