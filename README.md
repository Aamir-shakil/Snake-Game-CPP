# Snake Game (C++ Terminal Version)

## Overview
This is a terminal-based Snake game implemented in C++. The project demonstrates advanced programming concepts including **pointers, dynamic arrays, memory management, object-oriented design, and smart pointers**.  

The game uses **Segment structs** to represent points on the board and a **Snake class** to manage the snake’s movement, growth, and self-collision. A **Game class** handles the game loop, input, rendering, and additional features such as food and poison.

---

## Features
- Move the snake using **arrow keys**  
- Eat `*` to **grow** the snake  
- Avoid:  
  - Walls  
  - Poison `X`  
  - Your own body  
- Dynamic placement of **food and poison**  
- Pointer-based management of snake segments and poison positions  
- Pre-game **instructions screen**  
- Object-oriented code with **smart pointers** and **dynamic arrays**  

---

## Technical Details
- **Language:** C++  
- **Compiler:** Visual Studio 2022  
- **Memory Management:**  
  - Dynamic array for snake body and poison positions  
  - Smart pointer (`unique_ptr`) for the snake object  
- **Structs:** `Segment` used to represent points on the board  
- **Classes:**  
  - `Snake`: Handles movement, growth, collision detection  
  - `Game`: Handles game loop, rendering, input, and objects  
- **Pointers:**  
  - Access snake segments and poison dynamically  
  - Demonstrates memory management and pointer dereferencing  

---

## How to Run
1. Open the project in **Visual Studio 2022**  
2. Build the solution  
3. Run the executable — a terminal window will open  
4. Follow the **instructions screen** and use the arrow keys to play  


