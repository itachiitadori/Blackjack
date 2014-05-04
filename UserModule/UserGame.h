/**
 * Classe UserGame. Classe de gestion des joueurs
 */

#ifndef USERGAME_H_
#define USERGAME_H_

#include <vector>
#include "../GameModule/Player.h"
#include "../CommunicationModule/PlayerCommunication.h"
#include "../InterfaceModule/HMI.h"

class UserGame {
public:
	/**
	 * Constructeur de Usergame
	 */
	UserGame(int pBalance);
	/**
	 * Destructeur de UserGame
	 */
	virtual ~UserGame();
	/**
	 * Methode permettant au joueur courant de quitter le jeux
	 */
	void quitGame();
	/**
	 * Methode permettant au joueur courant de demarer son jeux
	 */
	void runGame();

private:

	Player player; /**< Player. Joueur courant **/
	PlayerCommunication com; /**< PlayerCommunication. Objet permettant la communication entre l'exécutable joueurs et l'exécutable bank */
	std::string message; /**< char*. Stocke le message reçu*/
	char* reste;/**< char*.Stocke le reste du message (ce qu'on a pas encore lu)*/
	int id_message; /**< Entier. Code d'identification du message*/
	HMI ihm; /**<HMI. Objet permettant la communication entre le joueur humain et le module joueur*/
	PlayerHand *myHand1,*myHand2; /**<PlayerHand. mains du joueur*/

	/**
	 * Methode permettant d' initialiser un tour
	 */
	void initRound();

	/**
	 * Methode permettant de faire un tour
	 */
	void runRound();

	/**
	 * Methode permettant de demander des actions au joueur en fontion de l'etat de sa(ses) main(s)
	 */
	void choseAction(PlayerHand* myhand);

};

#endif /* USERGAME_H_ */
