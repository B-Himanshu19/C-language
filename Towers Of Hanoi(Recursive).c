#include <stdio.h>
void tower(int n, char source, char auxiliary, char destination) {
    if (n > 0) {
        tower(n - 1, source, destination, auxiliary);
        printf("Move disk %d from peg %c to peg %c\n", n, source, destination);
        tower(n - 1, auxiliary, source, destination);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    tower(n, 'A', 'B', 'C');
    return 0;
}
