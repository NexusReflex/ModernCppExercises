#include "MultiThreading.h"

void SafeQueue::push(std::string message){
    std::lock_guard<std::mutex> lock(mux);
    storage.push(std::move(message));
}

std::optional<std::string> SafeQueue::pop(){
    std::lock_guard<std::mutex> lock(mux);

    if (storage.empty()){
        return std::nullopt; // return nullptr
    }

    std::string frontValue = std::move(storage.front());
    storage.pop();
    return frontValue;
}// Mutex unlocks automatically here

size_t SafeQueue::size() const {
    std::lock_guard<std::mutex> lock(mux);
    return storage.size();

}