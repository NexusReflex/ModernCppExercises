#pragma once

#include <string>
#include <vector>
#include <map>
#include <functional>


class EventManager{
    public:

        void subscribe(const std::string& eventName, std::function<void(const std::string&, int)> callback);

        void emit(const std::string& eventName, int damage_taken);

    private:
        std::map<std::string, std::vector<std::function<void(const std::string&, int)>>> eventHandlers;
        
};