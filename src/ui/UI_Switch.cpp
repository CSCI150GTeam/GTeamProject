/*
 * UI_Switch.cpp - UI module
 * Code contributed by: Sammy
 * A switch is a UI element that has an on/off state, represented as a boolean variable (true=on/false=off)
 */

#include "UI_Switch.h"

//Constructor
UI_Switch::UI_Switch(int iX, int iY, string iSize, string iId, bool iState) : UI_Element(iX,iY,iSize,iId)
{
    this->state = iState;
}

//Destructor
UI_Switch::~UI_Switch()
{
    
}

string UI_Switch::handleEvents()
{
    
}

void UI_Switch::drawOnScreen()
{
    
}