#include "EventManager.h"
#include <iostream>
#include <functional>
#include <string>
#include <iostream>


int main(){

    int total_damage = 0;
    std::string panda_attack = "Panda";
    std::string grizzly_attack = "Grizzly";
    
    auto attack_callback = [&total_damage](const std::string& attacker, int damage_taken){
        total_damage += damage_taken;
        if (total_damage < 100){
            std::cout << "You got attacked by a " << attacker << ". Total damage taken: " << total_damage << std::endl;
        }
        else{
            std::cout << "Game-over! You got attacked by a " << attacker << " again. Total damage: " << total_damage << "\nCongrats, now you're dead\n";
        }
    };

    EventManager manager;

    manager.subscribe(panda_attack, attack_callback);
    manager.subscribe(grizzly_attack, attack_callback);

    manager.emit(grizzly_attack, 25);
    manager.emit(panda_attack, 1);
    manager.emit(grizzly_attack, 25);
    manager.emit(grizzly_attack, 25);
    manager.emit(panda_attack, 1);
    manager.emit(grizzly_attack, 25);


}