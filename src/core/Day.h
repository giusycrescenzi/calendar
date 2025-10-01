#pragma once

#include <vector>
#include <string>
#include <chrono>

enum class Mood { //from Plutchik's wheel of emotions
    Happy,
    Sad,
    Angry,
    Fearful,
    Surprised,
    Anticipation,
    Trust,
    Disgusted,
};

class Day {
public:
    Day(const std::string& dailyNote, Mood mood)
        : dailyNote(dailyNote), mood(mood) {}

    void addActivity(const std::string& activity) {
        activities.push_back(activity);
    }

    std::vector<std::string> getActivities() const {
        return activities;
    }

    std::string getDailyNote() const {
        return dailyNote;
    }

    Mood getMood() const {
        return mood;
    }

private:
    std::vector<std::string> activities;
    std::string dailyNote;
    Mood mood;
};