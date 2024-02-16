#include "../headers/GameImpl.h"
#include <QVariantMap>

GameImpl::GameImpl(int id, std::string name, int playerAmount, std::string genre, int minAge, std::string supplier)
    : id(id), name(name), playerAmount(playerAmount), genre(genre), minAge(minAge), supplier(supplier)
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

std::string GameImpl::getSupplier() const {
    return supplier;
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

void GameImpl::setSupplier(const std::string& newSupplier) {
    supplier = newSupplier;
}
