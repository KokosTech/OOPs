#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Character {
    protected:
        float health; // must be positive
        float defense; // must be positive
        string name;
    public:
        Character(string name, float health, float defense)
        : name(name), health(health), defense(defense) {
            if (health <= 0 || defense <= 0 || name.empty())
                        throw invalid_argument("Invalid player stats!");
        }
        
        float getHealth() const { return this->health; }
        
        float getDefense() const { return this->defense; }
        
        const string& getName() const { return this->name; }

        void setHealth(const float health) { if(health < 0) throw invalid_argument("Health must be positive or neutral"); this->health = health; }

        void setDefense(const float defense) { if(defense < 0) throw invalid_argument("Defense must be positive or neutral"); this->defense = defense; }
        
        void setName(const string& name) { if(name.length() == 0) throw invalid_argument("Name must be non-empty"); this->name = name; }
};

class Enemy : public Character {
    private:
        float damage;
    public:
        Enemy(const string& name, float health, float defense, float damage) 
        : Character(name, health, defense), damage(damage) {
            if (health <= 0 || defense <= 0 || name.empty())
                throw invalid_argument("Invalid player stats!");
        }
        float getDamage() const { return this->damage; }
        void setDamage(const float damage) { if(damage <= 0) throw invalid_argument("Damage must be positive"); this->damage = damage; }
};

class Ability {
    private:
        string name;
        float damage;
    public:
        Ability(const string& name, const float damage)
        : name(name), damage(damage) { 
            if (name.empty() || damage <= 0)
                throw invalid_argument("Invalid player stats!");
        }

        float getDamage() const { return this->damage; }
        
        void setDamage(const float damage) { if(damage <= 0) throw invalid_argument("Damage must be positive"); this->damage = damage; }
        
        const string& getName() const { return this->name; }
        
        void setName(const string& name) { if(name.length() == 0) throw invalid_argument("Name must be non-empty"); this->name = name; }
};

class Player : public Character {
    private:
        vector<Ability> abilities;
    public:
        Player(const string& name, float health, float defense, const std::vector<Ability>& abilities) : Character(name, health, defense), abilities(abilities) {
            if(abilities.size() == 0) throw invalid_argument("Invalid player stats!");
        }

        Player& addAbility(const Ability& ability) {
            abilities.push_back(ability);
            return *this;
        }

        const vector<Ability>& getAbilities() const { return abilities; }
};

class PlayerHelper {
    public:
        static float getTotalPlayerDamage(const Player& player){
            float totalDamage = 0;

            for(const auto& ability : player.getAbilities())
                totalDamage += ability.getDamage();
            
            return totalDamage;
        }
};

class Arena {
    public:
        static int currentEnemyIndex;

        static bool fight(Player& player, vector<Enemy>& enemies){
            if(enemies.size() == 0) throw std::invalid_argument("No enemies!");
            if(player.getHealth() + player.getDefense() <= 0) return false;

            float playerDamage = PlayerHelper::getTotalPlayerDamage(player);

            while(currentEnemyIndex < enemies.size() && player.getHealth() > 0){
/*                 cout << "AAAA" << currentEnemyIndex << "  " << enemies.size() << endl;
                cout << "Stats:\n";
                cout << "Player: " << player.getName() << " " << player.getHealth() << " " << player.getDefense() << " TD: " << playerDamage << "\n";
                cout << "Enemy: " << enemies[currentEnemyIndex].getName() << " " << enemies[currentEnemyIndex].getHealth() << " " << enemies[currentEnemyIndex].getDefense() << " TD: " << enemies[currentEnemyIndex].getDamage() << "\n";
                cout << endl; */
                Enemy& enemy = enemies[currentEnemyIndex];
                
                // Player turn
                float damageDealt = 0;

                if(enemy.getDefense() > 0) {
                    damageDealt = enemy.getDefense() - playerDamage;
                    damageDealt = damageDealt > 0 ? damageDealt : 0;
                    enemy.setDefense(damageDealt);
                } else {
                    damageDealt = enemy.getHealth() - playerDamage;
                    damageDealt = damageDealt > 0 ? damageDealt : 0;
                    enemy.setHealth(damageDealt);
                }

                // Enemy turn

                damageDealt = 0;
                if(enemies[currentEnemyIndex].getHealth() <= 0) 
                    enemy = enemies[++currentEnemyIndex];
                

                if(player.getDefense() > 0) {
                    damageDealt = player.getDefense() - enemy.getDamage();
                    damageDealt = damageDealt > 0 ? damageDealt : 0;
                    player.setDefense(damageDealt);

                } else {
                    damageDealt = player.getHealth() - enemy.getDamage();
                    damageDealt = damageDealt > 0 ? damageDealt : 0;
                    player.setHealth(damageDealt);
                }
            }

            if(player.getHealth() <= 0) return false;

            currentEnemyIndex = -1;
            return true;
        }
};

int Arena::currentEnemyIndex = 0;

// Reading from File


/*
// Writing to file - output

Player wins:
-	“Player health: _”.
-	“Player defense: _”.


Enemy X wins:
-	“Enemy X health: _” , where X is the first living enemy from the list
-	“Enemy X defense: _”, where X is the first living enemy from the list
*/

int main() {
    ifstream inputFile("input.txt", ios::in);
    try {
        if(!inputFile.is_open()) throw invalid_argument("File not found!");
    } catch(const invalid_argument& e) {
        cout << e.what() << endl;
        return -1;
    }

    ofstream outputFile("output.txt", ios::out);
    try {
        if(!outputFile.is_open()) throw invalid_argument("File not found!");
    } catch(const invalid_argument& e) {
        cout << e.what() << endl;
        inputFile.close();
        return -1;
    }

    Arena arena;
    vector<Enemy> enemies;
    vector<Ability> abilities;

    // Get Player & Abilities

    string line;
    getline(inputFile, line);
    stringstream ss(line);
    string name = ""; float health = 0, defense = 0; 
    ss >> name >> health >> defense;
    abilities.clear();

    try {
        string abilityName; float abilityDamage;
        while(ss >> abilityName){
            ss >> abilityDamage;
            abilities.push_back(Ability(abilityName, abilityDamage));
            abilityName = ""; abilityDamage = 0;
        }  
    } catch(const invalid_argument& e) {
        cout << e.what() << endl;
        inputFile.close();
        outputFile.close();
        return -1;
    }
 
    // Get Enemies
    try {
        while(inputFile.good() && getline(inputFile, line)) {
            string name;
            float health;
            float defense;
            float damage;

            ss = stringstream();
            ss << line;
            ss >> name >> health >> defense >> damage;
            enemies.push_back(Enemy(name, health, defense, damage));

        }
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
        inputFile.close();
        outputFile.close();
        return -1;
    }

    // End of input

    inputFile.close();

    // Create player && start game
    try {
        Player player(name, health, defense, abilities);

        // Start Game

        if(arena.fight(player, enemies)){
            outputFile << "Player health: " << player.getHealth() << endl;
            outputFile << "Player defense: " << player.getDefense() << endl;
        } else {
            outputFile << "Enemy " << Arena::currentEnemyIndex + 1 << " health: " << enemies[Arena::currentEnemyIndex].getHealth() << endl;
            outputFile << "Enemy " << Arena::currentEnemyIndex + 1 << " defense: " << enemies[Arena::currentEnemyIndex].getDefense() << endl;
        }
    } catch(const invalid_argument& e) {
        cout << e.what() << endl;
        outputFile.close();
        return -1;
    }

    outputFile.close();

    return 0;
}