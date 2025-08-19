#include <stdio.h>
#include <stdlib.h>

// Function declarations
void queue_menu();
void circular_queue_menu();
void deque_menu();

int main() {
    int choice;

    while(1) {
        printf("\nMain Menu:\n");
        printf("1. Normal Queue\n2. Circular Queue\n");
        printf("3. Double-Ended Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                queue_menu();
                break;
            case 2:
                circular_queue_menu();
                break;
            case 3:
                deque_menu();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
