#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12  

void generate_password(char *password, int length) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
    int num_characters = sizeof(characters) - 1; 

    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % num_characters];
    }
    password[length] = '\0';
}

int main() {
    srand(time(NULL)); 
    char password[PASSWORD_LENGTH + 1];

    generate_password(password, PASSWORD_LENGTH);
    printf("Generated password: %s\n", password);

    return 0;
}
