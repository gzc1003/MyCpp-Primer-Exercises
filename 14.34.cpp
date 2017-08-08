class IfThenElse {
	int operator()(bool i, int first, int second)
	{
		return i ? first : second;
	}
};