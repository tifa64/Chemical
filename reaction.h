#include <stdio.h>
#include <pthread.h>


struct reaction {
	int hyd_atom;
	int oxy_atom;
};

void reaction_init(struct reaction *reaction);

void reaction_h(struct reaction *reaction);

void reaction_o(struct reaction *reaction);
