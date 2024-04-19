
#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
#include <stdexcept>


class GameException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};


class InvalidIndexException : public GameException {
public:
    using GameException::GameException;
};

class InventoryFullException : public GameException {
public:
    using GameException::GameException;
};


class GearFullException : public GameException {
public:
    using GameException::GameException;
};

class InvalidItemException : public GameException {
public:
    using GameException::GameException;
};

class InvalidArgument : public GameException {
public:
    using GameException::GameException;
};


#endif /* EXCEPTIONS_H_ */
