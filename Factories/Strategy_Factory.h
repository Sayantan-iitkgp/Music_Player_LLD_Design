#ifndef STRATEGY_FACTORY_H
#define STRATEGY_FACTORY_H
#include "../Playing_Strategies/IPlay_Strategy.h"
#include "../Playing_Strategies/Sequential_Strategy.h"
#include "../Playing_Strategies/Random_Strategy.h"
#include "../Playing_Strategies/Custom_Strategy.h"
// This is the factory class for creating different playing strategies based on the user's choice
// This is a Singleton class to ensure that only one instance of the factory exists throughout the application
class Strategy_Factory
{
private:
    // Private constructor to prevent instantiation
    static Strategy_Factory *instance; // Static instance pointer for the singleton pattern
    static mutex mtx;
    Strategy_Factory() {}

public:
    // Static method to get the single instance of the factory
    static Strategy_Factory *getInstance()
    {
        if (instance == nullptr)
        {                                // Check if the instance is not created yet
            lock_guard<mutex> lock(mtx); // Lock the mutex to ensure thread safety
            if (instance == nullptr)
            {                                      // Double-check if the instance is still not created
                instance = new Strategy_Factory(); // Create the instance
            }
        }
        return instance; // Return the single instance of the factory
    }

    // Factory method to create a playing strategy based on the user's choice
    IPlay_Strategy *createStrategy(Playlist *playlist, string strategyType, vector<Song> customOrder = {}, string direction = "forward")
    {
        if (strategyType == "sequential")
        {
            return new Sequential_Strategy(playlist, direction); // Create and return a Sequential_Strategy
        }
        else if (strategyType == "random")
        {
            return new Random_Strategy(playlist, direction); // Create and return a Random_Strategy
        }
        else if (strategyType == "custom")
        {
            return new Custom_Strategy(playlist, customOrder, direction); // Create and return a Custom_Strategy with the custom order
        }
        else
        {
            throw invalid_argument("Invalid strategy type"); // Throw an exception for an invalid strategy type
        }
    }
};

// Initialize the static instance pointer and mutex
Strategy_Factory *Strategy_Factory::instance = nullptr;
mutex Strategy_Factory::mtx;

#endif // STRATEGY_FACTORY_H