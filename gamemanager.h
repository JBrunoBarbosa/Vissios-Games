#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "game.h"
#include "gameimpl.h"
#include <QVector>

/**
 * @brief Interface abstrata para gerenciamento de operações relacionadas a jogos.
 *
 * Define um contrato para as operações CRUD que devem ser implementadas.
 */
class GameManager {
public:
    virtual ~GameManager() {}

    /**
     * @brief Salva um jogo no banco de dados.
     *
     * @param game Referência constante para o jogo a ser salvo.
     * @return true se o jogo for salvo com sucesso, false caso contrário.
     */
    virtual bool saveGame(const Game& game) = 0;

    /**
     * @brief Remove um jogo do banco de dados pelo seu ID.
     *
     * @param gameId ID do jogo a ser removido.
     * @return true se o jogo for removido com sucesso, false caso contrário.
     */
    virtual bool removeGame(int gameId) = 0;

    /**
     * @brief Lista todos os jogos do banco de dados.
     *
     * @return QVector<GameImpl> contendo todos os jogos.
     */
    virtual QVector<GameImpl> listGames() = 0;

    /**
     * @brief Modifica os dados de um jogo existente no banco de dados.
     *
     * @param game Referência constante para o jogo com os dados atualizados.
     * @return true se o jogo for modificado com sucesso, false caso contrário.
     */
    virtual bool modifyGame(const Game& game) = 0;
};

#endif // GAMEMANAGER_H
