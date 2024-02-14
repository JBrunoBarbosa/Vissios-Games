#ifndef GAME_H
#define GAME_H

#include <string>

/**
 * @brief Interface for Game class, declaring methods for game management.
 */
class Game
{
public:
    virtual ~Game() {}

    /**
     * @brief Get the Game ID
     * @return int The unique identifier for the game.
     */
    virtual int getId() const = 0;

    /**
     * @brief Get the Game Name
     * @return std::string The name of the game.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Get the Player Amount
     * @return int The amount of players that can play the game.
     */
    virtual int getPlayerAmount() const = 0;

    /**
     * @brief Get the Game Genre
     * @return std::string The genre of the game.
     */
    virtual std::string getGenre() const = 0;

    /**
     * @brief Get the Minimum Age required to play the game
     * @return int The minimum age required to play the game.
     */
    virtual int getMinAge() const = 0;

    /**
     * @brief Get the Total Amount of copies of the game
     * @return int The total amount of copies of the game available.
     */
    virtual int getTotalAmount() const = 0;

    /**
     * @brief Get the Current Amount of copies of the game available
     * @return int The current amount of copies available for rent/purchase.
     */
    virtual int getCurrentAmount() const = 0;


    /**
     * @brief Set the Game ID
     * @param newId The new unique identifier for the game.
     */
    virtual void setId(int newId) = 0;

    /**
     * @brief Set the Game Name
     * @param newName The new name of the game.
     */
    virtual void setName(const std::string& newName) = 0;

    /**
     * @brief Set the Player Amount
     * @param newPlayerAmount The new amount of players that can play the game.
     */
    virtual void setPlayerAmount(int newPlayerAmount) = 0;

    /**
     * @brief Set the Game Genre
     * @param newGenre The new genre of the game.
     */
    virtual void setGenre(const std::string& newGenre) = 0;

    /**
     * @brief Set the Minimum Age required to play the game
     * @param newMinAge The new minimum age required to play the game.
     */
    virtual void setMinAge(int newMinAge) = 0;

    /**
     * @brief Set the Total Amount of copies of the game
     * @param newTotalAmount The new total amount of copies of the game available.
     */
    virtual void setTotalAmount(int newTotalAmount) = 0;

    /**
     * @brief Set the Current Amount of copies of the game available
     * @param newCurrentAmount The new current amount of copies available for rent/purchase.
     */
    virtual void setCurrentAmount(int newCurrentAmount) = 0;
};

#endif
