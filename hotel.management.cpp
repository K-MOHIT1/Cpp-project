#include <iostream>
#include <string>

using namespace std;

const int MAX_ROOMS = 10;
const int MAX_GUESTS = 10;

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

    // Default constructor
    Guest() : name(""), roomNumber(0) {}

    // Parameterized constructor
    Guest(const string& guestName, int room) : name(guestName), roomNumber(room) {}
};

class Hotel {
private:
    Room rooms[MAX_ROOMS];
    Guest guests[MAX_GUESTS];
    int numRooms;
    int numGuests;

public:
    Hotel() : numRooms(0), numGuests(0) {
        // Initialize rooms
        for (int i = 1; i <= MAX_ROOMS; ++i) {
            rooms[i - 1] = Room(i);
            numRooms++;
        }
    }

    void addRoom() {
        if (numRooms < MAX_ROOMS) {
            rooms[numRooms++] = Room(numRooms + 1);
            cout << "Room added successfully!" << endl;
        } else {
            cout << "Cannot add more rooms. Maximum limit reached." << endl;
        }
    }

    void addGuest(const string& guestName, int roomNumber) {
        if (numGuests < MAX_GUESTS && roomNumber >= 1 && roomNumber <= numRooms && !rooms[roomNumber - 1].isOccupied) {
            rooms[roomNumber - 1].isOccupied = true;
            guests[numGuests++] = Guest(guestName, roomNumber);
            cout << "Guest added successfully!" << endl;
        } else {
            cout << "Cannot add guest. Invalid room number or maximum limit reached." << endl;
        }
    }

    void displayAvailableRooms() {
        cout << "Available Rooms:" << endl;
        for (int i = 0; i < numRooms; ++i) {
            const Room& room = rooms[i];
            if (!room.isOccupied) {
                cout << "Room " << room.number << " is available." << endl;
            }
        }
    }

    void displayGuests() {
        cout << "Guests:" << endl;
        for (int i = 0; i < numGuests; ++i) {
            const Guest& guest = guests[i];
            cout << "Name: " << guest.name << ", Room: " << guest.roomNumber << endl;
        }
    }
};

int main() {
    Hotel hotel;

    cout << "Welcome to the Simple Hotel Management System!" << endl;

    int choice;
    do {
        cout << "\nMenu:\n1. Display Available Rooms\n2. Book a Room\n3. Display Guests\n4. Add Room\n5. Add Guest\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayAvailableRooms();
                break;
            case 2: {
                string guestName;
                cout << "Enter your name: ";
                cin.ignore();  // Clear the newline character from the buffer
                getline(cin, guestName);
                int roomNumber;
                cout << "Enter the room number you want to book: ";
                cin >> roomNumber;
                hotel.addGuest(guestName, roomNumber);
                break;
            }
            case 3:
                hotel.displayGuests();
                break;
            case 4:
                hotel.addRoom();
                break;
            case 5: {
                string guestName;
                cout << "Enter guest's name: ";
                cin.ignore();  // Clear the newline character from the buffer
                getline(cin, guestName);
                int roomNumber;
                cout << "Enter the room number: ";
                cin >> roomNumber;
                hotel.addGuest(guestName, roomNumber);
                break;
            }
            case 6:
                cout << "Exiting the program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
