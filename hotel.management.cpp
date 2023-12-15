#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_ROOMS = 10;
const int MAX_GUESTS = 10;

class Accommodation {
public:
    int number;
    double rate;

    Accommodation(int num, double rate) : number(num), rate(rate) {}
};

class Room : public Accommodation {
public:
    bool isOccupied;

    Room() : Accommodation(0, 0), isOccupied(false) {}  // Default constructor

    Room(int num, double rate) : Accommodation(num, rate), isOccupied(false) {}
};

class Guest : public Accommodation {
public:
    string name;
    int nights;

    Guest() : Accommodation(0, 0), nights(0) {}  // Default constructor

    Guest(const string& guestName, int num, int numNights) : Accommodation(num, 0), name(guestName), nights(numNights) {}
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
            rooms[i - 1] = Room(i, 100.0); // Room number and rate
            numRooms++;
        }
    }

    void displayAvailableRooms() {
        cout << "Available Rooms:" << endl;
        for (int i = 0; i < numRooms; ++i) {
            const Room& room = rooms[i];
            if (!room.isOccupied) {
                cout << "Room " << room.number << " - $" << fixed << setprecision(2) << room.rate << " per night" << endl;
            }
        }
    }

    void bookRoom() {
        cout << "Enter your name: ";
        string guestName;
        getline(cin, guestName);

        cout << "Enter the room number you want to book: ";
        int roomNumber;
        cin >> roomNumber;

        cout << "Enter the number of nights: ";
        int numNights;
        cin >> numNights;

        cin.ignore(); // Clear the newline character from the buffer

        for (int i = 0; i < numRooms; ++i) {
            Room& room = rooms[i];
            if (room.number == roomNumber && !room.isOccupied) {
                room.isOccupied = true;
                guests[numGuests++] = Guest(guestName, roomNumber, numNights);
                cout << "Room booked successfully!" << endl;
                return;
            }
        }
        cout << "Sorry, the selected room is not available." << endl;
    }

    void displayGuests() {
        cout << "Guests:" << endl;
        for (int i = 0; i < numGuests; ++i) {
            const Guest& guest = guests[i];
            cout << "Name: " << guest.name << ", Room: " << guest.number << ", Nights: " << guest.nights << endl;
        }
    }
};

int main() {
    Hotel hotel;

    // Display available rooms
    hotel.displayAvailableRooms();

    // Book a room
    hotel.bookRoom();

    // Display guests
    hotel.displayGuests();

    return 0;
}
