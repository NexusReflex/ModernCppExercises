# C++ Practice Circuit: Exercise 1
## The Media Library Manager (RAII & Ownership)

Mastering smart pointers is the "Point of No Return" for C++ developers—once you get comfortable with them, you'll never want to touch a `delete` keyword again. In this exercise, you will build a **Media Library Manager** to track assets like videos or photos.

### Phase 1: The Foundation

#### The Objective
Create a base class called `MediaAsset` and a derived class called `Video`. You will manage these using `std::unique_ptr` to ensure no memory leaks occur, adhering to modern RAII (Resource Acquisition Is Initialization) principles.

#### Your Tasks
1. **Define the Base:** Create a class `MediaAsset` with a `virtual` destructor. Add a pure virtual function:  
   `virtual void play() const = 0;`
2. **Define the Derived:** Create a class `Video` that inherits from `MediaAsset`. 
   * Give it a `std::string` member for the title. 
   * Implement `play()` so it prints: `"Playing video: [title]"`.
3. **The Factory:** Write a standalone function (or a static factory method) called `createAsset` that takes a string and returns a `std::unique_ptr<MediaAsset>` pointing to a new `Video` object.
4. **The Test:** In `main()`, use your factory to create an asset. Call `.play()` on it.

#### Why This Matters
In modern C++, `std::unique_ptr` represents **exclusive ownership**. When the pointer goes out of scope, the memory is freed automatically. By using a `virtual` destructor in the base class, you ensure that the `Video` portion of the memory is cleaned up correctly even when deleted via a `MediaAsset*` pointer.