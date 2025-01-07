//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pencode_core.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 07-Jan-2025 12:52:27
//

// Include Files
#include "pencode_core.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// Arguments    : const double d[128]
//                double x[128]
// Return Type  : void
//
void pencode_core(const double d[128], double x[128])
{
  std::copy(&d[0], &d[128], &x[0]);
  for (int i{0}; i < 7; i++) {
    int B;
    int nB;
    int q_tmp;
    unsigned int u;
    B = static_cast<int>(1U << static_cast<unsigned int>(7 - i));
    nB = static_cast<int>(1U << static_cast<unsigned int>(i));
    q_tmp = static_cast<int>(static_cast<unsigned int>(B) >> 1);
    u = static_cast<unsigned int>(B) - (static_cast<unsigned int>(q_tmp) << 1);
    for (int j{0}; j < nB; j++) {
      int base;
      int q;
      base = j * B - 1;
      q = q_tmp;
      if (u > 0U) {
        q = static_cast<int>(static_cast<unsigned int>(q_tmp) + 1U);
      }
      for (int l{0}; l < q; l++) {
        double b_x;
        int x_tmp;
        int xi;
        xi = q_tmp;
        if (u > 0U) {
          xi = static_cast<int>(static_cast<unsigned int>(q_tmp) + 1U);
        }
        x_tmp = (base + l) + 1;
        b_x = x[x_tmp] + x[((base + xi) + l) + 1];
        xi = static_cast<int>(std::round(b_x));
        if (xi == b_x) {
          xi -= (xi >> 1) << 1;
        } else {
          double r;
          if (std::isnan(b_x) || std::isinf(b_x)) {
            r = rtNaN;
          } else if (b_x == 0.0) {
            r = 0.0;
          } else {
            r = std::fmod(b_x, 2.0);
            if (r == 0.0) {
              r = 0.0;
            } else if (b_x < 0.0) {
              r += 2.0;
            }
          }
          xi = static_cast<int>(std::round(r));
        }
        x[x_tmp] = xi;
      }
    }
  }
}

//
// File trailer for pencode_core.cpp
//
// [EOF]
//
