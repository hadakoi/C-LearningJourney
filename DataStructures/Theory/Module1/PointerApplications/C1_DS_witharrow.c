#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *Month;
    int days;
    char *Activities;
} MonthEvents;

void inputEvents(MonthEvents **events, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the month for event %d: ", i + 1);
        scanf("%s", events[i]->Month);

        printf("Enter the activities for event %d: ", i + 1);
        scanf("%s", events[i]->Activities);
    }
}

void modifyEvent(MonthEvents **events, int index, char *newActivities) {
    events[index]->Activities = newActivities; 
}

int main() {
    // Allocate memory for 30 MonthEvents pointers
    MonthEvents **events = (MonthEvents**)malloc(30 * sizeof(MonthEvents*));

    for (int i = 0; i < 30; i++) {
        events[i] = (MonthEvents*)malloc(sizeof(MonthEvents)); 
        events[i]->Month = (char*)malloc(100 * sizeof(char));
        events[i]->Activities = (char*)malloc(100 * sizeof(char)); 
    }

    int count;
    printf("How many events do you want to input? ");
    scanf("%d", &count);

    inputEvents(events, count);

    printf("\nEvents after input:\n");
    for (int i = 0; i < count; i++) {
        printf("Event %d -> Month: %s, Activities: %s\n", 
               i + 1, events[i]->Month, events[i]->Activities);
    }

    int index;
    char *newActivities = (char*)malloc(100 * sizeof(char));

    printf("\nWhich event's activities do you want to modify (index 1 to 30)? ");
    scanf("%d", &index);
    index--;

    printf("Enter new activities for event %d: ", index + 1);
    scanf("%s", newActivities);

    modifyEvent(events, index, newActivities);

    printf("\nEvents after modification:\n");
    for (int i = 0; i < count; i++) {
        printf("Event %d -> Month: %s, Activities: %s\n", 
               i + 1, events[i]->Month, events[i]->Activities);
    }

    for (int i = 0; i < 30; i++) {
        free(events[i]->Month);
        free(events[i]->Activities);
        free(events[i]);
    }
    free(events);

    return 0;
}
