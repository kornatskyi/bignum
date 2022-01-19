#include "../include/BigInt.hpp"

/*

*** Comparison operators overloading ***

*/

/**
 * BigInt == BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator==(const BigInt &rhnumber) const {
  if (getSign() != rhnumber.getSign() ||
      getNumberOfDigits() != rhnumber.getNumberOfDigits()) {
    return false;
  }

  for (int i = 0; i < getNumberOfDigits(); i++) {
    if (getDigit(i) != rhnumber.getDigit(i)) {
      return false;
    }
  }
  return true;
}

/**
 * BigInt > BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator>(const BigInt &rhnumber) const {
  if (getSign() && !rhnumber.getSign()) {
    return true;
  }
  if (!getSign() && rhnumber.getSign()) {
    return false;
  }

  if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
    return getSign() ? true : false;
  }

  if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
    return getSign() ? false : true;
  }

  for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
    if (getDigit(i) < rhnumber.getDigit(i)) {
      return getSign() ? false : true;
    }
    if (getDigit(i) > rhnumber.getDigit(i)) {
      return getSign() ? true : false;
    }
  }
  return false;
}

/**
 * BigInt < BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator<(const BigInt &rhnumber) const {
  if (getSign() && !rhnumber.getSign()) {
    return false;
  }
  if (!getSign() && rhnumber.getSign()) {
    return true;
  }

  if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
    return getSign() ? false : true;
  }

  if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
    return getSign() ? true : false;
  }

  for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
    if (getDigit(i) < rhnumber.getDigit(i)) {
      return getSign() ? true : false;
    }
    if (getDigit(i) > rhnumber.getDigit(i)) {
      return getSign() ? false : true;
    }
  }
  return false;
}
/**
 * BigInt != BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator!=(const BigInt &rhnumber) const {
  if (getSign() != rhnumber.getSign() ||
      getNumberOfDigits() != rhnumber.getNumberOfDigits()) {
    return true;
  }

  for (int i = 0; i < getNumberOfDigits(); i++) {
    if (getDigit(i) != rhnumber.getDigit(i)) {
      return true;
    }
  }
  return false;
}
/**
 * BigInt <= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator<=(const BigInt &rhnumber) const {
  if (getSign() && !rhnumber.getSign()) {
    return false;
  }
  if (!getSign() && rhnumber.getSign()) {
    return true;
  }

  if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
    return getSign() ? false : true;
  }

  if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
    return getSign() ? true : false;
  }

  for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
    if (getDigit(i) < rhnumber.getDigit(i)) {
      return getSign() ? true : false;
    }
    if (getDigit(i) > rhnumber.getDigit(i)) {
      return getSign() ? false : true;
    }
  }
  return true;
}
/**
 * BigInt >= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator>=(const BigInt &rhnumber) const {
  if (getSign() && !rhnumber.getSign()) {
    return true;
  }
  if (!getSign() && rhnumber.getSign()) {
    return false;
  }

  if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
    return getSign() ? true : false;
  }

  if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
    return getSign() ? false : true;
  }

  for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
    if (getDigit(i) < rhnumber.getDigit(i)) {
      return getSign() ? false : true;
    }
    if (getDigit(i) > rhnumber.getDigit(i)) {
      return getSign() ? true : false;
    }
  }
  return true;
}

/*

*** Comparison methods ***

*/

// bool BigInt::isEqualTo(const BigInt rhnumber) const {

//   if (getSign() != rhnumber.getSign() ||
//       getNumberOfDigits() != rhnumber.getNumberOfDigits()) {
//     return false;
//   }

//   for (int i = 0; i < getNumberOfDigits(); i++) {
//     if (getDigit(i) != rhnumber.getDigit(i)) {
//       return false;
//     }
//   }
//   return true;
// }

// bool BigInt::isMoreThen(const BigInt rhnumber) const {

//   if (getSign() && !rhnumber.getSign()) {
//     return true;
//   }
//   if (!getSign() && rhnumber.getSign()) {
//     return false;
//   }

//   if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
//     return getSign() ? true : false;
//   }

//   if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
//     return getSign() ? false : true;
//   }

//   for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
//     if (getDigit(i) < rhnumber.getDigit(i)) {
//       return getSign() ? false : true;
//     }
//     if (getDigit(i) > rhnumber.getDigit(i)) {
//       return getSign() ? true : false;
//     }
//   }
//   return false;
// }

// bool BigInt::isLessThen(const BigInt rhnumber) const {

//   if (getSign() && !rhnumber.getSign()) {
//     return false;
//   }
//   if (!getSign() && rhnumber.getSign()) {
//     return true;
//   }

//   if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
//     return getSign() ? false : true;
//   }

//   if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
//     return getSign() ? true : false;
//   }

//   for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
//     if (getDigit(i) < rhnumber.getDigit(i)) {
//       return getSign() ? true : false;
//     }
//     if (getDigit(i) > rhnumber.getDigit(i)) {
//       return getSign() ? false : true;
//     }
//   }
//   return false;
// }

// bool BigInt::notEqualTo(const BigInt rhnumber) const {

//   if (getSign() != rhnumber.getSign() ||
//       getNumberOfDigits() != rhnumber.getNumberOfDigits()) {
//     return true;
//   }

//   for (int i = 0; i < getNumberOfDigits(); i++) {
//     if (getDigit(i) != rhnumber.getDigit(i)) {
//       return true;
//     }
//   }
//   return false;
// }

// bool BigInt::isLessOrEqualTo(const BigInt rhnumber) const {
//   if (getSign() && !rhnumber.getSign()) {
//     return false;
//   }
//   if (!getSign() && rhnumber.getSign()) {
//     return true;
//   }

//   if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
//     return getSign() ? false : true;
//   }

//   if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
//     return getSign() ? true : false;
//   }

//   for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
//     if (getDigit(i) < rhnumber.getDigit(i)) {
//       return getSign() ? true : false;
//     }
//     if (getDigit(i) > rhnumber.getDigit(i)) {
//       return getSign() ? false : true;
//     }
//   }
//   return true;
// }

// bool BigInt::isMoreOrEqualTo(const BigInt rhnumber) const {
//   if (getSign() && !rhnumber.getSign()) {
//     return true;
//   }
//   if (!getSign() && rhnumber.getSign()) {
//     return false;
//   }

//   if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
//     return getSign() ? true : false;
//   }

//   if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
//     return getSign() ? false : true;
//   }

//   for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
//     if (getDigit(i) < rhnumber.getDigit(i)) {
//       return getSign() ? false : true;
//     }
//     if (getDigit(i) > rhnumber.getDigit(i)) {
//       return getSign() ? true : false;
//     }
//   }
//   return true;
// }