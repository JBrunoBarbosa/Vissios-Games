#include "GameImpl.h"

GameImpl::GameImpl(int id, std::string name, int playerAmount, std::string genre, int minAge, int totalAmount, int currentAmount)
    : id(id), name(name), playerAmount(playerAmount), genre(genre), minAge(minAge), totalAmount(totalAmount), currentAmount(currentAmount)
{
}

int GameImpl::getId() const {
    return id;
}

std::string GameImpl::getName() const {
    return name;
}

int GameImpl::getPlayerAmount() const {
    return playerAmount;
}

std::string GameImpl::getGenre() const {
    return genre;
}

int GameImpl::getMinAge() const {
    return minAge;
}

int GameImpl::getTotalAmount() const {
    return totalAmount;
}

int GameImpl::getCurrentAmount() const {
    return currentAmount;
}

void GameImpl::setId(int newId) {
    id = newId;
}

void GameImpl::setName(const std::string& newName) {
    name = newName;
}

void GameImpl::setPlayerAmount(int newPlayerAmount) {
    playerAmount = newPlayerAmount;
}

void GameImpl::setGenre(const std::string& newGenre) {
    genre = newGenre;
}

void GameImpl::setMinAge(int newMinAge) {
    minAge = newMinAge;
}

void GameImpl::setTotalAmount(int newTotalAmount) {
    totalAmount = newTotalAmount;
}

void GameImpl::setCurrentAmount(int newCurrentAmount) {
    currentAmount = newCurrentAmount;
}
