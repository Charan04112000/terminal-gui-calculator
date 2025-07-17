# terminal-gui-calculator
A modular terminal-based calculator in C++ using ncurses, with expression parsing, floating-point support, and history saving.
# 🧮 Terminal-Based GUI Calculator (C++ | ncurses | Modular Design)

A powerful, modular command-line calculator featuring a terminal GUI built using `ncurses`. This calculator supports:

- ✅ Integer & Floating Point Arithmetic  
- ✅ Expression Parsing with Precedence  
- ✅ Error Handling for Invalid Inputs  
- ✅ History Viewing & Saving to File  
- ✅ Cross-platform compatibility  
- ✅ Easily extendable to GUI frameworks like Qt/GTK

---

## 📁 Features

- **GUI via ncurses**: Terminal-based interface with color, cursor control, and better interactivity  
- **Expression Parsing**: Parses and evaluates complex math expressions (e.g., `3 + 4 * (2 - 1)`)  
- **Floating Point Support**: Works with both integers and decimals (e.g., `3.5 * 2.1`)  
- **Error Messages**: Displays user-friendly error messages on invalid inputs  
- **History Saving**: Automatically saves calculation history to a file  
- **Modular Design**: Separated into `main.cpp`, `parser.cpp`, and `ui.cpp` for clarity and maintainability  

---

## 🛠️ Compilation

Ensure you have `g++` and `libncurses-dev` installed.

### 📦 Linux

```bash
sudo apt install libncurses5-dev libncursesw5-dev
g++ main.cpp parser.cpp ui.cpp -lncurses -o calc
./calc
📂 File Structure
less
Copy
Edit
📦 calculator
├── main.cpp          // Handles main loop, user input/output
├── parser.cpp/.h     // Expression parser and evaluator
├── ui.cpp/.h         // ncurses UI and history file handling
├── calc_history.txt  // (Generated) Saved history of calculations
└── README.md         // Project documentation
🚀 How to Use
Launch with ./calc

Enter expressions like 3 + 5 * 2.5

Press Enter to evaluate

View/save history

Exit with q
 Export History
History is auto-saved to calc_history.txt after each session.

🧩 Future Additions
 GUI with Qt or GTK+

 Scientific functions (sin, cos, log, etc.)

 Mouse support in ncurses

👨‍💻 Author
Sai Charan Reddy Etikala
🛠️ Embedded Developer | C/C++ | Linux | UI Systems
etikala441@gmail.com
