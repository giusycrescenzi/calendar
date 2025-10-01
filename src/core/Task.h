#ifndef TASK_H
#define TASK_H

#include <chrono>
#include <string>

class Task {
public:
    Task(const std::string& description)
        : description(description), start(std::chrono::system_clock::now()) {}
    void setFinish() {
        finish = std::chrono::system_clock::now();
    }
    std::string getDescription() const {
        return description;
    }
    std::chrono::system_clock::time_point getStart() const {
        return start;
    }
    std::chrono::system_clock::time_point getFinish() const {
        return finish;
    }

private:
    std::string description;
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point finish;
};

#endif // TASK_H
