#ifndef GAMEIMPL_H
#define GAMEIMPL_H

#include "Game.h"

class GameImpl : public Game
{
private:
    int id;
    std::string name;
    int playerAmount;
    std::string genre;
    int minAge;
    int totalAmount;
    int currentAmount;

public:
    // Constructor
    GameImpl(int id, std::string name, int playerAmount, std::string genre, int minAge, int totalAmount, int currentAmount);

    // Getters
    int getId() const override;
    std::string getName() const override;
    int getPlayerAmount() const override;
    std::string getGenre() const override;
    int getMinAge() const override;
    int getTotalAmount() const override;
    int getCurrentAmount() const override;

    // Setters
    void setId(int newId) override;
    void setName(const std::string& newName) override;
    void setPlayerAmount(int newPlayerAmount) override;
    void setGenre(const std::string& newGenre) override;
    void setMinAge(int newMinAge) override;
    void setTotalAmount(int newTotalAmount) override;
    void setCurrentAmount(int newCurrentAmount) override;
};

#endif
