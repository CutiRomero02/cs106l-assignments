/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */

  friend std::ostream& operator <<(std::ostream& os, const User& user);

  ~User();
  User(const User& other);
  User& operator=(const User& other);
  User(User&& other) = delete;
  User& operator=(User&& other) = delete;

  User& operator+=(User& other);

  bool operator<(const User& other) const {
    return this->_name < other._name;
  }


private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};