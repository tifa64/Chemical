#include <pthread.h>
#include "reaction.h"

// Forward declaration. This function is implemented in reaction-runner.c,
// but you needn't care what it does. Just be sure it's called when
// appropriate within reaction_o()/reaction_h().
void make_water();


void reaction_init(struct reaction *reaction)
{
	reaction->hyd_atom = 0;
	reaction->oxy_atom = 0;
}


void reaction_h(struct reaction *reaction)
{
	// FILL ME IN
}


void reaction_o(struct reaction *reaction)
{
	// FILL ME IN
}


