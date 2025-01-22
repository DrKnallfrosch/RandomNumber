#include <stdio.h>
#include <stdint.h>
#include <time.h>

/**
 * Generates a pseudo-random number using the Linear Congruential Generator (LCG) algorithm.
 *
 * This function utilizes the standard LCG formula to generate a pseudo-random number
 * based on the provided seed. The result is a value constrained within the range of
 * 1 to the specified upper limit, inclusive. The seed is updated with each calculation
 * to ensure the sequence of numbers generated is deterministic and repeatable given the same initial seed.
 *
 * @param seed A pointer to a 32-bit unsigned integer representing the current seed
 *             value. This value is updated during each call to the function.
 * @param upLimit An integer specifying the upper limit (inclusive) of the generated
 *                random number's range. The result will be within the range [1, upLimit].
 * @return A 32-bit unsigned integer representing the generated random number,
 *         constrained within the range [1, upLimit].
 */
uint32_t lcg_random(uint32_t *seed, const int upLimit) {
    // Constants for LCG
    #define MULTIPLIER 1664525 // Multiplier constant for the LCG algorithm
    #define INCREMENT 1013904223 // Increment constant for the LCG algorithm
    #define MODULUS 4294967296 // Modulus value for the LCG (2^32)

    // Update the seed using the LCG formula: (a * seed + c) % m
    *seed = (MULTIPLIER * (*seed) + INCREMENT) % MODULUS;

    // Return a value in the range [1, upLimit] (inclusive)
    return (*seed % upLimit) + 1;
}

/**
 * Generates a seed value based on the current system time in milliseconds.
 *
 * This function retrieves the current time, calculates the number of milliseconds
 * since the Unix epoch, and returns it as a 32-bit unsigned integer. It can be
 * used to provide an initial seed value for random number generation.
 *
 * @return A 32-bit unsigned integer representing the number of milliseconds
 *         since the Unix epoch.
 */
uint32_t seedByTime() {
    // Get current time in milliseconds
    struct timeval tv; // Struct to store time values

    // Retrieve the current time since the Unix epoch (seconds and microseconds)
    clock_gettime(CLOCK_REALTIME, &tv);

    // Compute the number of milliseconds since the Unix epoch
    uint32_t millisecondsSinceEpoch = (uint32_t) (tv.tv_sec) * 1000 + (uint32_t) (tv.tv_usec) / 1000;

    return millisecondsSinceEpoch; // Return the milliseconds as a seed value
}
