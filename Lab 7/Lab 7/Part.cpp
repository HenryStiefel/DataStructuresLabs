#include "Part.h"

string Part::getPartInfo()
{
	string pN = "Part Number: " + to_string(partNum);
	string description = "\nDescription: " + desc;

	return pN.append(description);
}
bool Part::available(Date desired)
{
	if (inStock())
	{
		return true;
	}
	else
	{
		return desired.day > (today.day + leadTime);
	}
}
bool Part::operator<(const Part& rval)
{
	return partNum < rval.partNum;
}
bool Part::operator>(const Part& rval)
{
	return partNum > rval.partNum;
}
bool Part::operator==(const Part& rval)
{
	return partNum == rval.partNum;
}