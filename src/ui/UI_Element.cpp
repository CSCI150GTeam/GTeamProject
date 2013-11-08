/*
 * UI_Element.cpp - UI module
 * Code contributed by: Sammy
 * UI_Element is an abstract class (an abstract class is meant only for other classes to inherit from it) that
 * other UI classes (button, switch) will inherit from
 */
#include "UI_Element.h"

virtual UI_Element::UI_Element() = 0;

UI_Element::~UI_Element()
{
}

