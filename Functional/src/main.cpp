#include "EventManager.h"
#include <iostream>
#include <functional>
#include <string>
#include <iostream>


int main(){

    int total_damage = 0;
    bool is_alive = true;

    std::string panda_attack = "Panda";
    std::string grizzly_attack = "Grizzly";

    auto attack_callback = [&total_damage, &is_alive](const std::string& attacker, int damage_taken){
        if (!is_alive) return; // Don't process if already dead
        total_damage += damage_taken;
        if (total_damage < 100){
            std::cout << "You got attacked by a " << attacker << ". Total damage taken: " << total_damage << std::endl;
        }
        else{
            is_alive = false;
            std::cout << "Game-over! You got attacked by a " << attacker << " again. Total damage: " << total_damage << "\nCongrats, now you're dead\n";
        }
    };

    EventManager manager;

    manager.subscribe(panda_attack, attack_callback);
    manager.subscribe(grizzly_attack, attack_callback);

    while(is_alive) {
        manager.emit(grizzly_attack, 25);
        manager.emit(panda_attack, 1);
    }
    

}