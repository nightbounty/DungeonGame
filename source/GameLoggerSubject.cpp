#include "GameLoggerSubject.h"

void GameLoggerSubject::Attach(GameLoggerObserver* observer) {
    observers.push_back(observer);
}

void GameLoggerSubject::Detach(GameLoggerObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void GameLoggerSubject::Notify(const std::string& logEntry) {
    for (GameLoggerObserver* observer : observers) {
        observer->Update(logEntry);
    }
}
