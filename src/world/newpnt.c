#include "world.h"

void	update_step(t_prsn *person)
{
	person->step.x = cos(person->alp) * STEP;
	person->step.y = sin(person->alp) * STEP;
}

t_pnt	newpnt(float x, float y)
{
	t_pnt	pnt;

	pnt.x = x;
	pnt.y = y;
	return (pnt);
}
