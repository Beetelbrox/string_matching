#include <iostream>
#include <string>
#include "horspool.h"

int parse_input(int argc, char* argv[], std::string &pattern, std::string &sequence) ;

int main (int argc, char** argv) {
  std::string pattern, sequence;
  if ( parse_input(argc, argv, pattern, sequence ) < 0 ) return -1;
  if ( horspool(pattern, sequence) < 0 ) std::cerr << "No matches found" << std::endl;
  return 0;
}

int parse_input(int argc, char* argv[], std::string &pattern, std::string &sequence) {
  if ( argc == 1 ) {
    if (!std::getline(std::cin, pattern)) {
      std::cerr << "Error: Missing pattern input." << std::endl;
      return -1;
    }
    if (!std::getline(std::cin, sequence)) {
      std::cerr << "Error: Missing sequnce input." << std::endl;
      return -1;
    }
  }else if (argc == 3 ){
    pattern = argv[1];
    sequence = argv[2];
  }else {
    std::cerr << "Error: Wrong number of parameters" << std::endl;
    return -1;
  }
  return 0;
}
