#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int towerA[10], towerB[10], towerC[10];
int topA, topB, topC;
int n = 3;
int colors[10]; 
int disks; 
int source, destination, auxiliary; 
int i;  
int step;  
int moves[7][3] = { {1, 3, 2}, {1, 2, 3}, {3, 2, 1}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {1, 3, 2} };
int disk;  
int gd = DETECT, gm;

void initializeTowers();  
void drawTowers();
void moveDisk();
void hanoi();
void stepByKey();

int main() {
    
    initgraph(&gd, &gm, "");  // Inicializar el modo gráfico

    disks = 3;  // Número de discos inicializado
    source = 1;  // Torre de origen
    destination = 3;  // Torre de destino
    auxiliary = 2;  // Torre auxiliar
    

    initializeTowers();  // Inicialización de las torres
    drawTowers();        // Dibujar las torres

    stepByKey();  // Mover los discos uno a uno con tecla

    closegraph();  // Cerrar el modo gráfico
    return 0;
}

// Función para inicializar las torres
void initializeTowers() {
    topA = disks - 1;  // Inicializar la torre A con todos los discos
    topB = -1;  // Torre B vacía
    topC = -1;  // Torre C vacía

    for (i = 0; i < disks; i++) {
        towerA[i] = disks - i;  // Llenar la torre A con los discos en orden decreciente
        towerB[i] = 0;  // Torre B vacía
        towerC[i] = 0;  // Torre C vacía
        colors[i] = i + 1;  // Asignar colores únicos a los discos
    }
}

// Función para dibujar las torres con colores
void drawTowers() {
    cleardevice();

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(190, 100, 210, 400);  // Torre A
    bar(390, 100, 410, 400);  // Torre B
    bar(590, 100, 610, 400);  // Torre C
	outtextxy(250, 75, (char*)"Hanoi");
	outtextxy(150, 400, (char*)"Presiona espacio para mover un disco");

    for (i = 0; i <= topA; i++) {
        setfillstyle(SOLID_FILL, colors[towerA[i] - 1]);  // Color basado en el disco
        bar(200 - towerA[i] * 10, 350 - i * 20, 200 + towerA[i] * 10, 370 - i * 20);
    }
    for (i = 0; i <= topB; i++) {
        setfillstyle(SOLID_FILL, colors[towerB[i] - 1]);  // Color basado en el disco
        bar(400 - towerB[i] * 10, 350 - i * 20, 400 + towerB[i] * 10, 370 - i * 20);
    }
    for (i = 0; i <= topC; i++) {
        setfillstyle(SOLID_FILL, colors[towerC[i] - 1]);  // Color basado en el disco
        bar(600 - towerC[i] * 10, 350 - i * 20, 600 + towerC[i] * 10, 370 - i * 20);
    }
}

// Función para mover un disco entre dos torres
void moveDisk() {
    if (source == 1) {
        disk = towerA[topA--];
    } else if (source == 2) {
        disk = towerB[topB--];
    } else {
        disk = towerC[topC--];
    }

    if (destination == 1) {
        towerA[++topA] = disk;
    } else if (destination == 2) {
        towerB[++topB] = disk;
    } else {
        towerC[++topC] = disk;
    }

    drawTowers();
}

// Función recursiva para resolver las Torres de Hanoi
void hanoi() {
    if (disks == 1) {
        moveDisk();
        return;
    }
    disks--;
    hanoi();
    moveDisk();
    hanoi();
    disks++;
}

// Función para mover discos paso a paso con la tecla
void stepByKey() {
    step = 0;
    while (step < 7) {
        if (kbhit()) {
            getch();  // Esperar a que se presione una tecla
            source = moves[step][0];
            destination = moves[step][1];
            auxiliary = moves[step][2];
            disks = 1;  // Para hacer movimientos individuales
            hanoi();
            step++;
        }
    }
}

