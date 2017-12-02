#include <pthread.h>
#include "reaction.h"

// Forward declaration. This function is implemented in reaction-runner.c,
// but you needn't care what it does. Just be sure it's called when
// appropriate within reaction_o()/reaction_h().
void make_water();
pthread_mutex_t lock;
void reaction_init(struct reaction *reaction) {
	reaction->hyd_atom = 0;
	reaction->oxy_atom = 0;
}

void reaction_h(struct reaction *reaction) {
	reaction->hyd_atom ++;
	pthread_mutex_lock(&lock);
	if(reaction->hyd_atom >= 2 && reaction->oxy_atom >=1){
		make_water();
		reaction->hyd_atom -= 2;
		reaction->oxy_atom --;
	}
	else {
		while(reaction->hyd_atom < 2 && reaction->oxy_atom < 1);
	}
	pthread_mutex_unlock(&lock);
}

void reaction_o(struct reaction *reaction) {
	reaction->oxy_atom ++;
	pthread_mutex_lock(&lock);
	if(reaction->hyd_atom >= 2 && reaction->oxy_atom >=1){
		make_water();
		reaction->hyd_atom -= 2;
		reaction->oxy_atom --;
	}
	else
		while(reaction->hyd_atom < 2);
	pthread_mutex_unlock(&lock);
}
