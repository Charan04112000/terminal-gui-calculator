#ifndef UI_H
#define UI_H

#include <string>
#include <vector>

void initColors();
std::string getInput(const std::string& prompt);
void showOutput(const std::string& output);
void showError(const std::string& error);
void showHistory(const std::vector<std::string>& history);
void saveHistoryToFile(const std::vector<std::string>& history);

#endif

