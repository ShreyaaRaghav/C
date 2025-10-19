#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define W 20
#define H 10

char canvas[H][W];

void clear() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            canvas[i][j] = '.';
        }
    }
}

void display() {
    printf("\n");
    for(int j = 0; j < W; j++) {
        printf("%2d", j);
    }
    printf("\n");

    for(int i = 0; i < H; i++) {
        printf("%2d ", i);
        
        for(int j = 0; j < W; j++) {
            printf("%c ", canvas[i][j]);
        } 
        printf("\n");   
    }
    printf("\n");   
}

int bounds(int x, int y) {
    return x>= 0 && x < W && y>=0 && y < H;
}

void draw(int x1, int y1, int x2, int y2) {
    if(!bounds(x1,y1) || !bounds(x2,y2)) {
        printf("Out of range Coordinates.\n");
        return;
    }

    if(x1==x2) { //vertical lines

        int start = y1<y2?y1:y2;   //This ensures the loop runs from top to bottom regardless of the order the points were given.
        int end = y1>y2?y1:y2;     // has to have run from smaller to larger

        for(int i = start; i <= end; i++) {
            canvas[i][x1] = '*';
        }
    }
    else if (y1 == y2) { // horizontal line

            int start = x1 < x2 ? x1 : x2;
            int end = x1 > x2 ? x1 : x2;
            for(int j = start; j <= end; j++)
                canvas[y1][j] = '*';
        } 
    
    else if (abs(x2-x1) == abs(y2 - y1)) { //diagonal
    int dx = x2>x1 ? 1 : -1;
    int dy = y2>y1 ? 1 : -1;
    int length = abs(x2 - x1);
    for(int i = 0; i <= length; i++) {
        canvas[y1 + i*dy][x1 + i*dx] = '*';
    }
}
    else {
            printf("Only horizontal or diagonal or vertical lines supported.\n");
    }
}

void erase(int x, int y) {
    if(!bounds(x,y)) {
        printf("Coordinates out of bounds!\n");
        return;
    }
    canvas[y][x] = '.';
}

//safely get an integer from the user, with input validation.

int getInt (const char *prompt) {
    char buffer[50];  //→ temporary storage for the user input as text.
    int value;  //→ variable to store the actual integer after conversion.

    while(1) {
        printf("%s", prompt);  //Prints whatever string was passed to the function.
        if(fgets(buffer, sizeof(buffer), stdin)) {

            //stdin → standard input (keyboard)
            //fgets includes the newline if the user presses Enter, but that’s fine
            //if ()checks that input was actually read

            if(sscanf(buffer, "%d", &value) == 1)  //like scanf but reads from a string instead of stdin.
                return value;

            //== 1 → exactly one integer was read successfully.
            // If successful, return value; → exit function and give back the integer.
        }
        printf("Invalid Input, try again.\n");
    }
}
//Read as string → try convert to int → if good return → if bad, loop again


int main() {
    char command[50];
    printf("=== Mini CAD Prototype ===\nCommands: start, draw, erase, display, exit\n");

    while(1) {
        printf("Enter Command: ");
        if(!fgets(command, sizeof(command), stdin))
            continue;
        command[strcspn(command, "\n")]=0;
        // remove newline

        if(strcmp(command, "start") == 0) {
            clear();
            display();
            printf("Canvas initialized.\n");
        }
        else if(strcmp(command, "draw") == 0) {
            printf("Drawing mode: Enter horizontal/diagonal/vertical lines.\n");

            while(1) {
                int x1 = getInt("Enter x1 (or -1 to stop): ");
                if(x1 == -1) break;
                int y1 = getInt("Enter y1: ");
                int x2 = getInt("Enter x2: ");
                int y2 = getInt("Enter y2: ");

                draw(x1, y1, x2, y2);
                display();
            }
        }
        else if(strcmp(command, "erase") == 0) {
            int x = getInt("Enter x to erase: ");
            int y = getInt("Enter y to erase: ");
            erase(x, y);
            display();
        }
        else if(strcmp(command, "display") == 0) {
            display();
        }
        else if(strcmp(command, "exit") == 0) {
            printf("Exiting Mini CAD. Goodbye!\n");
            break;
        }
        else {
            printf("Unknown command! Try again.\n");
        }
    }

    return 0;
}
