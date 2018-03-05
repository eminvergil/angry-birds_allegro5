#include"deneme.h"
yapi st;
int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *que = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool done = false;
	bool mous = false;
	bool fly = false;
	if (!al_init())
		return -1;

	display = al_create_display(w, h);
	
	if (!display)
		return -1;

	al_init_primitives_addon();
	al_install_mouse();

	timer = al_create_timer(1. / 55.);
	que = al_create_event_queue();
	
	al_register_event_source(que, al_get_timer_event_source(timer));
	al_register_event_source(que, al_get_mouse_event_source());
	al_register_event_source(que, al_get_display_event_source(display));
	al_start_timer(timer);
	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(que,&ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			done = false;
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			fly = true;
			weight._position.setX(ev.mouse.x);
			weight._position.setY(ev.mouse.y);
		}
	    
		st.update();
		if (fly)  st.drag = true; 
		al_flip_display();
		al_clear_to_color(al_map_rgb(255, 255, 255));
	}
	al_destroy_event_queue(que);
	al_destroy_display(display);
	return 0;
}