#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {
public:
    int number;
    bool isOccupied;

    // Default constructor
    Room() : number(0), isOccupied(false) {}

    // Parameterized constructor
    Room(int num) : number(num), isOccupied(false) {}
};

class Guest {
public:
    string name;
    int roomNumber;
    int nights;

    // Default constructor
    Guest() : name(""), roomNumber(0), nights(0) {}

    // Parameterized constructor
    Guest(const string& guestName, int room, int numNights) : name(guestName), roomNumber(room), nights(numNights) {}
};

class Hotel {
private:
    vector<Room> rooms;
    vector<Guest> guests;
    int numRooms;
    int numGuests;

public:
    Hotel() : numRooms(0), numGuests(0) {
        // Initialize with 10 rooms
        for (int i = 1; i <= 10; ++i) {
            rooms.push_back(Room(i));
            numRooms++;
        }
    }

    void addRoom() {
        rooms.push_back(Room(++numRooms));
        cout << "Room added successfully! Room number: " << numRooms << endl;
    }

    void bookRoom(const string& guestName) {
        cout << "Available Rooms:" << endl;
        displayAvailableRooms();

        int roomNumber;
        cout << "Enter the room number you want to book: ";
        cin >> roomNumber;

        if (roomNumber >= 1 && roomNumber <= numRooms && !rooms[roomNumber - 1].isOccupied) {
            int numNights;
            cout << "Enter the number of nights you want to stay: ";
            cin >> numNights;

            rooms[roomNumber - 1].isOccupied = true;
            guests.push_back(Guest(guestName, roomNumber, numNights));
            cout << "Room booked successfully for " << guestName << " in Room " << roomNumber << " for " << numNights << " nights." << endl;
            numGuests++;
        } else {
            cout << "Cannot book the room. Invalid room number or the room is already occupied." << endl;
        }
    }

    void displayAvailableRooms() {
        cout << "Available Rooms:" << endl;
        for (const Room& room : rooms) {
            if (!room.isOccupied) {
                cout << "Room " << room.number << endl;
            }
        }
    }

    void displayBookedGuests() {
        cout << "Booked Guests:" << endl;
        for (const Guest& guest : guests) {
            cout << "Name: " << guest.name << ", Room: " << guest.roomNumber << ", Nights: " << guest.nights << endl;
        }
    }
};

int main() {
    Hotel hotel;

    cout << "Welcome to the Hotel Management System!" << endl;

    int choice;
    do {
        cout << "\nMenu:\n1. Add Room\n2. Book a Room\n3. Display Available Rooms\n4. Display Booked Guests\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.addRoom();
                break;
            case 2: {
                string guestName;
                cout << "Enter guest's name: ";
                cin.ignore();  // Clear the newline character from the buffer
                getline(cin, guestName);
                hotel.bookRoom(guestName);
                break;
            }
            case 3:
                hotel.displayAvailableRooms();
                break;
            case 4:
                hotel.displayBookedGuests();
                break;
            case 5:
                cout << "Exiting the program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
