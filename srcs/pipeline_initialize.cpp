#include "../headers/rt.hpp"
#include <iostream>

// void initialize_gl(GLuint *render_tex)
// {
//     glEnable(GL_TEXTURE_2D);
//     glGenTextures(1, render_tex);
//     glBindTexture(GL_TEXTURE_2D, *render_tex);
//     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH, HEIGHT, 0, GL_RGBA, GL_FLOAT, nullptr);
//     glBindTexture(GL_TEXTURE_2D, 0);

//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glMatrixMode(GL_MODELVIEW);

//     glFinish();	
// }


// void image_draw()   
// {
//     for (int j = HEIGHT-1; j >= 0; --j)
//     {
//         for (int i = 0; i < WIDTH; ++i)
//         {
//             auto r = double(i) / (WIDTH-1);
//             auto g = double(j) / (HEIGHT-1);
//             auto b = 0.25;

//             int ir = static_cast<int>(255.999 * r);
//             int ig = static_cast<int>(255.999 * g);
//             int ib = static_cast<int>(255.999 * b);
//         }
//     }
// }