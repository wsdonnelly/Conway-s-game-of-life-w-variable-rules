#ifndef CONTROLS_HPP
#define CONTROLS_HPP

class Controls {
	public:
		unsigned int low = 2;
		unsigned int high = 3;
		unsigned int born = 3;
		void move_low_down();
		void move_low_up();
		void move_high_up();
		void move_high_down();
		void set_born(int n);
		void display();
};

#endif