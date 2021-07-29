/*
 * Copyright:   2021 Johnathon Leong
 *
 * License:     License under LGPL-3.0-or-later.
 *              Please refer to https://www.gnu.org/licenses/lgpl-3.0.txt for more information on the
 *              terms of LGPL-3.0 or relavent website for a later version of the LGPL.
 *
 * Disclaimer:  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY
 *              EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *              OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 *              SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *              INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *              TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *              BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *              CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 *              WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Author:      Johnathon Leong
 *
 * Note:
 *
 * Version:     1.0.0
 * Date:        2021/07/29 (YYYY/MM/DD)
 * Change Log:  1. Implemented "shuffle()" functions for various data type arrays.
 *              2. Implemented "version()" function.
 */

#include "genericlibrarymaths.h"
#include <time.h>

#define GENERICLIBRARYMATHS_VERSION_MAJOR 1
#define GENERICLIBRARYMATHS_VERSION_MINOR 0
#define GENERICLIBRARYMATHS_VERSION_PATCH 0

// ============================================================================================== //
// START OF: PRIVATE FUNCTIONS                                                                    //
// ============================================================================================== //
/**
 * @brief seedRand  Seed the pseudo random generator.
 * @return          Return flag to indicate if the random generator has been seeded.
 */
unsigned char seedRand(void) {
  static unsigned char flagIsSeeded = 0;
  if (flagIsSeeded == 0) {
    srand(time(NULL));
    flagIsSeeded = 1;
  }
  return flagIsSeeded;
} //  unsigned char seedRand(void) -----------------------------------------------------------------

/**
 * @brief swap - Swap the values of variables a and b.
 * @param a    - First variable whose value is to be swapped.
 * @param b    - Second variable whose value is to be swapped.
 */
template <typename T>
void swap(T & a, T & b) {
   T t = a;
   a = b;
   b = t;
} //  void swap(unsigned long long & a, unsigned long long & b); -----------------------------------

/**
 * @brief shuffle   - Shuffle the numbers in a template data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
template <typename T>
void shuffle(T * array, unsigned long long arraySize) {
  unsigned long long index = 0;
  unsigned long long i = 0;

  seedRand();

  switch(arraySize) {
  case 0:
    break;

  case 1:
    break;

  case 2:
    swap(array[0], array[1]);
    break;

  default:
    for (i = 0; i < arraySize; i++) {
      while(1) {
        index = rand() % arraySize;
        if (index != i)
          break;
      }
      swap(array[i], array[index]);
    }
    break;
  }
} //  void shuffle(unsigned long * array, unsigned long arraySize); --------------------------------

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
// END OF: PRIVATE FUNCTIONS                                                                      //
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

// ============================================================================================== //
// START OF: PUBLIC FUNCTIONS                                                                     //
// ============================================================================================== //
/**
 * @brief shuffle   - Shuffle the numbers in a char data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(char * array, unsigned long long arraySize) {
  shuffle<char>(array, arraySize);
} // void shuffle(char * array, unsigned long long arraySize) --------------------------------------

/**
 * @brief shuffle   - Shuffle the numbers in a double data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(double * array, unsigned long long arraySize) {
  shuffle<double>(array, arraySize);
} // void shuffle(double * array, unsigned long long arraySize) ------------------------------------

/**
 * @brief shuffle   - Shuffle the numbers in a float data type  array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(float * array, unsigned long long arraySize) {
  shuffle<float>(array, arraySize);
} // void shuffle(float * array, unsigned long long arraySize) -------------------------------------

/**
 * @brief shuffle   - Shuffle the numbers in a long data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(long * array, unsigned long long arraySize) {
  shuffle<long>(array, arraySize);
} // void shuffle(long * array, unsigned long long arraySize) --------------------------------------

/**
 * @brief shuffle   - Shuffle the numbers in a long long data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(long long * array, unsigned long long arraySize) {
  shuffle<long long>(array, arraySize);
} // void shuffle(long long * array, unsigned long long arraySize) ---------------------------------

/**
 * @brief shuffle   - Shuffle the numbers in a short data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(short * array, unsigned long long arraySize) {
  shuffle<short>(array, arraySize);
} // void shuffle(short * array, unsigned long long arraySize) -------------------------------------

/**
 * @brief shuffle   - Shuffle the numbers in an unsigned char data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(unsigned char * array, unsigned long long arraySize) {
  shuffle<unsigned char>(array, arraySize);
} // void shuffle(unsigned char * array, unsigned long long arraySize) -----------------------------

/**
 * @brief shuffle   - Shuffle the numbers in an unsigned long data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(unsigned long * array, unsigned long long arraySize) {
  shuffle<unsigned long>(array, arraySize);
} // void shuffle(unsigned long * array, unsigned long long arraySize) -----------------------------

/**
 * @brief shuffle   - Shuffle the numbers in an unsigned long long data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(unsigned long long * array, unsigned long long arraySize) {
  shuffle<unsigned long long>(array, arraySize);
} // void shuffle(unsigned long lon * array, unsigned long long arraySize) -------------------------

/**
 * @brief shuffle   - Shuffle the numbers in an unsigned short data type array.
 * @param array     - Array that contains the numbers to be shuffled.
 * @param arraySize - Specify the array size.
 */
void shuffle(unsigned short * array, unsigned long long arraySize) {
  shuffle<unsigned short>(array, arraySize);
} // void shuffle(unsigned short * array, unsigned long long arraySize) ----------------------------

/**
 * @brief genericlibrarymaths_version - Check the version of this library
 * @param major                       - Major version number.
 * @param minor                       - Minor version number.
 * @param patch                       - Patch version number.
 */
void genericlibrarymaths_version(unsigned long & major, unsigned long & minor, unsigned long & patch) {
  major = GENERICLIBRARYMATHS_VERSION_MAJOR;
  minor = GENERICLIBRARYMATHS_VERSION_MINOR;
  patch = GENERICLIBRARYMATHS_VERSION_PATCH;
} // void genericlibrarymaths_version(unsigned long & major, unsigned long & minor, unsigned long & patch)

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
// END OF: PUBLIC FUNCTIONS                                                                       //
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
