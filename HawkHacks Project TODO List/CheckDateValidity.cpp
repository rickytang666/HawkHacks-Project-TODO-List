class CheckDateValidity
{
public:
	bool operator() (const int& year, const int& month, const int& day) const
	{
		bool leap = false;

		// Determine if it is a leap year
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			leap = true;
		}

		// Check if the month is correct
		if (month < 1 || month > 12)
		{
			return false;
		}

		// Check if the day is correct
		if (day < 1 || day > 31)
		{
			return false;
		}

		// Check for months with only 30 days
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30)
			{
				return false;
			}
		}

		// Check for February (leap year or not)
		if (month == 2)
		{
			if (leap && day > 29)
			{
				return false;
			}
			else if (!leap && day > 28)
			{
				return false;
			}
		}

		// If all checks pass, the date is valid
		return true;
	}
};
