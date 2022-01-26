#include "BigInt.hpp"

/*

*** Comparison operators overloading ***

*/

/**
 * BigInt == BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator==(const BigInt &rhn) const {
  if (getSign() != rhn.getSign() || length() != rhn.length()) {
    return false;
  }

  for (int i = 0; i < length(); i++) {
    if (getNthLSD(i) != rhn.getNthLSD(i)) {
      return false;
    }
  }
  return true;
}

/**
 * BigInt > BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator>(const BigInt &rhn) const {
  if (getSign() && !rhn.getSign()) {
    return true;
  }
  if (!getSign() && rhn.getSign()) {
    return false;
  }

  if (length() > rhn.length()) {
    return getSign() ? true : false;
  }

  if (length() < rhn.length()) {
    return getSign() ? false : true;
  }

  for (int i = length() - 1; i >= 0; i--) {
    if (getNthLSD(i) < rhn.getNthLSD(i)) {
      return getSign() ? false : true;
    }
    if (getNthLSD(i) > rhn.getNthLSD(i)) {
      return getSign() ? true : false;
    }
  }
  return false;
}

/**
 * BigInt < BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator<(const BigInt &rhn) const {
  if (getSign() && !rhn.getSign()) {
    return false;
  }
  if (!getSign() && rhn.getSign()) {
    return true;
  }

  if (length() > rhn.length()) {
    return getSign() ? false : true;
  }

  if (length() < rhn.length()) {
    return getSign() ? true : false;
  }

  for (int i = length() - 1; i >= 0; i--) {
    if (getNthLSD(i) < rhn.getNthLSD(i)) {
      return getSign() ? true : false;
    }
    if (getNthLSD(i) > rhn.getNthLSD(i)) {
      return getSign() ? false : true;
    }
  }
  return false;
}
/**
 * BigInt != BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator!=(const BigInt &rhn) const {
  if (getSign() != rhn.getSign() || length() != rhn.length()) {
    return true;
  }

  for (int i = 0; i < length(); i++) {
    if (getNthLSD(i) != rhn.getNthLSD(i)) {
      return true;
    }
  }
  return false;
}
/**
 * BigInt <= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator<=(const BigInt &rhn) const {
  if (getSign() && !rhn.getSign()) {
    return false;
  }
  if (!getSign() && rhn.getSign()) {
    return true;
  }

  if (length() > rhn.length()) {
    return getSign() ? false : true;
  }

  if (length() < rhn.length()) {
    return getSign() ? true : false;
  }

  for (int i = length() - 1; i >= 0; i--) {
    if (getNthLSD(i) < rhn.getNthLSD(i)) {
      return getSign() ? true : false;
    }
    if (getNthLSD(i) > rhn.getNthLSD(i)) {
      return getSign() ? false : true;
    }
  }
  return true;
}
/**
 * BigInt >= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::operator>=(const BigInt &rhn) const {
  if (getSign() && !rhn.getSign()) {
    return true;
  }
  if (!getSign() && rhn.getSign()) {
    return false;
  }

  if (length() > rhn.length()) {
    return getSign() ? true : false;
  }

  if (length() < rhn.length()) {
    return getSign() ? false : true;
  }

  for (int i = length() - 1; i >= 0; i--) {
    if (getNthLSD(i) < rhn.getNthLSD(i)) {
      return getSign() ? false : true;
    }
    if (getNthLSD(i) > rhn.getNthLSD(i)) {
      return getSign() ? true : false;
    }
  }
  return true;
}

/*

*** Comparison methods ***

*/

// bool BigInt::isEqualTo(const BigInt rhn) const {

//   if (getSign() != rhn.getSign() ||
//       length() != rhn.length()) {
//     return false;
//   }

//   for (int i = 0; i < length(); i++) {
//     if (getNthLSD(i) != rhn.getNthLSD(i)) {
//       return false;
//     }
//   }
//   return true;
// }

// bool BigInt::isMoreThen(const BigInt rhn) const {

//   if (getSign() && !rhn.getSign()) {
//     return true;
//   }
//   if (!getSign() && rhn.getSign()) {
//     return false;
//   }

//   if (length() > rhn.length()) {
//     return getSign() ? true : false;
//   }

//   if (length() < rhn.length()) {
//     return getSign() ? false : true;
//   }

//   for (int i = length() - 1; i >= 0; i--) {
//     if (getNthLSD(i) < rhn.getNthLSD(i)) {
//       return getSign() ? false : true;
//     }
//     if (getNthLSD(i) > rhn.getNthLSD(i)) {
//       return getSign() ? true : false;
//     }
//   }
//   return false;
// }

// bool BigInt::isLessThen(const BigInt rhn) const {

//   if (getSign() && !rhn.getSign()) {
//     return false;
//   }
//   if (!getSign() && rhn.getSign()) {
//     return true;
//   }

//   if (length() > rhn.length()) {
//     return getSign() ? false : true;
//   }

//   if (length() < rhn.length()) {
//     return getSign() ? true : false;
//   }

//   for (int i = length() - 1; i >= 0; i--) {
//     if (getNthLSD(i) < rhn.getNthLSD(i)) {
//       return getSign() ? true : false;
//     }
//     if (getNthLSD(i) > rhn.getNthLSD(i)) {
//       return getSign() ? false : true;
//     }
//   }
//   return false;
// }

// bool BigInt::notEqualTo(const BigInt rhn) const {

//   if (getSign() != rhn.getSign() ||
//       length() != rhn.length()) {
//     return true;
//   }

//   for (int i = 0; i < length(); i++) {
//     if (getNthLSD(i) != rhn.getNthLSD(i)) {
//       return true;
//     }
//   }
//   return false;
// }

// bool BigInt::isLessOrEqualTo(const BigInt rhn) const {
//   if (getSign() && !rhn.getSign()) {
//     return false;
//   }
//   if (!getSign() && rhn.getSign()) {
//     return true;
//   }

//   if (length() > rhn.length()) {
//     return getSign() ? false : true;
//   }

//   if (length() < rhn.length()) {
//     return getSign() ? true : false;
//   }

//   for (int i = length() - 1; i >= 0; i--) {
//     if (getNthLSD(i) < rhn.getNthLSD(i)) {
//       return getSign() ? true : false;
//     }
//     if (getNthLSD(i) > rhn.getNthLSD(i)) {
//       return getSign() ? false : true;
//     }
//   }
//   return true;
// }

// bool BigInt::isMoreOrEqualTo(const BigInt rhn) const {
//   if (getSign() && !rhn.getSign()) {
//     return true;
//   }
//   if (!getSign() && rhn.getSign()) {
//     return false;
//   }

//   if (length() > rhn.length()) {
//     return getSign() ? true : false;
//   }

//   if (length() < rhn.length()) {
//     return getSign() ? false : true;
//   }

//   for (int i = length() - 1; i >= 0; i--) {
//     if (getNthLSD(i) < rhn.getNthLSD(i)) {
//       return getSign() ? false : true;
//     }
//     if (getNthLSD(i) > rhn.getNthLSD(i)) {
//       return getSign() ? true : false;
//     }
//   }
//   return true;
// }