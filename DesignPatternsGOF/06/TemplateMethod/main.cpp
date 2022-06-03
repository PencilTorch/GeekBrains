#include "TemplateMethod.h"

int main() {
	Image* bi = new BitmapImage;
	Image* vi = new VectorImage;
	std::string path = "images.txt";
	bi->drawFigure(path);
	vi->drawFigure(path);

	return 0;           
}
