float[] x, y, d, vx, vy;
// x,y는 원의 중심 좌표, d는 원의 지름, vx는 x축 상에서의 이동속도, vy는 y축 상에서의 이동속도
void setup() {
    size(2000, 1400);
    x = new float[5];  y = new float[5];  d = new float[5];
    vx = new float[5];  vy = new float[5];
    // 최초 1개의 적: i = 0
    vx[0] = 5;    vy[0] = 5;
    x[0] = 900;    y[0] = 200;    d[0] = 400;
    // Player: i = 4
    x[4] = 900;    y[4] = 800;    d[4] = 100;
    for (int i = 0; i < 4; i++) {
        // 부딪힐 때마다 속도와 크기 1/2만큼 변화
        d[i] = d[i] / 2;
        vx[i] = vx[i] * 2;
        vy[i] = vy[i] * 2;
    }
}
void draw() {
    background(120);
    fill(255, 0, 0);
    for (int i = 0; i < 3; i++) {
        x[i] += vx[i];
        y[i] += vy[i];
        // 벽에 부딪히면 튕겨나온다
        Player(x[i], y[i], d[i]);
        if (x[i]<0 || x[i]>width) vx[i] = -vx[i];
        if (y[i]<0 || y[i]>height) vy[i] = -vy[i];
        if (collide = true) {
            d[i + 1] = d[i] / 2;
            vx[i + 1] = vx[i] * 2;
            vy[i + 1] = vy[i] * 2;
            Player(x[i + 1], y[i + 1], d[i + 1]);
            Player(x[i + 1], y[i + 1], d[i + 1]);
        }
    }
    fill(255);
    Player(x[4], y[4], d[4]);
    if (x[4] < 0) x[4] = width;
    if (x[4] > width) x[4] = 0;
    if (y[4] < 0) y[4] = height;
    if (y[4] > height) y[4] = 0;
}
void keyPressed() {
    if (key == 'd') x[4] += 13;
    else if (key == 'a') x[4] -= 13;
    else if (key == 'w') y[4] -= 13;
    else if (key == 's') y[4] += 13;
}
//움직이는 캐릭터
boolean collide;
void Player(float a, float b, float d) {
    circle(a, b, d);
    circle(a - 30, b - 20, d / 3);
    circle(a + 30, b - 20, d / 3);
    if (a - d < 0 || a + d > width || b - d < 0 || b + d > height) {
        collide = true;
    }
    else {
        collide = false;
    }
}