#ifndef STRATEGY_MANAGER_H
#define STRATEGY_MANAGER_H
#include "../Factories/Strategy_Factory.h"
// This is the Strategy Manager class that will manage the playing strategies for different playlists
// It will use strategy factory. It is a singleton class to ensure that only one instance of the manager exists throughout the application
class Strategy_Manager
{
private:
    static Strategy_Manager *instance; // Static instance pointer for the singleton pattern
    static mutex mtx;
    Strategy_Manager() {} // Private constructor to prevent instantiation
public:
    // Static method to get the single instance of the manager
    static Strategy_Manager *getInstance()
    {
        if (instance == nullptr)
        {                                // Check if the instance is not created yet
            lock_guard<mutex> lock(mtx); // Lock the mutex to ensure thread safety
            if (instance == nullptr)
            {                                      // Double-check if the instance is still not created
                instance = new Strategy_Manager(); // Create the instance
            }
        }
        return instance; // Return the single instance of the manager
    }

    // Method to get a playing strategy for a given playlist and strategy type
    IPlay_Strategy *getStrategy(Playlist *playlist, string strategyType, vector<Song> customOrder = {}, string direction = "forward")
    {
        // Use the strategy factory to create and return the appropriate strategy based on the user's choice
        return Strategy_Factory::getInstance()->createStrategy(playlist, strategyType, customOrder, direction);
    }
};

// Initialize the static instance pointer and mutex
Strategy_Manager *Strategy_Manager::instance = nullptr;
mutex Strategy_Manager::mtx;

#endif // STRATEGY_MANAGER_H