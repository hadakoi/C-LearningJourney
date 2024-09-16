#include <stdio.h>

#define SIZE 6  // Max size of the queue

// Enum for vehicle types with associated priorities
typedef enum {
  PUB = 6,     // Public vehicle
  GOVT = 7,    // Government vehicle
  POL = 8,     // Police vehicle
  MLA = 9,     // MLA vehicle
  MP = 10,     // MP vehicle
  PRES = 11,   // President vehicle
  SCL = 12,    // School vehicle
  FIRE = 13,   // Fire vehicle
  EMR = 14     // Emergency vehicle
} VehicleType;

// Queue array and rear pointer
VehicleType q[SIZE];
int r = -1;  // Rear pointer (initially set to -1)
#define Max SIZE

// Insert function to add a vehicle to the queue
void insert(VehicleType c) {
  if (r == Max - 1)
    printf("No space\n");
  else
    q[++r] = c;
}

// Move out the vehicle with the highest priority and shift others
VehicleType moved_out() {
  VehicleType b = q[0];
  int i, p = 0;

  if (r < 0) {
    printf("No vehicle in the queue\n");
    return -1; // Indicates an error
  }

  for (i = 1; i <= r; i++) {
    if (q[i] > b) {
      b = q[i];
      p = i;
    }
  }

  for (i = p; i < r; i++)
    q[i] = q[i + 1];

  r--;
  return b;
}

void print_vehicle(VehicleType v) {
  switch (v) {
    case PUB: printf("The vehicle moved is Public\n"); break;
    case GOVT: printf("The vehicle moved is Government\n"); break;
    case POL: printf("The vehicle moved is Police\n"); break;
    case MLA: printf("The vehicle moved is MLA\n"); break;
    case MP: printf("The vehicle moved is MP\n"); break;
    case PRES: printf("The vehicle moved is President\n"); break;
    case SCL: printf("The vehicle moved is School\n"); break;
    case FIRE: printf("The vehicle moved is Fire\n"); break;
    case EMR: printf("The vehicle moved is Emergency\n"); break;
    default: printf("Unknown vehicle\n"); break;
  }
}

int main() {
  int c;
  VehicleType code;
  char y;

  do {
    printf("1: Insert\t 2: Moved_out\t 3: CaptureTraffic\n");
    scanf("%d", &c);

    switch (c) {
      case 1:
        printf("Enter the vehicle code (0-8):\n");
        scanf("%d", &code);
        if (code < 0 || code > 8) {
          printf("Invalid vehicle code.\n");
        } 
        else {
          insert((VehicleType)code);
        }
        break;

      case 2:
        code = moved_out();
        if (code != -1) {
          print_vehicle(code);
        }
        break;

      case 3:
        // Implement CaptureTraffic() if needed
        printf("CaptureTraffic function not implemented.\n");
        break;

      default:
        printf("Invalid option.\n");
        break;
    }

    printf("Do you want to continue? (Y/N)\n");
    scanf(" %c", &y);
  } while (y == 'Y' || y == 'y');

  return 0;
}
