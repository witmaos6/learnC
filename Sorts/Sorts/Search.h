#pragma once

class Search
{
public:
	template<typename T>
	bool BinarySearch(T* Arr, int Size, const int& Value)
	{
		int Low = 0, High = Size - 1;

		while(Low < High)
		{
			int Mid = Low + (High - Low) / 2;

			if(Arr[Mid] == Value)
			{
				return true;
			}
			else if(Arr[Mid] < Value)
			{
				Low = Mid + 1;
			}
			else
			{
				High = Mid - 1;
			}
		}

		return false;
	}

	template<typename T>
	int LowerBound(T* Arr, int Begin, int End, const int& Value)
	{
		if(Begin >= End)
		{
			return Begin;
		}

		while(Begin < End)
		{
			int Mid = Begin + (End - Begin) / 2;

			if (Arr[Mid] == Value)
			{
				return LowerBound(Arr, Begin, Mid - 1, Value);
			}
			else if(Arr[Mid] < Value)
			{
				Begin = Mid + 1;
			}
			else
			{
				End = Mid - 1;
			}
		}

		return Begin;
	}
};
