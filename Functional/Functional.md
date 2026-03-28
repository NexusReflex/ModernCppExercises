# C++ Practice Circuit: Exercise 02
## The Functional Event Dispatcher (std::function & Closures)

In professional C++ development—ranging from Game Engines (Unreal/Godot) to GUI frameworks (Qt)—we often treat **logic as data**. This exercise moves beyond simple data sorting and into **Behavioral Programming** using the functional headers of Modern C++.

### The Objective
Build an `EventManager` system that allows different parts of a program to "subscribe" to named events (e.g., `"OnDamage"`, `"OnLevelUp"`) using Lambdas and execute them dynamically when an event is triggered.

### Your Tasks
1. **The Registry:** Define a class `EventManager`. Use a `std::map<std::string, std::vector<std::function<void(int)>>>` to store subscribers.
    * The `string` key is the Event Name.
    * The `std::vector` stores multiple "callbacks" (functions) for that specific event.
2. **The Subscribe Method:** Implement `void subscribe(const std::string& eventName, std::function<void(int)> callback)`.
3. **The Emit Method:** Implement `void emit(const std::string& eventName, int value)`.
    * Use `std::for_each` from the `<algorithm>` header to iterate through the vector and execute every callback.
    * **Pro-tip:** Use `.find()` on the map instead of `[]` to avoid creating empty entries for events that don't exist.
4. **The Stateful Lambda:** In `main()`, create a local variable `int totalDamage = 0;`. 
    * Subscribe a Lambda to `"OnDamage"` that captures `totalDamage` **by reference**.
    * Every time `emit("OnDamage", x)` is called, the total should increase and be printed.

### Why This Matters
By using `std::function`, you are utilizing **Type Erasure**. The `EventManager` doesn't need to know if it's calling a global function, a member function, or a Lambda; it only cares about the **signature** (`void(int)`). This decouple's your system's "Trigger" from its "Logic," which is essential for scalable architecture.