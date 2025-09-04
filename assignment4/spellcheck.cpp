#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */

  std::vector<std::string::iterator> positions = find_all(source.begin(), source.end(), 
    [](char c) { return std::isspace(static_cast<unsigned char>(c)); });
  Corpus tokens;
  
/*
  for (size_t i = 0; i < positions.size() - 1; ++i) {
    Token token(source, positions[i], positions[i + 1]);
    if (!token.content.empty()) {
      tokens.insert(token);
    }
  }
*/
  
  if (positions.size() >= 2) {
    std::transform(positions.begin(), positions.end() - 1, positions.begin() + 1, 
    std::inserter(tokens, tokens.end()),
    [&source](auto it1, auto it2) {
      return Token{source, it1, it2};
    });
  
   std::erase_if(tokens, [](const auto& token){ 
      return token.content.empty(); 
    });  
  }

  return tokens;

}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  
  namespace rv = std::ranges::views;
  auto view = source 
    | rv::filter([&dictionary](const auto& token) {
        return !dictionary.contains(token.content);
        })
    | rv::transform([&dictionary](const auto& token) {
        auto suggestionView = dictionary | rv::filter([&token](const auto& word) {
              return levenshtein(token.content, word) == 1;
            });
        std::set<std::string> suggestions(suggestionView.begin(), suggestionView.end());
        return Misspelling{token, suggestions};
      })
    | rv::filter([](const auto& misspelling) {
        return !misspelling.suggestions.empty();
      });
  
  std::set<Misspelling> misspellings(view.begin(), view.end());
  return misspellings;
    
};

/* Helper methods */

#include "utils.cpp"