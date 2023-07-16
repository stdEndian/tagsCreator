#include <iostream>
#include <fstream>
#include <string>
#include <array>


std::array<std::string, 11> patterns = {"c", "d", "e", "f", "g", "m", "n", "s", "t", "u", "v"};


std::string identifie(std::string& line, std::array<std::string, 11>& patterns) {
  std::string letterThatNeed;
  for(size_t i = 0; i < line.length() - 1; i++) {
    for(const std::string& pattern : patterns) {  
      if(line[i] == pattern[0] && line[i - 1] == '\t' && line[i + 1] == '\t') { return pattern; } 
    }
  }
  return " ";
}


std::string firstWordOfStr(std::string& line) {
  size_t tabPos = line.find('\t');
    if (tabPos != std::string::npos) {
        return line.substr(0, tabPos);
    } else {
        return " ";
    }
}


int main() {
  std::ifstream readFile("tags");
  std::ofstream createFile("tags.vim");
  
  std::string synKeyword = "syn keyword ";

  if(!readFile) { std::cout << "No 'tags' file!!!" << std::endl; }

  std::string dataString;
  while(std::getline(readFile, dataString)) {

    std::string result = identifie(dataString, patterns);
    std::string firstWord = firstWordOfStr(dataString);
    
   
    if(result == "c" ) { createFile << synKeyword << "eiClassTag " << firstWord << std::endl; }
    else if(result == "d" ) { createFile << synKeyword << "eiMacroTag " << firstWord << std::endl; }
    else if(result == "e" ) { createFile << synKeyword << "eiEnumTag " << firstWord << std::endl; }
    else if(result == "f" ) { createFile << synKeyword << "eiFunctionTag " << firstWord << std::endl; }
    else if(result == "g" ) { createFile << synKeyword << "eiEnumTypeTag " << firstWord << std::endl; }
    else if(result == "m" ) { createFile << synKeyword << "eiMemberTag " << firstWord << std::endl; }
    else if(result == "n" ) { createFile << synKeyword << "eiNamespaceTag " << firstWord << std::endl; }
    else if(result == "s" ) { createFile << synKeyword << "eiStuctTag " << firstWord << std::endl; }
    else if(result == "t" ) { createFile << synKeyword << "eiTypedefTag " << firstWord << std::endl; }
    else if(result == "u" ) { createFile << synKeyword << "eiUnionTag " << firstWord << std::endl; }
    else if(result == "v" ) { createFile << synKeyword << "eiVariableTag " << firstWord << std::endl; }
    else { continue; }
  }

  readFile.close();
  createFile.close();

  return 0;
}
