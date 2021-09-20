#ifndef MACHINENODE_H
#define MACHINENODE_H
class MachineNode
{
private:
	int ID, avail;
public:
	MachineNode(int idNum, int availability)
	{
		ID = idNum;
		avail = availability;
	}

	int getID() const { return ID; }
	int val() const { return avail; }
	bool operator<(const MachineNode& m)
	{
		if (avail < m.val())
		{
			return true;
		}

		return false;
	}
	bool operator>(const MachineNode& m)
	{
		if (avail > m.val())
		{
			return true;
		}

		return false;
	}
};

#endif