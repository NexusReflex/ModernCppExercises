# Modern C++ Practice Circuit

This repository contains a series of 10 independent small coding exercises designed to practice the content of the [Modern C++ Bootcamp](https://github.com/NexusReflex/ModernCppBootcamp). Each project focuses on a specific pillar of the C++11 through C++23 standards.

## 🛠 Tools & Requirements

* **Compiler:** GCC 11+, Clang 13+, or MSVC 2022+ (Support for C++20/23 required).
* **Standard:** C++20/C++23.
* **Key Focus:** RAII, Move Semantics, Type Safety, Templates, and Concurrency.

---

## 📚 Exercise Roadmap & Progress

| # | Exercise | Core Concepts | Status |
| :--- | :--- | :--- | :--- |
| 01 | [Smart Resource Manager](./SmartResourceManagement) | `unique_ptr`, RAII, Rule of 5/0 | ✅ Done |
| 02 | [Functional Gradebook](./FunctionalProgramming) | Lambdas, `<algorithm>`, `std::function` | ⏳ Pending |
| 03 | [Thread-Safe Log Queue](./Multithreading) | Mutex, `lock_guard`, Concurrency | ⏳ Pending |
| 04 | [Type-Safe Visitor](./Variant) | `std::variant`, `std::visit` | ⏳ Pending |
| 05 | [The Generic Matrix](./Templates) | Templates, `static_assert`, Operators | ⏳ Pending |
| 06 | [Async Data Fetcher](./Async) | `std::future`, `std::async` | ⏳ Pending |
| 07 | [Custom Iterator](./Iterators) | Iterator Requirements, Range-for | ⏳ Pending |
| 08 | [String View Parser](./StringView) | `std::string_view`, `std::optional` | ⏳ Pending |
| 09 | [The Numeric Concept](./Concepts) | C++20 Concepts, `requires` clauses | ⏳ Pending |
| 10 | [Compile-time Math](./Constexpr) | `constexpr`, Template Metaprogramming | ⏳ Pending |

---

## 🚀 Compilation & Execution

To compile an exercise manually using G++ (replace `01_SmartPointers` with the target directory):

```bash
g++ -std=c++20 ./[DirectoryName]/*.cpp -o exercise_output
./exercise_output 
```

## ✅ Progress Checklist

- [x] **Exercise 01:** Implement Media Library with Smart Pointers and RAII.

- [ ] **Exercise 02:** Perform data transformations using <algorithm> and Lambdas.

- [ ] **Exercise 03:** Implement a Producer-Consumer thread-safe queue with Mutexes.

- [ ] **Exercise 04:** Replace class hierarchies with std::variant and std::visit.

- [ ] **Exercise 05:** Build a Template Matrix class with operator overloading.

- [ ] **Exercise 06:** Handle asynchronous data fetching and exception propagation.

- [ ] **Exercise 07:** Create a custom iterator to support range-based for loops.

- [ ] **Exercise 08:** Write a non-allocating parser using std::string_view.

- [ ] **Exercise 09:** Use C++20 Concepts to constrain template parameters.

- [ ] **Exercise 10:** Implement recursive algorithms using constexpr for compile-time evaluation.