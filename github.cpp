#include <iostream>
#include <string>

using namespace std;

// Lab 1: Classes and Objects
class GamePlayer {
private:
    string player_name;
    int birth_year;
    string country;

public:
    // Lab 4: Parameterized Constructor
    GamePlayer(string name, int year, string player_country) {
        player_name = name;
        birth_year = year;
        country = player_country;
    }

    void displayDetails() {
        cout << "Player: " << player_name << endl;
        cout << "Year of Birth: " << birth_year << endl;
        cout << "Country: " << country << endl;
    }
};

// Lab 2: Default Arguments
class Player {
private:
    string name;
    string team;
    int rank;

public:
    void registerPlayer(string player_name, string player_team = "Unassigned", int player_rank = 1000) {
        name = player_name;
        team = player_team;
        rank = player_rank;
        cout << "Player name: " << name << endl;
        cout << "Team: " << team << endl;
        cout << "Initial rank: " << rank << endl;
        cout << "--------------------" << endl;
    }
};

// Lab 3: Friend Function
class LeaderboardPlayer {
private:
    string name;
    int score;

public:
    LeaderboardPlayer(string n, int s) {
        name = n;
        score = s;
    }

    // Friend function declaration
    friend void displayLeaderboard(LeaderboardPlayer p1, LeaderboardPlayer p2);
};

// Friend function definition
void displayLeaderboard(LeaderboardPlayer p1, LeaderboardPlayer p2) {
    cout << "--- Leaderboard ---" << endl;
    if (p1.score > p2.score) {
        cout << "1. " << p1.name << " (Score: " << p1.score << ")" << endl;
        cout << "2. " << p2.name << " (Score: " << p2.score << ")" << endl;
    } else {
        cout << "1. " << p2.name << " (Score: " << p2.score << ")" << endl;
        cout << "2. " << p1.name << " (Score: " << p1.score << ")" << endl;
    }
    cout << "--------------------" << endl;
}

// Lab 4: Default and Parameterized Constructors
class GameCharacter {
private:
    string name;
    int health;
    int level;

public:
    // Default Constructor
    GameCharacter() {
        name = "Unknown";
        health = 100;
        level = 1;
    }

    // Parameterized Constructor
    GameCharacter(string char_name, int char_health, int char_level) {
        name = char_name;
        health = char_health;
        level = char_level;
    }

    void displayCharacter() {
        cout << "Name: " << name << ", Health: " << health << ", Level: " << level << endl;
    }

    ~GameCharacter() {
        cout << "Game character " << name << " is destroyed." << endl;
    }
};

// Lab 5: Static Members
class Game {
private:
    static int total_games;

public:
    static void showTotalGames() {
        cout << "Total games played: " << total_games << endl;
    }

    void play() {
        cout << "Playing a game..." << endl;
        total_games++;
    }
};

int Game::total_games = 0; // Initialize static member

// Lab 6: Function Overloading
class CharacterAttacks {
private:
    string name;
    int health;

public:
    CharacterAttacks(string char_name, int hp) {
        name = char_name;
        health = hp;
    }

    void attack() {
        cout << name << " performs a basic attack!" << endl;
    }

    void attack(int damage) {
        cout << name << " deals " << damage << " with attack!" << endl;
    }

    void takeDamage(int damage) {
        health -= damage;
        cout << name << " takes " << damage << " damage." << endl;
    }
    
    void displayHealth() {
        cout << name << "'s remaining health: " << health << endl;
    }
};

// Lab 7: Operator Overloading
class PlayerStats {
private:
    int health;

public:
    PlayerStats(int h) {
        health = h;
    }

    // Overload the unary minus operator
    void operator-() {
        health -= 10;
        if (health < 0) {
            health = 0;
        }
    }

    void display() {
        cout << "Current health: " << health << endl;
    }
};

// Lab 8: Operator Overloading for binary addition
class TeamPlayer {
private:
    string name;
    int score;

public:
    TeamPlayer(string n, int s) {
        name = n;
        score = s;
    }

    TeamPlayer operator+(const TeamPlayer& other) {
        string combined_name = name + " + " + other.name;
        int combined_score = score + other.score;
        return TeamPlayer(combined_name, combined_score);
    }
    
    void display() {
        cout << "Player: " << name << ", Score: " << score << endl;
    }
};

// Main program
int main() {
    int choice;
    GamePlayer *player_array = nullptr; // Pointer for array of objects
    int num_players = 0;

    do {
        cout << "\n--- Master C++ Program Menu ---" << endl;
        cout << "1. Manage Game Player Data (Lab 1)" << endl;
        cout << "2. Register Players with Default Arguments (Lab 2)" << endl;
        cout << "3. Display Leaderboard with Friend Function (Lab 3)" << endl;
        cout << "4. Create Game Characters with Constructors (Lab 4)" << endl;
        cout << "5. Track Total Games Played (Lab 5)" << endl;
        cout << "6. Demonstrate Function Overloading (Lab 6)" << endl;
        cout << "7. Demonstrate Unary Operator Overloading (Lab 7)" << endl;
        cout << "8. Demonstrate Binary Operator Overloading (Lab 8)" << endl;
        cout << "9. Create an Array of Game Players" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Lab 1: Classes and Objects
                cout << "\n--- Lab 1: Classes and Objects ---" << endl;
                GamePlayer table_tennis("Fangzhendong", 1997, "China");
                table_tennis.displayDetails();
                break;
            }
            case 2: {
                // Lab 2: Default Arguments
                cout << "\n--- Lab 2: Default Arguments ---" << endl;
                Player p;
                p.registerPlayer("Malong");
                p.registerPlayer("Fangzhendong", "China");
                p.registerPlayer("Stanath", "Lions", 1250);
                break;
            }
            case 3: {
                // Lab 3: Friend Function
                cout << "\n--- Lab 3: Friend Function ---" << endl;
                LeaderboardPlayer p1("GhostRider", 1500);
                LeaderboardPlayer p2("Shadow", 1800);
                displayLeaderboard(p1, p2);
                break;
            }
            case 4: {
                // Lab 4: Default and Parameterized Constructors
                cout << "\n--- Lab 4: Constructors ---" << endl;
                GameCharacter c1; // Default constructor
                GameCharacter c2("Knight", 150, 5); // Parameterized constructor
                c1.displayCharacter();
                c2.displayCharacter();
                break;
            }
            case 5: {
                // Lab 5: Static Members
                cout << "\n--- Lab 5: Static Members ---" << endl;
                Game g1, g2;
                g1.play();
                g2.play();
                Game::showTotalGames();
                break;
            }
            case 6: {
                // Lab 6: Function Overloading
                cout << "\n--- Lab 6: Function Overloading ---" << endl;
                CharacterAttacks character("Barbarian", 200);
                character.attack(); // Basic attack
                character.attack(25); // Overloaded attack with damage
                character.takeDamage(10);
                character.displayHealth();
                break;
            }
            case 7: {
                // Lab 7: Unary Operator Overloading
                cout << "\n--- Lab 7: Unary Operator Overloading ---" << endl;
                PlayerStats p1(100);
                p1.display();
                -p1; // Decrement health by 10
                p1.display();
                break;
            }
            case 8: {
                // Lab 8: Binary Operator Overloading
                cout << "\n--- Lab 8: Binary Operator Overloading ---" << endl;
                TeamPlayer tp1("Sif", 50);
                TeamPlayer tp2("Knuth", 60);
                TeamPlayer tp3 = tp1 + tp2; // Overloaded addition
                tp3.display();
                break;
            }
            case 9: {
                cout << "\n--- Array of Objects ---" << endl;
                cout << "Enter the number of players to store: ";
                cin >> num_players;
                cin.ignore(); // Clear the buffer
                player_array = new GamePlayer[num_players];
                for (int i = 0; i < num_players; ++i) {
                    string name, country;
                    int year;
                    cout << "\nEnter details for player " << i + 1 << ":" << endl;
                    cout << "Name: ";
                    getline(cin, name);
                    cout << "Year of Birth: ";
                    cin >> year;
                    cin.ignore();
                    cout << "Country: ";
                    getline(cin, country);
                    player_array[i] = GamePlayer(name, year, country);
                }
                
                cout << "\n--- Stored Player Details ---" << endl;
                for (int i = 0; i < num_players; ++i) {
                    player_array[i].displayDetails();
                    cout << "--------------------" << endl;
                }
                
                delete[] player_array; // Deallocate memory
                player_array = nullptr;
                num_players = 0;
                break;
            }
            case 10:
                cout << "Exiting program. Goodbye! ??" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 10);

    return 0;
}
