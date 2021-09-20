#ifndef JOBNODE_H
#define JOBNODE_H

class JobNode
{
private:
	int ID, time;
public:
	JobNode(int idNum, int t)
	{
		ID = idNum;
		time = t;
	}

	int val() const { return time; }
	bool operator<(const JobNode& j)
	{
		if (time < j.val())
		{
			return true;
		}

		return false;
	}
	bool operator>(const JobNode& j)
	{
		if (time > j.val())
		{
			return true;
		}

		return false;
	}
};

#endif