//Linear interpolation MFGD method 
//*there WILL be errors*
float approachLI(float flGoal, float flCurrent, float deltatime)
{
	//how far do we have to go before the goal?
	float flDifference = flGoal - flCurrent;

	//if delta time isnt enough to meet our goal
	if (flDifference > deltatime)
	{
		//return a step farther
		return flCurrent + deltatime;
	}
	
	//EDGE CASE
	//if interpolating in a downwards direction, the "difference" would be negative
	if (flDifference < -deltatime)
	{
		return flCurrent - deltatime;
	}
	//if in range of our goal
	return flGoal;
}




