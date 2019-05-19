/*
 * 2019 Spring Compiler Course Assignment 2 
 */

float c = 150;
float c = 1.5 ;

bool loop (int n, float m) {
    while (n > m) {
        n--;
    }
    return true;
}

int main() {
    // Declaration
    int x;
    int i;
    int a = 5;
    string y = "She is a girl";

    print(y); // print

    // if condition
    if (a > 10) {
        x += a;
        int i;
        print(x);     
    } else {
        x = a % 10 + 10 * 7; /* Arithmetic */
        print(x);
    }

    float a;
    loop(x, i);
    print("Hello World");

    return 0; 
}
