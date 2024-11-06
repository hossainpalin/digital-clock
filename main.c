#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void fill_time(char*, int);
void fill_date(char*);
void clear_screen();

int main() {
    char time[50], date[100];
    int format;

    printf("Choose the time format: ");
    printf("\n1. 24 Hour format");
    printf("\n2. 12 Hour format");
    printf("\nMake a choice(1/2): ");

    scanf("%d", &format);

    while (1) {
        fill_time(time, format);
        fill_date(date);
        clear_screen();
        printf("\nCurrent Time: %s", time);
        printf("\nDate: %s", date);

        sleep(1);
    }

    return 0;
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void fill_date(char* buffer) {
    time_t raw_time;
    struct tm* current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    strftime(buffer, 100, "%A %B %d %Y", current_time);
}

void fill_time(char* buffer, int format) {
    time_t raw_time;
    struct tm* current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);

    if (format == 1) {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    } else {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
};
