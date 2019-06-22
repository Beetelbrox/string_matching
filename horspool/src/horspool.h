//: horspool.h - header for Horspool algorithm
#ifndef HORSPOOL_H
#define HORSPOOL_H


int horspool(const std::string &pattern, const std::string &sequence);
// PRE: Valid Strings 'pattern' & 'sequence'
// POST: Prints the 0-based index of all the matches found. Returns -1 if it found
//      no matches, 0 otherwise. Automatically returns -1 if len(pattern) > len(sequence).

#endif
