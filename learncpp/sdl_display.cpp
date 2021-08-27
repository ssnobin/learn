#include <iostream>
#include <SDL.h>

int main(int argc, char** argv)
{
    //初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
 
    //创建窗口
    SDL_Window *win = nullptr;
    win = SDL_CreateWindow("Hello SDL2",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
 
    //创建渲染器
    SDL_Renderer *ren = nullptr;
    ren = SDL_CreateRenderer(win, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
 
    //创建表面
    SDL_Surface *bmp = nullptr;
    /*bmp = SDL_LoadBMP("888.bmp");*/
    bmp = SDL_LoadBMP("888.bmp");
    if (bmp == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
 
    //创建材质
    SDL_Texture *tex = nullptr;
    tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
 
    //清空渲染器
    SDL_RenderClear(ren);
    //将材质复制到渲染器
    SDL_RenderCopy(ren, tex, NULL, NULL);
    //呈现渲染器
    SDL_RenderPresent(ren);
    //窗口延时
    SDL_Delay(5000);
 
    //释放资源
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    //退出SDL
    SDL_Quit();
 
    return 0;
}
/*#include "SDL.h"*/

/*int main (int argc, char* argv[])*/
/*{*/
  /*[>int numdrivers = SDL_GetNumRenderDrivers();<]*/
  /*int numdrivers = SDL_GetNumVideoDrivers();*/

  /*printf("Drivers count: %i\n", numdrivers);*/

  /*for (int i=0;i<numdrivers;i++)*/
  /*{*/
    /*SDL_RendererInfo drinfo;*/
    /*SDL_GetRenderDriverInfo(i, &drinfo);*/

    /*printf("Driver name: %s\n", drinfo.name);*/
  /*}*/
/*}*/
/*#include <stdio.h>*/
/*#include "SDL2/SDL.h"*/

/*//Screen dimension constants*/
/*const int SCREEN_WIDTH = 640;*/
/*const int SCREEN_HEIGHT = 480;*/

/*int main(int argc, char* argv[])*/
/*{*/
    /*//The window we'll be rendering to*/
    /*SDL_Window* window = NULL;*/

    /*//The surface contained by the window*/
    /*SDL_Surface* screenSurface = NULL;*/

    /*//Initialize SDL*/
    /*if( SDL_Init( SDL_INIT_VIDEO ) < 0 )*/
    /*{*/
        /*printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());*/
    /*}*/
    /*else*/
    /*{*/
        /*//Create window*/
        /*window = SDL_CreateWindow("SDL Tutorial",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,*/
                                      /*SCREEN_HEIGHT, SDL_WINDOW_SHOWN);*/
        /*if (window == NULL) {*/
            /*printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());*/
        /*}*/
    /*}*/

    /*return 0;*/
/*}*/
