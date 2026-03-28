For this exercise, you are going to build a Media Library Manager. This system will track "Assets" (like Videos or Photos).

Here is Step 1: The Foundation (RAII & Ownership).

The Objective
Create a base class called MediaAsset and a derived class called Video. You will then manage these using std::unique_ptr to ensure no memory leaks occur, even if you don't write a destructor yourself.

Your Tasks
Define the Base: Create a class MediaAsset with a virtual destructor. Add a pure virtual function void play() const = 0;.

Define the Derived: Create a class Video that inherits from MediaAsset. Give it a std::string member for the title. Implement play() so it prints "Playing video: [title]".

The Factory: Write a standalone function (or a static factory method) called createAsset that takes a string and returns a std::unique_ptr<MediaAsset> pointing to a new Video object.

The Test: In main(), use your factory to create an asset. Call .play() on it.

Why this matters
In modern C++, std::unique_ptr represents exclusive ownership. When the pointer goes out of scope, the memory is freed automatically. By using a virtual destructor in the base class, you ensure that the Video portion of the memory is cleaned up even when deleted via a MediaAsset*.