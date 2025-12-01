# CS5301 Image Editor — C++ Final Project  
**Author:** Syeda Tasmi Faria  
**Course:** CS5301 Programming Practicum  


---

## 📌 Project Overview

This project is a **console-based grayscale Image Editor** written in C++.  
It supports loading images from CSV files, applying image-processing operations, performing flood-fill recursion, maintaining edit history using a linked list, and providing full **Undo/Redo** functionality with stacks.

This project demonstrates:

- Object-Oriented Programming in C++  
- Linked List implementation (`History`)  
- Stack-based Undo/Redo (`UndoRedo`)  
- Recursion (`floodFill`)  
- File handling with CSVs  
- A menu-driven interface  

It is organized using clean `.h` and `.cpp` separation following modular programming principles.

---

## 🖼️ Features

### ✔ Image Editing Operations
- Invert image  
- Brighten  
- Darken  
- Apply threshold  
- Flood Fill (recursive)

### ✔ Undo / Redo System
- Uses two stacks (`undoStack`, `redoStack`)
- Saves state before every edit
- Resets automatically when a new image is loaded

### ✔ Edit History (Linked List)
- Stores every saved version of the image  
- User can display history anytime

### ✔ Load / Save Images
- Works with CSV-based grayscale images  
- Saves results into `/data` folder

### ✔ Menu-Based Console Interface
Simple numeric menu for all operations.

---

## 📂 Folder Structure

```
CS5301_ImageEditor/
│
├── data/            # CSV image files
│   ├── sample.csv
│   ├── output.csv
│   └── ...
│
├── include/         # Header files
│   ├── Image.h
│   ├── History.h
│   └── UndoRedo.h
│
├── src/             # C++ source code
│   ├── main.cpp
│   ├── Image.cpp
│   ├── History.cpp
│   └── UndoRedo.cpp
│
└── README.md
```

---

## 🛠️ How to Compile and Run

From the `src` directory:

```bash
g++ main.cpp Image.cpp History.cpp UndoRedo.cpp -I ../include -o main.exe
./main.exe
```

---

## 🧠 Data Structures Used

### 🔹 1. Linked List — History
The `History` class uses a **singly linked list** to store past image states:

- pixel matrix  
- width & height  
- pointer to next state  

Each time the image changes, a new node is added.

---

### 🔹 2. Stacks — Undo/Redo
Implemented in the `UndoRedo` class:

- `undoStack` stores previous states  
- `redoStack` stores states popped by undo  

Undo/Redo behavior:

- Before modifying the image: push to undo  
- Undo: move current → redo, restore previous  
- Redo: move current → undo, restore next  
- Loading a new image resets both stacks  

---

### 🔹 3. Recursion — Flood Fill
Flood fill uses a recursive DFS-like helper:

```cpp
void floodFillHelper(int r, int c, int oldColor, int newColor);
```

It:

1. Checks boundaries  
2. Replaces the pixel color  
3. Recursively visits neighbors (up, down, left, right)  

This models the “bucket fill” tool in image editors.

---

## 🧪 Sample Menu

```
===== Simple Image Menu =====
1. Invert
2. Brighten
3. Darken
4. Threshold
5. Flood Fill
6. Show History
7. Save Image
8. Load New Image
9. Undo
10. Redo
0. Exit
```

---

## 🔧 CSV Image Format

A CSV image is simply:

- Each row = one row of pixels  
- Each number = grayscale value (0–255)

Example:

```
0,0,0
0,255,255
255,255,255
```

---

## 🎯 Learning Reflection

This project helped me understand how separate C++ classes work together in a larger application. Implementing a linked list for edit history and stacks for undo/redo made data structures feel more practical. The recursive flood fill function taught me how recursion naturally models region-based algorithms. I also learned to structure code with `.h`/`.cpp` files, debug compilation issues, and manage a full project using Git and GitHub. Overall, this project strengthened my confidence in building real-world C++ systems instead of isolated classroom exercises.

---

## 📘 Future Improvements (Optional)

- Add input validation for incorrect user input  
- Add preview of images using ASCII characters  
- Add more filters (blur, sharpen, edge detection)  
- Add ability to undo multiple flood fill steps visually  

---

## ✔ Project Status

Fully functional.  
Includes linked list, stack, recursion, modular structure, and menu-driven interface.  
Implemented according to CS5301 Practicum requirements.
