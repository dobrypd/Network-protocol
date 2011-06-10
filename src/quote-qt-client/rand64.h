#ifndef RAND64_H
#define RAND64_H

/*
   A C-program for MT19937-64 (2004/9/29 version).
   Coded by Takuji Nishimura and Makoto Matsumoto.

   This is a 64-bit version of Mersenne Twister pseudorandom number
   generator.

   Before using, initialize the state by using init_genrand64(seed)
   or init_by_array64(init_key, key_length).

   Copyright (C) 2004, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.
(...)
   Any feedback is very welcome.
   http://www.math.hiroshima-u.ac.jp/~m-mat/MT/emt.html
   email: m-mat @ math.sci.hiroshima-u.ac.jp (remove spaces)
*/


#include <stdio.h>
#include <QtGlobal>

#define NN 312
#define MM 156
#define MATRIX_A 0xB5026F5AA96619E9ULL
#define UM 0xFFFFFFFF80000000ULL /* Most significant 33 bits */
#define LM 0x7FFFFFFFULL /* Least significant 31 bits */

class rand64
{
public:
    rand64();
    quint64 next();
private:
    /* The array for the state vector */
    unsigned long long mt[NN];
    /* mti==NN+1 means mt[NN] is not initialized */
    int mti;

    /* initializes mt[NN] with a seed */
    void init_genrand64(unsigned long long seed);
    void init_by_array64(unsigned long long init_key[],
                         unsigned long long key_length);
    unsigned long long genrand64_int64(void);

    /* generates a random number on [0, 2^63-1]-interval */
    long long genrand64_int63(void);
    /* generates a random number on [0,1]-real-interval */
    double genrand64_real1(void);
    /* generates a random number on [0,1)-real-interval */
    double genrand64_real2(void);
    /* generates a random number on (0,1)-real-interval */
    double genrand64_real3(void);
};

#endif // RAND64_H
