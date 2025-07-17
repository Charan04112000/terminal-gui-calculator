#include "parser.h"
#include "ui.h"
#include <ncurses.h>
#include <vector>
#include <string>

int main() {
    initscr();            // Start ncurses mode
    start_color();        // Enable color
    use_default_colors(); 
    cbreak();
    noecho();

    initColors();         // Defined in ui.cpp

    std::vector<std::string> history;

    while (true) {
        std::string input = getInput("Enter expression (or type 'exit'): ");

        if (input == "exit") break;

        try {
            double result = evaluateExpression(input);
            std::string output = input + " = " + std::to_string(result);
            history.push_back(output);
            showOutput(output);
        } catch (const std::exception& e) {
            showError(e.what());
        }

        showHistory(history);
        saveHistoryToFile(history);
    }

    endwin();  // End ncurses mode
    return 0;
}

