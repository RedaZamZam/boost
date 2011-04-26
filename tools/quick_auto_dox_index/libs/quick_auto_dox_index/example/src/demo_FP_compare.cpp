/* \file demo_FP_compare.cpp
   \brief Demonstrate features of floating-point comparisons.
   
   /details Uses overflow-proof methods to find if values are close to each other,
    or are too small to be significantly different from zero.

    There are two criteria for closeness of floating-point comparison
    "Very close" and "Close enough" to a chosen tolerance.  Only default
    "Strong" that requires closeness relative to \b both values being compared is used.

  \author Paul A. Bristow
  \date Mar 2009
*/

// Copyright Paul A. Bristow 2008, 2009

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
  using std::cout;
  using std::cin;
  using std::endl;
  using std::dec;
  using std::hex;
  using std::boolalpha;
#include <iomanip>
  using std::setprecision;
  using std::setw;
#include <string>
  using std::string;
#include <limits>
  using std::numeric_limits;

#include "./detail/FP_compare.hpp"
#include "quick_auto_dox_index.hpp"

int main()
{
  cout << "Demo FP compare";

  cout << boolalpha << endl;

  // Check if a floating-point value is very close to zero, or exactly zero.
  // Sort of operator ~= (if such a thing was possible)

  // Use the default type double and the default small value 2 * min_value.
  smallest<> t_def; // double is default FP type.
  cout << t_def.size() << endl; // 4.45015e-308
  cout << "t(0) " << t_def(0) << endl; // true -  is *integer* zero.
  cout << "t(0.) " << t_def(0.) << endl; // true = really is zero.

  // Specify a default float value.
  smallest<float> tf;
  cout << "smallest<float> tf size = " << tf.size() << endl; // smallest<float> tf small = 2.35099e-038
  cout << " tf(1e-38F) " << tf(1e-38F) << endl; // Smaller than float min_value, so expect true ~= zero.
  cout << " tf(9.e-38F) " << tf(9.e-38F) << endl; // Larger than float min_value, so expect false != zero.

  // Specify a chosen small float value of 1e-10.
  smallest<float> tf10(1e-10F); // Note value must be a float - to match.
  cout << "smallest<float> tf10(1e-10); = " << tf10.size() << endl; // smallest<float> tf10(1e-10); = 1e-010

  cout << " tf10(1e-11F) " << tf10(1e-11F) << endl; // Smaller than float 1e-10, so expect true ~= zero.
  cout << " tf10(tf10(9.e-9F) " << tf10(9.e-9F) << endl; // Larger than float 1e-10, so expect false != zero.

  return 0;
}  // int main()


/*

Output:

demo_FP_compare.cpp
Linking...
Embedding manifest...
Autorun "i:\boost-sandbox\tools\quick_auto_dox_index\quick_auto_dox_index\Debug\quick_auto_dox_index.exe"
Demo FP compare
4.45015e-308
t(0) true
t(0.) true
smallest<float> tf size = 2.35099e-038
 tf(1e-38F) true
 tf(9.e-38F) false
smallest<float> tf10(1e-10); = 1e-010
 tf10(1e-11F) true
 tf10(tf10(9.e-9F) false
Build Time 0:01

*/



