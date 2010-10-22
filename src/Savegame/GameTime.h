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
#ifndef OPENXCOM_GAMETIME_H
#define OPENXCOM_GAMETIME_H

#include "../Resource/LangString.h"

/**
 * Enumerator for time periods.
 */
enum TimeTrigger { TIME_5SEC, TIME_10MIN, TIME_30MIN, TIME_1HOUR, TIME_1DAY, TIME_1MONTH };

/**
 * Stores the current ingame time/date according to GMT.
 * Takes care of managing and representing each component,
 * as well as common time operations.
 */
class GameTime
{
private:
	int _second, _minute, _hour, _weekday, _day, _month, _year;
public:
	/// Creates a new ingame time at a certain point.
	GameTime(int weekday, int day, int month, int year, int hour, int minute, int second);
	/// Cleans up the ingame time.
	~GameTime();
	/// Advances the time by 5 seconds.
	TimeTrigger advance();
	/// Gets the ingame second.
	int getSecond();
	/// Gets the ingame minute.
	int getMinute();
	/// Gets the ingame hour.
	int getHour();
	/// Gets the ingame weekday.
	int getWeekday();
	// Gets a string version of the ingame weekday.
	LangString getWeekdayString();
	/// Gets the ingame day.
	int getDay();
	// Gets a string version of the ingame day.
	LangString getDayString();
	/// Gets the ingame month.
	int getMonth();
	// Gets a string version of the ingame month.
	LangString getMonthString();
	/// Gets the ingame year.
	int getYear();
	/// Gets the position of the daylight according to the ingame time.
	double getDaylight();
};

#endif