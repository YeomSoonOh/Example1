// Choonsik
float x, y;
void setup() {
	size(800, 600);
	x = 400;
	y = 300;
	Yeom();
}
void Yeom() {
	background(255, 255, 255);
	strokeWeight(8);
	fill(252, 203, 83); // face color
	ellipse(x, y, 600, 530); // face
	arc(0.6 * x, 0.32 * y, 60, 60, PI, 1.65 * PI); // ears
	arc(1.4 * x, 0.32 * y, 60, 60, 1.35 * PI, 2 * PI);
	fill(255, 255, 255); // nose color
	ellipse(x, 1.05 * y, 100, 60); // nose
	fill(200, 90, 37); // tongue color
	arc(x, 1.15 * y, 25, 40, 0, PI); // tongue
	noFill();
	arc(x, 1.4 * y, 30, 20, 0, PI);
	line(350, 315, 330, 300);
	line(350, 315, 330, 330);
	line(450, 315, 470, 300);
	line(450, 315, 470, 330);
	noStroke();
	fill(0, 0, 0); // eye color
	circle(340, 240, 30); // eyes
	circle(460, 240, 30);
	fill(255, 70, 80, 100); // cheek color
	circle(0.785 * x, 1.05 * y, 70); // cheeks
	circle(1.215 * x, 1.05 * y, 70);
}