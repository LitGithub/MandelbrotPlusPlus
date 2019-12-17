#include<allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_color.h>
#include<time.h>
#include<iostream>
#include<complex>
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;
int red = 255, green = 0, blue = 0;
int stage = 0;
double mandelbrot(complex<double> c);
int main() {
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);
	complex <double> c;
	int num;

	for (double i = -2; i < 2; i += .01) {
		for (double j = -2; j < 2; j += .01) {
			c = complex<double>(i, j);
			num = mandelbrot(c);
			int x = i * 100 + 400;
			int y = j * 100 + 400;
			al_put_pixel(x,y, al_map_rgb(0, num * 3, num * 5));
			cout << "Num is " << num << " at " << x << ", " << y << endl;
			al_flip_display();
		}
	}
	al_rest(40);
}

double mandelbrot(complex<double> c) {
	complex<double> z = 0;
	int counter = 0;
	while (abs(z) <= 2 && counter <= 80) {
		z = (z * z) + c;
		counter ++;
	}
	return counter;
}