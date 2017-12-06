
#include <pthread.h>
#include "reaction.h"

// Forward declaration. This function is implemented in reaction-runner.c,
// but you needn't care what it does. Just be sure it's called when
// appropriate within reaction_o()/reaction_h().
void make_water();
pthread_mutex_t lock;
pthread_cond_t waith = PTHREAD_COND_INITIALIZER;
pthread_cond_t waito = PTHREAD_COND_INITIALIZER;

void reaction_init(struct reaction *reaction) {
	reaction->hyd_atom = 0;
	reaction->oxy_atom = 0;
}



void reaction_h(struct reaction *reaction) {
    pthread_mutex_lock(&lock);
	reaction->hyd_atom ++;
	if(reaction->hyd_atom >= 2 && reaction->oxy_atom >=1){
		make_water();
		reaction->hyd_atom -= 2;
		reaction->oxy_atom --;
        pthread_cond_signal( &waith );
        pthread_cond_signal( &waito );
	}
	else
		pthread_cond_wait( &waith, & lock );
	pthread_mutex_unlock(&lock);
}

void reaction_o(struct reaction *reaction) {
    pthread_mutex_lock(&lock);
	reaction->oxy_atom ++;
	if(reaction->hyd_atom >= 2 && reaction->oxy_atom >=1){
		make_water();
		reaction->hyd_atom -= 2;
		reaction->oxy_atom --;
		pthread_cond_signal( &waith );
		pthread_cond_signal( &waith );
	}
	else
		pthread_cond_wait( &waito, &lock );
    pthread_mutex_unlock(&lock);
}
