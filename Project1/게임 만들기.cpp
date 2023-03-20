float[] x, y, d, vx, vy, bx, by, bd;
int L = 5;
int score = 0;

void choonsik(float x, float y, float d) {
    strokeWeight(8);
    circle(x, y, d * 3 / 4); // face
    arc(x - d / 4, y - d / 800 * 204, d / 80 * 6, d / 80 * 6, PI, 1.65 * PI); // ears
    arc(x + d / 4, y - d / 800 * 204, d / 80 * 6, d / 80 * 6, 1.35 * PI, 2 * PI);
    fill(255, 255, 255); // nose color
    circle(x, y + d / 800 * 15, d / 8); // nose
    fill(200, 90, 37); // tongue color
    arc(x, y + d / 800 * 65, d / 800 * 25, d / 20, 0, PI); // tongue
    noFill();
    arc(x, y + d / 800 * 120, d / 800 * 30, d / 40, 0, PI);
    line(x - d / 800 * 50, y + d / 800 * 15, x - d / 800 * 70, y);
    line(x - d / 800 * 50, y + d / 800 * 15, x - d / 800 * 70, y + d / 800 * 30);
    line(x + d / 800 * 50, y + d / 800 * 15, x + d / 800 * 70, y);
    line(x + d / 800 * 50, y + d / 800 * 15, x + d / 800 * 70, y + d / 800 * 30);
    noStroke();
    fill(0, 0, 0); // eye color
    circle(x - d / 800 * 60, y - d / 800 * 60, d / 800 * 30); // eyes
    circle(x + d / 800 * 60, y - d / 800 * 60, d / 800 * 30);
    fill(255, 70, 80, 100); // cheek color
    circle(x - d / 800 * 86, y + d / 800 * 15, d / 80 * 7); // cheeks
    circle(x + d / 800 * 86, y + d / 800 * 15, d / 80 * 7);
}

void Player(float a, float b, float d) {
    choonsik(a, b, d);
}

void bonus(float a, float b, float d) {
    circle(a, b, d);
}

void setup() {
    size(1500, 900);
    x = new float[8]; y = new float[8]; d = new float[8];
    vx = new float[8]; vy = new float[8];
    bx = new float[10000];  by = new float[10000]; bd = new float[10000];
    vx[0] = 0; vy[0] = 0;
    x[0] = 750; y[0] = 450; d[0] = 50;
    for (int i = 1; i < 8; i++) {
        vx[i] = random(1, 5); vy[i] = random(1, 5);
        x[i] = random(0, 1400); y[i] = random(0, 800); d[i] = 100;
    }
    for (int i = 1; i < 10000; i++) {
        bx[i] = random(15, 1500 - 15);  by[i] = random(15, 900 - 15);  bd[i] = 30;
    }
}

boolean collide(float a, float b, float d) {
    float D = dist(x[0], y[0], a, b);
    if (D <= d / 2 + 25) return true;
    else return false;
}

int count = 0;
void draw() {
    if (L > 1) {
        background(12, 194, 247);
        fill(252, 203, 83);
        choonsik(40, 50, 50);
        fill(255, 255, 255, 255);
        textSize(100);
        text("x", 80, 75);
        text(L, 130, 80);
        textSize(100);
        score = (count / 60) * 50;
        count++;
        text("Score: ", 1000, 80);
        text(score, 1300, 80);
    }
    else if (L == 1) {
        background(234, 12, 194, 0);
        fill(252, 203, 83);
        choonsik(40, 50, 50);
        fill(255, 255, 255, 255);
        textSize(100);
        text("x", 80, 75);
        text(L, 130, 80);
        textSize(100);
        score = (count / 60) * 50;
        count++;
        text("Score: ", 1000, 80);
        text(score, 1300, 80);
    }
    fill(255, 0, 0, 230);
    for (int i = 1; i < 8; i++) {
        x[i] += vx[i];
        y[i] += vy[i];
        Player(x[i], y[i], d[i]);
        if (x[i] < 0 || x[i] > width) {
            vx[i] *= -1;
            vx[i] *= 1.05; vy[i] *= 1.05;
            if (abs(vx[i]) > 10) {
                vx[i] /= 2; vy[i] /= 2;
            }
        }
        if (y[i] < 0 || y[i] > height) {
            vy[i] *= -1;
            vx[i] *= 1.05; vy[i] *= 1.05;
            if (abs(vy[i]) > 10) {
                vx[i] /= 2; vy[i] /= 2;
            }
        }
        if (collide(x[i], y[i], d[i])) {
            if (L > 0) {
                L -= 1;
                x[i] = random(0, 1400); y[i] = random(0, 800); d[i] = 100;
            }
            else break;
        }
        fill(255, 0, 0, 200);
    }
    if (L == 0) {
        count *= 1;
        background(255, 0, 0, 255);
        fill(252, 203, 83);
        choonsik(40, 50, 50);
        fill(0, 0, 0, 255);
        textSize(100);
        text("x", 80, 75);
        text("0", 130, 80);

        textSize(100);
        score = (count / 60) * 50;
        count *= 1;
        text("Score: ", 1000, 80);
        text(score, 1300, 80);

        textSize(200);
        text("Game Over", 300, 300);
        textSize(70);
        text("Quit? => press ESC", 480, 800);
        fill(random(0, 255), random(0, 255), random(0, 255), 255);
        text("Restart? => press ENTER", 400, 600);

    }
    if (L != 0) {
        fill(252, 203, 83);
        Player(x[0], y[0], d[0]);
    }
    else if (L == 0) {
        noStroke();
        fill(255, 255, 255, 0);
        Player(x[0], y[0], d[0]);
    }
    if (x[0] < 0) x[0] = width;
    if (x[0] > width) x[0] = 0;
    if (y[0] < 0) y[0] = height;
    if (y[0] > height) y[0] = 0;
    for (int i = 1; i < 8; i++) {
        fill(random(0, 255), random(0, 255), random(0, 255), 255);
        if (count < 600 * i) {
            bonus(bx[i], by[i], bd[i]);
            break;
        }
        if (collide(bx[i], by[i], bd[i])) {
            bd[i] = 0;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (collide(bx[i], by[i], bd[i])) {
            bx[i] = 10000; by[i] = 10000;
            L += 1;
        }
    }
    fill(255);
}

void keyPressed() {
    if (key == 'd') x[0] += 18;
    else if (key == 'a') x[0] -= 18;
    else if (key == 'w') y[0] -= 18;
    else if (key == 's') y[0] += 18;
    else if (key == ENTER) {
        L = 5;
        x[0] = 750; y[0] = 450;
        count = 0;
        for (int i = 1; i < 8; i++) {
            vx[i] = 3; vy[i] = 3;
        }
    }
    else if (key == ESC) exit();
}