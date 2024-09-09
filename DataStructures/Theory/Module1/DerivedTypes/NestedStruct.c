#include <stdio.h>

typedef struct {
  int month;
  int day;
  int year;
} DATE;

typedef struct {
  int hour;
  int min;
  int sec;
} TIME;

typedef struct {
  DATE date;
  TIME time;
} STAMP;

typedef struct {
  STAMP startTime;
  STAMP endTime;
} JOB;

int main() {
  // Initializing the JOB structure with nested STAMP, DATE, and TIME
  JOB job = { { {8, 18, 2014}, {8, 40, 50} }, { {8, 19, 2014}, {9, 30, 10} } };
    
  // Accessing members from the nested structures
  printf("Job Start Date: %02d/%02d/%d\n", job.startTime.date.month, job.startTime.date.day, job.startTime.date.year);
  printf("Job Start Time: %02d:%02d:%02d\n", job.startTime.time.hour, job.startTime.time.min, job.startTime.time.sec);
  printf("Job End Date: %02d/%02d/%d\n", job.endTime.date.month, job.endTime.date.day, job.endTime.date.year);
  printf("Job End Time: %02d:%02d:%02d\n", job.endTime.time.hour, job.endTime.time.min, job.endTime.time.sec);
    
  return 0;
}
