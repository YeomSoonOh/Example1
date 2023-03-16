float[] x, y, d, vx, vy;
void setup() {
    size(2000, 1400);
    x = new float[5];
    y = new float[5];
    d = new float[5];
    vx = new float[5];
    vy = new float[5];
    for (int i = 0; i < 4; i++) {
        d[i] = d[i] / 2;
        vx[i] = vx[i] * 2;  vy[i] = vy[i] * 2;
        vx[0] = 7;   vy[0] = 7;
        x[0] = 1000;  y[0] = 200;  d[0] = 200;
        x[4] = 1000;  y[4] = 1200;  d[4] = 100;
    }
}
void draw() {
    background(120);
    for (int i = 0; i < 4; i++) {
        x[i] += vx[i];
        y[i] += vy[i];
        if (x[i]<0 || x[i]>width) vx[i] = -vx[i];
        if (y[i]<0 || y[i]>height) vy[i] = -vy[i];
        if (x[0]<0 || x[0]>width || y[0]<0 || y[0]>height) {
            Player(x[i + 1], y[i + 1], d[i + 1]);
            Player(x[i + 1], y[i + 1], d[i + 1]);
        }
        fill(255, 0, 0);
        Player(x[i], y[i], d[i]);
    }
    fill(255);
    Player(x[4], y[4], d[4]);
    if (x[4] < 50) x[4] = 50;
    if (x[4] > width - 50) x[4] = width - 50;
    if (y[4] < 50) y[4] = 50;
    if (y[4] > height - 50) y[4] = height - 50;
}
void keyPressed() {
    if (key == 'd') x[4] += 10;
    else if (key == 'a') x[4] -= 10;
    else if (key == 'w') y[4] -= 10;
    else if (key == 's') y[4] += 10;
}
//collide
void collide() {
    float dx, dy, ds;
    for (int i = 0; i < 4; i++) {
        dx = x[i + 1] - x[i];
        dy = y[i + 1] - y[i];
        ds = sqrt(dx * dx + dy * dy);
        if ((ds < d[i] + d[i + 1]) || x[i]<0 || x[i]>width || y[i]<0 || y[i]>height) {
            Player(x[i + 1], y[i + 1], d[i + 1]);
        }
    }
}
//Character
void Player(float a, float b, float d) {
    circle(a, b, d);
    circle(a - 30, b - 20, d / 3);
    circle(a + 30, b - 20, d / 3);
}