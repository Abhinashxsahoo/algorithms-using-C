#include <stdio.h>
#include <string.h>
#define d 256  // Total number of characters in ASCII
#define q 101  // A prime number to minimize hash collisions
void rabinKarp(char pat[], char txt[]) {
    int M = strlen(pat);  // Length of the pattern
    int N = strlen(txt);  // Length of the text 
    int patternHash = 0;  // Hash value for pattern
    int textHash = 0;     // Hash value for the current window of text
    int h = 1;            // Multiplier for the highest place value in the hash
    for (int i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }
    for (int i = 0; i < M; i++) {
        patternHash = (d * patternHash + pat[i]) % q;
        textHash = (d * textHash + txt[i]) % q;
    }
    for (int i = 0; i <= N - M; i++) {
        if (patternHash == textHash) {
            int match = 1;
            for (int j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Pattern found at index %d\n", i);
            }
        }
        if (i < N - M) {
            textHash = (d * (textHash - txt[i] * h) + txt[i + M]) % q;
            if (textHash < 0) {
                textHash = (textHash + q);
            }
        }
    }
}
int main() {
    char txt[] = "ABCCDDAEFG";
    char pat[] = "CDD";
    
    rabinKarp(pat, txt);
    return 0;
}