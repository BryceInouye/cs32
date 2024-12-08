**Name**: Bryce, Perm: A179M30

**Game**: Reincarnated in a Magical World (Definitely never been done before, totally original idea)

**Objective**: Get a restart on life and make daring choices your old self would never make! Be the hero you always dreamed of. Watch out though. Lot's of enemies out there.

**The Vision**: There would be more item types, locations, characters and a better UI. The current version is a preview with the game's core mechanics like **interactive combat**, **dynamic battles**, **a built-in economy**, and a **wacky set of items**. The foundations to a *Choose Your Adventure* game are there, there just needs to be more interactions for a complete story. Also, I apologize for the current code being extremely messy and disorganized. I realize I am not good under pressure and will work on that skill by creating a better system to prioritize tasks.

**Remark**: Yes, this game is still a work in progress. Due to a mixture of finals week studying and desire to keep adding features, I ran short on time. I really enjoyed working on this assignment as it served as a engaging way to review topics that have been taught over the course of the quarter. This is definitely something I would revist later. If I can get any credit for this, I would really appreciate it.

**Sources**:

geeksforgeeks.org - For quick c++ syntax lookups.

cppreference.com  - Used when geeksforgeeks was too vague.

stackoverflow.com - For oddly specific questions, like why Make was not linking files properly.

Miro              - For drawing out story structure and high level way to represent the program.

**Topics Used**:
1. Standard Library Containers - `vector` is used to store class instances. `unordered_set` is used to handle game states. `queue` is used for game progression logic.
2. Custom Template Class - Because I was short on time, I decided to rework and build on a previous lab, *Lab 7* and convert it to a template class. There are probably more creative ways to do this by creating something from scratch, but I believe I learned a lot, both reviewing templates and building off of existing code, something I belive is an important skill to work on.
3. Custom Namespace - I used them everywhere. An example would be `namespace Location`. I never thought I would enjoy using them as much as I did, this has helped me realize the gravity of my bad habit of `using namespace std`, something I will work on in future projects.
4. Classes with a Constructor, Destructor, Assignment Operator - I created a class `Food` that has an overloaded assignment operator. I was about to implement it, but I thought submitting something is better than nothing. I could have modified `CustomDataStruct::unordered_map` to support assignment operator, but I felt guilty seeing how many birds would have been killed with one stone (This could have checked all of the boxes smoothly besides inheritance).
5. Lambda Functions - I modified my implementation of `CustomDataStruct::unordered_map` to use lambda functions. I would use these more, but I wanted to get everything written first, then clean the code with lambda functions.
6. Exception Handling - The most common use case was to handle invalid user input. 
7. Inheritance - One example of this in the code would be the `Food` class, which is inherited from `Item`.
8. Virtual functions or Abstract Classes - `Item` class is an abstract class.
9. Hashing - Besides using `std::unordered_set`, `CustomDataStruct::unordered_map` uses a hashing function to calculate keys. So the code uses the cpp built-in hashing function and also my custom chaining method.
10. Sorting Algorithms - I modified `CustomDataStruct::unordered_map` to sort template, though I would argue still needs some polishing to support a wider variety of types.

**Remark 2** If have read up to this far, thank you for your time and consideration. Have a pleasant holiday break!
