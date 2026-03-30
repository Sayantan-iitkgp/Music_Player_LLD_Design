# Music Player Application (LLD)

This project is a Low-Level Design (LLD) implementation of a Music Player Application in C++. It demonstrates the use of several core Object-Oriented Design Patterns and efficient data structures to manage audio playback, device management, and playlist handling.

## Project Structure

```
.
├── Audio_Engine.h
├── IAudio_Output_Device.h
├── Main.cpp
├── Music_Player_Application.h
├── Music_Player_Facade.h
├── Audio_Adaptors/
│   ├── Bluetooth_Adaptor.h
│   ├── Headphone_Adaptor.h
│   ├── IAudioAdaptor.h
│   └── Wired_Speaker_Adaptor.h
├── Factories/
│   ├── Device_Factory.h
│   └── Strategy_Factory.h
├── Managers/
│   ├── Device_Manager.h
│   ├── Playlist_Manager.h
│   └── Strategy_Manager.h
├── Models/
│   ├── Playlist.h
│   └── Song.h
├── Playing_Strategies/
│   ├── Custom_Strategy.h
│   ├── IPlay_Strategy.h
│   ├── Random_Strategy.h
│   └── Sequential_Strategy.h
```

## Application Structure

- **Main.cpp**: Entry point of the application.
- **Music_Player_Application.h**: Core application logic.
- **Music_Player_Facade.h**: Facade pattern to simplify interaction with the music player system.
- **Audio_Engine.h**: Handles audio playback engine logic.
- **IAudio_Output_Device.h**: Interface for audio output devices.

### Key Folders

- **Audio_Adaptors/**: Contains adaptors for different audio output devices (Bluetooth, Headphones, Wired Speakers) using the Adaptor pattern.
- **Factories/**: Contains factory classes for device and strategy creation, implementing the Factory pattern.
- **Managers/**: Manages devices, playlists, and strategies. Device_Manager and Strategy_Manager are likely Singleton pattern implementations.
- **Models/**: Contains data models for Playlist and Song. Playlist uses an LRU cache-like structure with a doubly linked list for efficient song management.
- **Playing_Strategies/**: Contains different playback strategies (Sequential, Random, Custom) using the Strategy pattern. Some strategies may use LRU cache logic for recently played songs.

## Design Patterns Used

- **Strategy Pattern**: For implementing different song playing strategies (sequential, random, custom).
- **Factory Pattern**: For creating devices and strategies dynamically.
- **Singleton Pattern**: For managers that should have a single instance (e.g., Device_Manager, Strategy_Manager).
- **Adaptor Pattern**: For supporting multiple audio output devices with a common interface.
- **Facade Pattern**: To provide a simplified interface to the complex subsystems of the music player.

## Data Structures

- **LRU Cache (Doubly Linked List)**: Used in Playlist and some playing strategies to efficiently manage recently played songs and quick access/removal.

## How to Use

1. Clone the repository.
2. Open the project in your C++ IDE or editor.
3. Build and run `Main.cpp`.
4. Use the provided interfaces to interact with the music player, manage playlists, and switch between playback strategies and output devices.

---

**Note:** This project is for educational purposes and demonstrates the application of design patterns and data structures in a music player context.
