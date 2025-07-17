#include "ui.h"
#include <ncurses.h>
#include <iostream>
#include <fstream>

void initColors() {
    init_pair(1, COLOR_GREEN, -1);   // Output
    init_pair(2, COLOR_RED, -1);     // Error
    init_pair(3, COLOR_YELLOW, -1);  // Prompt
    init_pair(4, COLOR_CYAN, -1);    // History
}

std::string getInput(const std::string& prompt) {
    attron(COLOR_PAIR(3));
    printw("%s", prompt.c_str());
    attroff(COLOR_PAIR(3));
    refresh();

    char buffer[256];
    getnstr(buffer, 255);
    return std::string(buffer);
}

void showOutput(const std::string& output) {
    attron(COLOR_PAIR(1));
    printw("Result: %s\n", output.c_str());
    attroff(COLOR_PAIR(1));
    refresh();
}

void showError(const std::string& error) {
    attron(COLOR_PAIR(2));
    printw("Error: %s\n", error.c_str());
    attroff(COLOR_PAIR(2));
    refresh();
}

void showHistory(const std::vector<std::string>& history) {
    attron(COLOR_PAIR(4));
    printw("\nCalculation History:\n");
    for (const auto& line : history) {
        printw("%s\n", line.c_str());
    }
    attroff(COLOR_PAIR(4));
    refresh();
}

void saveHistoryToFile(const std::vector<std::string>& history) {
    std::ofstream file("calc_history.txt", std::ios::app);
    for (const auto& line : history) {
        file << line << std::endl;
    }
    file.close();
}

