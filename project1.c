#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_ROUTES 10
#define MAX_STOPS 20
#define MAX_BUSES 10

// Structure for storing bus information
typedef struct {
    char name[50];
    char route[200];
    float distance;
    float fare;
    float travelTime;
} Bus;

// Structure for bus stops
typedef struct {
    char stopName[50];
    int stopID;
} Stop;

// Predefined Bus Stops
Stop stops[MAX_STOPS] = {
    {"Signboard", 0}, {"Jatrabari", 1}, {"Sayedabad", 2}, {"Maniknagor", 3},
    {"Basabo", 4}, {"Malibag", 5}, {"Rampura", 6}, {"Badda", 7}, {"Notun Bazar", 8},
    {"Kuril", 9}, {"Airport", 10}, {"Uttara", 11}, {"Abdullahpur", 12}, {"Gabtoli", 13},
    {"Mirpur 1", 14}, {"Mirpur 10", 15}, {"Kazipara", 16}, {"Shewrapara", 17},
    {"Farmgate", 18}, {"Motijheel", 19}
};

// Predefined Buses
Bus buses[MAX_BUSES] = {
    {"Anabil Super", "Gazipur Chowrasta - Signboard", 25.5, 50, 45},
    {"Thikana Express", "Jirani - Gulistan - Sayedabad", 30.2, 55, 50},
    {"Raida Enterprise", "Diabari - Jatrabari - Postogola", 27.8, 52, 47},
    {"Shikor Paribahan", "Mirpur - Jatrabari", 22.5, 45, 40},
    {"Alif", "Mirpur - Rampura - Banasree", 28.0, 53, 48},
    {"Prajapati & Konok", "Gabtoli - Uttara", 18.5, 38, 30},
    {"BRTC", "Gabtoli - Gulshan - Rampura", 32.5, 60, 55}
};

// Function to display welcome message
void displayWelcome() {
    printf("\n=========================================\n");
    printf("    Welcome to Bus Koi Software\n");
    printf("=========================================\n");
}

// Function to display available bus stops
void displayStops() {
    printf("\nAvailable Bus Stops:\n");
    for (int i = 0; i < MAX_STOPS; i++) {
        printf("%d. %s\n", stops[i].stopID, stops[i].stopName);
    }
}

// Function to validate user input
int isValidStop(int stopID) {
    return stopID >= 0 && stopID < MAX_STOPS;
}

// Function to calculate distance between two stops
float calculateDistance(int start, int end) {
    return abs(start - end) * 1.5; // Assuming 1.5 km per stop
}

// Function to calculate fare
float calculateFare(float distance) {
    return 10 + (distance * 2); // Base fare 10, then 2 per km
}

// Function to calculate estimated travel time
float calculateTravelTime(float distance) {
    return (distance / 25) * 60; // Assuming 25 km/h speed
}

// Function to find a bus for the route
Bus findBus(float distance) {
    for (int i = 0; i < MAX_BUSES; i++) {
        if (buses[i].distance >= distance) {
            return buses[i];
        }
    }
    return buses[0]; // Default bus
}

// Function to collect user feedback
void collectFeedback() {
    char feedback[200];
    printf("\nEnter your feedback about our service: ");
    getchar(); // Clear buffer
    fgets(feedback, sizeof(feedback), stdin);
    printf("Thank you for your valuable feedback!\n");
}

// Main function to handle user interaction
int main() {
    int start, end;
    displayWelcome();
    displayStops();

    // Get user input
    printf("\nEnter starting stop: ");
    scanf("%d", &start);
    printf("Enter destination stop: ");
    scanf("%d", &end);

    // Validate input
    if (!isValidStop(start) || !isValidStop(end)) {
        printf("\nInvalid stop selection. Please restart the program.\n");
        return 1;
    }

    // Calculate outputs
    float distance = calculateDistance(start, end);
    float fare = calculateFare(distance);
    float travelTime = calculateTravelTime(distance);
    Bus selectedBus = findBus(distance);

    // Display Results
    printf("\n============= Journey Details =============\n");
    printf("Starting Point: %s\n", stops[start].stopName);
    printf("Destination: %s\n", stops[end].stopName);
    printf("Estimated Distance: %.2f km\n", distance);
    printf("Bus Name: %s\n", selectedBus.name);
    printf("Route: %s\n", selectedBus.route);
    printf("Fare: %.2f BDT\n", fare);
    printf("Estimated Travel Time: %.2f minutes\n", travelTime);
    printf("============================================\n");

    // Collect feedback
    collectFeedback();

    // Display exit message
    printf("\nThanks for using our software!\n");
    

    return 0;
}
