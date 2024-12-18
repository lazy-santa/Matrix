//////////////////////////////
// реализация вращения фигуры

#include <GL/glut.h>

float angle = 0.0f; // угол поворота

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // применяем вращение
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();                   // сбрасываем текущую матрицу модели
    glRotatef(angle, 1.0f, 1.0f, 0.0f); // вращаем вокруг оси X и Y

    // Рисуем куб
    glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.5, -0.5); // левая нижняя грань
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glVertex3f(-0.5, -0.5, 0.5); // правая нижняя грань
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glVertex3f(-0.5, -0.5, -0.5); // задняя грань
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glVertex3f(0.5, -0.5, -0.5); // передняя грань
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);

    glVertex3f(-0.5, -0.5, -0.5); // нижяя грань
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    glVertex3f(-0.5, 0.5, -0.5); // верхняя грань
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glEnd();

    glutSwapBuffers();

    angle += 0.1f; // изменяем угол следующего кадра
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotate Cub");

    glutDisplayFunc(display);
    glutIdleFunc(display); // вызываем display для обновления сцены
    glutMainLoop();

    return 0;
}