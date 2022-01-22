#include "BigInt.hpp"

/*

*** Comparison operators overloading ***

*/

/**
 * BigInt == BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator==(const BigInt &rhnumber) const {
  if (getSign() != rhnumber.getSign() || length() != rhnumber.length()) {
    return false;
  }

  for (int i = 0; i < length(); i++) {
    if (getNthLSD(i) != rhnumber.getNthLSD(i)) {
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

  if (length() > rhnumber.length()) {
    return getSign() ? true : false;
  }

  if (length() < rhnumber.length()) {
    return getSign() ? false : true;
  }

  for (int i = length() - 1; i >= 0; i--) {
    if (getNthLSD(i) < rhnumber.getNthLSD(i)) {
      return getSign() ? false : true;
    }
    if (getNthLSD(i) > rhnumber.getNthLSD(i)) {
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

  if (length() > rhnumber.length()) {
    return getSign() ? false : true;
  }

  if (length() < rhnumber.length()) {
    return getSign() ? true : false;
  }

  for (int i = length() - 1; i >= 0; i--) {
    if (getNthLSD(i) < rhnumber.getNthLSD(i)) {
      return getSign() ? true : false;
    }
    if (getNthLSD(i) > rhnumber.getNthLSD(i)) {
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
  if (getSign() != rhnumber.getSign() || length() != rhnumber.length()) {
    return true;
  }

  for (int i = 0; i < length(); i++) {
    if (getNthLSD(i) != rhnumber.getNthLSD(i)) {
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

  if (length() > rhnumber.length()) {
    return getSign() ? false : true;
  }

  if (length() < rhnumber.length()) {
    return getSign() ? true : false;
  }

  for (int i = length() - 1; i >= 0; i--) {
    if (getNthLSD(i) < rhnumber.getNthLSD(i)) {
      return getSign() ? true : false;
    }
    if (getNthLSD(i) > rhnumber.getNthLSD(i)) {
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

  if (length() > rhnumber.length()) {
    return getSign() ? true : false;
  }

  if (length() < rhnumber.length()) {
    return getSign() ? false : true;
  }

  for (int i = length() - 1; i >= 0; i--) {
    if (getNthLSD(i) < rhnumber.getNthLSD(i)) {
      return getSign() ? false : true;
    }
    if (getNthLSD(i) > rhnumber.getNthLSD(i)) {
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
//       length() != rhnumber.length()) {
//     return false;
//   }

//   for (int i = 0; i < length(); i++) {
//     if (getNthLSD(i) != rhnumber.getNthLSD(i)) {
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

//   if (length() > rhnumber.length()) {
//     return getSign() ? true : false;
//   }

//   if (length() < rhnumber.length()) {
//     return getSign() ? false : true;
//   }

//   for (int i = length() - 1; i >= 0; i--) {
//     if (getNthLSD(i) < rhnumber.getNthLSD(i)) {
//       return getSign() ? false : true;
//     }
//     if (getNthLSD(i) > rhnumber.getNthLSD(i)) {
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

//   if (length() > rhnumber.length()) {
//     return getSign() ? false : true;
//   }

//   if (length() < rhnumber.length()) {
//     return getSign() ? true : false;
//   }

//   for (int i = length() - 1; i >= 0; i--) {
//     if (getNthLSD(i) < rhnumber.getNthLSD(i)) {
//       return getSign() ? true : false;
//     }
//     if (getNthLSD(i) > rhnumber.getNthLSD(i)) {
//       return getSign() ? false : true;
//     }
//   }
//   return false;
// }

// bool BigInt::notEqualTo(const BigInt rhnumber) const {

//   if (getSign() != rhnumber.getSign() ||
//       length() != rhnumber.length()) {
//     return true;
//   }

//   for (int i = 0; i < length(); i++) {
//     if (getNthLSD(i) != rhnumber.getNthLSD(i)) {
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

//   if (length() > rhnumber.length()) {
//     return getSign() ? false : true;
//   }

//   if (length() < rhnumber.length()) {
//     return getSign() ? true : false;
//   }

//   for (int i = length() - 1; i >= 0; i--) {
//     if (getNthLSD(i) < rhnumber.getNthLSD(i)) {
//       return getSign() ? true : false;
//     }
//     if (getNthLSD(i) > rhnumber.getNthLSD(i)) {
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

//   if (length() > rhnumber.length()) {
//     return getSign() ? true : false;
//   }

//   if (length() < rhnumber.length()) {
//     return getSign() ? false : true;
//   }

//   for (int i = length() - 1; i >= 0; i--) {
//     if (getNthLSD(i) < rhnumber.getNthLSD(i)) {
//       return getSign() ? false : true;
//     }
//     if (getNthLSD(i) > rhnumber.getNthLSD(i)) {
//       return getSign() ? true : false;
//     }
//   }
//   return true;
// }