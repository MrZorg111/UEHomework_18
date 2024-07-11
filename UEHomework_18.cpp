#include <iostream>
#include <string>
#include <vector>


class Player{
private:
    std::string name_player;
    int point;
public:
    Player() {
        name_player = " ";
        point = 0;
    }
    void setNamePlayer(std::string _name_player) {
        name_player = _name_player;
    }
    void setPoint(int _point) {
        point = _point;
    }

    void getNamePlayer() {
        std::cout << name_player;
    }
    void getPrintPoint() {
        std::cout << point;
    }

    int getPoint() {
        return point;
    }
};


int main()
{
    std::vector<Player> players;
    int num_players = 0;
    std::cout << "How many players will we add? " << std::endl;
    std::cin >> num_players;
    const int SIZE = num_players;

    for (int i = 0; i < SIZE; i++) {
        Player* tempo_player = new Player();
        std::string tempo_name = " ";
        int tempo_point = 0;
        
        std::cout << "Enter the player's name: " << std::endl;
        std::cin >> tempo_name;
        tempo_player->setNamePlayer(tempo_name);

        std::cout << "Enter the number of points: " << std::endl;
        std::cin >> tempo_point;
        tempo_player->setPoint(tempo_point);
        
        players.push_back(*tempo_player);
        delete tempo_player;
    }
    
    for (int y = 0; y < SIZE - 1; y++) {
        for (int u = 0; u < SIZE - 1 - y; u++) {
            auto p = Player();
            if (players[u].getPoint() < players[u + 1].getPoint()) {
                p = players[u];
                players[u] = players[u + 1];
                players[u + 1] = p;
            }
        }
    }

    for (int j = 0; j < SIZE; j++) {
        std::cout << "\t--Name player ";
        players[j].getNamePlayer();
        std::cout << "\t Point: ";
        players[j].getPrintPoint();
        std::cout << std::endl;
    }
}

