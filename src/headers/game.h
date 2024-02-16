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
     * @brief Get the name of supplier the game available
     * @return std::string The name of the supplier.
     */
    virtual std::string getSupplier() const = 0;

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
     * @brief Set the supplier name of the game available
     * @param supplier The new name of supplier.
     */
    virtual void setSupplier(const std::string& supplier) = 0;
};

#endif
