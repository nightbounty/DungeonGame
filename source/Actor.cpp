#include "Actor.h"
#include "Character/Character.h"
#include "Character/Character.h"
#include "Strategies/FriendlyStrategy.h"
#include "Strategies/AggressorStrategy.h"

Actor::Actor()
{
	this->position = new Vector2(0, 0);
	this->currentTarget = NULL;
}

Actor::Actor(string name, Vector2* pos, TurnStrategy* ts, int lvl, string cls, Actor * target)
    :name(name), position(pos), level(lvl), characterClass(cls), currentTarget(target) 
{ 
    this->currentWeapon = new Weapon("Sword", "1d6+", 1);
    this->SetTurnStrategy(ts);
}

/**
 * Display the Character Stats
 */
void Actor::DisplayStats() {
    cout << "--------------------------------------------------" << endl;
    cout << "Character Info:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Level: " << level << ", Character Class: " << characterClass << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Ability Scores and Modifiers:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Strength:  " << abilityScores[0] << " (Modifier: " << abilityModifiers[0] << ")" << endl;
    cout << "Dexterity:  " << abilityScores[1] << " (Modifier: " << abilityModifiers[1] << ")" << endl;
    cout << "Constitution:  " << abilityScores[2] << " (Modifier: " << abilityModifiers[2] << ")" << endl;
    cout << "Intelligence:  " << abilityScores[3] << " (Modifier: " << abilityModifiers[3] << ")" << endl;
    cout << "Wisdom:  " << abilityScores[4] << " (Modifier: " << abilityModifiers[4] << ")" << endl;
    cout << "Charisma:  " << abilityScores[5] << " (Modifier: " << abilityModifiers[5] << ")" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Hidden Stats:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Hit Points: " << GetTotalHitPoints() << endl;
    cout << "Armor Class: " << armorClass << endl;
    cout << "Attack Bonus: " << attackBonus << endl;
    cout << "Damage Bonus: " << damageBonus << endl;
    cout << "--------------------------------------------------" << endl;

}

void Actor::MoveActorFromInput() {
    cout << "Move actor from input! o^o" << endl;

    char input;
    Vector2* oldPos = this->GetPosition();
    int newX = oldPos->GetX(), newY = oldPos->GetY();
    cout << "Enter direction of movement: WASD, QEZC for diagonals" << endl;
    cin >> input;
    switch (input) {
    case 'w':
    {
        newX -= 1;
        break;
    }
    case 'a':
    {
        newY -= 1;
        break;
    }
    case 's':
    {
        newX += 1;
        break;
    }
    case 'd':
    {
        newY += 1;
        break;
    }
    case 'q':
    {
        newX -= 1;
        newY += 1;
        break;
    }
    case 'e':
    {
        newX += 1;
        newY += 1;
        break;
    }
    case 'z':
    {
        newX -= 1;
        newY -= 1;
        break;
    }
    case 'c':
    {
        newX += 1;
        newY -= 1;
        break;
    }
    }
    Vector2* newPos = new Vector2(newX, newY);
    GameManager::GetInstance()->MoveActor(this, oldPos, newPos);
}

void Actor::MoveTowardTarget() {

    if (currentTarget == NULL) {
        cout << "No target selected" << endl;
        return;
    }

    int newX, newY;
    Vector2* oldPos = this->position;

    if (this->GetPositionX() == this->currentTarget->GetPositionX() + 1
        || this->GetPositionY() == this->currentTarget->GetPositionY() + 1
        || this->GetPositionX() == this->currentTarget->GetPositionX() - 1
        || this->GetPositionY() == this->currentTarget->GetPositionY() - 1) {
        GameManager::GetInstance()->InitiateCombat(this);
    }
    // determine whether to move in X direction
    if (this->currentTarget->GetPositionX() < position->GetX()) {
        newX = this->GetPositionX() - 1;
    }
    else if (this->currentTarget->GetPositionX() > position->GetX()) {
        newX = this->GetPositionX() + 1;
    }
    else {
        newX = this->GetPositionX();
    }
    // determine whether to move in Y direction
    if (this->currentTarget->GetPositionY() < position->GetY()) {
        newY = this->GetPositionY() - 1;
    }
    else if (this->currentTarget->GetPositionY() > position->GetY()) {
        newY = this->GetPositionY() + 1;
    }
    else {
        newY = this->GetPositionY();
    }
    this->position = new Vector2(newX, newY);
    GameManager::GetInstance()->MoveActor(this, oldPos, this->position);
}

void Actor::TakeDamage(int dmgTaken)
{
    if (dynamic_cast<FriendlyStrategy*>(this->GetTurnStrategy()) != NULL) {
        cout << "Enemy has taken damage! Switching to the aggressor strategy." << endl;
        this->SetTurnStrategy(new AggressorStrategy());
    }
    SetCurrentHitPoints(GetCurrentHitPoints() - dmgTaken);
}

/**
 * Method in which an actor will battle another actor.
 *
 */
void Actor::Attack() {
    
    if (currentTarget == NULL) {
        cout << "No target selected" << endl;
        return;
    }

    /*
    cout << "Current pos: (" << GetPositionX() << "," << GetPositionY() << ")\n" << endl;
    cout << "Current target pos: (" << GetCurrentTarget()->GetPositionX()
        << "," << GetCurrentTarget()->GetPositionY() << ")\n" << endl;
    cout << "Abs distance: (" << (std::abs(GetCurrentTarget()->GetPositionX() - GetPositionX()))
        << "," << (std::abs(GetCurrentTarget()->GetPositionY() - GetPositionY())) << ")\n" << endl;
    */

    //cout << "Weapon? " << (currentWeapon != NULL) << endl;

    if (std::abs(currentTarget->GetPositionY() - GetPositionY()) <= currentWeapon->GetRange()
        && std::abs(currentTarget->GetPositionX() - GetPositionX()) <= currentWeapon->GetRange()) {

        cout << "In range!" << endl;

        int atkRoll = Dice::rollDice("1d20+" + attackBonus);
        atkRoll = 12; // test success roll // todo remove
        cout << "Attack roll: " << atkRoll << " vs Target AC: " << currentTarget->GetArmorClass() << endl;

        if (atkRoll >= currentTarget->GetArmorClass()) {
            int dmgRoll = 4; //Dice::rollDice(currentWeapon->GetDamageDice() + "+" + std::to_string(damageBonus));
            currentTarget->TakeDamage(dmgRoll);
            cout << "Attack successful! " << dmgRoll << endl;
        }
        else {
            cout << "Missed the attack!" << endl;
        }
    }
    else {
        cout << "Out of range!" << endl;
    }
}

#pragma region

Vector2* Actor::GetPosition()
{
    return this->position;
}

int Actor::GetPositionX() {
    return this->position->GetX();
}

int Actor::GetPositionY() {
    return this->position->GetY();
}

void Actor::SetPosition(Vector2* pos)
{
    this->position = pos;
}

TurnStrategy* Actor::GetTurnStrategy()
{
    return this->turnStrategy;
}

void Actor::SetTurnStrategy(TurnStrategy* ts)
{
    this->turnStrategy = ts;
}

Actor* Actor::GetCurrentTarget()
{
    return this->currentTarget;
}

void Actor::SetCurrentTarget(Actor* target)
{
    this->currentTarget = target;
}

int Actor::GetCurrentHitPoints() {
    return this->currentHitPoints;
}

int Actor::GetTotalHitPoints() {
    return this->totalHitPoints;
}

void Actor::SetCurrentHitPoints(int hitPoints) {
    this->currentHitPoints = hitPoints;
}
void Actor::SetTotalHitPoints(int hitPoints) {
    this->totalHitPoints = hitPoints;
}

int Actor::GetArmorClass() {
    return armorClass; 
}

void Actor::SetInitiativeBonus(int bonus) {
    this->initiativeBonus = bonus;
}

int Actor::GetInitiativeBonus() {
    return this->initiativeBonus;
}

void Actor::SetCurrentWeapon(Weapon* weapon) {
    this->currentWeapon = weapon;
}

Weapon* Actor::GetCurrentWeapon() {
    return this->currentWeapon;
}

#pragma endregion