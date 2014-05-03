#include "Bank.h"

using namespace std;

Bank::Bank(int bankBalance) :
	Participant(0, bankBalance)
{
}

Bank::~Bank()
{
	this->hand->deleteHand();
	delete hand;
}

void Bank::newHand()
{
	if (this->hand != NULL)
		this->hand = new Hand();
	else throw exception("Main d�j� existante");
}

void Bank::deleteHand()
{
	this->hand->deleteHand();
	this->hand = NULL;
}