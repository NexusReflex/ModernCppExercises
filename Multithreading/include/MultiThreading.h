#include <queue>
#include <mutex>
#include <string>
#include <optional>

class SafeQueue{
    public:
    
    void push(std::string message);
    
    std::optional<std::string> pop();

    size_t size() const;
    
    private:
        std::queue<std::string> storage;
        // The 'mutable' keyword tells the compiler: "This specific variable is allowed to change, even inside const methods.""
        mutable std::mutex mux; 
};