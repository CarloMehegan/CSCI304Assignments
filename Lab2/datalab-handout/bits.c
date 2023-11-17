/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */

#endif
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y)
{
  // use De Morgan's Law:
  // ~(A & B) = (~A | ~B)
  // therefore (A & B) = ~(~A | ~B)
  return ~(~x | ~y);
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x)
{
  // left shifting 31 bits puts the LSB in the signed bit place
  // arithmetic right shifting 31 bits will put the signed bit in every place
  return (x << 31) >> 31;
}

/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n)
{
  // we will shift the desired byte to the LSB position
  // we will shift by 0, 8, 16, or 24 bits
  int amountToShift = n << 3;

  // use 0xFF to retain just the byte we want to return in the result
  return (x >> amountToShift) & 0x000000FF;
}

/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y)
{
  // use XOR to detect differences between x and y
  return !(x ^ y);
}

/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit)
{
  // set all bits to 1
  int allOnes = ~0;

  // mask of 1s to the left of the high bit
  int left = (allOnes << highbit) << 1;

  // mask of 1s to the left and including the low bit
  int right = allOnes << lowbit;

  // by negating the left mask, we can get the
  // desired mask by looking at where the 1s overlap
  return (~left & right);
}

/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x)
{
  // just extract each byte, then combine them in reverse order
  // repetitive, but simplest method / most readable
  int byte1 = (x >> 24) & 0xFF;
  int byte2 = (x >> 16) & 0xFF;
  int byte3 = (x >> 8) & 0xFF;
  int byte4 = (x >> 0) & 0xFF;

  return (byte4 << 24) | (byte3 << 16) | (byte2 << 8) | byte1;
}

/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x)
{
  // We want to find if x is zero or not.
  // We can use the properties of twos complement to do this.

  // The only case where the sign bit does not change when we negate
  // a twos complement integer is when the integer is zero.
  //
  int signed_bit = (x | (~x + 1)) >> 31;

  // signed_bit = 0 when x is zero
  // signed_bit = 1 when x is nonzero

  return ~signed_bit & 1;
}

/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x)
{
  // we can use twos complement properties to solve this problem too.
  // because you add 1 to get the complement of a number,
  // the least significant 1 does not flip after conversion
  int inverted = x | (~x + 1);
  return inverted & x & (~inverted + 1);
}

/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
  // in two's complement, -1 is represented with all 1s
  return ~0;
}

/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void)
{
  // sign bit needs to be 0, and everything after is 1
  return ~(1 << 31);
}

/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n)
{
  int negN = ~n + 1;                      // negative n
  int shiftVal = 32 + negN;               // 32 - n
  int shiftLeft = x << shiftVal;          // discard bits that wouldnt fit
  int shiftRight = shiftLeft >> shiftVal; // attempt to restore value
  int same = shiftRight ^ x;              // check if any bits were discarded
  return !same;
}

/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y)
{
  // we can compare the sign bit to see if there was overflow
  int signed_bit_x = x >> 31;
  int signed_bit_y = y >> 31;

  int sum = x + y;
  int signed_bit_sum = sum >> 31;

  // if x and y have the same sign,
  // but the sum sign is different,
  // then there is overflow
  int x_y_different_signs = (signed_bit_x ^ signed_bit_y);
  int sum_x_different_signs = (signed_bit_x ^ signed_bit_sum);
  int overflow = (!x_y_different_signs) & sum_x_different_signs;

  return !overflow;
}

/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y)
{
  // we can compare sign bits again to solve this problem
  int signed_bit_x = x >> 31;
  int signed_bit_y = y >> 31;
  int different_signs = signed_bit_x ^ signed_bit_y;

  int diff = x + (~y); // difference between x and y
  int signed_bit_diff = diff >> 31;

  // if x and y have the same sign and their difference is negative, x < y
  int same_signs_negative_diff = (~different_signs) & signed_bit_diff;

  // if x and y have diff signs and x is negative, x < y
  int diff_signs_negative_x = different_signs & signed_bit_x;

  // if neither of these two statements are true, then x > y
  return !(same_signs_negative_diff | diff_signs_negative_x);
}

/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x)
{
  // simply look at the signed bit. if it is 1, then x is negative
  return (x >> 31) & 1;
}

/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x)
{
  int mult = (x << 2) + x; //multiply x by 5
  int rounding = mult >> 31 & 0x7; // get the sign for rounding
  
  int rounded = (mult + rounding) >> 3; //divide by 8

  return rounded;
}

/*
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x)
{
  // extend the sign bit to all bits.
  // If x is negative, signBit is all 1s; otherwise, signBit is all 0s
  int signBit = x >> 31;

  // a mask to remove sign bit
  int maskSignBit = ~(1 << 31);

  // get 2's complement for negative cases
  int reverse = ~(x & maskSignBit) + 1;

  // if positive or 0, return x; else, return reverse.
  return ((~signBit) & x) | (signBit & reverse);
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x)
{
  return 2;
}
