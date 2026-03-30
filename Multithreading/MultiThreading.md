# C++ Practice Circuit: Exercise 03
## The Thread-Safe Log Queue (Concurrency & Mutexes)

In a multithreaded environment (like a game engine or a web server), multiple threads often try to write to the same resource (a log file, a console, or a database) simultaneously. Without synchronization, this leads to **Data Races**, memory corruption, or garbled output.

### The Objective
Build a `SafeQueue` wrapper for `std::queue<std::string>`. This class will act as a "Thread-Safe Pipe" where multiple **Producer** threads can safely push messages, and a **Consumer** thread can safely pull them out.

### Your Tasks
1. **The Protected Container:** Create a class `SafeQueue`.
    * Use a `std::queue<std::string>` as the underlying storage.
    * Use a `std::mutex` to protect access to the queue.
2. **The Thread-Safe Push:** Implement `void push(std::string message)`.
    * Use `std::lock_guard<std::mutex>` to ensure that only one thread can modify the queue at a time.
3. **The Thread-Safe Pop:** Implement `std::optional<std::string> pop()`.
    * Lock the mutex, check if the queue is `empty()`.
    * If data exists, return the front element and `pop()` it. Otherwise, return `std::nullopt`.
4. **The Concurrency Test:** In `main()`:
    * Launch two `std::thread` objects. Each should loop 50 times, pushing a message like `"Thread A: message #X"` into the queue.
    * Use `.join()` to wait for both threads to finish.
    * Print the final size of the queue to verify that no messages were lost (it should be exactly 100).

### Why This Matters
`std::mutex` (Mutual Exclusion) provides a synchronization primitive that prevents "Race Conditions." By using `std::lock_guard`, we leverage **RAII**: the mutex is locked when the guard is created and automatically unlocked when the guard goes out of scope (even if an