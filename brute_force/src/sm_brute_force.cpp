#include <iostream>
#include <string>

int parse_input (int argc, char* argv[], std::string &pattern, std::string &sequence);
bool check_match (int i, const std::string &pattern, const std::string &sequence);

int main (int argc, char** argv) {
  std::string pattern, sequence;
  if ( parse_input(argc, argv, pattern, sequence ) < 0 ) return -1;

  for (size_t i = 0; i <= sequence.length()-pattern.length(); ++i) {
    if ( check_match(i, pattern, sequence) ) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  std::cout << -1 << std::endl;
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

bool check_match (int i, const std::string &pattern, const std::string &sequence){
  for(size_t ii=0; ii < pattern.length(); ++ii ) {
    if (sequence[i+ii] != pattern[ii]) return false;
  }
  return true;
}
