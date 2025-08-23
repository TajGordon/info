/*
 * Solution Template for Atlantis III: Twin Rivers
 * 
 * Australian Informatics Olympiad 2024
 * 
 * This file is provided to assist with reading of input and writing of output
 * for the problem. You may modify this file however you wish, or
 * you may choose not to use this file at all.
 */

#include <cstdio>

/* N is the number of bridges. */
int N;

/* L is the length of the city. */
int L;

/*
 * B and R describe the bridges. Note that the arrays start from 0, and so the
 * bridges are (B[0], R[0]) to (B[N-1], R[N-1]).
 */
long long B[200005];
int R[200005];

/* T is the number of trips. */
int T;

/*
 * X and S describe the trips. Note that the arrays start from 0, and so the
 * trips are (X[0], S[0]) to (X[T-1], S[T-1]).
 */
long long X[200005];
int S[200005];

long long answer;
int main(void) {
    /* Read the values of N, L, B, R, T, X, and S from input file. */
    scanf("%d%d", &N, &L);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &B[i]);
        scanf("%d", &R[i]);
    }

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%lld", &X[i]);
        scanf("%d", &S[i]);
    }

    /*
     * TODO: This is where you should compute your solution. Store the smallest
     * possible sum of trip distances you can achieve after building one more
     * bridge into the variable answer.
     */

    /*
     * Please note that the answer may exceed the maximum value
     * that can be stored in an "int" integer type.
     * Because of this, you should use the "long long" integer type
     * instead of "int" when computing your solution.
     */

    /* Write the answer to the output file. */
    printf("%lld\n", answer);

    return 0;
}
