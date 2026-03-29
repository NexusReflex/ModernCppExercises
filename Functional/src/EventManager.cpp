#include "EventManager.h"


void EventManager::subscribe(const std::string& eventName, std::function<void(const std::string&, int)> callback){
    eventHandlers[eventName].push_back(std::move(callback));
}

void EventManager::emit(const std::string& eventName, int damage_taken){
    // 1. Find the event list
    auto it = eventHandlers.find(eventName);
    
    // 2. If it exists, iterate and call
    if (it != eventHandlers.end()){
        // 'it->second' is the vector of functions
        for (auto& handler : it->second){
            handler(eventName, damage_taken);
        }
    }
}