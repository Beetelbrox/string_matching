//: horspool.cpp - source for Horspool algorithm
#include <iostream>
#include <map>
#include <string>
#include "horspool.h"

using namespace std;

// Helper methods
bool check_match (const int i, const string &pattern, const string &sequence);
void build_shift_table(map<const char, int> &shift_table, const string pattern);

// Horspool function
int horspool(const string &pattern, const string &sequence) {
  // If the pattern is longer than the sequence return -1 immediately
  if ( pattern.length() > sequence.length() ) return -1;
  // Create and populate shift table
  map<const char, int> shift_table;    // Create shift table
  build_shift_table(shift_table, pattern);  // Populate shift table
  size_t i = 0, shift, matched = -1;
  while ( i <= sequence.length()-pattern.length() ) {
    if ( check_match(i, pattern, sequence) ) {
      matched = 0;
      cout << i << endl;
      ++i;  // Shift 1 character to the right so the algorithm moves on.
    } else {
      shift = shift_table[ sequence[i + pattern.length() - 1] ];
      i += shift != 0 ? shift : pattern.length();
    }
  }
  return matched;
}

void build_shift_table(map<const char, int> &shift_table, const string pattern) {
  for (size_t i=1; i < pattern.length(); ++i){
    int& n = shift_table[ pattern[pattern.length() - i- 1] ];
    if (n == 0) n = i;
  }
}

bool check_match (const int i, const string &pattern, const string &sequence){
  for(size_t ii=0; ii < pattern.length(); ++ii ) {
    if (sequence[i+ii] != pattern[ii]) return false;
  }
  return true;
}
