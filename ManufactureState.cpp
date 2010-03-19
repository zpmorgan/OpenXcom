/*
 * Copyright 2010 Daniel Albano
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "ManufactureState.h"

ManufactureState::ManufactureState(Game *game) : State(game)
{
	// Create objects
	_window = new Window(320, 200, 0, 0);
	_btnNew = new Button(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 148, 16, 8, 176);
	_btnOk = new Button(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 148, 16, 164, 176);
	_txtTitle = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 310, 13, 5, 8);
	_txtAvailable = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 150, 9, 8, 24);
	_txtAllocated = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 150, 9, 160, 24);
	_txtSpace = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 150, 9, 8, 34);
	_txtFunds = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 150, 9, 160, 34);
	_txtItem = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 80, 9, 10, 52);
	_txtEngineers = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 46, 18, 90, 44);
	_txtProduced = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 42, 18, 137, 44);
	_txtTotal = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 42, 18, 180, 44);
	_txtCost = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 42, 27, 223, 44);
	_txtTimeLeft = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 54, 18, 265, 44);
	_lstManufacture = new TextList(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 300, 100, 10, 74);
	
	// Set palette
	_game->setPalette(_game->getPalette("BACKPALS.DAT")->getColors(Palette::blockOffset(6)), Palette::backPos, 16);

	add(_window);
	add(_btnNew);
	add(_btnOk);
	add(_txtTitle);
	add(_txtAvailable);
	add(_txtAllocated);
	add(_txtSpace);
	add(_txtFunds);
	add(_txtItem);
	add(_txtEngineers);
	add(_txtProduced);
	add(_txtTotal);
	add(_txtCost);
	add(_txtTimeLeft);
	add(_lstManufacture);

	// Set up objects
	_window->setColor(Palette::blockOffset(15)+9);
	_window->setBg(game->getSurface("BACK17.SCR"));
	
	_btnNew->setColor(Palette::blockOffset(13)+13);
	_btnNew->setText(_game->getLanguage()->getString(103));

	_btnOk->setColor(Palette::blockOffset(13)+13);
	_btnOk->setText(_game->getLanguage()->getString(76));
	_btnOk->onMouseClick((EventHandler)&ManufactureState::btnOkClick);

	_txtTitle->setColor(Palette::blockOffset(15)+6);
	_txtTitle->setBig();
	_txtTitle->setAlign(ALIGN_CENTER);
	_txtTitle->setText(_game->getLanguage()->getString(92));

	_txtAvailable->setColor(Palette::blockOffset(15)+6);
	_txtAvailable->setText(_game->getLanguage()->getString(93));

	_txtAllocated->setColor(Palette::blockOffset(15)+6);
	_txtAllocated->setText(_game->getLanguage()->getString(94));

	_txtSpace->setColor(Palette::blockOffset(15)+6);
	_txtSpace->setText(_game->getLanguage()->getString(95));

	_txtFunds->setColor(Palette::blockOffset(15)+6);
	_txtFunds->setText(_game->getLanguage()->getString(96));

	_txtItem->setColor(Palette::blockOffset(15)+1);
	_txtItem->setText(_game->getLanguage()->getString(97));

	_txtEngineers->setColor(Palette::blockOffset(15)+1);
	_txtEngineers->setText(_game->getLanguage()->getString(98));

	_txtProduced->setColor(Palette::blockOffset(15)+1);
	_txtProduced->setText(_game->getLanguage()->getString(99));

	_txtTotal->setColor(Palette::blockOffset(15)+1);
	_txtTotal->setText(_game->getLanguage()->getString(100));

	_txtCost->setColor(Palette::blockOffset(15)+1);
	_txtCost->setText(_game->getLanguage()->getString(101));

	_txtTimeLeft->setColor(Palette::blockOffset(15)+1);
	_txtTimeLeft->setText(_game->getLanguage()->getString(102));

	_lstManufacture->setColor(Palette::blockOffset(15)+6);
	_lstManufacture->setColumns(6, 50, 50, 50, 50, 50, 50);
	_lstManufacture->addRow(6, "Laser Rifle", "30", "2", "8", "40 000", "5/2");
}

ManufactureState::~ManufactureState()
{
	
}

void ManufactureState::think()
{
}

void ManufactureState::btnOkClick(SDL_Event *ev, int scale)
{
	_game->setState(new BasescapeState(_game));
}