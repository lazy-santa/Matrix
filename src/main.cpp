//////////////////////////////
// Реализация вращения фигуры

#include <GL/glut.h>

GLfloat light_position[] = {1.0f, 1.0f, 1.0f, 0.0f};
GLfloat ambient_light[] = {0.2f, 0.2f, 0.2f, 1.0f};  // окружающее
GLfloat diffuse_light[] = {0.8f, 0.8f, 0.8f, 1.0f};  // диффузионное
GLfloat specular_light[] = {1.0f, 1.0f, 1.0f, 1.0f}; // зеркальное

GLfloat material_ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat material_diffuse[] = {0.0f, 1.0f, 0.0f, 1.0f}; // материал будет зеленого цвета
GLfloat material_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat material_shininess = 50.f;

float angle = 0.0f; // угол поворота

void initLighting() // инициализация освещения
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_shininess);
}

void display() // функция отрисовки
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // устанавливаем синий фон
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // применяем вращение
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();                   // сбрасываем текущую матрицу модели
                                        //  glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angle, 1.0f, 1.0f, 0.0f); // вращаем вокруг оси X и Y

    // Рисуем куб
    glBegin(GL_QUADS);

    glNormal3f(0.0f, 0.0f, -1.0f); // нормаль к грани
    glVertex3f(-0.5, -0.5, -0.5);  // левая грань
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glNormal3f(0.0f, 0.0f, 1.0f); // нормаль к грани
    glVertex3f(-0.5, -0.5, 0.5);  // правая грань
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glNormal3f(-1.0f, 0.0f, 0.0f); // нормаль к грани
    glVertex3f(-0.5, -0.5, -0.5);  // задняя грань
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glNormal3f(1.0f, 0.0f, 0.0f); // нормаль к грани
    glVertex3f(0.5, -0.5, -0.5);  // передняя грань
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);

    glNormal3f(0.0f, -1.0f, 0.0f); // нормаль к грани
    glVertex3f(-0.5, -0.5, -0.5);  // нижняя грань
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    glNormal3f(0.0f, 1.0f, 0.0f); // нормаль к грани
    glVertex3f(-0.5, 0.5, -0.5);  // верхняя грань
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glEnd(); // заканчиваем рисовать

    glutSwapBuffers();

    angle += 0.05f; // изменяем угол следующего кадра
}

// основная функция
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Rotate Cub");

    initLighting(); // вызываем настройку освещенности

    glutDisplayFunc(display);
    glutIdleFunc(display); // вызываем display для обновления сцены
    glutMainLoop();

    return 0;
}