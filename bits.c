/***********************************************************************
* Program:
*    Lab Datalab
*    Brother Jones, ECEN 324
* Author:
*    Your Name
* Summary:
*    descriptive text
***********************************************************************/

/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *          Even though you may work as a team, all students should
 *          individually submit a solution.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID (Linux Lab username) if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member.
       Example: joestudent+zmename */
    "mpbhome+joeford", 
   /* Student name 1: Replace with the name of first team member */
   "Matthew Brown",
   /* Login ID 1: Replace with the login ID of first team member */
   "mpbhome",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Name of the second team member */
   "Jarom Weatherford",
   /* Login ID 2: Login ID of the second team member */
   "joeford"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
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

  Note that in order to make the dlc (data lab checker) happy you need
  to declare all variables at the first of the function.
      dlc happy with:                 dlc not happy with:
      ---------------                 -------------------
      int Funct( arg1, arg2) {          int Funct( arg1, arg2) {
         int varA = ~0;                    int varA = ~0;
         int varB = 1;                     varA = varA + 4;
         varA = varA + 4;                  int varB = 1;
          ...                               ...

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
     NOTE: You may create big constants using code.  
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
     NOTE: You may define additional functions while you are working to
           solve the problems, but the final submission should not have any.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
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


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
           //Nor is true when x and y are both false, not x and not y
           return (~x & ~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
   //Xor is x && !y || y && !x, convert that to & and ~ and here you go



   return ~(~(~x & y) & ~(x & ~y));

}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
   //Xor them, any difference would show a 1, ! to make it 0 or 1,
   //! again to return it to != rather than ==
   return !!(x ^ y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
   //shift the byte left to the edge of the word, then right to the other
   //edge.
   int sizeSansOne = sizeof(int) - 1;
   return (((unsigned)x << ((sizeSansOne - n) * 8)) >> (sizeSansOne * 8));
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
   //shift left by the word size - 1, then right again to drop all but LSB
   return x << 31 >> 31;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
   //shift one, quarantee the leftmost bit is 0, shift n - 1
   int mask = 0xff;
   int result = 0;
   int negativeOne = 0;
   mask = mask | (mask << 8);
   negativeOne = mask | (mask << 16);
   mask = mask | (mask << 15);
   result = ((x >> 1) & mask) >> (n + negativeOne);
   return result;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
   //mask bits and add them in bytes, then mask bytes and add them into an int
   int bitSum = 0;
   int bitMask = 0x01;
   int byteSum = 0;
   int byteMask = 0xff;
   bitMask = bitMask | (bitMask << 8);
   bitMask = bitMask | (bitMask << 16);
   bitSum = bitSum + (x & bitMask);
   x = x >> 1;
   bitSum = bitSum + (x & bitMask);
   x = x >> 1;
   bitSum = bitSum + (x & bitMask);
   x = x >> 1;
   bitSum = bitSum + (x & bitMask);
   x = x >> 1;
   bitSum = bitSum + (x & bitMask);
   x = x >> 1;
   bitSum = bitSum + (x & bitMask);
   x = x >> 1;
   bitSum = bitSum + (x & bitMask);
   x = x >> 1;
   bitSum = bitSum + (x & bitMask);

   byteSum = byteSum + (bitSum & byteMask);
   bitSum = bitSum >> 8;
   byteSum = byteSum + (bitSum & byteMask);
   bitSum = bitSum >> 8;
   byteSum = byteSum + (bitSum & byteMask);
   bitSum = bitSum >> 8;
   byteSum = byteSum + (bitSum & byteMask);
   bitSum = bitSum >> 8;
   return byteSum;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
   //Split into two half ints and check for overflow when added to 1's
   int mask = 0xff | (0xff << 8);
   int y = (((x) >> 16) & mask) + mask;
   int z = ((x) & mask) + mask;
   int result = (y | z) >> 16;
   result = (~result) & 1;
   return result;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
   //Adding to 1's yields all the same as x to the left of the first 1 and
   //all different at and to the right of it, xor that with x yields 0's
   //to the left of the first 1 and 1's at and to the right, since you
   //know that it's the first 1, and-ing with that mask will yield 0's to
   //the left and 0's to the right.
   int mask = ~0;
   return (((x + mask) ^ x) & x);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
   //shift one to the left to get 0x80000000 then invert
   return ~(1 << 31);
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
   //if it's positive the shift will leave all 0's, negative leaves all 1's
   return !(x >> 31);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
   int diff = x ^ y;
   int rightMask = diff | diff >> 1;
   rightMask = diff | diff >> 2;
   rightMask = diff | diff >> 4;
   rightMask = diff | diff >> 8;
   rightMask = diff | diff >> 16;
   int leftMask = ~(rightMask >> 1) | (1 << 31);
   int firstDiffMask = rightMask & leftMask;
   int greaterMask = firstDiffMask & (x ^ (1 << 31)) & (y ^ ~(1 << 31));
   int isGreater = !!greaterMask;
  return isGreater;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
   //Conditional 1 and -1 used to bias only if x is negative, then shift
   int conNegOne = x >> 31;
   int isNeg = conNegOne & 1;
   int result = (x + (isNeg << n) + conNegOne) >> n;
   return result;
}
/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
   // Select which value is returned by applying a mask to x and
   // negated x. 
   int negated, posMask, negMask;

   negMask = x >> 31;

   posMask = ~negMask;
   negated = (~x + 1) & negMask;
   x = x & posMask;

   return x + negated;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
   //Check for different signs or if the sign doesn't change when added.
   int diff = !!((x ^ y) >> 31);
   int sumNeg = (x + y) >> 31;
   int neg = x >> 31;
   int sameSign = !(neg ^ sumNeg);

   return diff | sameSign;
}
